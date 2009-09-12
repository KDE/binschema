#include "deepfiletree.h"
#include <QXmlSerializer>
#include <QXmlQuery>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDebug>

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    if (argc != 2) return -1;

    QUrl queryUrl = QUrl::fromLocalFile(argv[1]);

    const QXmlNamePool namePool;
    DeepFileTree fileTreeModel(namePool);
    QXmlNodeModelIndex fileTree = fileTreeModel.toNodeIndex(
        QFileInfo("../../tests/"));
    //QXmlNodeModelIndex fileTree = fileTreeModel.nodeFor("/home/oever/workspace/msoparser/cpp/");

    QXmlQuery query(namePool);
    query.bindVariable("fileTree", fileTree);
    query.setQuery(queryUrl);

    QFile out;
    out.open(stdout, QIODevice::WriteOnly);

    QXmlSerializer serializer(query, &out);
    query.evaluateTo(&serializer);

    return 0;
}
