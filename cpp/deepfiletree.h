#ifndef DEEPFILETREE_H
#define DEEPFILETREE_H

#include <QAbstractXmlNodeModel>

class QFileInfo;

class DeepFileTree : public QAbstractXmlNodeModel {
public:
    DeepFileTree(const QXmlNamePool& pool);
    virtual ~DeepFileTree();

    QXmlNodeModelIndex toNodeIndex(const QFileInfo& fileinfo) const;

    virtual QVector<QXmlNodeModelIndex> attributes(const QXmlNodeModelIndex& element) const;
    virtual QXmlNodeModelIndex nextFromSimpleAxis(SimpleAxis axis, const QXmlNodeModelIndex& origin) const;
    virtual QUrl baseUri ( const QXmlNodeModelIndex & n ) const;
    virtual QXmlNodeModelIndex::DocumentOrder compareOrder ( const QXmlNodeModelIndex & ni1, const QXmlNodeModelIndex & ni2 ) const;
    virtual QUrl documentUri ( const QXmlNodeModelIndex & n ) const;
    virtual QXmlNodeModelIndex elementById ( const QXmlName & id ) const;
    virtual QXmlNodeModelIndex::NodeKind kind ( const QXmlNodeModelIndex & ni ) const;
    virtual QXmlName name ( const QXmlNodeModelIndex & ni ) const;
    virtual QVector<QXmlName> namespaceBindings ( const QXmlNodeModelIndex & n ) const;
    virtual QVector<QXmlNodeModelIndex> nodesByIdref ( const QXmlName & idref ) const;
    virtual QXmlNodeModelIndex root ( const QXmlNodeModelIndex & n ) const;
    virtual QString stringValue ( const QXmlNodeModelIndex & n ) const;
    virtual QVariant typedValue ( const QXmlNodeModelIndex & node ) const;
private:
    // do not copy
    DeepFileTree(const DeepFileTree&);

    class Private;
    Private* const d;
};

#endif
