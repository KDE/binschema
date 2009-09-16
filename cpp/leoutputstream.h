#ifndef LEOUTPUTSTREAM_H
#define LEOUTPUTSTREAM_H

#include <QtCore/QIODevice>
#include <QtCore/QDataStream>
#include <exception>

class LEOutputStream {
private:
    QIODevice* output;
    QDataStream data;

    qint8 bitfieldpos;
    quint8 bitfield;

    void writeBits(quint8 n, quint8 v) {
        bitfield = v << bitfieldpos | bitfield;
        bitfieldpos += n;
        if (bitfieldpos == 8) {
            data << bitfield;
            bitfield = 0;
            bitfieldpos = 0;
        } else if (bitfieldpos > 8) {
            throw IOException("Bitfield does not have enough bits left.");
        }
    }

    void checkForLeftOverBits() const {
        if (bitfieldpos != 0) {
            throw IOException(
                "Cannot read this type halfway through a bit operation.");
        }
    }

public:

    LEOutputStream(QIODevice* out) :output(out), data(out) {
        bitfield = 0;
        bitfieldpos = 0;
        data.setByteOrder(QDataStream::LittleEndian);
    }

    void writebit(bool v) {
        writeBits(1, (v) ?1 :0);
    }

    void writeuint2(quint8 v) {
        writeBits(2, v);
    }

    void writeuint3(quint8 v) {
        writeBits(3, v);
    }

    void writeuint4(quint8 v) {
        writeBits(4, v);
    }

    void writeuint5(quint8 v) {
        writeBits(5, v);
    }

    void writeuint6(quint8 v) {
        writeBits(6, v);
    }

    void writeuint7(quint8 v) {
        writeBits(7, v);
    }

    void writeuint9(quint16 v) {
        data << (quint8) v;
        writeBits(1, v >> 8);
    }

    void writeuint12(quint16 v) {
        writeBits(4, v);
        data << (quint8)(v >> 4);
    }

    void writeuint14(quint16 v) {
        if (bitfieldpos == 0) {
            data << (quint8) v;
            writeBits(6, v >> 8);
        } else if (bitfieldpos == 2) {
            writeBits(6, v);
            data << (quint8)(v >> 6);
        } else {
            throw IOException(
                "Cannot write this type halfway through a bit operation.");
        }
    }

    void writeuint15(quint16 v) {
        // we assume there are 7 bits left
        writeBits(7, v);
        data << (quint8)(v >> 7);
    }

    void writeuint20(quint32 v) {
        if (bitfieldpos == 0) {
            data << (quint8) v;
            data << (quint8)(v >> 8);
            writeBits(4, v >> 16);
        } else if (bitfieldpos == 4) {
            writeBits(4, v);
            data << (quint8)(v >> 4);
            data << (quint8)(v >> 12);
        } else {
            throw IOException(
                "Cannot write this type halfway through a bit operation.");
        }
    }

    void writeuint30(quint32 v) {
        checkForLeftOverBits();
        data << (quint8) v;
        data << (quint8)(v >> 8);
        data << (quint8)(v >> 16);
        writeBits(6, v >> 24);
    }

    void writeuint8(quint8 v) {
        checkForLeftOverBits();
        data << v;
    }

    void writeint16(qint16 v) {
        checkForLeftOverBits();
        data << v;
    }

    void writeuint16(quint16 v) {
        checkForLeftOverBits();
        data << v;
    }

    void writeuint32(quint32 v) {
        checkForLeftOverBits();
        data << v;
    }

    void writeint32(qint32 v) {
        checkForLeftOverBits();
        data << v;
    }

    void writeBytes(const QByteArray& b) {
        int offset = 0;
        int todo = b.size();
        do {
            int nwritten = data.writeRawData(b.data() + offset, todo);
            if (nwritten == -1) return; //TODO report error
            todo -= nwritten;
            offset += nwritten;
        } while (todo > 0);
    }

    quint64 getPosition() const { return output->pos(); }
};

#endif
