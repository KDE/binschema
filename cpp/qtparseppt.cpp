#include "leinputstream.h"
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

bool
parse(const QString& file) {
    try {
        POLE::Storage storage(file.toLocal8Bit());
        if (!storage.open()) return false;
        list<string> entries = storage.entries();
        for (list<string>::const_iterator i=entries.begin(); i!=entries.end(); ++i) {
            if (!storage.isDirectory(*i)) {
                POLE::Stream stream(&storage, "/"+*i);
                QString streamname(QString::fromStdString(*i));
                QByteArray array;
                array.resize(stream.size());
                unsigned long read = stream.read((unsigned char*)array.data(), stream.size());
                if (read != stream.size()) {
                    qDebug() << "Error reading stream " << streamname;
                    return false;
                }
                QBuffer buffer;
                buffer.setData(array);
                buffer.open(QIODevice::ReadOnly);
                LEInputStream lestream(&buffer);
                qDebug() << "Parsing stream '" << streamname << "'";
                const Introspectable* i = parse(streamname, lestream);
                QFile out;
                out.open(stdout, QIODevice::WriteOnly);
                QXmlStreamWriter xmlout(&out);
                xmlout.setAutoFormatting(true);
                xmlout.writeStartDocument();
                xmlout.writeStartElement(i->getIntrospection()->name);
                print(xmlout, i);
                xmlout.writeEndElement();
                xmlout.writeEndDocument();
                qDebug() << i->getIntrospection()->name;
                for (int j=0; j<i->getIntrospection()->numberOfMembers; ++j) {
                    qDebug() << " " << i->getIntrospection()->names[j];
                }
                delete i;
            }
        }
    } catch (IOException& e) {
        qDebug() << "Error: " << e.msg;
        return false;
    }
    return true;
}

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    if (argc < 2) return -1;

    for (int i=1; i<argc; ++i) {
        QString file(argv[i]);
        if (parse(file)) {
            qDebug() << "Parsing of " << file << " succeedded.";
        } else {
            qDebug() << "Parsing of " << file << " failed.";
        }
    }

    return 0;
}
