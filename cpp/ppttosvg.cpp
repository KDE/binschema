#include "utils.h"
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <libxml/parser.h>
#include <libxslt/xsltInternals.h>
#include <libxslt/transform.h>
#include <libxslt/xsltutils.h>

QByteArray loadFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    return file.readAll();
}

int
main(int argc, char** argv) {
    if (argc != 2) return 1;

    QString file = QString::fromLocal8Bit(argv[1]);
    const QMap<QString, QByteArray> streams = readStreams(file);
    const QMap<QString, QSharedPointer<const Introspectable> > introspectables
            = parseStreams(streams);
    const QByteArray xml = streamsToExtendedXml(introspectables);
    xmlDocPtr pptxmldoc = xmlParseMemory(xml, xml.size());

    QByteArray xslfiledata = loadFile(":/ppttosvg.xsl");
    xmlDocPtr xsldoc = xmlParseMemory(xslfiledata, xslfiledata.size());
    xsltStylesheetPtr xsl = xsltParseStylesheetDoc(xsldoc);
    qDebug() << xslfiledata.size();

    xmlDocPtr res = xsltApplyStylesheet(xsl, pptxmldoc, 0);

    xsltSaveResultToFile(stdout, res, xsl);

    xmlFreeDoc(pptxmldoc);
    xmlFreeDoc(res);
    xsltFreeStylesheet(xsl); // this frees xsldoc too

    xsltCleanupGlobals();
    xmlCleanupParser();

    return 0;
}
