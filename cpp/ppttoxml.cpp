#include "leinputstream.h"
#include "leoutputstream.h"
#include "introspection.h"
#include "utils.h"
#include "pole.h"
#include <QBuffer>
#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>
#include <QVariant>
#include <cstdio>

using namespace std;

void
ppttoxml(const QString& file, QIODevice* out) {
    QXmlStreamWriter xmlout(out);
    xmlout.setAutoFormatting(true);
    xmlout.writeStartDocument();
    xmlout.writeProcessingInstruction("xml-stylesheet", "type='text/xsl' href='ppttosvg.xsl'");
    xmlout.writeStartElement("ppt");
    POLE::Storage storage(file.toLocal8Bit());
    if (!storage.open()) return;

    string prefix;
    if (storage.isDirectory("PP97_DUALSTORAGE")) {
        prefix = "PP97_DUALSTORAGE/";
    } else {
        prefix = "/";
    }
    list<string> entries = storage.entries(prefix);
    for (list<string>::const_iterator i=entries.begin(); i!=entries.end(); ++i) {
        if (!storage.isDirectory(prefix+*i)) {
            POLE::Stream stream(&storage, prefix+*i);
            QString streamname(QString::fromStdString(*i));
            QByteArray array;
            array.resize(stream.size());
            unsigned long read = stream.read((unsigned char*)array.data(), stream.size());
            if (read != stream.size()) {
                qDebug() << "Error reading stream " << streamname;
                return;
            }
//                write("/tmp/"+streamname+".in", array);
            QBuffer buffer;
            buffer.setData(array);
            buffer.open(QIODevice::ReadOnly);
            LEInputStream listream(&buffer);
            qDebug() << "Parsing stream '" << streamname << "'";

            const Introspectable* i;
            try {
                i = parse(streamname, listream);
            } catch (IOException& e) {
                qDebug() << "Error: " << e.msg;
                continue;
            }

            if (listream.getPosition() != (qint64)stream.size()) {
                qDebug() << stream.size() - listream.getPosition()
                    << "trailing bytes in stream " << streamname;
                return;
            }
            buffer.close();

            xmlout.writeStartElement(i->getIntrospection()->name);
            if (i->getIntrospection()->name != "TODOS") {
                printWithExtendedParser(xmlout, i);
            }
            xmlout.writeEndElement();

            buffer.buffer().clear();
            buffer.open(QIODevice::WriteOnly);
            LEOutputStream lostream(&buffer);
            serialize(i, streamname, lostream);
//                write("/tmp/"+streamname+".out", buffer.data());
            if (array != buffer.data()) {
                qDebug() << "Serialized data different from original in "
                    << streamname;
            }

            delete i;
        }
    }
    xmlout.writeEndElement();
    xmlout.writeEndDocument();
}

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    if (argc != 2 && argc != 3) return -1;

    QFile out;
    if (argc == 3) {
        out.setFileName(argv[2]);
        out.open(QIODevice::WriteOnly);
    } else {
        out.open(stdout, QIODevice::WriteOnly);
    }
    ppttoxml(QLatin1String(argv[1]), &out);
    out.close();

    return 0;
}
