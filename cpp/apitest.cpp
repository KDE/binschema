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
    PPT::PowerPointStructs s(array.data(), array.size());
    qDebug() << "Parsed " << s._size << " of " << array.size() << ": "
        << ((s._size == array.size())?"OK":"FAIL");
}
int
main(int argc, char** argv) {
    for (int i=1; i<argc; ++i) {
        testFile(argv[i]);
    }
    return 0;
}
