#ifndef LEINPUT_H
#define LEINPUT_H

#include <QtCore/QtEndian>

template <typename T>
class MSOCastArray {
private:
    const T* _data;
    quint32 _count;
public:
    MSOCastArray() :_data(0), _count(0) {}
    MSOCastArray(const T* data, qint32 count) :_data(data), _count(count) {}
    const T* data() const;
    QByteArray mid(int pos, int len = -1) const;
    int size() const;
    T operator[](int pos) const { return _data[pos]; }
    bool operator!=(const QByteArray&);
    operator QByteArray() const;
};

template <typename T>
class MSOconst_iterator {
private:
    mutable T currentItem;
public:
    bool operator!=(const MSOconst_iterator &o) const;
    void operator++();
    const T& operator*() const {
        return currentItem;
    }
};

template <typename T>
class MSOFixedArray {
public:
    typedef MSOconst_iterator<T> const_iterator;
    const char* _data;
    quint32 _count;
    quint32 _size;
    MSOFixedArray() :_data(0), _count(0), _size(0) {}
    MSOFixedArray(const char* _d, quint32 _maxsize) :_data(0), _count(0), _size(0) {
        quint32 _msize = 0;
        quint32 _mcount = 0;
        while (_msize < _maxsize) {
            T _v(_d + _msize);
            if (_v._data == 0) return;
            _msize += T::_size;
            _mcount++;
        }
        _data = _d;
        _count = _mcount;
        _size = _msize;
    }
    MSOFixedArray(const char* _d, quint32 _maxsize, quint32 _mcount) :_data(0), _count(0), _size(0) {
        quint32 _msize = 0;
        for (quint32 _i = 0; _i < _mcount; ++_i) {
            T _v(_d + _msize);
            if (_v._data == 0) return;
            _msize += T::_size;
            if (_msize > _maxsize) return;
        }
        _data = _d;
        _count = _mcount;
        _size = _msize;
    }
    int size() const;
    MSOconst_iterator<T> begin() const;
    MSOconst_iterator<T> end() const;
};
template <typename T>
class MSOArray {
public:
    typedef MSOconst_iterator<T> const_iterator;
    const char* _data;
    quint32 _count;
    quint32 _size;
    MSOArray() :_data(0), _count(0), _size(0) {}
    MSOArray(const char* _d, quint32 _maxsize) :_data(0), _count(0), _size(0) {
        quint32 _msize = 0;
        quint32 _mcount = 0;
        while (_msize < _maxsize) {
            T _v(_d + _msize, _maxsize - _msize);
            if (_v._data == 0) return;
            _msize += _v._size;
            _mcount++;
        }
        _data = _d;
        _count = _mcount;
        _size = _msize;
    }
    MSOArray(const char* _d, quint32 _maxsize, quint32 _mcount) :_data(0), _count(0), _size(0) {
        quint32 _msize = 0;
        for (quint32 _i = 0; _i < _mcount; ++_i) {
            T _v(_d + _msize, _maxsize - _msize);
            if (_v._data == 0) return;
            _msize += _v._size;
            if (_msize > _maxsize) return;
        }
        _data = _d;
        _count = _mcount;
        _size = _msize;
    }
    int size() const;
    MSOconst_iterator<T> begin() const;
    MSOconst_iterator<T> end() const;
    const T operator[](quint32) const { return T(); }
};

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
inline quint16 readuint13_3(const char* d) {
    return readuint16(d) >> 3 & 0x1FFF;
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
