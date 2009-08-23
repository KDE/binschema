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

class ElementNode {
public:
    // if parent, firstSibling, next or previous are -1, they corresponding node does not exist
    // if the value is -2, the corresponding node has not been searched yet
    int parent;
    int firstSibling;
    int next;
    int previous;

    ElementNode() :parent(-2), firstSibling(-2), next(-2), previous(-2) {}
};

class OleStreamElementNode : public ElementNode {
    QString streamname;
};

class DeepFileTree::Private {
public:
    QXmlNamePool namepool;
    QList<ElementNode> fileinfonodes;
    QList<QFileInfo> fileinfos;
    QList<OleStreamElementNode> olestreams;
    const QXmlName file;
    const QXmlName name;

    Private(const QXmlNamePool& pool) :namepool(pool),
        file(QXmlName(namepool, QLatin1String("file"))),
        name(QXmlName(namepool, QLatin1String("name"))) {}

    enum Type {
        File
    };
    static Type getType(int indexdata) {
        return (Type)(indexdata >> (sizeof(int)-sizeof(Type)));
    }
    // last bits are used for the type
    static int getIndex(int indexdata) {
        return indexdata << sizeof(Type) >> sizeof(Type);
    }

    int getFileIndex(const QFileInfo& fileinfo) {
        // find the parent
        QDir dir = fileinfo.dir();
        QFileInfo parentInfo(dir.path());
        if (fileinfo == parentInfo) { // parent does not exist
            ElementNode node;
            node.parent = node.next = node.previous = -1;
            fileinfos.append(fileinfo);
            fileinfonodes.append(node);
            return fileinfonodes.count() - 1;
        }

        int parentIndex = getFileIndex(parentInfo);
        if (parentIndex == -1) return -1;
        ElementNode& parent = fileinfonodes[parentIndex];
        if (parent.firstSibling != -2) return -1;

        // the parent has not initialized its siblings yet
        const int indexOf = fileinfos.indexOf(parentInfo);
        if (indexOf != -1) return indexOf;

        int offset = fileinfos.count();
        loadSiblings(dir, parentIndex, parent);
        return fileinfos.indexOf(fileinfo, offset);
    }

    void loadSiblings(const QDir& dir, int parentIndex, ElementNode& parent) {
        QFileInfoList list = dir.entryInfoList(QStringList(),
            QDir::AllEntries|QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Hidden, QDir::Name);
        int offset = fileinfos.count();
        fileinfos.append(list);
        parent.firstSibling = (list.count()) ?offset :-1;
        for (int i=0; i<list.size(); ++i) {
            ElementNode n;
            n.parent = parentIndex;
            n.previous = (i) ?offset + i - 1 :-1;
            n.next = (i == list.size()-1) ?-1 :offset + i + 1;
            fileinfonodes.append(n);
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
    return createIndex(indexOf, 0);
}

QVector<QXmlNodeModelIndex>
DeepFileTree::attributes(const QXmlNodeModelIndex& element) const {
    QVector<QXmlNodeModelIndex> v(1);
    v[0] = createIndex(element.data(), 1);
    return v;
}

QXmlNodeModelIndex
DeepFileTree::nextFromSimpleAxis(SimpleAxis axis, const QXmlNodeModelIndex& origin) const {
    const QFileInfo& info = d->fileinfos[origin.data()];
    ElementNode& node = d->fileinfonodes[origin.data()];

    int data = -1;
    switch (axis) {
        case Parent:
            data = node.parent; break;

        case FirstChild:
            if (node.firstSibling == -2) {
                d->loadSiblings(info.filePath(), origin.data(), node);
            }
            data = node.firstSibling; break;
 
        case PreviousSibling:
            data = node.previous; break;

        case NextSibling:
            data = node.next; break;
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
    return ni.additionalData() == 0 ? QXmlNodeModelIndex::Element : QXmlNodeModelIndex::Attribute;
}
QXmlName
DeepFileTree::name(const QXmlNodeModelIndex& ni) const {
    return ni.additionalData() ? d->file : d->name;
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
    int parent = d->fileinfonodes[index].parent;
    while (parent != -1) {
        index = parent;
        parent = d->fileinfonodes[index].parent;
    }
    return createIndex(index, 0);
}
QString
DeepFileTree::stringValue(const QXmlNodeModelIndex& n) const {
    return (n.additionalData()) ?d->fileinfos[n.data()].fileName() :QString();
}
QVariant
DeepFileTree::typedValue(const QXmlNodeModelIndex& n) const {
    return (n.additionalData()) ?d->fileinfos[n.data()].fileName() :QVariant();
}

