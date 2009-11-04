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

void
xmltosvg(xsltStylesheetPtr xsl, const char* filepath, FILE* out) {
    QString file = QString::fromLocal8Bit(filepath);
    const QMap<QString, QByteArray> streams = readStreams(file);
    const QMap<QString, QSharedPointer<const Introspectable> > introspectables
            = parseStreams(streams);
    const QByteArray xml = streamsToExtendedXml(introspectables);
    xmlDocPtr pptxmldoc = xmlParseMemory(xml, xml.size());

    xmlDocPtr res = xsltApplyStylesheet(xsl, pptxmldoc, 0);

    xsltSaveResultToFile(out, res, xsl);

    xmlFreeDoc(pptxmldoc);
    xmlFreeDoc(res);
}

int
main(int argc, char** argv) {
    if (argc < 2) return 1;

    QByteArray xslfiledata = loadFile(":/ppttosvg.xsl");
    xmlDocPtr xsldoc = xmlParseMemory(xslfiledata, xslfiledata.size());
    xslfiledata.resize(0);
    xsltStylesheetPtr xsl = xsltParseStylesheetDoc(xsldoc);

    for (int i=1; i<argc; ++i) {
        xmltosvg(xsl, argv[i], stdout);
    }
    xsltFreeStylesheet(xsl); // this frees xsldoc too

    xsltCleanupGlobals();
    xmlCleanupParser();

    return 0;
}
