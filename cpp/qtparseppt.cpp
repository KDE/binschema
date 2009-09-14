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

class Test : public Introspectable {
private:
    class _Introspection {
    private:
        static const QString name;
        static const int numberOfMembers;
        static const QString names[2];
        static const Introspection* const introspections[2];
        static int (*numberOfInstances[2])(const Introspectable*);
        static QVariant (*value[2])(const Introspectable*, int position);
        static const Introspectable* (* introspectable[2])(const Introspectable*, int position);

        static int countBElements(const Introspectable* i) {
            return static_cast<const Test*>(i)->b.size();
        }
        static QVariant getAElements(const Introspectable* i, int  ) {
            return static_cast<const Test*>(i)->a;
        }
        static QVariant getBElements(const Introspectable* i, int p) {
            return static_cast<const Test*>(i)->b[p];
        }
    public:
        static const Introspection introspection;
    };
public:
    int a;
    std::vector<float> b;

    Test() :a(0) {}
    const Introspection* getIntrospection() const { return &_Introspection::introspection; }
};

const QString Test::_Introspection::name = "Test";
const int Test::_Introspection::numberOfMembers = 2;
const QString Test::_Introspection::names[2] = { "a", "b" };
const Introspection* const Test::_Introspection::introspections[2] = { 0, 0 };
int (*Test::_Introspection::numberOfInstances[2])(const Introspectable*) = {Introspection::one, countBElements};
QVariant (*Test::_Introspection::value[2])(const Introspectable*, int p) = {getAElements, getBElements};
const Introspectable* (*Test::_Introspection::introspectable[2])(const Introspectable*, int position) = { Introspection::null, Introspection::null };

const Introspection Test::_Introspection::introspection(
    "Test", 2, names, numberOfInstances, value, introspectable);

int
main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    if (argc < 2) return -1;

    int (*memberCounter[2])(const Introspectable*) = {Introspection::one, Introspection::one};
    qDebug() << memberCounter[0](0);

    Test test;
    test.b.resize(3);
    const Introspection* introspection = test.getIntrospection();
    for (int i=0; i<introspection->numberOfMembers; ++i) {
        qDebug() << introspection->numberOfInstances[i](&test);
        for (int j=0; j<introspection->numberOfInstances[i](&test); ++j) {
            qDebug() << introspection->names[i] << "\t" << introspection->value[i](&test, j);
        }
    }

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
