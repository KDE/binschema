#include "leinputstream.h"
#include "leoutputstream.h"
#include "introspection.h"
#include "pole.h"
#include <QBuffer>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QVariant>
#include <cstdio>

const Introspectable* parse(const QString& key, LEInputStream& in);
void serialize(const Introspectable* i, const QString& key, LEOutputStream& out);

using namespace std;

void
write(const QString& name, const QByteArray& data) {
    QFile out(name);
    out.open(QIODevice::WriteOnly);
    out.write(data);
    out.close();
}

bool
parse(const QString& file) {
    try {
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
                POLE::Stream stream(&storage, prefix+*i);
                QString streamname(QString::fromStdString(*i));
                QByteArray array;
                array.resize(stream.size());
                unsigned long read = stream.read((unsigned char*)array.data(), stream.size());
                if (read != stream.size()) {
                    qDebug() << "Error reading stream " << streamname;
                    return false;
                }
//                write("/tmp/"+streamname+".in", array);
                QBuffer buffer;
                buffer.setData(array);
                buffer.open(QIODevice::ReadOnly);
                LEInputStream listream(&buffer);
                qDebug() << "Parsing stream '" << streamname << "'";
                const Introspectable* i = parse(streamname, listream);
                if (listream.getPosition() != (qint64)stream.size()) {
                    qDebug() << stream.size() - listream.getPosition()
                        << "trailing bytes in stream " << streamname;
                    return false;
                }
                buffer.close();

                buffer.buffer().clear();
                buffer.open(QIODevice::WriteOnly);
                LEOutputStream lostream(&buffer);
                serialize(i, streamname, lostream);
//                write("/tmp/"+streamname+".out", buffer.data());
                if (array != buffer.data()) {
                    qDebug() << "Serialized data different from original in "
                        << streamname;
                    return false;
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
        qDebug() << "Parsing of " << file;
        if (parse(file)) {
            qDebug() << "Parsing of " << file << " succeedded.";
        } else {
            qDebug() << "Parsing of " << file << " failed.";
        }
    }

    return 0;
}
