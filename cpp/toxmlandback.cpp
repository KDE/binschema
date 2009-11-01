#include "leinputstream.h"
#include "leoutputstream.h"
#include "introspection.h"
#include "utils.h"
#include <QBuffer>
#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>
#include <QVariant>
#include <cstdio>
#include <QSharedPointer>

/** 
 * This program reads mso ole files, converts the streams to runtime structures,
 * translates these runtime structures to xml, parses the xml back to runtime
 * structures, serializes those runtime structures to binary streams and checks
 * whether the resulting collestion of streams is the same as the original.
 **/

const Introspectable* parse(const QString& key, LEInputStream& in);
void serialize(const Introspectable* i, const QString& key, LEOutputStream& out);
const QMap<QString,QSharedPointer<const Introspectable> > parse(QXmlStreamReader& in);

using namespace std;

void
testfile(const QString& file) {
    const QMap<QString, QByteArray> streams = readStreams(file);
    const QMap<QString, QSharedPointer<const Introspectable> > introspectables
            = parseStreams(streams);
    QMap<QString, QByteArray> streams2 = serialize(introspectables);
    if (streams != streams2) {
        qDebug() << "Serialized streams are different from the original.";
        return;
    }
    const QByteArray xml = streamsToXml(introspectables);
    write("out", xml);
    QXmlStreamReader in(xml);
    const QMap<QString,QSharedPointer<const Introspectable> > introspectables2
            = parse(in);
    streams2 = serialize(introspectables2);
    if (streams != streams2) {
        qDebug() << "Serialized streams from xml are different from the original.";
    }
}

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    if (argc != 2) return -1;

    testfile(QLatin1String(argv[1]));

    return 0;
}
