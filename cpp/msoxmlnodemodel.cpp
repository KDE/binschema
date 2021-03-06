#include "msoxmlnodemodel.h"
#include "utils.h"
#include <QtXmlPatterns/QXmlNamePool>
#include <QtCore/QUrl>
#include <QDebug>

using namespace std;

/** This XML model spans one OLE stream file.
 * The root node corresponds to the file. The child elements of the root
 * correspond to streams.
 * Below the streams, the elements can correspond to introspectables or values.
 * Each Introspectable contains a colleciont of Introspectables and values.
 * Each value is represented by a value element and a value text field.
 * There is a tree of introspectables available. Values (QVariants) do not know
 * about their parents and have to have a the pointer to their introspectable of
 * stream as a parent. The additionalData() filed of the QXmlNodeindex should
 * contain this information.
 * The data() field is a pointer to the introspectable also for the stream.
 **/
namespace {

/** The field additionalData() in QXmlNodeModelIndex is used for storing four
 *  bits of information while keeping the field increasing in value with
 *  document order. The value of the field data() is the same for each node
 *  below another node that is not a numbers: field type, member number and
 *  index in the member. These fields are
 **/

class Node {
public:
    enum Type { Document, RootElement, Stream, Introspectable, ValueElement };
    const void* data;
    int parent;
    int prev;
    int next;
    int firstChild;
    Type type;
    int memberno;
    int arrayno;

    Node() :data(0), parent(-1), prev(-1), next(-1), firstChild(-1) {}
};

int
countItems(const Introspectable* i) {
    if (i == 0) return 0;
    const Introspection* is = i->getIntrospection();
    int n = 0;
    for (int j=0; j<is->numberOfMembers; ++j) {
        for (int k=0; k<is->numberOfInstances[j](i); ++k) {
            const Introspectable* ci = is->introspectable[j](i, k);
            if (ci) {
                n += 1 + countItems(ci);
            } else {
                n += 1; // empty value element
            }
        }
    }
    return n;
}

int
countItems(const QMap<QString, QSharedPointer<const Introspectable> >& streams){
    int n = 2;
    QMap<QString, QSharedPointer<const Introspectable> >::const_iterator it
        = streams.begin();
    while (it != streams.end()) {
        n += 1 + countItems(it.value().data());
        it++;
    }
    return n;
}

void
addIntrospectable(QVector<Node>& nodes, const Introspectable* i, int pos,
        int parent) {
    if (i == 0) return;
    const Introspection* is = i->getIntrospection();
    nodes[pos].parent = parent;
    nodes[pos].data = i;
    nodes[pos].type = Node::Introspectable;
    int prevp = -1;
    int p = pos+1;
    for (int j=0; j<is->numberOfMembers; ++j) {
        for (int k=0; k<is->numberOfInstances[j](i); ++k) {
            const Introspectable* ci = is->introspectable[j](i, k);
            if (nodes[pos].firstChild == -1) {
                nodes[pos].firstChild = p;
            }
            if (prevp != -1) {
                nodes[p].prev = prevp;
                nodes[prevp].next = p;
            }
            prevp = p;
            nodes[p].memberno = j;
            nodes[p].arrayno = k;
            if (ci) {
                addIntrospectable(nodes, ci, p, pos);
                p += 1 + countItems(ci);
            } else {
                nodes[p].parent = pos;
                nodes[p].data = i;
                nodes[p].type = Node::ValueElement;
                p += 1; // skip empty position
            }
        }
    }
}

QVector<Node>
createNodes(const QMap<QString, QSharedPointer<const Introspectable> >&
        streams) {
    QVector<Node> nodes(countItems(streams));
    nodes[0].parent = -1; nodes[0].prev = -1; nodes[0].next = -1;
    nodes[0].firstChild = 1; nodes[0].type = Node::Document;
    nodes[1].parent =  0; nodes[1].prev = -1; nodes[1].next = -1;
    nodes[1].firstChild = (streams.size()) ?2 :-1;
    nodes[1].type = Node::RootElement;
    int prevp = -1;
    int p = 2;
    QMap<QString, QSharedPointer<const Introspectable> >::const_iterator it
        = streams.begin();
    while (it != streams.end()) {
        const Introspectable* i = it.value().data();
        addIntrospectable(nodes, i, p, 1);
        if (prevp != -1) {
            nodes[p].prev = prevp;
            nodes[prevp].next = p;
        }
        nodes[p].type = Node::Stream;
        prevp = p;
        p += 1 + countItems(i);
        it++;
    }
    return nodes;
}

}

class MsoXmlNodeModel::Private {
public:
    QXmlNamePool namepool;
    QString filepath;
    const QMap<QString, QSharedPointer<const Introspectable> > streams;
    const QVector<Node> nodes;
    const QXmlName ppt;
    const QXmlName directory;
    const QXmlName file;
    const QXmlName olestream;
    const QXmlName olestreamdir;
    const QXmlName name;
    const QXmlName size;
    const QXmlName type;

    static const QMap<QString, QSharedPointer<const Introspectable> > read(
            const char* filepath) {
        QString file = QString::fromLocal8Bit(filepath);
        const QMap<QString, QByteArray> streams = readStreams(file);
        return parseStreams(streams);
    }

    Private(const QXmlNamePool& pool, const char* filepath_) :namepool(pool),
            filepath(filepath_),
            streams(read(filepath_)),
            nodes(createNodes(streams)),
            ppt(QXmlName(namepool, QLatin1String("ppt"))),
            directory(QXmlName(namepool, QLatin1String("directory"))),
            file(QXmlName(namepool, QLatin1String("file"))),
            olestream(QXmlName(namepool, QLatin1String("olestream"))),
            olestreamdir(QXmlName(namepool, QLatin1String("olestreamdir"))),
            name(QXmlName(namepool, QLatin1String("name"))),
            size(QXmlName(namepool, QLatin1String("size"))),
            type(QXmlName(namepool, QLatin1String("type"))) {
    }

    void getIndex(QAbstractXmlNodeModel::SimpleAxis axis, qint64& data,
            qint64& additionalData) {
        if (additionalData == 1) {
            additionalData = 0;
            if (axis != Parent) data = -1;
            return;
        }
        const Node& node = nodes[data];
        // additionalData = 0;
        if (axis == Parent) {
            data = node.parent;
            return;
        }
        if (axis == FirstChild) {
            if (node.type == Node::ValueElement) {
                additionalData = 1;
            } else {
                data = node.firstChild;
            }
            return;
        }
        data = (axis == NextSibling) ?node.next :node.prev;
    }
 
    QXmlName getName(qint64 n, qint64 a) {
        if (a) return type;
        const Node& node = nodes[n];
        const Introspectable* i
            = static_cast<const Introspectable*>(nodes[node.parent].data);
        const Introspection* si = i->getIntrospection();
        return QXmlName(namepool, si->names[node.memberno]);
    }
};

MsoXmlNodeModel::MsoXmlNodeModel(const QXmlNamePool& pool, const char* filepath)
        :d(new Private(pool, filepath)) {
}
MsoXmlNodeModel::~MsoXmlNodeModel() {
    delete d;
}

QVector<QXmlNodeModelIndex>
MsoXmlNodeModel::attributes(const QXmlNodeModelIndex& element) const {
    QVector<QXmlNodeModelIndex> v;
    const Node& node = d->nodes[element.data()];
    if (node.type == Node::Introspectable && element.additionalData() == 0) {
        v.append(createIndex(element.data(), 1));
    }
    return v;
}

QXmlNodeModelIndex
MsoXmlNodeModel::nextFromSimpleAxis(SimpleAxis axis,
        const QXmlNodeModelIndex& origin) const {
    qint64 data = -1;
    qint64 additionalData = 0;
    const Node& node = d->nodes[origin.data()];
    if (node.type == Node::Introspectable || node.type == Node::ValueElement) {
        data = origin.data();
        additionalData = origin.additionalData();
        d->getIndex(axis, data, additionalData);
    } else {
        switch (axis) {
            case Parent:          data = node.parent;     break;
            case FirstChild:      data = node.firstChild; break;
            case PreviousSibling: data = node.prev;       break;
            case NextSibling:     data = node.next;       break;
            default: break;
        }
    }
    return (data == -1)
        ?QXmlNodeModelIndex() :createIndex(data, additionalData);
}

QUrl
MsoXmlNodeModel::baseUri(const QXmlNodeModelIndex& n) const {
    return documentUri(n);
}
QXmlNodeModelIndex::DocumentOrder
MsoXmlNodeModel::compareOrder(const QXmlNodeModelIndex& ni1,
        const QXmlNodeModelIndex& ni2) const {
    if (ni1.data() < ni2.data()) return QXmlNodeModelIndex::Precedes;
    if (ni1.data() == ni2.data()) {
        if (ni1.additionalData() < ni2.additionalData())
            return QXmlNodeModelIndex::Precedes;
        if (ni1.additionalData() == ni2.additionalData())
            return QXmlNodeModelIndex::Is;
    }
    return QXmlNodeModelIndex::Follows;
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
    if (ni.data() == 0) return QXmlNodeModelIndex::Document;
    if (ni.additionalData() == 1) {
        const Node& node = d->nodes[ni.data()];
        if (node.type == Node::Introspectable) {
            return QXmlNodeModelIndex::Attribute;
        }
        return QXmlNodeModelIndex::Text;
    }
    return QXmlNodeModelIndex::Element; // no attributes yet
}
QXmlName
MsoXmlNodeModel::name(const QXmlNodeModelIndex& ni) const {
    const Node& node = d->nodes[ni.data()];
    const Introspectable* i = static_cast<const Introspectable*>(node.data);
    const Introspection* si = (i) ?i->getIntrospection() :0;
    switch (node.type) {
        case Node::Document: return d->name; // should not matter
        case Node::RootElement: return d->ppt; 
        case Node::Stream: return QXmlName(d->namepool, si->name);
        case Node::Introspectable:
            return d->getName(ni.data(), ni.additionalData());
        case Node::ValueElement:
            return d->getName(ni.data(), ni.additionalData());
        default: break;
    }
    return QXmlName();
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
    return createIndex((qint64)0);
}
QString
MsoXmlNodeModel::stringValue(const QXmlNodeModelIndex& n) const {
    return typedValue(n).toString();
}
QVariant
MsoXmlNodeModel::typedValue(const QXmlNodeModelIndex& n) const {
    if (n.additionalData() == 1) { //attribute or value type
        const Node& node = d->nodes[n.data()];
        const Introspectable* i
            = static_cast<const Introspectable*>(d->nodes[n.data()].data);
        const Introspection* si = i->getIntrospection();
        if (node.type == Node::Introspectable) {
            return si->name;
        }
        return si->value[node.memberno](i, node.arrayno);
    }
    return QVariant();
}
