#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QMap>
#include <QSharedPointer>
#include "introspection.h"

class QXmlStreamReader;
class QXmlStreamWriter;
class LEInputStream;
class LEOutputStream;

// function declarations for accessing the generated parser classes
const Introspectable* parse(const QString& key, LEInputStream& in);
void serialize(const Introspectable* i, const QString& key, LEOutputStream& out);
const QMap<QString,QSharedPointer<const Introspectable> > parse(QXmlStreamReader& in);

// 
QByteArray escapeByteArray(const QByteArray& b);

QVector<quint16> toUInt16Vector(const QString& s);

QString toString(const QVector<quint16>& v);

void print(QXmlStreamWriter& out, const Introspectable* i);

QMap<QString, QByteArray> readStreams(const QString& file);

QMap<QString, QSharedPointer<const Introspectable> >
parseStreams(const QMap<QString, QByteArray>& streams);

QMap<QString, QByteArray> serialize(const QMap<QString, QSharedPointer<const Introspectable> >& m);

QByteArray streamsToXml(const QMap<QString, QSharedPointer<const Introspectable> >& streams);

QByteArray streamsToExtendedXml(const QMap<QString, QSharedPointer<const Introspectable> >& streams);

void write(const QString& name, const QByteArray& data);

void printWithExtendedParser(QXmlStreamWriter& out, const Introspectable* i);

#endif
