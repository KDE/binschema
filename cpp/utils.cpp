#include "utils.h"
#include "pole.h"
#include "leinputstream.h"
#include "leoutputstream.h"
#include <QByteArray>
#include <QBuffer>
#include <QFile>
#include <QXmlStreamWriter>
#include <QDebug>

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

void
print(QXmlStreamWriter& out, const Introspectable* i) {
    const Introspection* is = i->getIntrospection();
    for (int j=0; j<is->numberOfMembers; ++j) {
        for (int k=0; k<is->numberOfInstances[j](i); ++k) {
            out.writeStartElement(is->names[j]);
            const Introspectable* ci = is->introspectable[j](i, k);
            if (ci) {
                QString type = ci->getIntrospection()->name;
                out.writeAttribute("type", type);
                uint32_t offset = ci->streamOffset;
                out.writeAttribute("offset", QString::number(offset));
                print(out, ci);
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

QMap<QString, QByteArray>
readStreams(const QString& file) {
    QMap<QString, QByteArray> streams;
    POLE::Storage storage(file.toLocal8Bit());
    if (!storage.open()) return streams;

    // TODO add support for directories
    string prefix = "/";
    list<string> entries = storage.entries(prefix);
    for (list<string>::const_iterator i=entries.begin(); i!=entries.end(); ++i){
        string path(prefix+*i);
        if (!storage.isDirectory(path)) {
            POLE::Stream stream(&storage, path);
            QString streamname(QString::fromStdString(*i));
            QByteArray array;
            array.resize(stream.size());
            unsigned long read = stream.read((unsigned char*)array.data(),
                    stream.size());
            if (read != stream.size()) {
                qDebug() << "Error reading stream " << streamname;
                streams.clear();
                return streams;
            }
            streams[path.c_str()] = array;
        }
    }

    return streams;
}

QMap<QString, QSharedPointer<const Introspectable> >
parseStreams(const QMap<QString, QByteArray>& streams) {
    QMap<QString, QSharedPointer<const Introspectable> > result;
    QMap<QString, QByteArray>::const_iterator i;
    for (i = streams.begin(); i!= streams.end(); ++i) {
        const QString streampath(i.key());
        const QString streamname = streampath.mid(streampath.lastIndexOf('/')+1);
        const QByteArray array(i.value());
        QBuffer buffer;
        buffer.setData(array);
        buffer.open(QIODevice::ReadOnly);
        LEInputStream listream(&buffer);
        qDebug() << "Parsing stream '" << streampath << "'";

        const Introspectable* i;
        try {
            i = parse(streamname, listream);
        } catch (IOException& e) {
            qDebug() << "Error: " << e.msg;
            continue;
        }

        if (listream.getPosition() != (qint64)array.size()) {
            qDebug() << array.size() - listream.getPosition()
                << "trailing bytes in stream " << streampath;
            result.clear();
            return result;
        }
        buffer.close();

        // test if serialization gives the same bytearray as that which came in
        buffer.buffer().clear();
        buffer.open(QIODevice::WriteOnly);
        LEOutputStream lostream(&buffer);
        serialize(i, streamname, lostream);
        if (array != buffer.data()) {
            qDebug() << "Serialized data different from original in "
                << streampath;
        }

        result[streampath] = QSharedPointer<const Introspectable>(i);
    }
    return result;
}

QMap<QString, QByteArray>
serialize(const QMap<QString, QSharedPointer<const Introspectable> >& m) {
    QMap<QString, QByteArray> streams;
    QMap<QString, QSharedPointer<const Introspectable> >::const_iterator i;
    for (i = m.begin(); i!= m.end(); ++i) {
        const QString streampath(i.key());
        const QString streamname
            = streampath.mid(streampath.lastIndexOf('/')+1);
        QBuffer buffer;
        buffer.open(QIODevice::WriteOnly);
        LEOutputStream lostream(&buffer);
        const Introspectable* is = i.value().data();
        serialize(is, streamname, lostream);
        streams[streampath] = buffer.data();
    }
    return streams;
}

void
write(const QString& name, const QByteArray& data) {
    QFile out(name);
    out.open(QIODevice::WriteOnly);
    out.write(data);
    out.close();
}

void printWithExtendedParser(QXmlStreamWriter& out, const Introspectable* i);

void
printStyleTextPropAtom(QXmlStreamWriter& out, const Introspectable* i,
            int characterCount) {
    const Introspection* is = i->getIntrospection();

    // rh
    const Introspectable* ci = is->introspectable[0](i, 0);
    out.writeStartElement(is->names[0]);
    QString type = ci->getIntrospection()->name;
    out.writeAttribute("type", type);
    printWithExtendedParser(out, is->introspectable[0](i, 0)); // rh
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
            printWithExtendedParser(out, ci);
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
            printWithExtendedParser(out, ci);
            //qDebug() << "CF " << characterCount << " " << cis->value[0](ci, 0).toInt() << " " << sum;
            delete ci;
            out.writeEndElement();
        } while (sum <= characterCount);
    } catch (IOException& e) {
        qDebug() << "Error: " << e.msg;
    }
    if (buffer.size() != listream.getPosition()) {
        qDebug() << "Error: " << buffer.size() - listream.getPosition()
            << " bytes left for StyleTextPropAtom at position "
            << i->streamOffset;
    }
}

void
printWithExtendedParser(QXmlStreamWriter& out, const Introspectable* i) {
    int lastCharacterCount = 0; // needed for parsing StyleTextPropAtom

    const Introspection* is = i->getIntrospection();
    for (int j=0; j<is->numberOfMembers; ++j) {
        for (int k=0; k<is->numberOfInstances[j](i); ++k) {
            out.writeStartElement(is->names[j]);
            const Introspectable* ci = is->introspectable[j](i, k);
            if (ci) {
                QString type = ci->getIntrospection()->name;
                out.writeAttribute("type", type);
                uint32_t offset = ci->streamOffset;
                out.writeAttribute("offset", QString::number(offset));
                if (type == "StyleTextPropAtom") {
                    // StyleTextPropAtom is currently too hard to parse by the generated code
                    printStyleTextPropAtom(out, ci, lastCharacterCount);
                } else if (type == "TextCharsAtom") {
                    const Introspection* cis = ci->getIntrospection();
                    lastCharacterCount = cis->value[1](ci, 0).value<QVector<quint16> >().count();
                    printWithExtendedParser(out, ci);
                } else if (type == "TextBytesAtom") {
                    const Introspection* cis = ci->getIntrospection();
                    lastCharacterCount = cis->value[1](ci, 0).toByteArray().count();
                    printWithExtendedParser(out, ci);
                } else {
                    printWithExtendedParser(out, ci);
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

QByteArray
streamsToXml(
            const QMap<QString, QSharedPointer<const Introspectable> >& streams,
            void (*printFunction)(QXmlStreamWriter&,const Introspectable*)) {
    QBuffer xml;
    xml.open(QBuffer::WriteOnly);
    QXmlStreamWriter xmlout(&xml);
    xmlout.setAutoFormatting(true);
    xmlout.writeStartDocument();
    xmlout.writeStartElement("ppt");
    QMap<QString, QSharedPointer<const Introspectable> >::const_iterator i;
    for (i = streams.begin(); i!= streams.end(); ++i) {
        const Introspection* in = i.value()->getIntrospection();
        xmlout.writeStartElement(in->name);
        xmlout.writeAttribute("stream-path", i.key());
        if (in->name != "TODOS") {
            printFunction(xmlout, i.value().data());
        }
        xmlout.writeEndElement();
    }
    xmlout.writeEndElement();
    xmlout.writeEndDocument();
    return xml.data();
}

QByteArray
streamsToXml(const QMap<QString,
            QSharedPointer<const Introspectable> >& streams) {
    return streamsToXml(streams, print);
}

QByteArray
streamsToExtendedXml(const QMap<QString,
            QSharedPointer<const Introspectable> >& streams) {
    return streamsToXml(streams, printWithExtendedParser);
}
