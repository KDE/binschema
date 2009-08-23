#include "deepfiletree.h"
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QVector>
#include <QVariant>
#include <QXmlQuery>
#include <QDebug>

/** This XML model spans the file system, OLE streams in OLE files and data structures in some
 *  OLE streams.
 **/

namespace {
class ElementNode {
public:
    // if parent, firstSibling, next or previous are -1, they corresponding node does not exist
    // if the value is -2, the corresponding node has not been searched yet
    int parentId;
    int firstSiblingId;
    int nextId;
    int previousId;

    ElementNode() :parentId(-2), firstSiblingId(-2), nextId(-2), previousId(-2) {}
};

class OleStreamElementNode : public ElementNode {
public:
    QString streamname;
    int size;
    bool isdir;
};

enum Type {
    File,
    OLEStream
};

const int typeSize = 2;
const int indexSize = sizeof(int)*8 - typeSize;

Type getType(int id) {
    return (Type)(id >> indexSize);
}
// last bits are used for the type
int getIndex(int id) {
    return (id << typeSize) >> typeSize;
}
int getId(Type t, int index) {
    return (t << indexSize) | index;
}

enum Kind {
    Element,
    AttributeName,
    AttributeSize
};

}

class DeepFileTree::Private {
public:
    QXmlNamePool namepool;
    QList<ElementNode> fileinfonodes;
    QList<QFileInfo> fileinfos;
    QList<OleStreamElementNode> olestreams;
    const QXmlName directory;
    const QXmlName file;
    const QXmlName olestream;
    const QXmlName olestreamdir;
    const QXmlName name;
    const QXmlName size;

    Private(const QXmlNamePool& pool) :namepool(pool),
            directory(QXmlName(namepool, QLatin1String("directory"))),
            file(QXmlName(namepool, QLatin1String("file"))),
            olestream(QXmlName(namepool, QLatin1String("olestream"))),
            olestreamdir(QXmlName(namepool, QLatin1String("olestreamdir"))),
            name(QXmlName(namepool, QLatin1String("name"))),
            size(QXmlName(namepool, QLatin1String("size"))) {
    }

    ElementNode& getElementNode(int id) {
        int index = getIndex(id);
        switch (getType(id)) {
            case File: return fileinfonodes[index];
            case OLEStream: return olestreams[index];
        }
    }
    QFileInfo* getFileInfo(int id) {
        return (getType(id) == File) ?&fileinfos[getIndex(id)] :0;
    }

    int getFileIndex(const QFileInfo& fileinfo) {
        // find the parent
        QDir dir = fileinfo.dir();
        QFileInfo parentInfo(dir.path());
        if (fileinfo == parentInfo) { // parent does not exist
            ElementNode node;
            node.parentId = node.nextId = node.previousId = -1;
            fileinfos.append(fileinfo);
            fileinfonodes.append(node);
            return fileinfonodes.count() - 1;
        }

        int parentIndex = getFileIndex(parentInfo);
        if (parentIndex == -1) return -1;
        ElementNode& parent = fileinfonodes[parentIndex];
        if (parent.firstSiblingId != -2) return -1;

        // the parent has not initialized its siblings yet
        const int indexOf = fileinfos.indexOf(parentInfo);
        if (indexOf != -1) return indexOf;

        int offset = fileinfos.count();
        loadFileSiblings(dir, parentIndex, parent);
        return fileinfos.indexOf(fileinfo, offset);
    }

    void loadFileSiblings(const QDir& dir, int parentIndex, ElementNode& parent) {
        QFileInfoList list = dir.entryInfoList(QStringList(),
            QDir::AllEntries|QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Hidden, QDir::Name);
        int offset = fileinfos.count();
        fileinfos.append(list);
        parent.firstSiblingId = (list.count()) ?getId(File, offset) :-1;
        for (int i=0; i<list.size(); ++i) {
            ElementNode n;
            n.parentId = getId(File, parentIndex);
            n.previousId = (i) ?getId(File, offset + i - 1) :-1;
            n.nextId = (i == list.size()-1) ?-1 :getId(File, offset + i + 1);
            fileinfonodes.append(n);
        }
    }

    void loadStreamSiblings(const QFileInfo& info, int parentIndex, ElementNode& parent) {
        if (info.suffix().toLower() != "ppt") return;
        int offset = olestreams.count();
        parent.firstSiblingId = getId(OLEStream, offset);
        const char* names[3] = {"A", "Current User", "PowerPoint Document"};
        for (int i=0; i<3; ++i) {
            OleStreamElementNode n;
            n.streamname = names[i];
            n.size = 10;
            n.isdir = false;
            n.parentId = getId(File, parentIndex);
            n.previousId = (i) ?getId(OLEStream, offset + i - 1) :-1;
            n.nextId = (i == 2) ?-1 :getId(OLEStream, offset + i + 1);
            olestreams.append(n);
        }
    }
};

DeepFileTree::DeepFileTree(const QXmlNamePool& pool) :d(new Private(pool)) {
}
DeepFileTree::~DeepFileTree() {
    delete d;
}

QXmlNodeModelIndex
DeepFileTree::toNodeIndex(const QFileInfo& fileinfo) const {
    int indexOf = d->fileinfos.indexOf(fileinfo);
    if (indexOf == -1) {
        indexOf = d->getFileIndex(fileinfo);
        if (indexOf == -1) return QXmlNodeModelIndex();
    }
    return createIndex(indexOf, Element);
}

QVector<QXmlNodeModelIndex>
DeepFileTree::attributes(const QXmlNodeModelIndex& element) const {
    QVector<QXmlNodeModelIndex> v;
    const QFileInfo* info = d->getFileInfo(element.data());
    v.append(createIndex(element.data(), AttributeName));
    if (info) {
        if (info->isFile()) {
            v.append(createIndex(element.data(), AttributeSize));
        }
    } else { // OLEStream
        const OleStreamElementNode& e = (const OleStreamElementNode&)d->getElementNode(element.data());
        if (!e.isdir) {
            v.append(createIndex(element.data(), AttributeSize));
        }
    }
    return v;
}

QXmlNodeModelIndex
DeepFileTree::nextFromSimpleAxis(SimpleAxis axis, const QXmlNodeModelIndex& origin) const {
    const QFileInfo* info = d->getFileInfo(origin.data());
    ElementNode& node = d->getElementNode(origin.data());

    int data = -1;
    switch (axis) {
        case Parent:
            data = node.parentId; break;

        case FirstChild:
            if (node.firstSiblingId == -2) {
                if (info && info->isDir()) {
                    d->loadFileSiblings(info->filePath(), origin.data(), node);
                } else if (info && info->isFile()) {
                    d->loadStreamSiblings(info->filePath(), origin.data(), node);
                }
                if (node.firstSiblingId == -2) {
                    node.firstSiblingId = -1;
                }
            }
            data = node.firstSiblingId; break;
 
        case PreviousSibling:
            data = node.previousId; break;

        case NextSibling:
            data = node.nextId; break;
    };
    return (data == -1) ?QXmlNodeModelIndex() :createIndex(data, 0);
}

QUrl
DeepFileTree::baseUri(const QXmlNodeModelIndex& n) const {
    return documentUri(n);
}
QXmlNodeModelIndex::DocumentOrder
DeepFileTree::compareOrder(const QXmlNodeModelIndex& ni1, const QXmlNodeModelIndex& ni2) const {
    if (ni1.data() < ni2.data()) return QXmlNodeModelIndex::Precedes;
    return (ni1.data() == ni2.data()) ?QXmlNodeModelIndex::Is :QXmlNodeModelIndex::Follows;
}
QUrl
DeepFileTree::documentUri(const QXmlNodeModelIndex& n) const {
    const QFileInfo& fileinfo = d->fileinfos[n.data()];
    return QUrl::fromLocalFile(fileinfo.filePath());
}
QXmlNodeModelIndex
DeepFileTree::elementById(const QXmlName& id) const {
    return QXmlNodeModelIndex();
}
QXmlNodeModelIndex::NodeKind
DeepFileTree::kind(const QXmlNodeModelIndex& ni) const {
    return ni.additionalData() == Element ? QXmlNodeModelIndex::Element : QXmlNodeModelIndex::Attribute;
}
QXmlName
DeepFileTree::name(const QXmlNodeModelIndex& ni) const {
    switch ((Kind)ni.additionalData()) {
        case Element: {
            const QFileInfo* info = d->getFileInfo(ni.data());
            if (info) return info->isFile() ?d->file :d->directory;
            const OleStreamElementNode& e
                = (const OleStreamElementNode&)d->getElementNode(ni.data());
            return (e.isdir) ?d->olestreamdir :d->olestream;
        }
        case AttributeName: return d->name;
        case AttributeSize: return d->size;
    }
}
QVector<QXmlName>
DeepFileTree::namespaceBindings(const QXmlNodeModelIndex& n) const {
    return QVector<QXmlName>();
}
QVector<QXmlNodeModelIndex>
DeepFileTree::nodesByIdref(const QXmlName& idref) const {
    return QVector<QXmlNodeModelIndex>();
}
QXmlNodeModelIndex
DeepFileTree::root(const QXmlNodeModelIndex& n) const {
    int index = n.data();
    ElementNode& e = d->getElementNode(n.data());
    while (e.parentId != -1) {
         index = e.parentId;
         e = d->getElementNode(index);
    }
    return createIndex(index, 0);
}
QString
DeepFileTree::stringValue(const QXmlNodeModelIndex& n) const {
    return typedValue(n).toString();
}
QVariant
DeepFileTree::typedValue(const QXmlNodeModelIndex& n) const {
    const QFileInfo* info = d->getFileInfo(n.data());
    switch ((Kind)n.additionalData()) {
        case AttributeName:
            if (info) return info->fileName();
            return ((const OleStreamElementNode&)d->getElementNode(n.data())).streamname;
        case AttributeSize:
            if (info) return info->size();
            return ((const OleStreamElementNode&)d->getElementNode(n.data())).size;
        default:
            return QVariant();
    }
}
