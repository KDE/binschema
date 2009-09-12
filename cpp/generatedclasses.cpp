#include <QString>
#include <QByteArray>
#include <QVector>
#include <QSharedPointer>
#include "leinputstream.h"
namespace {
class RecordHeader;
void parseRecordHeader(LEInputStream& in, RecordHeader& _s);
class CurrentUserAtom;
void parseCurrentUserAtom(LEInputStream& in, CurrentUserAtom& _s);
class Byte;
void parseByte(LEInputStream& in, Byte& _s);
class CurrentUserStream;
void parseCurrentUserStream(LEInputStream& in, CurrentUserStream& _s);
class OfficeArtBStoreDelay;
void parseOfficeArtBStoreDelay(LEInputStream& in, OfficeArtBStoreDelay& _s);
class OfficeArtRecordHeader;
void parseOfficeArtRecordHeader(LEInputStream& in, OfficeArtRecordHeader& _s);
class OfficeArtBlipJPEG;
void parseOfficeArtBlipJPEG(LEInputStream& in, OfficeArtBlipJPEG& _s);
class OfficeArtBlipPNG;
void parseOfficeArtBlipPNG(LEInputStream& in, OfficeArtBlipPNG& _s);
class OfficeArtBlipDIB;
void parseOfficeArtBlipDIB(LEInputStream& in, OfficeArtBlipDIB& _s);
class OfficeArtBlipTIFF;
void parseOfficeArtBlipTIFF(LEInputStream& in, OfficeArtBlipTIFF& _s);
class RECT;
void parseRECT(LEInputStream& in, RECT& _s);
class POINT;
void parsePOINT(LEInputStream& in, POINT& _s);
class PowerPointStructs;
void parsePowerPointStructs(LEInputStream& in, PowerPointStructs& _s);
class SlideHeadersFootersContainer;
void parseSlideHeadersFootersContainer(LEInputStream& in, SlideHeadersFootersContainer& _s);
class NotesHeadersFootersContainer;
void parseNotesHeadersFootersContainer(LEInputStream& in, NotesHeadersFootersContainer& _s);
class PerSlideHeadersFootersContainer;
void parsePerSlideHeadersFootersContainer(LEInputStream& in, PerSlideHeadersFootersContainer& _s);
class EndDocumentAtom;
void parseEndDocumentAtom(LEInputStream& in, EndDocumentAtom& _s);
class DocInfoListContainer;
void parseDocInfoListContainer(LEInputStream& in, DocInfoListContainer& _s);
class DocInfoListSubContainerOrAtom;
void parseDocInfoListSubContainerOrAtom(LEInputStream& in, DocInfoListSubContainerOrAtom& _s);
class SlideViewInfoInstance;
void parseSlideViewInfoInstance(LEInputStream& in, SlideViewInfoInstance& _s);
class MasterListWithTextContainer;
void parseMasterListWithTextContainer(LEInputStream& in, MasterListWithTextContainer& _s);
class SlideListWithTextContainer;
void parseSlideListWithTextContainer(LEInputStream& in, SlideListWithTextContainer& _s);
class NotesListWithTextContainer;
void parseNotesListWithTextContainer(LEInputStream& in, NotesListWithTextContainer& _s);
class TextHeaderAtom;
void parseTextHeaderAtom(LEInputStream& in, TextHeaderAtom& _s);
class TextCharsAtom;
void parseTextCharsAtom(LEInputStream& in, TextCharsAtom& _s);
class TextBytesAtom;
void parseTextBytesAtom(LEInputStream& in, TextBytesAtom& _s);
class MasterTextPropAtom;
void parseMasterTextPropAtom(LEInputStream& in, MasterTextPropAtom& _s);
class StyleTextPropAtom;
void parseStyleTextPropAtom(LEInputStream& in, StyleTextPropAtom& _s);
class SlideNumberMCAtom;
void parseSlideNumberMCAtom(LEInputStream& in, SlideNumberMCAtom& _s);
class DateTimeMCAtom;
void parseDateTimeMCAtom(LEInputStream& in, DateTimeMCAtom& _s);
class GenericDateMCAtom;
void parseGenericDateMCAtom(LEInputStream& in, GenericDateMCAtom& _s);
class HeaderMCAtom;
void parseHeaderMCAtom(LEInputStream& in, HeaderMCAtom& _s);
class FooterMCAtom;
void parseFooterMCAtom(LEInputStream& in, FooterMCAtom& _s);
class RTFDateTimeMCAtom;
void parseRTFDateTimeMCAtom(LEInputStream& in, RTFDateTimeMCAtom& _s);
class TextBookmarkAtom;
void parseTextBookmarkAtom(LEInputStream& in, TextBookmarkAtom& _s);
class TextSpecialInfoAtom;
void parseTextSpecialInfoAtom(LEInputStream& in, TextSpecialInfoAtom& _s);
class InteractiveInfoInstance;
void parseInteractiveInfoInstance(LEInputStream& in, InteractiveInfoInstance& _s);
class TextInteractiveInfoInstance;
void parseTextInteractiveInfoInstance(LEInputStream& in, TextInteractiveInfoInstance& _s);
class SlideId;
void parseSlideId(LEInputStream& in, SlideId& _s);
class TabStops;
void parseTabStops(LEInputStream& in, TabStops& _s);
class TabStop;
void parseTabStop(LEInputStream& in, TabStop& _s);
class BulletFlags;
void parseBulletFlags(LEInputStream& in, BulletFlags& _s);
class PFMasks;
void parsePFMasks(LEInputStream& in, PFMasks& _s);
class CFMasks;
void parseCFMasks(LEInputStream& in, CFMasks& _s);
class CFStyle;
void parseCFStyle(LEInputStream& in, CFStyle& _s);
class FontCollectionContainer;
void parseFontCollectionContainer(LEInputStream& in, FontCollectionContainer& _s);
class FontEntityAtom;
void parseFontEntityAtom(LEInputStream& in, FontEntityAtom& _s);
class KinsokuAtom;
void parseKinsokuAtom(LEInputStream& in, KinsokuAtom& _s);
class TextSIExceptionAtom;
void parseTextSIExceptionAtom(LEInputStream& in, TextSIExceptionAtom& _s);
class ExOleEmbedAtom;
void parseExOleEmbedAtom(LEInputStream& in, ExOleEmbedAtom& _s);
class PointStruct;
void parsePointStruct(LEInputStream& in, PointStruct& _s);
class RatioStruct;
void parseRatioStruct(LEInputStream& in, RatioStruct& _s);
class PersistDirectoryAtom;
void parsePersistDirectoryAtom(LEInputStream& in, PersistDirectoryAtom& _s);
class PersistDirectoryEntry;
void parsePersistDirectoryEntry(LEInputStream& in, PersistDirectoryEntry& _s);
class PersistOffsetEntry;
void parsePersistOffsetEntry(LEInputStream& in, PersistOffsetEntry& _s);
class PersistIdRef;
void parsePersistIdRef(LEInputStream& in, PersistIdRef& _s);
class MainMasterContainer;
void parseMainMasterContainer(LEInputStream& in, MainMasterContainer& _s);
class NotesContainer;
void parseNotesContainer(LEInputStream& in, NotesContainer& _s);
class HandoutContainer;
void parseHandoutContainer(LEInputStream& in, HandoutContainer& _s);
class ExControlStg;
void parseExControlStg(LEInputStream& in, ExControlStg& _s);
class ExOleObjStg;
void parseExOleObjStg(LEInputStream& in, ExOleObjStg& _s);
class UserEditAtom;
void parseUserEditAtom(LEInputStream& in, UserEditAtom& _s);
class VbaProjectStg;
void parseVbaProjectStg(LEInputStream& in, VbaProjectStg& _s);
class SlideProgTagscontainer;
void parseSlideProgTagscontainer(LEInputStream& in, SlideProgTagscontainer& _s);
class SlideAtom;
void parseSlideAtom(LEInputStream& in, SlideAtom& _s);
class SlideShowSlideInfoAtom;
void parseSlideShowSlideInfoAtom(LEInputStream& in, SlideShowSlideInfoAtom& _s);
class SlideShowDocInfoAtom;
void parseSlideShowDocInfoAtom(LEInputStream& in, SlideShowDocInfoAtom& _s);
class SlideSchemeColorSchemeAtom;
void parseSlideSchemeColorSchemeAtom(LEInputStream& in, SlideSchemeColorSchemeAtom& _s);
class RoundTripSlideRecord;
void parseRoundTripSlideRecord(LEInputStream& in, RoundTripSlideRecord& _s);
class ColorStruct;
void parseColorStruct(LEInputStream& in, ColorStruct& _s);
class ExObjListAtom;
void parseExObjListAtom(LEInputStream& in, ExObjListAtom& _s);
class ExOleLinkAtom;
void parseExOleLinkAtom(LEInputStream& in, ExOleLinkAtom& _s);
class ExOleObjAtom;
void parseExOleObjAtom(LEInputStream& in, ExOleObjAtom& _s);
class MenuNameAtom;
void parseMenuNameAtom(LEInputStream& in, MenuNameAtom& _s);
class ProgIDAtom;
void parseProgIDAtom(LEInputStream& in, ProgIDAtom& _s);
class ClipboardNameAtom;
void parseClipboardNameAtom(LEInputStream& in, ClipboardNameAtom& _s);
class MetafileBlob;
void parseMetafileBlob(LEInputStream& in, MetafileBlob& _s);
class OfficeArtFDGG;
void parseOfficeArtFDGG(LEInputStream& in, OfficeArtFDGG& _s);
class OfficeArtFDG;
void parseOfficeArtFDG(LEInputStream& in, OfficeArtFDG& _s);
class OfficeArtFRITContainer;
void parseOfficeArtFRITContainer(LEInputStream& in, OfficeArtFRITContainer& _s);
class OfficeArtFRIT;
void parseOfficeArtFRIT(LEInputStream& in, OfficeArtFRIT& _s);
class OfficeArtBStoreContainer;
void parseOfficeArtBStoreContainer(LEInputStream& in, OfficeArtBStoreContainer& _s);
class OfficeArtSpgrContainer;
void parseOfficeArtSpgrContainer(LEInputStream& in, OfficeArtSpgrContainer& _s);
class OfficeArtSolverContainer;
void parseOfficeArtSolverContainer(LEInputStream& in, OfficeArtSolverContainer& _s);
class OfficeArtFSPGR;
void parseOfficeArtFSPGR(LEInputStream& in, OfficeArtFSPGR& _s);
class OfficeArtFSP;
void parseOfficeArtFSP(LEInputStream& in, OfficeArtFSP& _s);
class OfficeArtFOPT;
void parseOfficeArtFOPT(LEInputStream& in, OfficeArtFOPT& _s);
class OfficeArtChildAnchor;
void parseOfficeArtChildAnchor(LEInputStream& in, OfficeArtChildAnchor& _s);
class OfficeArtFPSPL;
void parseOfficeArtFPSPL(LEInputStream& in, OfficeArtFPSPL& _s);
class OfficeArtSecondaryFOPT;
void parseOfficeArtSecondaryFOPT(LEInputStream& in, OfficeArtSecondaryFOPT& _s);
class OfficeArtTertiaryFOPT;
void parseOfficeArtTertiaryFOPT(LEInputStream& in, OfficeArtTertiaryFOPT& _s);
class RectStruct;
void parseRectStruct(LEInputStream& in, RectStruct& _s);
class SmallRectStruct;
void parseSmallRectStruct(LEInputStream& in, SmallRectStruct& _s);
class ShapeFlagsAtom;
void parseShapeFlagsAtom(LEInputStream& in, ShapeFlagsAtom& _s);
class ShapeFlags10Atom;
void parseShapeFlags10Atom(LEInputStream& in, ShapeFlags10Atom& _s);
class ExObjRefAtom;
void parseExObjRefAtom(LEInputStream& in, ExObjRefAtom& _s);
class AnimationInfoContainer;
void parseAnimationInfoContainer(LEInputStream& in, AnimationInfoContainer& _s);
class MouseClickInteractiveInfoContainer;
void parseMouseClickInteractiveInfoContainer(LEInputStream& in, MouseClickInteractiveInfoContainer& _s);
class MouseOverInteractiveInfoContainer;
void parseMouseOverInteractiveInfoContainer(LEInputStream& in, MouseOverInteractiveInfoContainer& _s);
class PlaceholderAtom;
void parsePlaceholderAtom(LEInputStream& in, PlaceholderAtom& _s);
class RecolorInfoAtom;
void parseRecolorInfoAtom(LEInputStream& in, RecolorInfoAtom& _s);
class OutlineTextRefAtom;
void parseOutlineTextRefAtom(LEInputStream& in, OutlineTextRefAtom& _s);
class ShapeClientRoundtripDataSubcontainerOrAtom;
void parseShapeClientRoundtripDataSubcontainerOrAtom(LEInputStream& in, ShapeClientRoundtripDataSubcontainerOrAtom& _s);
class OfficeArtClientTextBox;
void parseOfficeArtClientTextBox(LEInputStream& in, OfficeArtClientTextBox& _s);
class TextClientDataSubContainerOrAtom;
void parseTextClientDataSubContainerOrAtom(LEInputStream& in, TextClientDataSubContainerOrAtom& _s);
class OfficeArtIDCL;
void parseOfficeArtIDCL(LEInputStream& in, OfficeArtIDCL& _s);
class OfficeArtFOPTEOPID;
void parseOfficeArtFOPTEOPID(LEInputStream& in, OfficeArtFOPTEOPID& _s);
class OfficeArtColorMRUContainer;
void parseOfficeArtColorMRUContainer(LEInputStream& in, OfficeArtColorMRUContainer& _s);
class MSOCR;
void parseMSOCR(LEInputStream& in, MSOCR& _s);
class OfficeArtSplitMenuColorContainer;
void parseOfficeArtSplitMenuColorContainer(LEInputStream& in, OfficeArtSplitMenuColorContainer& _s);
class TODO;
void parseTODO(LEInputStream& in, TODO& _s);
class TODOS;
void parseTODOS(LEInputStream& in, TODOS& _s);
class FibBase;
void parseFibBase(LEInputStream& in, FibBase& _s);
class FibRgW97;
void parseFibRgW97(LEInputStream& in, FibRgW97& _s);
class FibRgLw97;
void parseFibRgLw97(LEInputStream& in, FibRgLw97& _s);
class FibRgFcLcb97;
void parseFibRgFcLcb97(LEInputStream& in, FibRgFcLcb97& _s);
class FibRgFcLcb2000;
void parseFibRgFcLcb2000(LEInputStream& in, FibRgFcLcb2000& _s);
class FibRgFcLcb2002;
void parseFibRgFcLcb2002(LEInputStream& in, FibRgFcLcb2002& _s);
class LPStshi;
void parseLPStshi(LEInputStream& in, LPStshi& _s);
class LPStd;
void parseLPStd(LEInputStream& in, LPStd& _s);
class PlcfSed;
void parsePlcfSed(LEInputStream& in, PlcfSed& _s);
class Sed;
void parseSed(LEInputStream& in, Sed& _s);
class Plcfhdd;
void parsePlcfhdd(LEInputStream& in, Plcfhdd& _s);
class PlcBteChpx;
void parsePlcBteChpx(LEInputStream& in, PlcBteChpx& _s);
class PlcfBtePapx;
void parsePlcfBtePapx(LEInputStream& in, PlcfBtePapx& _s);
class Tcg;
void parseTcg(LEInputStream& in, Tcg& _s);
class PrcData;
void parsePrcData(LEInputStream& in, PrcData& _s);
class Sprm;
void parseSprm(LEInputStream& in, Sprm& _s);
class Pcdt;
void parsePcdt(LEInputStream& in, Pcdt& _s);
class FCompressed;
void parseFCompressed(LEInputStream& in, FCompressed& _s);
class Prm0;
void parsePrm0(LEInputStream& in, Prm0& _s);
class Prm1;
void parsePrm1(LEInputStream& in, Prm1& _s);
class SttbfFfn;
void parseSttbfFfn(LEInputStream& in, SttbfFfn& _s);
class SttbfFfnEntry;
void parseSttbfFfnEntry(LEInputStream& in, SttbfFfnEntry& _s);
class PicturesStream;
void parsePicturesStream(LEInputStream& in, PicturesStream& _s);
class OfficeArtMetafileHeader;
void parseOfficeArtMetafileHeader(LEInputStream& in, OfficeArtMetafileHeader& _s);
class NormalViewSetInfoAtom;
void parseNormalViewSetInfoAtom(LEInputStream& in, NormalViewSetInfoAtom& _s);
class MasterPersistAtom;
void parseMasterPersistAtom(LEInputStream& in, MasterPersistAtom& _s);
class SlidePersistAtom;
void parseSlidePersistAtom(LEInputStream& in, SlidePersistAtom& _s);
class TextRuler;
void parseTextRuler(LEInputStream& in, TextRuler& _s);
class TextPFException;
void parseTextPFException(LEInputStream& in, TextPFException& _s);
class TextCFException;
void parseTextCFException(LEInputStream& in, TextCFException& _s);
class KinsokuContainer;
void parseKinsokuContainer(LEInputStream& in, KinsokuContainer& _s);
class TextMasterStyleLevel;
void parseTextMasterStyleLevel(LEInputStream& in, TextMasterStyleLevel& _s);
class DocumentAtom;
void parseDocumentAtom(LEInputStream& in, DocumentAtom& _s);
class ExObjListContainer;
void parseExObjListContainer(LEInputStream& in, ExObjListContainer& _s);
class ExOleLinkContainer;
void parseExOleLinkContainer(LEInputStream& in, ExOleLinkContainer& _s);
class ExOleEmbedContainer;
void parseExOleEmbedContainer(LEInputStream& in, ExOleEmbedContainer& _s);
class OfficeArtFDGGBlock;
void parseOfficeArtFDGGBlock(LEInputStream& in, OfficeArtFDGGBlock& _s);
class OfficeArtClientAnchor;
void parseOfficeArtClientAnchor(LEInputStream& in, OfficeArtClientAnchor& _s);
class OfficeArtClientData;
void parseOfficeArtClientData(LEInputStream& in, OfficeArtClientData& _s);
class OfficeArtFOPTE;
void parseOfficeArtFOPTE(LEInputStream& in, OfficeArtFOPTE& _s);
class Fib;
void parseFib(LEInputStream& in, Fib& _s);
class STSH;
void parseSTSH(LEInputStream& in, STSH& _s);
class Clx;
void parseClx(LEInputStream& in, Clx& _s);
class Pcr;
void parsePcr(LEInputStream& in, Pcr& _s);
class Prm;
void parsePrm(LEInputStream& in, Prm& _s);
class OfficeArtBlipEMF;
void parseOfficeArtBlipEMF(LEInputStream& in, OfficeArtBlipEMF& _s);
class OfficeArtBlipWMF;
void parseOfficeArtBlipWMF(LEInputStream& in, OfficeArtBlipWMF& _s);
class OfficeArtBlipPICT;
void parseOfficeArtBlipPICT(LEInputStream& in, OfficeArtBlipPICT& _s);
class OfficeArtBlip;
void parseOfficeArtBlip(LEInputStream& in, OfficeArtBlip& _s);
class NormalViewSetInfoContainer;
void parseNormalViewSetInfoContainer(LEInputStream& in, NormalViewSetInfoContainer& _s);
class SlideListWithTextSubContainerOrAtom;
void parseSlideListWithTextSubContainerOrAtom(LEInputStream& in, SlideListWithTextSubContainerOrAtom& _s);
class TextCFExceptionAtom;
void parseTextCFExceptionAtom(LEInputStream& in, TextCFExceptionAtom& _s);
class DefaultRulerAtom;
void parseDefaultRulerAtom(LEInputStream& in, DefaultRulerAtom& _s);
class TextPFExceptionAtom;
void parseTextPFExceptionAtom(LEInputStream& in, TextPFExceptionAtom& _s);
class TextMasterStyleAtom;
void parseTextMasterStyleAtom(LEInputStream& in, TextMasterStyleAtom& _s);
class ExObjListSubContainer;
void parseExObjListSubContainer(LEInputStream& in, ExObjListSubContainer& _s);
class OfficeArtDggContainer;
void parseOfficeArtDggContainer(LEInputStream& in, OfficeArtDggContainer& _s);
class OfficeArtSpContainer;
void parseOfficeArtSpContainer(LEInputStream& in, OfficeArtSpContainer& _s);
class WordDocument;
void parseWordDocument(LEInputStream& in, WordDocument& _s);
class Table;
void parseTable(LEInputStream& in, Table& _s);
class Pcd;
void parsePcd(LEInputStream& in, Pcd& _s);
class OfficeArtFBSE;
void parseOfficeArtFBSE(LEInputStream& in, OfficeArtFBSE& _s);
class OfficeArtBStoreContainerFileBlock;
void parseOfficeArtBStoreContainerFileBlock(LEInputStream& in, OfficeArtBStoreContainerFileBlock& _s);
class DocumentTextInfoContainer;
void parseDocumentTextInfoContainer(LEInputStream& in, DocumentTextInfoContainer& _s);
class DrawingGroupContainer;
void parseDrawingGroupContainer(LEInputStream& in, DrawingGroupContainer& _s);
class OfficeArtDgContainer;
void parseOfficeArtDgContainer(LEInputStream& in, OfficeArtDgContainer& _s);
class OfficeArtSpgrContainerFileBlock;
void parseOfficeArtSpgrContainerFileBlock(LEInputStream& in, OfficeArtSpgrContainerFileBlock& _s);
class DocumentContainer;
void parseDocumentContainer(LEInputStream& in, DocumentContainer& _s);
class DrawingContainer;
void parseDrawingContainer(LEInputStream& in, DrawingContainer& _s);
class SlideContainer;
void parseSlideContainer(LEInputStream& in, SlideContainer& _s);
class MasterOrSlideContainer;
void parseMasterOrSlideContainer(LEInputStream& in, MasterOrSlideContainer& _s);
class PowerPointStruct;
void parsePowerPointStruct(LEInputStream& in, PowerPointStruct& _s);
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
class Byte {
public:
    quint8 b;
    QString toString() {
        QString _s = "Byte:";
        _s = _s + "b: " + QString::number(b) + "(" + QString::number(b,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class CurrentUserStream {
public:
    CurrentUserAtom anon1;
    QList<Byte> trailing;
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
        _s = _s + "anon1: " + "[array of anon1]" + ", ";
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
        _s = _s + "anon: " + "[array of anon]" + ", ";
        return _s;
    }
};
class SlideHeadersFootersContainer {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "SlideHeadersFootersContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class NotesHeadersFootersContainer {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "NotesHeadersFootersContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class PerSlideHeadersFootersContainer {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "PerSlideHeadersFootersContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
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
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
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
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
};
class NotesListWithTextContainer {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "NotesListWithTextContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
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
class MasterTextPropAtom {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "MasterTextPropAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class StyleTextPropAtom {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "StyleTextPropAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
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
        _s = _s + "fHasBullet: " + QString::number(fHasBullet) + ", ";
        _s = _s + "fBulletHasFont: " + QString::number(fBulletHasFont) + ", ";
        _s = _s + "fBulletHasColor: " + QString::number(fBulletHasColor) + ", ";
        _s = _s + "fBulletHasSize: " + QString::number(fBulletHasSize) + ", ";
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
        _s = _s + "hasBullet: " + QString::number(hasBullet) + ", ";
        _s = _s + "bulletHasFont: " + QString::number(bulletHasFont) + ", ";
        _s = _s + "bulletHasColor: " + QString::number(bulletHasColor) + ", ";
        _s = _s + "bulletHasSize: " + QString::number(bulletHasSize) + ", ";
        _s = _s + "bulletFont: " + QString::number(bulletFont) + ", ";
        _s = _s + "bulletColor: " + QString::number(bulletColor) + ", ";
        _s = _s + "bulletSize: " + QString::number(bulletSize) + ", ";
        _s = _s + "bulletChar: " + QString::number(bulletChar) + ", ";
        _s = _s + "leftMargin: " + QString::number(leftMargin) + ", ";
        _s = _s + "unused: " + QString::number(unused) + ", ";
        _s = _s + "indent: " + QString::number(indent) + ", ";
        _s = _s + "align: " + QString::number(align) + ", ";
        _s = _s + "lineSpacing: " + QString::number(lineSpacing) + ", ";
        _s = _s + "spaceBefore: " + QString::number(spaceBefore) + ", ";
        _s = _s + "spaceAfter: " + QString::number(spaceAfter) + ", ";
        _s = _s + "defaultTabSize: " + QString::number(defaultTabSize) + ", ";
        _s = _s + "fontAlign: " + QString::number(fontAlign) + ", ";
        _s = _s + "charWrap: " + QString::number(charWrap) + ", ";
        _s = _s + "wordWrap: " + QString::number(wordWrap) + ", ";
        _s = _s + "overflow: " + QString::number(overflow) + ", ";
        _s = _s + "tabStops: " + QString::number(tabStops) + ", ";
        _s = _s + "textDirection: " + QString::number(textDirection) + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + ", ";
        _s = _s + "bulletBlip: " + QString::number(bulletBlip) + ", ";
        _s = _s + "bulletScheme: " + QString::number(bulletScheme) + ", ";
        _s = _s + "bulletHasScheme: " + QString::number(bulletHasScheme) + ", ";
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
        _s = _s + "bold: " + QString::number(bold) + ", ";
        _s = _s + "italic: " + QString::number(italic) + ", ";
        _s = _s + "underline: " + QString::number(underline) + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + ", ";
        _s = _s + "shadow: " + QString::number(shadow) + ", ";
        _s = _s + "fehint: " + QString::number(fehint) + ", ";
        _s = _s + "unused2: " + QString::number(unused2) + ", ";
        _s = _s + "kumi: " + QString::number(kumi) + ", ";
        _s = _s + "unused3: " + QString::number(unused3) + ", ";
        _s = _s + "emboss: " + QString::number(emboss) + ", ";
        _s = _s + "fHasStyle: " + QString::number(fHasStyle) + "(" + QString::number(fHasStyle,16).toUpper() + ")" + ", ";
        _s = _s + "unused4: " + QString::number(unused4) + "(" + QString::number(unused4,16).toUpper() + ")" + ", ";
        _s = _s + "typeface: " + QString::number(typeface) + ", ";
        _s = _s + "size: " + QString::number(size) + ", ";
        _s = _s + "color: " + QString::number(color) + ", ";
        _s = _s + "position: " + QString::number(position) + ", ";
        _s = _s + "pp10ext: " + QString::number(pp10ext) + ", ";
        _s = _s + "oldEATypeface: " + QString::number(oldEATypeface) + ", ";
        _s = _s + "ansiTypeface: " + QString::number(ansiTypeface) + ", ";
        _s = _s + "symbolTypeface: " + QString::number(symbolTypeface) + ", ";
        _s = _s + "newEATypeface: " + QString::number(newEATypeface) + ", ";
        _s = _s + "csTypeface: " + QString::number(csTypeface) + ", ";
        _s = _s + "pp11ext: " + QString::number(pp11ext) + ", ";
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
        _s = _s + "bold: " + QString::number(bold) + ", ";
        _s = _s + "italic: " + QString::number(italic) + ", ";
        _s = _s + "underline: " + QString::number(underline) + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + ", ";
        _s = _s + "shadow: " + QString::number(shadow) + ", ";
        _s = _s + "fehint: " + QString::number(fehint) + ", ";
        _s = _s + "unused2: " + QString::number(unused2) + ", ";
        _s = _s + "kumi: " + QString::number(kumi) + ", ";
        _s = _s + "unused3: " + QString::number(unused3) + ", ";
        _s = _s + "emboss: " + QString::number(emboss) + ", ";
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
class FontEntityAtom {
public:
    RecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "FontEntityAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
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
        _s = _s + "rgPersistDirEntry: " + "[array of rgPersistDirEntry]" + ", ";
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
class NotesContainer {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "NotesContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class HandoutContainer {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "HandoutContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class ExControlStg {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "ExControlStg:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class ExOleObjStg {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "ExOleObjStg:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class UserEditAtom {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "UserEditAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
        return _s;
    }
};
class VbaProjectStg {
public:
    RecordHeader rh;
    QByteArray TODO;
    QString toString() {
        QString _s = "VbaProjectStg:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "TODO: " + "[array of TODO]" + ", ";
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
        _s = _s + "fManualAdvance: " + QString::number(fManualAdvance) + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + ", ";
        _s = _s + "fHidden: " + QString::number(fHidden) + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + ", ";
        _s = _s + "fSound: " + QString::number(fSound) + ", ";
        _s = _s + "reserved3: " + QString::number(reserved3) + ", ";
        _s = _s + "fLoopSound: " + QString::number(fLoopSound) + ", ";
        _s = _s + "reserved4: " + QString::number(reserved4) + ", ";
        _s = _s + "fStopSound: " + QString::number(fStopSound) + ", ";
        _s = _s + "freserved5: " + QString::number(freserved5) + ", ";
        _s = _s + "fAutoAdvance: " + QString::number(fAutoAdvance) + ", ";
        _s = _s + "reserved6: " + QString::number(reserved6) + ", ";
        _s = _s + "fCursorVisible: " + QString::number(fCursorVisible) + ", ";
        _s = _s + "reserved7: " + QString::number(reserved7) + "(" + QString::number(reserved7,16).toUpper() + ")" + ", ";
        _s = _s + "speed: " + QString::number(speed) + "(" + QString::number(speed,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + "[array of unused]" + ", ";
        return _s;
    }
};
class SlideShowDocInfoAtom {
public:
    RecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "SlideShowDocInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
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
class OfficeArtBStoreContainer {
public:
    OfficeArtRecordHeader rh;
    QList<OfficeArtBStoreContainerFileBlock> rgfb;
    QString toString() {
        QString _s = "OfficeArtBStoreContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfb: " + "[array of rgfb]" + ", ";
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
        _s = _s + "rgfb: " + "[array of rgfb]" + ", ";
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
        _s = _s + "fGroup: " + QString::number(fGroup) + ", ";
        _s = _s + "fChild: " + QString::number(fChild) + ", ";
        _s = _s + "fPatriarch: " + QString::number(fPatriarch) + ", ";
        _s = _s + "fDeleted: " + QString::number(fDeleted) + ", ";
        _s = _s + "fOleShape: " + QString::number(fOleShape) + ", ";
        _s = _s + "fHaveMaster: " + QString::number(fHaveMaster) + ", ";
        _s = _s + "fFlipH: " + QString::number(fFlipH) + ", ";
        _s = _s + "fFlipV: " + QString::number(fFlipV) + ", ";
        _s = _s + "fConnector: " + QString::number(fConnector) + ", ";
        _s = _s + "fHaveAnchor: " + QString::number(fHaveAnchor) + ", ";
        _s = _s + "fBackground: " + QString::number(fBackground) + ", ";
        _s = _s + "fHaveSpt: " + QString::number(fHaveSpt) + ", ";
        _s = _s + "unused1: " + QString::number(unused1) + "(" + QString::number(unused1,16).toUpper() + ")" + ", ";
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
        _s = _s + "reserved1: " + QString::number(reserved1) + ", ";
        _s = _s + "fLast: " + QString::number(fLast) + ", ";
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
    QVector<OfficeArtFOPTE> fopt;
    QString toString() {
        QString _s = "OfficeArtTertiaryFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
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
class ShapeFlagsAtom {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "ShapeFlagsAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class ShapeFlags10Atom {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "ShapeFlags10Atom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class ExObjRefAtom {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "ExObjRefAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class AnimationInfoContainer {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "AnimationInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class MouseClickInteractiveInfoContainer {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "MouseClickInteractiveInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class MouseOverInteractiveInfoContainer {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "MouseOverInteractiveInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class PlaceholderAtom {
public:
    OfficeArtRecordHeader rh;
    qint32 position;
    quint8 placementId;
    quint8 size;
    quint16 unused;
    QString toString() {
        QString _s = "PlaceholderAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "placementId: " + QString::number(placementId) + "(" + QString::number(placementId,16).toUpper() + ")" + ", ";
        _s = _s + "size: " + QString::number(size) + "(" + QString::number(size,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class RecolorInfoAtom {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "RecolorInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class OutlineTextRefAtom {
public:
    OfficeArtRecordHeader rh;
    qint32 index;
    QString toString() {
        QString _s = "OutlineTextRefAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "index: " + QString::number(index) + "(" + QString::number(index,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class ShapeClientRoundtripDataSubcontainerOrAtom {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "ShapeClientRoundtripDataSubcontainerOrAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class OfficeArtClientTextBox {
public:
    OfficeArtRecordHeader rh;
    QList<TextClientDataSubContainerOrAtom> rgChildRec;
    QString toString() {
        QString _s = "OfficeArtClientTextBox:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
};
class TextClientDataSubContainerOrAtom {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
    QString toString() {
        QString _s = "TextClientDataSubContainerOrAtom:";
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
class OfficeArtFOPTEOPID {
public:
    quint16 opid;
    bool fBid;
    bool fComplex;
    QString toString() {
        QString _s = "OfficeArtFOPTEOPID:";
        _s = _s + "opid: " + QString::number(opid) + "(" + QString::number(opid,16).toUpper() + ")" + ", ";
        _s = _s + "fBid: " + QString::number(fBid) + ", ";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
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
        _s = _s + "fSchemeIndex: " + QString::number(fSchemeIndex) + ", ";
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
        _s = _s + "anon: " + "[array of anon]" + ", ";
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
    quint8 cQuickSaves;
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
        _s = _s + "fDot: " + QString::number(fDot) + ", ";
        _s = _s + "fGlsy: " + QString::number(fGlsy) + ", ";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
        _s = _s + "fHasPic: " + QString::number(fHasPic) + ", ";
        _s = _s + "cQuickSaves: " + QString::number(cQuickSaves) + "(" + QString::number(cQuickSaves,16).toUpper() + ")" + ", ";
        _s = _s + "fEncrypted: " + QString::number(fEncrypted) + ", ";
        _s = _s + "fWhichTblStm: " + QString::number(fWhichTblStm) + ", ";
        _s = _s + "fReadOnlyRecommended: " + QString::number(fReadOnlyRecommended) + ", ";
        _s = _s + "fWriteReservation: " + QString::number(fWriteReservation) + ", ";
        _s = _s + "fExtChar: " + QString::number(fExtChar) + ", ";
        _s = _s + "fLoadOverride: " + QString::number(fLoadOverride) + ", ";
        _s = _s + "fFarEast: " + QString::number(fFarEast) + ", ";
        _s = _s + "fObfuscated: " + QString::number(fObfuscated) + ", ";
        _s = _s + "nFibBack: " + QString::number(nFibBack) + "(" + QString::number(nFibBack,16).toUpper() + ")" + ", ";
        _s = _s + "IKey: " + QString::number(IKey) + "(" + QString::number(IKey,16).toUpper() + ")" + ", ";
        _s = _s + "envr: " + QString::number(envr) + "(" + QString::number(envr,16).toUpper() + ")" + ", ";
        _s = _s + "fMac: " + QString::number(fMac) + ", ";
        _s = _s + "fEmptySpecial: " + QString::number(fEmptySpecial) + ", ";
        _s = _s + "fLoadOverridePage: " + QString::number(fLoadOverridePage) + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + ", ";
        _s = _s + "reserved2: " + QString::number(reserved2) + ", ";
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
class FibRgFcLcb97 {
public:
    quint32 fcStshfOrig;
    quint32 lcbStshfOrig;
    quint32 fcStshf;
    quint32 lcbStshf;
    quint32 fcPlcffndRef;
    quint32 lcbPlcffndRef;
    quint32 fcPlcffndTxt;
    quint32 lcbPlcffndTxt;
    quint32 fcPlcfandRef;
    quint32 lcbPlcfandRef;
    quint32 fcPlcfandTxt;
    quint32 lcbPlcfandTxt;
    quint32 fcPlcfSed;
    quint32 lcbPlcfSed;
    quint32 fcPlcPad;
    quint32 lcbPlcPad;
    quint32 fcPlcfPhe;
    quint32 lcbPlcfPhe;
    quint32 fcSttbfGlsy;
    quint32 lcbSttbfGlsy;
    quint32 fcPlcfGlsy;
    quint32 lcbPlcfGlsy;
    quint32 fcPlcfHdd;
    quint32 lcbPlcfHdd;
    quint32 fcPlcfBteChpx;
    quint32 lcbPlcfBteChpx;
    quint32 fcPlcfBtePapx;
    quint32 lcbPlcfBtePapx;
    quint32 fcPlcfSea;
    quint32 lcbPlcfSea;
    quint32 fcSttbfFfn;
    quint32 lcbSttbfFfn;
    quint32 fcPlcfFldMom;
    quint32 lcbPlcfFldMom;
    quint32 fcPlcfFldHdr;
    quint32 lcbPlcfFldHdr;
    quint32 fcPlcfFldFtn;
    quint32 lcbPlcfFldFtn;
    quint32 fcPlcfFldAtn;
    quint32 lcbPlcfFldAtn;
    quint32 fcPlcfFldMcr;
    quint32 lcbPlcfFldMcr;
    quint32 fcSttbfBkmk;
    quint32 lcbSttbfBkmk;
    quint32 fcPlcfBkf;
    quint32 lcbPlcfBkf;
    quint32 fcPlcfBkl;
    quint32 lcbPlcfBkl;
    quint32 fcCmds;
    quint32 lcbCmds;
    quint32 fcUnused1;
    quint32 lcbUnused1;
    quint32 fcSttbfMcr;
    quint32 lcbSttbfMcr;
    quint32 fcPrDrvr;
    quint32 lcbPrDrvr;
    quint32 fcPrEnvPort;
    quint32 lcbPrEnvPort;
    quint32 fcPrEnvLand;
    quint32 lcbPrEnvLand;
    quint32 fcWss;
    quint32 lcbWss;
    quint32 fcDop;
    quint32 lcbDop;
    quint32 fcSttbfAssoc;
    quint32 lcbSttbfAssoc;
    quint32 fcClx;
    quint32 lcbClx;
    quint32 fcPlcfPgdFtn;
    quint32 lcbPlcfPgdFtn;
    quint32 fcAutosaveSource;
    quint32 lcbAutosaveSource;
    quint32 fcGrpXstAtnOwners;
    quint32 lcbGrpXstAtnOwners;
    quint32 fcSttbfAtnBkmk;
    quint32 lcbSttbfAtnBkmk;
    quint32 fcUnused2;
    quint32 lcbUnused2;
    quint32 fcUnused3;
    quint32 lcbUnused3;
    quint32 fcPlcSpaMom;
    quint32 lcbPlcSpaMom;
    quint32 fcPlcSpaHdr;
    quint32 lcbPlcSpaHdr;
    quint32 fcPlcfAtnBkf;
    quint32 lcbPlcfAtnBkf;
    quint32 fcPlcfAtnBkl;
    quint32 lcbPlcfAtnBkl;
    quint32 fcPms;
    quint32 lcbPms;
    quint32 fcFormFldSttbs;
    quint32 lcbFormFldSttbs;
    quint32 fcPlcfendRef;
    quint32 lcbPlcfendRef;
    quint32 fcPlcfendTxt;
    quint32 lcbPlcfendTxt;
    quint32 fcPlcfFldEdn;
    quint32 lcbPlcfFldEdn;
    quint32 fcUnused4;
    quint32 lcbUnused4;
    quint32 fcDggInfo;
    quint32 lcbDggInfo;
    quint32 fcSttbfRMark;
    quint32 lcbSttbfRMark;
    quint32 fcSttbfCaption;
    quint32 lcbSttbfCaption;
    quint32 fcSttbfAutoCaption;
    quint32 lcbSttbfAutoCaption;
    quint32 fcPlcfWkb;
    quint32 lcbPlcfWkb;
    quint32 fcPlcfSpl;
    quint32 lcbPlcfSpl;
    quint32 fcPlcftxbxTxt;
    quint32 lcbPlcftxbxTxt;
    quint32 fcPlcfFldTxbx;
    quint32 lcbPlcfFldTxbx;
    quint32 fcPlcfHdrtxbxTxt;
    quint32 lcbPlcfHdrtxbxTxt;
    quint32 fcPlcffldHdrTxbx;
    quint32 lcbPlcffldHdrTxbx;
    quint32 fcStwUser;
    quint32 lcbStwUser;
    quint32 fcSttbTtmbd;
    quint32 lcbSttbTtmbd;
    quint32 fcCookieData;
    quint32 lcbCookieData;
    quint32 fcPgdMotherOldOld;
    quint32 lcbPgdMotherOldOld;
    quint32 fcBkdMotherOldOld;
    quint32 lcbBkdMotherOldOld;
    quint32 fcPgdFtnOldOld;
    quint32 lcbPgdFtnOldOld;
    quint32 fcBkdFtnOldOld;
    quint32 lcbBkdFtnOldOld;
    quint32 fcPgdEdnOldOld;
    quint32 lcbPgdEdnOldOld;
    quint32 fcBkdEdnOldOld;
    quint32 lcbBkdEdnOldOld;
    quint32 fcSttbfIntlFld;
    quint32 lcbSttbfIntlFld;
    quint32 fcRouteSlip;
    quint32 lcbRouteSlip;
    quint32 fcSttbSavedBy;
    quint32 lcbSttbSavedBy;
    quint32 fcSttbFnm;
    quint32 lcbSttbFnm;
    quint32 fcPlfLst;
    quint32 lcbPlfLst;
    quint32 fcPlfLfo;
    quint32 lcbPlfLfo;
    quint32 fcPlcfTxbxBkd;
    quint32 lcbPlcfTxbxBkd;
    quint32 fcPlcfTxbxHdrBkd;
    quint32 lcbPlcfTxbxHdrBkd;
    quint32 fcDocUndoWord9;
    quint32 lcbDocUndoWord9;
    quint32 fcRgbUse;
    quint32 lcbRgbUse;
    quint32 fcUsp;
    quint32 lcbUsp;
    quint32 fcUskf;
    quint32 lcbUskf;
    quint32 fcPlcupcRgbUse;
    quint32 lcbPlcupcRgbUse;
    quint32 fcPlcupcUsp;
    quint32 lcbPlcupcUsp;
    quint32 fcSttbGlsyStyle;
    quint32 lcbSttbGlsyStyle;
    quint32 fcPlgosl;
    quint32 lcbPlgosl;
    quint32 fcPlcocx;
    quint32 lcbPlcocx;
    quint32 fcPlcfBteLvc;
    quint32 lcbPlcfBteLvc;
    quint32 dwLowDateTime;
    quint32 dwHighDateTime;
    quint32 fcPlcfLvcPre10;
    quint32 lcbPlcfLvcPre10;
    quint32 fcPlcfAsumy;
    quint32 lcbPlcfAsumy;
    quint32 fcPlcfGram;
    quint32 lcbPlcfGram;
    quint32 fcSttbListNames;
    quint32 lcbSttbListNames;
    quint32 fcSttbfUssr;
    quint32 lcbSttbfUssr;
    QString toString() {
        QString _s = "FibRgFcLcb97:";
        _s = _s + "fcStshfOrig: " + QString::number(fcStshfOrig) + "(" + QString::number(fcStshfOrig,16).toUpper() + ")" + ", ";
        _s = _s + "lcbStshfOrig: " + QString::number(lcbStshfOrig) + "(" + QString::number(lcbStshfOrig,16).toUpper() + ")" + ", ";
        _s = _s + "fcStshf: " + QString::number(fcStshf) + "(" + QString::number(fcStshf,16).toUpper() + ")" + ", ";
        _s = _s + "lcbStshf: " + QString::number(lcbStshf) + "(" + QString::number(lcbStshf,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcffndRef: " + QString::number(fcPlcffndRef) + "(" + QString::number(fcPlcffndRef,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcffndRef: " + QString::number(lcbPlcffndRef) + "(" + QString::number(lcbPlcffndRef,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcffndTxt: " + QString::number(fcPlcffndTxt) + "(" + QString::number(fcPlcffndTxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcffndTxt: " + QString::number(lcbPlcffndTxt) + "(" + QString::number(lcbPlcffndTxt,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfandRef: " + QString::number(fcPlcfandRef) + "(" + QString::number(fcPlcfandRef,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfandRef: " + QString::number(lcbPlcfandRef) + "(" + QString::number(lcbPlcfandRef,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfandTxt: " + QString::number(fcPlcfandTxt) + "(" + QString::number(fcPlcfandTxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfandTxt: " + QString::number(lcbPlcfandTxt) + "(" + QString::number(lcbPlcfandTxt,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfSed: " + QString::number(fcPlcfSed) + "(" + QString::number(fcPlcfSed,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfSed: " + QString::number(lcbPlcfSed) + "(" + QString::number(lcbPlcfSed,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcPad: " + QString::number(fcPlcPad) + "(" + QString::number(fcPlcPad,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcPad: " + QString::number(lcbPlcPad) + "(" + QString::number(lcbPlcPad,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfPhe: " + QString::number(fcPlcfPhe) + "(" + QString::number(fcPlcfPhe,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfPhe: " + QString::number(lcbPlcfPhe) + "(" + QString::number(lcbPlcfPhe,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfGlsy: " + QString::number(fcSttbfGlsy) + "(" + QString::number(fcSttbfGlsy,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfGlsy: " + QString::number(lcbSttbfGlsy) + "(" + QString::number(lcbSttbfGlsy,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfGlsy: " + QString::number(fcPlcfGlsy) + "(" + QString::number(fcPlcfGlsy,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfGlsy: " + QString::number(lcbPlcfGlsy) + "(" + QString::number(lcbPlcfGlsy,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfHdd: " + QString::number(fcPlcfHdd) + "(" + QString::number(fcPlcfHdd,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfHdd: " + QString::number(lcbPlcfHdd) + "(" + QString::number(lcbPlcfHdd,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBteChpx: " + QString::number(fcPlcfBteChpx) + "(" + QString::number(fcPlcfBteChpx,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBteChpx: " + QString::number(lcbPlcfBteChpx) + "(" + QString::number(lcbPlcfBteChpx,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBtePapx: " + QString::number(fcPlcfBtePapx) + "(" + QString::number(fcPlcfBtePapx,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBtePapx: " + QString::number(lcbPlcfBtePapx) + "(" + QString::number(lcbPlcfBtePapx,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfSea: " + QString::number(fcPlcfSea) + "(" + QString::number(fcPlcfSea,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfSea: " + QString::number(lcbPlcfSea) + "(" + QString::number(lcbPlcfSea,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfFfn: " + QString::number(fcSttbfFfn) + "(" + QString::number(fcSttbfFfn,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfFfn: " + QString::number(lcbSttbfFfn) + "(" + QString::number(lcbSttbfFfn,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldMom: " + QString::number(fcPlcfFldMom) + "(" + QString::number(fcPlcfFldMom,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldMom: " + QString::number(lcbPlcfFldMom) + "(" + QString::number(lcbPlcfFldMom,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldHdr: " + QString::number(fcPlcfFldHdr) + "(" + QString::number(fcPlcfFldHdr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldHdr: " + QString::number(lcbPlcfFldHdr) + "(" + QString::number(lcbPlcfFldHdr,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldFtn: " + QString::number(fcPlcfFldFtn) + "(" + QString::number(fcPlcfFldFtn,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldFtn: " + QString::number(lcbPlcfFldFtn) + "(" + QString::number(lcbPlcfFldFtn,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldAtn: " + QString::number(fcPlcfFldAtn) + "(" + QString::number(fcPlcfFldAtn,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldAtn: " + QString::number(lcbPlcfFldAtn) + "(" + QString::number(lcbPlcfFldAtn,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldMcr: " + QString::number(fcPlcfFldMcr) + "(" + QString::number(fcPlcfFldMcr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldMcr: " + QString::number(lcbPlcfFldMcr) + "(" + QString::number(lcbPlcfFldMcr,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfBkmk: " + QString::number(fcSttbfBkmk) + "(" + QString::number(fcSttbfBkmk,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfBkmk: " + QString::number(lcbSttbfBkmk) + "(" + QString::number(lcbSttbfBkmk,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBkf: " + QString::number(fcPlcfBkf) + "(" + QString::number(fcPlcfBkf,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBkf: " + QString::number(lcbPlcfBkf) + "(" + QString::number(lcbPlcfBkf,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBkl: " + QString::number(fcPlcfBkl) + "(" + QString::number(fcPlcfBkl,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBkl: " + QString::number(lcbPlcfBkl) + "(" + QString::number(lcbPlcfBkl,16).toUpper() + ")" + ", ";
        _s = _s + "fcCmds: " + QString::number(fcCmds) + "(" + QString::number(fcCmds,16).toUpper() + ")" + ", ";
        _s = _s + "lcbCmds: " + QString::number(lcbCmds) + "(" + QString::number(lcbCmds,16).toUpper() + ")" + ", ";
        _s = _s + "fcUnused1: " + QString::number(fcUnused1) + "(" + QString::number(fcUnused1,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUnused1: " + QString::number(lcbUnused1) + "(" + QString::number(lcbUnused1,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfMcr: " + QString::number(fcSttbfMcr) + "(" + QString::number(fcSttbfMcr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfMcr: " + QString::number(lcbSttbfMcr) + "(" + QString::number(lcbSttbfMcr,16).toUpper() + ")" + ", ";
        _s = _s + "fcPrDrvr: " + QString::number(fcPrDrvr) + "(" + QString::number(fcPrDrvr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPrDrvr: " + QString::number(lcbPrDrvr) + "(" + QString::number(lcbPrDrvr,16).toUpper() + ")" + ", ";
        _s = _s + "fcPrEnvPort: " + QString::number(fcPrEnvPort) + "(" + QString::number(fcPrEnvPort,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPrEnvPort: " + QString::number(lcbPrEnvPort) + "(" + QString::number(lcbPrEnvPort,16).toUpper() + ")" + ", ";
        _s = _s + "fcPrEnvLand: " + QString::number(fcPrEnvLand) + "(" + QString::number(fcPrEnvLand,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPrEnvLand: " + QString::number(lcbPrEnvLand) + "(" + QString::number(lcbPrEnvLand,16).toUpper() + ")" + ", ";
        _s = _s + "fcWss: " + QString::number(fcWss) + "(" + QString::number(fcWss,16).toUpper() + ")" + ", ";
        _s = _s + "lcbWss: " + QString::number(lcbWss) + "(" + QString::number(lcbWss,16).toUpper() + ")" + ", ";
        _s = _s + "fcDop: " + QString::number(fcDop) + "(" + QString::number(fcDop,16).toUpper() + ")" + ", ";
        _s = _s + "lcbDop: " + QString::number(lcbDop) + "(" + QString::number(lcbDop,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfAssoc: " + QString::number(fcSttbfAssoc) + "(" + QString::number(fcSttbfAssoc,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfAssoc: " + QString::number(lcbSttbfAssoc) + "(" + QString::number(lcbSttbfAssoc,16).toUpper() + ")" + ", ";
        _s = _s + "fcClx: " + QString::number(fcClx) + "(" + QString::number(fcClx,16).toUpper() + ")" + ", ";
        _s = _s + "lcbClx: " + QString::number(lcbClx) + "(" + QString::number(lcbClx,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfPgdFtn: " + QString::number(fcPlcfPgdFtn) + "(" + QString::number(fcPlcfPgdFtn,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfPgdFtn: " + QString::number(lcbPlcfPgdFtn) + "(" + QString::number(lcbPlcfPgdFtn,16).toUpper() + ")" + ", ";
        _s = _s + "fcAutosaveSource: " + QString::number(fcAutosaveSource) + "(" + QString::number(fcAutosaveSource,16).toUpper() + ")" + ", ";
        _s = _s + "lcbAutosaveSource: " + QString::number(lcbAutosaveSource) + "(" + QString::number(lcbAutosaveSource,16).toUpper() + ")" + ", ";
        _s = _s + "fcGrpXstAtnOwners: " + QString::number(fcGrpXstAtnOwners) + "(" + QString::number(fcGrpXstAtnOwners,16).toUpper() + ")" + ", ";
        _s = _s + "lcbGrpXstAtnOwners: " + QString::number(lcbGrpXstAtnOwners) + "(" + QString::number(lcbGrpXstAtnOwners,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfAtnBkmk: " + QString::number(fcSttbfAtnBkmk) + "(" + QString::number(fcSttbfAtnBkmk,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfAtnBkmk: " + QString::number(lcbSttbfAtnBkmk) + "(" + QString::number(lcbSttbfAtnBkmk,16).toUpper() + ")" + ", ";
        _s = _s + "fcUnused2: " + QString::number(fcUnused2) + "(" + QString::number(fcUnused2,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUnused2: " + QString::number(lcbUnused2) + "(" + QString::number(lcbUnused2,16).toUpper() + ")" + ", ";
        _s = _s + "fcUnused3: " + QString::number(fcUnused3) + "(" + QString::number(fcUnused3,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUnused3: " + QString::number(lcbUnused3) + "(" + QString::number(lcbUnused3,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcSpaMom: " + QString::number(fcPlcSpaMom) + "(" + QString::number(fcPlcSpaMom,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcSpaMom: " + QString::number(lcbPlcSpaMom) + "(" + QString::number(lcbPlcSpaMom,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcSpaHdr: " + QString::number(fcPlcSpaHdr) + "(" + QString::number(fcPlcSpaHdr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcSpaHdr: " + QString::number(lcbPlcSpaHdr) + "(" + QString::number(lcbPlcSpaHdr,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfAtnBkf: " + QString::number(fcPlcfAtnBkf) + "(" + QString::number(fcPlcfAtnBkf,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfAtnBkf: " + QString::number(lcbPlcfAtnBkf) + "(" + QString::number(lcbPlcfAtnBkf,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfAtnBkl: " + QString::number(fcPlcfAtnBkl) + "(" + QString::number(fcPlcfAtnBkl,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfAtnBkl: " + QString::number(lcbPlcfAtnBkl) + "(" + QString::number(lcbPlcfAtnBkl,16).toUpper() + ")" + ", ";
        _s = _s + "fcPms: " + QString::number(fcPms) + "(" + QString::number(fcPms,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPms: " + QString::number(lcbPms) + "(" + QString::number(lcbPms,16).toUpper() + ")" + ", ";
        _s = _s + "fcFormFldSttbs: " + QString::number(fcFormFldSttbs) + "(" + QString::number(fcFormFldSttbs,16).toUpper() + ")" + ", ";
        _s = _s + "lcbFormFldSttbs: " + QString::number(lcbFormFldSttbs) + "(" + QString::number(lcbFormFldSttbs,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfendRef: " + QString::number(fcPlcfendRef) + "(" + QString::number(fcPlcfendRef,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfendRef: " + QString::number(lcbPlcfendRef) + "(" + QString::number(lcbPlcfendRef,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfendTxt: " + QString::number(fcPlcfendTxt) + "(" + QString::number(fcPlcfendTxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfendTxt: " + QString::number(lcbPlcfendTxt) + "(" + QString::number(lcbPlcfendTxt,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldEdn: " + QString::number(fcPlcfFldEdn) + "(" + QString::number(fcPlcfFldEdn,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldEdn: " + QString::number(lcbPlcfFldEdn) + "(" + QString::number(lcbPlcfFldEdn,16).toUpper() + ")" + ", ";
        _s = _s + "fcUnused4: " + QString::number(fcUnused4) + "(" + QString::number(fcUnused4,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUnused4: " + QString::number(lcbUnused4) + "(" + QString::number(lcbUnused4,16).toUpper() + ")" + ", ";
        _s = _s + "fcDggInfo: " + QString::number(fcDggInfo) + "(" + QString::number(fcDggInfo,16).toUpper() + ")" + ", ";
        _s = _s + "lcbDggInfo: " + QString::number(lcbDggInfo) + "(" + QString::number(lcbDggInfo,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfRMark: " + QString::number(fcSttbfRMark) + "(" + QString::number(fcSttbfRMark,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfRMark: " + QString::number(lcbSttbfRMark) + "(" + QString::number(lcbSttbfRMark,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfCaption: " + QString::number(fcSttbfCaption) + "(" + QString::number(fcSttbfCaption,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfCaption: " + QString::number(lcbSttbfCaption) + "(" + QString::number(lcbSttbfCaption,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfAutoCaption: " + QString::number(fcSttbfAutoCaption) + "(" + QString::number(fcSttbfAutoCaption,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfAutoCaption: " + QString::number(lcbSttbfAutoCaption) + "(" + QString::number(lcbSttbfAutoCaption,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfWkb: " + QString::number(fcPlcfWkb) + "(" + QString::number(fcPlcfWkb,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfWkb: " + QString::number(lcbPlcfWkb) + "(" + QString::number(lcbPlcfWkb,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfSpl: " + QString::number(fcPlcfSpl) + "(" + QString::number(fcPlcfSpl,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfSpl: " + QString::number(lcbPlcfSpl) + "(" + QString::number(lcbPlcfSpl,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcftxbxTxt: " + QString::number(fcPlcftxbxTxt) + "(" + QString::number(fcPlcftxbxTxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcftxbxTxt: " + QString::number(lcbPlcftxbxTxt) + "(" + QString::number(lcbPlcftxbxTxt,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfFldTxbx: " + QString::number(fcPlcfFldTxbx) + "(" + QString::number(fcPlcfFldTxbx,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfFldTxbx: " + QString::number(lcbPlcfFldTxbx) + "(" + QString::number(lcbPlcfFldTxbx,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfHdrtxbxTxt: " + QString::number(fcPlcfHdrtxbxTxt) + "(" + QString::number(fcPlcfHdrtxbxTxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfHdrtxbxTxt: " + QString::number(lcbPlcfHdrtxbxTxt) + "(" + QString::number(lcbPlcfHdrtxbxTxt,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcffldHdrTxbx: " + QString::number(fcPlcffldHdrTxbx) + "(" + QString::number(fcPlcffldHdrTxbx,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcffldHdrTxbx: " + QString::number(lcbPlcffldHdrTxbx) + "(" + QString::number(lcbPlcffldHdrTxbx,16).toUpper() + ")" + ", ";
        _s = _s + "fcStwUser: " + QString::number(fcStwUser) + "(" + QString::number(fcStwUser,16).toUpper() + ")" + ", ";
        _s = _s + "lcbStwUser: " + QString::number(lcbStwUser) + "(" + QString::number(lcbStwUser,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbTtmbd: " + QString::number(fcSttbTtmbd) + "(" + QString::number(fcSttbTtmbd,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbTtmbd: " + QString::number(lcbSttbTtmbd) + "(" + QString::number(lcbSttbTtmbd,16).toUpper() + ")" + ", ";
        _s = _s + "fcCookieData: " + QString::number(fcCookieData) + "(" + QString::number(fcCookieData,16).toUpper() + ")" + ", ";
        _s = _s + "lcbCookieData: " + QString::number(lcbCookieData) + "(" + QString::number(lcbCookieData,16).toUpper() + ")" + ", ";
        _s = _s + "fcPgdMotherOldOld: " + QString::number(fcPgdMotherOldOld) + "(" + QString::number(fcPgdMotherOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPgdMotherOldOld: " + QString::number(lcbPgdMotherOldOld) + "(" + QString::number(lcbPgdMotherOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcBkdMotherOldOld: " + QString::number(fcBkdMotherOldOld) + "(" + QString::number(fcBkdMotherOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbBkdMotherOldOld: " + QString::number(lcbBkdMotherOldOld) + "(" + QString::number(lcbBkdMotherOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcPgdFtnOldOld: " + QString::number(fcPgdFtnOldOld) + "(" + QString::number(fcPgdFtnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPgdFtnOldOld: " + QString::number(lcbPgdFtnOldOld) + "(" + QString::number(lcbPgdFtnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcBkdFtnOldOld: " + QString::number(fcBkdFtnOldOld) + "(" + QString::number(fcBkdFtnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbBkdFtnOldOld: " + QString::number(lcbBkdFtnOldOld) + "(" + QString::number(lcbBkdFtnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcPgdEdnOldOld: " + QString::number(fcPgdEdnOldOld) + "(" + QString::number(fcPgdEdnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPgdEdnOldOld: " + QString::number(lcbPgdEdnOldOld) + "(" + QString::number(lcbPgdEdnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcBkdEdnOldOld: " + QString::number(fcBkdEdnOldOld) + "(" + QString::number(fcBkdEdnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbBkdEdnOldOld: " + QString::number(lcbBkdEdnOldOld) + "(" + QString::number(lcbBkdEdnOldOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfIntlFld: " + QString::number(fcSttbfIntlFld) + "(" + QString::number(fcSttbfIntlFld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfIntlFld: " + QString::number(lcbSttbfIntlFld) + "(" + QString::number(lcbSttbfIntlFld,16).toUpper() + ")" + ", ";
        _s = _s + "fcRouteSlip: " + QString::number(fcRouteSlip) + "(" + QString::number(fcRouteSlip,16).toUpper() + ")" + ", ";
        _s = _s + "lcbRouteSlip: " + QString::number(lcbRouteSlip) + "(" + QString::number(lcbRouteSlip,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbSavedBy: " + QString::number(fcSttbSavedBy) + "(" + QString::number(fcSttbSavedBy,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbSavedBy: " + QString::number(lcbSttbSavedBy) + "(" + QString::number(lcbSttbSavedBy,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbFnm: " + QString::number(fcSttbFnm) + "(" + QString::number(fcSttbFnm,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbFnm: " + QString::number(lcbSttbFnm) + "(" + QString::number(lcbSttbFnm,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlfLst: " + QString::number(fcPlfLst) + "(" + QString::number(fcPlfLst,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlfLst: " + QString::number(lcbPlfLst) + "(" + QString::number(lcbPlfLst,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlfLfo: " + QString::number(fcPlfLfo) + "(" + QString::number(fcPlfLfo,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlfLfo: " + QString::number(lcbPlfLfo) + "(" + QString::number(lcbPlfLfo,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfTxbxBkd: " + QString::number(fcPlcfTxbxBkd) + "(" + QString::number(fcPlcfTxbxBkd,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfTxbxBkd: " + QString::number(lcbPlcfTxbxBkd) + "(" + QString::number(lcbPlcfTxbxBkd,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfTxbxHdrBkd: " + QString::number(fcPlcfTxbxHdrBkd) + "(" + QString::number(fcPlcfTxbxHdrBkd,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfTxbxHdrBkd: " + QString::number(lcbPlcfTxbxHdrBkd) + "(" + QString::number(lcbPlcfTxbxHdrBkd,16).toUpper() + ")" + ", ";
        _s = _s + "fcDocUndoWord9: " + QString::number(fcDocUndoWord9) + "(" + QString::number(fcDocUndoWord9,16).toUpper() + ")" + ", ";
        _s = _s + "lcbDocUndoWord9: " + QString::number(lcbDocUndoWord9) + "(" + QString::number(lcbDocUndoWord9,16).toUpper() + ")" + ", ";
        _s = _s + "fcRgbUse: " + QString::number(fcRgbUse) + "(" + QString::number(fcRgbUse,16).toUpper() + ")" + ", ";
        _s = _s + "lcbRgbUse: " + QString::number(lcbRgbUse) + "(" + QString::number(lcbRgbUse,16).toUpper() + ")" + ", ";
        _s = _s + "fcUsp: " + QString::number(fcUsp) + "(" + QString::number(fcUsp,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUsp: " + QString::number(lcbUsp) + "(" + QString::number(lcbUsp,16).toUpper() + ")" + ", ";
        _s = _s + "fcUskf: " + QString::number(fcUskf) + "(" + QString::number(fcUskf,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUskf: " + QString::number(lcbUskf) + "(" + QString::number(lcbUskf,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcupcRgbUse: " + QString::number(fcPlcupcRgbUse) + "(" + QString::number(fcPlcupcRgbUse,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcupcRgbUse: " + QString::number(lcbPlcupcRgbUse) + "(" + QString::number(lcbPlcupcRgbUse,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcupcUsp: " + QString::number(fcPlcupcUsp) + "(" + QString::number(fcPlcupcUsp,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcupcUsp: " + QString::number(lcbPlcupcUsp) + "(" + QString::number(lcbPlcupcUsp,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbGlsyStyle: " + QString::number(fcSttbGlsyStyle) + "(" + QString::number(fcSttbGlsyStyle,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbGlsyStyle: " + QString::number(lcbSttbGlsyStyle) + "(" + QString::number(lcbSttbGlsyStyle,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlgosl: " + QString::number(fcPlgosl) + "(" + QString::number(fcPlgosl,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlgosl: " + QString::number(lcbPlgosl) + "(" + QString::number(lcbPlgosl,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcocx: " + QString::number(fcPlcocx) + "(" + QString::number(fcPlcocx,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcocx: " + QString::number(lcbPlcocx) + "(" + QString::number(lcbPlcocx,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBteLvc: " + QString::number(fcPlcfBteLvc) + "(" + QString::number(fcPlcfBteLvc,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBteLvc: " + QString::number(lcbPlcfBteLvc) + "(" + QString::number(lcbPlcfBteLvc,16).toUpper() + ")" + ", ";
        _s = _s + "dwLowDateTime: " + QString::number(dwLowDateTime) + "(" + QString::number(dwLowDateTime,16).toUpper() + ")" + ", ";
        _s = _s + "dwHighDateTime: " + QString::number(dwHighDateTime) + "(" + QString::number(dwHighDateTime,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfLvcPre10: " + QString::number(fcPlcfLvcPre10) + "(" + QString::number(fcPlcfLvcPre10,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfLvcPre10: " + QString::number(lcbPlcfLvcPre10) + "(" + QString::number(lcbPlcfLvcPre10,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfAsumy: " + QString::number(fcPlcfAsumy) + "(" + QString::number(fcPlcfAsumy,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfAsumy: " + QString::number(lcbPlcfAsumy) + "(" + QString::number(lcbPlcfAsumy,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfGram: " + QString::number(fcPlcfGram) + "(" + QString::number(fcPlcfGram,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfGram: " + QString::number(lcbPlcfGram) + "(" + QString::number(lcbPlcfGram,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbListNames: " + QString::number(fcSttbListNames) + "(" + QString::number(fcSttbListNames,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbListNames: " + QString::number(lcbSttbListNames) + "(" + QString::number(lcbSttbListNames,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfUssr: " + QString::number(fcSttbfUssr) + "(" + QString::number(fcSttbfUssr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfUssr: " + QString::number(lcbSttbfUssr) + "(" + QString::number(lcbSttbfUssr,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class FibRgFcLcb2000 {
public:
    quint32 fcPlcfTch;
    quint32 lcbPlcfTch;
    quint32 fcRmdThreading;
    quint32 lcbRmdThreading;
    quint32 fcMid;
    quint32 lcbMid;
    quint32 fcSttbRgtplc;
    quint32 lcbSttbRgtplc;
    quint32 fcMsoEnvelope;
    quint32 lcbMsoEnvelope;
    quint32 fcPlcfLad;
    quint32 lcbPlcfLad;
    quint32 fcRgDofr;
    quint32 lcbRgDofr;
    quint32 fcPlcosl;
    quint32 lcbPlcosl;
    quint32 fcPlcfCookieOld;
    quint32 lcbPlcfCookieOld;
    quint32 fcPgdMotherOld;
    quint32 lcbPgdMotherOld;
    quint32 fcBkdMotherOld;
    quint32 lcbBkdMotherOld;
    quint32 fcPgdFtnOld;
    quint32 lcbPgdFtnOld;
    quint32 fcBkdFtnOld;
    quint32 lcbBkdFtnOld;
    quint32 fcPgdEdnOld;
    quint32 lcbPgdEdnOld;
    quint32 fcBkdEdnOld;
    quint32 lcbBkdEdnOld;
    QString toString() {
        QString _s = "FibRgFcLcb2000:";
        _s = _s + "fcPlcfTch: " + QString::number(fcPlcfTch) + "(" + QString::number(fcPlcfTch,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfTch: " + QString::number(lcbPlcfTch) + "(" + QString::number(lcbPlcfTch,16).toUpper() + ")" + ", ";
        _s = _s + "fcRmdThreading: " + QString::number(fcRmdThreading) + "(" + QString::number(fcRmdThreading,16).toUpper() + ")" + ", ";
        _s = _s + "lcbRmdThreading: " + QString::number(lcbRmdThreading) + "(" + QString::number(lcbRmdThreading,16).toUpper() + ")" + ", ";
        _s = _s + "fcMid: " + QString::number(fcMid) + "(" + QString::number(fcMid,16).toUpper() + ")" + ", ";
        _s = _s + "lcbMid: " + QString::number(lcbMid) + "(" + QString::number(lcbMid,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbRgtplc: " + QString::number(fcSttbRgtplc) + "(" + QString::number(fcSttbRgtplc,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbRgtplc: " + QString::number(lcbSttbRgtplc) + "(" + QString::number(lcbSttbRgtplc,16).toUpper() + ")" + ", ";
        _s = _s + "fcMsoEnvelope: " + QString::number(fcMsoEnvelope) + "(" + QString::number(fcMsoEnvelope,16).toUpper() + ")" + ", ";
        _s = _s + "lcbMsoEnvelope: " + QString::number(lcbMsoEnvelope) + "(" + QString::number(lcbMsoEnvelope,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfLad: " + QString::number(fcPlcfLad) + "(" + QString::number(fcPlcfLad,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfLad: " + QString::number(lcbPlcfLad) + "(" + QString::number(lcbPlcfLad,16).toUpper() + ")" + ", ";
        _s = _s + "fcRgDofr: " + QString::number(fcRgDofr) + "(" + QString::number(fcRgDofr,16).toUpper() + ")" + ", ";
        _s = _s + "lcbRgDofr: " + QString::number(lcbRgDofr) + "(" + QString::number(lcbRgDofr,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcosl: " + QString::number(fcPlcosl) + "(" + QString::number(fcPlcosl,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcosl: " + QString::number(lcbPlcosl) + "(" + QString::number(lcbPlcosl,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfCookieOld: " + QString::number(fcPlcfCookieOld) + "(" + QString::number(fcPlcfCookieOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfCookieOld: " + QString::number(lcbPlcfCookieOld) + "(" + QString::number(lcbPlcfCookieOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcPgdMotherOld: " + QString::number(fcPgdMotherOld) + "(" + QString::number(fcPgdMotherOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPgdMotherOld: " + QString::number(lcbPgdMotherOld) + "(" + QString::number(lcbPgdMotherOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcBkdMotherOld: " + QString::number(fcBkdMotherOld) + "(" + QString::number(fcBkdMotherOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbBkdMotherOld: " + QString::number(lcbBkdMotherOld) + "(" + QString::number(lcbBkdMotherOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcPgdFtnOld: " + QString::number(fcPgdFtnOld) + "(" + QString::number(fcPgdFtnOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPgdFtnOld: " + QString::number(lcbPgdFtnOld) + "(" + QString::number(lcbPgdFtnOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcBkdFtnOld: " + QString::number(fcBkdFtnOld) + "(" + QString::number(fcBkdFtnOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbBkdFtnOld: " + QString::number(lcbBkdFtnOld) + "(" + QString::number(lcbBkdFtnOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcPgdEdnOld: " + QString::number(fcPgdEdnOld) + "(" + QString::number(fcPgdEdnOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPgdEdnOld: " + QString::number(lcbPgdEdnOld) + "(" + QString::number(lcbPgdEdnOld,16).toUpper() + ")" + ", ";
        _s = _s + "fcBkdEdnOld: " + QString::number(fcBkdEdnOld) + "(" + QString::number(fcBkdEdnOld,16).toUpper() + ")" + ", ";
        _s = _s + "lcbBkdEdnOld: " + QString::number(lcbBkdEdnOld) + "(" + QString::number(lcbBkdEdnOld,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class FibRgFcLcb2002 {
public:
    quint32 fcUnused1;
    quint32 lcbUnused1;
    quint32 fcPlcfPgp;
    quint32 lcbPlcfPgp;
    quint32 fcPlcfuim;
    quint32 lcbPlcfuim;
    quint32 fcPlfguidUim;
    quint32 lcbPlfguidUim;
    quint32 fcAtrdExtra;
    quint32 lcbAtrdExtra;
    quint32 fcPlrsid;
    quint32 lcbPlrsid;
    quint32 fcSttbfBkmkFactoid;
    quint32 lcbSttbfBkmkFactoid;
    quint32 fcPlcfBkfFactoid;
    quint32 lcbPlcfBkfFactoid;
    quint32 fcPlcfcookie;
    quint32 lcbPlcfcookie;
    quint32 fcPlcfBklFactoid;
    quint32 lcbPlcfBklFactoid;
    quint32 fcFactoidData;
    quint32 lcbFactoidData;
    quint32 fcDocUndo;
    quint32 lcbDocUndo;
    quint32 fcSttbfBkmkFcc;
    quint32 lcbSttbfBkmkFcc;
    quint32 fcPlcfBkfFcc;
    quint32 lcbPlcfBkfFcc;
    quint32 fcPlcfBklFcc;
    quint32 lcbPlcfBklFcc;
    quint32 fcSttbfbkmkBPRepairs;
    quint32 lcbSttbfbkmkBPRepairs;
    quint32 fcPlcfbkfBPRepairs;
    quint32 lcbPlcfbkfBPRepairs;
    quint32 fcPlcfbklBPRepairs;
    quint32 lcbPlcfbklBPRepairs;
    quint32 fcPmsNew;
    quint32 lcbPmsNew;
    quint32 fcODSO;
    quint32 lcbODSO;
    quint32 fcPlcfpmiOldXP;
    quint32 lcbPlcfpmiOldXP;
    quint32 fcPlcfpmiNewXP;
    quint32 lcbPlcfpmiNewXP;
    quint32 fcPlcfpmiMixedXP;
    quint32 lcbPlcfpmiMixedXP;
    quint32 fcUnused2;
    quint32 lcbUnused2;
    quint32 fcPlcffactoid;
    quint32 lcbPlcffactoid;
    QString toString() {
        QString _s = "FibRgFcLcb2002:";
        _s = _s + "fcUnused1: " + QString::number(fcUnused1) + "(" + QString::number(fcUnused1,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUnused1: " + QString::number(lcbUnused1) + "(" + QString::number(lcbUnused1,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfPgp: " + QString::number(fcPlcfPgp) + "(" + QString::number(fcPlcfPgp,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfPgp: " + QString::number(lcbPlcfPgp) + "(" + QString::number(lcbPlcfPgp,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfuim: " + QString::number(fcPlcfuim) + "(" + QString::number(fcPlcfuim,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfuim: " + QString::number(lcbPlcfuim) + "(" + QString::number(lcbPlcfuim,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlfguidUim: " + QString::number(fcPlfguidUim) + "(" + QString::number(fcPlfguidUim,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlfguidUim: " + QString::number(lcbPlfguidUim) + "(" + QString::number(lcbPlfguidUim,16).toUpper() + ")" + ", ";
        _s = _s + "fcAtrdExtra: " + QString::number(fcAtrdExtra) + "(" + QString::number(fcAtrdExtra,16).toUpper() + ")" + ", ";
        _s = _s + "lcbAtrdExtra: " + QString::number(lcbAtrdExtra) + "(" + QString::number(lcbAtrdExtra,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlrsid: " + QString::number(fcPlrsid) + "(" + QString::number(fcPlrsid,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlrsid: " + QString::number(lcbPlrsid) + "(" + QString::number(lcbPlrsid,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfBkmkFactoid: " + QString::number(fcSttbfBkmkFactoid) + "(" + QString::number(fcSttbfBkmkFactoid,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfBkmkFactoid: " + QString::number(lcbSttbfBkmkFactoid) + "(" + QString::number(lcbSttbfBkmkFactoid,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBkfFactoid: " + QString::number(fcPlcfBkfFactoid) + "(" + QString::number(fcPlcfBkfFactoid,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBkfFactoid: " + QString::number(lcbPlcfBkfFactoid) + "(" + QString::number(lcbPlcfBkfFactoid,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfcookie: " + QString::number(fcPlcfcookie) + "(" + QString::number(fcPlcfcookie,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfcookie: " + QString::number(lcbPlcfcookie) + "(" + QString::number(lcbPlcfcookie,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBklFactoid: " + QString::number(fcPlcfBklFactoid) + "(" + QString::number(fcPlcfBklFactoid,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBklFactoid: " + QString::number(lcbPlcfBklFactoid) + "(" + QString::number(lcbPlcfBklFactoid,16).toUpper() + ")" + ", ";
        _s = _s + "fcFactoidData: " + QString::number(fcFactoidData) + "(" + QString::number(fcFactoidData,16).toUpper() + ")" + ", ";
        _s = _s + "lcbFactoidData: " + QString::number(lcbFactoidData) + "(" + QString::number(lcbFactoidData,16).toUpper() + ")" + ", ";
        _s = _s + "fcDocUndo: " + QString::number(fcDocUndo) + "(" + QString::number(fcDocUndo,16).toUpper() + ")" + ", ";
        _s = _s + "lcbDocUndo: " + QString::number(lcbDocUndo) + "(" + QString::number(lcbDocUndo,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfBkmkFcc: " + QString::number(fcSttbfBkmkFcc) + "(" + QString::number(fcSttbfBkmkFcc,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfBkmkFcc: " + QString::number(lcbSttbfBkmkFcc) + "(" + QString::number(lcbSttbfBkmkFcc,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBkfFcc: " + QString::number(fcPlcfBkfFcc) + "(" + QString::number(fcPlcfBkfFcc,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBkfFcc: " + QString::number(lcbPlcfBkfFcc) + "(" + QString::number(lcbPlcfBkfFcc,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfBklFcc: " + QString::number(fcPlcfBklFcc) + "(" + QString::number(fcPlcfBklFcc,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfBklFcc: " + QString::number(lcbPlcfBklFcc) + "(" + QString::number(lcbPlcfBklFcc,16).toUpper() + ")" + ", ";
        _s = _s + "fcSttbfbkmkBPRepairs: " + QString::number(fcSttbfbkmkBPRepairs) + "(" + QString::number(fcSttbfbkmkBPRepairs,16).toUpper() + ")" + ", ";
        _s = _s + "lcbSttbfbkmkBPRepairs: " + QString::number(lcbSttbfbkmkBPRepairs) + "(" + QString::number(lcbSttbfbkmkBPRepairs,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfbkfBPRepairs: " + QString::number(fcPlcfbkfBPRepairs) + "(" + QString::number(fcPlcfbkfBPRepairs,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfbkfBPRepairs: " + QString::number(lcbPlcfbkfBPRepairs) + "(" + QString::number(lcbPlcfbkfBPRepairs,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfbklBPRepairs: " + QString::number(fcPlcfbklBPRepairs) + "(" + QString::number(fcPlcfbklBPRepairs,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfbklBPRepairs: " + QString::number(lcbPlcfbklBPRepairs) + "(" + QString::number(lcbPlcfbklBPRepairs,16).toUpper() + ")" + ", ";
        _s = _s + "fcPmsNew: " + QString::number(fcPmsNew) + "(" + QString::number(fcPmsNew,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPmsNew: " + QString::number(lcbPmsNew) + "(" + QString::number(lcbPmsNew,16).toUpper() + ")" + ", ";
        _s = _s + "fcODSO: " + QString::number(fcODSO) + "(" + QString::number(fcODSO,16).toUpper() + ")" + ", ";
        _s = _s + "lcbODSO: " + QString::number(lcbODSO) + "(" + QString::number(lcbODSO,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfpmiOldXP: " + QString::number(fcPlcfpmiOldXP) + "(" + QString::number(fcPlcfpmiOldXP,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfpmiOldXP: " + QString::number(lcbPlcfpmiOldXP) + "(" + QString::number(lcbPlcfpmiOldXP,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfpmiNewXP: " + QString::number(fcPlcfpmiNewXP) + "(" + QString::number(fcPlcfpmiNewXP,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfpmiNewXP: " + QString::number(lcbPlcfpmiNewXP) + "(" + QString::number(lcbPlcfpmiNewXP,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcfpmiMixedXP: " + QString::number(fcPlcfpmiMixedXP) + "(" + QString::number(fcPlcfpmiMixedXP,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcfpmiMixedXP: " + QString::number(lcbPlcfpmiMixedXP) + "(" + QString::number(lcbPlcfpmiMixedXP,16).toUpper() + ")" + ", ";
        _s = _s + "fcUnused2: " + QString::number(fcUnused2) + "(" + QString::number(fcUnused2,16).toUpper() + ")" + ", ";
        _s = _s + "lcbUnused2: " + QString::number(lcbUnused2) + "(" + QString::number(lcbUnused2,16).toUpper() + ")" + ", ";
        _s = _s + "fcPlcffactoid: " + QString::number(fcPlcffactoid) + "(" + QString::number(fcPlcffactoid,16).toUpper() + ")" + ", ";
        _s = _s + "lcbPlcffactoid: " + QString::number(lcbPlcffactoid) + "(" + QString::number(lcbPlcffactoid,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class LPStshi {
public:
    quint16 cbSthi;
    QByteArray stshi;
    QString toString() {
        QString _s = "LPStshi:";
        _s = _s + "cbSthi: " + QString::number(cbSthi) + "(" + QString::number(cbSthi,16).toUpper() + ")" + ", ";
        _s = _s + "stshi: " + "[array of stshi]" + ", ";
        return _s;
    }
};
class LPStd {
public:
    quint16 cbStd;
    QByteArray std;
    quint8 padding;
    QString toString() {
        QString _s = "LPStd:";
        _s = _s + "cbStd: " + QString::number(cbStd) + "(" + QString::number(cbStd,16).toUpper() + ")" + ", ";
        _s = _s + "std: " + "[array of std]" + ", ";
        _s = _s + "padding: " + QString::number(padding) + "(" + QString::number(padding,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class PlcfSed {
public:
    QVector<quint32> aCP;
    QVector<Sed> aSed;
    QString toString() {
        QString _s = "PlcfSed:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        _s = _s + "aSed: " + "[array of aSed]" + ", ";
        return _s;
    }
};
class Sed {
public:
    quint16 fn;
    qint32 fcSepx;
    quint16 fnMpr;
    quint32 fcMpr;
    QString toString() {
        QString _s = "Sed:";
        _s = _s + "fn: " + QString::number(fn) + "(" + QString::number(fn,16).toUpper() + ")" + ", ";
        _s = _s + "fcSepx: " + QString::number(fcSepx) + "(" + QString::number(fcSepx,16).toUpper() + ")" + ", ";
        _s = _s + "fnMpr: " + QString::number(fnMpr) + "(" + QString::number(fnMpr,16).toUpper() + ")" + ", ";
        _s = _s + "fcMpr: " + QString::number(fcMpr) + "(" + QString::number(fcMpr,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class Plcfhdd {
public:
    QVector<quint32> aCP;
    QString toString() {
        QString _s = "Plcfhdd:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        return _s;
    }
};
class PlcBteChpx {
public:
    QVector<quint32> aCP;
    QVector<quint32> aPnBteChpx;
    QString toString() {
        QString _s = "PlcBteChpx:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        _s = _s + "aPnBteChpx: " + "[array of aPnBteChpx]" + ", ";
        return _s;
    }
};
class PlcfBtePapx {
public:
    QVector<quint32> aCP;
    QVector<quint32> aPnBteChpx;
    QString toString() {
        QString _s = "PlcfBtePapx:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        _s = _s + "aPnBteChpx: " + "[array of aPnBteChpx]" + ", ";
        return _s;
    }
};
class Tcg {
public:
    quint8 nTcgVer;
    QByteArray todo;
    QString toString() {
        QString _s = "Tcg:";
        _s = _s + "nTcgVer: " + QString::number(nTcgVer) + "(" + QString::number(nTcgVer,16).toUpper() + ")" + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
};
class PrcData {
public:
    qint16 cbGrpprl;
    QVector<Sprm> GrpPrl;
    QString toString() {
        QString _s = "PrcData:";
        _s = _s + "cbGrpprl: " + QString::number(cbGrpprl) + "(" + QString::number(cbGrpprl,16).toUpper() + ")" + ", ";
        _s = _s + "GrpPrl: " + "[array of GrpPrl]" + ", ";
        return _s;
    }
};
class Sprm {
public:
    quint16 ispmd;
    bool fSpec;
    quint8 sgc;
    quint8 spra;
    QString toString() {
        QString _s = "Sprm:";
        _s = _s + "ispmd: " + QString::number(ispmd) + "(" + QString::number(ispmd,16).toUpper() + ")" + ", ";
        _s = _s + "fSpec: " + QString::number(fSpec) + ", ";
        _s = _s + "sgc: " + QString::number(sgc) + "(" + QString::number(sgc,16).toUpper() + ")" + ", ";
        _s = _s + "spra: " + QString::number(spra) + "(" + QString::number(spra,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class Pcdt {
public:
    quint8 clxt;
    quint32 lcb;
    QVector<Pcd> PlcPcd;
    QString toString() {
        QString _s = "Pcdt:";
        _s = _s + "clxt: " + QString::number(clxt) + "(" + QString::number(clxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcb: " + QString::number(lcb) + "(" + QString::number(lcb,16).toUpper() + ")" + ", ";
        _s = _s + "PlcPcd: " + "[array of PlcPcd]" + ", ";
        return _s;
    }
};
class FCompressed {
public:
    quint32 fc;
    bool fCompressed;
    bool r1;
    QString toString() {
        QString _s = "FCompressed:";
        _s = _s + "fc: " + QString::number(fc) + "(" + QString::number(fc,16).toUpper() + ")" + ", ";
        _s = _s + "fCompressed: " + QString::number(fCompressed) + ", ";
        _s = _s + "r1: " + QString::number(r1) + ", ";
        return _s;
    }
};
class Prm0 {
public:
    bool fComplex;
    quint8 isprm;
    quint8 val;
    QString toString() {
        QString _s = "Prm0:";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
        _s = _s + "isprm: " + QString::number(isprm) + "(" + QString::number(isprm,16).toUpper() + ")" + ", ";
        _s = _s + "val: " + QString::number(val) + "(" + QString::number(val,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class Prm1 {
public:
    bool fComplex;
    quint16 igrpprl;
    QString toString() {
        QString _s = "Prm1:";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
        _s = _s + "igrpprl: " + QString::number(igrpprl) + "(" + QString::number(igrpprl,16).toUpper() + ")" + ", ";
        return _s;
    }
};
class SttbfFfn {
public:
    quint16 cData;
    quint16 cbExtra;
    QVector<SttbfFfnEntry> data;
    QString toString() {
        QString _s = "SttbfFfn:";
        _s = _s + "cData: " + QString::number(cData) + "(" + QString::number(cData,16).toUpper() + ")" + ", ";
        _s = _s + "cbExtra: " + QString::number(cbExtra) + "(" + QString::number(cbExtra,16).toUpper() + ")" + ", ";
        _s = _s + "data: " + "[array of data]" + ", ";
        return _s;
    }
};
class SttbfFfnEntry {
public:
    quint8 cchData;
    QByteArray Data;
    QString toString() {
        QString _s = "SttbfFfnEntry:";
        _s = _s + "cchData: " + QString::number(cchData) + "(" + QString::number(cchData,16).toUpper() + ")" + ", ";
        _s = _s + "Data: " + "[array of Data]" + ", ";
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
        _s = _s + "fHideThumbnails: " + QString::number(fHideThumbnails) + ", ";
        _s = _s + "fBarSnapped: " + QString::number(fBarSnapped) + ", ";
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
        _s = _s + "fNonOutLineData: " + QString::number(fNonOutLineData) + ", ";
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
        _s = _s + "reserved1: " + QString::number(reserved1) + ", ";
        _s = _s + "fShouldCollapse: " + QString::number(fShouldCollapse) + ", ";
        _s = _s + "fNonOutlineData: " + QString::number(fNonOutlineData) + ", ";
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
        _s = _s + "fDefaultTabSize: " + QString::number(fDefaultTabSize) + ", ";
        _s = _s + "fCLevels: " + QString::number(fCLevels) + ", ";
        _s = _s + "fTabStops: " + QString::number(fTabStops) + ", ";
        _s = _s + "fLeftMargin1: " + QString::number(fLeftMargin1) + ", ";
        _s = _s + "fLeftMargin2: " + QString::number(fLeftMargin2) + ", ";
        _s = _s + "fLeftMargin3: " + QString::number(fLeftMargin3) + ", ";
        _s = _s + "fLeftMargin4: " + QString::number(fLeftMargin4) + ", ";
        _s = _s + "fLeftMargin5: " + QString::number(fLeftMargin5) + ", ";
        _s = _s + "fIndent1: " + QString::number(fIndent1) + ", ";
        _s = _s + "fIndent2: " + QString::number(fIndent2) + ", ";
        _s = _s + "fIndent3: " + QString::number(fIndent3) + ", ";
        _s = _s + "fIndent4: " + QString::number(fIndent4) + ", ";
        _s = _s + "fIndent5: " + QString::number(fIndent5) + ", ";
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
        _s = _s + "slideSize: " + slideSize.toString() + ", ";
        _s = _s + "notesSize: " + notesSize.toString() + ", ";
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
    QSharedPointer<MenuNameAtom> menuNameAtom;
    QSharedPointer<ProgIDAtom> progIdAtom;
    QSharedPointer<ClipboardNameAtom> clipboardNameAtom;
    QSharedPointer<MetafileBlob> metafile;
    QString toString() {
        QString _s = "ExOleLinkContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exOleLinkAtom: " + exOleLinkAtom.toString() + ", ";
        _s = _s + "exOleObjAtom: " + exOleObjAtom.toString() + ", ";
        _s = _s + "menuNameAtom: " + ((menuNameAtom)?menuNameAtom->toString() :"null") + ", ";
        _s = _s + "progIdAtom: " + ((progIdAtom)?progIdAtom->toString() :"null") + ", ";
        _s = _s + "clipboardNameAtom: " + ((clipboardNameAtom)?clipboardNameAtom->toString() :"null") + ", ";
        _s = _s + "metafile: " + ((metafile)?metafile->toString() :"null") + ", ";
        return _s;
    }
};
class ExOleEmbedContainer {
public:
    RecordHeader rh;
    ExOleEmbedAtom exOleEmbedAtom;
    ExOleObjAtom exOleObjAtom;
    QSharedPointer<MenuNameAtom> menuNameAtom;
    QSharedPointer<ProgIDAtom> progIdAtom;
    QSharedPointer<ClipboardNameAtom> clipboardNameAtom;
    QSharedPointer<MetafileBlob> metafile;
    QString toString() {
        QString _s = "ExOleEmbedContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exOleEmbedAtom: " + exOleEmbedAtom.toString() + ", ";
        _s = _s + "exOleObjAtom: " + exOleObjAtom.toString() + ", ";
        _s = _s + "menuNameAtom: " + ((menuNameAtom)?menuNameAtom->toString() :"null") + ", ";
        _s = _s + "progIdAtom: " + ((progIdAtom)?progIdAtom->toString() :"null") + ", ";
        _s = _s + "clipboardNameAtom: " + ((clipboardNameAtom)?clipboardNameAtom->toString() :"null") + ", ";
        _s = _s + "metafile: " + ((metafile)?metafile->toString() :"null") + ", ";
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
class OfficeArtClientData {
public:
    OfficeArtRecordHeader rh;
    QSharedPointer<ShapeFlagsAtom> shapeFlagsAtom;
    QSharedPointer<ShapeFlags10Atom> shapeFlags10Atom;
    QSharedPointer<ExObjRefAtom> exObjRefAtom;
    QSharedPointer<AnimationInfoContainer> animationInfo;
    QSharedPointer<MouseClickInteractiveInfoContainer> mouseClickInteractiveInfo;
    QSharedPointer<MouseOverInteractiveInfoContainer> mouseOverInteractiveInfo;
    QSharedPointer<PlaceholderAtom> placeholderAtom;
    QSharedPointer<RecolorInfoAtom> recolorInfoAtom;
    QList<ShapeClientRoundtripDataSubcontainerOrAtom> rgShapeClientRoundtripData;
    QString toString() {
        QString _s = "OfficeArtClientData:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "shapeFlagsAtom: " + ((shapeFlagsAtom)?shapeFlagsAtom->toString() :"null") + ", ";
        _s = _s + "shapeFlags10Atom: " + ((shapeFlags10Atom)?shapeFlags10Atom->toString() :"null") + ", ";
        _s = _s + "exObjRefAtom: " + ((exObjRefAtom)?exObjRefAtom->toString() :"null") + ", ";
        _s = _s + "animationInfo: " + ((animationInfo)?animationInfo->toString() :"null") + ", ";
        _s = _s + "mouseClickInteractiveInfo: " + ((mouseClickInteractiveInfo)?mouseClickInteractiveInfo->toString() :"null") + ", ";
        _s = _s + "mouseOverInteractiveInfo: " + ((mouseOverInteractiveInfo)?mouseOverInteractiveInfo->toString() :"null") + ", ";
        _s = _s + "placeholderAtom: " + ((placeholderAtom)?placeholderAtom->toString() :"null") + ", ";
        _s = _s + "recolorInfoAtom: " + ((recolorInfoAtom)?recolorInfoAtom->toString() :"null") + ", ";
        _s = _s + "rgShapeClientRoundtripData: " + "[array of rgShapeClientRoundtripData]" + ", ";
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
    FibRgFcLcb97 fibRgFcLcbBlob;
    FibRgFcLcb2000 fibRgFcLcbBlob2;
    FibRgFcLcb2002 fibRgFcLcbBlob3;
    quint16 cswNew;
    QByteArray fibRgCswNew;
    QByteArray trail;
    QString toString() {
        QString _s = "Fib:";
        _s = _s + "base: " + base.toString() + ", ";
        _s = _s + "csw: " + QString::number(csw) + "(" + QString::number(csw,16).toUpper() + ")" + ", ";
        _s = _s + "fibRgW: " + fibRgW.toString() + ", ";
        _s = _s + "cslw: " + QString::number(cslw) + "(" + QString::number(cslw,16).toUpper() + ")" + ", ";
        _s = _s + "fibRgLw: " + fibRgLw.toString() + ", ";
        _s = _s + "cbRgFcLcb: " + QString::number(cbRgFcLcb) + "(" + QString::number(cbRgFcLcb,16).toUpper() + ")" + ", ";
        _s = _s + "fibRgFcLcbBlob: " + fibRgFcLcbBlob.toString() + ", ";
        _s = _s + "fibRgFcLcbBlob2: " + fibRgFcLcbBlob2.toString() + ", ";
        _s = _s + "fibRgFcLcbBlob3: " + fibRgFcLcbBlob3.toString() + ", ";
        _s = _s + "cswNew: " + QString::number(cswNew) + "(" + QString::number(cswNew,16).toUpper() + ")" + ", ";
        _s = _s + "fibRgCswNew: " + "[array of fibRgCswNew]" + ", ";
        _s = _s + "trail: " + "[array of trail]" + ", ";
        return _s;
    }
};
class STSH {
public:
    LPStshi lpstshi;
    QVector<LPStd> rglpstd;
    QString toString() {
        QString _s = "STSH:";
        _s = _s + "lpstshi: " + lpstshi.toString() + ", ";
        _s = _s + "rglpstd: " + "[array of rglpstd]" + ", ";
        return _s;
    }
};
class Clx {
public:
    QList<Pcr> RgPrc;
    Pcdt pcdt;
    QString toString() {
        QString _s = "Clx:";
        _s = _s + "RgPrc: " + "[array of RgPrc]" + ", ";
        _s = _s + "pcdt: " + pcdt.toString() + ", ";
        return _s;
    }
};
class Pcr {
public:
    quint8 clxt;
    PrcData prcData;
    QString toString() {
        QString _s = "Pcr:";
        _s = _s + "clxt: " + QString::number(clxt) + "(" + QString::number(clxt,16).toUpper() + ")" + ", ";
        _s = _s + "prcData: " + prcData.toString() + ", ";
        return _s;
    }
};
class Prm {
public:
    class prmChoice {public:QSharedPointer<Prm0> prm0;
QSharedPointer<Prm1> prm1;
}; prmChoice prm;
    QString toString() {
        QString _s = "Prm:";
        _s = _s + "prm: " + "<choice>" + ", ";
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
    class anonChoice {public:QSharedPointer<OfficeArtBlipEMF> officeartblipemf;
QSharedPointer<OfficeArtBlipWMF> officeartblipwmf;
QSharedPointer<OfficeArtBlipPICT> officeartblippict;
QSharedPointer<OfficeArtBlipJPEG> officeartblipjpeg;
QSharedPointer<OfficeArtBlipPNG> officeartblippng;
QSharedPointer<OfficeArtBlipDIB> officeartblipdib;
QSharedPointer<OfficeArtBlipTIFF> officeartbliptiff;
}; anonChoice anon;
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
    class anonChoice {public:QSharedPointer<SlidePersistAtom> slidepersistatom;
QSharedPointer<TextHeaderAtom> textheaderatom;
QSharedPointer<TextCharsAtom> textcharsatom;
QSharedPointer<TextBytesAtom> textbytesatom;
QSharedPointer<StyleTextPropAtom> styletextpropatom;
QSharedPointer<SlideNumberMCAtom> slidenumbermcatom;
QSharedPointer<DateTimeMCAtom> datetimemcatom;
QSharedPointer<GenericDateMCAtom> genericdatemcatom;
QSharedPointer<HeaderMCAtom> headermcatom;
QSharedPointer<FooterMCAtom> footermcatom;
QSharedPointer<RTFDateTimeMCAtom> rtfdatetimemcatom;
QSharedPointer<TextBookmarkAtom> textbookmarkatom;
QSharedPointer<TextSpecialInfoAtom> textspecialinfoatom;
QSharedPointer<InteractiveInfoInstance> interactiveinfoinstance;
QSharedPointer<TextInteractiveInfoInstance> textinteractiveinfoinstance;
}; anonChoice anon;
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
    class anonChoice {public:QSharedPointer<ExOleLinkContainer> exolelinkcontainer;
QSharedPointer<ExOleEmbedContainer> exoleembedcontainer;
}; anonChoice anon;
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
    QSharedPointer<OfficeArtBStoreContainer> blipStore;
    OfficeArtFOPT drawingPrimaryOptions;
    QSharedPointer<OfficeArtTertiaryFOPT> drawingTertiaryOptions;
    QSharedPointer<OfficeArtColorMRUContainer> colorMRU;
    OfficeArtSplitMenuColorContainer splitColors;
    QString toString() {
        QString _s = "OfficeArtDggContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "drawingGroup: " + drawingGroup.toString() + ", ";
        _s = _s + "blipStore: " + ((blipStore)?blipStore->toString() :"null") + ", ";
        _s = _s + "drawingPrimaryOptions: " + drawingPrimaryOptions.toString() + ", ";
        _s = _s + "drawingTertiaryOptions: " + ((drawingTertiaryOptions)?drawingTertiaryOptions->toString() :"null") + ", ";
        _s = _s + "colorMRU: " + ((colorMRU)?colorMRU->toString() :"null") + ", ";
        _s = _s + "splitColors: " + splitColors.toString() + ", ";
        return _s;
    }
};
class OfficeArtSpContainer {
public:
    OfficeArtRecordHeader rh;
    QSharedPointer<OfficeArtFSPGR> shapeGroup;
    OfficeArtFSP shapeProp;
    QSharedPointer<OfficeArtFPSPL> deletedshape;
    QSharedPointer<OfficeArtFOPT> shapePrimaryOptions;
    QSharedPointer<OfficeArtSecondaryFOPT> shapeSecondaryOptions1;
    QSharedPointer<OfficeArtTertiaryFOPT> shapeTertiaryOptions1;
    QSharedPointer<OfficeArtChildAnchor> childAnchor;
    QSharedPointer<OfficeArtClientAnchor> clientAnchor;
    QSharedPointer<OfficeArtClientData> clientData;
    QSharedPointer<OfficeArtClientTextBox> clientTextbox;
    QString toString() {
        QString _s = "OfficeArtSpContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "shapeGroup: " + ((shapeGroup)?shapeGroup->toString() :"null") + ", ";
        _s = _s + "shapeProp: " + shapeProp.toString() + ", ";
        _s = _s + "deletedshape: " + ((deletedshape)?deletedshape->toString() :"null") + ", ";
        _s = _s + "shapePrimaryOptions: " + ((shapePrimaryOptions)?shapePrimaryOptions->toString() :"null") + ", ";
        _s = _s + "shapeSecondaryOptions1: " + ((shapeSecondaryOptions1)?shapeSecondaryOptions1->toString() :"null") + ", ";
        _s = _s + "shapeTertiaryOptions1: " + ((shapeTertiaryOptions1)?shapeTertiaryOptions1->toString() :"null") + ", ";
        _s = _s + "childAnchor: " + ((childAnchor)?childAnchor->toString() :"null") + ", ";
        _s = _s + "clientAnchor: " + ((clientAnchor)?clientAnchor->toString() :"null") + ", ";
        _s = _s + "clientData: " + ((clientData)?clientData->toString() :"null") + ", ";
        _s = _s + "clientTextbox: " + ((clientTextbox)?clientTextbox->toString() :"null") + ", ";
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
class Table {
public:
    STSH stsh;
    PlcfSed plcfSed;
    Plcfhdd plcfHdd;
    PlcBteChpx plcfBteChpx;
    PlcfBtePapx plcfBtePapx;
    Tcg cmds;
    Clx clx;
    SttbfFfn sttbfFfn;
    QByteArray dop;
    QString toString() {
        QString _s = "Table:";
        _s = _s + "stsh: " + stsh.toString() + ", ";
        _s = _s + "plcfSed: " + plcfSed.toString() + ", ";
        _s = _s + "plcfHdd: " + plcfHdd.toString() + ", ";
        _s = _s + "plcfBteChpx: " + plcfBteChpx.toString() + ", ";
        _s = _s + "plcfBtePapx: " + plcfBtePapx.toString() + ", ";
        _s = _s + "cmds: " + cmds.toString() + ", ";
        _s = _s + "clx: " + clx.toString() + ", ";
        _s = _s + "sttbfFfn: " + sttbfFfn.toString() + ", ";
        _s = _s + "dop: " + "[array of dop]" + ", ";
        return _s;
    }
};
class Pcd {
public:
    bool fNoParaLast;
    bool fR1;
    bool fDirtly;
    bool fR2;
    quint16 fR3;
    FCompressed fc;
    Prm prm;
    QString toString() {
        QString _s = "Pcd:";
        _s = _s + "fNoParaLast: " + QString::number(fNoParaLast) + ", ";
        _s = _s + "fR1: " + QString::number(fR1) + ", ";
        _s = _s + "fDirtly: " + QString::number(fDirtly) + ", ";
        _s = _s + "fR2: " + QString::number(fR2) + ", ";
        _s = _s + "fR3: " + QString::number(fR3) + "(" + QString::number(fR3,16).toUpper() + ")" + ", ";
        _s = _s + "fc: " + fc.toString() + ", ";
        _s = _s + "prm: " + prm.toString() + ", ";
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
    class anonChoice {public:QSharedPointer<OfficeArtFBSE> officeartfbse;
QSharedPointer<OfficeArtBlip> officeartblip;
}; anonChoice anon;
    QString toString() {
        QString _s = "OfficeArtBStoreContainerFileBlock:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class DocumentTextInfoContainer {
public:
    RecordHeader rh;
    QSharedPointer<KinsokuContainer> kinsoku;
    QSharedPointer<FontCollectionContainer> fontCollection;
    QSharedPointer<TextCFExceptionAtom> textCFDefaultsAtom;
    QSharedPointer<TextPFExceptionAtom> textPFDefaultsAtom;
    QSharedPointer<DefaultRulerAtom> defaultRulerAtom;
    TextSIExceptionAtom textSIDefaultsAtom;
    TextMasterStyleAtom textMasterStyleAtom;
    QString toString() {
        QString _s = "DocumentTextInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "kinsoku: " + ((kinsoku)?kinsoku->toString() :"null") + ", ";
        _s = _s + "fontCollection: " + ((fontCollection)?fontCollection->toString() :"null") + ", ";
        _s = _s + "textCFDefaultsAtom: " + ((textCFDefaultsAtom)?textCFDefaultsAtom->toString() :"null") + ", ";
        _s = _s + "textPFDefaultsAtom: " + ((textPFDefaultsAtom)?textPFDefaultsAtom->toString() :"null") + ", ";
        _s = _s + "defaultRulerAtom: " + ((defaultRulerAtom)?defaultRulerAtom->toString() :"null") + ", ";
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
    QSharedPointer<OfficeArtFRITContainer> regroupItems;
    OfficeArtSpgrContainer groupShape;
    OfficeArtSpContainer shape;
    QList<OfficeArtSpgrContainerFileBlock> deletedShapes;
    QSharedPointer<OfficeArtSolverContainer> solvers;
    QString toString() {
        QString _s = "OfficeArtDgContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "drawingData: " + drawingData.toString() + ", ";
        _s = _s + "regroupItems: " + ((regroupItems)?regroupItems->toString() :"null") + ", ";
        _s = _s + "groupShape: " + groupShape.toString() + ", ";
        _s = _s + "shape: " + shape.toString() + ", ";
        _s = _s + "deletedShapes: " + "[array of deletedShapes]" + ", ";
        _s = _s + "solvers: " + ((solvers)?solvers->toString() :"null") + ", ";
        return _s;
    }
};
class OfficeArtSpgrContainerFileBlock {
public:
    class anonChoice {public:QSharedPointer<OfficeArtSpContainer> officeartspcontainer;
QSharedPointer<OfficeArtSpgrContainer> officeartspgrcontainer;
}; anonChoice anon;
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
    QSharedPointer<ExObjListContainer> exObjList;
    DocumentTextInfoContainer documentTextInfo;
    DrawingGroupContainer drawingGroup;
    MasterListWithTextContainer masterList;
    QSharedPointer<DocInfoListContainer> docInfoList;
    QSharedPointer<SlideHeadersFootersContainer> slideHF;
    QSharedPointer<NotesHeadersFootersContainer> notesHF;
    QSharedPointer<SlideListWithTextContainer> slideList;
    QSharedPointer<NotesListWithTextContainer> notesList;
    QSharedPointer<SlideShowDocInfoAtom> slideShowDocInfoAtom;
    EndDocumentAtom endDocumentAtom;
    QString toString() {
        QString _s = "DocumentContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "documentAtom: " + documentAtom.toString() + ", ";
        _s = _s + "exObjList: " + ((exObjList)?exObjList->toString() :"null") + ", ";
        _s = _s + "documentTextInfo: " + documentTextInfo.toString() + ", ";
        _s = _s + "drawingGroup: " + drawingGroup.toString() + ", ";
        _s = _s + "masterList: " + masterList.toString() + ", ";
        _s = _s + "docInfoList: " + ((docInfoList)?docInfoList->toString() :"null") + ", ";
        _s = _s + "slideHF: " + ((slideHF)?slideHF->toString() :"null") + ", ";
        _s = _s + "notesHF: " + ((notesHF)?notesHF->toString() :"null") + ", ";
        _s = _s + "slideList: " + ((slideList)?slideList->toString() :"null") + ", ";
        _s = _s + "notesList: " + ((notesList)?notesList->toString() :"null") + ", ";
        _s = _s + "slideShowDocInfoAtom: " + ((slideShowDocInfoAtom)?slideShowDocInfoAtom->toString() :"null") + ", ";
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
    QSharedPointer<SlideShowSlideInfoAtom> slideShowSlideInfoAtom;
    QSharedPointer<PerSlideHeadersFootersContainer> perSlideHFContainer;
    DrawingContainer drawing;
    SlideSchemeColorSchemeAtom slideSchemeColorSchemeAtom;
    QSharedPointer<SlideProgTagscontainer> slideProgTagsContainer;
    QString toString() {
        QString _s = "SlideContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "slideAtom: " + slideAtom.toString() + ", ";
        _s = _s + "slideShowSlideInfoAtom: " + ((slideShowSlideInfoAtom)?slideShowSlideInfoAtom->toString() :"null") + ", ";
        _s = _s + "perSlideHFContainer: " + ((perSlideHFContainer)?perSlideHFContainer->toString() :"null") + ", ";
        _s = _s + "drawing: " + drawing.toString() + ", ";
        _s = _s + "slideSchemeColorSchemeAtom: " + slideSchemeColorSchemeAtom.toString() + ", ";
        _s = _s + "slideProgTagsContainer: " + ((slideProgTagsContainer)?slideProgTagsContainer->toString() :"null") + ", ";
        return _s;
    }
};
class MasterOrSlideContainer {
public:
    class anonChoice {public:QSharedPointer<MainMasterContainer> mainmastercontainer;
QSharedPointer<SlideContainer> slidecontainer;
}; anonChoice anon;
    QString toString() {
        QString _s = "MasterOrSlideContainer:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
class PowerPointStruct {
public:
    class anonChoice {public:QSharedPointer<DocumentContainer> documentcontainer;
QSharedPointer<MasterOrSlideContainer> masterorslidecontainer;
QSharedPointer<PersistDirectoryAtom> persistdirectoryatom;
QSharedPointer<NotesContainer> notescontainer;
QSharedPointer<HandoutContainer> handoutcontainer;
QSharedPointer<SlideContainer> slidecontainer;
QSharedPointer<ExOleObjStg> exoleobjstg;
QSharedPointer<ExControlStg> excontrolstg;
QSharedPointer<VbaProjectStg> vbaprojectstg;
QSharedPointer<UserEditAtom> usereditatom;
}; anonChoice anon;
    QString toString() {
        QString _s = "PowerPointStruct:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
};
void parseRecordHeader(LEInputStream& in, RecordHeader& _s) {
    _s.recVer = in.readuint4();
    _s.recInstance = in.readuint12();
    _s.recType = in.readuint16();
    if (!(((quint16)_s.recType)>0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.recType)>0 for value ") + QString::number(_s.recType) + "(" + QString::number(_s.recType,16).toUpper() + ")");
    }
    _s.recLen = in.readuint32();
}
void parseCurrentUserAtom(LEInputStream& in, CurrentUserAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FF6)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FF6 for value ") + _s.rh.toString());
    }
    _s.size = in.readuint32();
    if (!(((quint32)_s.size) == 0x14)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.size) == 0x14 for value ") + QString::number(_s.size) + "(" + QString::number(_s.size,16).toUpper() + ")");
    }
    _s.headerToken = in.readuint32();
    if (!(((quint32)_s.headerToken) == 0xE391C05F || ((quint32)_s.headerToken) == 0xF3D1C4DF)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.headerToken) == 0xE391C05F || ((quint32)_s.headerToken) == 0xF3D1C4DF for value ") + QString::number(_s.headerToken) + "(" + QString::number(_s.headerToken,16).toUpper() + ")");
    }
    _s.offsetToCurrentEdit = in.readuint32();
    _s.lenUserName = in.readuint16();
    if (!(((quint16)_s.lenUserName)<=255)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.lenUserName)<=255 for value ") + QString::number(_s.lenUserName) + "(" + QString::number(_s.lenUserName,16).toUpper() + ")");
    }
    _s.docFileVersion = in.readuint16();
    if (!(((quint16)_s.docFileVersion) == 0x03F4)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.docFileVersion) == 0x03F4 for value ") + QString::number(_s.docFileVersion) + "(" + QString::number(_s.docFileVersion,16).toUpper() + ")");
    }
    _s.majorVersion = in.readuint8();
    if (!(((quint8)_s.majorVersion) == 0x03)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.majorVersion) == 0x03 for value ") + QString::number(_s.majorVersion) + "(" + QString::number(_s.majorVersion,16).toUpper() + ")");
    }
    _s.minorVersion = in.readuint8();
    if (!(((quint8)_s.minorVersion) == 0x00)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.minorVersion) == 0x00 for value ") + QString::number(_s.minorVersion) + "(" + QString::number(_s.minorVersion,16).toUpper() + ")");
    }
    _s.unused = in.readuint16();
    _c = _s.lenUserName;
    _s.ansiUserName.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.ansiUserName[_i] = in.readuint8();
    }
    _s.relVersion = in.readuint32();
    if (!(((quint32)_s.relVersion) == 0x8 || ((quint32)_s.relVersion) == 0x9)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.relVersion) == 0x8 || ((quint32)_s.relVersion) == 0x9 for value ") + QString::number(_s.relVersion) + "(" + QString::number(_s.relVersion,16).toUpper() + ")");
    }
    if (_s.rh.recLen==3*_s.lenUserName+0x14) {
        _c = 2*_s.lenUserName;
        _s.unicodeUserName.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.unicodeUserName[_i] = in.readuint8();
        }
    }
}
void parseByte(LEInputStream& in, Byte& _s) {
    _s.b = in.readuint8();
}
void parseCurrentUserStream(LEInputStream& in, CurrentUserStream& _s) {
    LEInputStream::Mark _m;
    parseCurrentUserAtom(in, _s.anon1);
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.trailing.append(Byte());
            parseByte(in, _s.trailing.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseOfficeArtBStoreDelay(LEInputStream& in, OfficeArtBStoreDelay& _s) {
    LEInputStream::Mark _m;
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.anon1.append(OfficeArtBStoreContainerFileBlock());
            parseOfficeArtBStoreContainerFileBlock(in, _s.anon1.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseOfficeArtRecordHeader(LEInputStream& in, OfficeArtRecordHeader& _s) {
    _s.recVer = in.readuint4();
    _s.recInstance = in.readuint12();
    _s.recType = in.readuint16();
    _s.recLen = in.readuint32();
}
void parseOfficeArtBlipJPEG(LEInputStream& in, OfficeArtBlipJPEG& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E2 || _s.rh.recInstance == 0x6E3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E2 || _s.rh.recInstance == 0x6E3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF01D)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF01D for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E3) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    _s.tag = in.readuint8();
    _c = _s.rh.recLen-((_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x6E2)?17:33);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseOfficeArtBlipPNG(LEInputStream& in, OfficeArtBlipPNG& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x6E0 || _s.rh.recInstance == 0x6E1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x6E0 || _s.rh.recInstance == 0x6E1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF01E)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF01E for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x6E1) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    _s.tag = in.readuint8();
    _c = _s.rh.recLen-((_s.rh.recInstance==0x6E0)?17:33);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseOfficeArtBlipDIB(LEInputStream& in, OfficeArtBlipDIB& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x7A8 || _s.rh.recInstance == 0x7A9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x7A8 || _s.rh.recInstance == 0x7A9 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF01F)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF01F for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x7A9) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    _s.tag = in.readuint8();
    _c = _s.rh.recLen-((_s.rh.recInstance==0x7A8)?17:33);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseOfficeArtBlipTIFF(LEInputStream& in, OfficeArtBlipTIFF& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x6E4 || _s.rh.recInstance == 0x6E5)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x6E4 || _s.rh.recInstance == 0x6E5 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF020)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF020 for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x6E5) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    _s.tag = in.readuint8();
    _c = _s.rh.recLen-((_s.rh.recInstance==0x6E4)?17:33);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseRECT(LEInputStream& in, RECT& _s) {
    _s.left = in.readint32();
    _s.top = in.readint32();
    _s.right = in.readint32();
    _s.bottom = in.readint32();
}
void parsePOINT(LEInputStream& in, POINT& _s) {
    _s.x = in.readint32();
    _s.y = in.readint32();
}
void parsePowerPointStructs(LEInputStream& in, PowerPointStructs& _s) {
    LEInputStream::Mark _m;
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.anon.append(PowerPointStruct());
            parsePowerPointStruct(in, _s.anon.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseSlideHeadersFootersContainer(LEInputStream& in, SlideHeadersFootersContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFD9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFD9 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseNotesHeadersFootersContainer(LEInputStream& in, NotesHeadersFootersContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 4 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFD9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFD9 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parsePerSlideHeadersFootersContainer(LEInputStream& in, PerSlideHeadersFootersContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFD9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFD9 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseEndDocumentAtom(LEInputStream& in, EndDocumentAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x3EA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x3EA for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0 for value ") + _s.rh.toString());
    }
}
void parseDocInfoListContainer(LEInputStream& in, DocInfoListContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x7D0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x7D0 for value ") + _s.rh.toString());
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgChildRec.append(DocInfoListSubContainerOrAtom());
            parseDocInfoListSubContainerOrAtom(in, _s.rgChildRec.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseDocInfoListSubContainerOrAtom(LEInputStream& in, DocInfoListSubContainerOrAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0 || _s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 || _s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1388 || _s.rh.recType == 0x414 || _s.rh.recType == 0x413 || _s.rh.recType == 0x407 || _s.rh.recType == 0x3FA || _s.rh.recType == 0x408 || _s.rh.recType == 0x3FF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1388 || _s.rh.recType == 0x414 || _s.rh.recType == 0x413 || _s.rh.recType == 0x407 || _s.rh.recType == 0x3FA || _s.rh.recType == 0x408 || _s.rh.recType == 0x3FF for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.wrong.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.wrong[_i] = in.readuint8();
    }
}
void parseSlideViewInfoInstance(LEInputStream& in, SlideViewInfoInstance& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x3FA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x3FA for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseMasterListWithTextContainer(LEInputStream& in, MasterListWithTextContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FF0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FF0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen%28==0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen%28==0 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen/28;
    _s.rgMasterPersistAtom.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseMasterPersistAtom(in, _s.rgMasterPersistAtom[_i]);
    }
}
void parseSlideListWithTextContainer(LEInputStream& in, SlideListWithTextContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FF0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FF0 for value ") + _s.rh.toString());
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgChildRec.append(SlideListWithTextSubContainerOrAtom());
            parseSlideListWithTextSubContainerOrAtom(in, _s.rgChildRec.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseNotesListWithTextContainer(LEInputStream& in, NotesListWithTextContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FF0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FF0 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseTextHeaderAtom(LEInputStream& in, TextHeaderAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF9F)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF9F for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.textType = in.readuint32();
}
void parseTextCharsAtom(LEInputStream& in, TextCharsAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFA0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFA0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen%2==0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen%2==0 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen/2;
    _s.textChars.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.textChars[_i] = in.readuint16();
        if (!(((quint16)_s.textChars[_i]) != 0)) {
            throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.textChars[_i]) != 0 for value ") + "[array of _s.textChars]");
        }
    }
}
void parseTextBytesAtom(LEInputStream& in, TextBytesAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFA8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFA8 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.textChars.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.textChars[_i] = in.readuint8();
        if (!(((quint8)_s.textChars[_i]) != 0)) {
            throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.textChars[_i]) != 0 for value ") + "[array of _s.textChars]");
        }
    }
}
void parseMasterTextPropAtom(LEInputStream& in, MasterTextPropAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFA2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFA2 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseStyleTextPropAtom(LEInputStream& in, StyleTextPropAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFA1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFA1 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseSlideNumberMCAtom(LEInputStream& in, SlideNumberMCAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFD8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFD8 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
}
void parseDateTimeMCAtom(LEInputStream& in, DateTimeMCAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF7)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF7 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
    _s.index = in.readuint8();
    _c = 3;
    _s.unused.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.unused[_i] = in.readuint8();
    }
}
void parseGenericDateMCAtom(LEInputStream& in, GenericDateMCAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF8 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
}
void parseHeaderMCAtom(LEInputStream& in, HeaderMCAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF9 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
}
void parseFooterMCAtom(LEInputStream& in, FooterMCAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFFA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFFA for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
}
void parseRTFDateTimeMCAtom(LEInputStream& in, RTFDateTimeMCAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1015)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1015 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x84)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x84 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
    _c = 128;
    _s.format.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.format[_i] = in.readuint8();
    }
}
void parseTextBookmarkAtom(LEInputStream& in, TextBookmarkAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFA7)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFA7 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0xC)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0xC for value ") + _s.rh.toString());
    }
    _s.begin = in.readint32();
    _s.end = in.readint32();
    _s.bookmarkID = in.readint32();
}
void parseTextSpecialInfoAtom(LEInputStream& in, TextSpecialInfoAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFAA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFAA for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.wrong.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.wrong[_i] = in.readuint8();
    }
}
void parseInteractiveInfoInstance(LEInputStream& in, InteractiveInfoInstance& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _c = 8;
    _s.range.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.range[_i] = in.readuint8();
    }
}
void parseTextInteractiveInfoInstance(LEInputStream& in, TextInteractiveInfoInstance& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFDF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFDF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _c = 8;
    _s.range.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.range[_i] = in.readuint8();
    }
}
void parseSlideId(LEInputStream& in, SlideId& _s) {
    _s.slideId = in.readuint32();
    if (!(((quint32)_s.slideId)>=100)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.slideId)>=100 for value ") + QString::number(_s.slideId) + "(" + QString::number(_s.slideId,16).toUpper() + ")");
    }
    if (!(((quint32)_s.slideId)<2147483647)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.slideId)<2147483647 for value ") + QString::number(_s.slideId) + "(" + QString::number(_s.slideId,16).toUpper() + ")");
    }
}
void parseTabStops(LEInputStream& in, TabStops& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.count = in.readuint16();
    _c = _s.count;
    _s.rgTabStop.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseTabStop(in, _s.rgTabStop[_i]);
    }
}
void parseTabStop(LEInputStream& in, TabStop& _s) {
    _s.position = in.readint16();
    _s.type = in.readuint16();
}
void parseBulletFlags(LEInputStream& in, BulletFlags& _s) {
    _s.fHasBullet = in.readbit();
    _s.fBulletHasFont = in.readbit();
    _s.fBulletHasColor = in.readbit();
    _s.fBulletHasSize = in.readbit();
    _s.reserved = in.readuint12();
}
void parsePFMasks(LEInputStream& in, PFMasks& _s) {
    _s.hasBullet = in.readbit();
    _s.bulletHasFont = in.readbit();
    _s.bulletHasColor = in.readbit();
    _s.bulletHasSize = in.readbit();
    _s.bulletFont = in.readbit();
    _s.bulletColor = in.readbit();
    _s.bulletSize = in.readbit();
    _s.bulletChar = in.readbit();
    _s.leftMargin = in.readbit();
    _s.unused = in.readbit();
    _s.indent = in.readbit();
    _s.align = in.readbit();
    _s.lineSpacing = in.readbit();
    _s.spaceBefore = in.readbit();
    _s.spaceAfter = in.readbit();
    _s.defaultTabSize = in.readbit();
    _s.fontAlign = in.readbit();
    _s.charWrap = in.readbit();
    _s.wordWrap = in.readbit();
    _s.overflow = in.readbit();
    _s.tabStops = in.readbit();
    _s.textDirection = in.readbit();
    _s.reserved = in.readbit();
    _s.bulletBlip = in.readbit();
    _s.bulletScheme = in.readbit();
    _s.bulletHasScheme = in.readbit();
    _s.reserved2 = in.readuint6();
}
void parseCFMasks(LEInputStream& in, CFMasks& _s) {
    _s.bold = in.readbit();
    _s.italic = in.readbit();
    _s.underline = in.readbit();
    _s.unused1 = in.readbit();
    _s.shadow = in.readbit();
    _s.fehint = in.readbit();
    _s.unused2 = in.readbit();
    _s.kumi = in.readbit();
    _s.unused3 = in.readbit();
    _s.emboss = in.readbit();
    _s.fHasStyle = in.readuint4();
    _s.unused4 = in.readuint2();
    _s.typeface = in.readbit();
    _s.size = in.readbit();
    _s.color = in.readbit();
    _s.position = in.readbit();
    _s.pp10ext = in.readbit();
    _s.oldEATypeface = in.readbit();
    _s.ansiTypeface = in.readbit();
    _s.symbolTypeface = in.readbit();
    _s.newEATypeface = in.readbit();
    _s.csTypeface = in.readbit();
    _s.pp11ext = in.readbit();
    _s.reserved = in.readuint5();
}
void parseCFStyle(LEInputStream& in, CFStyle& _s) {
    _s.bold = in.readbit();
    _s.italic = in.readbit();
    _s.underline = in.readbit();
    _s.unused1 = in.readbit();
    _s.shadow = in.readbit();
    _s.fehint = in.readbit();
    _s.unused2 = in.readbit();
    _s.kumi = in.readbit();
    _s.unused3 = in.readbit();
    _s.emboss = in.readbit();
    _s.pp9rt = in.readuint4();
    _s.unused4 = in.readuint2();
}
void parseFontCollectionContainer(LEInputStream& in, FontCollectionContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x07D5)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x07D5 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.rgFontCollectionEntry.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgFontCollectionEntry[_i] = in.readuint8();
    }
}
void parseFontEntityAtom(LEInputStream& in, FontEntityAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance>=0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance<=128)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance<=128 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFB7)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFB7 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x44)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x44 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseKinsokuAtom(LEInputStream& in, KinsokuAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FD2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FD2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.level = in.readuint32();
    if (!(((quint32)_s.level) == 0 || ((quint32)_s.level) == 1 || ((quint32)_s.level) == 2)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.level) == 0 || ((quint32)_s.level) == 1 || ((quint32)_s.level) == 2 for value ") + QString::number(_s.level) + "(" + QString::number(_s.level,16).toUpper() + ")");
    }
}
void parseTextSIExceptionAtom(LEInputStream& in, TextSIExceptionAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FA9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FA9 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.textSIException.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.textSIException[_i] = in.readuint8();
    }
}
void parseExOleEmbedAtom(LEInputStream& in, ExOleEmbedAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FCD)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FCD for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x8 for value ") + _s.rh.toString());
    }
    _s.exColorFollow = in.readuint32();
    if (!(((quint32)_s.exColorFollow) == 0 || ((quint32)_s.exColorFollow) == 1 || ((quint32)_s.exColorFollow) == 2)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.exColorFollow) == 0 || ((quint32)_s.exColorFollow) == 1 || ((quint32)_s.exColorFollow) == 2 for value ") + QString::number(_s.exColorFollow) + "(" + QString::number(_s.exColorFollow,16).toUpper() + ")");
    }
    _s.fCantLockServer = in.readuint8();
    _s.fNoSizeToServer = in.readuint8();
    _s.fIsTable = in.readuint8();
    _s.unused = in.readuint8();
}
void parsePointStruct(LEInputStream& in, PointStruct& _s) {
    _s.x = in.readint32();
    _s.y = in.readint32();
}
void parseRatioStruct(LEInputStream& in, RatioStruct& _s) {
    _s.numer = in.readint32();
    _s.denom = in.readint32();
    if (!(((qint32)_s.denom)!= 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.denom)!= 0 for value ") + QString::number(_s.denom) + "(" + QString::number(_s.denom,16).toUpper() + ")");
    }
}
void parsePersistDirectoryAtom(LEInputStream& in, PersistDirectoryAtom& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1772)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1772 for value ") + _s.rh.toString());
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgPersistDirEntry.append(PersistDirectoryEntry());
            parsePersistDirectoryEntry(in, _s.rgPersistDirEntry.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parsePersistDirectoryEntry(LEInputStream& in, PersistDirectoryEntry& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.persistId = in.readuint20();
    _s.cPersist = in.readuint12();
    _c = _s.cPersist;
    _s.rgPersistOffset.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parsePersistOffsetEntry(in, _s.rgPersistOffset[_i]);
    }
}
void parsePersistOffsetEntry(LEInputStream& in, PersistOffsetEntry& _s) {
    _s.anon = in.readuint32();
}
void parsePersistIdRef(LEInputStream& in, PersistIdRef& _s) {
    _s.anon = in.readuint32();
}
void parseMainMasterContainer(LEInputStream& in, MainMasterContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03F8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03F8 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseNotesContainer(LEInputStream& in, NotesContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03F0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03F0 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseHandoutContainer(LEInputStream& in, HandoutContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FC9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FC9 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseExControlStg(LEInputStream& in, ExControlStg& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1011)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1011 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseExOleObjStg(LEInputStream& in, ExOleObjStg& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1011)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1011 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseUserEditAtom(LEInputStream& in, UserEditAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FF5)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FF5 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x1C || _s.rh.recLen == 0x20)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x1C || _s.rh.recLen == 0x20 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseVbaProjectStg(LEInputStream& in, VbaProjectStg& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1011)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1011 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.TODO.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.TODO[_i] = in.readuint8();
    }
}
void parseSlideProgTagscontainer(LEInputStream& in, SlideProgTagscontainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x1388)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1388 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseSlideAtom(LEInputStream& in, SlideAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03EF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03EF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x18)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x18 for value ") + _s.rh.toString());
    }
    _s.geom = in.readuint32();
    _c = 8;
    _s.rgPlaceholderTypes.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgPlaceholderTypes[_i] = in.readuint8();
    }
    _s.masterIdRef = in.readuint32();
    _s.notesIdRef = in.readuint32();
    _s.slideFlags = in.readuint16();
    _s.unused = in.readuint16();
}
void parseSlideShowSlideInfoAtom(LEInputStream& in, SlideShowSlideInfoAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03F9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03F9 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x10)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x10 for value ") + _s.rh.toString());
    }
    _s.slidetime = in.readuint32();
    _s.slideIdRef = in.readuint32();
    _s.effectDirection = in.readuint8();
    _s.effectType = in.readuint8();
    _s.fManualAdvance = in.readbit();
    _s.reserved = in.readbit();
    _s.fHidden = in.readbit();
    _s.reserved2 = in.readbit();
    _s.fSound = in.readbit();
    _s.reserved3 = in.readbit();
    _s.fLoopSound = in.readbit();
    _s.reserved4 = in.readbit();
    _s.fStopSound = in.readbit();
    _s.freserved5 = in.readbit();
    _s.fAutoAdvance = in.readbit();
    _s.reserved6 = in.readbit();
    _s.fCursorVisible = in.readbit();
    _s.reserved7 = in.readuint3();
    _s.speed = in.readuint8();
    _c = 3;
    _s.unused.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.unused[_i] = in.readuint8();
    }
}
void parseSlideShowDocInfoAtom(LEInputStream& in, SlideShowDocInfoAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0401)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0401 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x50)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x50 for value ") + _s.rh.toString());
    }
    _c = 0x50;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseSlideSchemeColorSchemeAtom(LEInputStream& in, SlideSchemeColorSchemeAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x07F0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x07F0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x20)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x20 for value ") + _s.rh.toString());
    }
    _c = 8;
    _s.rgSchemeColor.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseColorStruct(in, _s.rgSchemeColor[_i]);
    }
}
void parseRoundTripSlideRecord(LEInputStream& in, RoundTripSlideRecord& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recType == 0x40E || _s.rh.recType == 0x40F || _s.rh.recType == 0x41C || _s.rh.recType == 0x41D || _s.rh.recType == 0x41E || _s.rh.recType == 0x41F || _s.rh.recType == 0x420 || _s.rh.recType == 0x422 || _s.rh.recType == 0x423 || _s.rh.recType == 0x425 || _s.rh.recType == 0x426 || _s.rh.recType == 0x427 || _s.rh.recType == 0x428)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x40E || _s.rh.recType == 0x40F || _s.rh.recType == 0x41C || _s.rh.recType == 0x41D || _s.rh.recType == 0x41E || _s.rh.recType == 0x41F || _s.rh.recType == 0x420 || _s.rh.recType == 0x422 || _s.rh.recType == 0x423 || _s.rh.recType == 0x425 || _s.rh.recType == 0x426 || _s.rh.recType == 0x427 || _s.rh.recType == 0x428 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseColorStruct(LEInputStream& in, ColorStruct& _s) {
    _s.red = in.readuint8();
    _s.green = in.readuint8();
    _s.blue = in.readuint8();
    _s.unused = in.readuint8();
}
void parseExObjListAtom(LEInputStream& in, ExObjListAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x040A)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x040A for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.exObjIdSeed = in.readint32();
    if (!(((qint32)_s.exObjIdSeed)>1)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.exObjIdSeed)>1 for value ") + QString::number(_s.exObjIdSeed) + "(" + QString::number(_s.exObjIdSeed,16).toUpper() + ")");
    }
}
void parseExOleLinkAtom(LEInputStream& in, ExOleLinkAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FD1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FD1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xC)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xC for value ") + _s.rh.toString());
    }
    _s.slideIdRef = in.readuint32();
    _s.oleUpdateMode = in.readuint32();
    _s.unused = in.readuint32();
}
void parseExOleObjAtom(LEInputStream& in, ExOleObjAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FC3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FC3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x18)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x18 for value ") + _s.rh.toString());
    }
    _s.drawAspect = in.readuint32();
    _s.type = in.readuint32();
    _s.exObjId = in.readuint32();
    _s.subType = in.readuint32();
    _s.persistIdRef = in.readuint32();
    _s.unused = in.readuint32();
}
void parseMenuNameAtom(LEInputStream& in, MenuNameAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FBA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FBA for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen%2 == 0 )) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen%2 == 0  for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.menuName.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.menuName[_i] = in.readuint8();
    }
}
void parseProgIDAtom(LEInputStream& in, ProgIDAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FBA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FBA for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen%2 == 0 )) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen%2 == 0  for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.progId.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.progId[_i] = in.readuint8();
    }
}
void parseClipboardNameAtom(LEInputStream& in, ClipboardNameAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FBA)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FBA for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen%2 == 0 )) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen%2 == 0  for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.clipboardName.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.clipboardName[_i] = in.readuint8();
    }
}
void parseMetafileBlob(LEInputStream& in, MetafileBlob& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FC1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FC1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen>16)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen>16 for value ") + _s.rh.toString());
    }
    _s.mm = in.readint16();
    _s.xExt = in.readint16();
    _s.yExt = in.readint16();
    _c = _s.rh.recLen-6;
    _s.data.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.data[_i] = in.readuint8();
    }
}
void parseOfficeArtFDGG(LEInputStream& in, OfficeArtFDGG& _s) {
    _s.spidMax = in.readuint32();
    if (!(((quint32)_s.spidMax)<67098623)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.spidMax)<67098623 for value ") + QString::number(_s.spidMax) + "(" + QString::number(_s.spidMax,16).toUpper() + ")");
    }
    _s.cidcl = in.readuint32();
    if (!(((quint32)_s.cidcl)<268435455)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.cidcl)<268435455 for value ") + QString::number(_s.cidcl) + "(" + QString::number(_s.cidcl,16).toUpper() + ")");
    }
    _s.cspSaved = in.readuint32();
    _s.cdgSaved = in.readuint32();
}
void parseOfficeArtFDG(LEInputStream& in, OfficeArtFDG& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance<=4094)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance<=4094 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F008)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F008 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _s.csp = in.readuint32();
    _s.spidCur = in.readuint32();
}
void parseOfficeArtFRITContainer(LEInputStream& in, OfficeArtFRITContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F118)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F118 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recInstance;
    _s.rgfrit.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseOfficeArtFRIT(in, _s.rgfrit[_i]);
    }
}
void parseOfficeArtFRIT(LEInputStream& in, OfficeArtFRIT& _s) {
    _s.fridNew = in.readuint16();
    _s.fridOld = in.readuint16();
}
void parseOfficeArtBStoreContainer(LEInputStream& in, OfficeArtBStoreContainer& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F001)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F001 for value ") + _s.rh.toString());
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgfb.append(OfficeArtBStoreContainerFileBlock());
            parseOfficeArtBStoreContainerFileBlock(in, _s.rgfb.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseOfficeArtSpgrContainer(LEInputStream& in, OfficeArtSpgrContainer& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F003)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F003 for value ") + _s.rh.toString());
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgfb.append(OfficeArtSpgrContainerFileBlock());
            parseOfficeArtSpgrContainerFileBlock(in, _s.rgfb.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseOfficeArtSolverContainer(LEInputStream& in, OfficeArtSolverContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF005)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF005 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseOfficeArtFSPGR(LEInputStream& in, OfficeArtFSPGR& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F009)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F009 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x10)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x10 for value ") + _s.rh.toString());
    }
    _s.xLeft = in.readint32();
    _s.yTop = in.readint32();
    _s.xRight = in.readint32();
    _s.yBottom = in.readint32();
}
void parseOfficeArtFSP(LEInputStream& in, OfficeArtFSP& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance<= 202)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance<= 202 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F00A)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F00A for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _s.spid = in.readuint32();
    _s.fGroup = in.readbit();
    _s.fChild = in.readbit();
    _s.fPatriarch = in.readbit();
    _s.fDeleted = in.readbit();
    _s.fOleShape = in.readbit();
    _s.fHaveMaster = in.readbit();
    _s.fFlipH = in.readbit();
    _s.fFlipV = in.readbit();
    _s.fConnector = in.readbit();
    _s.fHaveAnchor = in.readbit();
    _s.fBackground = in.readbit();
    _s.fHaveSpt = in.readbit();
    _s.unused1 = in.readuint20();
}
void parseOfficeArtFOPT(LEInputStream& in, OfficeArtFOPT& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F00B)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F00B for value ") + _s.rh.toString());
    }
    _c = _s.rh.recInstance;
    _s.fopt.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseOfficeArtFOPTE(in, _s.fopt[_i]);
    }
}
void parseOfficeArtChildAnchor(LEInputStream& in, OfficeArtChildAnchor& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF00F)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF00F for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x10)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x10 for value ") + _s.rh.toString());
    }
    _s.xLeft = in.readint32();
    _s.yTop = in.readint32();
    _s.xRight = in.readint32();
    _s.yBottom = in.readint32();
}
void parseOfficeArtFPSPL(LEInputStream& in, OfficeArtFPSPL& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF11D)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF11D for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.spid = in.readuint30();
    _s.reserved1 = in.readbit();
    _s.fLast = in.readbit();
}
void parseOfficeArtSecondaryFOPT(LEInputStream& in, OfficeArtSecondaryFOPT& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF121)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF121 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.fopt.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.fopt[_i] = in.readuint8();
    }
}
void parseOfficeArtTertiaryFOPT(LEInputStream& in, OfficeArtTertiaryFOPT& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF122)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF122 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recInstance;
    _s.fopt.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseOfficeArtFOPTE(in, _s.fopt[_i]);
    }
}
void parseRectStruct(LEInputStream& in, RectStruct& _s) {
    _s.top = in.readint32();
    _s.left = in.readint32();
    _s.right = in.readint32();
    _s.bottom = in.readint32();
}
void parseSmallRectStruct(LEInputStream& in, SmallRectStruct& _s) {
    _s.top = in.readint16();
    _s.left = in.readint16();
    _s.right = in.readint16();
    _s.bottom = in.readint16();
}
void parseShapeFlagsAtom(LEInputStream& in, ShapeFlagsAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xBDB)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xBDB for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 1 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseShapeFlags10Atom(LEInputStream& in, ShapeFlags10Atom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xBDC)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xBDC for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 1 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseExObjRefAtom(LEInputStream& in, ExObjRefAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xBC1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xBC1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseAnimationInfoContainer(LEInputStream& in, AnimationInfoContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF1 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseMouseClickInteractiveInfoContainer(LEInputStream& in, MouseClickInteractiveInfoContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF2 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseMouseOverInteractiveInfoContainer(LEInputStream& in, MouseOverInteractiveInfoContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFF2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFF2 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parsePlaceholderAtom(LEInputStream& in, PlaceholderAtom& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xBC3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xBC3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 8 for value ") + _s.rh.toString());
    }
    _s.position = in.readint32();
    _s.placementId = in.readuint8();
    _s.size = in.readuint8();
    _s.unused = in.readuint16();
}
void parseRecolorInfoAtom(LEInputStream& in, RecolorInfoAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xFE7)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xFE7 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseOutlineTextRefAtom(LEInputStream& in, OutlineTextRefAtom& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF9E)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF9E for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 4 for value ") + _s.rh.toString());
    }
    _s.index = in.readint32();
    if (!(((qint32)_s.index)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.index)>=0 for value ") + QString::number(_s.index) + "(" + QString::number(_s.index,16).toUpper() + ")");
    }
}
void parseShapeClientRoundtripDataSubcontainerOrAtom(LEInputStream& in, ShapeClientRoundtripDataSubcontainerOrAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recType == 0x1388 || _s.rh.recType == 0xBDD || _s.rh.recType == 0x41F || _s.rh.recType == 0x420 || _s.rh.recType == 0x426)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x1388 || _s.rh.recType == 0xBDD || _s.rh.recType == 0x41F || _s.rh.recType == 0x420 || _s.rh.recType == 0x426 for value ") + _s.rh.toString());
    }
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseOfficeArtClientTextBox(LEInputStream& in, OfficeArtClientTextBox& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0 || _s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 || _s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF00D)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF00D for value ") + _s.rh.toString());
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgChildRec.append(TextClientDataSubContainerOrAtom());
            parseTextClientDataSubContainerOrAtom(in, _s.rgChildRec.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseTextClientDataSubContainerOrAtom(LEInputStream& in, TextClientDataSubContainerOrAtom& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    _c = _s.rh.recLen;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parseOfficeArtIDCL(LEInputStream& in, OfficeArtIDCL& _s) {
    _s.dgid = in.readuint32();
    _s.cspidCur = in.readuint32();
}
void parseOfficeArtFOPTEOPID(LEInputStream& in, OfficeArtFOPTEOPID& _s) {
    _s.opid = in.readuint14();
    _s.fBid = in.readbit();
    _s.fComplex = in.readbit();
}
void parseOfficeArtColorMRUContainer(LEInputStream& in, OfficeArtColorMRUContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF11A)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF11A for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen==4*_s.rh.recInstance)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen==4*_s.rh.recInstance for value ") + _s.rh.toString());
    }
    _c = _s.rh.recInstance;
    _s.rgmsocr.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseMSOCR(in, _s.rgmsocr[_i]);
    }
}
void parseMSOCR(LEInputStream& in, MSOCR& _s) {
    _s.red = in.readuint8();
    _s.green = in.readuint8();
    _s.blue = in.readuint8();
    _s.unused1 = in.readuint3();
    _s.fSchemeIndex = in.readbit();
    _s.unused2 = in.readuint4();
}
void parseOfficeArtSplitMenuColorContainer(LEInputStream& in, OfficeArtSplitMenuColorContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x4 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF11E)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF11E for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x10)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x10 for value ") + _s.rh.toString());
    }
    _c = 4;
    _s.smca.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseMSOCR(in, _s.smca[_i]);
    }
}
void parseTODO(LEInputStream& in, TODO& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    _c = _s.rh.recLen;
    _s.anon.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.anon[_i] = in.readuint8();
    }
}
void parseTODOS(LEInputStream& in, TODOS& _s) {
    LEInputStream::Mark _m;
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.anon.append(TODO());
            parseTODO(in, _s.anon.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseFibBase(LEInputStream& in, FibBase& _s) {
    _s.wIdent = in.readuint16();
    if (!(((quint16)_s.wIdent) == 0xA5EC)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.wIdent) == 0xA5EC for value ") + QString::number(_s.wIdent) + "(" + QString::number(_s.wIdent,16).toUpper() + ")");
    }
    _s.nFib = in.readuint16();
    if (!(((quint16)_s.nFib) == 0xC0 || ((quint16)_s.nFib) == 0xC1 || ((quint16)_s.nFib) == 0xC2 || ((quint16)_s.nFib) == 0x101 || ((quint16)_s.nFib) == 0x10B || ((quint16)_s.nFib) == 0x10C || ((quint16)_s.nFib) == 0x112)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.nFib) == 0xC0 || ((quint16)_s.nFib) == 0xC1 || ((quint16)_s.nFib) == 0xC2 || ((quint16)_s.nFib) == 0x101 || ((quint16)_s.nFib) == 0x10B || ((quint16)_s.nFib) == 0x10C || ((quint16)_s.nFib) == 0x112 for value ") + QString::number(_s.nFib) + "(" + QString::number(_s.nFib,16).toUpper() + ")");
    }
    _s.unused = in.readuint16();
    _s.lid = in.readuint16();
    _s.pnNext = in.readuint16();
    _s.fDot = in.readbit();
    _s.fGlsy = in.readbit();
    _s.fComplex = in.readbit();
    _s.fHasPic = in.readbit();
    _s.cQuickSaves = in.readuint4();
    _s.fEncrypted = in.readbit();
    _s.fWhichTblStm = in.readbit();
    _s.fReadOnlyRecommended = in.readbit();
    _s.fWriteReservation = in.readbit();
    _s.fExtChar = in.readbit();
    _s.fLoadOverride = in.readbit();
    _s.fFarEast = in.readbit();
    _s.fObfuscated = in.readbit();
    _s.nFibBack = in.readuint16();
    if (!(((quint16)_s.nFibBack) == 0xBF || ((quint16)_s.nFibBack) == 0xC1)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.nFibBack) == 0xBF || ((quint16)_s.nFibBack) == 0xC1 for value ") + QString::number(_s.nFibBack) + "(" + QString::number(_s.nFibBack,16).toUpper() + ")");
    }
    _s.IKey = in.readuint32();
    _s.envr = in.readuint8();
    if (!(((quint8)_s.envr) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.envr) == 0 for value ") + QString::number(_s.envr) + "(" + QString::number(_s.envr,16).toUpper() + ")");
    }
    _s.fMac = in.readbit();
    if (!(((bool)_s.fMac) == false)) {
        throw IncorrectValueException(in.getPosition() + QString("((bool)_s.fMac) == false for value ") + QString::number(_s.fMac));
    }
    _s.fEmptySpecial = in.readbit();
    _s.fLoadOverridePage = in.readbit();
    _s.reserved1 = in.readbit();
    _s.reserved2 = in.readbit();
    _s.fSpare0 = in.readuint3();
    _s.reserved3 = in.readuint16();
    if (!(((quint16)_s.reserved3) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.reserved3) == 0 for value ") + QString::number(_s.reserved3) + "(" + QString::number(_s.reserved3,16).toUpper() + ")");
    }
    _s.reserved4 = in.readuint16();
    if (!(((quint16)_s.reserved4) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.reserved4) == 0 for value ") + QString::number(_s.reserved4) + "(" + QString::number(_s.reserved4,16).toUpper() + ")");
    }
    _s.reserved5 = in.readuint32();
    _s.reserved6 = in.readuint32();
}
void parseFibRgW97(LEInputStream& in, FibRgW97& _s) {
    _s.reserved1 = in.readuint16();
    _s.reserved2 = in.readuint16();
    _s.reserved3 = in.readuint16();
    _s.reserved4 = in.readuint16();
    _s.reserved5 = in.readuint16();
    _s.reserved6 = in.readuint16();
    _s.reserved7 = in.readuint16();
    _s.reserved8 = in.readuint16();
    _s.reserved9 = in.readuint16();
    _s.reserved10 = in.readuint16();
    _s.reserved11 = in.readuint16();
    _s.reserved12 = in.readuint16();
    _s.reserved13 = in.readuint16();
    _s.lidFE = in.readuint16();
}
void parseFibRgLw97(LEInputStream& in, FibRgLw97& _s) {
    _s.cbMac = in.readuint32();
    _s.reserved1 = in.readuint32();
    _s.reserved2 = in.readuint32();
    _s.ccpText = in.readint32();
    if (!(((qint32)_s.ccpText)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpText)>=0 for value ") + QString::number(_s.ccpText) + "(" + QString::number(_s.ccpText,16).toUpper() + ")");
    }
    _s.ccpFtn = in.readint32();
    if (!(((qint32)_s.ccpFtn)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpFtn)>=0 for value ") + QString::number(_s.ccpFtn) + "(" + QString::number(_s.ccpFtn,16).toUpper() + ")");
    }
    _s.ccpHdd = in.readint32();
    if (!(((qint32)_s.ccpHdd)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpHdd)>=0 for value ") + QString::number(_s.ccpHdd) + "(" + QString::number(_s.ccpHdd,16).toUpper() + ")");
    }
    _s.reserved3 = in.readuint32();
    if (!(((quint32)_s.reserved3) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.reserved3) == 0 for value ") + QString::number(_s.reserved3) + "(" + QString::number(_s.reserved3,16).toUpper() + ")");
    }
    _s.ccpAtn = in.readint32();
    if (!(((qint32)_s.ccpAtn)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpAtn)>=0 for value ") + QString::number(_s.ccpAtn) + "(" + QString::number(_s.ccpAtn,16).toUpper() + ")");
    }
    _s.ccpEdn = in.readint32();
    if (!(((qint32)_s.ccpEdn)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpEdn)>=0 for value ") + QString::number(_s.ccpEdn) + "(" + QString::number(_s.ccpEdn,16).toUpper() + ")");
    }
    _s.ccpTxbx = in.readint32();
    if (!(((qint32)_s.ccpTxbx)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpTxbx)>=0 for value ") + QString::number(_s.ccpTxbx) + "(" + QString::number(_s.ccpTxbx,16).toUpper() + ")");
    }
    _s.ccpHdrTxbx = in.readint32();
    if (!(((qint32)_s.ccpHdrTxbx)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.ccpHdrTxbx)>=0 for value ") + QString::number(_s.ccpHdrTxbx) + "(" + QString::number(_s.ccpHdrTxbx,16).toUpper() + ")");
    }
    _s.reserved4 = in.readuint32();
    _s.reserved5 = in.readuint32();
    _s.reserved6 = in.readuint32();
    _s.reserved7 = in.readuint32();
    _s.reserved8 = in.readuint32();
    _s.reserved9 = in.readuint32();
    _s.reserved10 = in.readuint32();
    _s.reserved11 = in.readuint32();
    _s.reserved12 = in.readuint32();
    _s.reserved13 = in.readuint32();
    if (!(((quint32)_s.reserved13) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.reserved13) == 0 for value ") + QString::number(_s.reserved13) + "(" + QString::number(_s.reserved13,16).toUpper() + ")");
    }
    _s.reserved14 = in.readuint32();
    if (!(((quint32)_s.reserved14) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.reserved14) == 0 for value ") + QString::number(_s.reserved14) + "(" + QString::number(_s.reserved14,16).toUpper() + ")");
    }
}
void parseFibRgFcLcb97(LEInputStream& in, FibRgFcLcb97& _s) {
    _s.fcStshfOrig = in.readuint32();
    _s.lcbStshfOrig = in.readuint32();
    _s.fcStshf = in.readuint32();
    _s.lcbStshf = in.readuint32();
    _s.fcPlcffndRef = in.readuint32();
    _s.lcbPlcffndRef = in.readuint32();
    _s.fcPlcffndTxt = in.readuint32();
    _s.lcbPlcffndTxt = in.readuint32();
    _s.fcPlcfandRef = in.readuint32();
    _s.lcbPlcfandRef = in.readuint32();
    _s.fcPlcfandTxt = in.readuint32();
    _s.lcbPlcfandTxt = in.readuint32();
    _s.fcPlcfSed = in.readuint32();
    _s.lcbPlcfSed = in.readuint32();
    _s.fcPlcPad = in.readuint32();
    _s.lcbPlcPad = in.readuint32();
    _s.fcPlcfPhe = in.readuint32();
    _s.lcbPlcfPhe = in.readuint32();
    _s.fcSttbfGlsy = in.readuint32();
    _s.lcbSttbfGlsy = in.readuint32();
    _s.fcPlcfGlsy = in.readuint32();
    _s.lcbPlcfGlsy = in.readuint32();
    _s.fcPlcfHdd = in.readuint32();
    _s.lcbPlcfHdd = in.readuint32();
    _s.fcPlcfBteChpx = in.readuint32();
    _s.lcbPlcfBteChpx = in.readuint32();
    _s.fcPlcfBtePapx = in.readuint32();
    _s.lcbPlcfBtePapx = in.readuint32();
    _s.fcPlcfSea = in.readuint32();
    _s.lcbPlcfSea = in.readuint32();
    _s.fcSttbfFfn = in.readuint32();
    _s.lcbSttbfFfn = in.readuint32();
    _s.fcPlcfFldMom = in.readuint32();
    _s.lcbPlcfFldMom = in.readuint32();
    _s.fcPlcfFldHdr = in.readuint32();
    _s.lcbPlcfFldHdr = in.readuint32();
    _s.fcPlcfFldFtn = in.readuint32();
    _s.lcbPlcfFldFtn = in.readuint32();
    _s.fcPlcfFldAtn = in.readuint32();
    _s.lcbPlcfFldAtn = in.readuint32();
    _s.fcPlcfFldMcr = in.readuint32();
    _s.lcbPlcfFldMcr = in.readuint32();
    _s.fcSttbfBkmk = in.readuint32();
    _s.lcbSttbfBkmk = in.readuint32();
    _s.fcPlcfBkf = in.readuint32();
    _s.lcbPlcfBkf = in.readuint32();
    _s.fcPlcfBkl = in.readuint32();
    _s.lcbPlcfBkl = in.readuint32();
    _s.fcCmds = in.readuint32();
    _s.lcbCmds = in.readuint32();
    _s.fcUnused1 = in.readuint32();
    _s.lcbUnused1 = in.readuint32();
    _s.fcSttbfMcr = in.readuint32();
    _s.lcbSttbfMcr = in.readuint32();
    _s.fcPrDrvr = in.readuint32();
    _s.lcbPrDrvr = in.readuint32();
    _s.fcPrEnvPort = in.readuint32();
    _s.lcbPrEnvPort = in.readuint32();
    _s.fcPrEnvLand = in.readuint32();
    _s.lcbPrEnvLand = in.readuint32();
    _s.fcWss = in.readuint32();
    _s.lcbWss = in.readuint32();
    _s.fcDop = in.readuint32();
    _s.lcbDop = in.readuint32();
    _s.fcSttbfAssoc = in.readuint32();
    _s.lcbSttbfAssoc = in.readuint32();
    _s.fcClx = in.readuint32();
    _s.lcbClx = in.readuint32();
    _s.fcPlcfPgdFtn = in.readuint32();
    _s.lcbPlcfPgdFtn = in.readuint32();
    _s.fcAutosaveSource = in.readuint32();
    _s.lcbAutosaveSource = in.readuint32();
    _s.fcGrpXstAtnOwners = in.readuint32();
    _s.lcbGrpXstAtnOwners = in.readuint32();
    _s.fcSttbfAtnBkmk = in.readuint32();
    _s.lcbSttbfAtnBkmk = in.readuint32();
    _s.fcUnused2 = in.readuint32();
    _s.lcbUnused2 = in.readuint32();
    _s.fcUnused3 = in.readuint32();
    _s.lcbUnused3 = in.readuint32();
    _s.fcPlcSpaMom = in.readuint32();
    _s.lcbPlcSpaMom = in.readuint32();
    _s.fcPlcSpaHdr = in.readuint32();
    _s.lcbPlcSpaHdr = in.readuint32();
    _s.fcPlcfAtnBkf = in.readuint32();
    _s.lcbPlcfAtnBkf = in.readuint32();
    _s.fcPlcfAtnBkl = in.readuint32();
    _s.lcbPlcfAtnBkl = in.readuint32();
    _s.fcPms = in.readuint32();
    _s.lcbPms = in.readuint32();
    _s.fcFormFldSttbs = in.readuint32();
    _s.lcbFormFldSttbs = in.readuint32();
    _s.fcPlcfendRef = in.readuint32();
    _s.lcbPlcfendRef = in.readuint32();
    _s.fcPlcfendTxt = in.readuint32();
    _s.lcbPlcfendTxt = in.readuint32();
    _s.fcPlcfFldEdn = in.readuint32();
    _s.lcbPlcfFldEdn = in.readuint32();
    _s.fcUnused4 = in.readuint32();
    _s.lcbUnused4 = in.readuint32();
    _s.fcDggInfo = in.readuint32();
    _s.lcbDggInfo = in.readuint32();
    _s.fcSttbfRMark = in.readuint32();
    _s.lcbSttbfRMark = in.readuint32();
    _s.fcSttbfCaption = in.readuint32();
    _s.lcbSttbfCaption = in.readuint32();
    _s.fcSttbfAutoCaption = in.readuint32();
    _s.lcbSttbfAutoCaption = in.readuint32();
    _s.fcPlcfWkb = in.readuint32();
    _s.lcbPlcfWkb = in.readuint32();
    _s.fcPlcfSpl = in.readuint32();
    _s.lcbPlcfSpl = in.readuint32();
    _s.fcPlcftxbxTxt = in.readuint32();
    _s.lcbPlcftxbxTxt = in.readuint32();
    _s.fcPlcfFldTxbx = in.readuint32();
    _s.lcbPlcfFldTxbx = in.readuint32();
    _s.fcPlcfHdrtxbxTxt = in.readuint32();
    _s.lcbPlcfHdrtxbxTxt = in.readuint32();
    _s.fcPlcffldHdrTxbx = in.readuint32();
    _s.lcbPlcffldHdrTxbx = in.readuint32();
    _s.fcStwUser = in.readuint32();
    _s.lcbStwUser = in.readuint32();
    _s.fcSttbTtmbd = in.readuint32();
    _s.lcbSttbTtmbd = in.readuint32();
    _s.fcCookieData = in.readuint32();
    _s.lcbCookieData = in.readuint32();
    _s.fcPgdMotherOldOld = in.readuint32();
    _s.lcbPgdMotherOldOld = in.readuint32();
    _s.fcBkdMotherOldOld = in.readuint32();
    _s.lcbBkdMotherOldOld = in.readuint32();
    _s.fcPgdFtnOldOld = in.readuint32();
    _s.lcbPgdFtnOldOld = in.readuint32();
    _s.fcBkdFtnOldOld = in.readuint32();
    _s.lcbBkdFtnOldOld = in.readuint32();
    _s.fcPgdEdnOldOld = in.readuint32();
    _s.lcbPgdEdnOldOld = in.readuint32();
    _s.fcBkdEdnOldOld = in.readuint32();
    _s.lcbBkdEdnOldOld = in.readuint32();
    _s.fcSttbfIntlFld = in.readuint32();
    _s.lcbSttbfIntlFld = in.readuint32();
    _s.fcRouteSlip = in.readuint32();
    _s.lcbRouteSlip = in.readuint32();
    _s.fcSttbSavedBy = in.readuint32();
    _s.lcbSttbSavedBy = in.readuint32();
    _s.fcSttbFnm = in.readuint32();
    _s.lcbSttbFnm = in.readuint32();
    _s.fcPlfLst = in.readuint32();
    _s.lcbPlfLst = in.readuint32();
    _s.fcPlfLfo = in.readuint32();
    _s.lcbPlfLfo = in.readuint32();
    _s.fcPlcfTxbxBkd = in.readuint32();
    _s.lcbPlcfTxbxBkd = in.readuint32();
    _s.fcPlcfTxbxHdrBkd = in.readuint32();
    _s.lcbPlcfTxbxHdrBkd = in.readuint32();
    _s.fcDocUndoWord9 = in.readuint32();
    _s.lcbDocUndoWord9 = in.readuint32();
    _s.fcRgbUse = in.readuint32();
    _s.lcbRgbUse = in.readuint32();
    _s.fcUsp = in.readuint32();
    _s.lcbUsp = in.readuint32();
    _s.fcUskf = in.readuint32();
    _s.lcbUskf = in.readuint32();
    _s.fcPlcupcRgbUse = in.readuint32();
    _s.lcbPlcupcRgbUse = in.readuint32();
    _s.fcPlcupcUsp = in.readuint32();
    _s.lcbPlcupcUsp = in.readuint32();
    _s.fcSttbGlsyStyle = in.readuint32();
    _s.lcbSttbGlsyStyle = in.readuint32();
    _s.fcPlgosl = in.readuint32();
    _s.lcbPlgosl = in.readuint32();
    _s.fcPlcocx = in.readuint32();
    _s.lcbPlcocx = in.readuint32();
    _s.fcPlcfBteLvc = in.readuint32();
    _s.lcbPlcfBteLvc = in.readuint32();
    _s.dwLowDateTime = in.readuint32();
    _s.dwHighDateTime = in.readuint32();
    _s.fcPlcfLvcPre10 = in.readuint32();
    _s.lcbPlcfLvcPre10 = in.readuint32();
    _s.fcPlcfAsumy = in.readuint32();
    _s.lcbPlcfAsumy = in.readuint32();
    _s.fcPlcfGram = in.readuint32();
    _s.lcbPlcfGram = in.readuint32();
    _s.fcSttbListNames = in.readuint32();
    _s.lcbSttbListNames = in.readuint32();
    _s.fcSttbfUssr = in.readuint32();
    _s.lcbSttbfUssr = in.readuint32();
}
void parseFibRgFcLcb2000(LEInputStream& in, FibRgFcLcb2000& _s) {
    _s.fcPlcfTch = in.readuint32();
    _s.lcbPlcfTch = in.readuint32();
    _s.fcRmdThreading = in.readuint32();
    _s.lcbRmdThreading = in.readuint32();
    _s.fcMid = in.readuint32();
    _s.lcbMid = in.readuint32();
    _s.fcSttbRgtplc = in.readuint32();
    _s.lcbSttbRgtplc = in.readuint32();
    _s.fcMsoEnvelope = in.readuint32();
    _s.lcbMsoEnvelope = in.readuint32();
    _s.fcPlcfLad = in.readuint32();
    _s.lcbPlcfLad = in.readuint32();
    _s.fcRgDofr = in.readuint32();
    _s.lcbRgDofr = in.readuint32();
    _s.fcPlcosl = in.readuint32();
    _s.lcbPlcosl = in.readuint32();
    _s.fcPlcfCookieOld = in.readuint32();
    _s.lcbPlcfCookieOld = in.readuint32();
    _s.fcPgdMotherOld = in.readuint32();
    _s.lcbPgdMotherOld = in.readuint32();
    _s.fcBkdMotherOld = in.readuint32();
    _s.lcbBkdMotherOld = in.readuint32();
    _s.fcPgdFtnOld = in.readuint32();
    _s.lcbPgdFtnOld = in.readuint32();
    _s.fcBkdFtnOld = in.readuint32();
    _s.lcbBkdFtnOld = in.readuint32();
    _s.fcPgdEdnOld = in.readuint32();
    _s.lcbPgdEdnOld = in.readuint32();
    _s.fcBkdEdnOld = in.readuint32();
    _s.lcbBkdEdnOld = in.readuint32();
}
void parseFibRgFcLcb2002(LEInputStream& in, FibRgFcLcb2002& _s) {
    _s.fcUnused1 = in.readuint32();
    _s.lcbUnused1 = in.readuint32();
    _s.fcPlcfPgp = in.readuint32();
    _s.lcbPlcfPgp = in.readuint32();
    _s.fcPlcfuim = in.readuint32();
    _s.lcbPlcfuim = in.readuint32();
    _s.fcPlfguidUim = in.readuint32();
    _s.lcbPlfguidUim = in.readuint32();
    _s.fcAtrdExtra = in.readuint32();
    _s.lcbAtrdExtra = in.readuint32();
    _s.fcPlrsid = in.readuint32();
    _s.lcbPlrsid = in.readuint32();
    _s.fcSttbfBkmkFactoid = in.readuint32();
    _s.lcbSttbfBkmkFactoid = in.readuint32();
    _s.fcPlcfBkfFactoid = in.readuint32();
    _s.lcbPlcfBkfFactoid = in.readuint32();
    _s.fcPlcfcookie = in.readuint32();
    _s.lcbPlcfcookie = in.readuint32();
    _s.fcPlcfBklFactoid = in.readuint32();
    _s.lcbPlcfBklFactoid = in.readuint32();
    _s.fcFactoidData = in.readuint32();
    _s.lcbFactoidData = in.readuint32();
    _s.fcDocUndo = in.readuint32();
    _s.lcbDocUndo = in.readuint32();
    _s.fcSttbfBkmkFcc = in.readuint32();
    _s.lcbSttbfBkmkFcc = in.readuint32();
    _s.fcPlcfBkfFcc = in.readuint32();
    _s.lcbPlcfBkfFcc = in.readuint32();
    _s.fcPlcfBklFcc = in.readuint32();
    _s.lcbPlcfBklFcc = in.readuint32();
    _s.fcSttbfbkmkBPRepairs = in.readuint32();
    _s.lcbSttbfbkmkBPRepairs = in.readuint32();
    _s.fcPlcfbkfBPRepairs = in.readuint32();
    _s.lcbPlcfbkfBPRepairs = in.readuint32();
    _s.fcPlcfbklBPRepairs = in.readuint32();
    _s.lcbPlcfbklBPRepairs = in.readuint32();
    _s.fcPmsNew = in.readuint32();
    _s.lcbPmsNew = in.readuint32();
    _s.fcODSO = in.readuint32();
    _s.lcbODSO = in.readuint32();
    _s.fcPlcfpmiOldXP = in.readuint32();
    _s.lcbPlcfpmiOldXP = in.readuint32();
    _s.fcPlcfpmiNewXP = in.readuint32();
    _s.lcbPlcfpmiNewXP = in.readuint32();
    _s.fcPlcfpmiMixedXP = in.readuint32();
    _s.lcbPlcfpmiMixedXP = in.readuint32();
    _s.fcUnused2 = in.readuint32();
    _s.lcbUnused2 = in.readuint32();
    _s.fcPlcffactoid = in.readuint32();
    _s.lcbPlcffactoid = in.readuint32();
}
void parseLPStshi(LEInputStream& in, LPStshi& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.cbSthi = in.readuint16();
    _c = _s.cbSthi;
    _s.stshi.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.stshi[_i] = in.readuint8();
    }
}
void parseLPStd(LEInputStream& in, LPStd& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.cbStd = in.readuint16();
    _c = _s.cbStd;
    _s.std.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.std[_i] = in.readuint8();
    }
    if (_s.cbStd%2==1) {
        _s.padding = in.readuint8();
    }
}
void parsePlcfSed(LEInputStream& in, PlcfSed& _s) {
    int _c;
    LEInputStream::Mark _m;
    _c = 2;
    _s.aCP.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.aCP[_i] = in.readuint32();
    }
    _c = 1;
    _s.aSed.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseSed(in, _s.aSed[_i]);
    }
}
void parseSed(LEInputStream& in, Sed& _s) {
    _s.fn = in.readuint16();
    _s.fcSepx = in.readint32();
    _s.fnMpr = in.readuint16();
    _s.fcMpr = in.readuint32();
}
void parsePlcfhdd(LEInputStream& in, Plcfhdd& _s) {
    int _c;
    LEInputStream::Mark _m;
    _c = 13;
    _s.aCP.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.aCP[_i] = in.readuint32();
    }
}
void parsePlcBteChpx(LEInputStream& in, PlcBteChpx& _s) {
    int _c;
    LEInputStream::Mark _m;
    _c = 2;
    _s.aCP.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.aCP[_i] = in.readuint32();
    }
    _c = 1;
    _s.aPnBteChpx.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.aPnBteChpx[_i] = in.readuint32();
    }
}
void parsePlcfBtePapx(LEInputStream& in, PlcfBtePapx& _s) {
    int _c;
    LEInputStream::Mark _m;
    _c = 2;
    _s.aCP.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.aCP[_i] = in.readuint32();
    }
    _c = 1;
    _s.aPnBteChpx.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.aPnBteChpx[_i] = in.readuint32();
    }
}
void parseTcg(LEInputStream& in, Tcg& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.nTcgVer = in.readuint8();
    if (!(((quint8)_s.nTcgVer) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.nTcgVer) == 0 for value ") + QString::number(_s.nTcgVer) + "(" + QString::number(_s.nTcgVer,16).toUpper() + ")");
    }
    _c = 11;
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
    }
}
void parsePrcData(LEInputStream& in, PrcData& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.cbGrpprl = in.readint16();
    if (!(((qint16)_s.cbGrpprl)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint16)_s.cbGrpprl)>=0 for value ") + QString::number(_s.cbGrpprl) + "(" + QString::number(_s.cbGrpprl,16).toUpper() + ")");
    }
    if (!(((qint16)_s.cbGrpprl)<=16290)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint16)_s.cbGrpprl)<=16290 for value ") + QString::number(_s.cbGrpprl) + "(" + QString::number(_s.cbGrpprl,16).toUpper() + ")");
    }
    if (!(((qint16)_s.cbGrpprl)%2==0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint16)_s.cbGrpprl)%2==0 for value ") + QString::number(_s.cbGrpprl) + "(" + QString::number(_s.cbGrpprl,16).toUpper() + ")");
    }
    _c = _s.cbGrpprl/2;
    _s.GrpPrl.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseSprm(in, _s.GrpPrl[_i]);
    }
}
void parseSprm(LEInputStream& in, Sprm& _s) {
    _s.ispmd = in.readuint9();
    _s.fSpec = in.readbit();
    _s.sgc = in.readuint3();
    _s.spra = in.readuint3();
}
void parsePcdt(LEInputStream& in, Pcdt& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.clxt = in.readuint8();
    if (!(((quint8)_s.clxt) == 2)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.clxt) == 2 for value ") + QString::number(_s.clxt) + "(" + QString::number(_s.clxt,16).toUpper() + ")");
    }
    _s.lcb = in.readuint32();
    _c = _s.lcb/8;
    _s.PlcPcd.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parsePcd(in, _s.PlcPcd[_i]);
    }
}
void parseFCompressed(LEInputStream& in, FCompressed& _s) {
    _s.fc = in.readuint30();
    _s.fCompressed = in.readbit();
    _s.r1 = in.readbit();
}
void parsePrm0(LEInputStream& in, Prm0& _s) {
    _s.fComplex = in.readbit();
    if (!(((bool)_s.fComplex) == false)) {
        throw IncorrectValueException(in.getPosition() + QString("((bool)_s.fComplex) == false for value ") + QString::number(_s.fComplex));
    }
    _s.isprm = in.readuint7();
    _s.val = in.readuint8();
}
void parsePrm1(LEInputStream& in, Prm1& _s) {
    _s.fComplex = in.readbit();
    if (!(((bool)_s.fComplex) == true)) {
        throw IncorrectValueException(in.getPosition() + QString("((bool)_s.fComplex) == true for value ") + QString::number(_s.fComplex));
    }
    _s.igrpprl = in.readuint15();
}
void parseSttbfFfn(LEInputStream& in, SttbfFfn& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.cData = in.readuint16();
    _s.cbExtra = in.readuint16();
    if (!(((quint16)_s.cbExtra) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.cbExtra) == 0 for value ") + QString::number(_s.cbExtra) + "(" + QString::number(_s.cbExtra,16).toUpper() + ")");
    }
    _c = _s.cData;
    _s.data.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseSttbfFfnEntry(in, _s.data[_i]);
    }
}
void parseSttbfFfnEntry(LEInputStream& in, SttbfFfnEntry& _s) {
    int _c;
    LEInputStream::Mark _m;
    _s.cchData = in.readuint8();
    _c = _s.cchData;
    _s.Data.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.Data[_i] = in.readuint8();
    }
}
void parsePicturesStream(LEInputStream& in, PicturesStream& _s) {
    parseOfficeArtBStoreDelay(in, _s.anon1);
}
void parseOfficeArtMetafileHeader(LEInputStream& in, OfficeArtMetafileHeader& _s) {
    _s.cbSize = in.readuint32();
    parseRECT(in, _s.rcBounds);
    parsePOINT(in, _s.ptSize);
    _s.cbsave = in.readuint32();
    _s.compression = in.readuint8();
    _s.filter = in.readuint8();
}
void parseNormalViewSetInfoAtom(LEInputStream& in, NormalViewSetInfoAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x415)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x415 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x14)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x14 for value ") + _s.rh.toString());
    }
    parseRatioStruct(in, _s.leftPortion);
    parseRatioStruct(in, _s.topPortion);
    _s.vertBarState = in.readuint8();
    _s.horizBarState = in.readuint8();
    _s.fPreferSingleSet = in.readuint8();
    if (!(((quint8)_s.fPreferSingleSet) == 0 || ((quint8)_s.fPreferSingleSet) == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.fPreferSingleSet) == 0 || ((quint8)_s.fPreferSingleSet) == 1 for value ") + QString::number(_s.fPreferSingleSet) + "(" + QString::number(_s.fPreferSingleSet,16).toUpper() + ")");
    }
    _s.fHideThumbnails = in.readbit();
    _s.fBarSnapped = in.readbit();
    _s.reserved = in.readuint6();
    if (!(((quint8)_s.reserved) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.reserved) == 0 for value ") + QString::number(_s.reserved) + "(" + QString::number(_s.reserved,16).toUpper() + ")");
    }
}
void parseMasterPersistAtom(LEInputStream& in, MasterPersistAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x3F3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x3F3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x14)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x14 for value ") + _s.rh.toString());
    }
    parsePersistIdRef(in, _s.persistIdRef);
    _s.reserved1 = in.readuint2();
    if (!(((quint8)_s.reserved1) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.reserved1) == 0 for value ") + QString::number(_s.reserved1) + "(" + QString::number(_s.reserved1,16).toUpper() + ")");
    }
    _s.fNonOutLineData = in.readbit();
    _s.reserved2 = in.readuint5();
    if (!(((quint8)_s.reserved2) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.reserved2) == 0 for value ") + QString::number(_s.reserved2) + "(" + QString::number(_s.reserved2,16).toUpper() + ")");
    }
    _s.reserved3 = in.readuint8();
    if (!(((quint8)_s.reserved3) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.reserved3) == 0 for value ") + QString::number(_s.reserved3) + "(" + QString::number(_s.reserved3,16).toUpper() + ")");
    }
    _s.reserved4 = in.readuint16();
    if (!(((quint16)_s.reserved4) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.reserved4) == 0 for value ") + QString::number(_s.reserved4) + "(" + QString::number(_s.reserved4,16).toUpper() + ")");
    }
    _s.reserved5 = in.readuint32();
    if (!(((quint32)_s.reserved5) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.reserved5) == 0 for value ") + QString::number(_s.reserved5) + "(" + QString::number(_s.reserved5,16).toUpper() + ")");
    }
    _s.masterId = in.readuint32();
    _s.reserved6 = in.readuint32();
    if (!(((quint32)_s.reserved6) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.reserved6) == 0 for value ") + QString::number(_s.reserved6) + "(" + QString::number(_s.reserved6,16).toUpper() + ")");
    }
}
void parseSlidePersistAtom(LEInputStream& in, SlidePersistAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x3F3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x3F3 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x14)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x14 for value ") + _s.rh.toString());
    }
    parsePersistIdRef(in, _s.persistIdRef);
    _s.reserved1 = in.readbit();
    if (!(((bool)_s.reserved1) == false)) {
        throw IncorrectValueException(in.getPosition() + QString("((bool)_s.reserved1) == false for value ") + QString::number(_s.reserved1));
    }
    _s.fShouldCollapse = in.readbit();
    _s.fNonOutlineData = in.readbit();
    _s.reserved2 = in.readuint5();
    if (!(((quint8)_s.reserved2) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.reserved2) == 0 for value ") + QString::number(_s.reserved2) + "(" + QString::number(_s.reserved2,16).toUpper() + ")");
    }
    _s.reserved3 = in.readuint8();
    if (!(((quint8)_s.reserved3) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.reserved3) == 0 for value ") + QString::number(_s.reserved3) + "(" + QString::number(_s.reserved3,16).toUpper() + ")");
    }
    _s.reserved4 = in.readuint16();
    if (!(((quint16)_s.reserved4) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.reserved4) == 0 for value ") + QString::number(_s.reserved4) + "(" + QString::number(_s.reserved4,16).toUpper() + ")");
    }
    _s.cTexts = in.readint32();
    if (!(((qint32)_s.cTexts)>=0)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.cTexts)>=0 for value ") + QString::number(_s.cTexts) + "(" + QString::number(_s.cTexts,16).toUpper() + ")");
    }
    if (!(((qint32)_s.cTexts)<=8)) {
        throw IncorrectValueException(in.getPosition() + QString("((qint32)_s.cTexts)<=8 for value ") + QString::number(_s.cTexts) + "(" + QString::number(_s.cTexts,16).toUpper() + ")");
    }
    parseSlideId(in, _s.slideId);
    _s.reserved5 = in.readuint32();
    if (!(((quint32)_s.reserved5) == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.reserved5) == 0 for value ") + QString::number(_s.reserved5) + "(" + QString::number(_s.reserved5,16).toUpper() + ")");
    }
}
void parseTextRuler(LEInputStream& in, TextRuler& _s) {
    _s.fDefaultTabSize = in.readbit();
    _s.fCLevels = in.readbit();
    _s.fTabStops = in.readbit();
    _s.fLeftMargin1 = in.readbit();
    _s.fLeftMargin2 = in.readbit();
    _s.fLeftMargin3 = in.readbit();
    _s.fLeftMargin4 = in.readbit();
    _s.fLeftMargin5 = in.readbit();
    _s.fIndent1 = in.readbit();
    _s.fIndent2 = in.readbit();
    _s.fIndent3 = in.readbit();
    _s.fIndent4 = in.readbit();
    _s.fIndent5 = in.readbit();
    _s.reserved1 = in.readuint3();
    _s.reserved2 = in.readuint16();
    if (_s.fCLevels) {
        _s.cLevels = in.readint16();
    }
    if (_s.fDefaultTabSize) {
        _s.defaultTabSize = in.readuint16();
    }
    if (_s.fTabStops) {
        parseTabStops(in, _s.tabs);
    }
    if (_s.fLeftMargin1) {
        _s.leftMargin1 = in.readuint16();
    }
    if (_s.fIndent1) {
        _s.indent1 = in.readuint16();
    }
    if (_s.fLeftMargin2) {
        _s.leftMargin2 = in.readuint16();
    }
    if (_s.fIndent2) {
        _s.indent2 = in.readuint16();
    }
    if (_s.fLeftMargin3) {
        _s.leftMargin3 = in.readuint16();
    }
    if (_s.fIndent3) {
        _s.indent3 = in.readuint16();
    }
    if (_s.fLeftMargin4) {
        _s.leftMargin4 = in.readuint16();
    }
    if (_s.fIndent4) {
        _s.indent4 = in.readuint16();
    }
    if (_s.fLeftMargin5) {
        _s.leftMargin5 = in.readuint16();
    }
    if (_s.fIndent5) {
        _s.indent5 = in.readuint16();
    }
}
void parseTextPFException(LEInputStream& in, TextPFException& _s) {
    parsePFMasks(in, _s.masks);
    if (!(_s.masks.bulletBlip == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.bulletBlip == false for value ") + _s.masks.toString());
    }
    if (!(_s.masks.bulletHasScheme == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.bulletHasScheme == false for value ") + _s.masks.toString());
    }
    if (!(_s.masks.bulletScheme == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.bulletScheme == false for value ") + _s.masks.toString());
    }
    if (_s.masks.hasBullet||_s.masks.bulletHasFont||_s.masks.bulletHasColor||_s.masks.bulletHasSize) {
        parseBulletFlags(in, _s.bulletFlags);
    }
    if (_s.masks.bulletChar) {
        _s.bulletChar = in.readint16();
        if (!(((qint16)_s.bulletChar) != 0)) {
            throw IncorrectValueException(in.getPosition() + QString("((qint16)_s.bulletChar) != 0 for value ") + QString::number(_s.bulletChar) + "(" + QString::number(_s.bulletChar,16).toUpper() + ")");
        }
    }
    if (_s.masks.bulletFont) {
        _s.bulletFontRef = in.readuint16();
    }
    if (_s.masks.bulletSize) {
        _s.bulletSize = in.readuint16();
    }
    if (_s.masks.bulletColor) {
        _s.bulletColor = in.readuint32();
    }
    if (_s.masks.align) {
        _s.textAlignment = in.readuint16();
    }
    if (_s.masks.lineSpacing) {
        _s.lineSpacing = in.readuint16();
    }
    if (_s.masks.spaceBefore) {
        _s.spaceBefore = in.readuint16();
    }
    if (_s.masks.spaceAfter) {
        _s.spaceAfter = in.readuint16();
    }
    if (_s.masks.leftMargin) {
        _s.leftMargin = in.readuint16();
    }
    if (_s.masks.indent) {
        _s.indent = in.readuint16();
    }
    if (_s.masks.defaultTabSize) {
        _s.defaultTabSize = in.readuint16();
    }
    if (_s.masks.tabStops) {
        parseTabStops(in, _s.tabStops);
    }
    if (_s.masks.fontAlign) {
        _s.fontAlign = in.readuint16();
    }
    if (_s.masks.charWrap||_s.masks.wordWrap||_s.masks.overflow) {
        _s.wrapFlags = in.readuint16();
    }
    if (_s.masks.textDirection) {
        _s.textDirection = in.readuint16();
    }
}
void parseTextCFException(LEInputStream& in, TextCFException& _s) {
    parseCFMasks(in, _s.masks);
    if (!(_s.masks.pp10ext == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.pp10ext == false for value ") + _s.masks.toString());
    }
    if (!(_s.masks.newEATypeface == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.newEATypeface == false for value ") + _s.masks.toString());
    }
    if (!(_s.masks.csTypeface == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.csTypeface == false for value ") + _s.masks.toString());
    }
    if (!(_s.masks.pp11ext == false)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.masks.pp11ext == false for value ") + _s.masks.toString());
    }
    if (_s.masks.bold || _s.masks.italic || _s.masks.underline || _s.masks.shadow || _s.masks.fehint || _s.masks.kumi || _s.masks.emboss || _s.masks.fHasStyle != 0) {
        parseCFStyle(in, _s.fontStyle);
    }
    if (_s.masks.typeface) {
        _s.fontRef = in.readuint16();
    }
    if (_s.masks.oldEATypeface) {
        _s.oldEAFontRef = in.readuint16();
    }
    if (_s.masks.ansiTypeface) {
        _s.ansiFontRef = in.readuint16();
    }
    if (_s.masks.symbolTypeface) {
        _s.symbolFontRef = in.readuint16();
    }
    if (_s.masks.size) {
        _s.fontSize = in.readuint16();
        if (!(((quint16)_s.fontSize)>=1)) {
            throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.fontSize)>=1 for value ") + QString::number(_s.fontSize) + "(" + QString::number(_s.fontSize,16).toUpper() + ")");
        }
        if (!(((quint16)_s.fontSize)<=4000)) {
            throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.fontSize)<=4000 for value ") + QString::number(_s.fontSize) + "(" + QString::number(_s.fontSize,16).toUpper() + ")");
        }
    }
    if (_s.masks.color) {
        _s.color = in.readuint32();
    }
    if (_s.masks.position) {
        _s.position = in.readuint16();
        if (!(((quint16)_s.position)>=-100)) {
            throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.position)>=-100 for value ") + QString::number(_s.position) + "(" + QString::number(_s.position,16).toUpper() + ")");
        }
        if (!(((quint16)_s.position)<=100)) {
            throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.position)<=100 for value ") + QString::number(_s.position) + "(" + QString::number(_s.position,16).toUpper() + ")");
        }
    }
}
void parseKinsokuContainer(LEInputStream& in, KinsokuContainer& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FC8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FC8 for value ") + _s.rh.toString());
    }
    parseKinsokuAtom(in, _s.kinsokuAtom);
}
void parseTextMasterStyleLevel(LEInputStream& in, TextMasterStyleLevel& _s) {
    parseTextPFException(in, _s.pf);
    parseTextCFException(in, _s.cf);
}
void parseDocumentAtom(LEInputStream& in, DocumentAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03E9)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03E9 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x28)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x28 for value ") + _s.rh.toString());
    }
    parsePointStruct(in, _s.slideSize);
    parsePointStruct(in, _s.notesSize);
    parseRatioStruct(in, _s.serverZoom);
    if (!(_s.serverZoom.numer*_s.serverZoom.denom > 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.serverZoom.numer*_s.serverZoom.denom > 0 for value ") + _s.serverZoom.toString());
    }
    parsePersistIdRef(in, _s.notesMasterPersistIdRef);
    parsePersistIdRef(in, _s.handoutMasterPersistIdRef);
    _s.firstSlideNumber = in.readuint16();
    if (!(((quint16)_s.firstSlideNumber)<10000)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.firstSlideNumber)<10000 for value ") + QString::number(_s.firstSlideNumber) + "(" + QString::number(_s.firstSlideNumber,16).toUpper() + ")");
    }
    _s.slideSizeType = in.readuint16();
    if (!(((quint16)_s.slideSizeType) == 0 || ((quint16)_s.slideSizeType) == 1 || ((quint16)_s.slideSizeType) == 2 || ((quint16)_s.slideSizeType) == 3 || ((quint16)_s.slideSizeType) == 4 || ((quint16)_s.slideSizeType) == 5 || ((quint16)_s.slideSizeType) == 6)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.slideSizeType) == 0 || ((quint16)_s.slideSizeType) == 1 || ((quint16)_s.slideSizeType) == 2 || ((quint16)_s.slideSizeType) == 3 || ((quint16)_s.slideSizeType) == 4 || ((quint16)_s.slideSizeType) == 5 || ((quint16)_s.slideSizeType) == 6 for value ") + QString::number(_s.slideSizeType) + "(" + QString::number(_s.slideSizeType,16).toUpper() + ")");
    }
    _s.fSaveWithFonts = in.readuint8();
    _s.fOmitTitlePlace = in.readuint8();
    _s.fRightToLeft = in.readuint8();
    _s.fShowComments = in.readuint8();
}
void parseExObjListContainer(LEInputStream& in, ExObjListContainer& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0409)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0409 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen>=12)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen>=12 for value ") + _s.rh.toString());
    }
    parseExObjListAtom(in, _s.exObjListAtom);
    _c = _s.rh.recLen-12;
    _s.rgChildRec.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseExObjListSubContainer(in, _s.rgChildRec[_i]);
    }
}
void parseExOleLinkContainer(LEInputStream& in, ExOleLinkContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FCE)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FCE for value ") + _s.rh.toString());
    }
    parseExOleLinkAtom(in, _s.exOleLinkAtom);
    parseExOleObjAtom(in, _s.exOleObjAtom);
    _m = in.setMark();
    try {
        MenuNameAtom _t;
        parseMenuNameAtom(in, _t);
        _s.menuNameAtom = QSharedPointer<MenuNameAtom>(new MenuNameAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        ProgIDAtom _t;
        parseProgIDAtom(in, _t);
        _s.progIdAtom = QSharedPointer<ProgIDAtom>(new ProgIDAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        ClipboardNameAtom _t;
        parseClipboardNameAtom(in, _t);
        _s.clipboardNameAtom = QSharedPointer<ClipboardNameAtom>(new ClipboardNameAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        MetafileBlob _t;
        parseMetafileBlob(in, _t);
        _s.metafile = QSharedPointer<MetafileBlob>(new MetafileBlob(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
}
void parseExOleEmbedContainer(LEInputStream& in, ExOleEmbedContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FCC)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FCC for value ") + _s.rh.toString());
    }
    parseExOleEmbedAtom(in, _s.exOleEmbedAtom);
    parseExOleObjAtom(in, _s.exOleObjAtom);
    _m = in.setMark();
    try {
        MenuNameAtom _t;
        parseMenuNameAtom(in, _t);
        _s.menuNameAtom = QSharedPointer<MenuNameAtom>(new MenuNameAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        ProgIDAtom _t;
        parseProgIDAtom(in, _t);
        _s.progIdAtom = QSharedPointer<ProgIDAtom>(new ProgIDAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        ClipboardNameAtom _t;
        parseClipboardNameAtom(in, _t);
        _s.clipboardNameAtom = QSharedPointer<ClipboardNameAtom>(new ClipboardNameAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        MetafileBlob _t;
        parseMetafileBlob(in, _t);
        _s.metafile = QSharedPointer<MetafileBlob>(new MetafileBlob(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
}
void parseOfficeArtFDGGBlock(LEInputStream& in, OfficeArtFDGGBlock& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F006)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F006 for value ") + _s.rh.toString());
    }
    parseOfficeArtFDGG(in, _s.head);
    _c = _s.head.cidcl-1;
    _s.Rgidcl.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseOfficeArtIDCL(in, _s.Rgidcl[_i]);
    }
}
void parseOfficeArtClientAnchor(LEInputStream& in, OfficeArtClientAnchor& _s) {
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF010)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF010 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x8 || _s.rh.recLen == 0x10)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x8 || _s.rh.recLen == 0x10 for value ") + _s.rh.toString());
    }
    if (_s.rh.recLen==0x8) {
        parseSmallRectStruct(in, _s.rect1);
    }
    if (_s.rh.recLen==0x10) {
        parseRectStruct(in, _s.rect2);
    }
}
void parseOfficeArtClientData(LEInputStream& in, OfficeArtClientData& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF011)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF011 for value ") + _s.rh.toString());
    }
    _m = in.setMark();
    try {
        ShapeFlagsAtom _t;
        parseShapeFlagsAtom(in, _t);
        _s.shapeFlagsAtom = QSharedPointer<ShapeFlagsAtom>(new ShapeFlagsAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        ShapeFlags10Atom _t;
        parseShapeFlags10Atom(in, _t);
        _s.shapeFlags10Atom = QSharedPointer<ShapeFlags10Atom>(new ShapeFlags10Atom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        ExObjRefAtom _t;
        parseExObjRefAtom(in, _t);
        _s.exObjRefAtom = QSharedPointer<ExObjRefAtom>(new ExObjRefAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        AnimationInfoContainer _t;
        parseAnimationInfoContainer(in, _t);
        _s.animationInfo = QSharedPointer<AnimationInfoContainer>(new AnimationInfoContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        MouseClickInteractiveInfoContainer _t;
        parseMouseClickInteractiveInfoContainer(in, _t);
        _s.mouseClickInteractiveInfo = QSharedPointer<MouseClickInteractiveInfoContainer>(new MouseClickInteractiveInfoContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        MouseOverInteractiveInfoContainer _t;
        parseMouseOverInteractiveInfoContainer(in, _t);
        _s.mouseOverInteractiveInfo = QSharedPointer<MouseOverInteractiveInfoContainer>(new MouseOverInteractiveInfoContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        PlaceholderAtom _t;
        parsePlaceholderAtom(in, _t);
        _s.placeholderAtom = QSharedPointer<PlaceholderAtom>(new PlaceholderAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        RecolorInfoAtom _t;
        parseRecolorInfoAtom(in, _t);
        _s.recolorInfoAtom = QSharedPointer<RecolorInfoAtom>(new RecolorInfoAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.rgShapeClientRoundtripData.append(ShapeClientRoundtripDataSubcontainerOrAtom());
            parseShapeClientRoundtripDataSubcontainerOrAtom(in, _s.rgShapeClientRoundtripData.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
}
void parseOfficeArtFOPTE(LEInputStream& in, OfficeArtFOPTE& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtFOPTEOPID(in, _s.opid);
    _s.op = in.readint32();
    _c = (_s.opid.fComplex)?_s.op:0;
    _s.complexData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.complexData[_i] = in.readuint8();
    }
}
void parseFib(LEInputStream& in, Fib& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseFibBase(in, _s.base);
    _s.csw = in.readuint16();
    if (!(((quint16)_s.csw) == 14)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.csw) == 14 for value ") + QString::number(_s.csw) + "(" + QString::number(_s.csw,16).toUpper() + ")");
    }
    parseFibRgW97(in, _s.fibRgW);
    _s.cslw = in.readuint16();
    if (!(((quint16)_s.cslw) == 22)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.cslw) == 22 for value ") + QString::number(_s.cslw) + "(" + QString::number(_s.cslw,16).toUpper() + ")");
    }
    parseFibRgLw97(in, _s.fibRgLw);
    _s.cbRgFcLcb = in.readuint16();
    if (!(((quint16)_s.cbRgFcLcb) == 0x5D || ((quint16)_s.cbRgFcLcb) == 0x6C || ((quint16)_s.cbRgFcLcb) == 0x88 || ((quint16)_s.cbRgFcLcb) == 0xA4 || ((quint16)_s.cbRgFcLcb) == 0xB7)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.cbRgFcLcb) == 0x5D || ((quint16)_s.cbRgFcLcb) == 0x6C || ((quint16)_s.cbRgFcLcb) == 0x88 || ((quint16)_s.cbRgFcLcb) == 0xA4 || ((quint16)_s.cbRgFcLcb) == 0xB7 for value ") + QString::number(_s.cbRgFcLcb) + "(" + QString::number(_s.cbRgFcLcb,16).toUpper() + ")");
    }
    parseFibRgFcLcb97(in, _s.fibRgFcLcbBlob);
    if (_s.cbRgFcLcb>=0x6C) {
        parseFibRgFcLcb2000(in, _s.fibRgFcLcbBlob2);
    }
    if (_s.cbRgFcLcb>=0x88) {
        parseFibRgFcLcb2002(in, _s.fibRgFcLcbBlob3);
    }
    _s.cswNew = in.readuint16();
    if (!(((quint16)_s.cswNew) == 0 || ((quint16)_s.cswNew) == 2 || ((quint16)_s.cswNew) == 5)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint16)_s.cswNew) == 0 || ((quint16)_s.cswNew) == 2 || ((quint16)_s.cswNew) == 5 for value ") + QString::number(_s.cswNew) + "(" + QString::number(_s.cswNew,16).toUpper() + ")");
    }
    _c = 2*_s.cswNew;
    _s.fibRgCswNew.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.fibRgCswNew[_i] = in.readuint8();
    }
    _c = _s.fibRgLw.cbMac-156-8*_s.cbRgFcLcb-2*_s.cswNew;
    _s.trail.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.trail[_i] = in.readuint8();
    }
}
void parseSTSH(LEInputStream& in, STSH& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseLPStshi(in, _s.lpstshi);
    _c = 20;
    _s.rglpstd.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        parseLPStd(in, _s.rglpstd[_i]);
    }
}
void parseClx(LEInputStream& in, Clx& _s) {
    LEInputStream::Mark _m;
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.RgPrc.append(Pcr());
            parsePcr(in, _s.RgPrc.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
    parsePcdt(in, _s.pcdt);
}
void parsePcr(LEInputStream& in, Pcr& _s) {
    _s.clxt = in.readuint8();
    if (!(((quint8)_s.clxt) == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint8)_s.clxt) == 1 for value ") + QString::number(_s.clxt) + "(" + QString::number(_s.clxt,16).toUpper() + ")");
    }
    parsePrcData(in, _s.prcData);
}
void parsePrm(LEInputStream& in, Prm& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        Prm0 _t;
        parsePrm0(in, _t);
        _s.prm.prm0 = QSharedPointer<Prm0>(new Prm0(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
        Prm1 _t;
        parsePrm1(in, _t);
        _s.prm.prm1 = QSharedPointer<Prm1>(new Prm1(_t));
    }
}
void parseOfficeArtBlipEMF(LEInputStream& in, OfficeArtBlipEMF& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x3D4 || _s.rh.recInstance == 0x3D5)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x3D4 || _s.rh.recInstance == 0x3D5 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF01A)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF01A for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x3D5) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    parseOfficeArtMetafileHeader(in, _s.metafileHeader);
    _c = _s.rh.recLen-((_s.rh.recInstance==0x3D4)?50:66);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseOfficeArtBlipWMF(LEInputStream& in, OfficeArtBlipWMF& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x216 || _s.rh.recInstance == 0x217)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x216 || _s.rh.recInstance == 0x217 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF01B)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF01B for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x217) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    parseOfficeArtMetafileHeader(in, _s.metafileHeader);
    _c = _s.rh.recLen-((_s.rh.recInstance==0x216)?50:66);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseOfficeArtBlipPICT(LEInputStream& in, OfficeArtBlipPICT& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x542 || _s.rh.recInstance == 0x543)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x542 || _s.rh.recInstance == 0x543 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF01C)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF01C for value ") + _s.rh.toString());
    }
    _c = 16;
    _s.rgbUid1.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid1[_i] = in.readuint8();
    }
    if (_s.rh.recInstance == 0x543) {
        _c = 16;
        _s.rgbUid2.resize(_c);
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid2[_i] = in.readuint8();
        }
    }
    parseOfficeArtMetafileHeader(in, _s.metafileHeader);
    _c = _s.rh.recLen-((_s.rh.recInstance==0x542)?50:66);
    _s.BLIPFileData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.BLIPFileData[_i] = in.readuint8();
    }
}
void parseOfficeArtBlip(LEInputStream& in, OfficeArtBlip& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        OfficeArtBlipEMF _t;
        parseOfficeArtBlipEMF(in, _t);
        _s.anon.officeartblipemf = QSharedPointer<OfficeArtBlipEMF>(new OfficeArtBlipEMF(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
    try {
        OfficeArtBlipWMF _t;
        parseOfficeArtBlipWMF(in, _t);
        _s.anon.officeartblipwmf = QSharedPointer<OfficeArtBlipWMF>(new OfficeArtBlipWMF(_t));
    } catch (IncorrectValueException _xx) {
        in.rewind(_m);
    try {
        OfficeArtBlipPICT _t;
        parseOfficeArtBlipPICT(in, _t);
        _s.anon.officeartblippict = QSharedPointer<OfficeArtBlipPICT>(new OfficeArtBlipPICT(_t));
    } catch (IncorrectValueException _xxx) {
        in.rewind(_m);
    try {
        OfficeArtBlipJPEG _t;
        parseOfficeArtBlipJPEG(in, _t);
        _s.anon.officeartblipjpeg = QSharedPointer<OfficeArtBlipJPEG>(new OfficeArtBlipJPEG(_t));
    } catch (IncorrectValueException _xxxx) {
        in.rewind(_m);
    try {
        OfficeArtBlipPNG _t;
        parseOfficeArtBlipPNG(in, _t);
        _s.anon.officeartblippng = QSharedPointer<OfficeArtBlipPNG>(new OfficeArtBlipPNG(_t));
    } catch (IncorrectValueException _xxxxx) {
        in.rewind(_m);
    try {
        OfficeArtBlipDIB _t;
        parseOfficeArtBlipDIB(in, _t);
        _s.anon.officeartblipdib = QSharedPointer<OfficeArtBlipDIB>(new OfficeArtBlipDIB(_t));
    } catch (IncorrectValueException _xxxxxx) {
        in.rewind(_m);
        OfficeArtBlipTIFF _t;
        parseOfficeArtBlipTIFF(in, _t);
        _s.anon.officeartbliptiff = QSharedPointer<OfficeArtBlipTIFF>(new OfficeArtBlipTIFF(_t));
    }}}}}}
}
void parseNormalViewSetInfoContainer(LEInputStream& in, NormalViewSetInfoContainer& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 1)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 1 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x414)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x414 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recLen == 0x1C)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recLen == 0x1C for value ") + _s.rh.toString());
    }
    parseNormalViewSetInfoAtom(in, _s.normalViewSetInfoAtom);
}
void parseSlideListWithTextSubContainerOrAtom(LEInputStream& in, SlideListWithTextSubContainerOrAtom& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        SlidePersistAtom _t;
        parseSlidePersistAtom(in, _t);
        _s.anon.slidepersistatom = QSharedPointer<SlidePersistAtom>(new SlidePersistAtom(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
    try {
        TextHeaderAtom _t;
        parseTextHeaderAtom(in, _t);
        _s.anon.textheaderatom = QSharedPointer<TextHeaderAtom>(new TextHeaderAtom(_t));
    } catch (IncorrectValueException _xx) {
        in.rewind(_m);
    try {
        TextCharsAtom _t;
        parseTextCharsAtom(in, _t);
        _s.anon.textcharsatom = QSharedPointer<TextCharsAtom>(new TextCharsAtom(_t));
    } catch (IncorrectValueException _xxx) {
        in.rewind(_m);
    try {
        TextBytesAtom _t;
        parseTextBytesAtom(in, _t);
        _s.anon.textbytesatom = QSharedPointer<TextBytesAtom>(new TextBytesAtom(_t));
    } catch (IncorrectValueException _xxxx) {
        in.rewind(_m);
    try {
        StyleTextPropAtom _t;
        parseStyleTextPropAtom(in, _t);
        _s.anon.styletextpropatom = QSharedPointer<StyleTextPropAtom>(new StyleTextPropAtom(_t));
    } catch (IncorrectValueException _xxxxx) {
        in.rewind(_m);
    try {
        SlideNumberMCAtom _t;
        parseSlideNumberMCAtom(in, _t);
        _s.anon.slidenumbermcatom = QSharedPointer<SlideNumberMCAtom>(new SlideNumberMCAtom(_t));
    } catch (IncorrectValueException _xxxxxx) {
        in.rewind(_m);
    try {
        DateTimeMCAtom _t;
        parseDateTimeMCAtom(in, _t);
        _s.anon.datetimemcatom = QSharedPointer<DateTimeMCAtom>(new DateTimeMCAtom(_t));
    } catch (IncorrectValueException _xxxxxxx) {
        in.rewind(_m);
    try {
        GenericDateMCAtom _t;
        parseGenericDateMCAtom(in, _t);
        _s.anon.genericdatemcatom = QSharedPointer<GenericDateMCAtom>(new GenericDateMCAtom(_t));
    } catch (IncorrectValueException _xxxxxxxx) {
        in.rewind(_m);
    try {
        HeaderMCAtom _t;
        parseHeaderMCAtom(in, _t);
        _s.anon.headermcatom = QSharedPointer<HeaderMCAtom>(new HeaderMCAtom(_t));
    } catch (IncorrectValueException _xxxxxxxxx) {
        in.rewind(_m);
    try {
        FooterMCAtom _t;
        parseFooterMCAtom(in, _t);
        _s.anon.footermcatom = QSharedPointer<FooterMCAtom>(new FooterMCAtom(_t));
    } catch (IncorrectValueException _xxxxxxxxxx) {
        in.rewind(_m);
    try {
        RTFDateTimeMCAtom _t;
        parseRTFDateTimeMCAtom(in, _t);
        _s.anon.rtfdatetimemcatom = QSharedPointer<RTFDateTimeMCAtom>(new RTFDateTimeMCAtom(_t));
    } catch (IncorrectValueException _xxxxxxxxxxx) {
        in.rewind(_m);
    try {
        TextBookmarkAtom _t;
        parseTextBookmarkAtom(in, _t);
        _s.anon.textbookmarkatom = QSharedPointer<TextBookmarkAtom>(new TextBookmarkAtom(_t));
    } catch (IncorrectValueException _xxxxxxxxxxxx) {
        in.rewind(_m);
    try {
        TextSpecialInfoAtom _t;
        parseTextSpecialInfoAtom(in, _t);
        _s.anon.textspecialinfoatom = QSharedPointer<TextSpecialInfoAtom>(new TextSpecialInfoAtom(_t));
    } catch (IncorrectValueException _xxxxxxxxxxxxx) {
        in.rewind(_m);
    try {
        InteractiveInfoInstance _t;
        parseInteractiveInfoInstance(in, _t);
        _s.anon.interactiveinfoinstance = QSharedPointer<InteractiveInfoInstance>(new InteractiveInfoInstance(_t));
    } catch (IncorrectValueException _xxxxxxxxxxxxxx) {
        in.rewind(_m);
        TextInteractiveInfoInstance _t;
        parseTextInteractiveInfoInstance(in, _t);
        _s.anon.textinteractiveinfoinstance = QSharedPointer<TextInteractiveInfoInstance>(new TextInteractiveInfoInstance(_t));
    }}}}}}}}}}}}}}
}
void parseTextCFExceptionAtom(LEInputStream& in, TextCFExceptionAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FA4)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FA4 for value ") + _s.rh.toString());
    }
    parseTextCFException(in, _s.cf);
}
void parseDefaultRulerAtom(LEInputStream& in, DefaultRulerAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FAB)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FAB for value ") + _s.rh.toString());
    }
    parseTextRuler(in, _s.defaultTextRuler);
    if (!(_s.defaultTextRuler.fDefaultTabSize == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fDefaultTabSize == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fCLevels == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fCLevels == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fTabStops == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fTabStops == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fLeftMargin1 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fLeftMargin1 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fLeftMargin2 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fLeftMargin2 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fLeftMargin3 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fLeftMargin3 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fLeftMargin4 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fLeftMargin4 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fIndent1 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fIndent1 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fIndent2 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fIndent2 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fIndent3 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fIndent3 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fIndent4 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fIndent4 == true for value ") + _s.defaultTextRuler.toString());
    }
    if (!(_s.defaultTextRuler.fIndent5 == true)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.defaultTextRuler.fIndent5 == true for value ") + _s.defaultTextRuler.toString());
    }
}
void parseTextPFExceptionAtom(LEInputStream& in, TextPFExceptionAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FA5)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FA5 for value ") + _s.rh.toString());
    }
    _s.reserved = in.readuint16();
    parseTextPFException(in, _s.pf);
}
void parseTextMasterStyleAtom(LEInputStream& in, TextMasterStyleAtom& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 8 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0FA3)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0FA3 for value ") + _s.rh.toString());
    }
    _s.cLevels = in.readuint16();
    if (_s.rh.recInstance>=5) {
        _s.lstLvl1level = in.readuint16();
    }
    if (_s.cLevels>0) {
        parseTextMasterStyleLevel(in, _s.lstLvl1);
    }
    if (_s.rh.recInstance>=5) {
        _s.lstLvl2level = in.readuint16();
    }
    if (_s.cLevels>1) {
        parseTextMasterStyleLevel(in, _s.lstLvl2);
    }
    if (_s.rh.recInstance>=5) {
        _s.lstLvl3level = in.readuint16();
    }
    if (_s.cLevels>2) {
        parseTextMasterStyleLevel(in, _s.lstLvl3);
    }
    if (_s.rh.recInstance>=5) {
        _s.lstLvl4level = in.readuint16();
    }
    if (_s.cLevels>3) {
        parseTextMasterStyleLevel(in, _s.lstLvl4);
    }
    if (_s.rh.recInstance>=5) {
        _s.lstLvl5level = in.readuint16();
    }
    if (_s.cLevels>4) {
        parseTextMasterStyleLevel(in, _s.lstLvl5);
    }
}
void parseExObjListSubContainer(LEInputStream& in, ExObjListSubContainer& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        ExOleLinkContainer _t;
        parseExOleLinkContainer(in, _t);
        _s.anon.exolelinkcontainer = QSharedPointer<ExOleLinkContainer>(new ExOleLinkContainer(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
        ExOleEmbedContainer _t;
        parseExOleEmbedContainer(in, _t);
        _s.anon.exoleembedcontainer = QSharedPointer<ExOleEmbedContainer>(new ExOleEmbedContainer(_t));
    }
}
void parseOfficeArtDggContainer(LEInputStream& in, OfficeArtDggContainer& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F000)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F000 for value ") + _s.rh.toString());
    }
    parseOfficeArtFDGGBlock(in, _s.drawingGroup);
    _m = in.setMark();
    try {
        OfficeArtBStoreContainer _t;
        parseOfficeArtBStoreContainer(in, _t);
        _s.blipStore = QSharedPointer<OfficeArtBStoreContainer>(new OfficeArtBStoreContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseOfficeArtFOPT(in, _s.drawingPrimaryOptions);
    _m = in.setMark();
    try {
        OfficeArtTertiaryFOPT _t;
        parseOfficeArtTertiaryFOPT(in, _t);
        _s.drawingTertiaryOptions = QSharedPointer<OfficeArtTertiaryFOPT>(new OfficeArtTertiaryFOPT(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtColorMRUContainer _t;
        parseOfficeArtColorMRUContainer(in, _t);
        _s.colorMRU = QSharedPointer<OfficeArtColorMRUContainer>(new OfficeArtColorMRUContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseOfficeArtSplitMenuColorContainer(in, _s.splitColors);
}
void parseOfficeArtSpContainer(LEInputStream& in, OfficeArtSpContainer& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x0F004)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x0F004 for value ") + _s.rh.toString());
    }
    _m = in.setMark();
    try {
        OfficeArtFSPGR _t;
        parseOfficeArtFSPGR(in, _t);
        _s.shapeGroup = QSharedPointer<OfficeArtFSPGR>(new OfficeArtFSPGR(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseOfficeArtFSP(in, _s.shapeProp);
    _m = in.setMark();
    try {
        OfficeArtFPSPL _t;
        parseOfficeArtFPSPL(in, _t);
        _s.deletedshape = QSharedPointer<OfficeArtFPSPL>(new OfficeArtFPSPL(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtFOPT _t;
        parseOfficeArtFOPT(in, _t);
        _s.shapePrimaryOptions = QSharedPointer<OfficeArtFOPT>(new OfficeArtFOPT(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtSecondaryFOPT _t;
        parseOfficeArtSecondaryFOPT(in, _t);
        _s.shapeSecondaryOptions1 = QSharedPointer<OfficeArtSecondaryFOPT>(new OfficeArtSecondaryFOPT(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtTertiaryFOPT _t;
        parseOfficeArtTertiaryFOPT(in, _t);
        _s.shapeTertiaryOptions1 = QSharedPointer<OfficeArtTertiaryFOPT>(new OfficeArtTertiaryFOPT(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtChildAnchor _t;
        parseOfficeArtChildAnchor(in, _t);
        _s.childAnchor = QSharedPointer<OfficeArtChildAnchor>(new OfficeArtChildAnchor(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtClientAnchor _t;
        parseOfficeArtClientAnchor(in, _t);
        _s.clientAnchor = QSharedPointer<OfficeArtClientAnchor>(new OfficeArtClientAnchor(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtClientData _t;
        parseOfficeArtClientData(in, _t);
        _s.clientData = QSharedPointer<OfficeArtClientData>(new OfficeArtClientData(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        OfficeArtClientTextBox _t;
        parseOfficeArtClientTextBox(in, _t);
        _s.clientTextbox = QSharedPointer<OfficeArtClientTextBox>(new OfficeArtClientTextBox(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
}
void parseWordDocument(LEInputStream& in, WordDocument& _s) {
    parseFib(in, _s.fib);
}
void parseTable(LEInputStream& in, Table& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseSTSH(in, _s.stsh);
    parsePlcfSed(in, _s.plcfSed);
    parsePlcfhdd(in, _s.plcfHdd);
    parsePlcBteChpx(in, _s.plcfBteChpx);
    parsePlcfBtePapx(in, _s.plcfBtePapx);
    parseTcg(in, _s.cmds);
    parseClx(in, _s.clx);
    parseSttbfFfn(in, _s.sttbfFfn);
    _c = 600;
    _s.dop.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.dop[_i] = in.readuint8();
    }
}
void parsePcd(LEInputStream& in, Pcd& _s) {
    _s.fNoParaLast = in.readbit();
    _s.fR1 = in.readbit();
    _s.fDirtly = in.readbit();
    if (!(((bool)_s.fDirtly) == false)) {
        throw IncorrectValueException(in.getPosition() + QString("((bool)_s.fDirtly) == false for value ") + QString::number(_s.fDirtly));
    }
    _s.fR2 = in.readbit();
    _s.fR3 = in.readuint12();
    parseFCompressed(in, _s.fc);
    parsePrm(in, _s.prm);
}
void parseOfficeArtFBSE(LEInputStream& in, OfficeArtFBSE& _s) {
    int _c;
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0x2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0x2 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 0x11 || _s.rh.recInstance == 0x12)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 0x11 || _s.rh.recInstance == 0x12 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF007)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF007 for value ") + _s.rh.toString());
    }
    _s.btWin32 = in.readuint8();
    _s.btMacOS = in.readuint8();
    _c = 16;
    _s.rgbUid.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.rgbUid[_i] = in.readuint8();
    }
    _s.tag = in.readuint16();
    _s.size = in.readuint32();
    if (!(((quint32)_s.size)>=8)) {
        throw IncorrectValueException(in.getPosition() + QString("((quint32)_s.size)>=8 for value ") + QString::number(_s.size) + "(" + QString::number(_s.size,16).toUpper() + ")");
    }
    _s.cRef = in.readuint32();
    _s.foDelay = in.readuint32();
    _s.unused1 = in.readuint8();
    _s.cbName = in.readuint8();
    _s.unused2 = in.readuint8();
    _s.unused3 = in.readuint8();
    _c = _s.cbName;
    _s.nameData.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.nameData[_i] = in.readuint8();
    }
    if (_s.rh.recLen > 36 + _s.cbName) {
        parseOfficeArtBlip(in, _s.embeddedBlip);
    }
}
void parseOfficeArtBStoreContainerFileBlock(LEInputStream& in, OfficeArtBStoreContainerFileBlock& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        OfficeArtFBSE _t;
        parseOfficeArtFBSE(in, _t);
        _s.anon.officeartfbse = QSharedPointer<OfficeArtFBSE>(new OfficeArtFBSE(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
        OfficeArtBlip _t;
        parseOfficeArtBlip(in, _t);
        _s.anon.officeartblip = QSharedPointer<OfficeArtBlip>(new OfficeArtBlip(_t));
    }
}
void parseDocumentTextInfoContainer(LEInputStream& in, DocumentTextInfoContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03F2)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03F2 for value ") + _s.rh.toString());
    }
    _m = in.setMark();
    try {
        KinsokuContainer _t;
        parseKinsokuContainer(in, _t);
        _s.kinsoku = QSharedPointer<KinsokuContainer>(new KinsokuContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        FontCollectionContainer _t;
        parseFontCollectionContainer(in, _t);
        _s.fontCollection = QSharedPointer<FontCollectionContainer>(new FontCollectionContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        TextCFExceptionAtom _t;
        parseTextCFExceptionAtom(in, _t);
        _s.textCFDefaultsAtom = QSharedPointer<TextCFExceptionAtom>(new TextCFExceptionAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        TextPFExceptionAtom _t;
        parseTextPFExceptionAtom(in, _t);
        _s.textPFDefaultsAtom = QSharedPointer<TextPFExceptionAtom>(new TextPFExceptionAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        DefaultRulerAtom _t;
        parseDefaultRulerAtom(in, _t);
        _s.defaultRulerAtom = QSharedPointer<DefaultRulerAtom>(new DefaultRulerAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseTextSIExceptionAtom(in, _s.textSIDefaultsAtom);
    parseTextMasterStyleAtom(in, _s.textMasterStyleAtom);
}
void parseDrawingGroupContainer(LEInputStream& in, DrawingGroupContainer& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x040B)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x040B for value ") + _s.rh.toString());
    }
    parseOfficeArtDggContainer(in, _s.OfficeArtDgg);
}
void parseOfficeArtDgContainer(LEInputStream& in, OfficeArtDgContainer& _s) {
    LEInputStream::Mark _m;
    parseOfficeArtRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0xF002)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0xF002 for value ") + _s.rh.toString());
    }
    parseOfficeArtFDG(in, _s.drawingData);
    _m = in.setMark();
    try {
        OfficeArtFRITContainer _t;
        parseOfficeArtFRITContainer(in, _t);
        _s.regroupItems = QSharedPointer<OfficeArtFRITContainer>(new OfficeArtFRITContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseOfficeArtSpgrContainer(in, _s.groupShape);
    parseOfficeArtSpContainer(in, _s.shape);
    bool _atend = false;
    while (!_atend) {
        _m = in.setMark();
        try {
            _s.deletedShapes.append(OfficeArtSpgrContainerFileBlock());
            parseOfficeArtSpgrContainerFileBlock(in, _s.deletedShapes.last());
        } catch(IncorrectValueException _e) {
            _atend = true;
            in.rewind(_m);
        } catch(EOFException _e) {
            _atend = true;
            in.rewind(_m);
        }
    }
    _m = in.setMark();
    try {
        OfficeArtSolverContainer _t;
        parseOfficeArtSolverContainer(in, _t);
        _s.solvers = QSharedPointer<OfficeArtSolverContainer>(new OfficeArtSolverContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
}
void parseOfficeArtSpgrContainerFileBlock(LEInputStream& in, OfficeArtSpgrContainerFileBlock& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        OfficeArtSpContainer _t;
        parseOfficeArtSpContainer(in, _t);
        _s.anon.officeartspcontainer = QSharedPointer<OfficeArtSpContainer>(new OfficeArtSpContainer(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
        OfficeArtSpgrContainer _t;
        parseOfficeArtSpgrContainer(in, _t);
        _s.anon.officeartspgrcontainer = QSharedPointer<OfficeArtSpgrContainer>(new OfficeArtSpgrContainer(_t));
    }
}
void parseDocumentContainer(LEInputStream& in, DocumentContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03E8)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03E8 for value ") + _s.rh.toString());
    }
    parseDocumentAtom(in, _s.documentAtom);
    _m = in.setMark();
    try {
        ExObjListContainer _t;
        parseExObjListContainer(in, _t);
        _s.exObjList = QSharedPointer<ExObjListContainer>(new ExObjListContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseDocumentTextInfoContainer(in, _s.documentTextInfo);
    parseDrawingGroupContainer(in, _s.drawingGroup);
    parseMasterListWithTextContainer(in, _s.masterList);
    _m = in.setMark();
    try {
        DocInfoListContainer _t;
        parseDocInfoListContainer(in, _t);
        _s.docInfoList = QSharedPointer<DocInfoListContainer>(new DocInfoListContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        SlideHeadersFootersContainer _t;
        parseSlideHeadersFootersContainer(in, _t);
        _s.slideHF = QSharedPointer<SlideHeadersFootersContainer>(new SlideHeadersFootersContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        NotesHeadersFootersContainer _t;
        parseNotesHeadersFootersContainer(in, _t);
        _s.notesHF = QSharedPointer<NotesHeadersFootersContainer>(new NotesHeadersFootersContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        SlideListWithTextContainer _t;
        parseSlideListWithTextContainer(in, _t);
        _s.slideList = QSharedPointer<SlideListWithTextContainer>(new SlideListWithTextContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        NotesListWithTextContainer _t;
        parseNotesListWithTextContainer(in, _t);
        _s.notesList = QSharedPointer<NotesListWithTextContainer>(new NotesListWithTextContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        SlideShowDocInfoAtom _t;
        parseSlideShowDocInfoAtom(in, _t);
        _s.slideShowDocInfoAtom = QSharedPointer<SlideShowDocInfoAtom>(new SlideShowDocInfoAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseEndDocumentAtom(in, _s.endDocumentAtom);
}
void parseDrawingContainer(LEInputStream& in, DrawingContainer& _s) {
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x040C)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x040C for value ") + _s.rh.toString());
    }
    parseOfficeArtDgContainer(in, _s.OfficeArtDg);
}
void parseSlideContainer(LEInputStream& in, SlideContainer& _s) {
    LEInputStream::Mark _m;
    parseRecordHeader(in, _s.rh);
    if (!(_s.rh.recVer == 0xF)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recVer == 0xF for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recInstance == 0x0)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recInstance == 0x0 for value ") + _s.rh.toString());
    }
    if (!(_s.rh.recType == 0x03EE)) {
        throw IncorrectValueException(in.getPosition() + QString("_s.rh.recType == 0x03EE for value ") + _s.rh.toString());
    }
    parseSlideAtom(in, _s.slideAtom);
    _m = in.setMark();
    try {
        SlideShowSlideInfoAtom _t;
        parseSlideShowSlideInfoAtom(in, _t);
        _s.slideShowSlideInfoAtom = QSharedPointer<SlideShowSlideInfoAtom>(new SlideShowSlideInfoAtom(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    _m = in.setMark();
    try {
        PerSlideHeadersFootersContainer _t;
        parsePerSlideHeadersFootersContainer(in, _t);
        _s.perSlideHFContainer = QSharedPointer<PerSlideHeadersFootersContainer>(new PerSlideHeadersFootersContainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
    parseDrawingContainer(in, _s.drawing);
    parseSlideSchemeColorSchemeAtom(in, _s.slideSchemeColorSchemeAtom);
    _m = in.setMark();
    try {
        SlideProgTagscontainer _t;
        parseSlideProgTagscontainer(in, _t);
        _s.slideProgTagsContainer = QSharedPointer<SlideProgTagscontainer>(new SlideProgTagscontainer(_t));
    } catch(IncorrectValueException _e) {
        in.rewind(_m);
    } catch(EOFException _e) {
        in.rewind(_m);
    }
}
void parseMasterOrSlideContainer(LEInputStream& in, MasterOrSlideContainer& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        MainMasterContainer _t;
        parseMainMasterContainer(in, _t);
        _s.anon.mainmastercontainer = QSharedPointer<MainMasterContainer>(new MainMasterContainer(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
        SlideContainer _t;
        parseSlideContainer(in, _t);
        _s.anon.slidecontainer = QSharedPointer<SlideContainer>(new SlideContainer(_t));
    }
}
void parsePowerPointStruct(LEInputStream& in, PowerPointStruct& _s) {
    LEInputStream::Mark _m = in.setMark();
    try {
        DocumentContainer _t;
        parseDocumentContainer(in, _t);
        _s.anon.documentcontainer = QSharedPointer<DocumentContainer>(new DocumentContainer(_t));
    } catch (IncorrectValueException _x) {
        in.rewind(_m);
    try {
        MasterOrSlideContainer _t;
        parseMasterOrSlideContainer(in, _t);
        _s.anon.masterorslidecontainer = QSharedPointer<MasterOrSlideContainer>(new MasterOrSlideContainer(_t));
    } catch (IncorrectValueException _xx) {
        in.rewind(_m);
    try {
        PersistDirectoryAtom _t;
        parsePersistDirectoryAtom(in, _t);
        _s.anon.persistdirectoryatom = QSharedPointer<PersistDirectoryAtom>(new PersistDirectoryAtom(_t));
    } catch (IncorrectValueException _xxx) {
        in.rewind(_m);
    try {
        NotesContainer _t;
        parseNotesContainer(in, _t);
        _s.anon.notescontainer = QSharedPointer<NotesContainer>(new NotesContainer(_t));
    } catch (IncorrectValueException _xxxx) {
        in.rewind(_m);
    try {
        HandoutContainer _t;
        parseHandoutContainer(in, _t);
        _s.anon.handoutcontainer = QSharedPointer<HandoutContainer>(new HandoutContainer(_t));
    } catch (IncorrectValueException _xxxxx) {
        in.rewind(_m);
    try {
        SlideContainer _t;
        parseSlideContainer(in, _t);
        _s.anon.slidecontainer = QSharedPointer<SlideContainer>(new SlideContainer(_t));
    } catch (IncorrectValueException _xxxxxx) {
        in.rewind(_m);
    try {
        ExOleObjStg _t;
        parseExOleObjStg(in, _t);
        _s.anon.exoleobjstg = QSharedPointer<ExOleObjStg>(new ExOleObjStg(_t));
    } catch (IncorrectValueException _xxxxxxx) {
        in.rewind(_m);
    try {
        ExControlStg _t;
        parseExControlStg(in, _t);
        _s.anon.excontrolstg = QSharedPointer<ExControlStg>(new ExControlStg(_t));
    } catch (IncorrectValueException _xxxxxxxx) {
        in.rewind(_m);
    try {
        VbaProjectStg _t;
        parseVbaProjectStg(in, _t);
        _s.anon.vbaprojectstg = QSharedPointer<VbaProjectStg>(new VbaProjectStg(_t));
    } catch (IncorrectValueException _xxxxxxxxx) {
        in.rewind(_m);
        UserEditAtom _t;
        parseUserEditAtom(in, _t);
        _s.anon.usereditatom = QSharedPointer<UserEditAtom>(new UserEditAtom(_t));
    }}}}}}}}}
}
}
void parse(const QString& key, LEInputStream& in) {
    if ("PowerPoint Document" == key) {
        PowerPointStructs _t;
        parsePowerPointStructs(in, _t);
    } else if ("Current User" == key) {
        CurrentUserStream _t;
        parseCurrentUserStream(in, _t);
    } else if ("Pictures" == key) {
        OfficeArtBStoreDelay _t;
        parseOfficeArtBStoreDelay(in, _t);
    } else if ("WordDocument" == key) {
        WordDocument _t;
        parseWordDocument(in, _t);
    } else if ("1Table" == key) {
        Table _t;
        parseTable(in, _t);
    } else {
        TODOS _t;
        parseTODOS(in, _t);
    }
}
