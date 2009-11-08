#include "msoxmlnodemodel.h"
#include "utils.h"
#include <QtXmlPatterns/QXmlNamePool>
#include <QtCore/QUrl>
#include <QDebug>

using namespace std;

/** This XML model spans one OLE stream file.
 * The root node corresponds to the file. The child elements of the root correspond to streams.
 * Below the streams, the elements can correspond to introspectables or values.
 * Each Introspectable contains a colleciont of Introspectables and values.
 * Each value is represented by a value element and a value text field.
 * There is a tree of introspectables available. Values (QVariants) do not know about their parents
 * and have to have a the pointer to their introspectable of stream as a parent.
 * The additionalData() filed of the QXmlNodeindex should contain this information.
 * The data() field is a pointer to the introspectable also for the stream.
 **/
namespace {

static const qint64 Document = 0;
static const qint64 File = 1;
static const qint64 OLEStream = 2;
static const qint64 IntrospectableNode = 3;
static const qint64 AttributeType = 4;
static const qint64 ValueElement = 5;
static const qint64 Value = 6;

int
getMemberNumber(qint64 i) {
    return 0;
}
int
getInstanceNumber(qint64 i) {
    return 0;
}
qint64
createIndex(qint64 type, int membernumber, int instancenumber) {
    return 0;
}

const Introspectable*
getNextElement(const Introspectable* i, qint64 adin, qint64& adout) {
    int m = getMemberNumber(adin);
    int in = getInstanceNumber(adin);
    const Introspection* is = i->getIntrospection();
    for (int j=m; j<is->numberOfMembers; ++j) {
        for (int k=in; k<is->numberOfInstances[j](i); ++k) {
            const Introspectable* ci = is->introspectable[j](i, k);
            if (ci) {
                adout = createIndex(IntrospectableNode, j, k);
                return ci;
            } else {
                adout = createIndex(ValueElement, j, k);
                return i;
            }
        }
    }
    return 0;
}

}

class MsoXmlNodeModel::Private {
public:
    QXmlNamePool namepool;
    QString filepath;
    const QMap<QString, QSharedPointer<const Introspectable> > streams;
    const QXmlName directory;
    const QXmlName file;
    const QXmlName olestream;
    const QXmlName olestreamdir;
    const QXmlName name;
    const QXmlName size;
    const QXmlName type;

    static const QMap<QString, QSharedPointer<const Introspectable> > read(const char* filepath) {
        QString file = QString::fromLocal8Bit(filepath);
        const QMap<QString, QByteArray> streams = readStreams(file);
        return parseStreams(streams);
    }

    Private(const QXmlNamePool& pool, const char* filepath_) :namepool(pool),
            filepath(filepath_),
            streams(read(filepath_)),
            directory(QXmlName(namepool, QLatin1String("directory"))),
            file(QXmlName(namepool, QLatin1String("file"))),
            olestream(QXmlName(namepool, QLatin1String("olestream"))),
            olestreamdir(QXmlName(namepool, QLatin1String("olestreamdir"))),
            name(QXmlName(namepool, QLatin1String("name"))),
            size(QXmlName(namepool, QLatin1String("size"))),
            type(QXmlName(namepool, QLatin1String("type"))) {
    }

    const Introspectable* getPreviousStream(const Introspectable* i) {
        const Introspectable* ps = 0;
        QMap<QString, QSharedPointer<const Introspectable> >::const_iterator it = streams.begin();
        while (it != streams.end()) {
            if (it.value() == i) {
                return ps;
            }
            ps = it.value().data();
            ++it;
        }
        return 0;
    }

    const Introspectable* getNextStream(const Introspectable* i) {
        const Introspectable* ps = 0;
        QMap<QString, QSharedPointer<const Introspectable> >::const_iterator it = streams.begin();
        while (it != streams.end()) {
            if (ps == i) {
                return it.value().data();
            }
            ps = it.value().data();
            ++it;
        }
        return 0;
    }

};

MsoXmlNodeModel::MsoXmlNodeModel(const QXmlNamePool& pool, const char* filepath) :d(new Private(pool, filepath)) {
}
MsoXmlNodeModel::~MsoXmlNodeModel() {
    delete d;
}

QVector<QXmlNodeModelIndex>
MsoXmlNodeModel::attributes(const QXmlNodeModelIndex& element) const {
    QVector<QXmlNodeModelIndex> v;
    qint64 type = element.additionalData();
    if (type != IntrospectableNode) {
        return v;
    }
    v.append(createIndex(element.data(), AttributeType));    
    return v;
}

QXmlNodeModelIndex
MsoXmlNodeModel::nextFromSimpleAxis(SimpleAxis axis, const QXmlNodeModelIndex& origin) const {
    const Introspectable* i = static_cast<const Introspectable*>(origin.internalPointer());
    qint64 type = origin.additionalData();
    QXmlNodeModelIndex node;

    if (type == Document) {
        node = createIndex((void*)0, File);
    } else if (type == File) {
        if (axis == Parent) {
            node = createIndex((void*)0, Document);
        } else if (axis == FirstChild) {
            const Introspectable* cs = d->getNextStream(0);
            if (cs) {
                node = createIndex((void*)cs, OLEStream);
            }
        }
    } else if (type == OLEStream) {
        if (axis == Parent) {
            node = createIndex((void*)0, File);
        } else if (axis == PreviousSibling) {
            const Introspectable* ps = d->getPreviousStream(i);
            if (ps) {
                node = createIndex((void*)ps, OLEStream);
            }
        } else if (axis == NextSibling) {
            const Introspectable* ns = d->getNextStream(i);
            if (ns) {
                node = createIndex((void*)ns, OLEStream);
            }
        } else if (axis == FirstChild) {
            qint64 additionalData;
            const Introspection* ci = getNextElement(i, 0, additionalData);
            if (ci) {
                node = createIndex((void*)ci, additionalData);
            }
        }
    } else if (type == IntrospectableNode) {
        if (axis == Parent) {
            if (i->parent->parent) { // parent is an introspectable
                node = createIndex((void*)i->parent, 
    } else if (type == AttributeType) {
        if (axis == Parent) {
            node = createIndex(origin.data(), IntrospectableNode);
        }
    } else if (type % 2 == 0) { // ValueElement
        if (axis = Parent) {
            node = createIndex(element.data(), IntrospectableNode);
        }
    } else { // Value
    }
    return node;
}

QUrl
MsoXmlNodeModel::baseUri(const QXmlNodeModelIndex& n) const {
    return documentUri(n);
}
QXmlNodeModelIndex::DocumentOrder
MsoXmlNodeModel::compareOrder(const QXmlNodeModelIndex& ni1, const QXmlNodeModelIndex& ni2) const {
    if (ni1.data() < ni2.data()) return QXmlNodeModelIndex::Precedes;
    return (ni1.data() == ni2.data()) ?QXmlNodeModelIndex::Is :QXmlNodeModelIndex::Follows;
}
QUrl
MsoXmlNodeModel::documentUri(const QXmlNodeModelIndex& n) const {
    return QUrl::fromLocalFile(d->filepath);
}
QXmlNodeModelIndex
MsoXmlNodeModel::elementById(const QXmlName& id) const {
    return QXmlNodeModelIndex();
}
QXmlNodeModelIndex::NodeKind
MsoXmlNodeModel::kind(const QXmlNodeModelIndex& ni) const {
    return ni.additionalData() == Element ? QXmlNodeModelIndex::Element : QXmlNodeModelIndex::Attribute;
}
QXmlName
MsoXmlNodeModel::name(const QXmlNodeModelIndex& ni) const {
    QVector<QXmlNodeModelIndex> v;
    Type type = getType(ni.data());
    switch (type) {
        case File:
            switch ((Kind)ni.additionalData()) {
                case Element: return d->getFileInfo(ni.data())->isFile() ?d->file :d->directory;
                case AttributeName: return d->name;
                case AttributeSize: return d->size;
            }
        case OLEStream:
            switch ((Kind)ni.additionalData()) {
                case Element: {
                    const OleStreamElementNode& e
                         = (const OleStreamElementNode&)d->getElementNode(ni.data());
                    return (e.isdir) ?d->olestreamdir :d->olestream;
                }
                case AttributeName: return d->name;
                case AttributeSize: return d->size;
            }
        case XmlElement:
        default: {
            QDomElement e = d->xmlelements[getIndex(ni.data())].element;
            if (ni.additionalData() == 0) {
                return QXmlName(d->namepool, e.nodeName());
            } else {
                return QXmlName(d->namepool, e.attributes().item(ni.additionalData()-1).nodeName());
            }
        }
    }
}
QVector<QXmlName>
MsoXmlNodeModel::namespaceBindings(const QXmlNodeModelIndex& n) const {
    return QVector<QXmlName>();
}
QVector<QXmlNodeModelIndex>
MsoXmlNodeModel::nodesByIdref(const QXmlName& idref) const {
    return QVector<QXmlNodeModelIndex>();
}
QXmlNodeModelIndex
MsoXmlNodeModel::root(const QXmlNodeModelIndex& n) const {
    int index = n.data();
    ElementNode& e = d->getElementNode(n.data());
    while (e.parentId != -1) {
         index = e.parentId;
         e = d->getElementNode(index);
    }
    return createIndex(index, 0);
}
QString
MsoXmlNodeModel::stringValue(const QXmlNodeModelIndex& n) const {
    return typedValue(n).toString();
}
QVariant
MsoXmlNodeModel::typedValue(const QXmlNodeModelIndex& n) const {
    Type type = getType(n.data());
    switch (type) {
        case File: {
            const QFileInfo* info = d->getFileInfo(n.data());
            switch ((Kind)n.additionalData()) {
                case AttributeName: return info->fileName();
                case AttributeSize: return info->size();
                default:;
            }
        }
        case OLEStream: {
            const OleStreamElementNode& e
                = (const OleStreamElementNode&)d->getElementNode(n.data());
            switch ((Kind)n.additionalData()) {
                case AttributeName: return e.streamname.c_str();
                case AttributeSize: return e.size;
                default:;
            }
        }
        case XmlElement: {
            if (n.additionalData() > 0) {
                QDomElement e = d->xmlelements[getIndex(n.data())].element;
                return e.attributes().item(n.additionalData()-1).nodeValue();
            }
        }
    }
    return QVariant();
}
