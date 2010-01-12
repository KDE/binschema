#ifndef INTROSPECTION_H
#define INTROSPECTION_H

// define TREEINTROSPECTION to let objects have a pointer to their parents
#define TREEINTROSPECTION

#include <QtCore/QVariant>
#include <QtCore/QVector>
#include <stdint.h>

class Introspectable;

Q_DECLARE_METATYPE(QVector<quint16>);
Q_DECLARE_METATYPE(QVector<quint32>);

class Introspection {
public:
    const QString name;
    const int numberOfMembers;
    const QString* const names;
    int (* const * const numberOfInstances)(const Introspectable*);
    QVariant (* const * const value)(const Introspectable*, int position);
    const Introspectable* (* const * const introspectable)(const Introspectable*, int position);

    Introspection(const QString& n,
            const int nOM,
            const QString* const ns,
            int (* const * const mC)(const Introspectable*),
            QVariant (* const * const vG)(const Introspectable*, int),
            const Introspectable* (* const * const i)(const Introspectable*, int))
        :name(n), numberOfMembers(nOM), names(ns),
         numberOfInstances(mC), value(vG), introspectable(i) {}

    // convenience
    static int zero(const Introspectable*) { return 0; }
    static int one(const Introspectable*) { return 1; }
    static const Introspectable* null(const Introspectable*, int) { return NULL; } 
    static QVariant nullValue(const Introspectable*, int) { return QVariant(); }
};

class Introspectable {
public:
    uint32_t streamOffset;
#ifdef TREEINTROSPECTION
    Introspectable const * parent; // one more 'const' would be nice ...

    Introspectable(const Introspectable* p)
            :streamOffset(999999), parent(p) {}
#else
    Introspectable(const Introspectable* = 0)
            :streamOffset(999999) {
    }
#endif

    virtual ~Introspectable() {}
    virtual const Introspection* getIntrospection() const = 0;
};


#endif
