#include "leinputstream.h"
#include "leoutputstream.h"
#include "introspection.h"
#include "pole.h"
#include <QBuffer>
#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>
#include <QVariant>
#include <cstdio>

const Introspectable* parse(const QString& key, LEInputStream& in);
void serialize(const Introspectable* i, const QString& key, LEOutputStream& out);

using namespace std;

QVariant
escapeByteArray(const QByteArray& b) {
    // we escape all non printable byte values
    // printable is 9, 10, 13, 32-126
    QByteArray exclude(97, ' ');
    exclude[0] = 9; exclude[1] = 10; exclude[2] = 13;
    for (int i=3; i<97; ++i) {
        exclude[i] = i+29;
    }
    return b.toPercentEncoding(exclude);
}

void
print(QXmlStreamWriter& out, const Introspectable* i) {
    const Introspection* is = i->getIntrospection();
    for (int j=0; j<is->numberOfMembers; ++j) {
        for (int k=0; k<is->numberOfInstances[j](i); ++k) {
            out.writeStartElement(is->names[j]);
            const Introspectable* ci = is->introspectable[j](i, k);
            if (ci) {
                out.writeAttribute("type", ci->getIntrospection()->name);
                print(out, ci);
            } else {
                QVariant v(is->value[j](i, k));
                if (v.type() == QVariant::ByteArray) {
                    v = escapeByteArray(v.toByteArray());
                }
                out.writeCharacters(v.toString());
            }
            out.writeEndElement();
        }
    }
}

void
write(const QString& name, const QByteArray& data) {
    QFile out(name);
    out.open(QIODevice::WriteOnly);
    out.write(data);
    out.close();
}

void
ppttoxml(const QString& file, QIODevice* out) {
    QXmlStreamWriter xmlout(out);
    xmlout.setAutoFormatting(true);
    xmlout.writeStartDocument();
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
            }

            if (listream.getPosition() != (qint64)stream.size()) {
                qDebug() << stream.size() - listream.getPosition()
                    << "trailing bytes in stream " << streamname;
                return;
            }
            buffer.close();

            xmlout.writeStartElement(i->getIntrospection()->name);
            print(xmlout, i);
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
