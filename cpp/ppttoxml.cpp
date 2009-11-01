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

void printWithCustomParser(QXmlStreamWriter& out, const Introspectable* i);

void
printStyleTextPropAtom(QXmlStreamWriter& out, const Introspectable* i, int characterCount) {
    const Introspection* is = i->getIntrospection();

    // rh
    const Introspectable* ci = is->introspectable[0](i, 0);
    out.writeStartElement(is->names[0]);
    QString type = ci->getIntrospection()->name;
    out.writeAttribute("type", type);
    printWithCustomParser(out, is->introspectable[0](i, 0)); // rh
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
            printWithCustomParser(out, ci);
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
            printWithCustomParser(out, ci);
            //qDebug() << "CF " << characterCount << " " << cis->value[0](ci, 0).toInt() << " " << sum;
            delete ci;
            out.writeEndElement();
        } while (sum < characterCount);
    } catch (IOException& e) {
        qDebug() << "Error: " << e.msg;
    }
}

void
printWithCustomParser(QXmlStreamWriter& out, const Introspectable* i) {
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
                    printWithCustomParser(out, ci);
                } else if (type == "TextBytesAtom") {
                    const Introspection* cis = ci->getIntrospection();
                    lastCharacterCount = cis->value[1](ci, 0).toByteArray().count();
                    printWithCustomParser(out, ci);
                } else {
                    printWithCustomParser(out, ci);
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
                printWithCustomParser(xmlout, i);
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
