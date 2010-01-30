#ifndef LEINPUT_H
#define LEINPUT_H

#include <QtCore/QtEndian>
#include <QtCore/QDebug>

inline quint8 readuint8(const char* d) {
    return *d;
}
inline quint16 readuint16(const char* d) {
    return qFromLittleEndian<quint16>((const unsigned char*)d);
}
inline qint16 readint16(const char* d) {
    return qFromLittleEndian<qint16>((const unsigned char*)d);
}
inline quint32 readuint32(const char* d) {
    return qFromLittleEndian<quint32>((const unsigned char*)d);
}
inline qint32 readint32(const char* d) {
    return qFromLittleEndian<qint32>((const unsigned char*)d);
}

inline bool readbit(const char* d) {
    return *d & 0x01;
}
inline bool readbit_1(const char* d) {
    return *d >> 1 & 0x01;
}
inline bool readbit_2(const char* d) {
    return *d >> 2 & 0x01;
}
inline bool readbit_3(const char* d) {
    return *d >> 3 & 0x01;
}
inline bool readbit_4(const char* d) {
    return *d >> 4 & 0x01;
}
inline bool readbit_5(const char* d) {
    return *d >> 5 & 0x01;
}
inline bool readbit_6(const char* d) {
    return *d >> 6 & 0x01;
}
inline bool readbit_7(const char* d) {
    return *d >> 7 & 0x01;
}
inline quint8 readuint2(const char* d) {
    return *d & 0x03;
}
inline quint8 readuint2_2(const char* d) {
    return *d >> 2 & 0x03;
}
inline quint8 readuint2_4(const char* d) {
    return *d >> 4 & 0x03;
}
inline quint8 readuint2_6(const char* d) {
    return *d >> 6 & 0x03;
}
inline quint8 readuint3(const char* d) {
    return *d & 0x07;
}
inline quint8 readuint3_2(const char* d) {
    return *d >> 2 & 0x07;
}
inline quint8 readuint3_5(const char* d) {
    return *d >> 5 & 0x07;
}
inline quint8 readuint4(const char* d) {
    return *d & 0x0F;
}
inline quint8 readuint4_2(const char* d) {
    return *d >> 2 & 0x0F;
}
inline quint8 readuint4_4(const char* d) {
    return *d >> 4 & 0x0F;
}
inline quint8 readuint5(const char* d) {
    return *d & 0x1F;
}
inline quint8 readuint5_3(const char* d) {
    return *d >> 3 & 0x1F;
}
inline quint8 readuint6(const char* d) {
    return *d & 0x3F;
}
inline quint8 readuint6_2(const char* d) {
    return *d >> 2 & 0x3F;
}
inline quint8 readuint7(const char* d) {
    return *d & 0x7F;
}
inline quint8 readuint7_1(const char* d) {
    return *d >> 1 & 0x7F;
}
inline quint16 readuint9(const char* d) {
    return readuint16(d) & 0x01FF;
}
inline quint16 readuint12_4(const char* d) {
    return readuint16(d) >> 4 & 0x0FFF;
}
inline quint16 readuint14(const char* d) {
    return readuint16(d) & 0x3FFF;
}
inline quint16 readuint14_2(const char* d) {
    return readuint16(d) >> 2 & 0x3FFF;
}
inline quint16 readuint15_1(const char* d) {
    return readuint16(d) >> 1 & 0x7FFF;
}
inline quint32 readuint20(const char* d) {
    return readuint32(d) & 0x0FFFFF;
}
inline quint32 readuint20_4(const char* d) {
    return readuint32(d) >> 4 & 0x0FFFFF;
}
inline quint32 readuint30(const char* d) {
    return readuint32(d) & 0x3FFFFFFF;
}

#endif
