#include "leinputstream.h"
#include "pole.h"
#include <QBuffer>
#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <QTextStream>
#include <QStringList>
#include <QDomDocument>

#include <cstdio>

using namespace std;

void
printStructure(LEInputStream& in, int depth, QTextStream& out,
        const QMap<int, QString>& recordTypeNames) {
    quint8 recVer = in.readuint4();
    quint16 recInstance = in.readuint12();
    quint16 recType = in.readuint16();
    quint32 recLen = in.readuint32();

    QString hexinstance = QString::number(recInstance, 16);
    QString hextype = QString::number(recType, 16);
    QString t = "\t";
    out << depth << t << recVer << t << hexinstance << t << hextype << t << recLen << t << in.getPosition() << t << recordTypeNames.value(recType) << endl;

    if (recVer == 0xF && recType != 0x428) {
        int end = in.getPosition() + recLen;
        while (in.getPosition() != end) {
            if (in.getPosition() > end) {
                throw IOException("structure is too long");
            }
            printStructure(in, depth + 1, out, recordTypeNames);
        }
    } else {
        in.skip(recLen);
    }
}

bool
parse(const QString& file, const QMap<int, QString>& recordTypeNames) {
    QFile out;
    out.open(stdout, QIODevice::WriteOnly);
    QTextStream textout(&out);
    POLE::Storage storage(file.toLocal8Bit());
    if (!storage.open()) return false;

    string prefix;
    if (storage.isDirectory("PP97_DUALSTORAGE")) {
        prefix = "PP97_DUALSTORAGE/";
    } else {
        prefix = "/";
    }
    list<string> entries = storage.entries(prefix);
    for (list<string>::const_iterator i=entries.begin(); i!=entries.end(); ++i) {
        if (!storage.isDirectory(prefix+*i)) {
            try {
                POLE::Stream stream(&storage, prefix+*i);
                QString streamname(QString::fromStdString(*i));
                textout << "Stream '" << streamname << "':" << endl;
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
                LEInputStream listream(&buffer);
                while (listream.getPosition() != buffer.size()) {
                    printStructure(listream, 0, textout, recordTypeNames);
                }
            } catch (IOException& e) {
                qDebug() << "Error: " << e.msg;
            }
        }
    }
    return true;
}

QMap<int, QString>
getRecordTypeNames(const QString& filename) {
    QDomDocument dom;
    QFile f(filename);
    f.open(QIODevice::ReadOnly);
    dom.setContent(&f);

    QMap<int, QString> map;
    QDomNodeList limits = dom.elementsByTagName("limitation");
    for (int i=0; i<limits.count(); ++i) {
        QDomElement l = limits.item(i).toElement();
        if (l.attribute("name") == "recType") {
            QString name
                = l.parentNode().parentNode().toElement().attribute("name");
            QString value = l.attribute("value").replace("0x", "");
            foreach (QString s, value.split("|")) {
                bool ok;
                int typeNumber = s.toInt(&ok, 16);
                if (map.contains(typeNumber)) {
                    map[typeNumber] += "/" + name;
                } else {
                    map[typeNumber] = name;
                }
            }
        }
    }

    return map;
}

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    //if (argc < 2) return -1;

    const QMap<int, QString> recordTypeNames
        = getRecordTypeNames("../../src/mso.xml");

    for (int i=1; i<argc; ++i) {
        QString file(argv[i]);
        qDebug() << "Parsing of " << file;
        if (parse(file, recordTypeNames)) {
            qDebug() << "Parsing of " << file << " succeedded.";
        } else {
            qDebug() << "Parsing of " << file << " failed.";
        }
    }

    return 0;
}
