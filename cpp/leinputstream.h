#ifndef LEINPUTSTREAM_H
#define LEINPUTSTREAM_H

#include <QtCore/QtGlobal>
#include <exception>

class IncorrectValueException : public std::exception {
public:
    IncorrectValueException(const QString&) {}
};

class EOFException : public std::exception {
public:
    EOFException(const QString&) {}
};

class LEInputStream {
public:
    class Mark {
    public:
         ~Mark() {
             // TODO: release mark from stream
         }
    };

    Mark setMark() { return Mark(); }
    void rewind(const Mark& m) {}

    bool readbit() { return false; }
    quint8 readuint2() { return 0; }
    quint8 readuint3() { return 0; }
    quint8 readuint4() { return 0; }
    quint8 readuint5() { return 0; }
    quint8 readuint6() { return 0; }
    quint8 readuint7() { return 0; }
    quint8 readuint8() { return 0; }
    quint8 readuint9() { return 0; }
    quint16 readuint12() { return 0; }
    quint16 readuint14() { return 0; }
    quint16 readuint15() { return 0; }
    quint16 readuint16() { return 0; }
    quint16 readuint20() { return 0; }
    quint32 readuint30() { return 0; }
    quint32 readuint32() { return 0; }
    qint16 readint16() { return 0; }
    qint32 readint32() { return 0; }

    quint32 getPosition() const { return 0; }
};

#endif
