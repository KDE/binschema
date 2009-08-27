#ifndef LEINPUTSTREAM_H
#define LEINPUTSTREAM_H

class IncorrectValueException : public std::exception {
public:
    IncorrectValueException(const QString&) {}
};

class LEInputStream {
public:
    quint8 readuint4() { return 0; }
    quint8 readuint8() { return 0; }
    quint16 readuint12() { return 0; }
    quint16 readuint16() { return 0; }
    quint32 readuint32() { return 0; }

    quint32 getPosition() const { return 0; }
};

#endif
