#include "api.h"
#include "pole.h"
#include <QtCore/QDebug>

void
testFile(const char* path) {
    POLE::Storage storage(path);
    if (!storage.open()) return;
    POLE::Stream stream(&storage, "/PowerPoint Document");
    QByteArray array;
    array.resize(stream.size());
    unsigned long read = stream.read((unsigned char*)array.data(), stream.size());
    if (read != stream.size()) {
        qDebug() << "Error reading stream ";
        return;
    }
    qDebug() << "Parsing stream of size " << array.size();
    PPT::PowerPointStructs s(array.data(), array.size());
    qDebug() << "Parsed: " << (s._data != 0) << " " << s._size;
}
int
main(int argc, char** argv) {
    for (int i=1; i<argc; ++i) {
        testFile(argv[i]);
    }
    return 0;
}
