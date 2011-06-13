#include "leinputstream.h"
#include "simpleParser.h"
#include "pole.h"
#include <QtCore/QBuffer>
#include <QtCore/QDebug>

using namespace std;

void
testFile(const char* path) {
    POLE::Storage storage(path);
    if (!storage.open()) return;
    string prefix;
    if (storage.isDirectory("PP97_DUALSTORAGE")) {
        prefix = "PP97_DUALSTORAGE/";
    } else {
        prefix = "/";
    }
    list<string> entries = storage.entries(prefix);
    for (list<string>::const_iterator i=entries.begin(); i!=entries.end(); ++i) {
        // if encrypted, do not report failure.
        if (*i == "EncryptedSummary") return;
    }
    POLE::Stream stream(&storage, prefix + "PowerPoint Document");

    QByteArray array;
    array.resize(stream.size());
    unsigned long read = stream.read((unsigned char*)array.data(), stream.size());
    if (read != stream.size()) {
        qDebug() << "Error reading stream ";
        return;
    }
    QBuffer buffer(&array);
    buffer.open(QIODevice::ReadOnly);
    LEInputStream listream(&buffer);
    MSO::PowerPointStructs pps;
    try {
        parsePowerPointStructs(listream, pps);
    } catch (...) {
        qDebug() << "Error while parsing.";
    }
    qDebug() << "Parsed " << buffer.pos() << " of " << array.size() << ": "
        << ((buffer.pos() == array.size())?"OK":"FAIL");
    if (buffer.pos() != array.size()) {
        qDebug() << path;
    }
}
int
main(int argc, char** argv) {
    for (int i=1; i<argc; ++i) {
        testFile(argv[i]);
    }
    return 0;
}
