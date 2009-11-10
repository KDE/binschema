#include "msoxmlnodemodel.h"
#include <QXmlSerializer>
#include <QXmlFormatter>
#include <QXmlQuery>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDebug>

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    if (argc != 3) return -1;

    QUrl queryUrl = QUrl::fromLocalFile(argv[1]);

    const QXmlNamePool namePool;
    MsoXmlNodeModel model(namePool, argv[2]);
    QXmlNodeModelIndex root = model.root(QXmlNodeModelIndex());

    QXmlQuery query(namePool);
    query.bindVariable("fileTree", root);
    query.setQuery(queryUrl);

    QFile out;
    out.open(stdout, QIODevice::WriteOnly);

    QXmlFormatter serializer(query, &out);
    query.evaluateTo(&serializer);

    return 0;
}
