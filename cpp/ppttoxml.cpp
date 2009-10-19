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

QByteArray
escapeByteArray(const QByteArray& b) {
    // we escape all non printable byte values
    // printable is 9, 10, 13, 32-126
    QByteArray exclude(96, ' ');
    exclude[0] = 9; exclude[1] = 10; exclude[2] = 13;
    for (int i=3; i<8; ++i) {
        exclude[i] = i+29;
    }
    for (int i=8; i<96; ++i) {
        exclude[i] = i+30;
    }

    QByteArray result = b.toPercentEncoding(exclude);
    if (QByteArray::fromPercentEncoding(result) != b) {
        qDebug() << "Escaping of bytearray " << b << " is not reversible.";
        exit(1);
    }
    return result;
}

QVector<quint16>
toUInt16Vector(const QString& s) {
    QVector<quint16> v;
    QString z = QString::fromUtf8(QByteArray::fromPercentEncoding(s.toUtf8()));
    v.resize(z.size());
    for (int i=0; i<z.size(); ++i) {
        v[i] = z.utf16()[i];
    }
    return v;
}

QString
toString(const QVector<quint16>& v) {
    QString s;
    foreach(quint16 c, v) {
        s.append(c);
    }
    s = QString::fromUtf8(escapeByteArray(s.toUtf8()));
    // TODO: implement and check reversibility
/*
    if (toUInt16Vector(s) != v) {
        qDebug() << "Escaping of string " << v << " is not reversible.";
        qDebug() << toUInt16Vector(s);
        exit(1);
    }
*/
    return s;
}

void print(QXmlStreamWriter& out, const Introspectable* i);

void
printStyleTextPropAtom(QXmlStreamWriter& out, const Introspectable* i, int characterCount) {
    const Introspection* is = i->getIntrospection();

    // rh
    const Introspectable* ci = is->introspectable[0](i, 0);
    out.writeStartElement(is->names[0]);
    QString type = ci->getIntrospection()->name;
    out.writeAttribute("type", type);
    print(out, is->introspectable[0](i, 0)); // rh
    out.writeEndElement();

    // styles
    QByteArray blob = is->value[1](i, 0).toByteArray();
    QBuffer buffer;
    buffer.setData(blob);
    buffer.open(QIODevice::ReadOnly);
    LEInputStream listream(&buffer);

    try {
        int sum = 0;
        do {
            ci = parse("textPFRun", listream);
            const Introspection* cis = ci->getIntrospection();
            sum += cis->value[0](ci, 0).toInt();
            out.writeStartElement("rgTextPFRun");
            out.writeAttribute("type", "TextPFRun");
            print(out, ci);
            //qDebug() << "PF " << characterCount << " " << cis->value[0](ci, 0).toInt() << " " << sum;
            delete ci;
            out.writeEndElement();
        } while (sum <= characterCount);
        sum = 0;
        do {
            ci = parse("textCFRun", listream);
            const Introspection* cis = ci->getIntrospection();
            sum += cis->value[0](ci, 0).toInt();
            out.writeStartElement("rgTextCFRun");
            out.writeAttribute("type", "TextCFRun");
            print(out, ci);
            //qDebug() << "CF " << characterCount << " " << cis->value[0](ci, 0).toInt() << " " << sum;
            delete ci;
            out.writeEndElement();
        } while (sum < characterCount);
    } catch (IOException& e) {
        qDebug() << "Error: " << e.msg;
    }
}

void
print(QXmlStreamWriter& out, const Introspectable* i) {
    int lastCharacterCount = 0; // needed for parsing StyleTextPropAtom

    const Introspection* is = i->getIntrospection();
    for (int j=0; j<is->numberOfMembers; ++j) {
        for (int k=0; k<is->numberOfInstances[j](i); ++k) {
            out.writeStartElement(is->names[j]);
            const Introspectable* ci = is->introspectable[j](i, k);
            if (ci) {
                QString type = ci->getIntrospection()->name;
                out.writeAttribute("type", type);
                if (type == "StyleTextPropAtom") {
                    // StyleTextPropAtom is currently too hard to parse by the generated code
                    printStyleTextPropAtom(out, ci, lastCharacterCount);
                } else if (type == "TextCharsAtom") {
                    const Introspection* cis = ci->getIntrospection();
                    lastCharacterCount = cis->value[1](ci, 0).value<QVector<quint16> >().count();
                    print(out, ci);
                } else if (type == "TextBytesAtom") {
                    const Introspection* cis = ci->getIntrospection();
                    lastCharacterCount = cis->value[1](ci, 0).toByteArray().count();
                    print(out, ci);
                } else {
                    print(out, ci);
                }
            } else {
                QVariant v(is->value[j](i, k));
                if (v.canConvert<QVector<quint16> >()) {
                    out.writeCharacters(toString(v.value<QVector<quint16> >()));
                } else {
                    if (v.type() == QVariant::ByteArray) {
                        v = escapeByteArray(v.toByteArray());
                    }
                    out.writeCharacters(v.toString());
                }
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
    xmlout.writeProcessingInstruction("xml-stylesheet",
      "type='text/xsl' href='ppttosvg.xsl'");
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
                print(xmlout, i);
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
