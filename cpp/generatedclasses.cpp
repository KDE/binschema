#include <QString>
#include <QByteArray>
#include <QVector>
#include "leinputstream.h"
namespace {
class RecordHeader;
class CurrentUserAtom;
class CurrentUserStream;
class OfficeArtBStoreDelay;
class OfficeArtRecordHeader;
class OfficeArtBlipJPEG;
class OfficeArtBlipPNG;
class OfficeArtBlipDIB;
class OfficeArtBlipTIFF;
class RECT;
class POINT;
class PowerPointStructs;
class EndDocumentAtom;
class DocInfoListContainer;
class DocInfoListSubContainerOrAtom;
class SlideViewInfoInstance;
class MasterListWithTextContainer;
class SlideListWithTextContainer;
class TextHeaderAtom;
class TextCharsAtom;
class TextBytesAtom;
class StyleTextPropAtom;
class SlideNumberMCAtom;
class DateTimeMCAtom;
class GenericDateMCAtom;
class HeaderMCAtom;
class FooterMCAtom;
class RTFDateTimeMCAtom;
class TextBookmarkAtom;
class TextSpecialInfoAtom;
class InteractiveInfoInstance;
class TextInteractiveInfoInstance;
class SlideId;
class TabStops;
class TabStop;
class BulletFlags;
class PFMasks;
class CFMasks;
class CFStyle;
class FontCollectionContainer;
class KinsokuAtom;
class TextSIExceptionAtom;
class ExOleEmbedAtom;
class PointStruct;
class RatioStruct;
class PersistDirectoryAtom;
class PersistDirectoryEntry;
class PersistOffsetEntry;
class PersistIdRef;
class MainMasterContainer;
class SlideProgTagscontainer;
class SlideAtom;
class SlideShowSlideInfoAtom;
class SlideSchemeColorSchemeAtom;
class RoundTripSlideRecord;
class ColorStruct;
class ExObjListAtom;
class ExOleLinkAtom;
class ExOleObjAtom;
class MenuNameAtom;
class ProgIDAtom;
class ClipboardNameAtom;
class MetafileBlob;
class OfficeArtFDGG;
class OfficeArtFDG;
class OfficeArtFRITContainer;
class OfficeArtFRIT;
class OfficeArtSpgrContainer;
class OfficeArtFSPGR;
class OfficeArtFSP;
class OfficeArtFPSPL;
class OfficeArtSolverContainer;
class OfficeArtSecondaryFOPT;
class OfficeArtTertiaryFOPT;
class OfficeArtChildAnchor;
class RectStruct;
class SmallRectStruct;
class OfficeArtClientData;
class OfficeArtClientTextBox;
class OfficeArtIDCL;
class OfficeArtBStoreContainer;
class OfficeArtFOPT;
class OfficeArtFOPTEOPID;
class OfficeArtColorMRUContainer;
class MSOCR;
class OfficeArtSplitMenuColorContainer;
class TODO;
class TODOS;
class FibBase;
class FibRgW97;
class FibRgLw97;
class PicturesStream;
class OfficeArtMetafileHeader;
class NormalViewSetInfoAtom;
class MasterPersistAtom;
class SlidePersistAtom;
class TextRuler;
class TextPFException;
class TextCFException;
class KinsokuContainer;
class TextMasterStyleLevel;
class DocumentAtom;
class ExObjListContainer;
class ExOleLinkContainer;
class ExOleEmbedContainer;
class OfficeArtFDGGBlock;
class OfficeArtClientAnchor;
class OfficeArtFOPTE;
class Fib;
class OfficeArtBlipEMF;
class OfficeArtBlipWMF;
class OfficeArtBlipPICT;
class OfficeArtBlip;
class NormalViewSetInfoContainer;
class SlideListWithTextSubContainerOrAtom;
class TextCFExceptionAtom;
class DefaultRulerAtom;
class TextPFExceptionAtom;
class TextMasterStyleAtom;
class ExObjListSubContainer;
class OfficeArtDggContainer;
class OfficeArtSpContainer;
class WordDocument;
class OfficeArtFBSE;
class OfficeArtBStoreContainerFileBlock;
class DocumentTextInfoContainer;
class DrawingGroupContainer;
class OfficeArtDgContainer;
class OfficeArtSpgrContainerFileBlock;
class DocumentContainer;
class DrawingContainer;
class SlideContainer;
class MasterOrSlideContainer;
class PowerPointStruct;
class RecordHeader {
public:
    quint8 recVer;
    quint16 recInstance;
    quint16 recType;
    quint32 recLen;
    QString toString() {
        QString _s = "RecordHeader:";
        _s = _s + "recVer: " + QString::number(recVer) + "(" + QString::number(recVer,16).toUpper() + ")" + ", ";
        _s = _s + "recInstance: " + QString::number(recInstance) + "(" + QString::number(recInstance,16).toUpper() + ")" + ", ";
        _s = _s + "recType: " + QString::number(recType) + "(" + QString::number(recType,16).toUpper() + ")" + ", ";
        _s = _s + "recLen: " + QString::number(recLen) + "(" + QString::number(recLen,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class CurrentUserAtom {
public:
    RecordHeader rh;
    quint32 size;
    quint32 headerToken;
    quint32 offsetToCurrentEdit;
    quint16 lenUserName;
    quint16 docFileVersion;
    quint8 majorVersion;
    quint8 minorVersion;
    quint16 unused;
    QByteArray ansiUserName;
    quint32 relVersion;
    QByteArray unicodeUserName;
    QString toString() {
        QString _s = "CurrentUserAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "size: " + QString::number(size) + "(" + QString::number(size,16).toUpper() + ")" + ", ";
        _s = _s + "headerToken: " + QString::number(headerToken) + "(" + QString::number(headerToken,16).toUpper() + ")" + ", ";
        _s = _s + "offsetToCurrentEdit: " + QString::number(offsetToCurrentEdit) + "(" + QString::number(offsetToCurrentEdit,16).toUpper() + ")" + ", ";
        _s = _s + "lenUserName: " + QString::number(lenUserName) + "(" + QString::number(lenUserName,16).toUpper() + ")" + ", ";
        _s = _s + "docFileVersion: " + QString::number(docFileVersion) + "(" + QString::number(docFileVersion,16).toUpper() + ")" + ", ";
        _s = _s + "majorVersion: " + QString::number(majorVersion) + "(" + QString::number(majorVersion,16).toUpper() + ")" + ", ";
        _s = _s + "minorVersion: " + QString::number(minorVersion) + "(" + QString::number(minorVersion,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        _s = _s + "ansiUserName: " + "[array of ansiUserName]" + ", ";
        _s = _s + "relVersion: " + QString::number(relVersion) + "(" + QString::number(relVersion,16).toUpper() + ")" + ", ";
        _s = _s + "unicodeUserName: " + "[array of unicodeUserName]" + ", ";
        return _s;
    }
};
class CurrentUserStream {
public:
    CurrentUserAtom anon1;
    QByteArray trailing;
    QString toString() {
        QString _s = "CurrentUserStream:";
        _s = _s + "anon1: " + anon1.toString() + ", ";
        _s = _s + "trailing: " + "[array of trailing]" + ", ";
        return _s;
    }
};
class OfficeArtBStoreDelay {
public:
    QList<OfficeArtBStoreContainerFileBlock> anon1;
    QString toString() {
        QString _s = "OfficeArtBStoreDelay:";
        _s = _s + "anon1: " + anon1.toString() + ", ";
        return _s;
    }
};
class OfficeArtRecordHeader {
public:
    quint8 recVer;
    quint16 recInstance;
    quint16 recType;
    quint32 recLen;
    QString toString() {
        QString _s = "OfficeArtRecordHeader:";
        _s = _s + "recVer: " + QString::number(recVer) + "(" + QString::number(recVer,16).toUpper() + ")" + ", ";
        _s = _s + "recInstance: " + QString::number(recInstance) + "(" + QString::number(recInstance,16).toUpper() + ")" + ", ";
        _s = _s + "recType: " + QString::number(recType) + "(" + QString::number(recType,16).toUpper() + ")" + ", ";
        _s = _s + "recLen: " + QString::number(recLen) + "(" + QString::number(recLen,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtBlipJPEG {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipJPEG:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class OfficeArtBlipPNG {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipPNG:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class OfficeArtBlipDIB {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipDIB:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class OfficeArtBlipTIFF {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipTIFF:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class RECT {
public:
    qint32 left;
    qint32 top;
    qint32 right;
    qint32 bottom;
    QString toString() {
        QString _s = "RECT:";
        _s = _s + "left: " + QString::number(left) + "(" + QString::number(left,16).toUpper() + ")" + ", ";
        _s = _s + "top: " + QString::number(top) + "(" + QString::number(top,16).toUpper() + ")" + ", ";
        _s = _s + "right: " + QString::number(right) + "(" + QString::number(right,16).toUpper() + ")" + ", ";
        _s = _s + "bottom: " + QString::number(bottom) + "(" + QString::number(bottom,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class POINT {
public:
    qint32 x;
    qint32 y;
    QString toString() {
        QString _s = "POINT:";
        _s = _s + "x: " + QString::number(x) + "(" + QString::number(x,16).toUpper() + ")" + ", ";
        _s = _s + "y: " + QString::number(y) + "(" + QString::number(y,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PowerPointStructs {
public:
    QList<PowerPointStruct> anon;
    QString toString() {
        QString _s = "PowerPointStructs:";
        _s = _s + "anon: " + QString::number(anon) + "(" + QString::number(anon,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class EndDocumentAtom {
public:
    RecordHeader rh;
    QString toString() {
        QString _s = "EndDocumentAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        return _s;
    }
};
class DocInfoListContainer {
public:
    RecordHeader rh;
    QList<DocInfoListSubContainerOrAtom> rgChildRec;
    QString toString() {
        QString _s = "DocInfoListContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgChildRec: " + rgChildRec.toString() + ", ";
        return _s;
    }
};
class DocInfoListSubContainerOrAtom {
public:
    RecordHeader rh;
    QByteArray wrong;
    QString toString() {
        QString _s = "DocInfoListSubContainerOrAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "wrong: " + "[array of wrong]" + ", ";
        return _s;
    }
};
class SlideViewInfoInstance {
public:
    RecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "SlideViewInfoInstance:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class MasterListWithTextContainer {
public:
    RecordHeader rh;
    QVector<MasterPersistAtom> rgMasterPersistAtom;
    QString toString() {
        QString _s = "MasterListWithTextContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgMasterPersistAtom: " + "[array of rgMasterPersistAtom]" + ", ";
        return _s;
    }
};
class SlideListWithTextContainer {
public:
    RecordHeader rh;
    QList<SlideListWithTextSubContainerOrAtom> rgChildRec;
    QString toString() {
        QString _s = "SlideListWithTextContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgChildRec: " + rgChildRec.toString() + ", ";
        return _s;
    }
};
class TextHeaderAtom {
public:
    RecordHeader rh;
    quint32 textType;
    QString toString() {
        QString _s = "TextHeaderAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textType: " + QString::number(textType) + "(" + QString::number(textType,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TextCharsAtom {
public:
    RecordHeader rh;
    QVector<quint16> textChars;
    QString toString() {
        QString _s = "TextCharsAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textChars: " + "[array of textChars]" + ", ";
        return _s;
    }
};
class TextBytesAtom {
public:
    RecordHeader rh;
    QByteArray textChars;
    QString toString() {
        QString _s = "TextBytesAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textChars: " + "[array of textChars]" + ", ";
        return _s;
    }
};
class StyleTextPropAtom {
public:
    RecordHeader rh;
    QByteArray wrong;
    QString toString() {
        QString _s = "StyleTextPropAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "wrong: " + "[array of wrong]" + ", ";
        return _s;
    }
};
class SlideNumberMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    QString toString() {
        QString _s = "SlideNumberMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class DateTimeMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    quint8 index;
    QByteArray unused;
    QString toString() {
        QString _s = "DateTimeMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "index: " + QString::number(index) + "(" + QString::number(index,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + "[array of unused]" + ", ";
        return _s;
    }
};
class GenericDateMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    QString toString() {
        QString _s = "GenericDateMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class HeaderMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    QString toString() {
        QString _s = "HeaderMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class FooterMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    QString toString() {
        QString _s = "FooterMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class RTFDateTimeMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    QByteArray format;
    QString toString() {
        QString _s = "RTFDateTimeMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "format: " + "[array of format]" + ", ";
        return _s;
    }
};
class TextBookmarkAtom {
public:
    RecordHeader rh;
    qint32 begin;
    qint32 end;
    qint32 bookmarkID;
    QString toString() {
        QString _s = "TextBookmarkAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "begin: " + QString::number(begin) + "(" + QString::number(begin,16).toUpper() + ")" + ", ";
        _s = _s + "end: " + QString::number(end) + "(" + QString::number(end,16).toUpper() + ")" + ", ";
        _s = _s + "bookmarkID: " + QString::number(bookmarkID) + "(" + QString::number(bookmarkID,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TextSpecialInfoAtom {
public:
    RecordHeader rh;
    QByteArray wrong;
    QString toString() {
        QString _s = "TextSpecialInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "wrong: " + "[array of wrong]" + ", ";
        return _s;
    }
};
class InteractiveInfoInstance {
public:
    RecordHeader rh;
    QByteArray range;
    QString toString() {
        QString _s = "InteractiveInfoInstance:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "range: " + "[array of range]" + ", ";
        return _s;
    }
};
class TextInteractiveInfoInstance {
public:
    RecordHeader rh;
    QByteArray range;
    QString toString() {
        QString _s = "TextInteractiveInfoInstance:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "range: " + "[array of range]" + ", ";
        return _s;
    }
};
class SlideId {
public:
    quint32 slideId;
    QString toString() {
        QString _s = "SlideId:";
        _s = _s + "slideId: " + QString::number(slideId) + "(" + QString::number(slideId,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TabStops {
public:
    quint16 count;
    QVector<TabStop> rgTabStop;
    QString toString() {
        QString _s = "TabStops:";
        _s = _s + "count: " + QString::number(count) + "(" + QString::number(count,16).toUpper() + ")" + ", ";
        _s = _s + "rgTabStop: " + "[array of rgTabStop]" + ", ";
        return _s;
    }
};
class TabStop {
public:
    qint16 position;
    quint16 type;
    QString toString() {
        QString _s = "TabStop:";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "type: " + QString::number(type) + "(" + QString::number(type,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class BulletFlags {
public:
    bool fHasBullet;
    bool fBulletHasFont;
    bool fBulletHasColor;
    bool fBulletHasSize;
    quint16 reserved;
    QString toString() {
        QString _s = "BulletFlags:";
        _s = _s + "fHasBullet: " + QString::number(fHasBullet) + "(" + QString::number(fHasBullet,16).toUpper() + ")" + ", ";
        _s = _s + "fBulletHasFont: " + QString::number(fBulletHasFont) + "(" + QString::number(fBulletHasFont,16).toUpper() + ")" + ", ";
        _s = _s + "fBulletHasColor: " + QString::number(fBulletHasColor) + "(" + QString::number(fBulletHasColor,16).toUpper() + ")" + ", ";
        _s = _s + "fBulletHasSize: " + QString::number(fBulletHasSize) + "(" + QString::number(fBulletHasSize,16).toUpper() + ")" + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PFMasks {
public:
    bool hasBullet;
    bool bulletHasFont;
    bool bulletHasColor;
    bool bulletHasSize;
    bool bulletFont;
    bool bulletColor;
    bool bulletSize;
    bool bulletChar;
    bool leftMargin;
    bool unused;
    bool indent;
    bool align;
    bool lineSpacing;
    bool spaceBefore;
    bool spaceAfter;
    bool defaultTabSize;
    bool fontAlign;
    bool charWrap;
    bool wordWrap;
    bool overflow;
    bool tabStops;
    bool textDirection;
    bool reserved;
    bool bulletBlip;
    bool bulletScheme;
    bool bulletHasScheme;
    quint8 reserved2;
    QString toString() {
        QString _s = "PFMasks:";
        _s = _s + "hasBullet: " + QString::number(hasBullet) + "(" + QString::number(hasBullet,16).toUpper() + ")" + ", ";
        _s = _s + "bulletHasFont: " + QString::number(bulletHasFont) + "(" + QString::number(bulletHasFont,16).toUpper() + ")" + ", ";
        _s = _s + "bulletHasColor: " + QString::number(bulletHasColor) + "(" + QString::number(bulletHasColor,16).toUpper() + ")" + ", ";
        _s = _s + "bulletHasSize: " + QString::number(bulletHasSize) + "(" + QString::number(bulletHasSize,16).toUpper() + ")" + ", ";
        _s = _s + "bulletFont: " + QString::number(bulletFont) + "(" + QString::number(bulletFont,16).toUpper() + ")" + ", ";
        _s = _s + "bulletColor: " + QString::number(bulletColor) + "(" + QString::number(bulletColor,16).toUpper() + ")" + ", ";
        _s = _s + "bulletSize: " + QString::number(bulletSize) + "(" + QString::number(bulletSize,16).toUpper() + ")" + ", ";
        _s = _s + "bulletChar: " + QString::number(bulletChar) + "(" + QString::number(bulletChar,16).toUpper() + ")" + ", ";
        _s = _s + "leftMargin: " + QString::number(leftMargin) + "(" + QString::number(leftMargin,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        _s = _s + "indent: " + QString::number(indent) + "(" + QString::number(indent,16).toUpper() + ")" + ", ";
        _s = _s + "align: " + QString::number(align) + "(" + QString::number(align,16).toUpper() + ")" + ", ";
        _s = _s + "lineSpacing: " + QString::number(lineSpacing) + "(" + QString::number(lineSpacing,16).toUpper() + ")" + ", ";
        _s = _s + "spaceBefore: " + QString::number(spaceBefore) + "(" + QString::number(spaceBefore,16).toUpper() + ")" + ", ";
        _s = _s + "spaceAfter: " + QString::number(spaceAfter) + "(" + QString::number(spaceAfter,16).toUpper() + ")" + ", ";
        _s = _s + "defaultTabSize: " + QString::number(defaultTabSize) + "(" + QString::number(defaultTabSize,16).toUpper() + ")" + ", ";
        _s = _s + "fontAlign: " + QString::number(fontAlign) + "(" + QString::number(fontAlign,16).toUpper() + ")" + ", ";
        _s = _s + "charWrap: " + QString::number(charWrap) + "(" + QString::number(charWrap,16).toUpper() + ")" + ", ";
        _s = _s + "wordWrap: " + QString::number(wordWrap) + "(" + QString::number(wordWrap,16).toUpper() + ")" + ", ";
        _s = _s + "overflow: " + QString::number(overflow) + "(" + QString::number(overflow,16).toUpper() + ")" + ", ";
        _s = _s + "tabStops: " + QString::number(tabStops) + "(" + QString::number(tabStops,16).toUpper() + ")" + ", ";
        _s = _s + "textDirection: " + QString::number(textDirection) + "(" + QString::number(textDirection,16).toUpper() + ")" + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        _s = _s + "bulletBlip: " + QString::number(bulletBlip) + "(" + QString::number(bulletBlip,16).toUpper() + ")" + ", ";
        _s = _s + "bulletScheme: " + QString::number(bulletScheme) + "(" + QString::number(bulletScheme,16).toUpper() + ")" + ", ";
        _s = _s + "bulletHasScheme: " + QString::number(bulletHasScheme) + "(" + QString::number(bulletHasScheme,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class CFMasks {
public:
    bool bold;
    bool italic;
    bool underline;
    bool unused1;
    bool shadow;
    bool fehint;
    bool unused2;
    bool kumi;
    bool unused3;
    bool emboss;
    quint8 fHasStyle;
    quint8 unused4;
    bool typeface;
    bool size;
    bool color;
    bool position;
    bool pp10ext;
    bool oldEATypeface;
    bool ansiTypeface;
    bool symbolTypeface;
    bool newEATypeface;
    bool csTypeface;
    bool pp11ext;
    quint8 reserved;
    QString toString() {
        QString _s = "CFMasks:";
        _s = _s + "bold: " + QString::number(bold) + "(" + QString::number(bold,16).toUpper() + ")" + ", ";
        _s = _s + "italic: " + QString::number(italic) + "(" + QString::number(italic,16).toUpper() + ")" + ", ";
        _s = _s + "underline: " + QString::number(underline) + "(" + QString::number(underline,16).toUpper() + ")" + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + "(" + QString::number(unused1,16).toUpper() + ")" + ", ";
        _s = _s + "shadow: " + QString::number(shadow) + "(" + QString::number(shadow,16).toUpper() + ")" + ", ";
        _s = _s + "fehint: " + QString::number(fehint) + "(" + QString::number(fehint,16).toUpper() + ")" + ", ";
        _s = _s + "unused2: " + QString::number(unused2) + "(" + QString::number(unused2,16).toUpper() + ")" + ", ";
        _s = _s + "kumi: " + QString::number(kumi) + "(" + QString::number(kumi,16).toUpper() + ")" + ", ";
        _s = _s + "unused3: " + QString::number(unused3) + "(" + QString::number(unused3,16).toUpper() + ")" + ", ";
        _s = _s + "emboss: " + QString::number(emboss) + "(" + QString::number(emboss,16).toUpper() + ")" + ", ";
        _s = _s + "fHasStyle: " + QString::number(fHasStyle) + "(" + QString::number(fHasStyle,16).toUpper() + ")" + ", ";
        _s = _s + "unused4: " + QString::number(unused4) + "(" + QString::number(unused4,16).toUpper() + ")" + ", ";
        _s = _s + "typeface: " + QString::number(typeface) + "(" + QString::number(typeface,16).toUpper() + ")" + ", ";
        _s = _s + "size: " + QString::number(size) + "(" + QString::number(size,16).toUpper() + ")" + ", ";
        _s = _s + "color: " + QString::number(color) + "(" + QString::number(color,16).toUpper() + ")" + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "pp10ext: " + QString::number(pp10ext) + "(" + QString::number(pp10ext,16).toUpper() + ")" + ", ";
        _s = _s + "oldEATypeface: " + QString::number(oldEATypeface) + "(" + QString::number(oldEATypeface,16).toUpper() + ")" + ", ";
        _s = _s + "ansiTypeface: " + QString::number(ansiTypeface) + "(" + QString::number(ansiTypeface,16).toUpper() + ")" + ", ";
        _s = _s + "symbolTypeface: " + QString::number(symbolTypeface) + "(" + QString::number(symbolTypeface,16).toUpper() + ")" + ", ";
        _s = _s + "newEATypeface: " + QString::number(newEATypeface) + "(" + QString::number(newEATypeface,16).toUpper() + ")" + ", ";
        _s = _s + "csTypeface: " + QString::number(csTypeface) + "(" + QString::number(csTypeface,16).toUpper() + ")" + ", ";
        _s = _s + "pp11ext: " + QString::number(pp11ext) + "(" + QString::number(pp11ext,16).toUpper() + ")" + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class CFStyle {
public:
    bool bold;
    bool italic;
    bool underline;
    bool unused1;
    bool shadow;
    bool fehint;
    bool unused2;
    bool kumi;
    bool unused3;
    bool emboss;
    quint8 pp9rt;
    quint8 unused4;
    QString toString() {
        QString _s = "CFStyle:";
        _s = _s + "bold: " + QString::number(bold) + "(" + QString::number(bold,16).toUpper() + ")" + ", ";
        _s = _s + "italic: " + QString::number(italic) + "(" + QString::number(italic,16).toUpper() + ")" + ", ";
        _s = _s + "underline: " + QString::number(underline) + "(" + QString::number(underline,16).toUpper() + ")" + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + "(" + QString::number(unused1,16).toUpper() + ")" + ", ";
        _s = _s + "shadow: " + QString::number(shadow) + "(" + QString::number(shadow,16).toUpper() + ")" + ", ";
        _s = _s + "fehint: " + QString::number(fehint) + "(" + QString::number(fehint,16).toUpper() + ")" + ", ";
        _s = _s + "unused2: " + QString::number(unused2) + "(" + QString::number(unused2,16).toUpper() + ")" + ", ";
        _s = _s + "kumi: " + QString::number(kumi) + "(" + QString::number(kumi,16).toUpper() + ")" + ", ";
        _s = _s + "unused3: " + QString::number(unused3) + "(" + QString::number(unused3,16).toUpper() + ")" + ", ";
        _s = _s + "emboss: " + QString::number(emboss) + "(" + QString::number(emboss,16).toUpper() + ")" + ", ";
        _s = _s + "pp9rt: " + QString::number(pp9rt) + "(" + QString::number(pp9rt,16).toUpper() + ")" + ", ";
        _s = _s + "unused4: " + QString::number(unused4) + "(" + QString::number(unused4,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class FontCollectionContainer {
public:
    RecordHeader rh;
    QByteArray rgFontCollectionEntry;
    QString toString() {
        QString _s = "FontCollectionContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgFontCollectionEntry: " + "[array of rgFontCollectionEntry]" + ", ";
        return _s;
    }
};
class KinsokuAtom {
public:
    RecordHeader rh;
    quint32 level;
    QString toString() {
        QString _s = "KinsokuAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "level: " + QString::number(level) + "(" + QString::number(level,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TextSIExceptionAtom {
public:
    RecordHeader rh;
    QByteArray textSIException;
    QString toString() {
        QString _s = "TextSIExceptionAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textSIException: " + "[array of textSIException]" + ", ";
        return _s;
    }
};
class ExOleEmbedAtom {
public:
    RecordHeader rh;
    quint32 exColorFollow;
    quint8 fCantLockServer;
    quint8 fNoSizeToServer;
    quint8 fIsTable;
    quint8 unused;
    QString toString() {
        QString _s = "ExOleEmbedAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exColorFollow: " + QString::number(exColorFollow) + "(" + QString::number(exColorFollow,16).toUpper() + ")" + ", ";
        _s = _s + "fCantLockServer: " + QString::number(fCantLockServer) + "(" + QString::number(fCantLockServer,16).toUpper() + ")" + ", ";
        _s = _s + "fNoSizeToServer: " + QString::number(fNoSizeToServer) + "(" + QString::number(fNoSizeToServer,16).toUpper() + ")" + ", ";
        _s = _s + "fIsTable: " + QString::number(fIsTable) + "(" + QString::number(fIsTable,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PointStruct {
public:
    qint32 x;
    qint32 y;
    QString toString() {
        QString _s = "PointStruct:";
        _s = _s + "x: " + QString::number(x) + "(" + QString::number(x,16).toUpper() + ")" + ", ";
        _s = _s + "y: " + QString::number(y) + "(" + QString::number(y,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class RatioStruct {
public:
    qint32 numer;
    qint32 denom;
    QString toString() {
        QString _s = "RatioStruct:";
        _s = _s + "numer: " + QString::number(numer) + "(" + QString::number(numer,16).toUpper() + ")" + ", ";
        _s = _s + "denom: " + QString::number(denom) + "(" + QString::number(denom,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PersistDirectoryAtom {
public:
    RecordHeader rh;
    QList<PersistDirectoryEntry> rgPersistDirEntry;
    QString toString() {
        QString _s = "PersistDirectoryAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgPersistDirEntry: " + rgPersistDirEntry.toString() + ", ";
        return _s;
    }
};
class PersistDirectoryEntry {
public:
    quint32 persistId;
    quint16 cPersist;
    QVector<PersistOffsetEntry> rgPersistOffset;
    QString toString() {
        QString _s = "PersistDirectoryEntry:";
        _s = _s + "persistId: " + QString::number(persistId) + "(" + QString::number(persistId,16).toUpper() + ")" + ", ";
        _s = _s + "cPersist: " + QString::number(cPersist) + "(" + QString::number(cPersist,16).toUpper() + ")" + ", ";
        _s = _s + "rgPersistOffset: " + "[array of rgPersistOffset]" + ", ";
        return _s;
    }
};
class PersistOffsetEntry {
public:
    quint32 anon;
    QString toString() {
        QString _s = "PersistOffsetEntry:";
        _s = _s + "anon: " + QString::number(anon) + "(" + QString::number(anon,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PersistIdRef {
public:
    quint32 anon;
    QString toString() {
        QString _s = "PersistIdRef:";
        _s = _s + "anon: " + QString::number(anon) + "(" + QString::number(anon,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class MainMasterContainer {
public:
    RecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "MainMasterContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class SlideProgTagscontainer {
public:
    RecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "SlideProgTagscontainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class SlideAtom {
public:
    RecordHeader rh;
    quint32 geom;
    QByteArray rgPlaceholderTypes;
    quint32 masterIdRef;
    quint32 notesIdRef;
    quint16 slideFlags;
    quint16 unused;
    QString toString() {
        QString _s = "SlideAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "geom: " + QString::number(geom) + "(" + QString::number(geom,16).toUpper() + ")" + ", ";
        _s = _s + "rgPlaceholderTypes: " + "[array of rgPlaceholderTypes]" + ", ";
        _s = _s + "masterIdRef: " + QString::number(masterIdRef) + "(" + QString::number(masterIdRef,16).toUpper() + ")" + ", ";
        _s = _s + "notesIdRef: " + QString::number(notesIdRef) + "(" + QString::number(notesIdRef,16).toUpper() + ")" + ", ";
        _s = _s + "slideFlags: " + QString::number(slideFlags) + "(" + QString::number(slideFlags,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class SlideShowSlideInfoAtom {
public:
    RecordHeader rh;
    quint32 slidetime;
    quint32 slideIdRef;
    quint8 effectDirection;
    quint8 effectType;
    bool fManualAdvance;
    bool reserved;
    bool fHidden;
    bool reserved2;
    bool fSound;
    bool reserved3;
    bool fLoopSound;
    bool reserved4;
    bool fStopSound;
    bool freserved5;
    bool fAutoAdvance;
    bool reserved6;
    bool fCursorVisible;
    quint8 reserved7;
    quint8 speed;
    QByteArray unused;
    QString toString() {
        QString _s = "SlideShowSlideInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "slidetime: " + QString::number(slidetime) + "(" + QString::number(slidetime,16).toUpper() + ")" + ", ";
        _s = _s + "slideIdRef: " + QString::number(slideIdRef) + "(" + QString::number(slideIdRef,16).toUpper() + ")" + ", ";
        _s = _s + "effectDirection: " + QString::number(effectDirection) + "(" + QString::number(effectDirection,16).toUpper() + ")" + ", ";
        _s = _s + "effectType: " + QString::number(effectType) + "(" + QString::number(effectType,16).toUpper() + ")" + ", ";
        _s = _s + "fManualAdvance: " + QString::number(fManualAdvance) + "(" + QString::number(fManualAdvance,16).toUpper() + ")" + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        _s = _s + "fHidden: " + QString::number(fHidden) + "(" + QString::number(fHidden,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "fSound: " + QString::number(fSound) + "(" + QString::number(fSound,16).toUpper() + ")" + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + "(" + QString::number(reserved3,16).toUpper() + ")" + ", ";
        _s = _s + "fLoopSound: " + QString::number(fLoopSound) + "(" + QString::number(fLoopSound,16).toUpper() + ")" + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + "(" + QString::number(reserved4,16).toUpper() + ")" + ", ";
        _s = _s + "fStopSound: " + QString::number(fStopSound) + "(" + QString::number(fStopSound,16).toUpper() + ")" + ", ";
        _s = _s + "freserved5: " + QString::number(freserved5) + "(" + QString::number(freserved5,16).toUpper() + ")" + ", ";
        _s = _s + "fAutoAdvance: " + QString::number(fAutoAdvance) + "(" + QString::number(fAutoAdvance,16).toUpper() + ")" + ", ";
        _s = _s + "reserved6: " + QString::number(reserved6) + "(" + QString::number(reserved6,16).toUpper() + ")" + ", ";
        _s = _s + "fCursorVisible: " + QString::number(fCursorVisible) + "(" + QString::number(fCursorVisible,16).toUpper() + ")" + ", ";
        _s = _s + "reserved7: " + QString::number(reserved7) + "(" + QString::number(reserved7,16).toUpper() + ")" + ", ";
        _s = _s + "speed: " + QString::number(speed) + "(" + QString::number(speed,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + "[array of unused]" + ", ";
        return _s;
    }
};
class SlideSchemeColorSchemeAtom {
public:
    RecordHeader rh;
    QVector<ColorStruct> rgSchemeColor;
    QString toString() {
        QString _s = "SlideSchemeColorSchemeAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgSchemeColor: " + "[array of rgSchemeColor]" + ", ";
        return _s;
    }
};
class RoundTripSlideRecord {
public:
    RecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "RoundTripSlideRecord:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class ColorStruct {
public:
    quint8 red;
    quint8 green;
    quint8 blue;
    quint8 unused;
    QString toString() {
        QString _s = "ColorStruct:";
        _s = _s + "red: " + QString::number(red) + "(" + QString::number(red,16).toUpper() + ")" + ", ";
        _s = _s + "green: " + QString::number(green) + "(" + QString::number(green,16).toUpper() + ")" + ", ";
        _s = _s + "blue: " + QString::number(blue) + "(" + QString::number(blue,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class ExObjListAtom {
public:
    RecordHeader rh;
    qint32 exObjIdSeed;
    QString toString() {
        QString _s = "ExObjListAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exObjIdSeed: " + QString::number(exObjIdSeed) + "(" + QString::number(exObjIdSeed,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class ExOleLinkAtom {
public:
    RecordHeader rh;
    quint32 slideIdRef;
    quint32 oleUpdateMode;
    quint32 unused;
    QString toString() {
        QString _s = "ExOleLinkAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "slideIdRef: " + QString::number(slideIdRef) + "(" + QString::number(slideIdRef,16).toUpper() + ")" + ", ";
        _s = _s + "oleUpdateMode: " + QString::number(oleUpdateMode) + "(" + QString::number(oleUpdateMode,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class ExOleObjAtom {
public:
    RecordHeader rh;
    quint32 drawAspect;
    quint32 type;
    quint32 exObjId;
    quint32 subType;
    quint32 persistIdRef;
    quint32 unused;
    QString toString() {
        QString _s = "ExOleObjAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "drawAspect: " + QString::number(drawAspect) + "(" + QString::number(drawAspect,16).toUpper() + ")" + ", ";
        _s = _s + "type: " + QString::number(type) + "(" + QString::number(type,16).toUpper() + ")" + ", ";
        _s = _s + "exObjId: " + QString::number(exObjId) + "(" + QString::number(exObjId,16).toUpper() + ")" + ", ";
        _s = _s + "subType: " + QString::number(subType) + "(" + QString::number(subType,16).toUpper() + ")" + ", ";
        _s = _s + "persistIdRef: " + QString::number(persistIdRef) + "(" + QString::number(persistIdRef,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class MenuNameAtom {
public:
    RecordHeader rh;
    QByteArray menuName;
    QString toString() {
        QString _s = "MenuNameAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "menuName: " + "[array of menuName]" + ", ";
        return _s;
    }
};
class ProgIDAtom {
public:
    RecordHeader rh;
    QByteArray progId;
    QString toString() {
        QString _s = "ProgIDAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "progId: " + "[array of progId]" + ", ";
        return _s;
    }
};
class ClipboardNameAtom {
public:
    RecordHeader rh;
    QByteArray clipboardName;
    QString toString() {
        QString _s = "ClipboardNameAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "clipboardName: " + "[array of clipboardName]" + ", ";
        return _s;
    }
};
class MetafileBlob {
public:
    RecordHeader rh;
    qint16 mm;
    qint16 xExt;
    qint16 yExt;
    QByteArray data;
    QString toString() {
        QString _s = "MetafileBlob:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "mm: " + QString::number(mm) + "(" + QString::number(mm,16).toUpper() + ")" + ", ";
        _s = _s + "xExt: " + QString::number(xExt) + "(" + QString::number(xExt,16).toUpper() + ")" + ", ";
        _s = _s + "yExt: " + QString::number(yExt) + "(" + QString::number(yExt,16).toUpper() + ")" + ", ";
        _s = _s + "data: " + "[array of data]" + ", ";
        return _s;
    }
};
class OfficeArtFDGG {
public:
    quint32 spidMax;
    quint32 cidcl;
    quint32 cspSaved;
    quint32 cdgSaved;
    QString toString() {
        QString _s = "OfficeArtFDGG:";
        _s = _s + "spidMax: " + QString::number(spidMax) + "(" + QString::number(spidMax,16).toUpper() + ")" + ", ";
        _s = _s + "cidcl: " + QString::number(cidcl) + "(" + QString::number(cidcl,16).toUpper() + ")" + ", ";
        _s = _s + "cspSaved: " + QString::number(cspSaved) + "(" + QString::number(cspSaved,16).toUpper() + ")" + ", ";
        _s = _s + "cdgSaved: " + QString::number(cdgSaved) + "(" + QString::number(cdgSaved,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtFDG {
public:
    OfficeArtRecordHeader rh;
    quint32 csp;
    quint32 spidCur;
    QString toString() {
        QString _s = "OfficeArtFDG:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "csp: " + QString::number(csp) + "(" + QString::number(csp,16).toUpper() + ")" + ", ";
        _s = _s + "spidCur: " + QString::number(spidCur) + "(" + QString::number(spidCur,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtFRITContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFRIT> rgfrit;
    QString toString() {
        QString _s = "OfficeArtFRITContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfrit: " + "[array of rgfrit]" + ", ";
        return _s;
    }
};
class OfficeArtFRIT {
public:
    quint16 fridNew;
    quint16 fridOld;
    QString toString() {
        QString _s = "OfficeArtFRIT:";
        _s = _s + "fridNew: " + QString::number(fridNew) + "(" + QString::number(fridNew,16).toUpper() + ")" + ", ";
        _s = _s + "fridOld: " + QString::number(fridOld) + "(" + QString::number(fridOld,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtSpgrContainer {
public:
    OfficeArtRecordHeader rh;
    QList<OfficeArtSpgrContainerFileBlock> rgfb;
    QString toString() {
        QString _s = "OfficeArtSpgrContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfb: " + rgfb.toString() + ", ";
        return _s;
    }
};
class OfficeArtFSPGR {
public:
    OfficeArtRecordHeader rh;
    qint32 xLeft;
    qint32 yTop;
    qint32 xRight;
    qint32 yBottom;
    QString toString() {
        QString _s = "OfficeArtFSPGR:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "xLeft: " + QString::number(xLeft) + "(" + QString::number(xLeft,16).toUpper() + ")" + ", ";
        _s = _s + "yTop: " + QString::number(yTop) + "(" + QString::number(yTop,16).toUpper() + ")" + ", ";
        _s = _s + "xRight: " + QString::number(xRight) + "(" + QString::number(xRight,16).toUpper() + ")" + ", ";
        _s = _s + "yBottom: " + QString::number(yBottom) + "(" + QString::number(yBottom,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtFSP {
public:
    OfficeArtRecordHeader rh;
    quint32 spid;
    bool fGroup;
    bool fChild;
    bool fPatriarch;
    bool fDeleted;
    bool fOleShape;
    bool fHaveMaster;
    bool fFlipH;
    bool fFlipV;
    bool fConnector;
    bool fHaveAnchor;
    bool fBackground;
    bool fHaveSpt;
    quint32 unused1;
    QString toString() {
        QString _s = "OfficeArtFSP:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "spid: " + QString::number(spid) + "(" + QString::number(spid,16).toUpper() + ")" + ", ";
        _s = _s + "fGroup: " + QString::number(fGroup) + "(" + QString::number(fGroup,16).toUpper() + ")" + ", ";
        _s = _s + "fChild: " + QString::number(fChild) + "(" + QString::number(fChild,16).toUpper() + ")" + ", ";
        _s = _s + "fPatriarch: " + QString::number(fPatriarch) + "(" + QString::number(fPatriarch,16).toUpper() + ")" + ", ";
        _s = _s + "fDeleted: " + QString::number(fDeleted) + "(" + QString::number(fDeleted,16).toUpper() + ")" + ", ";
        _s = _s + "fOleShape: " + QString::number(fOleShape) + "(" + QString::number(fOleShape,16).toUpper() + ")" + ", ";
        _s = _s + "fHaveMaster: " + QString::number(fHaveMaster) + "(" + QString::number(fHaveMaster,16).toUpper() + ")" + ", ";
        _s = _s + "fFlipH: " + QString::number(fFlipH) + "(" + QString::number(fFlipH,16).toUpper() + ")" + ", ";
        _s = _s + "fFlipV: " + QString::number(fFlipV) + "(" + QString::number(fFlipV,16).toUpper() + ")" + ", ";
        _s = _s + "fConnector: " + QString::number(fConnector) + "(" + QString::number(fConnector,16).toUpper() + ")" + ", ";
        _s = _s + "fHaveAnchor: " + QString::number(fHaveAnchor) + "(" + QString::number(fHaveAnchor,16).toUpper() + ")" + ", ";
        _s = _s + "fBackground: " + QString::number(fBackground) + "(" + QString::number(fBackground,16).toUpper() + ")" + ", ";
        _s = _s + "fHaveSpt: " + QString::number(fHaveSpt) + "(" + QString::number(fHaveSpt,16).toUpper() + ")" + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + "(" + QString::number(unused1,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtFPSPL {
public:
    OfficeArtRecordHeader rh;
    quint32 spid;
    bool reserved1;
    bool fLast;
    QString toString() {
        QString _s = "OfficeArtFPSPL:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "spid: " + QString::number(spid) + "(" + QString::number(spid,16).toUpper() + ")" + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "fLast: " + QString::number(fLast) + "(" + QString::number(fLast,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtSolverContainer {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "OfficeArtSolverContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class OfficeArtSecondaryFOPT {
public:
    OfficeArtRecordHeader rh;
    QByteArray fopt;
    QString toString() {
        QString _s = "OfficeArtSecondaryFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
        return _s;
    }
};
class OfficeArtTertiaryFOPT {
public:
    OfficeArtRecordHeader rh;
    QByteArray fopt;
    QString toString() {
        QString _s = "OfficeArtTertiaryFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
        return _s;
    }
};
class OfficeArtChildAnchor {
public:
    OfficeArtRecordHeader rh;
    qint32 xLeft;
    qint32 yTop;
    qint32 xRight;
    qint32 yBottom;
    QString toString() {
        QString _s = "OfficeArtChildAnchor:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "xLeft: " + QString::number(xLeft) + "(" + QString::number(xLeft,16).toUpper() + ")" + ", ";
        _s = _s + "yTop: " + QString::number(yTop) + "(" + QString::number(yTop,16).toUpper() + ")" + ", ";
        _s = _s + "xRight: " + QString::number(xRight) + "(" + QString::number(xRight,16).toUpper() + ")" + ", ";
        _s = _s + "yBottom: " + QString::number(yBottom) + "(" + QString::number(yBottom,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class RectStruct {
public:
    qint32 top;
    qint32 left;
    qint32 right;
    qint32 bottom;
    QString toString() {
        QString _s = "RectStruct:";
        _s = _s + "top: " + QString::number(top) + "(" + QString::number(top,16).toUpper() + ")" + ", ";
        _s = _s + "left: " + QString::number(left) + "(" + QString::number(left,16).toUpper() + ")" + ", ";
        _s = _s + "right: " + QString::number(right) + "(" + QString::number(right,16).toUpper() + ")" + ", ";
        _s = _s + "bottom: " + QString::number(bottom) + "(" + QString::number(bottom,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class SmallRectStruct {
public:
    qint16 top;
    qint16 left;
    qint16 right;
    qint16 bottom;
    QString toString() {
        QString _s = "SmallRectStruct:";
        _s = _s + "top: " + QString::number(top) + "(" + QString::number(top,16).toUpper() + ")" + ", ";
        _s = _s + "left: " + QString::number(left) + "(" + QString::number(left,16).toUpper() + ")" + ", ";
        _s = _s + "right: " + QString::number(right) + "(" + QString::number(right,16).toUpper() + ")" + ", ";
        _s = _s + "bottom: " + QString::number(bottom) + "(" + QString::number(bottom,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtClientData {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "OfficeArtClientData:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class OfficeArtClientTextBox {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "OfficeArtClientTextBox:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class OfficeArtIDCL {
public:
    quint32 dgid;
    quint32 cspidCur;
    QString toString() {
        QString _s = "OfficeArtIDCL:";
        _s = _s + "dgid: " + QString::number(dgid) + "(" + QString::number(dgid,16).toUpper() + ")" + ", ";
        _s = _s + "cspidCur: " + QString::number(cspidCur) + "(" + QString::number(cspidCur,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtBStoreContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<OfficeArtBStoreContainerFileBlock> rgfb;
    QString toString() {
        QString _s = "OfficeArtBStoreContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfb: " + "[array of rgfb]" + ", ";
        return _s;
    }
};
class OfficeArtFOPT {
public:
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFOPTE> fopt;
    QString toString() {
        QString _s = "OfficeArtFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
        return _s;
    }
};
class OfficeArtFOPTEOPID {
public:
    quint16 opid;
    bool fBid;
    bool fComplex;
    QString toString() {
        QString _s = "OfficeArtFOPTEOPID:";
        _s = _s + "opid: " + QString::number(opid) + "(" + QString::number(opid,16).toUpper() + ")" + ", ";
        _s = _s + "fBid: " + QString::number(fBid) + "(" + QString::number(fBid,16).toUpper() + ")" + ", ";
        _s = _s + "fComplex: " + QString::number(fComplex) + "(" + QString::number(fComplex,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtColorMRUContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<MSOCR> rgmsocr;
    QString toString() {
        QString _s = "OfficeArtColorMRUContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgmsocr: " + "[array of rgmsocr]" + ", ";
        return _s;
    }
};
class MSOCR {
public:
    quint8 red;
    quint8 green;
    quint8 blue;
    quint8 unused1;
    bool fSchemeIndex;
    quint8 unused2;
    QString toString() {
        QString _s = "MSOCR:";
        _s = _s + "red: " + QString::number(red) + "(" + QString::number(red,16).toUpper() + ")" + ", ";
        _s = _s + "green: " + QString::number(green) + "(" + QString::number(green,16).toUpper() + ")" + ", ";
        _s = _s + "blue: " + QString::number(blue) + "(" + QString::number(blue,16).toUpper() + ")" + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + "(" + QString::number(unused1,16).toUpper() + ")" + ", ";
        _s = _s + "fSchemeIndex: " + QString::number(fSchemeIndex) + "(" + QString::number(fSchemeIndex,16).toUpper() + ")" + ", ";
        _s = _s + "unused2: " + QString::number(unused2) + "(" + QString::number(unused2,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtSplitMenuColorContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<MSOCR> smca;
    QString toString() {
        QString _s = "OfficeArtSplitMenuColorContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "smca: " + "[array of smca]" + ", ";
        return _s;
    }
};
class TODO {
public:
    RecordHeader rh;
    QByteArray anon;
    QString toString() {
        QString _s = "TODO:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "anon: " + "[array of anon]" + ", ";
        return _s;
    }
};
class TODOS {
public:
    QList<TODO> anon;
    QString toString() {
        QString _s = "TODOS:";
        _s = _s + "anon: " + anon.toString() + ", ";
        return _s;
    }
};
class FibBase {
public:
    quint16 wIdent;
    quint16 nFib;
    quint16 unused;
    quint16 lid;
    quint16 pnNext;
    bool fDot;
    bool fGlsy;
    bool fComplex;
    bool fHasPic;
    bool cQuickSaves;
    bool fEncrypted;
    bool fWhichTblStm;
    bool fReadOnlyRecommended;
    bool fWriteReservation;
    bool fExtChar;
    bool fLoadOverride;
    bool fFarEast;
    bool fObfuscated;
    quint16 nFibBack;
    quint32 IKey;
    quint8 envr;
    bool fMac;
    bool fEmptySpecial;
    bool fLoadOverridePage;
    bool reserved1;
    bool reserved2;
    quint8 fSpare0;
    quint16 reserved3;
    quint16 reserved4;
    quint32 reserved5;
    quint32 reserved6;
    QString toString() {
        QString _s = "FibBase:";
        _s = _s + "wIdent: " + QString::number(wIdent) + "(" + QString::number(wIdent,16).toUpper() + ")" + ", ";
        _s = _s + "nFib: " + QString::number(nFib) + "(" + QString::number(nFib,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        _s = _s + "lid: " + QString::number(lid) + "(" + QString::number(lid,16).toUpper() + ")" + ", ";
        _s = _s + "pnNext: " + QString::number(pnNext) + "(" + QString::number(pnNext,16).toUpper() + ")" + ", ";
        _s = _s + "fDot: " + QString::number(fDot) + "(" + QString::number(fDot,16).toUpper() + ")" + ", ";
        _s = _s + "fGlsy: " + QString::number(fGlsy) + "(" + QString::number(fGlsy,16).toUpper() + ")" + ", ";
        _s = _s + "fComplex: " + QString::number(fComplex) + "(" + QString::number(fComplex,16).toUpper() + ")" + ", ";
        _s = _s + "fHasPic: " + QString::number(fHasPic) + "(" + QString::number(fHasPic,16).toUpper() + ")" + ", ";
        _s = _s + "cQuickSaves: " + QString::number(cQuickSaves) + "(" + QString::number(cQuickSaves,16).toUpper() + ")" + ", ";
        _s = _s + "fEncrypted: " + QString::number(fEncrypted) + "(" + QString::number(fEncrypted,16).toUpper() + ")" + ", ";
        _s = _s + "fWhichTblStm: " + QString::number(fWhichTblStm) + "(" + QString::number(fWhichTblStm,16).toUpper() + ")" + ", ";
        _s = _s + "fReadOnlyRecommended: " + QString::number(fReadOnlyRecommended) + "(" + QString::number(fReadOnlyRecommended,16).toUpper() + ")" + ", ";
        _s = _s + "fWriteReservation: " + QString::number(fWriteReservation) + "(" + QString::number(fWriteReservation,16).toUpper() + ")" + ", ";
        _s = _s + "fExtChar: " + QString::number(fExtChar) + "(" + QString::number(fExtChar,16).toUpper() + ")" + ", ";
        _s = _s + "fLoadOverride: " + QString::number(fLoadOverride) + "(" + QString::number(fLoadOverride,16).toUpper() + ")" + ", ";
        _s = _s + "fFarEast: " + QString::number(fFarEast) + "(" + QString::number(fFarEast,16).toUpper() + ")" + ", ";
        _s = _s + "fObfuscated: " + QString::number(fObfuscated) + "(" + QString::number(fObfuscated,16).toUpper() + ")" + ", ";
        _s = _s + "nFibBack: " + QString::number(nFibBack) + "(" + QString::number(nFibBack,16).toUpper() + ")" + ", ";
        _s = _s + "IKey: " + QString::number(IKey) + "(" + QString::number(IKey,16).toUpper() + ")" + ", ";
        _s = _s + "envr: " + QString::number(envr) + "(" + QString::number(envr,16).toUpper() + ")" + ", ";
        _s = _s + "fMac: " + QString::number(fMac) + "(" + QString::number(fMac,16).toUpper() + ")" + ", ";
        _s = _s + "fEmptySpecial: " + QString::number(fEmptySpecial) + "(" + QString::number(fEmptySpecial,16).toUpper() + ")" + ", ";
        _s = _s + "fLoadOverridePage: " + QString::number(fLoadOverridePage) + "(" + QString::number(fLoadOverridePage,16).toUpper() + ")" + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "fSpare0: " + QString::number(fSpare0) + "(" + QString::number(fSpare0,16).toUpper() + ")" + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + "(" + QString::number(reserved3,16).toUpper() + ")" + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + "(" + QString::number(reserved4,16).toUpper() + ")" + ", ";
        _s = _s + "reserved5: " + QString::number(reserved5) + "(" + QString::number(reserved5,16).toUpper() + ")" + ", ";
        _s = _s + "reserved6: " + QString::number(reserved6) + "(" + QString::number(reserved6,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class FibRgW97 {
public:
    quint16 reserved1;
    quint16 reserved2;
    quint16 reserved3;
    quint16 reserved4;
    quint16 reserved5;
    quint16 reserved6;
    quint16 reserved7;
    quint16 reserved8;
    quint16 reserved9;
    quint16 reserved10;
    quint16 reserved11;
    quint16 reserved12;
    quint16 reserved13;
    quint16 lidFE;
    QString toString() {
        QString _s = "FibRgW97:";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + "(" + QString::number(reserved3,16).toUpper() + ")" + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + "(" + QString::number(reserved4,16).toUpper() + ")" + ", ";
        _s = _s + "reserved5: " + QString::number(reserved5) + "(" + QString::number(reserved5,16).toUpper() + ")" + ", ";
        _s = _s + "reserved6: " + QString::number(reserved6) + "(" + QString::number(reserved6,16).toUpper() + ")" + ", ";
        _s = _s + "reserved7: " + QString::number(reserved7) + "(" + QString::number(reserved7,16).toUpper() + ")" + ", ";
        _s = _s + "reserved8: " + QString::number(reserved8) + "(" + QString::number(reserved8,16).toUpper() + ")" + ", ";
        _s = _s + "reserved9: " + QString::number(reserved9) + "(" + QString::number(reserved9,16).toUpper() + ")" + ", ";
        _s = _s + "reserved10: " + QString::number(reserved10) + "(" + QString::number(reserved10,16).toUpper() + ")" + ", ";
        _s = _s + "reserved11: " + QString::number(reserved11) + "(" + QString::number(reserved11,16).toUpper() + ")" + ", ";
        _s = _s + "reserved12: " + QString::number(reserved12) + "(" + QString::number(reserved12,16).toUpper() + ")" + ", ";
        _s = _s + "reserved13: " + QString::number(reserved13) + "(" + QString::number(reserved13,16).toUpper() + ")" + ", ";
        _s = _s + "lidFE: " + QString::number(lidFE) + "(" + QString::number(lidFE,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class FibRgLw97 {
public:
    quint32 cbMac;
    quint32 reserved1;
    quint32 reserved2;
    qint32 ccpText;
    qint32 ccpFtn;
    qint32 ccpHdd;
    quint32 reserved3;
    qint32 ccpAtn;
    qint32 ccpEdn;
    qint32 ccpTxbx;
    qint32 ccpHdrTxbx;
    quint32 reserved4;
    quint32 reserved5;
    quint32 reserved6;
    quint32 reserved7;
    quint32 reserved8;
    quint32 reserved9;
    quint32 reserved10;
    quint32 reserved11;
    quint32 reserved12;
    quint32 reserved13;
    quint32 reserved14;
    QString toString() {
        QString _s = "FibRgLw97:";
        _s = _s + "cbMac: " + QString::number(cbMac) + "(" + QString::number(cbMac,16).toUpper() + ")" + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "ccpText: " + QString::number(ccpText) + "(" + QString::number(ccpText,16).toUpper() + ")" + ", ";
        _s = _s + "ccpFtn: " + QString::number(ccpFtn) + "(" + QString::number(ccpFtn,16).toUpper() + ")" + ", ";
        _s = _s + "ccpHdd: " + QString::number(ccpHdd) + "(" + QString::number(ccpHdd,16).toUpper() + ")" + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + "(" + QString::number(reserved3,16).toUpper() + ")" + ", ";
        _s = _s + "ccpAtn: " + QString::number(ccpAtn) + "(" + QString::number(ccpAtn,16).toUpper() + ")" + ", ";
        _s = _s + "ccpEdn: " + QString::number(ccpEdn) + "(" + QString::number(ccpEdn,16).toUpper() + ")" + ", ";
        _s = _s + "ccpTxbx: " + QString::number(ccpTxbx) + "(" + QString::number(ccpTxbx,16).toUpper() + ")" + ", ";
        _s = _s + "ccpHdrTxbx: " + QString::number(ccpHdrTxbx) + "(" + QString::number(ccpHdrTxbx,16).toUpper() + ")" + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + "(" + QString::number(reserved4,16).toUpper() + ")" + ", ";
        _s = _s + "reserved5: " + QString::number(reserved5) + "(" + QString::number(reserved5,16).toUpper() + ")" + ", ";
        _s = _s + "reserved6: " + QString::number(reserved6) + "(" + QString::number(reserved6,16).toUpper() + ")" + ", ";
        _s = _s + "reserved7: " + QString::number(reserved7) + "(" + QString::number(reserved7,16).toUpper() + ")" + ", ";
        _s = _s + "reserved8: " + QString::number(reserved8) + "(" + QString::number(reserved8,16).toUpper() + ")" + ", ";
        _s = _s + "reserved9: " + QString::number(reserved9) + "(" + QString::number(reserved9,16).toUpper() + ")" + ", ";
        _s = _s + "reserved10: " + QString::number(reserved10) + "(" + QString::number(reserved10,16).toUpper() + ")" + ", ";
        _s = _s + "reserved11: " + QString::number(reserved11) + "(" + QString::number(reserved11,16).toUpper() + ")" + ", ";
        _s = _s + "reserved12: " + QString::number(reserved12) + "(" + QString::number(reserved12,16).toUpper() + ")" + ", ";
        _s = _s + "reserved13: " + QString::number(reserved13) + "(" + QString::number(reserved13,16).toUpper() + ")" + ", ";
        _s = _s + "reserved14: " + QString::number(reserved14) + "(" + QString::number(reserved14,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PicturesStream {
public:
    OfficeArtBStoreDelay anon1;
    QString toString() {
        QString _s = "PicturesStream:";
        _s = _s + "anon1: " + anon1.toString() + ", ";
        return _s;
    }
};
class OfficeArtMetafileHeader {
public:
    quint32 cbSize;
    RECT rcBounds;
    POINT ptSize;
    quint32 cbsave;
    quint8 compression;
    quint8 filter;
    QString toString() {
        QString _s = "OfficeArtMetafileHeader:";
        _s = _s + "cbSize: " + QString::number(cbSize) + "(" + QString::number(cbSize,16).toUpper() + ")" + ", ";
        _s = _s + "rcBounds: " + rcBounds.toString() + ", ";
        _s = _s + "ptSize: " + ptSize.toString() + ", ";
        _s = _s + "cbsave: " + QString::number(cbsave) + "(" + QString::number(cbsave,16).toUpper() + ")" + ", ";
        _s = _s + "compression: " + QString::number(compression) + "(" + QString::number(compression,16).toUpper() + ")" + ", ";
        _s = _s + "filter: " + QString::number(filter) + "(" + QString::number(filter,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class NormalViewSetInfoAtom {
public:
    RecordHeader rh;
    RatioStruct leftPortion;
    RatioStruct topPortion;
    quint8 vertBarState;
    quint8 horizBarState;
    quint8 fPreferSingleSet;
    bool fHideThumbnails;
    bool fBarSnapped;
    quint8 reserved;
    QString toString() {
        QString _s = "NormalViewSetInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "leftPortion: " + leftPortion.toString() + ", ";
        _s = _s + "topPortion: " + topPortion.toString() + ", ";
        _s = _s + "vertBarState: " + QString::number(vertBarState) + "(" + QString::number(vertBarState,16).toUpper() + ")" + ", ";
        _s = _s + "horizBarState: " + QString::number(horizBarState) + "(" + QString::number(horizBarState,16).toUpper() + ")" + ", ";
        _s = _s + "fPreferSingleSet: " + QString::number(fPreferSingleSet) + "(" + QString::number(fPreferSingleSet,16).toUpper() + ")" + ", ";
        _s = _s + "fHideThumbnails: " + QString::number(fHideThumbnails) + "(" + QString::number(fHideThumbnails,16).toUpper() + ")" + ", ";
        _s = _s + "fBarSnapped: " + QString::number(fBarSnapped) + "(" + QString::number(fBarSnapped,16).toUpper() + ")" + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class MasterPersistAtom {
public:
    RecordHeader rh;
    PersistIdRef persistIdRef;
    quint8 reserved1;
    bool fNonOutLineData;
    quint8 reserved2;
    quint8 reserved3;
    quint16 reserved4;
    quint32 reserved5;
    quint32 masterId;
    quint32 reserved6;
    QString toString() {
        QString _s = "MasterPersistAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "persistIdRef: " + persistIdRef.toString() + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "fNonOutLineData: " + QString::number(fNonOutLineData) + "(" + QString::number(fNonOutLineData,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + "(" + QString::number(reserved3,16).toUpper() + ")" + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + "(" + QString::number(reserved4,16).toUpper() + ")" + ", ";
        _s = _s + "reserved5: " + QString::number(reserved5) + "(" + QString::number(reserved5,16).toUpper() + ")" + ", ";
        _s = _s + "masterId: " + QString::number(masterId) + "(" + QString::number(masterId,16).toUpper() + ")" + ", ";
        _s = _s + "reserved6: " + QString::number(reserved6) + "(" + QString::number(reserved6,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class SlidePersistAtom {
public:
    RecordHeader rh;
    PersistIdRef persistIdRef;
    bool reserved1;
    bool fShouldCollapse;
    bool fNonOutlineData;
    quint8 reserved2;
    quint8 reserved3;
    quint16 reserved4;
    qint32 cTexts;
    SlideId slideId;
    quint32 reserved5;
    QString toString() {
        QString _s = "SlidePersistAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "persistIdRef: " + persistIdRef.toString() + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "fShouldCollapse: " + QString::number(fShouldCollapse) + "(" + QString::number(fShouldCollapse,16).toUpper() + ")" + ", ";
        _s = _s + "fNonOutlineData: " + QString::number(fNonOutlineData) + "(" + QString::number(fNonOutlineData,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + "(" + QString::number(reserved3,16).toUpper() + ")" + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + "(" + QString::number(reserved4,16).toUpper() + ")" + ", ";
        _s = _s + "cTexts: " + QString::number(cTexts) + "(" + QString::number(cTexts,16).toUpper() + ")" + ", ";
        _s = _s + "slideId: " + slideId.toString() + ", ";
        _s = _s + "reserved5: " + QString::number(reserved5) + "(" + QString::number(reserved5,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TextRuler {
public:
    bool fDefaultTabSize;
    bool fCLevels;
    bool fTabStops;
    bool fLeftMargin1;
    bool fLeftMargin2;
    bool fLeftMargin3;
    bool fLeftMargin4;
    bool fLeftMargin5;
    bool fIndent1;
    bool fIndent2;
    bool fIndent3;
    bool fIndent4;
    bool fIndent5;
    quint8 reserved1;
    quint16 reserved2;
    qint16 cLevels;
    quint16 defaultTabSize;
    TabStops tabs;
    quint16 leftMargin1;
    quint16 indent1;
    quint16 leftMargin2;
    quint16 indent2;
    quint16 leftMargin3;
    quint16 indent3;
    quint16 leftMargin4;
    quint16 indent4;
    quint16 leftMargin5;
    quint16 indent5;
    QString toString() {
        QString _s = "TextRuler:";
        _s = _s + "fDefaultTabSize: " + QString::number(fDefaultTabSize) + "(" + QString::number(fDefaultTabSize,16).toUpper() + ")" + ", ";
        _s = _s + "fCLevels: " + QString::number(fCLevels) + "(" + QString::number(fCLevels,16).toUpper() + ")" + ", ";
        _s = _s + "fTabStops: " + QString::number(fTabStops) + "(" + QString::number(fTabStops,16).toUpper() + ")" + ", ";
        _s = _s + "fLeftMargin1: " + QString::number(fLeftMargin1) + "(" + QString::number(fLeftMargin1,16).toUpper() + ")" + ", ";
        _s = _s + "fLeftMargin2: " + QString::number(fLeftMargin2) + "(" + QString::number(fLeftMargin2,16).toUpper() + ")" + ", ";
        _s = _s + "fLeftMargin3: " + QString::number(fLeftMargin3) + "(" + QString::number(fLeftMargin3,16).toUpper() + ")" + ", ";
        _s = _s + "fLeftMargin4: " + QString::number(fLeftMargin4) + "(" + QString::number(fLeftMargin4,16).toUpper() + ")" + ", ";
        _s = _s + "fLeftMargin5: " + QString::number(fLeftMargin5) + "(" + QString::number(fLeftMargin5,16).toUpper() + ")" + ", ";
        _s = _s + "fIndent1: " + QString::number(fIndent1) + "(" + QString::number(fIndent1,16).toUpper() + ")" + ", ";
        _s = _s + "fIndent2: " + QString::number(fIndent2) + "(" + QString::number(fIndent2,16).toUpper() + ")" + ", ";
        _s = _s + "fIndent3: " + QString::number(fIndent3) + "(" + QString::number(fIndent3,16).toUpper() + ")" + ", ";
        _s = _s + "fIndent4: " + QString::number(fIndent4) + "(" + QString::number(fIndent4,16).toUpper() + ")" + ", ";
        _s = _s + "fIndent5: " + QString::number(fIndent5) + "(" + QString::number(fIndent5,16).toUpper() + ")" + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + "(" + QString::number(reserved1,16).toUpper() + ")" + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + "(" + QString::number(reserved2,16).toUpper() + ")" + ", ";
        _s = _s + "cLevels: " + QString::number(cLevels) + "(" + QString::number(cLevels,16).toUpper() + ")" + ", ";
        _s = _s + "defaultTabSize: " + QString::number(defaultTabSize) + "(" + QString::number(defaultTabSize,16).toUpper() + ")" + ", ";
        _s = _s + "tabs: " + tabs.toString() + ", ";
        _s = _s + "leftMargin1: " + QString::number(leftMargin1) + "(" + QString::number(leftMargin1,16).toUpper() + ")" + ", ";
        _s = _s + "indent1: " + QString::number(indent1) + "(" + QString::number(indent1,16).toUpper() + ")" + ", ";
        _s = _s + "leftMargin2: " + QString::number(leftMargin2) + "(" + QString::number(leftMargin2,16).toUpper() + ")" + ", ";
        _s = _s + "indent2: " + QString::number(indent2) + "(" + QString::number(indent2,16).toUpper() + ")" + ", ";
        _s = _s + "leftMargin3: " + QString::number(leftMargin3) + "(" + QString::number(leftMargin3,16).toUpper() + ")" + ", ";
        _s = _s + "indent3: " + QString::number(indent3) + "(" + QString::number(indent3,16).toUpper() + ")" + ", ";
        _s = _s + "leftMargin4: " + QString::number(leftMargin4) + "(" + QString::number(leftMargin4,16).toUpper() + ")" + ", ";
        _s = _s + "indent4: " + QString::number(indent4) + "(" + QString::number(indent4,16).toUpper() + ")" + ", ";
        _s = _s + "leftMargin5: " + QString::number(leftMargin5) + "(" + QString::number(leftMargin5,16).toUpper() + ")" + ", ";
        _s = _s + "indent5: " + QString::number(indent5) + "(" + QString::number(indent5,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TextPFException {
public:
    PFMasks masks;
    BulletFlags bulletFlags;
    qint16 bulletChar;
    quint16 bulletFontRef;
    quint16 bulletSize;
    quint32 bulletColor;
    quint16 textAlignment;
    quint16 lineSpacing;
    quint16 spaceBefore;
    quint16 spaceAfter;
    quint16 leftMargin;
    quint16 indent;
    quint16 defaultTabSize;
    TabStops tabStops;
    quint16 fontAlign;
    quint16 wrapFlags;
    quint16 textDirection;
    QString toString() {
        QString _s = "TextPFException:";
        _s = _s + "masks: " + masks.toString() + ", ";
        _s = _s + "bulletFlags: " + bulletFlags.toString() + ", ";
        _s = _s + "bulletChar: " + QString::number(bulletChar) + "(" + QString::number(bulletChar,16).toUpper() + ")" + ", ";
        _s = _s + "bulletFontRef: " + QString::number(bulletFontRef) + "(" + QString::number(bulletFontRef,16).toUpper() + ")" + ", ";
        _s = _s + "bulletSize: " + QString::number(bulletSize) + "(" + QString::number(bulletSize,16).toUpper() + ")" + ", ";
        _s = _s + "bulletColor: " + QString::number(bulletColor) + "(" + QString::number(bulletColor,16).toUpper() + ")" + ", ";
        _s = _s + "textAlignment: " + QString::number(textAlignment) + "(" + QString::number(textAlignment,16).toUpper() + ")" + ", ";
        _s = _s + "lineSpacing: " + QString::number(lineSpacing) + "(" + QString::number(lineSpacing,16).toUpper() + ")" + ", ";
        _s = _s + "spaceBefore: " + QString::number(spaceBefore) + "(" + QString::number(spaceBefore,16).toUpper() + ")" + ", ";
        _s = _s + "spaceAfter: " + QString::number(spaceAfter) + "(" + QString::number(spaceAfter,16).toUpper() + ")" + ", ";
        _s = _s + "leftMargin: " + QString::number(leftMargin) + "(" + QString::number(leftMargin,16).toUpper() + ")" + ", ";
        _s = _s + "indent: " + QString::number(indent) + "(" + QString::number(indent,16).toUpper() + ")" + ", ";
        _s = _s + "defaultTabSize: " + QString::number(defaultTabSize) + "(" + QString::number(defaultTabSize,16).toUpper() + ")" + ", ";
        _s = _s + "tabStops: " + tabStops.toString() + ", ";
        _s = _s + "fontAlign: " + QString::number(fontAlign) + "(" + QString::number(fontAlign,16).toUpper() + ")" + ", ";
        _s = _s + "wrapFlags: " + QString::number(wrapFlags) + "(" + QString::number(wrapFlags,16).toUpper() + ")" + ", ";
        _s = _s + "textDirection: " + QString::number(textDirection) + "(" + QString::number(textDirection,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class TextCFException {
public:
    CFMasks masks;
    CFStyle fontStyle;
    quint16 fontRef;
    quint16 oldEAFontRef;
    quint16 ansiFontRef;
    quint16 symbolFontRef;
    quint16 fontSize;
    quint32 color;
    quint16 position;
    QString toString() {
        QString _s = "TextCFException:";
        _s = _s + "masks: " + masks.toString() + ", ";
        _s = _s + "fontStyle: " + fontStyle.toString() + ", ";
        _s = _s + "fontRef: " + QString::number(fontRef) + "(" + QString::number(fontRef,16).toUpper() + ")" + ", ";
        _s = _s + "oldEAFontRef: " + QString::number(oldEAFontRef) + "(" + QString::number(oldEAFontRef,16).toUpper() + ")" + ", ";
        _s = _s + "ansiFontRef: " + QString::number(ansiFontRef) + "(" + QString::number(ansiFontRef,16).toUpper() + ")" + ", ";
        _s = _s + "symbolFontRef: " + QString::number(symbolFontRef) + "(" + QString::number(symbolFontRef,16).toUpper() + ")" + ", ";
        _s = _s + "fontSize: " + QString::number(fontSize) + "(" + QString::number(fontSize,16).toUpper() + ")" + ", ";
        _s = _s + "color: " + QString::number(color) + "(" + QString::number(color,16).toUpper() + ")" + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class KinsokuContainer {
public:
    RecordHeader rh;
    KinsokuAtom kinsokuAtom;
    QString toString() {
        QString _s = "KinsokuContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "kinsokuAtom: " + kinsokuAtom.toString() + ", ";
        return _s;
    }
};
class TextMasterStyleLevel {
public:
    TextPFException pf;
    TextCFException cf;
    QString toString() {
        QString _s = "TextMasterStyleLevel:";
        _s = _s + "pf: " + pf.toString() + ", ";
        _s = _s + "cf: " + cf.toString() + ", ";
        return _s;
    }
};
class DocumentAtom {
public:
    RecordHeader rh;
    PointStruct slideSize;
    PointStruct notesSize;
    RatioStruct serverZoom;
    PersistIdRef notesMasterPersistIdRef;
    PersistIdRef handoutMasterPersistIdRef;
    quint16 firstSlideNumber;
    quint16 slideSizeType;
    quint8 fSaveWithFonts;
    quint8 fOmitTitlePlace;
    quint8 fRightToLeft;
    quint8 fShowComments;
    QString toString() {
        QString _s = "DocumentAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "slideSize: " + QString::number(slideSize) + "(" + QString::number(slideSize,16).toUpper() + ")" + ", ";
        _s = _s + "notesSize: " + QString::number(notesSize) + "(" + QString::number(notesSize,16).toUpper() + ")" + ", ";
        _s = _s + "serverZoom: " + serverZoom.toString() + ", ";
        _s = _s + "notesMasterPersistIdRef: " + notesMasterPersistIdRef.toString() + ", ";
        _s = _s + "handoutMasterPersistIdRef: " + handoutMasterPersistIdRef.toString() + ", ";
        _s = _s + "firstSlideNumber: " + QString::number(firstSlideNumber) + "(" + QString::number(firstSlideNumber,16).toUpper() + ")" + ", ";
        _s = _s + "slideSizeType: " + QString::number(slideSizeType) + "(" + QString::number(slideSizeType,16).toUpper() + ")" + ", ";
        _s = _s + "fSaveWithFonts: " + QString::number(fSaveWithFonts) + "(" + QString::number(fSaveWithFonts,16).toUpper() + ")" + ", ";
        _s = _s + "fOmitTitlePlace: " + QString::number(fOmitTitlePlace) + "(" + QString::number(fOmitTitlePlace,16).toUpper() + ")" + ", ";
        _s = _s + "fRightToLeft: " + QString::number(fRightToLeft) + "(" + QString::number(fRightToLeft,16).toUpper() + ")" + ", ";
        _s = _s + "fShowComments: " + QString::number(fShowComments) + "(" + QString::number(fShowComments,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class ExObjListContainer {
public:
    RecordHeader rh;
    ExObjListAtom exObjListAtom;
    QVector<ExObjListSubContainer> rgChildRec;
    QString toString() {
        QString _s = "ExObjListContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exObjListAtom: " + exObjListAtom.toString() + ", ";
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
};
class ExOleLinkContainer {
public:
    RecordHeader rh;
    ExOleLinkAtom exOleLinkAtom;
    ExOleObjAtom exOleObjAtom;
    MenuNameAtom menuNameAtom;
    ProgIDAtom progIdAtom;
    ClipboardNameAtom clipboardNameAtom;
    MetafileBlob metafile;
    QString toString() {
        QString _s = "ExOleLinkContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exOleLinkAtom: " + exOleLinkAtom.toString() + ", ";
        _s = _s + "exOleObjAtom: " + exOleObjAtom.toString() + ", ";
        _s = _s + "menuNameAtom: " + menuNameAtom.toString() + ", ";
        _s = _s + "progIdAtom: " + progIdAtom.toString() + ", ";
        _s = _s + "clipboardNameAtom: " + clipboardNameAtom.toString() + ", ";
        _s = _s + "metafile: " + metafile.toString() + ", ";
        return _s;
    }
};
class ExOleEmbedContainer {
public:
    RecordHeader rh;
    ExOleEmbedAtom exOleEmbedAtom;
    ExOleObjAtom exOleObjAtom;
    MenuNameAtom menuNameAtom;
    ProgIDAtom progIdAtom;
    ClipboardNameAtom clipboardNameAtom;
    MetafileBlob metafile;
    QString toString() {
        QString _s = "ExOleEmbedContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exOleEmbedAtom: " + exOleEmbedAtom.toString() + ", ";
        _s = _s + "exOleObjAtom: " + exOleObjAtom.toString() + ", ";
        _s = _s + "menuNameAtom: " + menuNameAtom.toString() + ", ";
        _s = _s + "progIdAtom: " + progIdAtom.toString() + ", ";
        _s = _s + "clipboardNameAtom: " + clipboardNameAtom.toString() + ", ";
        _s = _s + "metafile: " + metafile.toString() + ", ";
        return _s;
    }
};
class OfficeArtFDGGBlock {
public:
    OfficeArtRecordHeader rh;
    OfficeArtFDGG head;
    QVector<OfficeArtIDCL> Rgidcl;
    QString toString() {
        QString _s = "OfficeArtFDGGBlock:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "head: " + head.toString() + ", ";
        _s = _s + "Rgidcl: " + "[array of Rgidcl]" + ", ";
        return _s;
    }
};
class OfficeArtClientAnchor {
public:
    OfficeArtRecordHeader rh;
    SmallRectStruct rect1;
    RectStruct rect2;
    QString toString() {
        QString _s = "OfficeArtClientAnchor:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rect1: " + rect1.toString() + ", ";
        _s = _s + "rect2: " + rect2.toString() + ", ";
        return _s;
    }
};
class OfficeArtFOPTE {
public:
    OfficeArtFOPTEOPID opid;
    qint32 op;
    QByteArray complexData;
    QString toString() {
        QString _s = "OfficeArtFOPTE:";
        _s = _s + "opid: " + opid.toString() + ", ";
        _s = _s + "op: " + QString::number(op) + "(" + QString::number(op,16).toUpper() + ")" + ", ";
        _s = _s + "complexData: " + "[array of complexData]" + ", ";
        return _s;
    }
};
class Fib {
public:
    FibBase base;
    quint16 csw;
    FibRgW97 fibRgW;
    quint16 cslw;
    FibRgLw97 fibRgLw;
    quint16 cbRgFcLcb;
    QString toString() {
        QString _s = "Fib:";
        _s = _s + "base: " + base.toString() + ", ";
        _s = _s + "csw: " + QString::number(csw) + "(" + QString::number(csw,16).toUpper() + ")" + ", ";
        _s = _s + "fibRgW: " + fibRgW.toString() + ", ";
        _s = _s + "cslw: " + QString::number(cslw) + "(" + QString::number(cslw,16).toUpper() + ")" + ", ";
        _s = _s + "fibRgLw: " + fibRgLw.toString() + ", ";
        _s = _s + "cbRgFcLcb: " + QString::number(cbRgFcLcb) + "(" + QString::number(cbRgFcLcb,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class OfficeArtBlipEMF {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipEMF:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "metafileHeader: " + metafileHeader.toString() + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class OfficeArtBlipWMF {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipWMF:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "metafileHeader: " + metafileHeader.toString() + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class OfficeArtBlipPICT {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
    QString toString() {
        QString _s = "OfficeArtBlipPICT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "metafileHeader: " + metafileHeader.toString() + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
};
class OfficeArtBlip {
public:
    void * anon;
    QString toString() {
        QString _s = "OfficeArtBlip:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class NormalViewSetInfoContainer {
public:
    RecordHeader rh;
    NormalViewSetInfoAtom normalViewSetInfoAtom;
    QString toString() {
        QString _s = "NormalViewSetInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "normalViewSetInfoAtom: " + normalViewSetInfoAtom.toString() + ", ";
        return _s;
    }
};
class SlideListWithTextSubContainerOrAtom {
public:
    void * anon;
    QString toString() {
        QString _s = "SlideListWithTextSubContainerOrAtom:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class TextCFExceptionAtom {
public:
    RecordHeader rh;
    TextCFException cf;
    QString toString() {
        QString _s = "TextCFExceptionAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "cf: " + cf.toString() + ", ";
        return _s;
    }
};
class DefaultRulerAtom {
public:
    RecordHeader rh;
    TextRuler defaultTextRuler;
    QString toString() {
        QString _s = "DefaultRulerAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "defaultTextRuler: " + defaultTextRuler.toString() + ", ";
        return _s;
    }
};
class TextPFExceptionAtom {
public:
    RecordHeader rh;
    quint16 reserved;
    TextPFException pf;
    QString toString() {
        QString _s = "TextPFExceptionAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        _s = _s + "pf: " + pf.toString() + ", ";
        return _s;
    }
};
class TextMasterStyleAtom {
public:
    RecordHeader rh;
    quint16 cLevels;
    quint16 lstLvl1level;
    TextMasterStyleLevel lstLvl1;
    quint16 lstLvl2level;
    TextMasterStyleLevel lstLvl2;
    quint16 lstLvl3level;
    TextMasterStyleLevel lstLvl3;
    quint16 lstLvl4level;
    TextMasterStyleLevel lstLvl4;
    quint16 lstLvl5level;
    TextMasterStyleLevel lstLvl5;
    QString toString() {
        QString _s = "TextMasterStyleAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "cLevels: " + QString::number(cLevels) + "(" + QString::number(cLevels,16).toUpper() + ")" + ", ";
        _s = _s + "lstLvl1level: " + QString::number(lstLvl1level) + "(" + QString::number(lstLvl1level,16).toUpper() + ")" + ", ";
        _s = _s + "lstLvl1: " + lstLvl1.toString() + ", ";
        _s = _s + "lstLvl2level: " + QString::number(lstLvl2level) + "(" + QString::number(lstLvl2level,16).toUpper() + ")" + ", ";
        _s = _s + "lstLvl2: " + lstLvl2.toString() + ", ";
        _s = _s + "lstLvl3level: " + QString::number(lstLvl3level) + "(" + QString::number(lstLvl3level,16).toUpper() + ")" + ", ";
        _s = _s + "lstLvl3: " + lstLvl3.toString() + ", ";
        _s = _s + "lstLvl4level: " + QString::number(lstLvl4level) + "(" + QString::number(lstLvl4level,16).toUpper() + ")" + ", ";
        _s = _s + "lstLvl4: " + lstLvl4.toString() + ", ";
        _s = _s + "lstLvl5level: " + QString::number(lstLvl5level) + "(" + QString::number(lstLvl5level,16).toUpper() + ")" + ", ";
        _s = _s + "lstLvl5: " + lstLvl5.toString() + ", ";
        return _s;
    }
};
class ExObjListSubContainer {
public:
    void * anon;
    QString toString() {
        QString _s = "ExObjListSubContainer:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class OfficeArtDggContainer {
public:
    OfficeArtRecordHeader rh;
    OfficeArtFDGGBlock drawingGroup;
    OfficeArtBStoreContainer blipStore;
    OfficeArtFOPT drawingPrimaryOptions;
    OfficeArtTertiaryFOPT drawingTertiaryOptions;
    OfficeArtColorMRUContainer colorMRU;
    OfficeArtSplitMenuColorContainer splitColors;
    QString toString() {
        QString _s = "OfficeArtDggContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "drawingGroup: " + drawingGroup.toString() + ", ";
        _s = _s + "blipStore: " + blipStore.toString() + ", ";
        _s = _s + "drawingPrimaryOptions: " + drawingPrimaryOptions.toString() + ", ";
        _s = _s + "drawingTertiaryOptions: " + drawingTertiaryOptions.toString() + ", ";
        _s = _s + "colorMRU: " + colorMRU.toString() + ", ";
        _s = _s + "splitColors: " + splitColors.toString() + ", ";
        return _s;
    }
};
class OfficeArtSpContainer {
public:
    OfficeArtRecordHeader rh;
    OfficeArtFSPGR shapeGroup;
    OfficeArtFSP shapeProp;
    OfficeArtFPSPL deletedshape;
    OfficeArtFOPT shapePrimaryOptions;
    OfficeArtSecondaryFOPT shapeSecondaryOptions1;
    OfficeArtTertiaryFOPT shapeTertiaryOptions1;
    OfficeArtChildAnchor childAnchor;
    OfficeArtClientAnchor clientAnchor;
    OfficeArtClientData clientData;
    OfficeArtClientTextBox clientTextbox;
    QString toString() {
        QString _s = "OfficeArtSpContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "shapeGroup: " + shapeGroup.toString() + ", ";
        _s = _s + "shapeProp: " + shapeProp.toString() + ", ";
        _s = _s + "deletedshape: " + deletedshape.toString() + ", ";
        _s = _s + "shapePrimaryOptions: " + shapePrimaryOptions.toString() + ", ";
        _s = _s + "shapeSecondaryOptions1: " + shapeSecondaryOptions1.toString() + ", ";
        _s = _s + "shapeTertiaryOptions1: " + shapeTertiaryOptions1.toString() + ", ";
        _s = _s + "childAnchor: " + childAnchor.toString() + ", ";
        _s = _s + "clientAnchor: " + clientAnchor.toString() + ", ";
        _s = _s + "clientData: " + clientData.toString() + ", ";
        _s = _s + "clientTextbox: " + clientTextbox.toString() + ", ";
        return _s;
    }
};
class WordDocument {
public:
    Fib fib;
    QString toString() {
        QString _s = "WordDocument:";
        _s = _s + "fib: " + fib.toString() + ", ";
        return _s;
    }
};
class OfficeArtFBSE {
public:
    OfficeArtRecordHeader rh;
    quint8 btWin32;
    quint8 btMacOS;
    QByteArray rgbUid;
    quint16 tag;
    quint32 size;
    quint32 cRef;
    quint32 foDelay;
    quint8 unused1;
    quint8 cbName;
    quint8 unused2;
    quint8 unused3;
    QByteArray nameData;
    OfficeArtBlip embeddedBlip;
    QString toString() {
        QString _s = "OfficeArtFBSE:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "btWin32: " + QString::number(btWin32) + "(" + QString::number(btWin32,16).toUpper() + ")" + ", ";
        _s = _s + "btMacOS: " + QString::number(btMacOS) + "(" + QString::number(btMacOS,16).toUpper() + ")" + ", ";
        _s = _s + "rgbUid: " + "[array of rgbUid]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "size: " + QString::number(size) + "(" + QString::number(size,16).toUpper() + ")" + ", ";
        _s = _s + "cRef: " + QString::number(cRef) + "(" + QString::number(cRef,16).toUpper() + ")" + ", ";
        _s = _s + "foDelay: " + QString::number(foDelay) + "(" + QString::number(foDelay,16).toUpper() + ")" + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + "(" + QString::number(unused1,16).toUpper() + ")" + ", ";
        _s = _s + "cbName: " + QString::number(cbName) + "(" + QString::number(cbName,16).toUpper() + ")" + ", ";
        _s = _s + "unused2: " + QString::number(unused2) + "(" + QString::number(unused2,16).toUpper() + ")" + ", ";
        _s = _s + "unused3: " + QString::number(unused3) + "(" + QString::number(unused3,16).toUpper() + ")" + ", ";
        _s = _s + "nameData: " + "[array of nameData]" + ", ";
        _s = _s + "embeddedBlip: " + embeddedBlip.toString() + ", ";
        return _s;
    }
};
class OfficeArtBStoreContainerFileBlock {
public:
    void * anon;
    QString toString() {
        QString _s = "OfficeArtBStoreContainerFileBlock:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class DocumentTextInfoContainer {
public:
    RecordHeader rh;
    KinsokuContainer kinsoku;
    FontCollectionContainer fontCollection;
    TextCFExceptionAtom textCFDefaultsAtom;
    TextPFExceptionAtom textPFDefaultsAtom;
    DefaultRulerAtom defaultRulerAtom;
    TextSIExceptionAtom textSIDefaultsAtom;
    TextMasterStyleAtom textMasterStyleAtom;
    QString toString() {
        QString _s = "DocumentTextInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "kinsoku: " + kinsoku.toString() + ", ";
        _s = _s + "fontCollection: " + fontCollection.toString() + ", ";
        _s = _s + "textCFDefaultsAtom: " + textCFDefaultsAtom.toString() + ", ";
        _s = _s + "textPFDefaultsAtom: " + textPFDefaultsAtom.toString() + ", ";
        _s = _s + "defaultRulerAtom: " + defaultRulerAtom.toString() + ", ";
        _s = _s + "textSIDefaultsAtom: " + textSIDefaultsAtom.toString() + ", ";
        _s = _s + "textMasterStyleAtom: " + textMasterStyleAtom.toString() + ", ";
        return _s;
    }
};
class DrawingGroupContainer {
public:
    RecordHeader rh;
    OfficeArtDggContainer OfficeArtDgg;
    QString toString() {
        QString _s = "DrawingGroupContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "OfficeArtDgg: " + OfficeArtDgg.toString() + ", ";
        return _s;
    }
};
class OfficeArtDgContainer {
public:
    OfficeArtRecordHeader rh;
    OfficeArtFDG drawingData;
    OfficeArtFRITContainer regroupItems;
    OfficeArtSpgrContainer groupShape;
    OfficeArtSpContainer shape;
    QList<OfficeArtSpgrContainerFileBlock> deletedShapes;
    OfficeArtSolverContainer solvers;
    QString toString() {
        QString _s = "OfficeArtDgContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "drawingData: " + drawingData.toString() + ", ";
        _s = _s + "regroupItems: " + regroupItems.toString() + ", ";
        _s = _s + "groupShape: " + groupShape.toString() + ", ";
        _s = _s + "shape: " + shape.toString() + ", ";
        _s = _s + "deletedShapes: " + deletedShapes.toString() + ", ";
        _s = _s + "solvers: " + solvers.toString() + ", ";
        return _s;
    }
};
class OfficeArtSpgrContainerFileBlock {
public:
    void * anon;
    QString toString() {
        QString _s = "OfficeArtSpgrContainerFileBlock:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class DocumentContainer {
public:
    RecordHeader rh;
    DocumentAtom documentAtom;
    ExObjListContainer exObjList;
    DocumentTextInfoContainer documentTextInfo;
    DrawingGroupContainer drawingGroup;
    MasterListWithTextContainer masterList;
    DocInfoListContainer docInfoList;
    SlideListWithTextContainer slideList;
    EndDocumentAtom endDocumentAtom;
    QString toString() {
        QString _s = "DocumentContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "documentAtom: " + documentAtom.toString() + ", ";
        _s = _s + "exObjList: " + exObjList.toString() + ", ";
        _s = _s + "documentTextInfo: " + documentTextInfo.toString() + ", ";
        _s = _s + "drawingGroup: " + drawingGroup.toString() + ", ";
        _s = _s + "masterList: " + masterList.toString() + ", ";
        _s = _s + "docInfoList: " + docInfoList.toString() + ", ";
        _s = _s + "slideList: " + slideList.toString() + ", ";
        _s = _s + "endDocumentAtom: " + endDocumentAtom.toString() + ", ";
        return _s;
    }
};
class DrawingContainer {
public:
    RecordHeader rh;
    OfficeArtDgContainer OfficeArtDg;
    QString toString() {
        QString _s = "DrawingContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "OfficeArtDg: " + OfficeArtDg.toString() + ", ";
        return _s;
    }
};
class SlideContainer {
public:
    RecordHeader rh;
    SlideAtom slideAtom;
    SlideShowSlideInfoAtom slideShowSlideInfoAtom;
    DrawingContainer drawing;
    SlideSchemeColorSchemeAtom slideSchemeColorSchemeAtom;
    SlideProgTagscontainer slideProgTagsContainer;
    QString toString() {
        QString _s 