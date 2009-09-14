#include <QString>
#include <QByteArray>
#include <QVector>
#include <QSharedPointer>
#include "leinputstream.h"
#include "introspection.h"
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
class todo;
void parsetodo(LEInputStream& in, todo& _s);
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
class RecordHeader : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 recVer;
    quint16 recInstance;
    quint16 recType;
    quint32 recLen;
    RecordHeader() :recVer(0), recInstance(0), recType(0), recLen(0) {
    }
    QString toString() {
        QString _s = "RecordHeader:";
        _s = _s + "recVer: " + QString::number(recVer) + "(" + QString::number(recVer,16).toUpper() + ")" + ", ";
        _s = _s + "recInstance: " + QString::number(recInstance) + "(" + QString::number(recInstance,16).toUpper() + ")" + ", ";
        _s = _s + "recType: " + QString::number(recType) + "(" + QString::number(recType,16).toUpper() + ")" + ", ";
        _s = _s + "recLen: " + QString::number(recLen) + "(" + QString::number(recLen,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class CurrentUserAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    CurrentUserAtom() :size(0), headerToken(0), offsetToCurrentEdit(0), lenUserName(0), docFileVersion(0), majorVersion(0), minorVersion(0), unused(0), relVersion(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Byte : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 b;
    Byte() :b(0) {
    }
    QString toString() {
        QString _s = "Byte:";
        _s = _s + "b: " + QString::number(b) + "(" + QString::number(b,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class CurrentUserStream : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    CurrentUserAtom anon1;
    QList<Byte> trailing;
    CurrentUserStream()  {
    }
    QString toString() {
        QString _s = "CurrentUserStream:";
        _s = _s + "anon1: " + anon1.toString() + ", ";
        _s = _s + "trailing: " + "[array of trailing]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBStoreDelay : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QList<OfficeArtBStoreContainerFileBlock> anon1;
    OfficeArtBStoreDelay()  {
    }
    QString toString() {
        QString _s = "OfficeArtBStoreDelay:";
        _s = _s + "anon1: " + "[array of anon1]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtRecordHeader : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 recVer;
    quint16 recInstance;
    quint16 recType;
    quint32 recLen;
    OfficeArtRecordHeader() :recVer(0), recInstance(0), recType(0), recLen(0) {
    }
    QString toString() {
        QString _s = "OfficeArtRecordHeader:";
        _s = _s + "recVer: " + QString::number(recVer) + "(" + QString::number(recVer,16).toUpper() + ")" + ", ";
        _s = _s + "recInstance: " + QString::number(recInstance) + "(" + QString::number(recInstance,16).toUpper() + ")" + ", ";
        _s = _s + "recType: " + QString::number(recType) + "(" + QString::number(recType,16).toUpper() + ")" + ", ";
        _s = _s + "recLen: " + QString::number(recLen) + "(" + QString::number(recLen,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipJPEG : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    OfficeArtBlipJPEG() :tag(0) {
    }
    QString toString() {
        QString _s = "OfficeArtBlipJPEG:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipPNG : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    OfficeArtBlipPNG() :tag(0) {
    }
    QString toString() {
        QString _s = "OfficeArtBlipPNG:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipDIB : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    OfficeArtBlipDIB() :tag(0) {
    }
    QString toString() {
        QString _s = "OfficeArtBlipDIB:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipTIFF : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
    OfficeArtBlipTIFF() :tag(0) {
    }
    QString toString() {
        QString _s = "OfficeArtBlipTIFF:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "tag: " + QString::number(tag) + "(" + QString::number(tag,16).toUpper() + ")" + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RECT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint32 left;
    qint32 top;
    qint32 right;
    qint32 bottom;
    RECT() :left(0), top(0), right(0), bottom(0) {
    }
    QString toString() {
        QString _s = "RECT:";
        _s = _s + "left: " + QString::number(left) + "(" + QString::number(left,16).toUpper() + ")" + ", ";
        _s = _s + "top: " + QString::number(top) + "(" + QString::number(top,16).toUpper() + ")" + ", ";
        _s = _s + "right: " + QString::number(right) + "(" + QString::number(right,16).toUpper() + ")" + ", ";
        _s = _s + "bottom: " + QString::number(bottom) + "(" + QString::number(bottom,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class POINT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint32 x;
    qint32 y;
    POINT() :x(0), y(0) {
    }
    QString toString() {
        QString _s = "POINT:";
        _s = _s + "x: " + QString::number(x) + "(" + QString::number(x,16).toUpper() + ")" + ", ";
        _s = _s + "y: " + QString::number(y) + "(" + QString::number(y,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PowerPointStructs : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QList<PowerPointStruct> anon;
    PowerPointStructs()  {
    }
    QString toString() {
        QString _s = "PowerPointStructs:";
        _s = _s + "anon: " + "[array of anon]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideHeadersFootersContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    SlideHeadersFootersContainer()  {
    }
    QString toString() {
        QString _s = "SlideHeadersFootersContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class NotesHeadersFootersContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    NotesHeadersFootersContainer()  {
    }
    QString toString() {
        QString _s = "NotesHeadersFootersContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PerSlideHeadersFootersContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    PerSlideHeadersFootersContainer()  {
    }
    QString toString() {
        QString _s = "PerSlideHeadersFootersContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class EndDocumentAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    EndDocumentAtom()  {
    }
    QString toString() {
        QString _s = "EndDocumentAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DocInfoListContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QList<DocInfoListSubContainerOrAtom> rgChildRec;
    DocInfoListContainer()  {
    }
    QString toString() {
        QString _s = "DocInfoListContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DocInfoListSubContainerOrAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    DocInfoListSubContainerOrAtom()  {
    }
    QString toString() {
        QString _s = "DocInfoListSubContainerOrAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideViewInfoInstance : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    SlideViewInfoInstance()  {
    }
    QString toString() {
        QString _s = "SlideViewInfoInstance:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MasterListWithTextContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QVector<MasterPersistAtom> rgMasterPersistAtom;
    MasterListWithTextContainer()  {
    }
    QString toString() {
        QString _s = "MasterListWithTextContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgMasterPersistAtom: " + "[array of rgMasterPersistAtom]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideListWithTextContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QList<SlideListWithTextSubContainerOrAtom> rgChildRec;
    SlideListWithTextContainer()  {
    }
    QString toString() {
        QString _s = "SlideListWithTextContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class NotesListWithTextContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    NotesListWithTextContainer()  {
    }
    QString toString() {
        QString _s = "NotesListWithTextContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextHeaderAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint32 textType;
    TextHeaderAtom() :textType(0) {
    }
    QString toString() {
        QString _s = "TextHeaderAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textType: " + QString::number(textType) + "(" + QString::number(textType,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextCharsAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QVector<quint16> textChars;
    TextCharsAtom()  {
    }
    QString toString() {
        QString _s = "TextCharsAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textChars: " + "[array of textChars]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextBytesAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray textChars;
    TextBytesAtom()  {
    }
    QString toString() {
        QString _s = "TextBytesAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textChars: " + "[array of textChars]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MasterTextPropAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    MasterTextPropAtom()  {
    }
    QString toString() {
        QString _s = "MasterTextPropAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class StyleTextPropAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    StyleTextPropAtom()  {
    }
    QString toString() {
        QString _s = "StyleTextPropAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideNumberMCAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 position;
    SlideNumberMCAtom() :position(0) {
    }
    QString toString() {
        QString _s = "SlideNumberMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DateTimeMCAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 position;
    quint8 index;
    QByteArray unused;
    DateTimeMCAtom() :position(0), index(0) {
    }
    QString toString() {
        QString _s = "DateTimeMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "index: " + QString::number(index) + "(" + QString::number(index,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + "[array of unused]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class GenericDateMCAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 position;
    GenericDateMCAtom() :position(0) {
    }
    QString toString() {
        QString _s = "GenericDateMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class HeaderMCAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 position;
    HeaderMCAtom() :position(0) {
    }
    QString toString() {
        QString _s = "HeaderMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FooterMCAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 position;
    FooterMCAtom() :position(0) {
    }
    QString toString() {
        QString _s = "FooterMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RTFDateTimeMCAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 position;
    QByteArray format;
    RTFDateTimeMCAtom() :position(0) {
    }
    QString toString() {
        QString _s = "RTFDateTimeMCAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "format: " + "[array of format]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextBookmarkAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 begin;
    qint32 end;
    qint32 bookmarkID;
    TextBookmarkAtom() :begin(0), end(0), bookmarkID(0) {
    }
    QString toString() {
        QString _s = "TextBookmarkAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "begin: " + QString::number(begin) + "(" + QString::number(begin,16).toUpper() + ")" + ", ";
        _s = _s + "end: " + QString::number(end) + "(" + QString::number(end,16).toUpper() + ")" + ", ";
        _s = _s + "bookmarkID: " + QString::number(bookmarkID) + "(" + QString::number(bookmarkID,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextSpecialInfoAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    TextSpecialInfoAtom()  {
    }
    QString toString() {
        QString _s = "TextSpecialInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class InteractiveInfoInstance : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray range;
    InteractiveInfoInstance()  {
    }
    QString toString() {
        QString _s = "InteractiveInfoInstance:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "range: " + "[array of range]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextInteractiveInfoInstance : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray range;
    TextInteractiveInfoInstance()  {
    }
    QString toString() {
        QString _s = "TextInteractiveInfoInstance:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "range: " + "[array of range]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideId : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 slideId;
    SlideId() :slideId(0) {
    }
    QString toString() {
        QString _s = "SlideId:";
        _s = _s + "slideId: " + QString::number(slideId) + "(" + QString::number(slideId,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TabStops : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 count;
    QVector<TabStop> rgTabStop;
    TabStops() :count(0) {
    }
    QString toString() {
        QString _s = "TabStops:";
        _s = _s + "count: " + QString::number(count) + "(" + QString::number(count,16).toUpper() + ")" + ", ";
        _s = _s + "rgTabStop: " + "[array of rgTabStop]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TabStop : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint16 position;
    quint16 type;
    TabStop() :position(0), type(0) {
    }
    QString toString() {
        QString _s = "TabStop:";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "type: " + QString::number(type) + "(" + QString::number(type,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class BulletFlags : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    bool fHasBullet;
    bool fBulletHasFont;
    bool fBulletHasColor;
    bool fBulletHasSize;
    quint16 reserved;
    BulletFlags() :fHasBullet(0), fBulletHasFont(0), fBulletHasColor(0), fBulletHasSize(0), reserved(0) {
    }
    QString toString() {
        QString _s = "BulletFlags:";
        _s = _s + "fHasBullet: " + QString::number(fHasBullet) + ", ";
        _s = _s + "fBulletHasFont: " + QString::number(fBulletHasFont) + ", ";
        _s = _s + "fBulletHasColor: " + QString::number(fBulletHasColor) + ", ";
        _s = _s + "fBulletHasSize: " + QString::number(fBulletHasSize) + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PFMasks : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    PFMasks() :hasBullet(0), bulletHasFont(0), bulletHasColor(0), bulletHasSize(0), bulletFont(0), bulletColor(0), bulletSize(0), bulletChar(0), leftMargin(0), unused(0), indent(0), align(0), lineSpacing(0), spaceBefore(0), spaceAfter(0), defaultTabSize(0), fontAlign(0), charWrap(0), wordWrap(0), overflow(0), tabStops(0), textDirection(0), reserved(0), bulletBlip(0), bulletScheme(0), bulletHasScheme(0), reserved2(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class CFMasks : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    CFMasks() :bold(0), italic(0), underline(0), unused1(0), shadow(0), fehint(0), unused2(0), kumi(0), unused3(0), emboss(0), fHasStyle(0), unused4(0), typeface(0), size(0), color(0), position(0), pp10ext(0), oldEATypeface(0), ansiTypeface(0), symbolTypeface(0), newEATypeface(0), csTypeface(0), pp11ext(0), reserved(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class CFStyle : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    CFStyle() :bold(0), italic(0), underline(0), unused1(0), shadow(0), fehint(0), unused2(0), kumi(0), unused3(0), emboss(0), pp9rt(0), unused4(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FontCollectionContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray rgFontCollectionEntry;
    FontCollectionContainer()  {
    }
    QString toString() {
        QString _s = "FontCollectionContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgFontCollectionEntry: " + "[array of rgFontCollectionEntry]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FontEntityAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    FontEntityAtom()  {
    }
    QString toString() {
        QString _s = "FontEntityAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class KinsokuAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint32 level;
    KinsokuAtom() :level(0) {
    }
    QString toString() {
        QString _s = "KinsokuAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "level: " + QString::number(level) + "(" + QString::number(level,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextSIExceptionAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray textSIException;
    TextSIExceptionAtom()  {
    }
    QString toString() {
        QString _s = "TextSIExceptionAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "textSIException: " + "[array of textSIException]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExOleEmbedAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint32 exColorFollow;
    quint8 fCantLockServer;
    quint8 fNoSizeToServer;
    quint8 fIsTable;
    quint8 unused;
    ExOleEmbedAtom() :exColorFollow(0), fCantLockServer(0), fNoSizeToServer(0), fIsTable(0), unused(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PointStruct : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint32 x;
    qint32 y;
    PointStruct() :x(0), y(0) {
    }
    QString toString() {
        QString _s = "PointStruct:";
        _s = _s + "x: " + QString::number(x) + "(" + QString::number(x,16).toUpper() + ")" + ", ";
        _s = _s + "y: " + QString::number(y) + "(" + QString::number(y,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RatioStruct : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint32 numer;
    qint32 denom;
    RatioStruct() :numer(0), denom(0) {
    }
    QString toString() {
        QString _s = "RatioStruct:";
        _s = _s + "numer: " + QString::number(numer) + "(" + QString::number(numer,16).toUpper() + ")" + ", ";
        _s = _s + "denom: " + QString::number(denom) + "(" + QString::number(denom,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PersistDirectoryAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QList<PersistDirectoryEntry> rgPersistDirEntry;
    PersistDirectoryAtom()  {
    }
    QString toString() {
        QString _s = "PersistDirectoryAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgPersistDirEntry: " + "[array of rgPersistDirEntry]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PersistDirectoryEntry : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 persistId;
    quint16 cPersist;
    QVector<PersistOffsetEntry> rgPersistOffset;
    PersistDirectoryEntry() :persistId(0), cPersist(0) {
    }
    QString toString() {
        QString _s = "PersistDirectoryEntry:";
        _s = _s + "persistId: " + QString::number(persistId) + "(" + QString::number(persistId,16).toUpper() + ")" + ", ";
        _s = _s + "cPersist: " + QString::number(cPersist) + "(" + QString::number(cPersist,16).toUpper() + ")" + ", ";
        _s = _s + "rgPersistOffset: " + "[array of rgPersistOffset]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PersistOffsetEntry : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 anon;
    PersistOffsetEntry() :anon(0) {
    }
    QString toString() {
        QString _s = "PersistOffsetEntry:";
        _s = _s + "anon: " + QString::number(anon) + "(" + QString::number(anon,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PersistIdRef : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 anon;
    PersistIdRef() :anon(0) {
    }
    QString toString() {
        QString _s = "PersistIdRef:";
        _s = _s + "anon: " + QString::number(anon) + "(" + QString::number(anon,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MainMasterContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    MainMasterContainer()  {
    }
    QString toString() {
        QString _s = "MainMasterContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class NotesContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    NotesContainer()  {
    }
    QString toString() {
        QString _s = "NotesContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class HandoutContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    HandoutContainer()  {
    }
    QString toString() {
        QString _s = "HandoutContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExControlStg : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    ExControlStg()  {
    }
    QString toString() {
        QString _s = "ExControlStg:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExOleObjStg : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    ExOleObjStg()  {
    }
    QString toString() {
        QString _s = "ExOleObjStg:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class UserEditAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    UserEditAtom()  {
    }
    QString toString() {
        QString _s = "UserEditAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class VbaProjectStg : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    VbaProjectStg()  {
    }
    QString toString() {
        QString _s = "VbaProjectStg:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideProgTagscontainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    SlideProgTagscontainer()  {
    }
    QString toString() {
        QString _s = "SlideProgTagscontainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint32 geom;
    QByteArray rgPlaceholderTypes;
    quint32 masterIdRef;
    quint32 notesIdRef;
    quint16 slideFlags;
    quint16 unused;
    SlideAtom() :geom(0), masterIdRef(0), notesIdRef(0), slideFlags(0), unused(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideShowSlideInfoAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    SlideShowSlideInfoAtom() :slidetime(0), slideIdRef(0), effectDirection(0), effectType(0), fManualAdvance(0), reserved(0), fHidden(0), reserved2(0), fSound(0), reserved3(0), fLoopSound(0), reserved4(0), fStopSound(0), freserved5(0), fAutoAdvance(0), reserved6(0), fCursorVisible(0), reserved7(0), speed(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideShowDocInfoAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    SlideShowDocInfoAtom()  {
    }
    QString toString() {
        QString _s = "SlideShowDocInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideSchemeColorSchemeAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QVector<ColorStruct> rgSchemeColor;
    SlideSchemeColorSchemeAtom()  {
    }
    QString toString() {
        QString _s = "SlideSchemeColorSchemeAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgSchemeColor: " + "[array of rgSchemeColor]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RoundTripSlideRecord : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray todo;
    RoundTripSlideRecord()  {
    }
    QString toString() {
        QString _s = "RoundTripSlideRecord:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ColorStruct : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 red;
    quint8 green;
    quint8 blue;
    quint8 unused;
    ColorStruct() :red(0), green(0), blue(0), unused(0) {
    }
    QString toString() {
        QString _s = "ColorStruct:";
        _s = _s + "red: " + QString::number(red) + "(" + QString::number(red,16).toUpper() + ")" + ", ";
        _s = _s + "green: " + QString::number(green) + "(" + QString::number(green,16).toUpper() + ")" + ", ";
        _s = _s + "blue: " + QString::number(blue) + "(" + QString::number(blue,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExObjListAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint32 exObjIdSeed;
    ExObjListAtom() :exObjIdSeed(0) {
    }
    QString toString() {
        QString _s = "ExObjListAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exObjIdSeed: " + QString::number(exObjIdSeed) + "(" + QString::number(exObjIdSeed,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExOleLinkAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint32 slideIdRef;
    quint32 oleUpdateMode;
    quint32 unused;
    ExOleLinkAtom() :slideIdRef(0), oleUpdateMode(0), unused(0) {
    }
    QString toString() {
        QString _s = "ExOleLinkAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "slideIdRef: " + QString::number(slideIdRef) + "(" + QString::number(slideIdRef,16).toUpper() + ")" + ", ";
        _s = _s + "oleUpdateMode: " + QString::number(oleUpdateMode) + "(" + QString::number(oleUpdateMode,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExOleObjAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint32 drawAspect;
    quint32 type;
    quint32 exObjId;
    quint32 subType;
    quint32 persistIdRef;
    quint32 unused;
    ExOleObjAtom() :drawAspect(0), type(0), exObjId(0), subType(0), persistIdRef(0), unused(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MenuNameAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray menuName;
    MenuNameAtom()  {
    }
    QString toString() {
        QString _s = "MenuNameAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "menuName: " + "[array of menuName]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ProgIDAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray progId;
    ProgIDAtom()  {
    }
    QString toString() {
        QString _s = "ProgIDAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "progId: " + "[array of progId]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ClipboardNameAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray clipboardName;
    ClipboardNameAtom()  {
    }
    QString toString() {
        QString _s = "ClipboardNameAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "clipboardName: " + "[array of clipboardName]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MetafileBlob : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    qint16 mm;
    qint16 xExt;
    qint16 yExt;
    QByteArray data;
    MetafileBlob() :mm(0), xExt(0), yExt(0) {
    }
    QString toString() {
        QString _s = "MetafileBlob:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "mm: " + QString::number(mm) + "(" + QString::number(mm,16).toUpper() + ")" + ", ";
        _s = _s + "xExt: " + QString::number(xExt) + "(" + QString::number(xExt,16).toUpper() + ")" + ", ";
        _s = _s + "yExt: " + QString::number(yExt) + "(" + QString::number(yExt,16).toUpper() + ")" + ", ";
        _s = _s + "data: " + "[array of data]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFDGG : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 spidMax;
    quint32 cidcl;
    quint32 cspSaved;
    quint32 cdgSaved;
    OfficeArtFDGG() :spidMax(0), cidcl(0), cspSaved(0), cdgSaved(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFDGG:";
        _s = _s + "spidMax: " + QString::number(spidMax) + "(" + QString::number(spidMax,16).toUpper() + ")" + ", ";
        _s = _s + "cidcl: " + QString::number(cidcl) + "(" + QString::number(cidcl,16).toUpper() + ")" + ", ";
        _s = _s + "cspSaved: " + QString::number(cspSaved) + "(" + QString::number(cspSaved,16).toUpper() + ")" + ", ";
        _s = _s + "cdgSaved: " + QString::number(cdgSaved) + "(" + QString::number(cdgSaved,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFDG : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    quint32 csp;
    quint32 spidCur;
    OfficeArtFDG() :csp(0), spidCur(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFDG:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "csp: " + QString::number(csp) + "(" + QString::number(csp,16).toUpper() + ")" + ", ";
        _s = _s + "spidCur: " + QString::number(spidCur) + "(" + QString::number(spidCur,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFRITContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFRIT> rgfrit;
    OfficeArtFRITContainer()  {
    }
    QString toString() {
        QString _s = "OfficeArtFRITContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfrit: " + "[array of rgfrit]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFRIT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 fridNew;
    quint16 fridOld;
    OfficeArtFRIT() :fridNew(0), fridOld(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFRIT:";
        _s = _s + "fridNew: " + QString::number(fridNew) + "(" + QString::number(fridNew,16).toUpper() + ")" + ", ";
        _s = _s + "fridOld: " + QString::number(fridOld) + "(" + QString::number(fridOld,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBStoreContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QList<OfficeArtBStoreContainerFileBlock> rgfb;
    OfficeArtBStoreContainer()  {
    }
    QString toString() {
        QString _s = "OfficeArtBStoreContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfb: " + "[array of rgfb]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtSpgrContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QList<OfficeArtSpgrContainerFileBlock> rgfb;
    OfficeArtSpgrContainer()  {
    }
    QString toString() {
        QString _s = "OfficeArtSpgrContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgfb: " + "[array of rgfb]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtSolverContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    OfficeArtSolverContainer()  {
    }
    QString toString() {
        QString _s = "OfficeArtSolverContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFSPGR : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    qint32 xLeft;
    qint32 yTop;
    qint32 xRight;
    qint32 yBottom;
    OfficeArtFSPGR() :xLeft(0), yTop(0), xRight(0), yBottom(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFSPGR:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "xLeft: " + QString::number(xLeft) + "(" + QString::number(xLeft,16).toUpper() + ")" + ", ";
        _s = _s + "yTop: " + QString::number(yTop) + "(" + QString::number(yTop,16).toUpper() + ")" + ", ";
        _s = _s + "xRight: " + QString::number(xRight) + "(" + QString::number(xRight,16).toUpper() + ")" + ", ";
        _s = _s + "yBottom: " + QString::number(yBottom) + "(" + QString::number(yBottom,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFSP : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    OfficeArtFSP() :spid(0), fGroup(0), fChild(0), fPatriarch(0), fDeleted(0), fOleShape(0), fHaveMaster(0), fFlipH(0), fFlipV(0), fConnector(0), fHaveAnchor(0), fBackground(0), fHaveSpt(0), unused1(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFOPT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFOPTE> fopt;
    OfficeArtFOPT()  {
    }
    QString toString() {
        QString _s = "OfficeArtFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtChildAnchor : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    qint32 xLeft;
    qint32 yTop;
    qint32 xRight;
    qint32 yBottom;
    OfficeArtChildAnchor() :xLeft(0), yTop(0), xRight(0), yBottom(0) {
    }
    QString toString() {
        QString _s = "OfficeArtChildAnchor:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "xLeft: " + QString::number(xLeft) + "(" + QString::number(xLeft,16).toUpper() + ")" + ", ";
        _s = _s + "yTop: " + QString::number(yTop) + "(" + QString::number(yTop,16).toUpper() + ")" + ", ";
        _s = _s + "xRight: " + QString::number(xRight) + "(" + QString::number(xRight,16).toUpper() + ")" + ", ";
        _s = _s + "yBottom: " + QString::number(yBottom) + "(" + QString::number(yBottom,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFPSPL : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    quint32 spid;
    bool reserved1;
    bool fLast;
    OfficeArtFPSPL() :spid(0), reserved1(0), fLast(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFPSPL:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "spid: " + QString::number(spid) + "(" + QString::number(spid,16).toUpper() + ")" + ", ";
        _s = _s + "reserved1: " + QString::number(reserved1) + ", ";
        _s = _s + "fLast: " + QString::number(fLast) + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtSecondaryFOPT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray fopt;
    OfficeArtSecondaryFOPT()  {
    }
    QString toString() {
        QString _s = "OfficeArtSecondaryFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtTertiaryFOPT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFOPTE> fopt;
    OfficeArtTertiaryFOPT()  {
    }
    QString toString() {
        QString _s = "OfficeArtTertiaryFOPT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "fopt: " + "[array of fopt]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RectStruct : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint32 top;
    qint32 left;
    qint32 right;
    qint32 bottom;
    RectStruct() :top(0), left(0), right(0), bottom(0) {
    }
    QString toString() {
        QString _s = "RectStruct:";
        _s = _s + "top: " + QString::number(top) + "(" + QString::number(top,16).toUpper() + ")" + ", ";
        _s = _s + "left: " + QString::number(left) + "(" + QString::number(left,16).toUpper() + ")" + ", ";
        _s = _s + "right: " + QString::number(right) + "(" + QString::number(right,16).toUpper() + ")" + ", ";
        _s = _s + "bottom: " + QString::number(bottom) + "(" + QString::number(bottom,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SmallRectStruct : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint16 top;
    qint16 left;
    qint16 right;
    qint16 bottom;
    SmallRectStruct() :top(0), left(0), right(0), bottom(0) {
    }
    QString toString() {
        QString _s = "SmallRectStruct:";
        _s = _s + "top: " + QString::number(top) + "(" + QString::number(top,16).toUpper() + ")" + ", ";
        _s = _s + "left: " + QString::number(left) + "(" + QString::number(left,16).toUpper() + ")" + ", ";
        _s = _s + "right: " + QString::number(right) + "(" + QString::number(right,16).toUpper() + ")" + ", ";
        _s = _s + "bottom: " + QString::number(bottom) + "(" + QString::number(bottom,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ShapeFlagsAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    ShapeFlagsAtom()  {
    }
    QString toString() {
        QString _s = "ShapeFlagsAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ShapeFlags10Atom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    ShapeFlags10Atom()  {
    }
    QString toString() {
        QString _s = "ShapeFlags10Atom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExObjRefAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    ExObjRefAtom()  {
    }
    QString toString() {
        QString _s = "ExObjRefAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class AnimationInfoContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    AnimationInfoContainer()  {
    }
    QString toString() {
        QString _s = "AnimationInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MouseClickInteractiveInfoContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    MouseClickInteractiveInfoContainer()  {
    }
    QString toString() {
        QString _s = "MouseClickInteractiveInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MouseOverInteractiveInfoContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    MouseOverInteractiveInfoContainer()  {
    }
    QString toString() {
        QString _s = "MouseOverInteractiveInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PlaceholderAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    qint32 position;
    quint8 placementId;
    quint8 size;
    quint16 unused;
    PlaceholderAtom() :position(0), placementId(0), size(0), unused(0) {
    }
    QString toString() {
        QString _s = "PlaceholderAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "position: " + QString::number(position) + "(" + QString::number(position,16).toUpper() + ")" + ", ";
        _s = _s + "placementId: " + QString::number(placementId) + "(" + QString::number(placementId,16).toUpper() + ")" + ", ";
        _s = _s + "size: " + QString::number(size) + "(" + QString::number(size,16).toUpper() + ")" + ", ";
        _s = _s + "unused: " + QString::number(unused) + "(" + QString::number(unused,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RecolorInfoAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    RecolorInfoAtom()  {
    }
    QString toString() {
        QString _s = "RecolorInfoAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OutlineTextRefAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    qint32 index;
    OutlineTextRefAtom() :index(0) {
    }
    QString toString() {
        QString _s = "OutlineTextRefAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "index: " + QString::number(index) + "(" + QString::number(index,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ShapeClientRoundtripDataSubcontainerOrAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    ShapeClientRoundtripDataSubcontainerOrAtom()  {
    }
    QString toString() {
        QString _s = "ShapeClientRoundtripDataSubcontainerOrAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtClientTextBox : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QList<TextClientDataSubContainerOrAtom> rgChildRec;
    OfficeArtClientTextBox()  {
    }
    QString toString() {
        QString _s = "OfficeArtClientTextBox:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextClientDataSubContainerOrAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray todo;
    TextClientDataSubContainerOrAtom()  {
    }
    QString toString() {
        QString _s = "TextClientDataSubContainerOrAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtIDCL : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 dgid;
    quint32 cspidCur;
    OfficeArtIDCL() :dgid(0), cspidCur(0) {
    }
    QString toString() {
        QString _s = "OfficeArtIDCL:";
        _s = _s + "dgid: " + QString::number(dgid) + "(" + QString::number(dgid,16).toUpper() + ")" + ", ";
        _s = _s + "cspidCur: " + QString::number(cspidCur) + "(" + QString::number(cspidCur,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFOPTEOPID : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 opid;
    bool fBid;
    bool fComplex;
    OfficeArtFOPTEOPID() :opid(0), fBid(0), fComplex(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFOPTEOPID:";
        _s = _s + "opid: " + QString::number(opid) + "(" + QString::number(opid,16).toUpper() + ")" + ", ";
        _s = _s + "fBid: " + QString::number(fBid) + ", ";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtColorMRUContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QVector<MSOCR> rgmsocr;
    OfficeArtColorMRUContainer()  {
    }
    QString toString() {
        QString _s = "OfficeArtColorMRUContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgmsocr: " + "[array of rgmsocr]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MSOCR : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 red;
    quint8 green;
    quint8 blue;
    quint8 unused1;
    bool fSchemeIndex;
    quint8 unused2;
    MSOCR() :red(0), green(0), blue(0), unused1(0), fSchemeIndex(0), unused2(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtSplitMenuColorContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QVector<MSOCR> smca;
    OfficeArtSplitMenuColorContainer()  {
    }
    QString toString() {
        QString _s = "OfficeArtSplitMenuColorContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "smca: " + "[array of smca]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class todo : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QByteArray anon;
    todo()  {
    }
    QString toString() {
        QString _s = "todo:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "anon: " + "[array of anon]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TODOS : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QList<todo> anon;
    TODOS()  {
    }
    QString toString() {
        QString _s = "TODOS:";
        _s = _s + "anon: " + "[array of anon]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FibBase : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    FibBase() :wIdent(0), nFib(0), unused(0), lid(0), pnNext(0), fDot(0), fGlsy(0), fComplex(0), fHasPic(0), cQuickSaves(0), fEncrypted(0), fWhichTblStm(0), fReadOnlyRecommended(0), fWriteReservation(0), fExtChar(0), fLoadOverride(0), fFarEast(0), fObfuscated(0), nFibBack(0), IKey(0), envr(0), fMac(0), fEmptySpecial(0), fLoadOverridePage(0), reserved1(0), reserved2(0), fSpare0(0), reserved3(0), reserved4(0), reserved5(0), reserved6(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FibRgW97 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    FibRgW97() :reserved1(0), reserved2(0), reserved3(0), reserved4(0), reserved5(0), reserved6(0), reserved7(0), reserved8(0), reserved9(0), reserved10(0), reserved11(0), reserved12(0), reserved13(0), lidFE(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FibRgLw97 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    FibRgLw97() :cbMac(0), reserved1(0), reserved2(0), ccpText(0), ccpFtn(0), ccpHdd(0), reserved3(0), ccpAtn(0), ccpEdn(0), ccpTxbx(0), ccpHdrTxbx(0), reserved4(0), reserved5(0), reserved6(0), reserved7(0), reserved8(0), reserved9(0), reserved10(0), reserved11(0), reserved12(0), reserved13(0), reserved14(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FibRgFcLcb97 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    FibRgFcLcb97() :fcStshfOrig(0), lcbStshfOrig(0), fcStshf(0), lcbStshf(0), fcPlcffndRef(0), lcbPlcffndRef(0), fcPlcffndTxt(0), lcbPlcffndTxt(0), fcPlcfandRef(0), lcbPlcfandRef(0), fcPlcfandTxt(0), lcbPlcfandTxt(0), fcPlcfSed(0), lcbPlcfSed(0), fcPlcPad(0), lcbPlcPad(0), fcPlcfPhe(0), lcbPlcfPhe(0), fcSttbfGlsy(0), lcbSttbfGlsy(0), fcPlcfGlsy(0), lcbPlcfGlsy(0), fcPlcfHdd(0), lcbPlcfHdd(0), fcPlcfBteChpx(0), lcbPlcfBteChpx(0), fcPlcfBtePapx(0), lcbPlcfBtePapx(0), fcPlcfSea(0), lcbPlcfSea(0), fcSttbfFfn(0), lcbSttbfFfn(0), fcPlcfFldMom(0), lcbPlcfFldMom(0), fcPlcfFldHdr(0), lcbPlcfFldHdr(0), fcPlcfFldFtn(0), lcbPlcfFldFtn(0), fcPlcfFldAtn(0), lcbPlcfFldAtn(0), fcPlcfFldMcr(0), lcbPlcfFldMcr(0), fcSttbfBkmk(0), lcbSttbfBkmk(0), fcPlcfBkf(0), lcbPlcfBkf(0), fcPlcfBkl(0), lcbPlcfBkl(0), fcCmds(0), lcbCmds(0), fcUnused1(0), lcbUnused1(0), fcSttbfMcr(0), lcbSttbfMcr(0), fcPrDrvr(0), lcbPrDrvr(0), fcPrEnvPort(0), lcbPrEnvPort(0), fcPrEnvLand(0), lcbPrEnvLand(0), fcWss(0), lcbWss(0), fcDop(0), lcbDop(0), fcSttbfAssoc(0), lcbSttbfAssoc(0), fcClx(0), lcbClx(0), fcPlcfPgdFtn(0), lcbPlcfPgdFtn(0), fcAutosaveSource(0), lcbAutosaveSource(0), fcGrpXstAtnOwners(0), lcbGrpXstAtnOwners(0), fcSttbfAtnBkmk(0), lcbSttbfAtnBkmk(0), fcUnused2(0), lcbUnused2(0), fcUnused3(0), lcbUnused3(0), fcPlcSpaMom(0), lcbPlcSpaMom(0), fcPlcSpaHdr(0), lcbPlcSpaHdr(0), fcPlcfAtnBkf(0), lcbPlcfAtnBkf(0), fcPlcfAtnBkl(0), lcbPlcfAtnBkl(0), fcPms(0), lcbPms(0), fcFormFldSttbs(0), lcbFormFldSttbs(0), fcPlcfendRef(0), lcbPlcfendRef(0), fcPlcfendTxt(0), lcbPlcfendTxt(0), fcPlcfFldEdn(0), lcbPlcfFldEdn(0), fcUnused4(0), lcbUnused4(0), fcDggInfo(0), lcbDggInfo(0), fcSttbfRMark(0), lcbSttbfRMark(0), fcSttbfCaption(0), lcbSttbfCaption(0), fcSttbfAutoCaption(0), lcbSttbfAutoCaption(0), fcPlcfWkb(0), lcbPlcfWkb(0), fcPlcfSpl(0), lcbPlcfSpl(0), fcPlcftxbxTxt(0), lcbPlcftxbxTxt(0), fcPlcfFldTxbx(0), lcbPlcfFldTxbx(0), fcPlcfHdrtxbxTxt(0), lcbPlcfHdrtxbxTxt(0), fcPlcffldHdrTxbx(0), lcbPlcffldHdrTxbx(0), fcStwUser(0), lcbStwUser(0), fcSttbTtmbd(0), lcbSttbTtmbd(0), fcCookieData(0), lcbCookieData(0), fcPgdMotherOldOld(0), lcbPgdMotherOldOld(0), fcBkdMotherOldOld(0), lcbBkdMotherOldOld(0), fcPgdFtnOldOld(0), lcbPgdFtnOldOld(0), fcBkdFtnOldOld(0), lcbBkdFtnOldOld(0), fcPgdEdnOldOld(0), lcbPgdEdnOldOld(0), fcBkdEdnOldOld(0), lcbBkdEdnOldOld(0), fcSttbfIntlFld(0), lcbSttbfIntlFld(0), fcRouteSlip(0), lcbRouteSlip(0), fcSttbSavedBy(0), lcbSttbSavedBy(0), fcSttbFnm(0), lcbSttbFnm(0), fcPlfLst(0), lcbPlfLst(0), fcPlfLfo(0), lcbPlfLfo(0), fcPlcfTxbxBkd(0), lcbPlcfTxbxBkd(0), fcPlcfTxbxHdrBkd(0), lcbPlcfTxbxHdrBkd(0), fcDocUndoWord9(0), lcbDocUndoWord9(0), fcRgbUse(0), lcbRgbUse(0), fcUsp(0), lcbUsp(0), fcUskf(0), lcbUskf(0), fcPlcupcRgbUse(0), lcbPlcupcRgbUse(0), fcPlcupcUsp(0), lcbPlcupcUsp(0), fcSttbGlsyStyle(0), lcbSttbGlsyStyle(0), fcPlgosl(0), lcbPlgosl(0), fcPlcocx(0), lcbPlcocx(0), fcPlcfBteLvc(0), lcbPlcfBteLvc(0), dwLowDateTime(0), dwHighDateTime(0), fcPlcfLvcPre10(0), lcbPlcfLvcPre10(0), fcPlcfAsumy(0), lcbPlcfAsumy(0), fcPlcfGram(0), lcbPlcfGram(0), fcSttbListNames(0), lcbSttbListNames(0), fcSttbfUssr(0), lcbSttbfUssr(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FibRgFcLcb2000 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    FibRgFcLcb2000() :fcPlcfTch(0), lcbPlcfTch(0), fcRmdThreading(0), lcbRmdThreading(0), fcMid(0), lcbMid(0), fcSttbRgtplc(0), lcbSttbRgtplc(0), fcMsoEnvelope(0), lcbMsoEnvelope(0), fcPlcfLad(0), lcbPlcfLad(0), fcRgDofr(0), lcbRgDofr(0), fcPlcosl(0), lcbPlcosl(0), fcPlcfCookieOld(0), lcbPlcfCookieOld(0), fcPgdMotherOld(0), lcbPgdMotherOld(0), fcBkdMotherOld(0), lcbBkdMotherOld(0), fcPgdFtnOld(0), lcbPgdFtnOld(0), fcBkdFtnOld(0), lcbBkdFtnOld(0), fcPgdEdnOld(0), lcbPgdEdnOld(0), fcBkdEdnOld(0), lcbBkdEdnOld(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FibRgFcLcb2002 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    FibRgFcLcb2002() :fcUnused1(0), lcbUnused1(0), fcPlcfPgp(0), lcbPlcfPgp(0), fcPlcfuim(0), lcbPlcfuim(0), fcPlfguidUim(0), lcbPlfguidUim(0), fcAtrdExtra(0), lcbAtrdExtra(0), fcPlrsid(0), lcbPlrsid(0), fcSttbfBkmkFactoid(0), lcbSttbfBkmkFactoid(0), fcPlcfBkfFactoid(0), lcbPlcfBkfFactoid(0), fcPlcfcookie(0), lcbPlcfcookie(0), fcPlcfBklFactoid(0), lcbPlcfBklFactoid(0), fcFactoidData(0), lcbFactoidData(0), fcDocUndo(0), lcbDocUndo(0), fcSttbfBkmkFcc(0), lcbSttbfBkmkFcc(0), fcPlcfBkfFcc(0), lcbPlcfBkfFcc(0), fcPlcfBklFcc(0), lcbPlcfBklFcc(0), fcSttbfbkmkBPRepairs(0), lcbSttbfbkmkBPRepairs(0), fcPlcfbkfBPRepairs(0), lcbPlcfbkfBPRepairs(0), fcPlcfbklBPRepairs(0), lcbPlcfbklBPRepairs(0), fcPmsNew(0), lcbPmsNew(0), fcODSO(0), lcbODSO(0), fcPlcfpmiOldXP(0), lcbPlcfpmiOldXP(0), fcPlcfpmiNewXP(0), lcbPlcfpmiNewXP(0), fcPlcfpmiMixedXP(0), lcbPlcfpmiMixedXP(0), fcUnused2(0), lcbUnused2(0), fcPlcffactoid(0), lcbPlcffactoid(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class LPStshi : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 cbSthi;
    QByteArray stshi;
    LPStshi() :cbSthi(0) {
    }
    QString toString() {
        QString _s = "LPStshi:";
        _s = _s + "cbSthi: " + QString::number(cbSthi) + "(" + QString::number(cbSthi,16).toUpper() + ")" + ", ";
        _s = _s + "stshi: " + "[array of stshi]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class LPStd : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 cbStd;
    QByteArray std;
    quint8 padding;
    LPStd() :cbStd(0), padding(0) {
    }
    QString toString() {
        QString _s = "LPStd:";
        _s = _s + "cbStd: " + QString::number(cbStd) + "(" + QString::number(cbStd,16).toUpper() + ")" + ", ";
        _s = _s + "std: " + "[array of std]" + ", ";
        _s = _s + "padding: " + QString::number(padding) + "(" + QString::number(padding,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PlcfSed : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QVector<quint32> aCP;
    QVector<Sed> aSed;
    PlcfSed()  {
    }
    QString toString() {
        QString _s = "PlcfSed:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        _s = _s + "aSed: " + "[array of aSed]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Sed : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 fn;
    qint32 fcSepx;
    quint16 fnMpr;
    quint32 fcMpr;
    Sed() :fn(0), fcSepx(0), fnMpr(0), fcMpr(0) {
    }
    QString toString() {
        QString _s = "Sed:";
        _s = _s + "fn: " + QString::number(fn) + "(" + QString::number(fn,16).toUpper() + ")" + ", ";
        _s = _s + "fcSepx: " + QString::number(fcSepx) + "(" + QString::number(fcSepx,16).toUpper() + ")" + ", ";
        _s = _s + "fnMpr: " + QString::number(fnMpr) + "(" + QString::number(fnMpr,16).toUpper() + ")" + ", ";
        _s = _s + "fcMpr: " + QString::number(fcMpr) + "(" + QString::number(fcMpr,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Plcfhdd : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QVector<quint32> aCP;
    Plcfhdd()  {
    }
    QString toString() {
        QString _s = "Plcfhdd:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PlcBteChpx : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QVector<quint32> aCP;
    QVector<quint32> aPnBteChpx;
    PlcBteChpx()  {
    }
    QString toString() {
        QString _s = "PlcBteChpx:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        _s = _s + "aPnBteChpx: " + "[array of aPnBteChpx]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PlcfBtePapx : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QVector<quint32> aCP;
    QVector<quint32> aPnBteChpx;
    PlcfBtePapx()  {
    }
    QString toString() {
        QString _s = "PlcfBtePapx:";
        _s = _s + "aCP: " + "[array of aCP]" + ", ";
        _s = _s + "aPnBteChpx: " + "[array of aPnBteChpx]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Tcg : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 nTcgVer;
    QByteArray todo;
    Tcg() :nTcgVer(0) {
    }
    QString toString() {
        QString _s = "Tcg:";
        _s = _s + "nTcgVer: " + QString::number(nTcgVer) + "(" + QString::number(nTcgVer,16).toUpper() + ")" + ", ";
        _s = _s + "todo: " + "[array of todo]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PrcData : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    qint16 cbGrpprl;
    QVector<Sprm> GrpPrl;
    PrcData() :cbGrpprl(0) {
    }
    QString toString() {
        QString _s = "PrcData:";
        _s = _s + "cbGrpprl: " + QString::number(cbGrpprl) + "(" + QString::number(cbGrpprl,16).toUpper() + ")" + ", ";
        _s = _s + "GrpPrl: " + "[array of GrpPrl]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Sprm : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 ispmd;
    bool fSpec;
    quint8 sgc;
    quint8 spra;
    Sprm() :ispmd(0), fSpec(0), sgc(0), spra(0) {
    }
    QString toString() {
        QString _s = "Sprm:";
        _s = _s + "ispmd: " + QString::number(ispmd) + "(" + QString::number(ispmd,16).toUpper() + ")" + ", ";
        _s = _s + "fSpec: " + QString::number(fSpec) + ", ";
        _s = _s + "sgc: " + QString::number(sgc) + "(" + QString::number(sgc,16).toUpper() + ")" + ", ";
        _s = _s + "spra: " + QString::number(spra) + "(" + QString::number(spra,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Pcdt : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 clxt;
    quint32 lcb;
    QVector<Pcd> PlcPcd;
    Pcdt() :clxt(0), lcb(0) {
    }
    QString toString() {
        QString _s = "Pcdt:";
        _s = _s + "clxt: " + QString::number(clxt) + "(" + QString::number(clxt,16).toUpper() + ")" + ", ";
        _s = _s + "lcb: " + QString::number(lcb) + "(" + QString::number(lcb,16).toUpper() + ")" + ", ";
        _s = _s + "PlcPcd: " + "[array of PlcPcd]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class FCompressed : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 fc;
    bool fCompressed;
    bool r1;
    FCompressed() :fc(0), fCompressed(0), r1(0) {
    }
    QString toString() {
        QString _s = "FCompressed:";
        _s = _s + "fc: " + QString::number(fc) + "(" + QString::number(fc,16).toUpper() + ")" + ", ";
        _s = _s + "fCompressed: " + QString::number(fCompressed) + ", ";
        _s = _s + "r1: " + QString::number(r1) + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Prm0 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    bool fComplex;
    quint8 isprm;
    quint8 val;
    Prm0() :fComplex(0), isprm(0), val(0) {
    }
    QString toString() {
        QString _s = "Prm0:";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
        _s = _s + "isprm: " + QString::number(isprm) + "(" + QString::number(isprm,16).toUpper() + ")" + ", ";
        _s = _s + "val: " + QString::number(val) + "(" + QString::number(val,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Prm1 : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    bool fComplex;
    quint16 igrpprl;
    Prm1() :fComplex(0), igrpprl(0) {
    }
    QString toString() {
        QString _s = "Prm1:";
        _s = _s + "fComplex: " + QString::number(fComplex) + ", ";
        _s = _s + "igrpprl: " + QString::number(igrpprl) + "(" + QString::number(igrpprl,16).toUpper() + ")" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SttbfFfn : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint16 cData;
    quint16 cbExtra;
    QVector<SttbfFfnEntry> data;
    SttbfFfn() :cData(0), cbExtra(0) {
    }
    QString toString() {
        QString _s = "SttbfFfn:";
        _s = _s + "cData: " + QString::number(cData) + "(" + QString::number(cData,16).toUpper() + ")" + ", ";
        _s = _s + "cbExtra: " + QString::number(cbExtra) + "(" + QString::number(cbExtra,16).toUpper() + ")" + ", ";
        _s = _s + "data: " + "[array of data]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SttbfFfnEntry : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 cchData;
    QByteArray Data;
    SttbfFfnEntry() :cchData(0) {
    }
    QString toString() {
        QString _s = "SttbfFfnEntry:";
        _s = _s + "cchData: " + QString::number(cchData) + "(" + QString::number(cchData,16).toUpper() + ")" + ", ";
        _s = _s + "Data: " + "[array of Data]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PicturesStream : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtBStoreDelay anon1;
    PicturesStream()  {
    }
    QString toString() {
        QString _s = "PicturesStream:";
        _s = _s + "anon1: " + anon1.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtMetafileHeader : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint32 cbSize;
    RECT rcBounds;
    POINT ptSize;
    quint32 cbsave;
    quint8 compression;
    quint8 filter;
    OfficeArtMetafileHeader() :cbSize(0), cbsave(0), compression(0), filter(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class NormalViewSetInfoAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    RatioStruct leftPortion;
    RatioStruct topPortion;
    quint8 vertBarState;
    quint8 horizBarState;
    quint8 fPreferSingleSet;
    bool fHideThumbnails;
    bool fBarSnapped;
    quint8 reserved;
    NormalViewSetInfoAtom() :vertBarState(0), horizBarState(0), fPreferSingleSet(0), fHideThumbnails(0), fBarSnapped(0), reserved(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MasterPersistAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    MasterPersistAtom() :reserved1(0), fNonOutLineData(0), reserved2(0), reserved3(0), reserved4(0), reserved5(0), masterId(0), reserved6(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlidePersistAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    SlidePersistAtom() :reserved1(0), fShouldCollapse(0), fNonOutlineData(0), reserved2(0), reserved3(0), reserved4(0), cTexts(0), reserved5(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextRuler : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    TextRuler() :fDefaultTabSize(0), fCLevels(0), fTabStops(0), fLeftMargin1(0), fLeftMargin2(0), fLeftMargin3(0), fLeftMargin4(0), fLeftMargin5(0), fIndent1(0), fIndent2(0), fIndent3(0), fIndent4(0), fIndent5(0), reserved1(0), reserved2(0), cLevels(0), defaultTabSize(0), leftMargin1(0), indent1(0), leftMargin2(0), indent2(0), leftMargin3(0), indent3(0), leftMargin4(0), indent4(0), leftMargin5(0), indent5(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextPFException : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    TextPFException() :bulletChar(0), bulletFontRef(0), bulletSize(0), bulletColor(0), textAlignment(0), lineSpacing(0), spaceBefore(0), spaceAfter(0), leftMargin(0), indent(0), defaultTabSize(0), fontAlign(0), wrapFlags(0), textDirection(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextCFException : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    CFMasks masks;
    CFStyle fontStyle;
    quint16 fontRef;
    quint16 oldEAFontRef;
    quint16 ansiFontRef;
    quint16 symbolFontRef;
    quint16 fontSize;
    quint32 color;
    quint16 position;
    TextCFException() :fontRef(0), oldEAFontRef(0), ansiFontRef(0), symbolFontRef(0), fontSize(0), color(0), position(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class KinsokuContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    KinsokuAtom kinsokuAtom;
    KinsokuContainer()  {
    }
    QString toString() {
        QString _s = "KinsokuContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "kinsokuAtom: " + kinsokuAtom.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextMasterStyleLevel : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    TextPFException pf;
    TextCFException cf;
    TextMasterStyleLevel()  {
    }
    QString toString() {
        QString _s = "TextMasterStyleLevel:";
        _s = _s + "pf: " + pf.toString() + ", ";
        _s = _s + "cf: " + cf.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DocumentAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    DocumentAtom() :firstSlideNumber(0), slideSizeType(0), fSaveWithFonts(0), fOmitTitlePlace(0), fRightToLeft(0), fShowComments(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExObjListContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    ExObjListAtom exObjListAtom;
    QVector<ExObjListSubContainer> rgChildRec;
    ExObjListContainer()  {
    }
    QString toString() {
        QString _s = "ExObjListContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "exObjListAtom: " + exObjListAtom.toString() + ", ";
        _s = _s + "rgChildRec: " + "[array of rgChildRec]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExOleLinkContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    ExOleLinkAtom exOleLinkAtom;
    ExOleObjAtom exOleObjAtom;
    QSharedPointer<MenuNameAtom> menuNameAtom;
    QSharedPointer<ProgIDAtom> progIdAtom;
    QSharedPointer<ClipboardNameAtom> clipboardNameAtom;
    QSharedPointer<MetafileBlob> metafile;
    ExOleLinkContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExOleEmbedContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    ExOleEmbedAtom exOleEmbedAtom;
    ExOleObjAtom exOleObjAtom;
    QSharedPointer<MenuNameAtom> menuNameAtom;
    QSharedPointer<ProgIDAtom> progIdAtom;
    QSharedPointer<ClipboardNameAtom> clipboardNameAtom;
    QSharedPointer<MetafileBlob> metafile;
    ExOleEmbedContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFDGGBlock : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    OfficeArtFDGG head;
    QVector<OfficeArtIDCL> Rgidcl;
    OfficeArtFDGGBlock()  {
    }
    QString toString() {
        QString _s = "OfficeArtFDGGBlock:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "head: " + head.toString() + ", ";
        _s = _s + "Rgidcl: " + "[array of Rgidcl]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtClientAnchor : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    SmallRectStruct rect1;
    RectStruct rect2;
    OfficeArtClientAnchor()  {
    }
    QString toString() {
        QString _s = "OfficeArtClientAnchor:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rect1: " + rect1.toString() + ", ";
        _s = _s + "rect2: " + rect2.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtClientData : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    OfficeArtClientData()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFOPTE : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtFOPTEOPID opid;
    qint32 op;
    QByteArray complexData;
    OfficeArtFOPTE() :op(0) {
    }
    QString toString() {
        QString _s = "OfficeArtFOPTE:";
        _s = _s + "opid: " + opid.toString() + ", ";
        _s = _s + "op: " + QString::number(op) + "(" + QString::number(op,16).toUpper() + ")" + ", ";
        _s = _s + "complexData: " + "[array of complexData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Fib : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    Fib() :csw(0), cslw(0), cbRgFcLcb(0), cswNew(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class STSH : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    LPStshi lpstshi;
    QVector<LPStd> rglpstd;
    STSH()  {
    }
    QString toString() {
        QString _s = "STSH:";
        _s = _s + "lpstshi: " + lpstshi.toString() + ", ";
        _s = _s + "rglpstd: " + "[array of rglpstd]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Clx : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    QList<Pcr> RgPrc;
    Pcdt pcdt;
    Clx()  {
    }
    QString toString() {
        QString _s = "Clx:";
        _s = _s + "RgPrc: " + "[array of RgPrc]" + ", ";
        _s = _s + "pcdt: " + pcdt.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Pcr : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    quint8 clxt;
    PrcData prcData;
    Pcr() :clxt(0) {
    }
    QString toString() {
        QString _s = "Pcr:";
        _s = _s + "clxt: " + QString::number(clxt) + "(" + QString::number(clxt,16).toUpper() + ")" + ", ";
        _s = _s + "prcData: " + prcData.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Prm : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    class prmChoice {public:QSharedPointer<Prm0> prm0;
QSharedPointer<Prm1> prm1;
}; prmChoice prm;
    Prm()  {
    }
    QString toString() {
        QString _s = "Prm:";
        _s = _s + "prm: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipEMF : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
    OfficeArtBlipEMF()  {
    }
    QString toString() {
        QString _s = "OfficeArtBlipEMF:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "metafileHeader: " + metafileHeader.toString() + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipWMF : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
    OfficeArtBlipWMF()  {
    }
    QString toString() {
        QString _s = "OfficeArtBlipWMF:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "metafileHeader: " + metafileHeader.toString() + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlipPICT : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
    OfficeArtBlipPICT()  {
    }
    QString toString() {
        QString _s = "OfficeArtBlipPICT:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "rgbUid1: " + "[array of rgbUid1]" + ", ";
        _s = _s + "rgbUid2: " + "[array of rgbUid2]" + ", ";
        _s = _s + "metafileHeader: " + metafileHeader.toString() + ", ";
        _s = _s + "BLIPFileData: " + "[array of BLIPFileData]" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBlip : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    class anonChoice {public:QSharedPointer<OfficeArtBlipEMF> officeartblipemf;
QSharedPointer<OfficeArtBlipWMF> officeartblipwmf;
QSharedPointer<OfficeArtBlipPICT> officeartblippict;
QSharedPointer<OfficeArtBlipJPEG> officeartblipjpeg;
QSharedPointer<OfficeArtBlipPNG> officeartblippng;
QSharedPointer<OfficeArtBlipDIB> officeartblipdib;
QSharedPointer<OfficeArtBlipTIFF> officeartbliptiff;
}; anonChoice anon;
    OfficeArtBlip()  {
    }
    QString toString() {
        QString _s = "OfficeArtBlip:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class NormalViewSetInfoContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    NormalViewSetInfoAtom normalViewSetInfoAtom;
    NormalViewSetInfoContainer()  {
    }
    QString toString() {
        QString _s = "NormalViewSetInfoContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "normalViewSetInfoAtom: " + normalViewSetInfoAtom.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideListWithTextSubContainerOrAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    SlideListWithTextSubContainerOrAtom()  {
    }
    QString toString() {
        QString _s = "SlideListWithTextSubContainerOrAtom:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextCFExceptionAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    TextCFException cf;
    TextCFExceptionAtom()  {
    }
    QString toString() {
        QString _s = "TextCFExceptionAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "cf: " + cf.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DefaultRulerAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    TextRuler defaultTextRuler;
    DefaultRulerAtom()  {
    }
    QString toString() {
        QString _s = "DefaultRulerAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "defaultTextRuler: " + defaultTextRuler.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextPFExceptionAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    quint16 reserved;
    TextPFException pf;
    TextPFExceptionAtom() :reserved(0) {
    }
    QString toString() {
        QString _s = "TextPFExceptionAtom:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "reserved: " + QString::number(reserved) + "(" + QString::number(reserved,16).toUpper() + ")" + ", ";
        _s = _s + "pf: " + pf.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class TextMasterStyleAtom : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    TextMasterStyleAtom() :cLevels(0), lstLvl1level(0), lstLvl2level(0), lstLvl3level(0), lstLvl4level(0), lstLvl5level(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class ExObjListSubContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    class anonChoice {public:QSharedPointer<ExOleLinkContainer> exolelinkcontainer;
QSharedPointer<ExOleEmbedContainer> exoleembedcontainer;
}; anonChoice anon;
    ExObjListSubContainer()  {
    }
    QString toString() {
        QString _s = "ExObjListSubContainer:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtDggContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    OfficeArtFDGGBlock drawingGroup;
    QSharedPointer<OfficeArtBStoreContainer> blipStore;
    OfficeArtFOPT drawingPrimaryOptions;
    QSharedPointer<OfficeArtTertiaryFOPT> drawingTertiaryOptions;
    QSharedPointer<OfficeArtColorMRUContainer> colorMRU;
    OfficeArtSplitMenuColorContainer splitColors;
    OfficeArtDggContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtSpContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    OfficeArtSpContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class WordDocument : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    Fib fib;
    WordDocument()  {
    }
    QString toString() {
        QString _s = "WordDocument:";
        _s = _s + "fib: " + fib.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Table : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    STSH stsh;
    PlcfSed plcfSed;
    Plcfhdd plcfHdd;
    PlcBteChpx plcfBteChpx;
    PlcfBtePapx plcfBtePapx;
    Tcg cmds;
    Clx clx;
    SttbfFfn sttbfFfn;
    QByteArray dop;
    Table()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class Pcd : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    bool fNoParaLast;
    bool fR1;
    bool fDirtly;
    bool fR2;
    quint16 fR3;
    FCompressed fc;
    Prm prm;
    Pcd() :fNoParaLast(0), fR1(0), fDirtly(0), fR2(0), fR3(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtFBSE : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    OfficeArtFBSE() :btWin32(0), btMacOS(0), tag(0), size(0), cRef(0), foDelay(0), unused1(0), cbName(0), unused2(0), unused3(0) {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtBStoreContainerFileBlock : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    class anonChoice {public:QSharedPointer<OfficeArtFBSE> officeartfbse;
QSharedPointer<OfficeArtBlip> officeartblip;
}; anonChoice anon;
    OfficeArtBStoreContainerFileBlock()  {
    }
    QString toString() {
        QString _s = "OfficeArtBStoreContainerFileBlock:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DocumentTextInfoContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    QSharedPointer<KinsokuContainer> kinsoku;
    QSharedPointer<FontCollectionContainer> fontCollection;
    QSharedPointer<TextCFExceptionAtom> textCFDefaultsAtom;
    QSharedPointer<TextPFExceptionAtom> textPFDefaultsAtom;
    QSharedPointer<DefaultRulerAtom> defaultRulerAtom;
    TextSIExceptionAtom textSIDefaultsAtom;
    TextMasterStyleAtom textMasterStyleAtom;
    DocumentTextInfoContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DrawingGroupContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    OfficeArtDggContainer OfficeArtDgg;
    DrawingGroupContainer()  {
    }
    QString toString() {
        QString _s = "DrawingGroupContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "OfficeArtDgg: " + OfficeArtDgg.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtDgContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    OfficeArtRecordHeader rh;
    OfficeArtFDG drawingData;
    QSharedPointer<OfficeArtFRITContainer> regroupItems;
    OfficeArtSpgrContainer groupShape;
    OfficeArtSpContainer shape;
    QList<OfficeArtSpgrContainerFileBlock> deletedShapes;
    QSharedPointer<OfficeArtSolverContainer> solvers;
    OfficeArtDgContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class OfficeArtSpgrContainerFileBlock : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    class anonChoice {public:QSharedPointer<OfficeArtSpContainer> officeartspcontainer;
QSharedPointer<OfficeArtSpgrContainer> officeartspgrcontainer;
}; anonChoice anon;
    OfficeArtSpgrContainerFileBlock()  {
    }
    QString toString() {
        QString _s = "OfficeArtSpgrContainerFileBlock:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DocumentContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    DocumentContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class DrawingContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    OfficeArtDgContainer OfficeArtDg;
    DrawingContainer()  {
    }
    QString toString() {
        QString _s = "DrawingContainer:";
        _s = _s + "rh: " + rh.toString() + ", ";
        _s = _s + "OfficeArtDg: " + OfficeArtDg.toString() + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class SlideContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    RecordHeader rh;
    SlideAtom slideAtom;
    QSharedPointer<SlideShowSlideInfoAtom> slideShowSlideInfoAtom;
    QSharedPointer<PerSlideHeadersFootersContainer> perSlideHFContainer;
    DrawingContainer drawing;
    SlideSchemeColorSchemeAtom slideSchemeColorSchemeAtom;
    QSharedPointer<SlideProgTagscontainer> slideProgTagsContainer;
    SlideContainer()  {
    }
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
    const Introspection* getIntrospection() const { return &_introspection; }
};
class MasterOrSlideContainer : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
    class anonChoice {public:QSharedPointer<MainMasterContainer> mainmastercontainer;
QSharedPointer<SlideContainer> slidecontainer;
}; anonChoice anon;
    MasterOrSlideContainer()  {
    }
    QString toString() {
        QString _s = "MasterOrSlideContainer:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class PowerPointStruct : public Introspectable {
private:
    class _Introspection;
public:
    static const Introspection _introspection;
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
    PowerPointStruct()  {
    }
    QString toString() {
        QString _s = "PowerPointStruct:";
        _s = _s + "anon: " + "<choice>" + ", ";
        return _s;
    }
    const Introspection* getIntrospection() const { return &_introspection; }
};
class RecordHeader::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_recVer(const Introspectable* i, int j) {
        return (static_cast<const RecordHeader*>(i)->recVer);
    }
    static QVariant get_recInstance(const Introspectable* i, int j) {
        return (static_cast<const RecordHeader*>(i)->recInstance);
    }
    static QVariant get_recType(const Introspectable* i, int j) {
        return (static_cast<const RecordHeader*>(i)->recType);
    }
    static QVariant get_recLen(const Introspectable* i, int j) {
        return (static_cast<const RecordHeader*>(i)->recLen);
    }
};
const QString RecordHeader::_Introspection::name("RecordHeader");
const int RecordHeader::_Introspection::numberOfMembers(4);
const QString RecordHeader::_Introspection::names[4] = {
    "recVer",
    "recInstance",
    "recType",
    "recLen",
};
int (* const RecordHeader::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const RecordHeader::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_recVer,
    _Introspection::get_recInstance,
    _Introspection::get_recType,
    _Introspection::get_recLen,
};
const Introspectable* (* const RecordHeader::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection RecordHeader::_introspection(
    "RecordHeader", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class CurrentUserAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[12];
    static int (* const numberOfInstances[12])(const Introspectable*);
    static QVariant (* const value[12])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[12])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const CurrentUserAtom*>(i)->rh);
    }
    static QVariant get_size(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->size);
    }
    static QVariant get_headerToken(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->headerToken);
    }
    static QVariant get_offsetToCurrentEdit(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->offsetToCurrentEdit);
    }
    static QVariant get_lenUserName(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->lenUserName);
    }
    static QVariant get_docFileVersion(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->docFileVersion);
    }
    static QVariant get_majorVersion(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->majorVersion);
    }
    static QVariant get_minorVersion(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->minorVersion);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->unused);
    }
    static QVariant get_ansiUserName(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->ansiUserName);
    }
    static QVariant get_relVersion(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->relVersion);
    }
    static QVariant get_unicodeUserName(const Introspectable* i, int j) {
        return (static_cast<const CurrentUserAtom*>(i)->unicodeUserName);
    }
};
const QString CurrentUserAtom::_Introspection::name("CurrentUserAtom");
const int CurrentUserAtom::_Introspection::numberOfMembers(12);
const QString CurrentUserAtom::_Introspection::names[12] = {
    "rh",
    "size",
    "headerToken",
    "offsetToCurrentEdit",
    "lenUserName",
    "docFileVersion",
    "majorVersion",
    "minorVersion",
    "unused",
    "ansiUserName",
    "relVersion",
    "unicodeUserName",
};
int (* const CurrentUserAtom::_Introspection::numberOfInstances[12])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const CurrentUserAtom::_Introspection::value[12])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_size,
    _Introspection::get_headerToken,
    _Introspection::get_offsetToCurrentEdit,
    _Introspection::get_lenUserName,
    _Introspection::get_docFileVersion,
    _Introspection::get_majorVersion,
    _Introspection::get_minorVersion,
    _Introspection::get_unused,
    _Introspection::get_ansiUserName,
    _Introspection::get_relVersion,
    _Introspection::get_unicodeUserName,
};
const Introspectable* (* const CurrentUserAtom::_Introspection::introspectable[12])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection CurrentUserAtom::_introspection(
    "CurrentUserAtom", 12, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Byte::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static QVariant get_b(const Introspectable* i, int j) {
        return (static_cast<const Byte*>(i)->b);
    }
};
const QString Byte::_Introspection::name("Byte");
const int Byte::_Introspection::numberOfMembers(1);
const QString Byte::_Introspection::names[1] = {
    "b",
};
int (* const Byte::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const Byte::_Introspection::value[1])(const Introspectable*, int position) = {
    _Introspection::get_b,
};
const Introspectable* (* const Byte::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    Introspection::null,
};
const Introspection Byte::_introspection(
    "Byte", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class CurrentUserStream::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_anon1(const Introspectable* i, int j) {
        return &(static_cast<const CurrentUserStream*>(i)->anon1);
    }
    static int count_trailing(const Introspectable* i) {
        return static_cast<const CurrentUserStream*>(i)->trailing.size();
    }
    static const Introspectable* get_trailing(const Introspectable* i, int j) {
        return &(static_cast<const CurrentUserStream*>(i)->trailing[j]);
    }
};
const QString CurrentUserStream::_Introspection::name("CurrentUserStream");
const int CurrentUserStream::_Introspection::numberOfMembers(2);
const QString CurrentUserStream::_Introspection::names[2] = {
    "anon1",
    "trailing",
};
int (* const CurrentUserStream::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_trailing,
};
QVariant (* const CurrentUserStream::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const CurrentUserStream::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_anon1,
    _Introspection::get_trailing,
};
const Introspection CurrentUserStream::_introspection(
    "CurrentUserStream", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBStoreDelay::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static int count_anon1(const Introspectable* i) {
        return static_cast<const OfficeArtBStoreDelay*>(i)->anon1.size();
    }
    static const Introspectable* get_anon1(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBStoreDelay*>(i)->anon1[j]);
    }
};
const QString OfficeArtBStoreDelay::_Introspection::name("OfficeArtBStoreDelay");
const int OfficeArtBStoreDelay::_Introspection::numberOfMembers(1);
const QString OfficeArtBStoreDelay::_Introspection::names[1] = {
    "anon1",
};
int (* const OfficeArtBStoreDelay::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    _Introspection::count_anon1,
};
QVariant (* const OfficeArtBStoreDelay::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtBStoreDelay::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon1,
};
const Introspection OfficeArtBStoreDelay::_introspection(
    "OfficeArtBStoreDelay", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtRecordHeader::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_recVer(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtRecordHeader*>(i)->recVer);
    }
    static QVariant get_recInstance(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtRecordHeader*>(i)->recInstance);
    }
    static QVariant get_recType(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtRecordHeader*>(i)->recType);
    }
    static QVariant get_recLen(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtRecordHeader*>(i)->recLen);
    }
};
const QString OfficeArtRecordHeader::_Introspection::name("OfficeArtRecordHeader");
const int OfficeArtRecordHeader::_Introspection::numberOfMembers(4);
const QString OfficeArtRecordHeader::_Introspection::names[4] = {
    "recVer",
    "recInstance",
    "recType",
    "recLen",
};
int (* const OfficeArtRecordHeader::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtRecordHeader::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_recVer,
    _Introspection::get_recInstance,
    _Introspection::get_recType,
    _Introspection::get_recLen,
};
const Introspectable* (* const OfficeArtRecordHeader::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtRecordHeader::_introspection(
    "OfficeArtRecordHeader", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipJPEG::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipJPEG*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipJPEG*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipJPEG*>(i)->rgbUid2);
    }
    static QVariant get_tag(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipJPEG*>(i)->tag);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipJPEG*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipJPEG::_Introspection::name("OfficeArtBlipJPEG");
const int OfficeArtBlipJPEG::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipJPEG::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "tag",
    "BLIPFileData",
};
int (* const OfficeArtBlipJPEG::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipJPEG::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    _Introspection::get_tag,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipJPEG::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtBlipJPEG::_introspection(
    "OfficeArtBlipJPEG", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipPNG::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipPNG*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPNG*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPNG*>(i)->rgbUid2);
    }
    static QVariant get_tag(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPNG*>(i)->tag);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPNG*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipPNG::_Introspection::name("OfficeArtBlipPNG");
const int OfficeArtBlipPNG::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipPNG::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "tag",
    "BLIPFileData",
};
int (* const OfficeArtBlipPNG::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipPNG::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    _Introspection::get_tag,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipPNG::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtBlipPNG::_introspection(
    "OfficeArtBlipPNG", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipDIB::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipDIB*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipDIB*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipDIB*>(i)->rgbUid2);
    }
    static QVariant get_tag(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipDIB*>(i)->tag);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipDIB*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipDIB::_Introspection::name("OfficeArtBlipDIB");
const int OfficeArtBlipDIB::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipDIB::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "tag",
    "BLIPFileData",
};
int (* const OfficeArtBlipDIB::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipDIB::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    _Introspection::get_tag,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipDIB::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtBlipDIB::_introspection(
    "OfficeArtBlipDIB", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipTIFF::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipTIFF*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipTIFF*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipTIFF*>(i)->rgbUid2);
    }
    static QVariant get_tag(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipTIFF*>(i)->tag);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipTIFF*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipTIFF::_Introspection::name("OfficeArtBlipTIFF");
const int OfficeArtBlipTIFF::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipTIFF::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "tag",
    "BLIPFileData",
};
int (* const OfficeArtBlipTIFF::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipTIFF::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    _Introspection::get_tag,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipTIFF::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtBlipTIFF::_introspection(
    "OfficeArtBlipTIFF", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class RECT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_left(const Introspectable* i, int j) {
        return (static_cast<const RECT*>(i)->left);
    }
    static QVariant get_top(const Introspectable* i, int j) {
        return (static_cast<const RECT*>(i)->top);
    }
    static QVariant get_right(const Introspectable* i, int j) {
        return (static_cast<const RECT*>(i)->right);
    }
    static QVariant get_bottom(const Introspectable* i, int j) {
        return (static_cast<const RECT*>(i)->bottom);
    }
};
const QString RECT::_Introspection::name("RECT");
const int RECT::_Introspection::numberOfMembers(4);
const QString RECT::_Introspection::names[4] = {
    "left",
    "top",
    "right",
    "bottom",
};
int (* const RECT::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const RECT::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_left,
    _Introspection::get_top,
    _Introspection::get_right,
    _Introspection::get_bottom,
};
const Introspectable* (* const RECT::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection RECT::_introspection(
    "RECT", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class POINT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_x(const Introspectable* i, int j) {
        return (static_cast<const POINT*>(i)->x);
    }
    static QVariant get_y(const Introspectable* i, int j) {
        return (static_cast<const POINT*>(i)->y);
    }
};
const QString POINT::_Introspection::name("POINT");
const int POINT::_Introspection::numberOfMembers(2);
const QString POINT::_Introspection::names[2] = {
    "x",
    "y",
};
int (* const POINT::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const POINT::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_x,
    _Introspection::get_y,
};
const Introspectable* (* const POINT::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection POINT::_introspection(
    "POINT", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PowerPointStructs::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static int count_anon(const Introspectable* i) {
        return static_cast<const PowerPointStructs*>(i)->anon.size();
    }
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        return &(static_cast<const PowerPointStructs*>(i)->anon[j]);
    }
};
const QString PowerPointStructs::_Introspection::name("PowerPointStructs");
const int PowerPointStructs::_Introspection::numberOfMembers(1);
const QString PowerPointStructs::_Introspection::names[1] = {
    "anon",
};
int (* const PowerPointStructs::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    _Introspection::count_anon,
};
QVariant (* const PowerPointStructs::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const PowerPointStructs::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection PowerPointStructs::_introspection(
    "PowerPointStructs", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideHeadersFootersContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideHeadersFootersContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const SlideHeadersFootersContainer*>(i)->todo);
    }
};
const QString SlideHeadersFootersContainer::_Introspection::name("SlideHeadersFootersContainer");
const int SlideHeadersFootersContainer::_Introspection::numberOfMembers(2);
const QString SlideHeadersFootersContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const SlideHeadersFootersContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideHeadersFootersContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const SlideHeadersFootersContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection SlideHeadersFootersContainer::_introspection(
    "SlideHeadersFootersContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class NotesHeadersFootersContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const NotesHeadersFootersContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const NotesHeadersFootersContainer*>(i)->todo);
    }
};
const QString NotesHeadersFootersContainer::_Introspection::name("NotesHeadersFootersContainer");
const int NotesHeadersFootersContainer::_Introspection::numberOfMembers(2);
const QString NotesHeadersFootersContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const NotesHeadersFootersContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const NotesHeadersFootersContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const NotesHeadersFootersContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection NotesHeadersFootersContainer::_introspection(
    "NotesHeadersFootersContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PerSlideHeadersFootersContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const PerSlideHeadersFootersContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const PerSlideHeadersFootersContainer*>(i)->todo);
    }
};
const QString PerSlideHeadersFootersContainer::_Introspection::name("PerSlideHeadersFootersContainer");
const int PerSlideHeadersFootersContainer::_Introspection::numberOfMembers(2);
const QString PerSlideHeadersFootersContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const PerSlideHeadersFootersContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const PerSlideHeadersFootersContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const PerSlideHeadersFootersContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection PerSlideHeadersFootersContainer::_introspection(
    "PerSlideHeadersFootersContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class EndDocumentAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const EndDocumentAtom*>(i)->rh);
    }
};
const QString EndDocumentAtom::_Introspection::name("EndDocumentAtom");
const int EndDocumentAtom::_Introspection::numberOfMembers(1);
const QString EndDocumentAtom::_Introspection::names[1] = {
    "rh",
};
int (* const EndDocumentAtom::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const EndDocumentAtom::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const EndDocumentAtom::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_rh,
};
const Introspection EndDocumentAtom::_introspection(
    "EndDocumentAtom", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DocInfoListContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DocInfoListContainer*>(i)->rh);
    }
    static int count_rgChildRec(const Introspectable* i) {
        return static_cast<const DocInfoListContainer*>(i)->rgChildRec.size();
    }
    static const Introspectable* get_rgChildRec(const Introspectable* i, int j) {
        return &(static_cast<const DocInfoListContainer*>(i)->rgChildRec[j]);
    }
};
const QString DocInfoListContainer::_Introspection::name("DocInfoListContainer");
const int DocInfoListContainer::_Introspection::numberOfMembers(2);
const QString DocInfoListContainer::_Introspection::names[2] = {
    "rh",
    "rgChildRec",
};
int (* const DocInfoListContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgChildRec,
};
QVariant (* const DocInfoListContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const DocInfoListContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgChildRec,
};
const Introspection DocInfoListContainer::_introspection(
    "DocInfoListContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DocInfoListSubContainerOrAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DocInfoListSubContainerOrAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const DocInfoListSubContainerOrAtom*>(i)->todo);
    }
};
const QString DocInfoListSubContainerOrAtom::_Introspection::name("DocInfoListSubContainerOrAtom");
const int DocInfoListSubContainerOrAtom::_Introspection::numberOfMembers(2);
const QString DocInfoListSubContainerOrAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const DocInfoListSubContainerOrAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const DocInfoListSubContainerOrAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const DocInfoListSubContainerOrAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection DocInfoListSubContainerOrAtom::_introspection(
    "DocInfoListSubContainerOrAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideViewInfoInstance::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideViewInfoInstance*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const SlideViewInfoInstance*>(i)->todo);
    }
};
const QString SlideViewInfoInstance::_Introspection::name("SlideViewInfoInstance");
const int SlideViewInfoInstance::_Introspection::numberOfMembers(2);
const QString SlideViewInfoInstance::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const SlideViewInfoInstance::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideViewInfoInstance::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const SlideViewInfoInstance::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection SlideViewInfoInstance::_introspection(
    "SlideViewInfoInstance", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MasterListWithTextContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MasterListWithTextContainer*>(i)->rh);
    }
    static int count_rgMasterPersistAtom(const Introspectable* i) {
        return static_cast<const MasterListWithTextContainer*>(i)->rgMasterPersistAtom.size();
    }
    static const Introspectable* get_rgMasterPersistAtom(const Introspectable* i, int j) {
        return &(static_cast<const MasterListWithTextContainer*>(i)->rgMasterPersistAtom[j]);
    }
};
const QString MasterListWithTextContainer::_Introspection::name("MasterListWithTextContainer");
const int MasterListWithTextContainer::_Introspection::numberOfMembers(2);
const QString MasterListWithTextContainer::_Introspection::names[2] = {
    "rh",
    "rgMasterPersistAtom",
};
int (* const MasterListWithTextContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgMasterPersistAtom,
};
QVariant (* const MasterListWithTextContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const MasterListWithTextContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgMasterPersistAtom,
};
const Introspection MasterListWithTextContainer::_introspection(
    "MasterListWithTextContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideListWithTextContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideListWithTextContainer*>(i)->rh);
    }
    static int count_rgChildRec(const Introspectable* i) {
        return static_cast<const SlideListWithTextContainer*>(i)->rgChildRec.size();
    }
    static const Introspectable* get_rgChildRec(const Introspectable* i, int j) {
        return &(static_cast<const SlideListWithTextContainer*>(i)->rgChildRec[j]);
    }
};
const QString SlideListWithTextContainer::_Introspection::name("SlideListWithTextContainer");
const int SlideListWithTextContainer::_Introspection::numberOfMembers(2);
const QString SlideListWithTextContainer::_Introspection::names[2] = {
    "rh",
    "rgChildRec",
};
int (* const SlideListWithTextContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgChildRec,
};
QVariant (* const SlideListWithTextContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const SlideListWithTextContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgChildRec,
};
const Introspection SlideListWithTextContainer::_introspection(
    "SlideListWithTextContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class NotesListWithTextContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const NotesListWithTextContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const NotesListWithTextContainer*>(i)->todo);
    }
};
const QString NotesListWithTextContainer::_Introspection::name("NotesListWithTextContainer");
const int NotesListWithTextContainer::_Introspection::numberOfMembers(2);
const QString NotesListWithTextContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const NotesListWithTextContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const NotesListWithTextContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const NotesListWithTextContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection NotesListWithTextContainer::_introspection(
    "NotesListWithTextContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextHeaderAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextHeaderAtom*>(i)->rh);
    }
    static QVariant get_textType(const Introspectable* i, int j) {
        return (static_cast<const TextHeaderAtom*>(i)->textType);
    }
};
const QString TextHeaderAtom::_Introspection::name("TextHeaderAtom");
const int TextHeaderAtom::_Introspection::numberOfMembers(2);
const QString TextHeaderAtom::_Introspection::names[2] = {
    "rh",
    "textType",
};
int (* const TextHeaderAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextHeaderAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_textType,
};
const Introspectable* (* const TextHeaderAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextHeaderAtom::_introspection(
    "TextHeaderAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextCharsAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextCharsAtom*>(i)->rh);
    }
    static int count_textChars(const Introspectable* i) {
        return static_cast<const TextCharsAtom*>(i)->textChars.size();
    }
    static QVariant get_textChars(const Introspectable* i, int j) {
        return (static_cast<const TextCharsAtom*>(i)->textChars[j]);
    }
};
const QString TextCharsAtom::_Introspection::name("TextCharsAtom");
const int TextCharsAtom::_Introspection::numberOfMembers(2);
const QString TextCharsAtom::_Introspection::names[2] = {
    "rh",
    "textChars",
};
int (* const TextCharsAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_textChars,
};
QVariant (* const TextCharsAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_textChars,
};
const Introspectable* (* const TextCharsAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextCharsAtom::_introspection(
    "TextCharsAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextBytesAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextBytesAtom*>(i)->rh);
    }
    static QVariant get_textChars(const Introspectable* i, int j) {
        return (static_cast<const TextBytesAtom*>(i)->textChars);
    }
};
const QString TextBytesAtom::_Introspection::name("TextBytesAtom");
const int TextBytesAtom::_Introspection::numberOfMembers(2);
const QString TextBytesAtom::_Introspection::names[2] = {
    "rh",
    "textChars",
};
int (* const TextBytesAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextBytesAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_textChars,
};
const Introspectable* (* const TextBytesAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextBytesAtom::_introspection(
    "TextBytesAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MasterTextPropAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MasterTextPropAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const MasterTextPropAtom*>(i)->todo);
    }
};
const QString MasterTextPropAtom::_Introspection::name("MasterTextPropAtom");
const int MasterTextPropAtom::_Introspection::numberOfMembers(2);
const QString MasterTextPropAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const MasterTextPropAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const MasterTextPropAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const MasterTextPropAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection MasterTextPropAtom::_introspection(
    "MasterTextPropAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class StyleTextPropAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const StyleTextPropAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const StyleTextPropAtom*>(i)->todo);
    }
};
const QString StyleTextPropAtom::_Introspection::name("StyleTextPropAtom");
const int StyleTextPropAtom::_Introspection::numberOfMembers(2);
const QString StyleTextPropAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const StyleTextPropAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const StyleTextPropAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const StyleTextPropAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection StyleTextPropAtom::_introspection(
    "StyleTextPropAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideNumberMCAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideNumberMCAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const SlideNumberMCAtom*>(i)->position);
    }
};
const QString SlideNumberMCAtom::_Introspection::name("SlideNumberMCAtom");
const int SlideNumberMCAtom::_Introspection::numberOfMembers(2);
const QString SlideNumberMCAtom::_Introspection::names[2] = {
    "rh",
    "position",
};
int (* const SlideNumberMCAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideNumberMCAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
};
const Introspectable* (* const SlideNumberMCAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection SlideNumberMCAtom::_introspection(
    "SlideNumberMCAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DateTimeMCAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DateTimeMCAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const DateTimeMCAtom*>(i)->position);
    }
    static QVariant get_index(const Introspectable* i, int j) {
        return (static_cast<const DateTimeMCAtom*>(i)->index);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const DateTimeMCAtom*>(i)->unused);
    }
};
const QString DateTimeMCAtom::_Introspection::name("DateTimeMCAtom");
const int DateTimeMCAtom::_Introspection::numberOfMembers(4);
const QString DateTimeMCAtom::_Introspection::names[4] = {
    "rh",
    "position",
    "index",
    "unused",
};
int (* const DateTimeMCAtom::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const DateTimeMCAtom::_Introspection::value[4])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
    _Introspection::get_index,
    _Introspection::get_unused,
};
const Introspectable* (* const DateTimeMCAtom::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection DateTimeMCAtom::_introspection(
    "DateTimeMCAtom", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class GenericDateMCAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const GenericDateMCAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const GenericDateMCAtom*>(i)->position);
    }
};
const QString GenericDateMCAtom::_Introspection::name("GenericDateMCAtom");
const int GenericDateMCAtom::_Introspection::numberOfMembers(2);
const QString GenericDateMCAtom::_Introspection::names[2] = {
    "rh",
    "position",
};
int (* const GenericDateMCAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const GenericDateMCAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
};
const Introspectable* (* const GenericDateMCAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection GenericDateMCAtom::_introspection(
    "GenericDateMCAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class HeaderMCAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const HeaderMCAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const HeaderMCAtom*>(i)->position);
    }
};
const QString HeaderMCAtom::_Introspection::name("HeaderMCAtom");
const int HeaderMCAtom::_Introspection::numberOfMembers(2);
const QString HeaderMCAtom::_Introspection::names[2] = {
    "rh",
    "position",
};
int (* const HeaderMCAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const HeaderMCAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
};
const Introspectable* (* const HeaderMCAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection HeaderMCAtom::_introspection(
    "HeaderMCAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FooterMCAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const FooterMCAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const FooterMCAtom*>(i)->position);
    }
};
const QString FooterMCAtom::_Introspection::name("FooterMCAtom");
const int FooterMCAtom::_Introspection::numberOfMembers(2);
const QString FooterMCAtom::_Introspection::names[2] = {
    "rh",
    "position",
};
int (* const FooterMCAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const FooterMCAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
};
const Introspectable* (* const FooterMCAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection FooterMCAtom::_introspection(
    "FooterMCAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class RTFDateTimeMCAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const RTFDateTimeMCAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const RTFDateTimeMCAtom*>(i)->position);
    }
    static QVariant get_format(const Introspectable* i, int j) {
        return (static_cast<const RTFDateTimeMCAtom*>(i)->format);
    }
};
const QString RTFDateTimeMCAtom::_Introspection::name("RTFDateTimeMCAtom");
const int RTFDateTimeMCAtom::_Introspection::numberOfMembers(3);
const QString RTFDateTimeMCAtom::_Introspection::names[3] = {
    "rh",
    "position",
    "format",
};
int (* const RTFDateTimeMCAtom::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const RTFDateTimeMCAtom::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
    _Introspection::get_format,
};
const Introspectable* (* const RTFDateTimeMCAtom::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
};
const Introspection RTFDateTimeMCAtom::_introspection(
    "RTFDateTimeMCAtom", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextBookmarkAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextBookmarkAtom*>(i)->rh);
    }
    static QVariant get_begin(const Introspectable* i, int j) {
        return (static_cast<const TextBookmarkAtom*>(i)->begin);
    }
    static QVariant get_end(const Introspectable* i, int j) {
        return (static_cast<const TextBookmarkAtom*>(i)->end);
    }
    static QVariant get_bookmarkID(const Introspectable* i, int j) {
        return (static_cast<const TextBookmarkAtom*>(i)->bookmarkID);
    }
};
const QString TextBookmarkAtom::_Introspection::name("TextBookmarkAtom");
const int TextBookmarkAtom::_Introspection::numberOfMembers(4);
const QString TextBookmarkAtom::_Introspection::names[4] = {
    "rh",
    "begin",
    "end",
    "bookmarkID",
};
int (* const TextBookmarkAtom::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextBookmarkAtom::_Introspection::value[4])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_begin,
    _Introspection::get_end,
    _Introspection::get_bookmarkID,
};
const Introspectable* (* const TextBookmarkAtom::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection TextBookmarkAtom::_introspection(
    "TextBookmarkAtom", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextSpecialInfoAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextSpecialInfoAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const TextSpecialInfoAtom*>(i)->todo);
    }
};
const QString TextSpecialInfoAtom::_Introspection::name("TextSpecialInfoAtom");
const int TextSpecialInfoAtom::_Introspection::numberOfMembers(2);
const QString TextSpecialInfoAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const TextSpecialInfoAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextSpecialInfoAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const TextSpecialInfoAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextSpecialInfoAtom::_introspection(
    "TextSpecialInfoAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class InteractiveInfoInstance::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const InteractiveInfoInstance*>(i)->rh);
    }
    static QVariant get_range(const Introspectable* i, int j) {
        return (static_cast<const InteractiveInfoInstance*>(i)->range);
    }
};
const QString InteractiveInfoInstance::_Introspection::name("InteractiveInfoInstance");
const int InteractiveInfoInstance::_Introspection::numberOfMembers(2);
const QString InteractiveInfoInstance::_Introspection::names[2] = {
    "rh",
    "range",
};
int (* const InteractiveInfoInstance::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const InteractiveInfoInstance::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_range,
};
const Introspectable* (* const InteractiveInfoInstance::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection InteractiveInfoInstance::_introspection(
    "InteractiveInfoInstance", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextInteractiveInfoInstance::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextInteractiveInfoInstance*>(i)->rh);
    }
    static QVariant get_range(const Introspectable* i, int j) {
        return (static_cast<const TextInteractiveInfoInstance*>(i)->range);
    }
};
const QString TextInteractiveInfoInstance::_Introspection::name("TextInteractiveInfoInstance");
const int TextInteractiveInfoInstance::_Introspection::numberOfMembers(2);
const QString TextInteractiveInfoInstance::_Introspection::names[2] = {
    "rh",
    "range",
};
int (* const TextInteractiveInfoInstance::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextInteractiveInfoInstance::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_range,
};
const Introspectable* (* const TextInteractiveInfoInstance::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextInteractiveInfoInstance::_introspection(
    "TextInteractiveInfoInstance", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideId::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static QVariant get_slideId(const Introspectable* i, int j) {
        return (static_cast<const SlideId*>(i)->slideId);
    }
};
const QString SlideId::_Introspection::name("SlideId");
const int SlideId::_Introspection::numberOfMembers(1);
const QString SlideId::_Introspection::names[1] = {
    "slideId",
};
int (* const SlideId::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const SlideId::_Introspection::value[1])(const Introspectable*, int position) = {
    _Introspection::get_slideId,
};
const Introspectable* (* const SlideId::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    Introspection::null,
};
const Introspection SlideId::_introspection(
    "SlideId", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TabStops::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_count(const Introspectable* i, int j) {
        return (static_cast<const TabStops*>(i)->count);
    }
    static int count_rgTabStop(const Introspectable* i) {
        return static_cast<const TabStops*>(i)->rgTabStop.size();
    }
    static const Introspectable* get_rgTabStop(const Introspectable* i, int j) {
        return &(static_cast<const TabStops*>(i)->rgTabStop[j]);
    }
};
const QString TabStops::_Introspection::name("TabStops");
const int TabStops::_Introspection::numberOfMembers(2);
const QString TabStops::_Introspection::names[2] = {
    "count",
    "rgTabStop",
};
int (* const TabStops::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgTabStop,
};
QVariant (* const TabStops::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_count,
    Introspection::nullValue,
};
const Introspectable* (* const TabStops::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    _Introspection::get_rgTabStop,
};
const Introspection TabStops::_introspection(
    "TabStops", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TabStop::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const TabStop*>(i)->position);
    }
    static QVariant get_type(const Introspectable* i, int j) {
        return (static_cast<const TabStop*>(i)->type);
    }
};
const QString TabStop::_Introspection::name("TabStop");
const int TabStop::_Introspection::numberOfMembers(2);
const QString TabStop::_Introspection::names[2] = {
    "position",
    "type",
};
int (* const TabStop::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TabStop::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_position,
    _Introspection::get_type,
};
const Introspectable* (* const TabStop::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection TabStop::_introspection(
    "TabStop", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class BulletFlags::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static QVariant get_fHasBullet(const Introspectable* i, int j) {
        return (static_cast<const BulletFlags*>(i)->fHasBullet);
    }
    static QVariant get_fBulletHasFont(const Introspectable* i, int j) {
        return (static_cast<const BulletFlags*>(i)->fBulletHasFont);
    }
    static QVariant get_fBulletHasColor(const Introspectable* i, int j) {
        return (static_cast<const BulletFlags*>(i)->fBulletHasColor);
    }
    static QVariant get_fBulletHasSize(const Introspectable* i, int j) {
        return (static_cast<const BulletFlags*>(i)->fBulletHasSize);
    }
    static QVariant get_reserved(const Introspectable* i, int j) {
        return (static_cast<const BulletFlags*>(i)->reserved);
    }
};
const QString BulletFlags::_Introspection::name("BulletFlags");
const int BulletFlags::_Introspection::numberOfMembers(5);
const QString BulletFlags::_Introspection::names[5] = {
    "fHasBullet",
    "fBulletHasFont",
    "fBulletHasColor",
    "fBulletHasSize",
    "reserved",
};
int (* const BulletFlags::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const BulletFlags::_Introspection::value[5])(const Introspectable*, int position) = {
    _Introspection::get_fHasBullet,
    _Introspection::get_fBulletHasFont,
    _Introspection::get_fBulletHasColor,
    _Introspection::get_fBulletHasSize,
    _Introspection::get_reserved,
};
const Introspectable* (* const BulletFlags::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection BulletFlags::_introspection(
    "BulletFlags", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PFMasks::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[27];
    static int (* const numberOfInstances[27])(const Introspectable*);
    static QVariant (* const value[27])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[27])(const Introspectable*, int position);
    static QVariant get_hasBullet(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->hasBullet);
    }
    static QVariant get_bulletHasFont(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletHasFont);
    }
    static QVariant get_bulletHasColor(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletHasColor);
    }
    static QVariant get_bulletHasSize(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletHasSize);
    }
    static QVariant get_bulletFont(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletFont);
    }
    static QVariant get_bulletColor(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletColor);
    }
    static QVariant get_bulletSize(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletSize);
    }
    static QVariant get_bulletChar(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletChar);
    }
    static QVariant get_leftMargin(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->leftMargin);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->unused);
    }
    static QVariant get_indent(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->indent);
    }
    static QVariant get_align(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->align);
    }
    static QVariant get_lineSpacing(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->lineSpacing);
    }
    static QVariant get_spaceBefore(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->spaceBefore);
    }
    static QVariant get_spaceAfter(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->spaceAfter);
    }
    static QVariant get_defaultTabSize(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->defaultTabSize);
    }
    static QVariant get_fontAlign(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->fontAlign);
    }
    static QVariant get_charWrap(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->charWrap);
    }
    static QVariant get_wordWrap(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->wordWrap);
    }
    static QVariant get_overflow(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->overflow);
    }
    static QVariant get_tabStops(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->tabStops);
    }
    static QVariant get_textDirection(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->textDirection);
    }
    static QVariant get_reserved(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->reserved);
    }
    static QVariant get_bulletBlip(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletBlip);
    }
    static QVariant get_bulletScheme(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletScheme);
    }
    static QVariant get_bulletHasScheme(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->bulletHasScheme);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const PFMasks*>(i)->reserved2);
    }
};
const QString PFMasks::_Introspection::name("PFMasks");
const int PFMasks::_Introspection::numberOfMembers(27);
const QString PFMasks::_Introspection::names[27] = {
    "hasBullet",
    "bulletHasFont",
    "bulletHasColor",
    "bulletHasSize",
    "bulletFont",
    "bulletColor",
    "bulletSize",
    "bulletChar",
    "leftMargin",
    "unused",
    "indent",
    "align",
    "lineSpacing",
    "spaceBefore",
    "spaceAfter",
    "defaultTabSize",
    "fontAlign",
    "charWrap",
    "wordWrap",
    "overflow",
    "tabStops",
    "textDirection",
    "reserved",
    "bulletBlip",
    "bulletScheme",
    "bulletHasScheme",
    "reserved2",
};
int (* const PFMasks::_Introspection::numberOfInstances[27])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const PFMasks::_Introspection::value[27])(const Introspectable*, int position) = {
    _Introspection::get_hasBullet,
    _Introspection::get_bulletHasFont,
    _Introspection::get_bulletHasColor,
    _Introspection::get_bulletHasSize,
    _Introspection::get_bulletFont,
    _Introspection::get_bulletColor,
    _Introspection::get_bulletSize,
    _Introspection::get_bulletChar,
    _Introspection::get_leftMargin,
    _Introspection::get_unused,
    _Introspection::get_indent,
    _Introspection::get_align,
    _Introspection::get_lineSpacing,
    _Introspection::get_spaceBefore,
    _Introspection::get_spaceAfter,
    _Introspection::get_defaultTabSize,
    _Introspection::get_fontAlign,
    _Introspection::get_charWrap,
    _Introspection::get_wordWrap,
    _Introspection::get_overflow,
    _Introspection::get_tabStops,
    _Introspection::get_textDirection,
    _Introspection::get_reserved,
    _Introspection::get_bulletBlip,
    _Introspection::get_bulletScheme,
    _Introspection::get_bulletHasScheme,
    _Introspection::get_reserved2,
};
const Introspectable* (* const PFMasks::_Introspection::introspectable[27])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection PFMasks::_introspection(
    "PFMasks", 27, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class CFMasks::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[24];
    static int (* const numberOfInstances[24])(const Introspectable*);
    static QVariant (* const value[24])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[24])(const Introspectable*, int position);
    static QVariant get_bold(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->bold);
    }
    static QVariant get_italic(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->italic);
    }
    static QVariant get_underline(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->underline);
    }
    static QVariant get_unused1(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->unused1);
    }
    static QVariant get_shadow(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->shadow);
    }
    static QVariant get_fehint(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->fehint);
    }
    static QVariant get_unused2(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->unused2);
    }
    static QVariant get_kumi(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->kumi);
    }
    static QVariant get_unused3(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->unused3);
    }
    static QVariant get_emboss(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->emboss);
    }
    static QVariant get_fHasStyle(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->fHasStyle);
    }
    static QVariant get_unused4(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->unused4);
    }
    static QVariant get_typeface(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->typeface);
    }
    static QVariant get_size(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->size);
    }
    static QVariant get_color(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->color);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->position);
    }
    static QVariant get_pp10ext(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->pp10ext);
    }
    static QVariant get_oldEATypeface(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->oldEATypeface);
    }
    static QVariant get_ansiTypeface(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->ansiTypeface);
    }
    static QVariant get_symbolTypeface(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->symbolTypeface);
    }
    static QVariant get_newEATypeface(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->newEATypeface);
    }
    static QVariant get_csTypeface(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->csTypeface);
    }
    static QVariant get_pp11ext(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->pp11ext);
    }
    static QVariant get_reserved(const Introspectable* i, int j) {
        return (static_cast<const CFMasks*>(i)->reserved);
    }
};
const QString CFMasks::_Introspection::name("CFMasks");
const int CFMasks::_Introspection::numberOfMembers(24);
const QString CFMasks::_Introspection::names[24] = {
    "bold",
    "italic",
    "underline",
    "unused1",
    "shadow",
    "fehint",
    "unused2",
    "kumi",
    "unused3",
    "emboss",
    "fHasStyle",
    "unused4",
    "typeface",
    "size",
    "color",
    "position",
    "pp10ext",
    "oldEATypeface",
    "ansiTypeface",
    "symbolTypeface",
    "newEATypeface",
    "csTypeface",
    "pp11ext",
    "reserved",
};
int (* const CFMasks::_Introspection::numberOfInstances[24])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const CFMasks::_Introspection::value[24])(const Introspectable*, int position) = {
    _Introspection::get_bold,
    _Introspection::get_italic,
    _Introspection::get_underline,
    _Introspection::get_unused1,
    _Introspection::get_shadow,
    _Introspection::get_fehint,
    _Introspection::get_unused2,
    _Introspection::get_kumi,
    _Introspection::get_unused3,
    _Introspection::get_emboss,
    _Introspection::get_fHasStyle,
    _Introspection::get_unused4,
    _Introspection::get_typeface,
    _Introspection::get_size,
    _Introspection::get_color,
    _Introspection::get_position,
    _Introspection::get_pp10ext,
    _Introspection::get_oldEATypeface,
    _Introspection::get_ansiTypeface,
    _Introspection::get_symbolTypeface,
    _Introspection::get_newEATypeface,
    _Introspection::get_csTypeface,
    _Introspection::get_pp11ext,
    _Introspection::get_reserved,
};
const Introspectable* (* const CFMasks::_Introspection::introspectable[24])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection CFMasks::_introspection(
    "CFMasks", 24, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class CFStyle::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[12];
    static int (* const numberOfInstances[12])(const Introspectable*);
    static QVariant (* const value[12])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[12])(const Introspectable*, int position);
    static QVariant get_bold(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->bold);
    }
    static QVariant get_italic(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->italic);
    }
    static QVariant get_underline(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->underline);
    }
    static QVariant get_unused1(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->unused1);
    }
    static QVariant get_shadow(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->shadow);
    }
    static QVariant get_fehint(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->fehint);
    }
    static QVariant get_unused2(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->unused2);
    }
    static QVariant get_kumi(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->kumi);
    }
    static QVariant get_unused3(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->unused3);
    }
    static QVariant get_emboss(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->emboss);
    }
    static QVariant get_pp9rt(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->pp9rt);
    }
    static QVariant get_unused4(const Introspectable* i, int j) {
        return (static_cast<const CFStyle*>(i)->unused4);
    }
};
const QString CFStyle::_Introspection::name("CFStyle");
const int CFStyle::_Introspection::numberOfMembers(12);
const QString CFStyle::_Introspection::names[12] = {
    "bold",
    "italic",
    "underline",
    "unused1",
    "shadow",
    "fehint",
    "unused2",
    "kumi",
    "unused3",
    "emboss",
    "pp9rt",
    "unused4",
};
int (* const CFStyle::_Introspection::numberOfInstances[12])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const CFStyle::_Introspection::value[12])(const Introspectable*, int position) = {
    _Introspection::get_bold,
    _Introspection::get_italic,
    _Introspection::get_underline,
    _Introspection::get_unused1,
    _Introspection::get_shadow,
    _Introspection::get_fehint,
    _Introspection::get_unused2,
    _Introspection::get_kumi,
    _Introspection::get_unused3,
    _Introspection::get_emboss,
    _Introspection::get_pp9rt,
    _Introspection::get_unused4,
};
const Introspectable* (* const CFStyle::_Introspection::introspectable[12])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection CFStyle::_introspection(
    "CFStyle", 12, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FontCollectionContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const FontCollectionContainer*>(i)->rh);
    }
    static QVariant get_rgFontCollectionEntry(const Introspectable* i, int j) {
        return (static_cast<const FontCollectionContainer*>(i)->rgFontCollectionEntry);
    }
};
const QString FontCollectionContainer::_Introspection::name("FontCollectionContainer");
const int FontCollectionContainer::_Introspection::numberOfMembers(2);
const QString FontCollectionContainer::_Introspection::names[2] = {
    "rh",
    "rgFontCollectionEntry",
};
int (* const FontCollectionContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const FontCollectionContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgFontCollectionEntry,
};
const Introspectable* (* const FontCollectionContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection FontCollectionContainer::_introspection(
    "FontCollectionContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FontEntityAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const FontEntityAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const FontEntityAtom*>(i)->todo);
    }
};
const QString FontEntityAtom::_Introspection::name("FontEntityAtom");
const int FontEntityAtom::_Introspection::numberOfMembers(2);
const QString FontEntityAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const FontEntityAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const FontEntityAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const FontEntityAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection FontEntityAtom::_introspection(
    "FontEntityAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class KinsokuAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const KinsokuAtom*>(i)->rh);
    }
    static QVariant get_level(const Introspectable* i, int j) {
        return (static_cast<const KinsokuAtom*>(i)->level);
    }
};
const QString KinsokuAtom::_Introspection::name("KinsokuAtom");
const int KinsokuAtom::_Introspection::numberOfMembers(2);
const QString KinsokuAtom::_Introspection::names[2] = {
    "rh",
    "level",
};
int (* const KinsokuAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const KinsokuAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_level,
};
const Introspectable* (* const KinsokuAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection KinsokuAtom::_introspection(
    "KinsokuAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextSIExceptionAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextSIExceptionAtom*>(i)->rh);
    }
    static QVariant get_textSIException(const Introspectable* i, int j) {
        return (static_cast<const TextSIExceptionAtom*>(i)->textSIException);
    }
};
const QString TextSIExceptionAtom::_Introspection::name("TextSIExceptionAtom");
const int TextSIExceptionAtom::_Introspection::numberOfMembers(2);
const QString TextSIExceptionAtom::_Introspection::names[2] = {
    "rh",
    "textSIException",
};
int (* const TextSIExceptionAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextSIExceptionAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_textSIException,
};
const Introspectable* (* const TextSIExceptionAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextSIExceptionAtom::_introspection(
    "TextSIExceptionAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExOleEmbedAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[6];
    static int (* const numberOfInstances[6])(const Introspectable*);
    static QVariant (* const value[6])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[6])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExOleEmbedAtom*>(i)->rh);
    }
    static QVariant get_exColorFollow(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedAtom*>(i)->exColorFollow);
    }
    static QVariant get_fCantLockServer(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedAtom*>(i)->fCantLockServer);
    }
    static QVariant get_fNoSizeToServer(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedAtom*>(i)->fNoSizeToServer);
    }
    static QVariant get_fIsTable(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedAtom*>(i)->fIsTable);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedAtom*>(i)->unused);
    }
};
const QString ExOleEmbedAtom::_Introspection::name("ExOleEmbedAtom");
const int ExOleEmbedAtom::_Introspection::numberOfMembers(6);
const QString ExOleEmbedAtom::_Introspection::names[6] = {
    "rh",
    "exColorFollow",
    "fCantLockServer",
    "fNoSizeToServer",
    "fIsTable",
    "unused",
};
int (* const ExOleEmbedAtom::_Introspection::numberOfInstances[6])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExOleEmbedAtom::_Introspection::value[6])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_exColorFollow,
    _Introspection::get_fCantLockServer,
    _Introspection::get_fNoSizeToServer,
    _Introspection::get_fIsTable,
    _Introspection::get_unused,
};
const Introspectable* (* const ExOleEmbedAtom::_Introspection::introspectable[6])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection ExOleEmbedAtom::_introspection(
    "ExOleEmbedAtom", 6, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PointStruct::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_x(const Introspectable* i, int j) {
        return (static_cast<const PointStruct*>(i)->x);
    }
    static QVariant get_y(const Introspectable* i, int j) {
        return (static_cast<const PointStruct*>(i)->y);
    }
};
const QString PointStruct::_Introspection::name("PointStruct");
const int PointStruct::_Introspection::numberOfMembers(2);
const QString PointStruct::_Introspection::names[2] = {
    "x",
    "y",
};
int (* const PointStruct::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const PointStruct::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_x,
    _Introspection::get_y,
};
const Introspectable* (* const PointStruct::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection PointStruct::_introspection(
    "PointStruct", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class RatioStruct::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_numer(const Introspectable* i, int j) {
        return (static_cast<const RatioStruct*>(i)->numer);
    }
    static QVariant get_denom(const Introspectable* i, int j) {
        return (static_cast<const RatioStruct*>(i)->denom);
    }
};
const QString RatioStruct::_Introspection::name("RatioStruct");
const int RatioStruct::_Introspection::numberOfMembers(2);
const QString RatioStruct::_Introspection::names[2] = {
    "numer",
    "denom",
};
int (* const RatioStruct::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const RatioStruct::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_numer,
    _Introspection::get_denom,
};
const Introspectable* (* const RatioStruct::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection RatioStruct::_introspection(
    "RatioStruct", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PersistDirectoryAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const PersistDirectoryAtom*>(i)->rh);
    }
    static int count_rgPersistDirEntry(const Introspectable* i) {
        return static_cast<const PersistDirectoryAtom*>(i)->rgPersistDirEntry.size();
    }
    static const Introspectable* get_rgPersistDirEntry(const Introspectable* i, int j) {
        return &(static_cast<const PersistDirectoryAtom*>(i)->rgPersistDirEntry[j]);
    }
};
const QString PersistDirectoryAtom::_Introspection::name("PersistDirectoryAtom");
const int PersistDirectoryAtom::_Introspection::numberOfMembers(2);
const QString PersistDirectoryAtom::_Introspection::names[2] = {
    "rh",
    "rgPersistDirEntry",
};
int (* const PersistDirectoryAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgPersistDirEntry,
};
QVariant (* const PersistDirectoryAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const PersistDirectoryAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgPersistDirEntry,
};
const Introspection PersistDirectoryAtom::_introspection(
    "PersistDirectoryAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PersistDirectoryEntry::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_persistId(const Introspectable* i, int j) {
        return (static_cast<const PersistDirectoryEntry*>(i)->persistId);
    }
    static QVariant get_cPersist(const Introspectable* i, int j) {
        return (static_cast<const PersistDirectoryEntry*>(i)->cPersist);
    }
    static int count_rgPersistOffset(const Introspectable* i) {
        return static_cast<const PersistDirectoryEntry*>(i)->rgPersistOffset.size();
    }
    static const Introspectable* get_rgPersistOffset(const Introspectable* i, int j) {
        return &(static_cast<const PersistDirectoryEntry*>(i)->rgPersistOffset[j]);
    }
};
const QString PersistDirectoryEntry::_Introspection::name("PersistDirectoryEntry");
const int PersistDirectoryEntry::_Introspection::numberOfMembers(3);
const QString PersistDirectoryEntry::_Introspection::names[3] = {
    "persistId",
    "cPersist",
    "rgPersistOffset",
};
int (* const PersistDirectoryEntry::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_rgPersistOffset,
};
QVariant (* const PersistDirectoryEntry::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_persistId,
    _Introspection::get_cPersist,
    Introspection::nullValue,
};
const Introspectable* (* const PersistDirectoryEntry::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    _Introspection::get_rgPersistOffset,
};
const Introspection PersistDirectoryEntry::_introspection(
    "PersistDirectoryEntry", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PersistOffsetEntry::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static QVariant get_anon(const Introspectable* i, int j) {
        return (static_cast<const PersistOffsetEntry*>(i)->anon);
    }
};
const QString PersistOffsetEntry::_Introspection::name("PersistOffsetEntry");
const int PersistOffsetEntry::_Introspection::numberOfMembers(1);
const QString PersistOffsetEntry::_Introspection::names[1] = {
    "anon",
};
int (* const PersistOffsetEntry::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const PersistOffsetEntry::_Introspection::value[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspectable* (* const PersistOffsetEntry::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    Introspection::null,
};
const Introspection PersistOffsetEntry::_introspection(
    "PersistOffsetEntry", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PersistIdRef::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static QVariant get_anon(const Introspectable* i, int j) {
        return (static_cast<const PersistIdRef*>(i)->anon);
    }
};
const QString PersistIdRef::_Introspection::name("PersistIdRef");
const int PersistIdRef::_Introspection::numberOfMembers(1);
const QString PersistIdRef::_Introspection::names[1] = {
    "anon",
};
int (* const PersistIdRef::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const PersistIdRef::_Introspection::value[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspectable* (* const PersistIdRef::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    Introspection::null,
};
const Introspection PersistIdRef::_introspection(
    "PersistIdRef", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MainMasterContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MainMasterContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const MainMasterContainer*>(i)->todo);
    }
};
const QString MainMasterContainer::_Introspection::name("MainMasterContainer");
const int MainMasterContainer::_Introspection::numberOfMembers(2);
const QString MainMasterContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const MainMasterContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const MainMasterContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const MainMasterContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection MainMasterContainer::_introspection(
    "MainMasterContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class NotesContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const NotesContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const NotesContainer*>(i)->todo);
    }
};
const QString NotesContainer::_Introspection::name("NotesContainer");
const int NotesContainer::_Introspection::numberOfMembers(2);
const QString NotesContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const NotesContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const NotesContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const NotesContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection NotesContainer::_introspection(
    "NotesContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class HandoutContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const HandoutContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const HandoutContainer*>(i)->todo);
    }
};
const QString HandoutContainer::_Introspection::name("HandoutContainer");
const int HandoutContainer::_Introspection::numberOfMembers(2);
const QString HandoutContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const HandoutContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const HandoutContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const HandoutContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection HandoutContainer::_introspection(
    "HandoutContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExControlStg::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExControlStg*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const ExControlStg*>(i)->todo);
    }
};
const QString ExControlStg::_Introspection::name("ExControlStg");
const int ExControlStg::_Introspection::numberOfMembers(2);
const QString ExControlStg::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const ExControlStg::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExControlStg::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const ExControlStg::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ExControlStg::_introspection(
    "ExControlStg", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExOleObjStg::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExOleObjStg*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjStg*>(i)->todo);
    }
};
const QString ExOleObjStg::_Introspection::name("ExOleObjStg");
const int ExOleObjStg::_Introspection::numberOfMembers(2);
const QString ExOleObjStg::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const ExOleObjStg::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExOleObjStg::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const ExOleObjStg::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ExOleObjStg::_introspection(
    "ExOleObjStg", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class UserEditAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const UserEditAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const UserEditAtom*>(i)->todo);
    }
};
const QString UserEditAtom::_Introspection::name("UserEditAtom");
const int UserEditAtom::_Introspection::numberOfMembers(2);
const QString UserEditAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const UserEditAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const UserEditAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const UserEditAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection UserEditAtom::_introspection(
    "UserEditAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class VbaProjectStg::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const VbaProjectStg*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const VbaProjectStg*>(i)->todo);
    }
};
const QString VbaProjectStg::_Introspection::name("VbaProjectStg");
const int VbaProjectStg::_Introspection::numberOfMembers(2);
const QString VbaProjectStg::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const VbaProjectStg::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const VbaProjectStg::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const VbaProjectStg::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection VbaProjectStg::_introspection(
    "VbaProjectStg", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideProgTagscontainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideProgTagscontainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const SlideProgTagscontainer*>(i)->todo);
    }
};
const QString SlideProgTagscontainer::_Introspection::name("SlideProgTagscontainer");
const int SlideProgTagscontainer::_Introspection::numberOfMembers(2);
const QString SlideProgTagscontainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const SlideProgTagscontainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideProgTagscontainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const SlideProgTagscontainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection SlideProgTagscontainer::_introspection(
    "SlideProgTagscontainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideAtom*>(i)->rh);
    }
    static QVariant get_geom(const Introspectable* i, int j) {
        return (static_cast<const SlideAtom*>(i)->geom);
    }
    static QVariant get_rgPlaceholderTypes(const Introspectable* i, int j) {
        return (static_cast<const SlideAtom*>(i)->rgPlaceholderTypes);
    }
    static QVariant get_masterIdRef(const Introspectable* i, int j) {
        return (static_cast<const SlideAtom*>(i)->masterIdRef);
    }
    static QVariant get_notesIdRef(const Introspectable* i, int j) {
        return (static_cast<const SlideAtom*>(i)->notesIdRef);
    }
    static QVariant get_slideFlags(const Introspectable* i, int j) {
        return (static_cast<const SlideAtom*>(i)->slideFlags);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const SlideAtom*>(i)->unused);
    }
};
const QString SlideAtom::_Introspection::name("SlideAtom");
const int SlideAtom::_Introspection::numberOfMembers(7);
const QString SlideAtom::_Introspection::names[7] = {
    "rh",
    "geom",
    "rgPlaceholderTypes",
    "masterIdRef",
    "notesIdRef",
    "slideFlags",
    "unused",
};
int (* const SlideAtom::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideAtom::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_geom,
    _Introspection::get_rgPlaceholderTypes,
    _Introspection::get_masterIdRef,
    _Introspection::get_notesIdRef,
    _Introspection::get_slideFlags,
    _Introspection::get_unused,
};
const Introspectable* (* const SlideAtom::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection SlideAtom::_introspection(
    "SlideAtom", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideShowSlideInfoAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[21];
    static int (* const numberOfInstances[21])(const Introspectable*);
    static QVariant (* const value[21])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[21])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideShowSlideInfoAtom*>(i)->rh);
    }
    static QVariant get_slidetime(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->slidetime);
    }
    static QVariant get_slideIdRef(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->slideIdRef);
    }
    static QVariant get_effectDirection(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->effectDirection);
    }
    static QVariant get_effectType(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->effectType);
    }
    static QVariant get_fManualAdvance(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fManualAdvance);
    }
    static QVariant get_reserved(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->reserved);
    }
    static QVariant get_fHidden(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fHidden);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->reserved2);
    }
    static QVariant get_fSound(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fSound);
    }
    static QVariant get_reserved3(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->reserved3);
    }
    static QVariant get_fLoopSound(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fLoopSound);
    }
    static QVariant get_reserved4(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->reserved4);
    }
    static QVariant get_fStopSound(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fStopSound);
    }
    static QVariant get_freserved5(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->freserved5);
    }
    static QVariant get_fAutoAdvance(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fAutoAdvance);
    }
    static QVariant get_reserved6(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->reserved6);
    }
    static QVariant get_fCursorVisible(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->fCursorVisible);
    }
    static QVariant get_reserved7(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->reserved7);
    }
    static QVariant get_speed(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->speed);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const SlideShowSlideInfoAtom*>(i)->unused);
    }
};
const QString SlideShowSlideInfoAtom::_Introspection::name("SlideShowSlideInfoAtom");
const int SlideShowSlideInfoAtom::_Introspection::numberOfMembers(21);
const QString SlideShowSlideInfoAtom::_Introspection::names[21] = {
    "rh",
    "slidetime",
    "slideIdRef",
    "effectDirection",
    "effectType",
    "fManualAdvance",
    "reserved",
    "fHidden",
    "reserved2",
    "fSound",
    "reserved3",
    "fLoopSound",
    "reserved4",
    "fStopSound",
    "freserved5",
    "fAutoAdvance",
    "reserved6",
    "fCursorVisible",
    "reserved7",
    "speed",
    "unused",
};
int (* const SlideShowSlideInfoAtom::_Introspection::numberOfInstances[21])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideShowSlideInfoAtom::_Introspection::value[21])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_slidetime,
    _Introspection::get_slideIdRef,
    _Introspection::get_effectDirection,
    _Introspection::get_effectType,
    _Introspection::get_fManualAdvance,
    _Introspection::get_reserved,
    _Introspection::get_fHidden,
    _Introspection::get_reserved2,
    _Introspection::get_fSound,
    _Introspection::get_reserved3,
    _Introspection::get_fLoopSound,
    _Introspection::get_reserved4,
    _Introspection::get_fStopSound,
    _Introspection::get_freserved5,
    _Introspection::get_fAutoAdvance,
    _Introspection::get_reserved6,
    _Introspection::get_fCursorVisible,
    _Introspection::get_reserved7,
    _Introspection::get_speed,
    _Introspection::get_unused,
};
const Introspectable* (* const SlideShowSlideInfoAtom::_Introspection::introspectable[21])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection SlideShowSlideInfoAtom::_introspection(
    "SlideShowSlideInfoAtom", 21, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideShowDocInfoAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideShowDocInfoAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const SlideShowDocInfoAtom*>(i)->todo);
    }
};
const QString SlideShowDocInfoAtom::_Introspection::name("SlideShowDocInfoAtom");
const int SlideShowDocInfoAtom::_Introspection::numberOfMembers(2);
const QString SlideShowDocInfoAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const SlideShowDocInfoAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlideShowDocInfoAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const SlideShowDocInfoAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection SlideShowDocInfoAtom::_introspection(
    "SlideShowDocInfoAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideSchemeColorSchemeAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideSchemeColorSchemeAtom*>(i)->rh);
    }
    static int count_rgSchemeColor(const Introspectable* i) {
        return static_cast<const SlideSchemeColorSchemeAtom*>(i)->rgSchemeColor.size();
    }
    static const Introspectable* get_rgSchemeColor(const Introspectable* i, int j) {
        return &(static_cast<const SlideSchemeColorSchemeAtom*>(i)->rgSchemeColor[j]);
    }
};
const QString SlideSchemeColorSchemeAtom::_Introspection::name("SlideSchemeColorSchemeAtom");
const int SlideSchemeColorSchemeAtom::_Introspection::numberOfMembers(2);
const QString SlideSchemeColorSchemeAtom::_Introspection::names[2] = {
    "rh",
    "rgSchemeColor",
};
int (* const SlideSchemeColorSchemeAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgSchemeColor,
};
QVariant (* const SlideSchemeColorSchemeAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const SlideSchemeColorSchemeAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgSchemeColor,
};
const Introspection SlideSchemeColorSchemeAtom::_introspection(
    "SlideSchemeColorSchemeAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class RoundTripSlideRecord::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const RoundTripSlideRecord*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const RoundTripSlideRecord*>(i)->todo);
    }
};
const QString RoundTripSlideRecord::_Introspection::name("RoundTripSlideRecord");
const int RoundTripSlideRecord::_Introspection::numberOfMembers(2);
const QString RoundTripSlideRecord::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const RoundTripSlideRecord::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const RoundTripSlideRecord::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const RoundTripSlideRecord::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection RoundTripSlideRecord::_introspection(
    "RoundTripSlideRecord", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ColorStruct::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_red(const Introspectable* i, int j) {
        return (static_cast<const ColorStruct*>(i)->red);
    }
    static QVariant get_green(const Introspectable* i, int j) {
        return (static_cast<const ColorStruct*>(i)->green);
    }
    static QVariant get_blue(const Introspectable* i, int j) {
        return (static_cast<const ColorStruct*>(i)->blue);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const ColorStruct*>(i)->unused);
    }
};
const QString ColorStruct::_Introspection::name("ColorStruct");
const int ColorStruct::_Introspection::numberOfMembers(4);
const QString ColorStruct::_Introspection::names[4] = {
    "red",
    "green",
    "blue",
    "unused",
};
int (* const ColorStruct::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const ColorStruct::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_red,
    _Introspection::get_green,
    _Introspection::get_blue,
    _Introspection::get_unused,
};
const Introspectable* (* const ColorStruct::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection ColorStruct::_introspection(
    "ColorStruct", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExObjListAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExObjListAtom*>(i)->rh);
    }
    static QVariant get_exObjIdSeed(const Introspectable* i, int j) {
        return (static_cast<const ExObjListAtom*>(i)->exObjIdSeed);
    }
};
const QString ExObjListAtom::_Introspection::name("ExObjListAtom");
const int ExObjListAtom::_Introspection::numberOfMembers(2);
const QString ExObjListAtom::_Introspection::names[2] = {
    "rh",
    "exObjIdSeed",
};
int (* const ExObjListAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExObjListAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_exObjIdSeed,
};
const Introspectable* (* const ExObjListAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ExObjListAtom::_introspection(
    "ExObjListAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExOleLinkAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExOleLinkAtom*>(i)->rh);
    }
    static QVariant get_slideIdRef(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkAtom*>(i)->slideIdRef);
    }
    static QVariant get_oleUpdateMode(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkAtom*>(i)->oleUpdateMode);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkAtom*>(i)->unused);
    }
};
const QString ExOleLinkAtom::_Introspection::name("ExOleLinkAtom");
const int ExOleLinkAtom::_Introspection::numberOfMembers(4);
const QString ExOleLinkAtom::_Introspection::names[4] = {
    "rh",
    "slideIdRef",
    "oleUpdateMode",
    "unused",
};
int (* const ExOleLinkAtom::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExOleLinkAtom::_Introspection::value[4])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_slideIdRef,
    _Introspection::get_oleUpdateMode,
    _Introspection::get_unused,
};
const Introspectable* (* const ExOleLinkAtom::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection ExOleLinkAtom::_introspection(
    "ExOleLinkAtom", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExOleObjAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExOleObjAtom*>(i)->rh);
    }
    static QVariant get_drawAspect(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjAtom*>(i)->drawAspect);
    }
    static QVariant get_type(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjAtom*>(i)->type);
    }
    static QVariant get_exObjId(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjAtom*>(i)->exObjId);
    }
    static QVariant get_subType(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjAtom*>(i)->subType);
    }
    static QVariant get_persistIdRef(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjAtom*>(i)->persistIdRef);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const ExOleObjAtom*>(i)->unused);
    }
};
const QString ExOleObjAtom::_Introspection::name("ExOleObjAtom");
const int ExOleObjAtom::_Introspection::numberOfMembers(7);
const QString ExOleObjAtom::_Introspection::names[7] = {
    "rh",
    "drawAspect",
    "type",
    "exObjId",
    "subType",
    "persistIdRef",
    "unused",
};
int (* const ExOleObjAtom::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExOleObjAtom::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_drawAspect,
    _Introspection::get_type,
    _Introspection::get_exObjId,
    _Introspection::get_subType,
    _Introspection::get_persistIdRef,
    _Introspection::get_unused,
};
const Introspectable* (* const ExOleObjAtom::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection ExOleObjAtom::_introspection(
    "ExOleObjAtom", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MenuNameAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MenuNameAtom*>(i)->rh);
    }
    static QVariant get_menuName(const Introspectable* i, int j) {
        return (static_cast<const MenuNameAtom*>(i)->menuName);
    }
};
const QString MenuNameAtom::_Introspection::name("MenuNameAtom");
const int MenuNameAtom::_Introspection::numberOfMembers(2);
const QString MenuNameAtom::_Introspection::names[2] = {
    "rh",
    "menuName",
};
int (* const MenuNameAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const MenuNameAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_menuName,
};
const Introspectable* (* const MenuNameAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection MenuNameAtom::_introspection(
    "MenuNameAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ProgIDAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ProgIDAtom*>(i)->rh);
    }
    static QVariant get_progId(const Introspectable* i, int j) {
        return (static_cast<const ProgIDAtom*>(i)->progId);
    }
};
const QString ProgIDAtom::_Introspection::name("ProgIDAtom");
const int ProgIDAtom::_Introspection::numberOfMembers(2);
const QString ProgIDAtom::_Introspection::names[2] = {
    "rh",
    "progId",
};
int (* const ProgIDAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ProgIDAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_progId,
};
const Introspectable* (* const ProgIDAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ProgIDAtom::_introspection(
    "ProgIDAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ClipboardNameAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ClipboardNameAtom*>(i)->rh);
    }
    static QVariant get_clipboardName(const Introspectable* i, int j) {
        return (static_cast<const ClipboardNameAtom*>(i)->clipboardName);
    }
};
const QString ClipboardNameAtom::_Introspection::name("ClipboardNameAtom");
const int ClipboardNameAtom::_Introspection::numberOfMembers(2);
const QString ClipboardNameAtom::_Introspection::names[2] = {
    "rh",
    "clipboardName",
};
int (* const ClipboardNameAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ClipboardNameAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_clipboardName,
};
const Introspectable* (* const ClipboardNameAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ClipboardNameAtom::_introspection(
    "ClipboardNameAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MetafileBlob::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MetafileBlob*>(i)->rh);
    }
    static QVariant get_mm(const Introspectable* i, int j) {
        return (static_cast<const MetafileBlob*>(i)->mm);
    }
    static QVariant get_xExt(const Introspectable* i, int j) {
        return (static_cast<const MetafileBlob*>(i)->xExt);
    }
    static QVariant get_yExt(const Introspectable* i, int j) {
        return (static_cast<const MetafileBlob*>(i)->yExt);
    }
    static QVariant get_data(const Introspectable* i, int j) {
        return (static_cast<const MetafileBlob*>(i)->data);
    }
};
const QString MetafileBlob::_Introspection::name("MetafileBlob");
const int MetafileBlob::_Introspection::numberOfMembers(5);
const QString MetafileBlob::_Introspection::names[5] = {
    "rh",
    "mm",
    "xExt",
    "yExt",
    "data",
};
int (* const MetafileBlob::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const MetafileBlob::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_mm,
    _Introspection::get_xExt,
    _Introspection::get_yExt,
    _Introspection::get_data,
};
const Introspectable* (* const MetafileBlob::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection MetafileBlob::_introspection(
    "MetafileBlob", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFDGG::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_spidMax(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFDGG*>(i)->spidMax);
    }
    static QVariant get_cidcl(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFDGG*>(i)->cidcl);
    }
    static QVariant get_cspSaved(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFDGG*>(i)->cspSaved);
    }
    static QVariant get_cdgSaved(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFDGG*>(i)->cdgSaved);
    }
};
const QString OfficeArtFDGG::_Introspection::name("OfficeArtFDGG");
const int OfficeArtFDGG::_Introspection::numberOfMembers(4);
const QString OfficeArtFDGG::_Introspection::names[4] = {
    "spidMax",
    "cidcl",
    "cspSaved",
    "cdgSaved",
};
int (* const OfficeArtFDGG::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFDGG::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_spidMax,
    _Introspection::get_cidcl,
    _Introspection::get_cspSaved,
    _Introspection::get_cdgSaved,
};
const Introspectable* (* const OfficeArtFDGG::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFDGG::_introspection(
    "OfficeArtFDGG", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFDG::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFDG*>(i)->rh);
    }
    static QVariant get_csp(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFDG*>(i)->csp);
    }
    static QVariant get_spidCur(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFDG*>(i)->spidCur);
    }
};
const QString OfficeArtFDG::_Introspection::name("OfficeArtFDG");
const int OfficeArtFDG::_Introspection::numberOfMembers(3);
const QString OfficeArtFDG::_Introspection::names[3] = {
    "rh",
    "csp",
    "spidCur",
};
int (* const OfficeArtFDG::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFDG::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_csp,
    _Introspection::get_spidCur,
};
const Introspectable* (* const OfficeArtFDG::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFDG::_introspection(
    "OfficeArtFDG", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFRITContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFRITContainer*>(i)->rh);
    }
    static int count_rgfrit(const Introspectable* i) {
        return static_cast<const OfficeArtFRITContainer*>(i)->rgfrit.size();
    }
    static const Introspectable* get_rgfrit(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFRITContainer*>(i)->rgfrit[j]);
    }
};
const QString OfficeArtFRITContainer::_Introspection::name("OfficeArtFRITContainer");
const int OfficeArtFRITContainer::_Introspection::numberOfMembers(2);
const QString OfficeArtFRITContainer::_Introspection::names[2] = {
    "rh",
    "rgfrit",
};
int (* const OfficeArtFRITContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgfrit,
};
QVariant (* const OfficeArtFRITContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtFRITContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgfrit,
};
const Introspection OfficeArtFRITContainer::_introspection(
    "OfficeArtFRITContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFRIT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_fridNew(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFRIT*>(i)->fridNew);
    }
    static QVariant get_fridOld(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFRIT*>(i)->fridOld);
    }
};
const QString OfficeArtFRIT::_Introspection::name("OfficeArtFRIT");
const int OfficeArtFRIT::_Introspection::numberOfMembers(2);
const QString OfficeArtFRIT::_Introspection::names[2] = {
    "fridNew",
    "fridOld",
};
int (* const OfficeArtFRIT::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFRIT::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_fridNew,
    _Introspection::get_fridOld,
};
const Introspectable* (* const OfficeArtFRIT::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFRIT::_introspection(
    "OfficeArtFRIT", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBStoreContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBStoreContainer*>(i)->rh);
    }
    static int count_rgfb(const Introspectable* i) {
        return static_cast<const OfficeArtBStoreContainer*>(i)->rgfb.size();
    }
    static const Introspectable* get_rgfb(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBStoreContainer*>(i)->rgfb[j]);
    }
};
const QString OfficeArtBStoreContainer::_Introspection::name("OfficeArtBStoreContainer");
const int OfficeArtBStoreContainer::_Introspection::numberOfMembers(2);
const QString OfficeArtBStoreContainer::_Introspection::names[2] = {
    "rh",
    "rgfb",
};
int (* const OfficeArtBStoreContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgfb,
};
QVariant (* const OfficeArtBStoreContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtBStoreContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgfb,
};
const Introspection OfficeArtBStoreContainer::_introspection(
    "OfficeArtBStoreContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtSpgrContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSpgrContainer*>(i)->rh);
    }
    static int count_rgfb(const Introspectable* i) {
        return static_cast<const OfficeArtSpgrContainer*>(i)->rgfb.size();
    }
    static const Introspectable* get_rgfb(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSpgrContainer*>(i)->rgfb[j]);
    }
};
const QString OfficeArtSpgrContainer::_Introspection::name("OfficeArtSpgrContainer");
const int OfficeArtSpgrContainer::_Introspection::numberOfMembers(2);
const QString OfficeArtSpgrContainer::_Introspection::names[2] = {
    "rh",
    "rgfb",
};
int (* const OfficeArtSpgrContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgfb,
};
QVariant (* const OfficeArtSpgrContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtSpgrContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgfb,
};
const Introspection OfficeArtSpgrContainer::_introspection(
    "OfficeArtSpgrContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtSolverContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSolverContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSolverContainer*>(i)->todo);
    }
};
const QString OfficeArtSolverContainer::_Introspection::name("OfficeArtSolverContainer");
const int OfficeArtSolverContainer::_Introspection::numberOfMembers(2);
const QString OfficeArtSolverContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const OfficeArtSolverContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtSolverContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const OfficeArtSolverContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection OfficeArtSolverContainer::_introspection(
    "OfficeArtSolverContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFSPGR::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFSPGR*>(i)->rh);
    }
    static QVariant get_xLeft(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSPGR*>(i)->xLeft);
    }
    static QVariant get_yTop(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSPGR*>(i)->yTop);
    }
    static QVariant get_xRight(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSPGR*>(i)->xRight);
    }
    static QVariant get_yBottom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSPGR*>(i)->yBottom);
    }
};
const QString OfficeArtFSPGR::_Introspection::name("OfficeArtFSPGR");
const int OfficeArtFSPGR::_Introspection::numberOfMembers(5);
const QString OfficeArtFSPGR::_Introspection::names[5] = {
    "rh",
    "xLeft",
    "yTop",
    "xRight",
    "yBottom",
};
int (* const OfficeArtFSPGR::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFSPGR::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_xLeft,
    _Introspection::get_yTop,
    _Introspection::get_xRight,
    _Introspection::get_yBottom,
};
const Introspectable* (* const OfficeArtFSPGR::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFSPGR::_introspection(
    "OfficeArtFSPGR", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFSP::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[15];
    static int (* const numberOfInstances[15])(const Introspectable*);
    static QVariant (* const value[15])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[15])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFSP*>(i)->rh);
    }
    static QVariant get_spid(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->spid);
    }
    static QVariant get_fGroup(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fGroup);
    }
    static QVariant get_fChild(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fChild);
    }
    static QVariant get_fPatriarch(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fPatriarch);
    }
    static QVariant get_fDeleted(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fDeleted);
    }
    static QVariant get_fOleShape(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fOleShape);
    }
    static QVariant get_fHaveMaster(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fHaveMaster);
    }
    static QVariant get_fFlipH(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fFlipH);
    }
    static QVariant get_fFlipV(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fFlipV);
    }
    static QVariant get_fConnector(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fConnector);
    }
    static QVariant get_fHaveAnchor(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fHaveAnchor);
    }
    static QVariant get_fBackground(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fBackground);
    }
    static QVariant get_fHaveSpt(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->fHaveSpt);
    }
    static QVariant get_unused1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFSP*>(i)->unused1);
    }
};
const QString OfficeArtFSP::_Introspection::name("OfficeArtFSP");
const int OfficeArtFSP::_Introspection::numberOfMembers(15);
const QString OfficeArtFSP::_Introspection::names[15] = {
    "rh",
    "spid",
    "fGroup",
    "fChild",
    "fPatriarch",
    "fDeleted",
    "fOleShape",
    "fHaveMaster",
    "fFlipH",
    "fFlipV",
    "fConnector",
    "fHaveAnchor",
    "fBackground",
    "fHaveSpt",
    "unused1",
};
int (* const OfficeArtFSP::_Introspection::numberOfInstances[15])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFSP::_Introspection::value[15])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_spid,
    _Introspection::get_fGroup,
    _Introspection::get_fChild,
    _Introspection::get_fPatriarch,
    _Introspection::get_fDeleted,
    _Introspection::get_fOleShape,
    _Introspection::get_fHaveMaster,
    _Introspection::get_fFlipH,
    _Introspection::get_fFlipV,
    _Introspection::get_fConnector,
    _Introspection::get_fHaveAnchor,
    _Introspection::get_fBackground,
    _Introspection::get_fHaveSpt,
    _Introspection::get_unused1,
};
const Introspectable* (* const OfficeArtFSP::_Introspection::introspectable[15])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFSP::_introspection(
    "OfficeArtFSP", 15, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFOPT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFOPT*>(i)->rh);
    }
    static int count_fopt(const Introspectable* i) {
        return static_cast<const OfficeArtFOPT*>(i)->fopt.size();
    }
    static const Introspectable* get_fopt(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFOPT*>(i)->fopt[j]);
    }
};
const QString OfficeArtFOPT::_Introspection::name("OfficeArtFOPT");
const int OfficeArtFOPT::_Introspection::numberOfMembers(2);
const QString OfficeArtFOPT::_Introspection::names[2] = {
    "rh",
    "fopt",
};
int (* const OfficeArtFOPT::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_fopt,
};
QVariant (* const OfficeArtFOPT::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtFOPT::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_fopt,
};
const Introspection OfficeArtFOPT::_introspection(
    "OfficeArtFOPT", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtChildAnchor::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtChildAnchor*>(i)->rh);
    }
    static QVariant get_xLeft(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtChildAnchor*>(i)->xLeft);
    }
    static QVariant get_yTop(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtChildAnchor*>(i)->yTop);
    }
    static QVariant get_xRight(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtChildAnchor*>(i)->xRight);
    }
    static QVariant get_yBottom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtChildAnchor*>(i)->yBottom);
    }
};
const QString OfficeArtChildAnchor::_Introspection::name("OfficeArtChildAnchor");
const int OfficeArtChildAnchor::_Introspection::numberOfMembers(5);
const QString OfficeArtChildAnchor::_Introspection::names[5] = {
    "rh",
    "xLeft",
    "yTop",
    "xRight",
    "yBottom",
};
int (* const OfficeArtChildAnchor::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtChildAnchor::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_xLeft,
    _Introspection::get_yTop,
    _Introspection::get_xRight,
    _Introspection::get_yBottom,
};
const Introspectable* (* const OfficeArtChildAnchor::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtChildAnchor::_introspection(
    "OfficeArtChildAnchor", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFPSPL::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFPSPL*>(i)->rh);
    }
    static QVariant get_spid(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFPSPL*>(i)->spid);
    }
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFPSPL*>(i)->reserved1);
    }
    static QVariant get_fLast(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFPSPL*>(i)->fLast);
    }
};
const QString OfficeArtFPSPL::_Introspection::name("OfficeArtFPSPL");
const int OfficeArtFPSPL::_Introspection::numberOfMembers(4);
const QString OfficeArtFPSPL::_Introspection::names[4] = {
    "rh",
    "spid",
    "reserved1",
    "fLast",
};
int (* const OfficeArtFPSPL::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFPSPL::_Introspection::value[4])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_spid,
    _Introspection::get_reserved1,
    _Introspection::get_fLast,
};
const Introspectable* (* const OfficeArtFPSPL::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFPSPL::_introspection(
    "OfficeArtFPSPL", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtSecondaryFOPT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSecondaryFOPT*>(i)->rh);
    }
    static QVariant get_fopt(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSecondaryFOPT*>(i)->fopt);
    }
};
const QString OfficeArtSecondaryFOPT::_Introspection::name("OfficeArtSecondaryFOPT");
const int OfficeArtSecondaryFOPT::_Introspection::numberOfMembers(2);
const QString OfficeArtSecondaryFOPT::_Introspection::names[2] = {
    "rh",
    "fopt",
};
int (* const OfficeArtSecondaryFOPT::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtSecondaryFOPT::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_fopt,
};
const Introspectable* (* const OfficeArtSecondaryFOPT::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection OfficeArtSecondaryFOPT::_introspection(
    "OfficeArtSecondaryFOPT", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtTertiaryFOPT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtTertiaryFOPT*>(i)->rh);
    }
    static int count_fopt(const Introspectable* i) {
        return static_cast<const OfficeArtTertiaryFOPT*>(i)->fopt.size();
    }
    static const Introspectable* get_fopt(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtTertiaryFOPT*>(i)->fopt[j]);
    }
};
const QString OfficeArtTertiaryFOPT::_Introspection::name("OfficeArtTertiaryFOPT");
const int OfficeArtTertiaryFOPT::_Introspection::numberOfMembers(2);
const QString OfficeArtTertiaryFOPT::_Introspection::names[2] = {
    "rh",
    "fopt",
};
int (* const OfficeArtTertiaryFOPT::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_fopt,
};
QVariant (* const OfficeArtTertiaryFOPT::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtTertiaryFOPT::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_fopt,
};
const Introspection OfficeArtTertiaryFOPT::_introspection(
    "OfficeArtTertiaryFOPT", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class RectStruct::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_top(const Introspectable* i, int j) {
        return (static_cast<const RectStruct*>(i)->top);
    }
    static QVariant get_left(const Introspectable* i, int j) {
        return (static_cast<const RectStruct*>(i)->left);
    }
    static QVariant get_right(const Introspectable* i, int j) {
        return (static_cast<const RectStruct*>(i)->right);
    }
    static QVariant get_bottom(const Introspectable* i, int j) {
        return (static_cast<const RectStruct*>(i)->bottom);
    }
};
const QString RectStruct::_Introspection::name("RectStruct");
const int RectStruct::_Introspection::numberOfMembers(4);
const QString RectStruct::_Introspection::names[4] = {
    "top",
    "left",
    "right",
    "bottom",
};
int (* const RectStruct::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const RectStruct::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_top,
    _Introspection::get_left,
    _Introspection::get_right,
    _Introspection::get_bottom,
};
const Introspectable* (* const RectStruct::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection RectStruct::_introspection(
    "RectStruct", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SmallRectStruct::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_top(const Introspectable* i, int j) {
        return (static_cast<const SmallRectStruct*>(i)->top);
    }
    static QVariant get_left(const Introspectable* i, int j) {
        return (static_cast<const SmallRectStruct*>(i)->left);
    }
    static QVariant get_right(const Introspectable* i, int j) {
        return (static_cast<const SmallRectStruct*>(i)->right);
    }
    static QVariant get_bottom(const Introspectable* i, int j) {
        return (static_cast<const SmallRectStruct*>(i)->bottom);
    }
};
const QString SmallRectStruct::_Introspection::name("SmallRectStruct");
const int SmallRectStruct::_Introspection::numberOfMembers(4);
const QString SmallRectStruct::_Introspection::names[4] = {
    "top",
    "left",
    "right",
    "bottom",
};
int (* const SmallRectStruct::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const SmallRectStruct::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_top,
    _Introspection::get_left,
    _Introspection::get_right,
    _Introspection::get_bottom,
};
const Introspectable* (* const SmallRectStruct::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection SmallRectStruct::_introspection(
    "SmallRectStruct", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ShapeFlagsAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ShapeFlagsAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const ShapeFlagsAtom*>(i)->todo);
    }
};
const QString ShapeFlagsAtom::_Introspection::name("ShapeFlagsAtom");
const int ShapeFlagsAtom::_Introspection::numberOfMembers(2);
const QString ShapeFlagsAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const ShapeFlagsAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ShapeFlagsAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const ShapeFlagsAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ShapeFlagsAtom::_introspection(
    "ShapeFlagsAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ShapeFlags10Atom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ShapeFlags10Atom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const ShapeFlags10Atom*>(i)->todo);
    }
};
const QString ShapeFlags10Atom::_Introspection::name("ShapeFlags10Atom");
const int ShapeFlags10Atom::_Introspection::numberOfMembers(2);
const QString ShapeFlags10Atom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const ShapeFlags10Atom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ShapeFlags10Atom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const ShapeFlags10Atom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ShapeFlags10Atom::_introspection(
    "ShapeFlags10Atom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExObjRefAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExObjRefAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const ExObjRefAtom*>(i)->todo);
    }
};
const QString ExObjRefAtom::_Introspection::name("ExObjRefAtom");
const int ExObjRefAtom::_Introspection::numberOfMembers(2);
const QString ExObjRefAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const ExObjRefAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ExObjRefAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const ExObjRefAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ExObjRefAtom::_introspection(
    "ExObjRefAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class AnimationInfoContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const AnimationInfoContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const AnimationInfoContainer*>(i)->todo);
    }
};
const QString AnimationInfoContainer::_Introspection::name("AnimationInfoContainer");
const int AnimationInfoContainer::_Introspection::numberOfMembers(2);
const QString AnimationInfoContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const AnimationInfoContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const AnimationInfoContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const AnimationInfoContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection AnimationInfoContainer::_introspection(
    "AnimationInfoContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MouseClickInteractiveInfoContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MouseClickInteractiveInfoContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const MouseClickInteractiveInfoContainer*>(i)->todo);
    }
};
const QString MouseClickInteractiveInfoContainer::_Introspection::name("MouseClickInteractiveInfoContainer");
const int MouseClickInteractiveInfoContainer::_Introspection::numberOfMembers(2);
const QString MouseClickInteractiveInfoContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const MouseClickInteractiveInfoContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const MouseClickInteractiveInfoContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const MouseClickInteractiveInfoContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection MouseClickInteractiveInfoContainer::_introspection(
    "MouseClickInteractiveInfoContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MouseOverInteractiveInfoContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MouseOverInteractiveInfoContainer*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const MouseOverInteractiveInfoContainer*>(i)->todo);
    }
};
const QString MouseOverInteractiveInfoContainer::_Introspection::name("MouseOverInteractiveInfoContainer");
const int MouseOverInteractiveInfoContainer::_Introspection::numberOfMembers(2);
const QString MouseOverInteractiveInfoContainer::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const MouseOverInteractiveInfoContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const MouseOverInteractiveInfoContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const MouseOverInteractiveInfoContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection MouseOverInteractiveInfoContainer::_introspection(
    "MouseOverInteractiveInfoContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PlaceholderAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const PlaceholderAtom*>(i)->rh);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const PlaceholderAtom*>(i)->position);
    }
    static QVariant get_placementId(const Introspectable* i, int j) {
        return (static_cast<const PlaceholderAtom*>(i)->placementId);
    }
    static QVariant get_size(const Introspectable* i, int j) {
        return (static_cast<const PlaceholderAtom*>(i)->size);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const PlaceholderAtom*>(i)->unused);
    }
};
const QString PlaceholderAtom::_Introspection::name("PlaceholderAtom");
const int PlaceholderAtom::_Introspection::numberOfMembers(5);
const QString PlaceholderAtom::_Introspection::names[5] = {
    "rh",
    "position",
    "placementId",
    "size",
    "unused",
};
int (* const PlaceholderAtom::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const PlaceholderAtom::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_position,
    _Introspection::get_placementId,
    _Introspection::get_size,
    _Introspection::get_unused,
};
const Introspectable* (* const PlaceholderAtom::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection PlaceholderAtom::_introspection(
    "PlaceholderAtom", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class RecolorInfoAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const RecolorInfoAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const RecolorInfoAtom*>(i)->todo);
    }
};
const QString RecolorInfoAtom::_Introspection::name("RecolorInfoAtom");
const int RecolorInfoAtom::_Introspection::numberOfMembers(2);
const QString RecolorInfoAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const RecolorInfoAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const RecolorInfoAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const RecolorInfoAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection RecolorInfoAtom::_introspection(
    "RecolorInfoAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OutlineTextRefAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OutlineTextRefAtom*>(i)->rh);
    }
    static QVariant get_index(const Introspectable* i, int j) {
        return (static_cast<const OutlineTextRefAtom*>(i)->index);
    }
};
const QString OutlineTextRefAtom::_Introspection::name("OutlineTextRefAtom");
const int OutlineTextRefAtom::_Introspection::numberOfMembers(2);
const QString OutlineTextRefAtom::_Introspection::names[2] = {
    "rh",
    "index",
};
int (* const OutlineTextRefAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const OutlineTextRefAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_index,
};
const Introspectable* (* const OutlineTextRefAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection OutlineTextRefAtom::_introspection(
    "OutlineTextRefAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ShapeClientRoundtripDataSubcontainerOrAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const ShapeClientRoundtripDataSubcontainerOrAtom*>(i)->todo);
    }
};
const QString ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection::name("ShapeClientRoundtripDataSubcontainerOrAtom");
const int ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection::numberOfMembers(2);
const QString ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const ShapeClientRoundtripDataSubcontainerOrAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection ShapeClientRoundtripDataSubcontainerOrAtom::_introspection(
    "ShapeClientRoundtripDataSubcontainerOrAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtClientTextBox::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientTextBox*>(i)->rh);
    }
    static int count_rgChildRec(const Introspectable* i) {
        return static_cast<const OfficeArtClientTextBox*>(i)->rgChildRec.size();
    }
    static const Introspectable* get_rgChildRec(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientTextBox*>(i)->rgChildRec[j]);
    }
};
const QString OfficeArtClientTextBox::_Introspection::name("OfficeArtClientTextBox");
const int OfficeArtClientTextBox::_Introspection::numberOfMembers(2);
const QString OfficeArtClientTextBox::_Introspection::names[2] = {
    "rh",
    "rgChildRec",
};
int (* const OfficeArtClientTextBox::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgChildRec,
};
QVariant (* const OfficeArtClientTextBox::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtClientTextBox::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgChildRec,
};
const Introspection OfficeArtClientTextBox::_introspection(
    "OfficeArtClientTextBox", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextClientDataSubContainerOrAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextClientDataSubContainerOrAtom*>(i)->rh);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const TextClientDataSubContainerOrAtom*>(i)->todo);
    }
};
const QString TextClientDataSubContainerOrAtom::_Introspection::name("TextClientDataSubContainerOrAtom");
const int TextClientDataSubContainerOrAtom::_Introspection::numberOfMembers(2);
const QString TextClientDataSubContainerOrAtom::_Introspection::names[2] = {
    "rh",
    "todo",
};
int (* const TextClientDataSubContainerOrAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextClientDataSubContainerOrAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_todo,
};
const Introspectable* (* const TextClientDataSubContainerOrAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection TextClientDataSubContainerOrAtom::_introspection(
    "TextClientDataSubContainerOrAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtIDCL::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_dgid(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtIDCL*>(i)->dgid);
    }
    static QVariant get_cspidCur(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtIDCL*>(i)->cspidCur);
    }
};
const QString OfficeArtIDCL::_Introspection::name("OfficeArtIDCL");
const int OfficeArtIDCL::_Introspection::numberOfMembers(2);
const QString OfficeArtIDCL::_Introspection::names[2] = {
    "dgid",
    "cspidCur",
};
int (* const OfficeArtIDCL::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtIDCL::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_dgid,
    _Introspection::get_cspidCur,
};
const Introspectable* (* const OfficeArtIDCL::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtIDCL::_introspection(
    "OfficeArtIDCL", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFOPTEOPID::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_opid(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFOPTEOPID*>(i)->opid);
    }
    static QVariant get_fBid(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFOPTEOPID*>(i)->fBid);
    }
    static QVariant get_fComplex(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFOPTEOPID*>(i)->fComplex);
    }
};
const QString OfficeArtFOPTEOPID::_Introspection::name("OfficeArtFOPTEOPID");
const int OfficeArtFOPTEOPID::_Introspection::numberOfMembers(3);
const QString OfficeArtFOPTEOPID::_Introspection::names[3] = {
    "opid",
    "fBid",
    "fComplex",
};
int (* const OfficeArtFOPTEOPID::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFOPTEOPID::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_opid,
    _Introspection::get_fBid,
    _Introspection::get_fComplex,
};
const Introspectable* (* const OfficeArtFOPTEOPID::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFOPTEOPID::_introspection(
    "OfficeArtFOPTEOPID", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtColorMRUContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtColorMRUContainer*>(i)->rh);
    }
    static int count_rgmsocr(const Introspectable* i) {
        return static_cast<const OfficeArtColorMRUContainer*>(i)->rgmsocr.size();
    }
    static const Introspectable* get_rgmsocr(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtColorMRUContainer*>(i)->rgmsocr[j]);
    }
};
const QString OfficeArtColorMRUContainer::_Introspection::name("OfficeArtColorMRUContainer");
const int OfficeArtColorMRUContainer::_Introspection::numberOfMembers(2);
const QString OfficeArtColorMRUContainer::_Introspection::names[2] = {
    "rh",
    "rgmsocr",
};
int (* const OfficeArtColorMRUContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rgmsocr,
};
QVariant (* const OfficeArtColorMRUContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtColorMRUContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rgmsocr,
};
const Introspection OfficeArtColorMRUContainer::_introspection(
    "OfficeArtColorMRUContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MSOCR::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[6];
    static int (* const numberOfInstances[6])(const Introspectable*);
    static QVariant (* const value[6])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[6])(const Introspectable*, int position);
    static QVariant get_red(const Introspectable* i, int j) {
        return (static_cast<const MSOCR*>(i)->red);
    }
    static QVariant get_green(const Introspectable* i, int j) {
        return (static_cast<const MSOCR*>(i)->green);
    }
    static QVariant get_blue(const Introspectable* i, int j) {
        return (static_cast<const MSOCR*>(i)->blue);
    }
    static QVariant get_unused1(const Introspectable* i, int j) {
        return (static_cast<const MSOCR*>(i)->unused1);
    }
    static QVariant get_fSchemeIndex(const Introspectable* i, int j) {
        return (static_cast<const MSOCR*>(i)->fSchemeIndex);
    }
    static QVariant get_unused2(const Introspectable* i, int j) {
        return (static_cast<const MSOCR*>(i)->unused2);
    }
};
const QString MSOCR::_Introspection::name("MSOCR");
const int MSOCR::_Introspection::numberOfMembers(6);
const QString MSOCR::_Introspection::names[6] = {
    "red",
    "green",
    "blue",
    "unused1",
    "fSchemeIndex",
    "unused2",
};
int (* const MSOCR::_Introspection::numberOfInstances[6])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const MSOCR::_Introspection::value[6])(const Introspectable*, int position) = {
    _Introspection::get_red,
    _Introspection::get_green,
    _Introspection::get_blue,
    _Introspection::get_unused1,
    _Introspection::get_fSchemeIndex,
    _Introspection::get_unused2,
};
const Introspectable* (* const MSOCR::_Introspection::introspectable[6])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection MSOCR::_introspection(
    "MSOCR", 6, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtSplitMenuColorContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSplitMenuColorContainer*>(i)->rh);
    }
    static int count_smca(const Introspectable* i) {
        return static_cast<const OfficeArtSplitMenuColorContainer*>(i)->smca.size();
    }
    static const Introspectable* get_smca(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSplitMenuColorContainer*>(i)->smca[j]);
    }
};
const QString OfficeArtSplitMenuColorContainer::_Introspection::name("OfficeArtSplitMenuColorContainer");
const int OfficeArtSplitMenuColorContainer::_Introspection::numberOfMembers(2);
const QString OfficeArtSplitMenuColorContainer::_Introspection::names[2] = {
    "rh",
    "smca",
};
int (* const OfficeArtSplitMenuColorContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_smca,
};
QVariant (* const OfficeArtSplitMenuColorContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtSplitMenuColorContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_smca,
};
const Introspection OfficeArtSplitMenuColorContainer::_introspection(
    "OfficeArtSplitMenuColorContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class todo::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const todo*>(i)->rh);
    }
    static QVariant get_anon(const Introspectable* i, int j) {
        return (static_cast<const todo*>(i)->anon);
    }
};
const QString todo::_Introspection::name("todo");
const int todo::_Introspection::numberOfMembers(2);
const QString todo::_Introspection::names[2] = {
    "rh",
    "anon",
};
int (* const todo::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const todo::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_anon,
};
const Introspectable* (* const todo::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
};
const Introspection todo::_introspection(
    "todo", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TODOS::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static int count_anon(const Introspectable* i) {
        return static_cast<const TODOS*>(i)->anon.size();
    }
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        return &(static_cast<const TODOS*>(i)->anon[j]);
    }
};
const QString TODOS::_Introspection::name("TODOS");
const int TODOS::_Introspection::numberOfMembers(1);
const QString TODOS::_Introspection::names[1] = {
    "anon",
};
int (* const TODOS::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    _Introspection::count_anon,
};
QVariant (* const TODOS::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const TODOS::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection TODOS::_introspection(
    "TODOS", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FibBase::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[31];
    static int (* const numberOfInstances[31])(const Introspectable*);
    static QVariant (* const value[31])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[31])(const Introspectable*, int position);
    static QVariant get_wIdent(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->wIdent);
    }
    static QVariant get_nFib(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->nFib);
    }
    static QVariant get_unused(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->unused);
    }
    static QVariant get_lid(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->lid);
    }
    static QVariant get_pnNext(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->pnNext);
    }
    static QVariant get_fDot(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fDot);
    }
    static QVariant get_fGlsy(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fGlsy);
    }
    static QVariant get_fComplex(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fComplex);
    }
    static QVariant get_fHasPic(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fHasPic);
    }
    static QVariant get_cQuickSaves(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->cQuickSaves);
    }
    static QVariant get_fEncrypted(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fEncrypted);
    }
    static QVariant get_fWhichTblStm(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fWhichTblStm);
    }
    static QVariant get_fReadOnlyRecommended(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fReadOnlyRecommended);
    }
    static QVariant get_fWriteReservation(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fWriteReservation);
    }
    static QVariant get_fExtChar(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fExtChar);
    }
    static QVariant get_fLoadOverride(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fLoadOverride);
    }
    static QVariant get_fFarEast(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fFarEast);
    }
    static QVariant get_fObfuscated(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fObfuscated);
    }
    static QVariant get_nFibBack(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->nFibBack);
    }
    static QVariant get_IKey(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->IKey);
    }
    static QVariant get_envr(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->envr);
    }
    static QVariant get_fMac(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fMac);
    }
    static QVariant get_fEmptySpecial(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fEmptySpecial);
    }
    static QVariant get_fLoadOverridePage(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fLoadOverridePage);
    }
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->reserved1);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->reserved2);
    }
    static QVariant get_fSpare0(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->fSpare0);
    }
    static QVariant get_reserved3(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->reserved3);
    }
    static QVariant get_reserved4(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->reserved4);
    }
    static QVariant get_reserved5(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->reserved5);
    }
    static QVariant get_reserved6(const Introspectable* i, int j) {
        return (static_cast<const FibBase*>(i)->reserved6);
    }
};
const QString FibBase::_Introspection::name("FibBase");
const int FibBase::_Introspection::numberOfMembers(31);
const QString FibBase::_Introspection::names[31] = {
    "wIdent",
    "nFib",
    "unused",
    "lid",
    "pnNext",
    "fDot",
    "fGlsy",
    "fComplex",
    "fHasPic",
    "cQuickSaves",
    "fEncrypted",
    "fWhichTblStm",
    "fReadOnlyRecommended",
    "fWriteReservation",
    "fExtChar",
    "fLoadOverride",
    "fFarEast",
    "fObfuscated",
    "nFibBack",
    "IKey",
    "envr",
    "fMac",
    "fEmptySpecial",
    "fLoadOverridePage",
    "reserved1",
    "reserved2",
    "fSpare0",
    "reserved3",
    "reserved4",
    "reserved5",
    "reserved6",
};
int (* const FibBase::_Introspection::numberOfInstances[31])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FibBase::_Introspection::value[31])(const Introspectable*, int position) = {
    _Introspection::get_wIdent,
    _Introspection::get_nFib,
    _Introspection::get_unused,
    _Introspection::get_lid,
    _Introspection::get_pnNext,
    _Introspection::get_fDot,
    _Introspection::get_fGlsy,
    _Introspection::get_fComplex,
    _Introspection::get_fHasPic,
    _Introspection::get_cQuickSaves,
    _Introspection::get_fEncrypted,
    _Introspection::get_fWhichTblStm,
    _Introspection::get_fReadOnlyRecommended,
    _Introspection::get_fWriteReservation,
    _Introspection::get_fExtChar,
    _Introspection::get_fLoadOverride,
    _Introspection::get_fFarEast,
    _Introspection::get_fObfuscated,
    _Introspection::get_nFibBack,
    _Introspection::get_IKey,
    _Introspection::get_envr,
    _Introspection::get_fMac,
    _Introspection::get_fEmptySpecial,
    _Introspection::get_fLoadOverridePage,
    _Introspection::get_reserved1,
    _Introspection::get_reserved2,
    _Introspection::get_fSpare0,
    _Introspection::get_reserved3,
    _Introspection::get_reserved4,
    _Introspection::get_reserved5,
    _Introspection::get_reserved6,
};
const Introspectable* (* const FibBase::_Introspection::introspectable[31])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FibBase::_introspection(
    "FibBase", 31, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FibRgW97::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[14];
    static int (* const numberOfInstances[14])(const Introspectable*);
    static QVariant (* const value[14])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[14])(const Introspectable*, int position);
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved1);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved2);
    }
    static QVariant get_reserved3(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved3);
    }
    static QVariant get_reserved4(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved4);
    }
    static QVariant get_reserved5(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved5);
    }
    static QVariant get_reserved6(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved6);
    }
    static QVariant get_reserved7(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved7);
    }
    static QVariant get_reserved8(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved8);
    }
    static QVariant get_reserved9(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved9);
    }
    static QVariant get_reserved10(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved10);
    }
    static QVariant get_reserved11(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved11);
    }
    static QVariant get_reserved12(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved12);
    }
    static QVariant get_reserved13(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->reserved13);
    }
    static QVariant get_lidFE(const Introspectable* i, int j) {
        return (static_cast<const FibRgW97*>(i)->lidFE);
    }
};
const QString FibRgW97::_Introspection::name("FibRgW97");
const int FibRgW97::_Introspection::numberOfMembers(14);
const QString FibRgW97::_Introspection::names[14] = {
    "reserved1",
    "reserved2",
    "reserved3",
    "reserved4",
    "reserved5",
    "reserved6",
    "reserved7",
    "reserved8",
    "reserved9",
    "reserved10",
    "reserved11",
    "reserved12",
    "reserved13",
    "lidFE",
};
int (* const FibRgW97::_Introspection::numberOfInstances[14])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FibRgW97::_Introspection::value[14])(const Introspectable*, int position) = {
    _Introspection::get_reserved1,
    _Introspection::get_reserved2,
    _Introspection::get_reserved3,
    _Introspection::get_reserved4,
    _Introspection::get_reserved5,
    _Introspection::get_reserved6,
    _Introspection::get_reserved7,
    _Introspection::get_reserved8,
    _Introspection::get_reserved9,
    _Introspection::get_reserved10,
    _Introspection::get_reserved11,
    _Introspection::get_reserved12,
    _Introspection::get_reserved13,
    _Introspection::get_lidFE,
};
const Introspectable* (* const FibRgW97::_Introspection::introspectable[14])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FibRgW97::_introspection(
    "FibRgW97", 14, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FibRgLw97::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[22];
    static int (* const numberOfInstances[22])(const Introspectable*);
    static QVariant (* const value[22])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[22])(const Introspectable*, int position);
    static QVariant get_cbMac(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->cbMac);
    }
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved1);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved2);
    }
    static QVariant get_ccpText(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpText);
    }
    static QVariant get_ccpFtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpFtn);
    }
    static QVariant get_ccpHdd(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpHdd);
    }
    static QVariant get_reserved3(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved3);
    }
    static QVariant get_ccpAtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpAtn);
    }
    static QVariant get_ccpEdn(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpEdn);
    }
    static QVariant get_ccpTxbx(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpTxbx);
    }
    static QVariant get_ccpHdrTxbx(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->ccpHdrTxbx);
    }
    static QVariant get_reserved4(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved4);
    }
    static QVariant get_reserved5(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved5);
    }
    static QVariant get_reserved6(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved6);
    }
    static QVariant get_reserved7(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved7);
    }
    static QVariant get_reserved8(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved8);
    }
    static QVariant get_reserved9(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved9);
    }
    static QVariant get_reserved10(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved10);
    }
    static QVariant get_reserved11(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved11);
    }
    static QVariant get_reserved12(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved12);
    }
    static QVariant get_reserved13(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved13);
    }
    static QVariant get_reserved14(const Introspectable* i, int j) {
        return (static_cast<const FibRgLw97*>(i)->reserved14);
    }
};
const QString FibRgLw97::_Introspection::name("FibRgLw97");
const int FibRgLw97::_Introspection::numberOfMembers(22);
const QString FibRgLw97::_Introspection::names[22] = {
    "cbMac",
    "reserved1",
    "reserved2",
    "ccpText",
    "ccpFtn",
    "ccpHdd",
    "reserved3",
    "ccpAtn",
    "ccpEdn",
    "ccpTxbx",
    "ccpHdrTxbx",
    "reserved4",
    "reserved5",
    "reserved6",
    "reserved7",
    "reserved8",
    "reserved9",
    "reserved10",
    "reserved11",
    "reserved12",
    "reserved13",
    "reserved14",
};
int (* const FibRgLw97::_Introspection::numberOfInstances[22])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FibRgLw97::_Introspection::value[22])(const Introspectable*, int position) = {
    _Introspection::get_cbMac,
    _Introspection::get_reserved1,
    _Introspection::get_reserved2,
    _Introspection::get_ccpText,
    _Introspection::get_ccpFtn,
    _Introspection::get_ccpHdd,
    _Introspection::get_reserved3,
    _Introspection::get_ccpAtn,
    _Introspection::get_ccpEdn,
    _Introspection::get_ccpTxbx,
    _Introspection::get_ccpHdrTxbx,
    _Introspection::get_reserved4,
    _Introspection::get_reserved5,
    _Introspection::get_reserved6,
    _Introspection::get_reserved7,
    _Introspection::get_reserved8,
    _Introspection::get_reserved9,
    _Introspection::get_reserved10,
    _Introspection::get_reserved11,
    _Introspection::get_reserved12,
    _Introspection::get_reserved13,
    _Introspection::get_reserved14,
};
const Introspectable* (* const FibRgLw97::_Introspection::introspectable[22])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FibRgLw97::_introspection(
    "FibRgLw97", 22, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FibRgFcLcb97::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[186];
    static int (* const numberOfInstances[186])(const Introspectable*);
    static QVariant (* const value[186])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[186])(const Introspectable*, int position);
    static QVariant get_fcStshfOrig(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcStshfOrig);
    }
    static QVariant get_lcbStshfOrig(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbStshfOrig);
    }
    static QVariant get_fcStshf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcStshf);
    }
    static QVariant get_lcbStshf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbStshf);
    }
    static QVariant get_fcPlcffndRef(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcffndRef);
    }
    static QVariant get_lcbPlcffndRef(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcffndRef);
    }
    static QVariant get_fcPlcffndTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcffndTxt);
    }
    static QVariant get_lcbPlcffndTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcffndTxt);
    }
    static QVariant get_fcPlcfandRef(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfandRef);
    }
    static QVariant get_lcbPlcfandRef(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfandRef);
    }
    static QVariant get_fcPlcfandTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfandTxt);
    }
    static QVariant get_lcbPlcfandTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfandTxt);
    }
    static QVariant get_fcPlcfSed(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfSed);
    }
    static QVariant get_lcbPlcfSed(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfSed);
    }
    static QVariant get_fcPlcPad(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcPad);
    }
    static QVariant get_lcbPlcPad(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcPad);
    }
    static QVariant get_fcPlcfPhe(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfPhe);
    }
    static QVariant get_lcbPlcfPhe(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfPhe);
    }
    static QVariant get_fcSttbfGlsy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfGlsy);
    }
    static QVariant get_lcbSttbfGlsy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfGlsy);
    }
    static QVariant get_fcPlcfGlsy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfGlsy);
    }
    static QVariant get_lcbPlcfGlsy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfGlsy);
    }
    static QVariant get_fcPlcfHdd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfHdd);
    }
    static QVariant get_lcbPlcfHdd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfHdd);
    }
    static QVariant get_fcPlcfBteChpx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfBteChpx);
    }
    static QVariant get_lcbPlcfBteChpx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfBteChpx);
    }
    static QVariant get_fcPlcfBtePapx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfBtePapx);
    }
    static QVariant get_lcbPlcfBtePapx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfBtePapx);
    }
    static QVariant get_fcPlcfSea(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfSea);
    }
    static QVariant get_lcbPlcfSea(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfSea);
    }
    static QVariant get_fcSttbfFfn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfFfn);
    }
    static QVariant get_lcbSttbfFfn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfFfn);
    }
    static QVariant get_fcPlcfFldMom(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldMom);
    }
    static QVariant get_lcbPlcfFldMom(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldMom);
    }
    static QVariant get_fcPlcfFldHdr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldHdr);
    }
    static QVariant get_lcbPlcfFldHdr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldHdr);
    }
    static QVariant get_fcPlcfFldFtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldFtn);
    }
    static QVariant get_lcbPlcfFldFtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldFtn);
    }
    static QVariant get_fcPlcfFldAtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldAtn);
    }
    static QVariant get_lcbPlcfFldAtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldAtn);
    }
    static QVariant get_fcPlcfFldMcr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldMcr);
    }
    static QVariant get_lcbPlcfFldMcr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldMcr);
    }
    static QVariant get_fcSttbfBkmk(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfBkmk);
    }
    static QVariant get_lcbSttbfBkmk(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfBkmk);
    }
    static QVariant get_fcPlcfBkf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfBkf);
    }
    static QVariant get_lcbPlcfBkf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfBkf);
    }
    static QVariant get_fcPlcfBkl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfBkl);
    }
    static QVariant get_lcbPlcfBkl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfBkl);
    }
    static QVariant get_fcCmds(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcCmds);
    }
    static QVariant get_lcbCmds(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbCmds);
    }
    static QVariant get_fcUnused1(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcUnused1);
    }
    static QVariant get_lcbUnused1(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbUnused1);
    }
    static QVariant get_fcSttbfMcr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfMcr);
    }
    static QVariant get_lcbSttbfMcr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfMcr);
    }
    static QVariant get_fcPrDrvr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPrDrvr);
    }
    static QVariant get_lcbPrDrvr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPrDrvr);
    }
    static QVariant get_fcPrEnvPort(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPrEnvPort);
    }
    static QVariant get_lcbPrEnvPort(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPrEnvPort);
    }
    static QVariant get_fcPrEnvLand(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPrEnvLand);
    }
    static QVariant get_lcbPrEnvLand(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPrEnvLand);
    }
    static QVariant get_fcWss(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcWss);
    }
    static QVariant get_lcbWss(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbWss);
    }
    static QVariant get_fcDop(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcDop);
    }
    static QVariant get_lcbDop(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbDop);
    }
    static QVariant get_fcSttbfAssoc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfAssoc);
    }
    static QVariant get_lcbSttbfAssoc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfAssoc);
    }
    static QVariant get_fcClx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcClx);
    }
    static QVariant get_lcbClx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbClx);
    }
    static QVariant get_fcPlcfPgdFtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfPgdFtn);
    }
    static QVariant get_lcbPlcfPgdFtn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfPgdFtn);
    }
    static QVariant get_fcAutosaveSource(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcAutosaveSource);
    }
    static QVariant get_lcbAutosaveSource(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbAutosaveSource);
    }
    static QVariant get_fcGrpXstAtnOwners(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcGrpXstAtnOwners);
    }
    static QVariant get_lcbGrpXstAtnOwners(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbGrpXstAtnOwners);
    }
    static QVariant get_fcSttbfAtnBkmk(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfAtnBkmk);
    }
    static QVariant get_lcbSttbfAtnBkmk(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfAtnBkmk);
    }
    static QVariant get_fcUnused2(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcUnused2);
    }
    static QVariant get_lcbUnused2(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbUnused2);
    }
    static QVariant get_fcUnused3(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcUnused3);
    }
    static QVariant get_lcbUnused3(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbUnused3);
    }
    static QVariant get_fcPlcSpaMom(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcSpaMom);
    }
    static QVariant get_lcbPlcSpaMom(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcSpaMom);
    }
    static QVariant get_fcPlcSpaHdr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcSpaHdr);
    }
    static QVariant get_lcbPlcSpaHdr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcSpaHdr);
    }
    static QVariant get_fcPlcfAtnBkf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfAtnBkf);
    }
    static QVariant get_lcbPlcfAtnBkf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfAtnBkf);
    }
    static QVariant get_fcPlcfAtnBkl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfAtnBkl);
    }
    static QVariant get_lcbPlcfAtnBkl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfAtnBkl);
    }
    static QVariant get_fcPms(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPms);
    }
    static QVariant get_lcbPms(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPms);
    }
    static QVariant get_fcFormFldSttbs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcFormFldSttbs);
    }
    static QVariant get_lcbFormFldSttbs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbFormFldSttbs);
    }
    static QVariant get_fcPlcfendRef(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfendRef);
    }
    static QVariant get_lcbPlcfendRef(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfendRef);
    }
    static QVariant get_fcPlcfendTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfendTxt);
    }
    static QVariant get_lcbPlcfendTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfendTxt);
    }
    static QVariant get_fcPlcfFldEdn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldEdn);
    }
    static QVariant get_lcbPlcfFldEdn(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldEdn);
    }
    static QVariant get_fcUnused4(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcUnused4);
    }
    static QVariant get_lcbUnused4(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbUnused4);
    }
    static QVariant get_fcDggInfo(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcDggInfo);
    }
    static QVariant get_lcbDggInfo(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbDggInfo);
    }
    static QVariant get_fcSttbfRMark(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfRMark);
    }
    static QVariant get_lcbSttbfRMark(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfRMark);
    }
    static QVariant get_fcSttbfCaption(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfCaption);
    }
    static QVariant get_lcbSttbfCaption(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfCaption);
    }
    static QVariant get_fcSttbfAutoCaption(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfAutoCaption);
    }
    static QVariant get_lcbSttbfAutoCaption(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfAutoCaption);
    }
    static QVariant get_fcPlcfWkb(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfWkb);
    }
    static QVariant get_lcbPlcfWkb(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfWkb);
    }
    static QVariant get_fcPlcfSpl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfSpl);
    }
    static QVariant get_lcbPlcfSpl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfSpl);
    }
    static QVariant get_fcPlcftxbxTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcftxbxTxt);
    }
    static QVariant get_lcbPlcftxbxTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcftxbxTxt);
    }
    static QVariant get_fcPlcfFldTxbx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfFldTxbx);
    }
    static QVariant get_lcbPlcfFldTxbx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfFldTxbx);
    }
    static QVariant get_fcPlcfHdrtxbxTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfHdrtxbxTxt);
    }
    static QVariant get_lcbPlcfHdrtxbxTxt(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfHdrtxbxTxt);
    }
    static QVariant get_fcPlcffldHdrTxbx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcffldHdrTxbx);
    }
    static QVariant get_lcbPlcffldHdrTxbx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcffldHdrTxbx);
    }
    static QVariant get_fcStwUser(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcStwUser);
    }
    static QVariant get_lcbStwUser(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbStwUser);
    }
    static QVariant get_fcSttbTtmbd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbTtmbd);
    }
    static QVariant get_lcbSttbTtmbd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbTtmbd);
    }
    static QVariant get_fcCookieData(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcCookieData);
    }
    static QVariant get_lcbCookieData(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbCookieData);
    }
    static QVariant get_fcPgdMotherOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPgdMotherOldOld);
    }
    static QVariant get_lcbPgdMotherOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPgdMotherOldOld);
    }
    static QVariant get_fcBkdMotherOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcBkdMotherOldOld);
    }
    static QVariant get_lcbBkdMotherOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbBkdMotherOldOld);
    }
    static QVariant get_fcPgdFtnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPgdFtnOldOld);
    }
    static QVariant get_lcbPgdFtnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPgdFtnOldOld);
    }
    static QVariant get_fcBkdFtnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcBkdFtnOldOld);
    }
    static QVariant get_lcbBkdFtnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbBkdFtnOldOld);
    }
    static QVariant get_fcPgdEdnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPgdEdnOldOld);
    }
    static QVariant get_lcbPgdEdnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPgdEdnOldOld);
    }
    static QVariant get_fcBkdEdnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcBkdEdnOldOld);
    }
    static QVariant get_lcbBkdEdnOldOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbBkdEdnOldOld);
    }
    static QVariant get_fcSttbfIntlFld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfIntlFld);
    }
    static QVariant get_lcbSttbfIntlFld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfIntlFld);
    }
    static QVariant get_fcRouteSlip(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcRouteSlip);
    }
    static QVariant get_lcbRouteSlip(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbRouteSlip);
    }
    static QVariant get_fcSttbSavedBy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbSavedBy);
    }
    static QVariant get_lcbSttbSavedBy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbSavedBy);
    }
    static QVariant get_fcSttbFnm(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbFnm);
    }
    static QVariant get_lcbSttbFnm(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbFnm);
    }
    static QVariant get_fcPlfLst(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlfLst);
    }
    static QVariant get_lcbPlfLst(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlfLst);
    }
    static QVariant get_fcPlfLfo(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlfLfo);
    }
    static QVariant get_lcbPlfLfo(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlfLfo);
    }
    static QVariant get_fcPlcfTxbxBkd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfTxbxBkd);
    }
    static QVariant get_lcbPlcfTxbxBkd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfTxbxBkd);
    }
    static QVariant get_fcPlcfTxbxHdrBkd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfTxbxHdrBkd);
    }
    static QVariant get_lcbPlcfTxbxHdrBkd(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfTxbxHdrBkd);
    }
    static QVariant get_fcDocUndoWord9(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcDocUndoWord9);
    }
    static QVariant get_lcbDocUndoWord9(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbDocUndoWord9);
    }
    static QVariant get_fcRgbUse(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcRgbUse);
    }
    static QVariant get_lcbRgbUse(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbRgbUse);
    }
    static QVariant get_fcUsp(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcUsp);
    }
    static QVariant get_lcbUsp(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbUsp);
    }
    static QVariant get_fcUskf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcUskf);
    }
    static QVariant get_lcbUskf(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbUskf);
    }
    static QVariant get_fcPlcupcRgbUse(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcupcRgbUse);
    }
    static QVariant get_lcbPlcupcRgbUse(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcupcRgbUse);
    }
    static QVariant get_fcPlcupcUsp(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcupcUsp);
    }
    static QVariant get_lcbPlcupcUsp(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcupcUsp);
    }
    static QVariant get_fcSttbGlsyStyle(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbGlsyStyle);
    }
    static QVariant get_lcbSttbGlsyStyle(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbGlsyStyle);
    }
    static QVariant get_fcPlgosl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlgosl);
    }
    static QVariant get_lcbPlgosl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlgosl);
    }
    static QVariant get_fcPlcocx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcocx);
    }
    static QVariant get_lcbPlcocx(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcocx);
    }
    static QVariant get_fcPlcfBteLvc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfBteLvc);
    }
    static QVariant get_lcbPlcfBteLvc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfBteLvc);
    }
    static QVariant get_dwLowDateTime(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->dwLowDateTime);
    }
    static QVariant get_dwHighDateTime(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->dwHighDateTime);
    }
    static QVariant get_fcPlcfLvcPre10(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfLvcPre10);
    }
    static QVariant get_lcbPlcfLvcPre10(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfLvcPre10);
    }
    static QVariant get_fcPlcfAsumy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfAsumy);
    }
    static QVariant get_lcbPlcfAsumy(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfAsumy);
    }
    static QVariant get_fcPlcfGram(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcPlcfGram);
    }
    static QVariant get_lcbPlcfGram(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbPlcfGram);
    }
    static QVariant get_fcSttbListNames(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbListNames);
    }
    static QVariant get_lcbSttbListNames(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbListNames);
    }
    static QVariant get_fcSttbfUssr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->fcSttbfUssr);
    }
    static QVariant get_lcbSttbfUssr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb97*>(i)->lcbSttbfUssr);
    }
};
const QString FibRgFcLcb97::_Introspection::name("FibRgFcLcb97");
const int FibRgFcLcb97::_Introspection::numberOfMembers(186);
const QString FibRgFcLcb97::_Introspection::names[186] = {
    "fcStshfOrig",
    "lcbStshfOrig",
    "fcStshf",
    "lcbStshf",
    "fcPlcffndRef",
    "lcbPlcffndRef",
    "fcPlcffndTxt",
    "lcbPlcffndTxt",
    "fcPlcfandRef",
    "lcbPlcfandRef",
    "fcPlcfandTxt",
    "lcbPlcfandTxt",
    "fcPlcfSed",
    "lcbPlcfSed",
    "fcPlcPad",
    "lcbPlcPad",
    "fcPlcfPhe",
    "lcbPlcfPhe",
    "fcSttbfGlsy",
    "lcbSttbfGlsy",
    "fcPlcfGlsy",
    "lcbPlcfGlsy",
    "fcPlcfHdd",
    "lcbPlcfHdd",
    "fcPlcfBteChpx",
    "lcbPlcfBteChpx",
    "fcPlcfBtePapx",
    "lcbPlcfBtePapx",
    "fcPlcfSea",
    "lcbPlcfSea",
    "fcSttbfFfn",
    "lcbSttbfFfn",
    "fcPlcfFldMom",
    "lcbPlcfFldMom",
    "fcPlcfFldHdr",
    "lcbPlcfFldHdr",
    "fcPlcfFldFtn",
    "lcbPlcfFldFtn",
    "fcPlcfFldAtn",
    "lcbPlcfFldAtn",
    "fcPlcfFldMcr",
    "lcbPlcfFldMcr",
    "fcSttbfBkmk",
    "lcbSttbfBkmk",
    "fcPlcfBkf",
    "lcbPlcfBkf",
    "fcPlcfBkl",
    "lcbPlcfBkl",
    "fcCmds",
    "lcbCmds",
    "fcUnused1",
    "lcbUnused1",
    "fcSttbfMcr",
    "lcbSttbfMcr",
    "fcPrDrvr",
    "lcbPrDrvr",
    "fcPrEnvPort",
    "lcbPrEnvPort",
    "fcPrEnvLand",
    "lcbPrEnvLand",
    "fcWss",
    "lcbWss",
    "fcDop",
    "lcbDop",
    "fcSttbfAssoc",
    "lcbSttbfAssoc",
    "fcClx",
    "lcbClx",
    "fcPlcfPgdFtn",
    "lcbPlcfPgdFtn",
    "fcAutosaveSource",
    "lcbAutosaveSource",
    "fcGrpXstAtnOwners",
    "lcbGrpXstAtnOwners",
    "fcSttbfAtnBkmk",
    "lcbSttbfAtnBkmk",
    "fcUnused2",
    "lcbUnused2",
    "fcUnused3",
    "lcbUnused3",
    "fcPlcSpaMom",
    "lcbPlcSpaMom",
    "fcPlcSpaHdr",
    "lcbPlcSpaHdr",
    "fcPlcfAtnBkf",
    "lcbPlcfAtnBkf",
    "fcPlcfAtnBkl",
    "lcbPlcfAtnBkl",
    "fcPms",
    "lcbPms",
    "fcFormFldSttbs",
    "lcbFormFldSttbs",
    "fcPlcfendRef",
    "lcbPlcfendRef",
    "fcPlcfendTxt",
    "lcbPlcfendTxt",
    "fcPlcfFldEdn",
    "lcbPlcfFldEdn",
    "fcUnused4",
    "lcbUnused4",
    "fcDggInfo",
    "lcbDggInfo",
    "fcSttbfRMark",
    "lcbSttbfRMark",
    "fcSttbfCaption",
    "lcbSttbfCaption",
    "fcSttbfAutoCaption",
    "lcbSttbfAutoCaption",
    "fcPlcfWkb",
    "lcbPlcfWkb",
    "fcPlcfSpl",
    "lcbPlcfSpl",
    "fcPlcftxbxTxt",
    "lcbPlcftxbxTxt",
    "fcPlcfFldTxbx",
    "lcbPlcfFldTxbx",
    "fcPlcfHdrtxbxTxt",
    "lcbPlcfHdrtxbxTxt",
    "fcPlcffldHdrTxbx",
    "lcbPlcffldHdrTxbx",
    "fcStwUser",
    "lcbStwUser",
    "fcSttbTtmbd",
    "lcbSttbTtmbd",
    "fcCookieData",
    "lcbCookieData",
    "fcPgdMotherOldOld",
    "lcbPgdMotherOldOld",
    "fcBkdMotherOldOld",
    "lcbBkdMotherOldOld",
    "fcPgdFtnOldOld",
    "lcbPgdFtnOldOld",
    "fcBkdFtnOldOld",
    "lcbBkdFtnOldOld",
    "fcPgdEdnOldOld",
    "lcbPgdEdnOldOld",
    "fcBkdEdnOldOld",
    "lcbBkdEdnOldOld",
    "fcSttbfIntlFld",
    "lcbSttbfIntlFld",
    "fcRouteSlip",
    "lcbRouteSlip",
    "fcSttbSavedBy",
    "lcbSttbSavedBy",
    "fcSttbFnm",
    "lcbSttbFnm",
    "fcPlfLst",
    "lcbPlfLst",
    "fcPlfLfo",
    "lcbPlfLfo",
    "fcPlcfTxbxBkd",
    "lcbPlcfTxbxBkd",
    "fcPlcfTxbxHdrBkd",
    "lcbPlcfTxbxHdrBkd",
    "fcDocUndoWord9",
    "lcbDocUndoWord9",
    "fcRgbUse",
    "lcbRgbUse",
    "fcUsp",
    "lcbUsp",
    "fcUskf",
    "lcbUskf",
    "fcPlcupcRgbUse",
    "lcbPlcupcRgbUse",
    "fcPlcupcUsp",
    "lcbPlcupcUsp",
    "fcSttbGlsyStyle",
    "lcbSttbGlsyStyle",
    "fcPlgosl",
    "lcbPlgosl",
    "fcPlcocx",
    "lcbPlcocx",
    "fcPlcfBteLvc",
    "lcbPlcfBteLvc",
    "dwLowDateTime",
    "dwHighDateTime",
    "fcPlcfLvcPre10",
    "lcbPlcfLvcPre10",
    "fcPlcfAsumy",
    "lcbPlcfAsumy",
    "fcPlcfGram",
    "lcbPlcfGram",
    "fcSttbListNames",
    "lcbSttbListNames",
    "fcSttbfUssr",
    "lcbSttbfUssr",
};
int (* const FibRgFcLcb97::_Introspection::numberOfInstances[186])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FibRgFcLcb97::_Introspection::value[186])(const Introspectable*, int position) = {
    _Introspection::get_fcStshfOrig,
    _Introspection::get_lcbStshfOrig,
    _Introspection::get_fcStshf,
    _Introspection::get_lcbStshf,
    _Introspection::get_fcPlcffndRef,
    _Introspection::get_lcbPlcffndRef,
    _Introspection::get_fcPlcffndTxt,
    _Introspection::get_lcbPlcffndTxt,
    _Introspection::get_fcPlcfandRef,
    _Introspection::get_lcbPlcfandRef,
    _Introspection::get_fcPlcfandTxt,
    _Introspection::get_lcbPlcfandTxt,
    _Introspection::get_fcPlcfSed,
    _Introspection::get_lcbPlcfSed,
    _Introspection::get_fcPlcPad,
    _Introspection::get_lcbPlcPad,
    _Introspection::get_fcPlcfPhe,
    _Introspection::get_lcbPlcfPhe,
    _Introspection::get_fcSttbfGlsy,
    _Introspection::get_lcbSttbfGlsy,
    _Introspection::get_fcPlcfGlsy,
    _Introspection::get_lcbPlcfGlsy,
    _Introspection::get_fcPlcfHdd,
    _Introspection::get_lcbPlcfHdd,
    _Introspection::get_fcPlcfBteChpx,
    _Introspection::get_lcbPlcfBteChpx,
    _Introspection::get_fcPlcfBtePapx,
    _Introspection::get_lcbPlcfBtePapx,
    _Introspection::get_fcPlcfSea,
    _Introspection::get_lcbPlcfSea,
    _Introspection::get_fcSttbfFfn,
    _Introspection::get_lcbSttbfFfn,
    _Introspection::get_fcPlcfFldMom,
    _Introspection::get_lcbPlcfFldMom,
    _Introspection::get_fcPlcfFldHdr,
    _Introspection::get_lcbPlcfFldHdr,
    _Introspection::get_fcPlcfFldFtn,
    _Introspection::get_lcbPlcfFldFtn,
    _Introspection::get_fcPlcfFldAtn,
    _Introspection::get_lcbPlcfFldAtn,
    _Introspection::get_fcPlcfFldMcr,
    _Introspection::get_lcbPlcfFldMcr,
    _Introspection::get_fcSttbfBkmk,
    _Introspection::get_lcbSttbfBkmk,
    _Introspection::get_fcPlcfBkf,
    _Introspection::get_lcbPlcfBkf,
    _Introspection::get_fcPlcfBkl,
    _Introspection::get_lcbPlcfBkl,
    _Introspection::get_fcCmds,
    _Introspection::get_lcbCmds,
    _Introspection::get_fcUnused1,
    _Introspection::get_lcbUnused1,
    _Introspection::get_fcSttbfMcr,
    _Introspection::get_lcbSttbfMcr,
    _Introspection::get_fcPrDrvr,
    _Introspection::get_lcbPrDrvr,
    _Introspection::get_fcPrEnvPort,
    _Introspection::get_lcbPrEnvPort,
    _Introspection::get_fcPrEnvLand,
    _Introspection::get_lcbPrEnvLand,
    _Introspection::get_fcWss,
    _Introspection::get_lcbWss,
    _Introspection::get_fcDop,
    _Introspection::get_lcbDop,
    _Introspection::get_fcSttbfAssoc,
    _Introspection::get_lcbSttbfAssoc,
    _Introspection::get_fcClx,
    _Introspection::get_lcbClx,
    _Introspection::get_fcPlcfPgdFtn,
    _Introspection::get_lcbPlcfPgdFtn,
    _Introspection::get_fcAutosaveSource,
    _Introspection::get_lcbAutosaveSource,
    _Introspection::get_fcGrpXstAtnOwners,
    _Introspection::get_lcbGrpXstAtnOwners,
    _Introspection::get_fcSttbfAtnBkmk,
    _Introspection::get_lcbSttbfAtnBkmk,
    _Introspection::get_fcUnused2,
    _Introspection::get_lcbUnused2,
    _Introspection::get_fcUnused3,
    _Introspection::get_lcbUnused3,
    _Introspection::get_fcPlcSpaMom,
    _Introspection::get_lcbPlcSpaMom,
    _Introspection::get_fcPlcSpaHdr,
    _Introspection::get_lcbPlcSpaHdr,
    _Introspection::get_fcPlcfAtnBkf,
    _Introspection::get_lcbPlcfAtnBkf,
    _Introspection::get_fcPlcfAtnBkl,
    _Introspection::get_lcbPlcfAtnBkl,
    _Introspection::get_fcPms,
    _Introspection::get_lcbPms,
    _Introspection::get_fcFormFldSttbs,
    _Introspection::get_lcbFormFldSttbs,
    _Introspection::get_fcPlcfendRef,
    _Introspection::get_lcbPlcfendRef,
    _Introspection::get_fcPlcfendTxt,
    _Introspection::get_lcbPlcfendTxt,
    _Introspection::get_fcPlcfFldEdn,
    _Introspection::get_lcbPlcfFldEdn,
    _Introspection::get_fcUnused4,
    _Introspection::get_lcbUnused4,
    _Introspection::get_fcDggInfo,
    _Introspection::get_lcbDggInfo,
    _Introspection::get_fcSttbfRMark,
    _Introspection::get_lcbSttbfRMark,
    _Introspection::get_fcSttbfCaption,
    _Introspection::get_lcbSttbfCaption,
    _Introspection::get_fcSttbfAutoCaption,
    _Introspection::get_lcbSttbfAutoCaption,
    _Introspection::get_fcPlcfWkb,
    _Introspection::get_lcbPlcfWkb,
    _Introspection::get_fcPlcfSpl,
    _Introspection::get_lcbPlcfSpl,
    _Introspection::get_fcPlcftxbxTxt,
    _Introspection::get_lcbPlcftxbxTxt,
    _Introspection::get_fcPlcfFldTxbx,
    _Introspection::get_lcbPlcfFldTxbx,
    _Introspection::get_fcPlcfHdrtxbxTxt,
    _Introspection::get_lcbPlcfHdrtxbxTxt,
    _Introspection::get_fcPlcffldHdrTxbx,
    _Introspection::get_lcbPlcffldHdrTxbx,
    _Introspection::get_fcStwUser,
    _Introspection::get_lcbStwUser,
    _Introspection::get_fcSttbTtmbd,
    _Introspection::get_lcbSttbTtmbd,
    _Introspection::get_fcCookieData,
    _Introspection::get_lcbCookieData,
    _Introspection::get_fcPgdMotherOldOld,
    _Introspection::get_lcbPgdMotherOldOld,
    _Introspection::get_fcBkdMotherOldOld,
    _Introspection::get_lcbBkdMotherOldOld,
    _Introspection::get_fcPgdFtnOldOld,
    _Introspection::get_lcbPgdFtnOldOld,
    _Introspection::get_fcBkdFtnOldOld,
    _Introspection::get_lcbBkdFtnOldOld,
    _Introspection::get_fcPgdEdnOldOld,
    _Introspection::get_lcbPgdEdnOldOld,
    _Introspection::get_fcBkdEdnOldOld,
    _Introspection::get_lcbBkdEdnOldOld,
    _Introspection::get_fcSttbfIntlFld,
    _Introspection::get_lcbSttbfIntlFld,
    _Introspection::get_fcRouteSlip,
    _Introspection::get_lcbRouteSlip,
    _Introspection::get_fcSttbSavedBy,
    _Introspection::get_lcbSttbSavedBy,
    _Introspection::get_fcSttbFnm,
    _Introspection::get_lcbSttbFnm,
    _Introspection::get_fcPlfLst,
    _Introspection::get_lcbPlfLst,
    _Introspection::get_fcPlfLfo,
    _Introspection::get_lcbPlfLfo,
    _Introspection::get_fcPlcfTxbxBkd,
    _Introspection::get_lcbPlcfTxbxBkd,
    _Introspection::get_fcPlcfTxbxHdrBkd,
    _Introspection::get_lcbPlcfTxbxHdrBkd,
    _Introspection::get_fcDocUndoWord9,
    _Introspection::get_lcbDocUndoWord9,
    _Introspection::get_fcRgbUse,
    _Introspection::get_lcbRgbUse,
    _Introspection::get_fcUsp,
    _Introspection::get_lcbUsp,
    _Introspection::get_fcUskf,
    _Introspection::get_lcbUskf,
    _Introspection::get_fcPlcupcRgbUse,
    _Introspection::get_lcbPlcupcRgbUse,
    _Introspection::get_fcPlcupcUsp,
    _Introspection::get_lcbPlcupcUsp,
    _Introspection::get_fcSttbGlsyStyle,
    _Introspection::get_lcbSttbGlsyStyle,
    _Introspection::get_fcPlgosl,
    _Introspection::get_lcbPlgosl,
    _Introspection::get_fcPlcocx,
    _Introspection::get_lcbPlcocx,
    _Introspection::get_fcPlcfBteLvc,
    _Introspection::get_lcbPlcfBteLvc,
    _Introspection::get_dwLowDateTime,
    _Introspection::get_dwHighDateTime,
    _Introspection::get_fcPlcfLvcPre10,
    _Introspection::get_lcbPlcfLvcPre10,
    _Introspection::get_fcPlcfAsumy,
    _Introspection::get_lcbPlcfAsumy,
    _Introspection::get_fcPlcfGram,
    _Introspection::get_lcbPlcfGram,
    _Introspection::get_fcSttbListNames,
    _Introspection::get_lcbSttbListNames,
    _Introspection::get_fcSttbfUssr,
    _Introspection::get_lcbSttbfUssr,
};
const Introspectable* (* const FibRgFcLcb97::_Introspection::introspectable[186])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FibRgFcLcb97::_introspection(
    "FibRgFcLcb97", 186, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FibRgFcLcb2000::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[30];
    static int (* const numberOfInstances[30])(const Introspectable*);
    static QVariant (* const value[30])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[30])(const Introspectable*, int position);
    static QVariant get_fcPlcfTch(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPlcfTch);
    }
    static QVariant get_lcbPlcfTch(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPlcfTch);
    }
    static QVariant get_fcRmdThreading(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcRmdThreading);
    }
    static QVariant get_lcbRmdThreading(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbRmdThreading);
    }
    static QVariant get_fcMid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcMid);
    }
    static QVariant get_lcbMid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbMid);
    }
    static QVariant get_fcSttbRgtplc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcSttbRgtplc);
    }
    static QVariant get_lcbSttbRgtplc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbSttbRgtplc);
    }
    static QVariant get_fcMsoEnvelope(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcMsoEnvelope);
    }
    static QVariant get_lcbMsoEnvelope(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbMsoEnvelope);
    }
    static QVariant get_fcPlcfLad(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPlcfLad);
    }
    static QVariant get_lcbPlcfLad(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPlcfLad);
    }
    static QVariant get_fcRgDofr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcRgDofr);
    }
    static QVariant get_lcbRgDofr(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbRgDofr);
    }
    static QVariant get_fcPlcosl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPlcosl);
    }
    static QVariant get_lcbPlcosl(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPlcosl);
    }
    static QVariant get_fcPlcfCookieOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPlcfCookieOld);
    }
    static QVariant get_lcbPlcfCookieOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPlcfCookieOld);
    }
    static QVariant get_fcPgdMotherOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPgdMotherOld);
    }
    static QVariant get_lcbPgdMotherOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPgdMotherOld);
    }
    static QVariant get_fcBkdMotherOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcBkdMotherOld);
    }
    static QVariant get_lcbBkdMotherOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbBkdMotherOld);
    }
    static QVariant get_fcPgdFtnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPgdFtnOld);
    }
    static QVariant get_lcbPgdFtnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPgdFtnOld);
    }
    static QVariant get_fcBkdFtnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcBkdFtnOld);
    }
    static QVariant get_lcbBkdFtnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbBkdFtnOld);
    }
    static QVariant get_fcPgdEdnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcPgdEdnOld);
    }
    static QVariant get_lcbPgdEdnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbPgdEdnOld);
    }
    static QVariant get_fcBkdEdnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->fcBkdEdnOld);
    }
    static QVariant get_lcbBkdEdnOld(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2000*>(i)->lcbBkdEdnOld);
    }
};
const QString FibRgFcLcb2000::_Introspection::name("FibRgFcLcb2000");
const int FibRgFcLcb2000::_Introspection::numberOfMembers(30);
const QString FibRgFcLcb2000::_Introspection::names[30] = {
    "fcPlcfTch",
    "lcbPlcfTch",
    "fcRmdThreading",
    "lcbRmdThreading",
    "fcMid",
    "lcbMid",
    "fcSttbRgtplc",
    "lcbSttbRgtplc",
    "fcMsoEnvelope",
    "lcbMsoEnvelope",
    "fcPlcfLad",
    "lcbPlcfLad",
    "fcRgDofr",
    "lcbRgDofr",
    "fcPlcosl",
    "lcbPlcosl",
    "fcPlcfCookieOld",
    "lcbPlcfCookieOld",
    "fcPgdMotherOld",
    "lcbPgdMotherOld",
    "fcBkdMotherOld",
    "lcbBkdMotherOld",
    "fcPgdFtnOld",
    "lcbPgdFtnOld",
    "fcBkdFtnOld",
    "lcbBkdFtnOld",
    "fcPgdEdnOld",
    "lcbPgdEdnOld",
    "fcBkdEdnOld",
    "lcbBkdEdnOld",
};
int (* const FibRgFcLcb2000::_Introspection::numberOfInstances[30])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FibRgFcLcb2000::_Introspection::value[30])(const Introspectable*, int position) = {
    _Introspection::get_fcPlcfTch,
    _Introspection::get_lcbPlcfTch,
    _Introspection::get_fcRmdThreading,
    _Introspection::get_lcbRmdThreading,
    _Introspection::get_fcMid,
    _Introspection::get_lcbMid,
    _Introspection::get_fcSttbRgtplc,
    _Introspection::get_lcbSttbRgtplc,
    _Introspection::get_fcMsoEnvelope,
    _Introspection::get_lcbMsoEnvelope,
    _Introspection::get_fcPlcfLad,
    _Introspection::get_lcbPlcfLad,
    _Introspection::get_fcRgDofr,
    _Introspection::get_lcbRgDofr,
    _Introspection::get_fcPlcosl,
    _Introspection::get_lcbPlcosl,
    _Introspection::get_fcPlcfCookieOld,
    _Introspection::get_lcbPlcfCookieOld,
    _Introspection::get_fcPgdMotherOld,
    _Introspection::get_lcbPgdMotherOld,
    _Introspection::get_fcBkdMotherOld,
    _Introspection::get_lcbBkdMotherOld,
    _Introspection::get_fcPgdFtnOld,
    _Introspection::get_lcbPgdFtnOld,
    _Introspection::get_fcBkdFtnOld,
    _Introspection::get_lcbBkdFtnOld,
    _Introspection::get_fcPgdEdnOld,
    _Introspection::get_lcbPgdEdnOld,
    _Introspection::get_fcBkdEdnOld,
    _Introspection::get_lcbBkdEdnOld,
};
const Introspectable* (* const FibRgFcLcb2000::_Introspection::introspectable[30])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FibRgFcLcb2000::_introspection(
    "FibRgFcLcb2000", 30, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FibRgFcLcb2002::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[50];
    static int (* const numberOfInstances[50])(const Introspectable*);
    static QVariant (* const value[50])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[50])(const Introspectable*, int position);
    static QVariant get_fcUnused1(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcUnused1);
    }
    static QVariant get_lcbUnused1(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbUnused1);
    }
    static QVariant get_fcPlcfPgp(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfPgp);
    }
    static QVariant get_lcbPlcfPgp(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfPgp);
    }
    static QVariant get_fcPlcfuim(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfuim);
    }
    static QVariant get_lcbPlcfuim(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfuim);
    }
    static QVariant get_fcPlfguidUim(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlfguidUim);
    }
    static QVariant get_lcbPlfguidUim(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlfguidUim);
    }
    static QVariant get_fcAtrdExtra(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcAtrdExtra);
    }
    static QVariant get_lcbAtrdExtra(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbAtrdExtra);
    }
    static QVariant get_fcPlrsid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlrsid);
    }
    static QVariant get_lcbPlrsid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlrsid);
    }
    static QVariant get_fcSttbfBkmkFactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcSttbfBkmkFactoid);
    }
    static QVariant get_lcbSttbfBkmkFactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbSttbfBkmkFactoid);
    }
    static QVariant get_fcPlcfBkfFactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfBkfFactoid);
    }
    static QVariant get_lcbPlcfBkfFactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfBkfFactoid);
    }
    static QVariant get_fcPlcfcookie(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfcookie);
    }
    static QVariant get_lcbPlcfcookie(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfcookie);
    }
    static QVariant get_fcPlcfBklFactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfBklFactoid);
    }
    static QVariant get_lcbPlcfBklFactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfBklFactoid);
    }
    static QVariant get_fcFactoidData(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcFactoidData);
    }
    static QVariant get_lcbFactoidData(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbFactoidData);
    }
    static QVariant get_fcDocUndo(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcDocUndo);
    }
    static QVariant get_lcbDocUndo(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbDocUndo);
    }
    static QVariant get_fcSttbfBkmkFcc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcSttbfBkmkFcc);
    }
    static QVariant get_lcbSttbfBkmkFcc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbSttbfBkmkFcc);
    }
    static QVariant get_fcPlcfBkfFcc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfBkfFcc);
    }
    static QVariant get_lcbPlcfBkfFcc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfBkfFcc);
    }
    static QVariant get_fcPlcfBklFcc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfBklFcc);
    }
    static QVariant get_lcbPlcfBklFcc(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfBklFcc);
    }
    static QVariant get_fcSttbfbkmkBPRepairs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcSttbfbkmkBPRepairs);
    }
    static QVariant get_lcbSttbfbkmkBPRepairs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbSttbfbkmkBPRepairs);
    }
    static QVariant get_fcPlcfbkfBPRepairs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfbkfBPRepairs);
    }
    static QVariant get_lcbPlcfbkfBPRepairs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfbkfBPRepairs);
    }
    static QVariant get_fcPlcfbklBPRepairs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfbklBPRepairs);
    }
    static QVariant get_lcbPlcfbklBPRepairs(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfbklBPRepairs);
    }
    static QVariant get_fcPmsNew(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPmsNew);
    }
    static QVariant get_lcbPmsNew(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPmsNew);
    }
    static QVariant get_fcODSO(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcODSO);
    }
    static QVariant get_lcbODSO(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbODSO);
    }
    static QVariant get_fcPlcfpmiOldXP(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfpmiOldXP);
    }
    static QVariant get_lcbPlcfpmiOldXP(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfpmiOldXP);
    }
    static QVariant get_fcPlcfpmiNewXP(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfpmiNewXP);
    }
    static QVariant get_lcbPlcfpmiNewXP(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfpmiNewXP);
    }
    static QVariant get_fcPlcfpmiMixedXP(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcfpmiMixedXP);
    }
    static QVariant get_lcbPlcfpmiMixedXP(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcfpmiMixedXP);
    }
    static QVariant get_fcUnused2(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcUnused2);
    }
    static QVariant get_lcbUnused2(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbUnused2);
    }
    static QVariant get_fcPlcffactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->fcPlcffactoid);
    }
    static QVariant get_lcbPlcffactoid(const Introspectable* i, int j) {
        return (static_cast<const FibRgFcLcb2002*>(i)->lcbPlcffactoid);
    }
};
const QString FibRgFcLcb2002::_Introspection::name("FibRgFcLcb2002");
const int FibRgFcLcb2002::_Introspection::numberOfMembers(50);
const QString FibRgFcLcb2002::_Introspection::names[50] = {
    "fcUnused1",
    "lcbUnused1",
    "fcPlcfPgp",
    "lcbPlcfPgp",
    "fcPlcfuim",
    "lcbPlcfuim",
    "fcPlfguidUim",
    "lcbPlfguidUim",
    "fcAtrdExtra",
    "lcbAtrdExtra",
    "fcPlrsid",
    "lcbPlrsid",
    "fcSttbfBkmkFactoid",
    "lcbSttbfBkmkFactoid",
    "fcPlcfBkfFactoid",
    "lcbPlcfBkfFactoid",
    "fcPlcfcookie",
    "lcbPlcfcookie",
    "fcPlcfBklFactoid",
    "lcbPlcfBklFactoid",
    "fcFactoidData",
    "lcbFactoidData",
    "fcDocUndo",
    "lcbDocUndo",
    "fcSttbfBkmkFcc",
    "lcbSttbfBkmkFcc",
    "fcPlcfBkfFcc",
    "lcbPlcfBkfFcc",
    "fcPlcfBklFcc",
    "lcbPlcfBklFcc",
    "fcSttbfbkmkBPRepairs",
    "lcbSttbfbkmkBPRepairs",
    "fcPlcfbkfBPRepairs",
    "lcbPlcfbkfBPRepairs",
    "fcPlcfbklBPRepairs",
    "lcbPlcfbklBPRepairs",
    "fcPmsNew",
    "lcbPmsNew",
    "fcODSO",
    "lcbODSO",
    "fcPlcfpmiOldXP",
    "lcbPlcfpmiOldXP",
    "fcPlcfpmiNewXP",
    "lcbPlcfpmiNewXP",
    "fcPlcfpmiMixedXP",
    "lcbPlcfpmiMixedXP",
    "fcUnused2",
    "lcbUnused2",
    "fcPlcffactoid",
    "lcbPlcffactoid",
};
int (* const FibRgFcLcb2002::_Introspection::numberOfInstances[50])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FibRgFcLcb2002::_Introspection::value[50])(const Introspectable*, int position) = {
    _Introspection::get_fcUnused1,
    _Introspection::get_lcbUnused1,
    _Introspection::get_fcPlcfPgp,
    _Introspection::get_lcbPlcfPgp,
    _Introspection::get_fcPlcfuim,
    _Introspection::get_lcbPlcfuim,
    _Introspection::get_fcPlfguidUim,
    _Introspection::get_lcbPlfguidUim,
    _Introspection::get_fcAtrdExtra,
    _Introspection::get_lcbAtrdExtra,
    _Introspection::get_fcPlrsid,
    _Introspection::get_lcbPlrsid,
    _Introspection::get_fcSttbfBkmkFactoid,
    _Introspection::get_lcbSttbfBkmkFactoid,
    _Introspection::get_fcPlcfBkfFactoid,
    _Introspection::get_lcbPlcfBkfFactoid,
    _Introspection::get_fcPlcfcookie,
    _Introspection::get_lcbPlcfcookie,
    _Introspection::get_fcPlcfBklFactoid,
    _Introspection::get_lcbPlcfBklFactoid,
    _Introspection::get_fcFactoidData,
    _Introspection::get_lcbFactoidData,
    _Introspection::get_fcDocUndo,
    _Introspection::get_lcbDocUndo,
    _Introspection::get_fcSttbfBkmkFcc,
    _Introspection::get_lcbSttbfBkmkFcc,
    _Introspection::get_fcPlcfBkfFcc,
    _Introspection::get_lcbPlcfBkfFcc,
    _Introspection::get_fcPlcfBklFcc,
    _Introspection::get_lcbPlcfBklFcc,
    _Introspection::get_fcSttbfbkmkBPRepairs,
    _Introspection::get_lcbSttbfbkmkBPRepairs,
    _Introspection::get_fcPlcfbkfBPRepairs,
    _Introspection::get_lcbPlcfbkfBPRepairs,
    _Introspection::get_fcPlcfbklBPRepairs,
    _Introspection::get_lcbPlcfbklBPRepairs,
    _Introspection::get_fcPmsNew,
    _Introspection::get_lcbPmsNew,
    _Introspection::get_fcODSO,
    _Introspection::get_lcbODSO,
    _Introspection::get_fcPlcfpmiOldXP,
    _Introspection::get_lcbPlcfpmiOldXP,
    _Introspection::get_fcPlcfpmiNewXP,
    _Introspection::get_lcbPlcfpmiNewXP,
    _Introspection::get_fcPlcfpmiMixedXP,
    _Introspection::get_lcbPlcfpmiMixedXP,
    _Introspection::get_fcUnused2,
    _Introspection::get_lcbUnused2,
    _Introspection::get_fcPlcffactoid,
    _Introspection::get_lcbPlcffactoid,
};
const Introspectable* (* const FibRgFcLcb2002::_Introspection::introspectable[50])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FibRgFcLcb2002::_introspection(
    "FibRgFcLcb2002", 50, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class LPStshi::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_cbSthi(const Introspectable* i, int j) {
        return (static_cast<const LPStshi*>(i)->cbSthi);
    }
    static QVariant get_stshi(const Introspectable* i, int j) {
        return (static_cast<const LPStshi*>(i)->stshi);
    }
};
const QString LPStshi::_Introspection::name("LPStshi");
const int LPStshi::_Introspection::numberOfMembers(2);
const QString LPStshi::_Introspection::names[2] = {
    "cbSthi",
    "stshi",
};
int (* const LPStshi::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const LPStshi::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_cbSthi,
    _Introspection::get_stshi,
};
const Introspectable* (* const LPStshi::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection LPStshi::_introspection(
    "LPStshi", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class LPStd::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_cbStd(const Introspectable* i, int j) {
        return (static_cast<const LPStd*>(i)->cbStd);
    }
    static QVariant get_std(const Introspectable* i, int j) {
        return (static_cast<const LPStd*>(i)->std);
    }
    static QVariant get_padding(const Introspectable* i, int j) {
        return (static_cast<const LPStd*>(i)->padding);
    }
};
const QString LPStd::_Introspection::name("LPStd");
const int LPStd::_Introspection::numberOfMembers(3);
const QString LPStd::_Introspection::names[3] = {
    "cbStd",
    "std",
    "padding",
};
int (* const LPStd::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const LPStd::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_cbStd,
    _Introspection::get_std,
    _Introspection::get_padding,
};
const Introspectable* (* const LPStd::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection LPStd::_introspection(
    "LPStd", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PlcfSed::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static int count_aCP(const Introspectable* i) {
        return static_cast<const PlcfSed*>(i)->aCP.size();
    }
    static QVariant get_aCP(const Introspectable* i, int j) {
        return (static_cast<const PlcfSed*>(i)->aCP[j]);
    }
    static int count_aSed(const Introspectable* i) {
        return static_cast<const PlcfSed*>(i)->aSed.size();
    }
    static const Introspectable* get_aSed(const Introspectable* i, int j) {
        return &(static_cast<const PlcfSed*>(i)->aSed[j]);
    }
};
const QString PlcfSed::_Introspection::name("PlcfSed");
const int PlcfSed::_Introspection::numberOfMembers(2);
const QString PlcfSed::_Introspection::names[2] = {
    "aCP",
    "aSed",
};
int (* const PlcfSed::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    _Introspection::count_aCP,
    _Introspection::count_aSed,
};
QVariant (* const PlcfSed::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_aCP,
    Introspection::nullValue,
};
const Introspectable* (* const PlcfSed::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    _Introspection::get_aSed,
};
const Introspection PlcfSed::_introspection(
    "PlcfSed", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Sed::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_fn(const Introspectable* i, int j) {
        return (static_cast<const Sed*>(i)->fn);
    }
    static QVariant get_fcSepx(const Introspectable* i, int j) {
        return (static_cast<const Sed*>(i)->fcSepx);
    }
    static QVariant get_fnMpr(const Introspectable* i, int j) {
        return (static_cast<const Sed*>(i)->fnMpr);
    }
    static QVariant get_fcMpr(const Introspectable* i, int j) {
        return (static_cast<const Sed*>(i)->fcMpr);
    }
};
const QString Sed::_Introspection::name("Sed");
const int Sed::_Introspection::numberOfMembers(4);
const QString Sed::_Introspection::names[4] = {
    "fn",
    "fcSepx",
    "fnMpr",
    "fcMpr",
};
int (* const Sed::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const Sed::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_fn,
    _Introspection::get_fcSepx,
    _Introspection::get_fnMpr,
    _Introspection::get_fcMpr,
};
const Introspectable* (* const Sed::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection Sed::_introspection(
    "Sed", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Plcfhdd::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static int count_aCP(const Introspectable* i) {
        return static_cast<const Plcfhdd*>(i)->aCP.size();
    }
    static QVariant get_aCP(const Introspectable* i, int j) {
        return (static_cast<const Plcfhdd*>(i)->aCP[j]);
    }
};
const QString Plcfhdd::_Introspection::name("Plcfhdd");
const int Plcfhdd::_Introspection::numberOfMembers(1);
const QString Plcfhdd::_Introspection::names[1] = {
    "aCP",
};
int (* const Plcfhdd::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    _Introspection::count_aCP,
};
QVariant (* const Plcfhdd::_Introspection::value[1])(const Introspectable*, int position) = {
    _Introspection::get_aCP,
};
const Introspectable* (* const Plcfhdd::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    Introspection::null,
};
const Introspection Plcfhdd::_introspection(
    "Plcfhdd", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PlcBteChpx::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static int count_aCP(const Introspectable* i) {
        return static_cast<const PlcBteChpx*>(i)->aCP.size();
    }
    static QVariant get_aCP(const Introspectable* i, int j) {
        return (static_cast<const PlcBteChpx*>(i)->aCP[j]);
    }
    static int count_aPnBteChpx(const Introspectable* i) {
        return static_cast<const PlcBteChpx*>(i)->aPnBteChpx.size();
    }
    static QVariant get_aPnBteChpx(const Introspectable* i, int j) {
        return (static_cast<const PlcBteChpx*>(i)->aPnBteChpx[j]);
    }
};
const QString PlcBteChpx::_Introspection::name("PlcBteChpx");
const int PlcBteChpx::_Introspection::numberOfMembers(2);
const QString PlcBteChpx::_Introspection::names[2] = {
    "aCP",
    "aPnBteChpx",
};
int (* const PlcBteChpx::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    _Introspection::count_aCP,
    _Introspection::count_aPnBteChpx,
};
QVariant (* const PlcBteChpx::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_aCP,
    _Introspection::get_aPnBteChpx,
};
const Introspectable* (* const PlcBteChpx::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection PlcBteChpx::_introspection(
    "PlcBteChpx", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PlcfBtePapx::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static int count_aCP(const Introspectable* i) {
        return static_cast<const PlcfBtePapx*>(i)->aCP.size();
    }
    static QVariant get_aCP(const Introspectable* i, int j) {
        return (static_cast<const PlcfBtePapx*>(i)->aCP[j]);
    }
    static int count_aPnBteChpx(const Introspectable* i) {
        return static_cast<const PlcfBtePapx*>(i)->aPnBteChpx.size();
    }
    static QVariant get_aPnBteChpx(const Introspectable* i, int j) {
        return (static_cast<const PlcfBtePapx*>(i)->aPnBteChpx[j]);
    }
};
const QString PlcfBtePapx::_Introspection::name("PlcfBtePapx");
const int PlcfBtePapx::_Introspection::numberOfMembers(2);
const QString PlcfBtePapx::_Introspection::names[2] = {
    "aCP",
    "aPnBteChpx",
};
int (* const PlcfBtePapx::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    _Introspection::count_aCP,
    _Introspection::count_aPnBteChpx,
};
QVariant (* const PlcfBtePapx::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_aCP,
    _Introspection::get_aPnBteChpx,
};
const Introspectable* (* const PlcfBtePapx::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection PlcfBtePapx::_introspection(
    "PlcfBtePapx", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Tcg::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_nTcgVer(const Introspectable* i, int j) {
        return (static_cast<const Tcg*>(i)->nTcgVer);
    }
    static QVariant get_todo(const Introspectable* i, int j) {
        return (static_cast<const Tcg*>(i)->todo);
    }
};
const QString Tcg::_Introspection::name("Tcg");
const int Tcg::_Introspection::numberOfMembers(2);
const QString Tcg::_Introspection::names[2] = {
    "nTcgVer",
    "todo",
};
int (* const Tcg::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const Tcg::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_nTcgVer,
    _Introspection::get_todo,
};
const Introspectable* (* const Tcg::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection Tcg::_introspection(
    "Tcg", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PrcData::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_cbGrpprl(const Introspectable* i, int j) {
        return (static_cast<const PrcData*>(i)->cbGrpprl);
    }
    static int count_GrpPrl(const Introspectable* i) {
        return static_cast<const PrcData*>(i)->GrpPrl.size();
    }
    static const Introspectable* get_GrpPrl(const Introspectable* i, int j) {
        return &(static_cast<const PrcData*>(i)->GrpPrl[j]);
    }
};
const QString PrcData::_Introspection::name("PrcData");
const int PrcData::_Introspection::numberOfMembers(2);
const QString PrcData::_Introspection::names[2] = {
    "cbGrpprl",
    "GrpPrl",
};
int (* const PrcData::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_GrpPrl,
};
QVariant (* const PrcData::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_cbGrpprl,
    Introspection::nullValue,
};
const Introspectable* (* const PrcData::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    _Introspection::get_GrpPrl,
};
const Introspection PrcData::_introspection(
    "PrcData", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Sprm::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[4];
    static int (* const numberOfInstances[4])(const Introspectable*);
    static QVariant (* const value[4])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[4])(const Introspectable*, int position);
    static QVariant get_ispmd(const Introspectable* i, int j) {
        return (static_cast<const Sprm*>(i)->ispmd);
    }
    static QVariant get_fSpec(const Introspectable* i, int j) {
        return (static_cast<const Sprm*>(i)->fSpec);
    }
    static QVariant get_sgc(const Introspectable* i, int j) {
        return (static_cast<const Sprm*>(i)->sgc);
    }
    static QVariant get_spra(const Introspectable* i, int j) {
        return (static_cast<const Sprm*>(i)->spra);
    }
};
const QString Sprm::_Introspection::name("Sprm");
const int Sprm::_Introspection::numberOfMembers(4);
const QString Sprm::_Introspection::names[4] = {
    "ispmd",
    "fSpec",
    "sgc",
    "spra",
};
int (* const Sprm::_Introspection::numberOfInstances[4])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const Sprm::_Introspection::value[4])(const Introspectable*, int position) = {
    _Introspection::get_ispmd,
    _Introspection::get_fSpec,
    _Introspection::get_sgc,
    _Introspection::get_spra,
};
const Introspectable* (* const Sprm::_Introspection::introspectable[4])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection Sprm::_introspection(
    "Sprm", 4, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Pcdt::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_clxt(const Introspectable* i, int j) {
        return (static_cast<const Pcdt*>(i)->clxt);
    }
    static QVariant get_lcb(const Introspectable* i, int j) {
        return (static_cast<const Pcdt*>(i)->lcb);
    }
    static int count_PlcPcd(const Introspectable* i) {
        return static_cast<const Pcdt*>(i)->PlcPcd.size();
    }
    static const Introspectable* get_PlcPcd(const Introspectable* i, int j) {
        return &(static_cast<const Pcdt*>(i)->PlcPcd[j]);
    }
};
const QString Pcdt::_Introspection::name("Pcdt");
const int Pcdt::_Introspection::numberOfMembers(3);
const QString Pcdt::_Introspection::names[3] = {
    "clxt",
    "lcb",
    "PlcPcd",
};
int (* const Pcdt::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_PlcPcd,
};
QVariant (* const Pcdt::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_clxt,
    _Introspection::get_lcb,
    Introspection::nullValue,
};
const Introspectable* (* const Pcdt::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    _Introspection::get_PlcPcd,
};
const Introspection Pcdt::_introspection(
    "Pcdt", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class FCompressed::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_fc(const Introspectable* i, int j) {
        return (static_cast<const FCompressed*>(i)->fc);
    }
    static QVariant get_fCompressed(const Introspectable* i, int j) {
        return (static_cast<const FCompressed*>(i)->fCompressed);
    }
    static QVariant get_r1(const Introspectable* i, int j) {
        return (static_cast<const FCompressed*>(i)->r1);
    }
};
const QString FCompressed::_Introspection::name("FCompressed");
const int FCompressed::_Introspection::numberOfMembers(3);
const QString FCompressed::_Introspection::names[3] = {
    "fc",
    "fCompressed",
    "r1",
};
int (* const FCompressed::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const FCompressed::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_fc,
    _Introspection::get_fCompressed,
    _Introspection::get_r1,
};
const Introspectable* (* const FCompressed::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection FCompressed::_introspection(
    "FCompressed", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Prm0::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_fComplex(const Introspectable* i, int j) {
        return (static_cast<const Prm0*>(i)->fComplex);
    }
    static QVariant get_isprm(const Introspectable* i, int j) {
        return (static_cast<const Prm0*>(i)->isprm);
    }
    static QVariant get_val(const Introspectable* i, int j) {
        return (static_cast<const Prm0*>(i)->val);
    }
};
const QString Prm0::_Introspection::name("Prm0");
const int Prm0::_Introspection::numberOfMembers(3);
const QString Prm0::_Introspection::names[3] = {
    "fComplex",
    "isprm",
    "val",
};
int (* const Prm0::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const Prm0::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_fComplex,
    _Introspection::get_isprm,
    _Introspection::get_val,
};
const Introspectable* (* const Prm0::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection Prm0::_introspection(
    "Prm0", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Prm1::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_fComplex(const Introspectable* i, int j) {
        return (static_cast<const Prm1*>(i)->fComplex);
    }
    static QVariant get_igrpprl(const Introspectable* i, int j) {
        return (static_cast<const Prm1*>(i)->igrpprl);
    }
};
const QString Prm1::_Introspection::name("Prm1");
const int Prm1::_Introspection::numberOfMembers(2);
const QString Prm1::_Introspection::names[2] = {
    "fComplex",
    "igrpprl",
};
int (* const Prm1::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const Prm1::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_fComplex,
    _Introspection::get_igrpprl,
};
const Introspectable* (* const Prm1::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection Prm1::_introspection(
    "Prm1", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SttbfFfn::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static QVariant get_cData(const Introspectable* i, int j) {
        return (static_cast<const SttbfFfn*>(i)->cData);
    }
    static QVariant get_cbExtra(const Introspectable* i, int j) {
        return (static_cast<const SttbfFfn*>(i)->cbExtra);
    }
    static int count_data(const Introspectable* i) {
        return static_cast<const SttbfFfn*>(i)->data.size();
    }
    static const Introspectable* get_data(const Introspectable* i, int j) {
        return &(static_cast<const SttbfFfn*>(i)->data[j]);
    }
};
const QString SttbfFfn::_Introspection::name("SttbfFfn");
const int SttbfFfn::_Introspection::numberOfMembers(3);
const QString SttbfFfn::_Introspection::names[3] = {
    "cData",
    "cbExtra",
    "data",
};
int (* const SttbfFfn::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_data,
};
QVariant (* const SttbfFfn::_Introspection::value[3])(const Introspectable*, int position) = {
    _Introspection::get_cData,
    _Introspection::get_cbExtra,
    Introspection::nullValue,
};
const Introspectable* (* const SttbfFfn::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    _Introspection::get_data,
};
const Introspection SttbfFfn::_introspection(
    "SttbfFfn", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SttbfFfnEntry::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_cchData(const Introspectable* i, int j) {
        return (static_cast<const SttbfFfnEntry*>(i)->cchData);
    }
    static QVariant get_Data(const Introspectable* i, int j) {
        return (static_cast<const SttbfFfnEntry*>(i)->Data);
    }
};
const QString SttbfFfnEntry::_Introspection::name("SttbfFfnEntry");
const int SttbfFfnEntry::_Introspection::numberOfMembers(2);
const QString SttbfFfnEntry::_Introspection::names[2] = {
    "cchData",
    "Data",
};
int (* const SttbfFfnEntry::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const SttbfFfnEntry::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_cchData,
    _Introspection::get_Data,
};
const Introspectable* (* const SttbfFfnEntry::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
};
const Introspection SttbfFfnEntry::_introspection(
    "SttbfFfnEntry", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PicturesStream::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon1(const Introspectable* i, int j) {
        return &(static_cast<const PicturesStream*>(i)->anon1);
    }
};
const QString PicturesStream::_Introspection::name("PicturesStream");
const int PicturesStream::_Introspection::numberOfMembers(1);
const QString PicturesStream::_Introspection::names[1] = {
    "anon1",
};
int (* const PicturesStream::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const PicturesStream::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const PicturesStream::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon1,
};
const Introspection PicturesStream::_introspection(
    "PicturesStream", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtMetafileHeader::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[6];
    static int (* const numberOfInstances[6])(const Introspectable*);
    static QVariant (* const value[6])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[6])(const Introspectable*, int position);
    static QVariant get_cbSize(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtMetafileHeader*>(i)->cbSize);
    }
    static const Introspectable* get_rcBounds(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtMetafileHeader*>(i)->rcBounds);
    }
    static const Introspectable* get_ptSize(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtMetafileHeader*>(i)->ptSize);
    }
    static QVariant get_cbsave(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtMetafileHeader*>(i)->cbsave);
    }
    static QVariant get_compression(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtMetafileHeader*>(i)->compression);
    }
    static QVariant get_filter(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtMetafileHeader*>(i)->filter);
    }
};
const QString OfficeArtMetafileHeader::_Introspection::name("OfficeArtMetafileHeader");
const int OfficeArtMetafileHeader::_Introspection::numberOfMembers(6);
const QString OfficeArtMetafileHeader::_Introspection::names[6] = {
    "cbSize",
    "rcBounds",
    "ptSize",
    "cbsave",
    "compression",
    "filter",
};
int (* const OfficeArtMetafileHeader::_Introspection::numberOfInstances[6])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtMetafileHeader::_Introspection::value[6])(const Introspectable*, int position) = {
    _Introspection::get_cbSize,
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_cbsave,
    _Introspection::get_compression,
    _Introspection::get_filter,
};
const Introspectable* (* const OfficeArtMetafileHeader::_Introspection::introspectable[6])(const Introspectable*, int position) = {
    Introspection::null,
    _Introspection::get_rcBounds,
    _Introspection::get_ptSize,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtMetafileHeader::_introspection(
    "OfficeArtMetafileHeader", 6, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class NormalViewSetInfoAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[9];
    static int (* const numberOfInstances[9])(const Introspectable*);
    static QVariant (* const value[9])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[9])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const NormalViewSetInfoAtom*>(i)->rh);
    }
    static const Introspectable* get_leftPortion(const Introspectable* i, int j) {
        return &(static_cast<const NormalViewSetInfoAtom*>(i)->leftPortion);
    }
    static const Introspectable* get_topPortion(const Introspectable* i, int j) {
        return &(static_cast<const NormalViewSetInfoAtom*>(i)->topPortion);
    }
    static QVariant get_vertBarState(const Introspectable* i, int j) {
        return (static_cast<const NormalViewSetInfoAtom*>(i)->vertBarState);
    }
    static QVariant get_horizBarState(const Introspectable* i, int j) {
        return (static_cast<const NormalViewSetInfoAtom*>(i)->horizBarState);
    }
    static QVariant get_fPreferSingleSet(const Introspectable* i, int j) {
        return (static_cast<const NormalViewSetInfoAtom*>(i)->fPreferSingleSet);
    }
    static QVariant get_fHideThumbnails(const Introspectable* i, int j) {
        return (static_cast<const NormalViewSetInfoAtom*>(i)->fHideThumbnails);
    }
    static QVariant get_fBarSnapped(const Introspectable* i, int j) {
        return (static_cast<const NormalViewSetInfoAtom*>(i)->fBarSnapped);
    }
    static QVariant get_reserved(const Introspectable* i, int j) {
        return (static_cast<const NormalViewSetInfoAtom*>(i)->reserved);
    }
};
const QString NormalViewSetInfoAtom::_Introspection::name("NormalViewSetInfoAtom");
const int NormalViewSetInfoAtom::_Introspection::numberOfMembers(9);
const QString NormalViewSetInfoAtom::_Introspection::names[9] = {
    "rh",
    "leftPortion",
    "topPortion",
    "vertBarState",
    "horizBarState",
    "fPreferSingleSet",
    "fHideThumbnails",
    "fBarSnapped",
    "reserved",
};
int (* const NormalViewSetInfoAtom::_Introspection::numberOfInstances[9])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const NormalViewSetInfoAtom::_Introspection::value[9])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_vertBarState,
    _Introspection::get_horizBarState,
    _Introspection::get_fPreferSingleSet,
    _Introspection::get_fHideThumbnails,
    _Introspection::get_fBarSnapped,
    _Introspection::get_reserved,
};
const Introspectable* (* const NormalViewSetInfoAtom::_Introspection::introspectable[9])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_leftPortion,
    _Introspection::get_topPortion,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection NormalViewSetInfoAtom::_introspection(
    "NormalViewSetInfoAtom", 9, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MasterPersistAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[10];
    static int (* const numberOfInstances[10])(const Introspectable*);
    static QVariant (* const value[10])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[10])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const MasterPersistAtom*>(i)->rh);
    }
    static const Introspectable* get_persistIdRef(const Introspectable* i, int j) {
        return &(static_cast<const MasterPersistAtom*>(i)->persistIdRef);
    }
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->reserved1);
    }
    static QVariant get_fNonOutLineData(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->fNonOutLineData);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->reserved2);
    }
    static QVariant get_reserved3(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->reserved3);
    }
    static QVariant get_reserved4(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->reserved4);
    }
    static QVariant get_reserved5(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->reserved5);
    }
    static QVariant get_masterId(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->masterId);
    }
    static QVariant get_reserved6(const Introspectable* i, int j) {
        return (static_cast<const MasterPersistAtom*>(i)->reserved6);
    }
};
const QString MasterPersistAtom::_Introspection::name("MasterPersistAtom");
const int MasterPersistAtom::_Introspection::numberOfMembers(10);
const QString MasterPersistAtom::_Introspection::names[10] = {
    "rh",
    "persistIdRef",
    "reserved1",
    "fNonOutLineData",
    "reserved2",
    "reserved3",
    "reserved4",
    "reserved5",
    "masterId",
    "reserved6",
};
int (* const MasterPersistAtom::_Introspection::numberOfInstances[10])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const MasterPersistAtom::_Introspection::value[10])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_reserved1,
    _Introspection::get_fNonOutLineData,
    _Introspection::get_reserved2,
    _Introspection::get_reserved3,
    _Introspection::get_reserved4,
    _Introspection::get_reserved5,
    _Introspection::get_masterId,
    _Introspection::get_reserved6,
};
const Introspectable* (* const MasterPersistAtom::_Introspection::introspectable[10])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_persistIdRef,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection MasterPersistAtom::_introspection(
    "MasterPersistAtom", 10, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlidePersistAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[11];
    static int (* const numberOfInstances[11])(const Introspectable*);
    static QVariant (* const value[11])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[11])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlidePersistAtom*>(i)->rh);
    }
    static const Introspectable* get_persistIdRef(const Introspectable* i, int j) {
        return &(static_cast<const SlidePersistAtom*>(i)->persistIdRef);
    }
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->reserved1);
    }
    static QVariant get_fShouldCollapse(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->fShouldCollapse);
    }
    static QVariant get_fNonOutlineData(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->fNonOutlineData);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->reserved2);
    }
    static QVariant get_reserved3(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->reserved3);
    }
    static QVariant get_reserved4(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->reserved4);
    }
    static QVariant get_cTexts(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->cTexts);
    }
    static const Introspectable* get_slideId(const Introspectable* i, int j) {
        return &(static_cast<const SlidePersistAtom*>(i)->slideId);
    }
    static QVariant get_reserved5(const Introspectable* i, int j) {
        return (static_cast<const SlidePersistAtom*>(i)->reserved5);
    }
};
const QString SlidePersistAtom::_Introspection::name("SlidePersistAtom");
const int SlidePersistAtom::_Introspection::numberOfMembers(11);
const QString SlidePersistAtom::_Introspection::names[11] = {
    "rh",
    "persistIdRef",
    "reserved1",
    "fShouldCollapse",
    "fNonOutlineData",
    "reserved2",
    "reserved3",
    "reserved4",
    "cTexts",
    "slideId",
    "reserved5",
};
int (* const SlidePersistAtom::_Introspection::numberOfInstances[11])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const SlidePersistAtom::_Introspection::value[11])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_reserved1,
    _Introspection::get_fShouldCollapse,
    _Introspection::get_fNonOutlineData,
    _Introspection::get_reserved2,
    _Introspection::get_reserved3,
    _Introspection::get_reserved4,
    _Introspection::get_cTexts,
    Introspection::nullValue,
    _Introspection::get_reserved5,
};
const Introspectable* (* const SlidePersistAtom::_Introspection::introspectable[11])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_persistIdRef,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    _Introspection::get_slideId,
    Introspection::null,
};
const Introspection SlidePersistAtom::_introspection(
    "SlidePersistAtom", 11, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextRuler::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[28];
    static int (* const numberOfInstances[28])(const Introspectable*);
    static QVariant (* const value[28])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[28])(const Introspectable*, int position);
    static QVariant get_fDefaultTabSize(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fDefaultTabSize);
    }
    static QVariant get_fCLevels(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fCLevels);
    }
    static QVariant get_fTabStops(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fTabStops);
    }
    static QVariant get_fLeftMargin1(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fLeftMargin1);
    }
    static QVariant get_fLeftMargin2(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fLeftMargin2);
    }
    static QVariant get_fLeftMargin3(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fLeftMargin3);
    }
    static QVariant get_fLeftMargin4(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fLeftMargin4);
    }
    static QVariant get_fLeftMargin5(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fLeftMargin5);
    }
    static QVariant get_fIndent1(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fIndent1);
    }
    static QVariant get_fIndent2(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fIndent2);
    }
    static QVariant get_fIndent3(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fIndent3);
    }
    static QVariant get_fIndent4(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fIndent4);
    }
    static QVariant get_fIndent5(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->fIndent5);
    }
    static QVariant get_reserved1(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->reserved1);
    }
    static QVariant get_reserved2(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->reserved2);
    }
    static QVariant get_cLevels(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->cLevels);
    }
    static QVariant get_defaultTabSize(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->defaultTabSize);
    }
    static const Introspectable* get_tabs(const Introspectable* i, int j) {
        return &(static_cast<const TextRuler*>(i)->tabs);
    }
    static QVariant get_leftMargin1(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->leftMargin1);
    }
    static QVariant get_indent1(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->indent1);
    }
    static QVariant get_leftMargin2(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->leftMargin2);
    }
    static QVariant get_indent2(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->indent2);
    }
    static QVariant get_leftMargin3(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->leftMargin3);
    }
    static QVariant get_indent3(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->indent3);
    }
    static QVariant get_leftMargin4(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->leftMargin4);
    }
    static QVariant get_indent4(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->indent4);
    }
    static QVariant get_leftMargin5(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->leftMargin5);
    }
    static QVariant get_indent5(const Introspectable* i, int j) {
        return (static_cast<const TextRuler*>(i)->indent5);
    }
};
const QString TextRuler::_Introspection::name("TextRuler");
const int TextRuler::_Introspection::numberOfMembers(28);
const QString TextRuler::_Introspection::names[28] = {
    "fDefaultTabSize",
    "fCLevels",
    "fTabStops",
    "fLeftMargin1",
    "fLeftMargin2",
    "fLeftMargin3",
    "fLeftMargin4",
    "fLeftMargin5",
    "fIndent1",
    "fIndent2",
    "fIndent3",
    "fIndent4",
    "fIndent5",
    "reserved1",
    "reserved2",
    "cLevels",
    "defaultTabSize",
    "tabs",
    "leftMargin1",
    "indent1",
    "leftMargin2",
    "indent2",
    "leftMargin3",
    "indent3",
    "leftMargin4",
    "indent4",
    "leftMargin5",
    "indent5",
};
int (* const TextRuler::_Introspection::numberOfInstances[28])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextRuler::_Introspection::value[28])(const Introspectable*, int position) = {
    _Introspection::get_fDefaultTabSize,
    _Introspection::get_fCLevels,
    _Introspection::get_fTabStops,
    _Introspection::get_fLeftMargin1,
    _Introspection::get_fLeftMargin2,
    _Introspection::get_fLeftMargin3,
    _Introspection::get_fLeftMargin4,
    _Introspection::get_fLeftMargin5,
    _Introspection::get_fIndent1,
    _Introspection::get_fIndent2,
    _Introspection::get_fIndent3,
    _Introspection::get_fIndent4,
    _Introspection::get_fIndent5,
    _Introspection::get_reserved1,
    _Introspection::get_reserved2,
    _Introspection::get_cLevels,
    _Introspection::get_defaultTabSize,
    Introspection::nullValue,
    _Introspection::get_leftMargin1,
    _Introspection::get_indent1,
    _Introspection::get_leftMargin2,
    _Introspection::get_indent2,
    _Introspection::get_leftMargin3,
    _Introspection::get_indent3,
    _Introspection::get_leftMargin4,
    _Introspection::get_indent4,
    _Introspection::get_leftMargin5,
    _Introspection::get_indent5,
};
const Introspectable* (* const TextRuler::_Introspection::introspectable[28])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    _Introspection::get_tabs,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection TextRuler::_introspection(
    "TextRuler", 28, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextPFException::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[17];
    static int (* const numberOfInstances[17])(const Introspectable*);
    static QVariant (* const value[17])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[17])(const Introspectable*, int position);
    static const Introspectable* get_masks(const Introspectable* i, int j) {
        return &(static_cast<const TextPFException*>(i)->masks);
    }
    static const Introspectable* get_bulletFlags(const Introspectable* i, int j) {
        return &(static_cast<const TextPFException*>(i)->bulletFlags);
    }
    static QVariant get_bulletChar(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->bulletChar);
    }
    static QVariant get_bulletFontRef(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->bulletFontRef);
    }
    static QVariant get_bulletSize(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->bulletSize);
    }
    static QVariant get_bulletColor(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->bulletColor);
    }
    static QVariant get_textAlignment(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->textAlignment);
    }
    static QVariant get_lineSpacing(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->lineSpacing);
    }
    static QVariant get_spaceBefore(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->spaceBefore);
    }
    static QVariant get_spaceAfter(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->spaceAfter);
    }
    static QVariant get_leftMargin(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->leftMargin);
    }
    static QVariant get_indent(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->indent);
    }
    static QVariant get_defaultTabSize(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->defaultTabSize);
    }
    static const Introspectable* get_tabStops(const Introspectable* i, int j) {
        return &(static_cast<const TextPFException*>(i)->tabStops);
    }
    static QVariant get_fontAlign(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->fontAlign);
    }
    static QVariant get_wrapFlags(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->wrapFlags);
    }
    static QVariant get_textDirection(const Introspectable* i, int j) {
        return (static_cast<const TextPFException*>(i)->textDirection);
    }
};
const QString TextPFException::_Introspection::name("TextPFException");
const int TextPFException::_Introspection::numberOfMembers(17);
const QString TextPFException::_Introspection::names[17] = {
    "masks",
    "bulletFlags",
    "bulletChar",
    "bulletFontRef",
    "bulletSize",
    "bulletColor",
    "textAlignment",
    "lineSpacing",
    "spaceBefore",
    "spaceAfter",
    "leftMargin",
    "indent",
    "defaultTabSize",
    "tabStops",
    "fontAlign",
    "wrapFlags",
    "textDirection",
};
int (* const TextPFException::_Introspection::numberOfInstances[17])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextPFException::_Introspection::value[17])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_bulletChar,
    _Introspection::get_bulletFontRef,
    _Introspection::get_bulletSize,
    _Introspection::get_bulletColor,
    _Introspection::get_textAlignment,
    _Introspection::get_lineSpacing,
    _Introspection::get_spaceBefore,
    _Introspection::get_spaceAfter,
    _Introspection::get_leftMargin,
    _Introspection::get_indent,
    _Introspection::get_defaultTabSize,
    Introspection::nullValue,
    _Introspection::get_fontAlign,
    _Introspection::get_wrapFlags,
    _Introspection::get_textDirection,
};
const Introspectable* (* const TextPFException::_Introspection::introspectable[17])(const Introspectable*, int position) = {
    _Introspection::get_masks,
    _Introspection::get_bulletFlags,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    _Introspection::get_tabStops,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection TextPFException::_introspection(
    "TextPFException", 17, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextCFException::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[9];
    static int (* const numberOfInstances[9])(const Introspectable*);
    static QVariant (* const value[9])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[9])(const Introspectable*, int position);
    static const Introspectable* get_masks(const Introspectable* i, int j) {
        return &(static_cast<const TextCFException*>(i)->masks);
    }
    static const Introspectable* get_fontStyle(const Introspectable* i, int j) {
        return &(static_cast<const TextCFException*>(i)->fontStyle);
    }
    static QVariant get_fontRef(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->fontRef);
    }
    static QVariant get_oldEAFontRef(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->oldEAFontRef);
    }
    static QVariant get_ansiFontRef(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->ansiFontRef);
    }
    static QVariant get_symbolFontRef(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->symbolFontRef);
    }
    static QVariant get_fontSize(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->fontSize);
    }
    static QVariant get_color(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->color);
    }
    static QVariant get_position(const Introspectable* i, int j) {
        return (static_cast<const TextCFException*>(i)->position);
    }
};
const QString TextCFException::_Introspection::name("TextCFException");
const int TextCFException::_Introspection::numberOfMembers(9);
const QString TextCFException::_Introspection::names[9] = {
    "masks",
    "fontStyle",
    "fontRef",
    "oldEAFontRef",
    "ansiFontRef",
    "symbolFontRef",
    "fontSize",
    "color",
    "position",
};
int (* const TextCFException::_Introspection::numberOfInstances[9])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextCFException::_Introspection::value[9])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_fontRef,
    _Introspection::get_oldEAFontRef,
    _Introspection::get_ansiFontRef,
    _Introspection::get_symbolFontRef,
    _Introspection::get_fontSize,
    _Introspection::get_color,
    _Introspection::get_position,
};
const Introspectable* (* const TextCFException::_Introspection::introspectable[9])(const Introspectable*, int position) = {
    _Introspection::get_masks,
    _Introspection::get_fontStyle,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection TextCFException::_introspection(
    "TextCFException", 9, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class KinsokuContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const KinsokuContainer*>(i)->rh);
    }
    static const Introspectable* get_kinsokuAtom(const Introspectable* i, int j) {
        return &(static_cast<const KinsokuContainer*>(i)->kinsokuAtom);
    }
};
const QString KinsokuContainer::_Introspection::name("KinsokuContainer");
const int KinsokuContainer::_Introspection::numberOfMembers(2);
const QString KinsokuContainer::_Introspection::names[2] = {
    "rh",
    "kinsokuAtom",
};
int (* const KinsokuContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const KinsokuContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const KinsokuContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_kinsokuAtom,
};
const Introspection KinsokuContainer::_introspection(
    "KinsokuContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextMasterStyleLevel::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_pf(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleLevel*>(i)->pf);
    }
    static const Introspectable* get_cf(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleLevel*>(i)->cf);
    }
};
const QString TextMasterStyleLevel::_Introspection::name("TextMasterStyleLevel");
const int TextMasterStyleLevel::_Introspection::numberOfMembers(2);
const QString TextMasterStyleLevel::_Introspection::names[2] = {
    "pf",
    "cf",
};
int (* const TextMasterStyleLevel::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextMasterStyleLevel::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const TextMasterStyleLevel::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_pf,
    _Introspection::get_cf,
};
const Introspection TextMasterStyleLevel::_introspection(
    "TextMasterStyleLevel", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DocumentAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[12];
    static int (* const numberOfInstances[12])(const Introspectable*);
    static QVariant (* const value[12])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[12])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DocumentAtom*>(i)->rh);
    }
    static const Introspectable* get_slideSize(const Introspectable* i, int j) {
        return &(static_cast<const DocumentAtom*>(i)->slideSize);
    }
    static const Introspectable* get_notesSize(const Introspectable* i, int j) {
        return &(static_cast<const DocumentAtom*>(i)->notesSize);
    }
    static const Introspectable* get_serverZoom(const Introspectable* i, int j) {
        return &(static_cast<const DocumentAtom*>(i)->serverZoom);
    }
    static const Introspectable* get_notesMasterPersistIdRef(const Introspectable* i, int j) {
        return &(static_cast<const DocumentAtom*>(i)->notesMasterPersistIdRef);
    }
    static const Introspectable* get_handoutMasterPersistIdRef(const Introspectable* i, int j) {
        return &(static_cast<const DocumentAtom*>(i)->handoutMasterPersistIdRef);
    }
    static QVariant get_firstSlideNumber(const Introspectable* i, int j) {
        return (static_cast<const DocumentAtom*>(i)->firstSlideNumber);
    }
    static QVariant get_slideSizeType(const Introspectable* i, int j) {
        return (static_cast<const DocumentAtom*>(i)->slideSizeType);
    }
    static QVariant get_fSaveWithFonts(const Introspectable* i, int j) {
        return (static_cast<const DocumentAtom*>(i)->fSaveWithFonts);
    }
    static QVariant get_fOmitTitlePlace(const Introspectable* i, int j) {
        return (static_cast<const DocumentAtom*>(i)->fOmitTitlePlace);
    }
    static QVariant get_fRightToLeft(const Introspectable* i, int j) {
        return (static_cast<const DocumentAtom*>(i)->fRightToLeft);
    }
    static QVariant get_fShowComments(const Introspectable* i, int j) {
        return (static_cast<const DocumentAtom*>(i)->fShowComments);
    }
};
const QString DocumentAtom::_Introspection::name("DocumentAtom");
const int DocumentAtom::_Introspection::numberOfMembers(12);
const QString DocumentAtom::_Introspection::names[12] = {
    "rh",
    "slideSize",
    "notesSize",
    "serverZoom",
    "notesMasterPersistIdRef",
    "handoutMasterPersistIdRef",
    "firstSlideNumber",
    "slideSizeType",
    "fSaveWithFonts",
    "fOmitTitlePlace",
    "fRightToLeft",
    "fShowComments",
};
int (* const DocumentAtom::_Introspection::numberOfInstances[12])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const DocumentAtom::_Introspection::value[12])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_firstSlideNumber,
    _Introspection::get_slideSizeType,
    _Introspection::get_fSaveWithFonts,
    _Introspection::get_fOmitTitlePlace,
    _Introspection::get_fRightToLeft,
    _Introspection::get_fShowComments,
};
const Introspectable* (* const DocumentAtom::_Introspection::introspectable[12])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_slideSize,
    _Introspection::get_notesSize,
    _Introspection::get_serverZoom,
    _Introspection::get_notesMasterPersistIdRef,
    _Introspection::get_handoutMasterPersistIdRef,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection DocumentAtom::_introspection(
    "DocumentAtom", 12, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExObjListContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExObjListContainer*>(i)->rh);
    }
    static const Introspectable* get_exObjListAtom(const Introspectable* i, int j) {
        return &(static_cast<const ExObjListContainer*>(i)->exObjListAtom);
    }
    static int count_rgChildRec(const Introspectable* i) {
        return static_cast<const ExObjListContainer*>(i)->rgChildRec.size();
    }
    static const Introspectable* get_rgChildRec(const Introspectable* i, int j) {
        return &(static_cast<const ExObjListContainer*>(i)->rgChildRec[j]);
    }
};
const QString ExObjListContainer::_Introspection::name("ExObjListContainer");
const int ExObjListContainer::_Introspection::numberOfMembers(3);
const QString ExObjListContainer::_Introspection::names[3] = {
    "rh",
    "exObjListAtom",
    "rgChildRec",
};
int (* const ExObjListContainer::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_rgChildRec,
};
QVariant (* const ExObjListContainer::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const ExObjListContainer::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_exObjListAtom,
    _Introspection::get_rgChildRec,
};
const Introspection ExObjListContainer::_introspection(
    "ExObjListContainer", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExOleLinkContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExOleLinkContainer*>(i)->rh);
    }
    static const Introspectable* get_exOleLinkAtom(const Introspectable* i, int j) {
        return &(static_cast<const ExOleLinkContainer*>(i)->exOleLinkAtom);
    }
    static const Introspectable* get_exOleObjAtom(const Introspectable* i, int j) {
        return &(static_cast<const ExOleLinkContainer*>(i)->exOleObjAtom);
    }
    static int count_menuNameAtom(const Introspectable* i) {
        return static_cast<const ExOleLinkContainer*>(i)->menuNameAtom ?1 :0;
    }
    static const Introspectable* get_menuNameAtom(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkContainer*>(i)->menuNameAtom.data());
    }
    static int count_progIdAtom(const Introspectable* i) {
        return static_cast<const ExOleLinkContainer*>(i)->progIdAtom ?1 :0;
    }
    static const Introspectable* get_progIdAtom(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkContainer*>(i)->progIdAtom.data());
    }
    static int count_clipboardNameAtom(const Introspectable* i) {
        return static_cast<const ExOleLinkContainer*>(i)->clipboardNameAtom ?1 :0;
    }
    static const Introspectable* get_clipboardNameAtom(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkContainer*>(i)->clipboardNameAtom.data());
    }
    static int count_metafile(const Introspectable* i) {
        return static_cast<const ExOleLinkContainer*>(i)->metafile ?1 :0;
    }
    static const Introspectable* get_metafile(const Introspectable* i, int j) {
        return (static_cast<const ExOleLinkContainer*>(i)->metafile.data());
    }
};
const QString ExOleLinkContainer::_Introspection::name("ExOleLinkContainer");
const int ExOleLinkContainer::_Introspection::numberOfMembers(7);
const QString ExOleLinkContainer::_Introspection::names[7] = {
    "rh",
    "exOleLinkAtom",
    "exOleObjAtom",
    "menuNameAtom",
    "progIdAtom",
    "clipboardNameAtom",
    "metafile",
};
int (* const ExOleLinkContainer::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    _Introspection::count_menuNameAtom,
    _Introspection::count_progIdAtom,
    _Introspection::count_clipboardNameAtom,
    _Introspection::count_metafile,
};
QVariant (* const ExOleLinkContainer::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const ExOleLinkContainer::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_exOleLinkAtom,
    _Introspection::get_exOleObjAtom,
    _Introspection::get_menuNameAtom,
    _Introspection::get_progIdAtom,
    _Introspection::get_clipboardNameAtom,
    _Introspection::get_metafile,
};
const Introspection ExOleLinkContainer::_introspection(
    "ExOleLinkContainer", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExOleEmbedContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const ExOleEmbedContainer*>(i)->rh);
    }
    static const Introspectable* get_exOleEmbedAtom(const Introspectable* i, int j) {
        return &(static_cast<const ExOleEmbedContainer*>(i)->exOleEmbedAtom);
    }
    static const Introspectable* get_exOleObjAtom(const Introspectable* i, int j) {
        return &(static_cast<const ExOleEmbedContainer*>(i)->exOleObjAtom);
    }
    static int count_menuNameAtom(const Introspectable* i) {
        return static_cast<const ExOleEmbedContainer*>(i)->menuNameAtom ?1 :0;
    }
    static const Introspectable* get_menuNameAtom(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedContainer*>(i)->menuNameAtom.data());
    }
    static int count_progIdAtom(const Introspectable* i) {
        return static_cast<const ExOleEmbedContainer*>(i)->progIdAtom ?1 :0;
    }
    static const Introspectable* get_progIdAtom(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedContainer*>(i)->progIdAtom.data());
    }
    static int count_clipboardNameAtom(const Introspectable* i) {
        return static_cast<const ExOleEmbedContainer*>(i)->clipboardNameAtom ?1 :0;
    }
    static const Introspectable* get_clipboardNameAtom(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedContainer*>(i)->clipboardNameAtom.data());
    }
    static int count_metafile(const Introspectable* i) {
        return static_cast<const ExOleEmbedContainer*>(i)->metafile ?1 :0;
    }
    static const Introspectable* get_metafile(const Introspectable* i, int j) {
        return (static_cast<const ExOleEmbedContainer*>(i)->metafile.data());
    }
};
const QString ExOleEmbedContainer::_Introspection::name("ExOleEmbedContainer");
const int ExOleEmbedContainer::_Introspection::numberOfMembers(7);
const QString ExOleEmbedContainer::_Introspection::names[7] = {
    "rh",
    "exOleEmbedAtom",
    "exOleObjAtom",
    "menuNameAtom",
    "progIdAtom",
    "clipboardNameAtom",
    "metafile",
};
int (* const ExOleEmbedContainer::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    _Introspection::count_menuNameAtom,
    _Introspection::count_progIdAtom,
    _Introspection::count_clipboardNameAtom,
    _Introspection::count_metafile,
};
QVariant (* const ExOleEmbedContainer::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const ExOleEmbedContainer::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_exOleEmbedAtom,
    _Introspection::get_exOleObjAtom,
    _Introspection::get_menuNameAtom,
    _Introspection::get_progIdAtom,
    _Introspection::get_clipboardNameAtom,
    _Introspection::get_metafile,
};
const Introspection ExOleEmbedContainer::_introspection(
    "ExOleEmbedContainer", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFDGGBlock::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFDGGBlock*>(i)->rh);
    }
    static const Introspectable* get_head(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFDGGBlock*>(i)->head);
    }
    static int count_Rgidcl(const Introspectable* i) {
        return static_cast<const OfficeArtFDGGBlock*>(i)->Rgidcl.size();
    }
    static const Introspectable* get_Rgidcl(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFDGGBlock*>(i)->Rgidcl[j]);
    }
};
const QString OfficeArtFDGGBlock::_Introspection::name("OfficeArtFDGGBlock");
const int OfficeArtFDGGBlock::_Introspection::numberOfMembers(3);
const QString OfficeArtFDGGBlock::_Introspection::names[3] = {
    "rh",
    "head",
    "Rgidcl",
};
int (* const OfficeArtFDGGBlock::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_Rgidcl,
};
QVariant (* const OfficeArtFDGGBlock::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtFDGGBlock::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_head,
    _Introspection::get_Rgidcl,
};
const Introspection OfficeArtFDGGBlock::_introspection(
    "OfficeArtFDGGBlock", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtClientAnchor::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientAnchor*>(i)->rh);
    }
    static const Introspectable* get_rect1(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientAnchor*>(i)->rect1);
    }
    static const Introspectable* get_rect2(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientAnchor*>(i)->rect2);
    }
};
const QString OfficeArtClientAnchor::_Introspection::name("OfficeArtClientAnchor");
const int OfficeArtClientAnchor::_Introspection::numberOfMembers(3);
const QString OfficeArtClientAnchor::_Introspection::names[3] = {
    "rh",
    "rect1",
    "rect2",
};
int (* const OfficeArtClientAnchor::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtClientAnchor::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtClientAnchor::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_rect1,
    _Introspection::get_rect2,
};
const Introspection OfficeArtClientAnchor::_introspection(
    "OfficeArtClientAnchor", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtClientData::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[10];
    static int (* const numberOfInstances[10])(const Introspectable*);
    static QVariant (* const value[10])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[10])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientData*>(i)->rh);
    }
    static int count_shapeFlagsAtom(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->shapeFlagsAtom ?1 :0;
    }
    static const Introspectable* get_shapeFlagsAtom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->shapeFlagsAtom.data());
    }
    static int count_shapeFlags10Atom(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->shapeFlags10Atom ?1 :0;
    }
    static const Introspectable* get_shapeFlags10Atom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->shapeFlags10Atom.data());
    }
    static int count_exObjRefAtom(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->exObjRefAtom ?1 :0;
    }
    static const Introspectable* get_exObjRefAtom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->exObjRefAtom.data());
    }
    static int count_animationInfo(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->animationInfo ?1 :0;
    }
    static const Introspectable* get_animationInfo(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->animationInfo.data());
    }
    static int count_mouseClickInteractiveInfo(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->mouseClickInteractiveInfo ?1 :0;
    }
    static const Introspectable* get_mouseClickInteractiveInfo(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->mouseClickInteractiveInfo.data());
    }
    static int count_mouseOverInteractiveInfo(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->mouseOverInteractiveInfo ?1 :0;
    }
    static const Introspectable* get_mouseOverInteractiveInfo(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->mouseOverInteractiveInfo.data());
    }
    static int count_placeholderAtom(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->placeholderAtom ?1 :0;
    }
    static const Introspectable* get_placeholderAtom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->placeholderAtom.data());
    }
    static int count_recolorInfoAtom(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->recolorInfoAtom ?1 :0;
    }
    static const Introspectable* get_recolorInfoAtom(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtClientData*>(i)->recolorInfoAtom.data());
    }
    static int count_rgShapeClientRoundtripData(const Introspectable* i) {
        return static_cast<const OfficeArtClientData*>(i)->rgShapeClientRoundtripData.size();
    }
    static const Introspectable* get_rgShapeClientRoundtripData(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtClientData*>(i)->rgShapeClientRoundtripData[j]);
    }
};
const QString OfficeArtClientData::_Introspection::name("OfficeArtClientData");
const int OfficeArtClientData::_Introspection::numberOfMembers(10);
const QString OfficeArtClientData::_Introspection::names[10] = {
    "rh",
    "shapeFlagsAtom",
    "shapeFlags10Atom",
    "exObjRefAtom",
    "animationInfo",
    "mouseClickInteractiveInfo",
    "mouseOverInteractiveInfo",
    "placeholderAtom",
    "recolorInfoAtom",
    "rgShapeClientRoundtripData",
};
int (* const OfficeArtClientData::_Introspection::numberOfInstances[10])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_shapeFlagsAtom,
    _Introspection::count_shapeFlags10Atom,
    _Introspection::count_exObjRefAtom,
    _Introspection::count_animationInfo,
    _Introspection::count_mouseClickInteractiveInfo,
    _Introspection::count_mouseOverInteractiveInfo,
    _Introspection::count_placeholderAtom,
    _Introspection::count_recolorInfoAtom,
    _Introspection::count_rgShapeClientRoundtripData,
};
QVariant (* const OfficeArtClientData::_Introspection::value[10])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtClientData::_Introspection::introspectable[10])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_shapeFlagsAtom,
    _Introspection::get_shapeFlags10Atom,
    _Introspection::get_exObjRefAtom,
    _Introspection::get_animationInfo,
    _Introspection::get_mouseClickInteractiveInfo,
    _Introspection::get_mouseOverInteractiveInfo,
    _Introspection::get_placeholderAtom,
    _Introspection::get_recolorInfoAtom,
    _Introspection::get_rgShapeClientRoundtripData,
};
const Introspection OfficeArtClientData::_introspection(
    "OfficeArtClientData", 10, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFOPTE::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_opid(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFOPTE*>(i)->opid);
    }
    static QVariant get_op(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFOPTE*>(i)->op);
    }
    static QVariant get_complexData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFOPTE*>(i)->complexData);
    }
};
const QString OfficeArtFOPTE::_Introspection::name("OfficeArtFOPTE");
const int OfficeArtFOPTE::_Introspection::numberOfMembers(3);
const QString OfficeArtFOPTE::_Introspection::names[3] = {
    "opid",
    "op",
    "complexData",
};
int (* const OfficeArtFOPTE::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFOPTE::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_op,
    _Introspection::get_complexData,
};
const Introspectable* (* const OfficeArtFOPTE::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_opid,
    Introspection::null,
    Introspection::null,
};
const Introspection OfficeArtFOPTE::_introspection(
    "OfficeArtFOPTE", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Fib::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[12];
    static int (* const numberOfInstances[12])(const Introspectable*);
    static QVariant (* const value[12])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[12])(const Introspectable*, int position);
    static const Introspectable* get_base(const Introspectable* i, int j) {
        return &(static_cast<const Fib*>(i)->base);
    }
    static QVariant get_csw(const Introspectable* i, int j) {
        return (static_cast<const Fib*>(i)->csw);
    }
    static const Introspectable* get_fibRgW(const Introspectable* i, int j) {
        return &(static_cast<const Fib*>(i)->fibRgW);
    }
    static QVariant get_cslw(const Introspectable* i, int j) {
        return (static_cast<const Fib*>(i)->cslw);
    }
    static const Introspectable* get_fibRgLw(const Introspectable* i, int j) {
        return &(static_cast<const Fib*>(i)->fibRgLw);
    }
    static QVariant get_cbRgFcLcb(const Introspectable* i, int j) {
        return (static_cast<const Fib*>(i)->cbRgFcLcb);
    }
    static const Introspectable* get_fibRgFcLcbBlob(const Introspectable* i, int j) {
        return &(static_cast<const Fib*>(i)->fibRgFcLcbBlob);
    }
    static const Introspectable* get_fibRgFcLcbBlob2(const Introspectable* i, int j) {
        return &(static_cast<const Fib*>(i)->fibRgFcLcbBlob2);
    }
    static const Introspectable* get_fibRgFcLcbBlob3(const Introspectable* i, int j) {
        return &(static_cast<const Fib*>(i)->fibRgFcLcbBlob3);
    }
    static QVariant get_cswNew(const Introspectable* i, int j) {
        return (static_cast<const Fib*>(i)->cswNew);
    }
    static QVariant get_fibRgCswNew(const Introspectable* i, int j) {
        return (static_cast<const Fib*>(i)->fibRgCswNew);
    }
    static QVariant get_trail(const Introspectable* i, int j) {
        return (static_cast<const Fib*>(i)->trail);
    }
};
const QString Fib::_Introspection::name("Fib");
const int Fib::_Introspection::numberOfMembers(12);
const QString Fib::_Introspection::names[12] = {
    "base",
    "csw",
    "fibRgW",
    "cslw",
    "fibRgLw",
    "cbRgFcLcb",
    "fibRgFcLcbBlob",
    "fibRgFcLcbBlob2",
    "fibRgFcLcbBlob3",
    "cswNew",
    "fibRgCswNew",
    "trail",
};
int (* const Fib::_Introspection::numberOfInstances[12])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const Fib::_Introspection::value[12])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_csw,
    Introspection::nullValue,
    _Introspection::get_cslw,
    Introspection::nullValue,
    _Introspection::get_cbRgFcLcb,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_cswNew,
    _Introspection::get_fibRgCswNew,
    _Introspection::get_trail,
};
const Introspectable* (* const Fib::_Introspection::introspectable[12])(const Introspectable*, int position) = {
    _Introspection::get_base,
    Introspection::null,
    _Introspection::get_fibRgW,
    Introspection::null,
    _Introspection::get_fibRgLw,
    Introspection::null,
    _Introspection::get_fibRgFcLcbBlob,
    _Introspection::get_fibRgFcLcbBlob2,
    _Introspection::get_fibRgFcLcbBlob3,
    Introspection::null,
    Introspection::null,
    Introspection::null,
};
const Introspection Fib::_introspection(
    "Fib", 12, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class STSH::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_lpstshi(const Introspectable* i, int j) {
        return &(static_cast<const STSH*>(i)->lpstshi);
    }
    static int count_rglpstd(const Introspectable* i) {
        return static_cast<const STSH*>(i)->rglpstd.size();
    }
    static const Introspectable* get_rglpstd(const Introspectable* i, int j) {
        return &(static_cast<const STSH*>(i)->rglpstd[j]);
    }
};
const QString STSH::_Introspection::name("STSH");
const int STSH::_Introspection::numberOfMembers(2);
const QString STSH::_Introspection::names[2] = {
    "lpstshi",
    "rglpstd",
};
int (* const STSH::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_rglpstd,
};
QVariant (* const STSH::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const STSH::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_lpstshi,
    _Introspection::get_rglpstd,
};
const Introspection STSH::_introspection(
    "STSH", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Clx::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static int count_RgPrc(const Introspectable* i) {
        return static_cast<const Clx*>(i)->RgPrc.size();
    }
    static const Introspectable* get_RgPrc(const Introspectable* i, int j) {
        return &(static_cast<const Clx*>(i)->RgPrc[j]);
    }
    static const Introspectable* get_pcdt(const Introspectable* i, int j) {
        return &(static_cast<const Clx*>(i)->pcdt);
    }
};
const QString Clx::_Introspection::name("Clx");
const int Clx::_Introspection::numberOfMembers(2);
const QString Clx::_Introspection::names[2] = {
    "RgPrc",
    "pcdt",
};
int (* const Clx::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    _Introspection::count_RgPrc,
    Introspection::one,
};
QVariant (* const Clx::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const Clx::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_RgPrc,
    _Introspection::get_pcdt,
};
const Introspection Clx::_introspection(
    "Clx", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Pcr::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static QVariant get_clxt(const Introspectable* i, int j) {
        return (static_cast<const Pcr*>(i)->clxt);
    }
    static const Introspectable* get_prcData(const Introspectable* i, int j) {
        return &(static_cast<const Pcr*>(i)->prcData);
    }
};
const QString Pcr::_Introspection::name("Pcr");
const int Pcr::_Introspection::numberOfMembers(2);
const QString Pcr::_Introspection::names[2] = {
    "clxt",
    "prcData",
};
int (* const Pcr::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const Pcr::_Introspection::value[2])(const Introspectable*, int position) = {
    _Introspection::get_clxt,
    Introspection::nullValue,
};
const Introspectable* (* const Pcr::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    Introspection::null,
    _Introspection::get_prcData,
};
const Introspection Pcr::_introspection(
    "Pcr", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Prm::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_prm(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const Prm*>(i)->prm.prm0.data();
        if (k == 0) k = static_cast<const Prm*>(i)->prm.prm1.data();
        return k;
    }
};
const QString Prm::_Introspection::name("Prm");
const int Prm::_Introspection::numberOfMembers(1);
const QString Prm::_Introspection::names[1] = {
    "prm",
};
int (* const Prm::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const Prm::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const Prm::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_prm,
};
const Introspection Prm::_introspection(
    "Prm", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipEMF::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipEMF*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipEMF*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipEMF*>(i)->rgbUid2);
    }
    static const Introspectable* get_metafileHeader(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipEMF*>(i)->metafileHeader);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipEMF*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipEMF::_Introspection::name("OfficeArtBlipEMF");
const int OfficeArtBlipEMF::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipEMF::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "metafileHeader",
    "BLIPFileData",
};
int (* const OfficeArtBlipEMF::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipEMF::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    Introspection::nullValue,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipEMF::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    _Introspection::get_metafileHeader,
    Introspection::null,
};
const Introspection OfficeArtBlipEMF::_introspection(
    "OfficeArtBlipEMF", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipWMF::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipWMF*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipWMF*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipWMF*>(i)->rgbUid2);
    }
    static const Introspectable* get_metafileHeader(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipWMF*>(i)->metafileHeader);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipWMF*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipWMF::_Introspection::name("OfficeArtBlipWMF");
const int OfficeArtBlipWMF::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipWMF::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "metafileHeader",
    "BLIPFileData",
};
int (* const OfficeArtBlipWMF::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipWMF::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    Introspection::nullValue,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipWMF::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    _Introspection::get_metafileHeader,
    Introspection::null,
};
const Introspection OfficeArtBlipWMF::_introspection(
    "OfficeArtBlipWMF", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlipPICT::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[5];
    static int (* const numberOfInstances[5])(const Introspectable*);
    static QVariant (* const value[5])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[5])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipPICT*>(i)->rh);
    }
    static QVariant get_rgbUid1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPICT*>(i)->rgbUid1);
    }
    static QVariant get_rgbUid2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPICT*>(i)->rgbUid2);
    }
    static const Introspectable* get_metafileHeader(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtBlipPICT*>(i)->metafileHeader);
    }
    static QVariant get_BLIPFileData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtBlipPICT*>(i)->BLIPFileData);
    }
};
const QString OfficeArtBlipPICT::_Introspection::name("OfficeArtBlipPICT");
const int OfficeArtBlipPICT::_Introspection::numberOfMembers(5);
const QString OfficeArtBlipPICT::_Introspection::names[5] = {
    "rh",
    "rgbUid1",
    "rgbUid2",
    "metafileHeader",
    "BLIPFileData",
};
int (* const OfficeArtBlipPICT::_Introspection::numberOfInstances[5])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtBlipPICT::_Introspection::value[5])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_rgbUid1,
    _Introspection::get_rgbUid2,
    Introspection::nullValue,
    _Introspection::get_BLIPFileData,
};
const Introspectable* (* const OfficeArtBlipPICT::_Introspection::introspectable[5])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    _Introspection::get_metafileHeader,
    Introspection::null,
};
const Introspection OfficeArtBlipPICT::_introspection(
    "OfficeArtBlipPICT", 5, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBlip::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartblipemf.data();
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartblipwmf.data();
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartblippict.data();
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartblipjpeg.data();
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartblippng.data();
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartblipdib.data();
        if (k == 0) k = static_cast<const OfficeArtBlip*>(i)->anon.officeartbliptiff.data();
        return k;
    }
};
const QString OfficeArtBlip::_Introspection::name("OfficeArtBlip");
const int OfficeArtBlip::_Introspection::numberOfMembers(1);
const QString OfficeArtBlip::_Introspection::names[1] = {
    "anon",
};
int (* const OfficeArtBlip::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const OfficeArtBlip::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtBlip::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection OfficeArtBlip::_introspection(
    "OfficeArtBlip", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class NormalViewSetInfoContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const NormalViewSetInfoContainer*>(i)->rh);
    }
    static const Introspectable* get_normalViewSetInfoAtom(const Introspectable* i, int j) {
        return &(static_cast<const NormalViewSetInfoContainer*>(i)->normalViewSetInfoAtom);
    }
};
const QString NormalViewSetInfoContainer::_Introspection::name("NormalViewSetInfoContainer");
const int NormalViewSetInfoContainer::_Introspection::numberOfMembers(2);
const QString NormalViewSetInfoContainer::_Introspection::names[2] = {
    "rh",
    "normalViewSetInfoAtom",
};
int (* const NormalViewSetInfoContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const NormalViewSetInfoContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const NormalViewSetInfoContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_normalViewSetInfoAtom,
};
const Introspection NormalViewSetInfoContainer::_introspection(
    "NormalViewSetInfoContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideListWithTextSubContainerOrAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.slidepersistatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.textheaderatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.textcharsatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.textbytesatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.styletextpropatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.slidenumbermcatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.datetimemcatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.genericdatemcatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.headermcatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.footermcatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.rtfdatetimemcatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.textbookmarkatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.textspecialinfoatom.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.interactiveinfoinstance.data();
        if (k == 0) k = static_cast<const SlideListWithTextSubContainerOrAtom*>(i)->anon.textinteractiveinfoinstance.data();
        return k;
    }
};
const QString SlideListWithTextSubContainerOrAtom::_Introspection::name("SlideListWithTextSubContainerOrAtom");
const int SlideListWithTextSubContainerOrAtom::_Introspection::numberOfMembers(1);
const QString SlideListWithTextSubContainerOrAtom::_Introspection::names[1] = {
    "anon",
};
int (* const SlideListWithTextSubContainerOrAtom::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const SlideListWithTextSubContainerOrAtom::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const SlideListWithTextSubContainerOrAtom::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection SlideListWithTextSubContainerOrAtom::_introspection(
    "SlideListWithTextSubContainerOrAtom", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextCFExceptionAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextCFExceptionAtom*>(i)->rh);
    }
    static const Introspectable* get_cf(const Introspectable* i, int j) {
        return &(static_cast<const TextCFExceptionAtom*>(i)->cf);
    }
};
const QString TextCFExceptionAtom::_Introspection::name("TextCFExceptionAtom");
const int TextCFExceptionAtom::_Introspection::numberOfMembers(2);
const QString TextCFExceptionAtom::_Introspection::names[2] = {
    "rh",
    "cf",
};
int (* const TextCFExceptionAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextCFExceptionAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const TextCFExceptionAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_cf,
};
const Introspection TextCFExceptionAtom::_introspection(
    "TextCFExceptionAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DefaultRulerAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DefaultRulerAtom*>(i)->rh);
    }
    static const Introspectable* get_defaultTextRuler(const Introspectable* i, int j) {
        return &(static_cast<const DefaultRulerAtom*>(i)->defaultTextRuler);
    }
};
const QString DefaultRulerAtom::_Introspection::name("DefaultRulerAtom");
const int DefaultRulerAtom::_Introspection::numberOfMembers(2);
const QString DefaultRulerAtom::_Introspection::names[2] = {
    "rh",
    "defaultTextRuler",
};
int (* const DefaultRulerAtom::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const DefaultRulerAtom::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const DefaultRulerAtom::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_defaultTextRuler,
};
const Introspection DefaultRulerAtom::_introspection(
    "DefaultRulerAtom", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextPFExceptionAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[3];
    static int (* const numberOfInstances[3])(const Introspectable*);
    static QVariant (* const value[3])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[3])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextPFExceptionAtom*>(i)->rh);
    }
    static QVariant get_reserved(const Introspectable* i, int j) {
        return (static_cast<const TextPFExceptionAtom*>(i)->reserved);
    }
    static const Introspectable* get_pf(const Introspectable* i, int j) {
        return &(static_cast<const TextPFExceptionAtom*>(i)->pf);
    }
};
const QString TextPFExceptionAtom::_Introspection::name("TextPFExceptionAtom");
const int TextPFExceptionAtom::_Introspection::numberOfMembers(3);
const QString TextPFExceptionAtom::_Introspection::names[3] = {
    "rh",
    "reserved",
    "pf",
};
int (* const TextPFExceptionAtom::_Introspection::numberOfInstances[3])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextPFExceptionAtom::_Introspection::value[3])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_reserved,
    Introspection::nullValue,
};
const Introspectable* (* const TextPFExceptionAtom::_Introspection::introspectable[3])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    _Introspection::get_pf,
};
const Introspection TextPFExceptionAtom::_introspection(
    "TextPFExceptionAtom", 3, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class TextMasterStyleAtom::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[12];
    static int (* const numberOfInstances[12])(const Introspectable*);
    static QVariant (* const value[12])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[12])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleAtom*>(i)->rh);
    }
    static QVariant get_cLevels(const Introspectable* i, int j) {
        return (static_cast<const TextMasterStyleAtom*>(i)->cLevels);
    }
    static QVariant get_lstLvl1level(const Introspectable* i, int j) {
        return (static_cast<const TextMasterStyleAtom*>(i)->lstLvl1level);
    }
    static const Introspectable* get_lstLvl1(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleAtom*>(i)->lstLvl1);
    }
    static QVariant get_lstLvl2level(const Introspectable* i, int j) {
        return (static_cast<const TextMasterStyleAtom*>(i)->lstLvl2level);
    }
    static const Introspectable* get_lstLvl2(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleAtom*>(i)->lstLvl2);
    }
    static QVariant get_lstLvl3level(const Introspectable* i, int j) {
        return (static_cast<const TextMasterStyleAtom*>(i)->lstLvl3level);
    }
    static const Introspectable* get_lstLvl3(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleAtom*>(i)->lstLvl3);
    }
    static QVariant get_lstLvl4level(const Introspectable* i, int j) {
        return (static_cast<const TextMasterStyleAtom*>(i)->lstLvl4level);
    }
    static const Introspectable* get_lstLvl4(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleAtom*>(i)->lstLvl4);
    }
    static QVariant get_lstLvl5level(const Introspectable* i, int j) {
        return (static_cast<const TextMasterStyleAtom*>(i)->lstLvl5level);
    }
    static const Introspectable* get_lstLvl5(const Introspectable* i, int j) {
        return &(static_cast<const TextMasterStyleAtom*>(i)->lstLvl5);
    }
};
const QString TextMasterStyleAtom::_Introspection::name("TextMasterStyleAtom");
const int TextMasterStyleAtom::_Introspection::numberOfMembers(12);
const QString TextMasterStyleAtom::_Introspection::names[12] = {
    "rh",
    "cLevels",
    "lstLvl1level",
    "lstLvl1",
    "lstLvl2level",
    "lstLvl2",
    "lstLvl3level",
    "lstLvl3",
    "lstLvl4level",
    "lstLvl4",
    "lstLvl5level",
    "lstLvl5",
};
int (* const TextMasterStyleAtom::_Introspection::numberOfInstances[12])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const TextMasterStyleAtom::_Introspection::value[12])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_cLevels,
    _Introspection::get_lstLvl1level,
    Introspection::nullValue,
    _Introspection::get_lstLvl2level,
    Introspection::nullValue,
    _Introspection::get_lstLvl3level,
    Introspection::nullValue,
    _Introspection::get_lstLvl4level,
    Introspection::nullValue,
    _Introspection::get_lstLvl5level,
    Introspection::nullValue,
};
const Introspectable* (* const TextMasterStyleAtom::_Introspection::introspectable[12])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    _Introspection::get_lstLvl1,
    Introspection::null,
    _Introspection::get_lstLvl2,
    Introspection::null,
    _Introspection::get_lstLvl3,
    Introspection::null,
    _Introspection::get_lstLvl4,
    Introspection::null,
    _Introspection::get_lstLvl5,
};
const Introspection TextMasterStyleAtom::_introspection(
    "TextMasterStyleAtom", 12, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class ExObjListSubContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const ExObjListSubContainer*>(i)->anon.exolelinkcontainer.data();
        if (k == 0) k = static_cast<const ExObjListSubContainer*>(i)->anon.exoleembedcontainer.data();
        return k;
    }
};
const QString ExObjListSubContainer::_Introspection::name("ExObjListSubContainer");
const int ExObjListSubContainer::_Introspection::numberOfMembers(1);
const QString ExObjListSubContainer::_Introspection::names[1] = {
    "anon",
};
int (* const ExObjListSubContainer::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const ExObjListSubContainer::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const ExObjListSubContainer::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection ExObjListSubContainer::_introspection(
    "ExObjListSubContainer", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtDggContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDggContainer*>(i)->rh);
    }
    static const Introspectable* get_drawingGroup(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDggContainer*>(i)->drawingGroup);
    }
    static int count_blipStore(const Introspectable* i) {
        return static_cast<const OfficeArtDggContainer*>(i)->blipStore ?1 :0;
    }
    static const Introspectable* get_blipStore(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtDggContainer*>(i)->blipStore.data());
    }
    static const Introspectable* get_drawingPrimaryOptions(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDggContainer*>(i)->drawingPrimaryOptions);
    }
    static int count_drawingTertiaryOptions(const Introspectable* i) {
        return static_cast<const OfficeArtDggContainer*>(i)->drawingTertiaryOptions ?1 :0;
    }
    static const Introspectable* get_drawingTertiaryOptions(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtDggContainer*>(i)->drawingTertiaryOptions.data());
    }
    static int count_colorMRU(const Introspectable* i) {
        return static_cast<const OfficeArtDggContainer*>(i)->colorMRU ?1 :0;
    }
    static const Introspectable* get_colorMRU(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtDggContainer*>(i)->colorMRU.data());
    }
    static const Introspectable* get_splitColors(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDggContainer*>(i)->splitColors);
    }
};
const QString OfficeArtDggContainer::_Introspection::name("OfficeArtDggContainer");
const int OfficeArtDggContainer::_Introspection::numberOfMembers(7);
const QString OfficeArtDggContainer::_Introspection::names[7] = {
    "rh",
    "drawingGroup",
    "blipStore",
    "drawingPrimaryOptions",
    "drawingTertiaryOptions",
    "colorMRU",
    "splitColors",
};
int (* const OfficeArtDggContainer::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_blipStore,
    Introspection::one,
    _Introspection::count_drawingTertiaryOptions,
    _Introspection::count_colorMRU,
    Introspection::one,
};
QVariant (* const OfficeArtDggContainer::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtDggContainer::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_drawingGroup,
    _Introspection::get_blipStore,
    _Introspection::get_drawingPrimaryOptions,
    _Introspection::get_drawingTertiaryOptions,
    _Introspection::get_colorMRU,
    _Introspection::get_splitColors,
};
const Introspection OfficeArtDggContainer::_introspection(
    "OfficeArtDggContainer", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtSpContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[11];
    static int (* const numberOfInstances[11])(const Introspectable*);
    static QVariant (* const value[11])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[11])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSpContainer*>(i)->rh);
    }
    static int count_shapeGroup(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->shapeGroup ?1 :0;
    }
    static const Introspectable* get_shapeGroup(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->shapeGroup.data());
    }
    static const Introspectable* get_shapeProp(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtSpContainer*>(i)->shapeProp);
    }
    static int count_deletedshape(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->deletedshape ?1 :0;
    }
    static const Introspectable* get_deletedshape(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->deletedshape.data());
    }
    static int count_shapePrimaryOptions(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->shapePrimaryOptions ?1 :0;
    }
    static const Introspectable* get_shapePrimaryOptions(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->shapePrimaryOptions.data());
    }
    static int count_shapeSecondaryOptions1(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->shapeSecondaryOptions1 ?1 :0;
    }
    static const Introspectable* get_shapeSecondaryOptions1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->shapeSecondaryOptions1.data());
    }
    static int count_shapeTertiaryOptions1(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->shapeTertiaryOptions1 ?1 :0;
    }
    static const Introspectable* get_shapeTertiaryOptions1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->shapeTertiaryOptions1.data());
    }
    static int count_childAnchor(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->childAnchor ?1 :0;
    }
    static const Introspectable* get_childAnchor(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->childAnchor.data());
    }
    static int count_clientAnchor(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->clientAnchor ?1 :0;
    }
    static const Introspectable* get_clientAnchor(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->clientAnchor.data());
    }
    static int count_clientData(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->clientData ?1 :0;
    }
    static const Introspectable* get_clientData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->clientData.data());
    }
    static int count_clientTextbox(const Introspectable* i) {
        return static_cast<const OfficeArtSpContainer*>(i)->clientTextbox ?1 :0;
    }
    static const Introspectable* get_clientTextbox(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtSpContainer*>(i)->clientTextbox.data());
    }
};
const QString OfficeArtSpContainer::_Introspection::name("OfficeArtSpContainer");
const int OfficeArtSpContainer::_Introspection::numberOfMembers(11);
const QString OfficeArtSpContainer::_Introspection::names[11] = {
    "rh",
    "shapeGroup",
    "shapeProp",
    "deletedshape",
    "shapePrimaryOptions",
    "shapeSecondaryOptions1",
    "shapeTertiaryOptions1",
    "childAnchor",
    "clientAnchor",
    "clientData",
    "clientTextbox",
};
int (* const OfficeArtSpContainer::_Introspection::numberOfInstances[11])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_shapeGroup,
    Introspection::one,
    _Introspection::count_deletedshape,
    _Introspection::count_shapePrimaryOptions,
    _Introspection::count_shapeSecondaryOptions1,
    _Introspection::count_shapeTertiaryOptions1,
    _Introspection::count_childAnchor,
    _Introspection::count_clientAnchor,
    _Introspection::count_clientData,
    _Introspection::count_clientTextbox,
};
QVariant (* const OfficeArtSpContainer::_Introspection::value[11])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtSpContainer::_Introspection::introspectable[11])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_shapeGroup,
    _Introspection::get_shapeProp,
    _Introspection::get_deletedshape,
    _Introspection::get_shapePrimaryOptions,
    _Introspection::get_shapeSecondaryOptions1,
    _Introspection::get_shapeTertiaryOptions1,
    _Introspection::get_childAnchor,
    _Introspection::get_clientAnchor,
    _Introspection::get_clientData,
    _Introspection::get_clientTextbox,
};
const Introspection OfficeArtSpContainer::_introspection(
    "OfficeArtSpContainer", 11, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class WordDocument::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_fib(const Introspectable* i, int j) {
        return &(static_cast<const WordDocument*>(i)->fib);
    }
};
const QString WordDocument::_Introspection::name("WordDocument");
const int WordDocument::_Introspection::numberOfMembers(1);
const QString WordDocument::_Introspection::names[1] = {
    "fib",
};
int (* const WordDocument::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const WordDocument::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const WordDocument::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_fib,
};
const Introspection WordDocument::_introspection(
    "WordDocument", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Table::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[9];
    static int (* const numberOfInstances[9])(const Introspectable*);
    static QVariant (* const value[9])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[9])(const Introspectable*, int position);
    static const Introspectable* get_stsh(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->stsh);
    }
    static const Introspectable* get_plcfSed(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->plcfSed);
    }
    static const Introspectable* get_plcfHdd(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->plcfHdd);
    }
    static const Introspectable* get_plcfBteChpx(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->plcfBteChpx);
    }
    static const Introspectable* get_plcfBtePapx(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->plcfBtePapx);
    }
    static const Introspectable* get_cmds(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->cmds);
    }
    static const Introspectable* get_clx(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->clx);
    }
    static const Introspectable* get_sttbfFfn(const Introspectable* i, int j) {
        return &(static_cast<const Table*>(i)->sttbfFfn);
    }
    static QVariant get_dop(const Introspectable* i, int j) {
        return (static_cast<const Table*>(i)->dop);
    }
};
const QString Table::_Introspection::name("Table");
const int Table::_Introspection::numberOfMembers(9);
const QString Table::_Introspection::names[9] = {
    "stsh",
    "plcfSed",
    "plcfHdd",
    "plcfBteChpx",
    "plcfBtePapx",
    "cmds",
    "clx",
    "sttbfFfn",
    "dop",
};
int (* const Table::_Introspection::numberOfInstances[9])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const Table::_Introspection::value[9])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    _Introspection::get_dop,
};
const Introspectable* (* const Table::_Introspection::introspectable[9])(const Introspectable*, int position) = {
    _Introspection::get_stsh,
    _Introspection::get_plcfSed,
    _Introspection::get_plcfHdd,
    _Introspection::get_plcfBteChpx,
    _Introspection::get_plcfBtePapx,
    _Introspection::get_cmds,
    _Introspection::get_clx,
    _Introspection::get_sttbfFfn,
    Introspection::null,
};
const Introspection Table::_introspection(
    "Table", 9, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class Pcd::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static QVariant get_fNoParaLast(const Introspectable* i, int j) {
        return (static_cast<const Pcd*>(i)->fNoParaLast);
    }
    static QVariant get_fR1(const Introspectable* i, int j) {
        return (static_cast<const Pcd*>(i)->fR1);
    }
    static QVariant get_fDirtly(const Introspectable* i, int j) {
        return (static_cast<const Pcd*>(i)->fDirtly);
    }
    static QVariant get_fR2(const Introspectable* i, int j) {
        return (static_cast<const Pcd*>(i)->fR2);
    }
    static QVariant get_fR3(const Introspectable* i, int j) {
        return (static_cast<const Pcd*>(i)->fR3);
    }
    static const Introspectable* get_fc(const Introspectable* i, int j) {
        return &(static_cast<const Pcd*>(i)->fc);
    }
    static const Introspectable* get_prm(const Introspectable* i, int j) {
        return &(static_cast<const Pcd*>(i)->prm);
    }
};
const QString Pcd::_Introspection::name("Pcd");
const int Pcd::_Introspection::numberOfMembers(7);
const QString Pcd::_Introspection::names[7] = {
    "fNoParaLast",
    "fR1",
    "fDirtly",
    "fR2",
    "fR3",
    "fc",
    "prm",
};
int (* const Pcd::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const Pcd::_Introspection::value[7])(const Introspectable*, int position) = {
    _Introspection::get_fNoParaLast,
    _Introspection::get_fR1,
    _Introspection::get_fDirtly,
    _Introspection::get_fR2,
    _Introspection::get_fR3,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const Pcd::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    _Introspection::get_fc,
    _Introspection::get_prm,
};
const Introspection Pcd::_introspection(
    "Pcd", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtFBSE::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[14];
    static int (* const numberOfInstances[14])(const Introspectable*);
    static QVariant (* const value[14])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[14])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFBSE*>(i)->rh);
    }
    static QVariant get_btWin32(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->btWin32);
    }
    static QVariant get_btMacOS(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->btMacOS);
    }
    static QVariant get_rgbUid(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->rgbUid);
    }
    static QVariant get_tag(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->tag);
    }
    static QVariant get_size(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->size);
    }
    static QVariant get_cRef(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->cRef);
    }
    static QVariant get_foDelay(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->foDelay);
    }
    static QVariant get_unused1(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->unused1);
    }
    static QVariant get_cbName(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->cbName);
    }
    static QVariant get_unused2(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->unused2);
    }
    static QVariant get_unused3(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->unused3);
    }
    static QVariant get_nameData(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtFBSE*>(i)->nameData);
    }
    static const Introspectable* get_embeddedBlip(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtFBSE*>(i)->embeddedBlip);
    }
};
const QString OfficeArtFBSE::_Introspection::name("OfficeArtFBSE");
const int OfficeArtFBSE::_Introspection::numberOfMembers(14);
const QString OfficeArtFBSE::_Introspection::names[14] = {
    "rh",
    "btWin32",
    "btMacOS",
    "rgbUid",
    "tag",
    "size",
    "cRef",
    "foDelay",
    "unused1",
    "cbName",
    "unused2",
    "unused3",
    "nameData",
    "embeddedBlip",
};
int (* const OfficeArtFBSE::_Introspection::numberOfInstances[14])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    Introspection::one,
};
QVariant (* const OfficeArtFBSE::_Introspection::value[14])(const Introspectable*, int position) = {
    Introspection::nullValue,
    _Introspection::get_btWin32,
    _Introspection::get_btMacOS,
    _Introspection::get_rgbUid,
    _Introspection::get_tag,
    _Introspection::get_size,
    _Introspection::get_cRef,
    _Introspection::get_foDelay,
    _Introspection::get_unused1,
    _Introspection::get_cbName,
    _Introspection::get_unused2,
    _Introspection::get_unused3,
    _Introspection::get_nameData,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtFBSE::_Introspection::introspectable[14])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    Introspection::null,
    _Introspection::get_embeddedBlip,
};
const Introspection OfficeArtFBSE::_introspection(
    "OfficeArtFBSE", 14, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtBStoreContainerFileBlock::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const OfficeArtBStoreContainerFileBlock*>(i)->anon.officeartfbse.data();
        if (k == 0) k = static_cast<const OfficeArtBStoreContainerFileBlock*>(i)->anon.officeartblip.data();
        return k;
    }
};
const QString OfficeArtBStoreContainerFileBlock::_Introspection::name("OfficeArtBStoreContainerFileBlock");
const int OfficeArtBStoreContainerFileBlock::_Introspection::numberOfMembers(1);
const QString OfficeArtBStoreContainerFileBlock::_Introspection::names[1] = {
    "anon",
};
int (* const OfficeArtBStoreContainerFileBlock::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const OfficeArtBStoreContainerFileBlock::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtBStoreContainerFileBlock::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection OfficeArtBStoreContainerFileBlock::_introspection(
    "OfficeArtBStoreContainerFileBlock", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DocumentTextInfoContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[8];
    static int (* const numberOfInstances[8])(const Introspectable*);
    static QVariant (* const value[8])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[8])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DocumentTextInfoContainer*>(i)->rh);
    }
    static int count_kinsoku(const Introspectable* i) {
        return static_cast<const DocumentTextInfoContainer*>(i)->kinsoku ?1 :0;
    }
    static const Introspectable* get_kinsoku(const Introspectable* i, int j) {
        return (static_cast<const DocumentTextInfoContainer*>(i)->kinsoku.data());
    }
    static int count_fontCollection(const Introspectable* i) {
        return static_cast<const DocumentTextInfoContainer*>(i)->fontCollection ?1 :0;
    }
    static const Introspectable* get_fontCollection(const Introspectable* i, int j) {
        return (static_cast<const DocumentTextInfoContainer*>(i)->fontCollection.data());
    }
    static int count_textCFDefaultsAtom(const Introspectable* i) {
        return static_cast<const DocumentTextInfoContainer*>(i)->textCFDefaultsAtom ?1 :0;
    }
    static const Introspectable* get_textCFDefaultsAtom(const Introspectable* i, int j) {
        return (static_cast<const DocumentTextInfoContainer*>(i)->textCFDefaultsAtom.data());
    }
    static int count_textPFDefaultsAtom(const Introspectable* i) {
        return static_cast<const DocumentTextInfoContainer*>(i)->textPFDefaultsAtom ?1 :0;
    }
    static const Introspectable* get_textPFDefaultsAtom(const Introspectable* i, int j) {
        return (static_cast<const DocumentTextInfoContainer*>(i)->textPFDefaultsAtom.data());
    }
    static int count_defaultRulerAtom(const Introspectable* i) {
        return static_cast<const DocumentTextInfoContainer*>(i)->defaultRulerAtom ?1 :0;
    }
    static const Introspectable* get_defaultRulerAtom(const Introspectable* i, int j) {
        return (static_cast<const DocumentTextInfoContainer*>(i)->defaultRulerAtom.data());
    }
    static const Introspectable* get_textSIDefaultsAtom(const Introspectable* i, int j) {
        return &(static_cast<const DocumentTextInfoContainer*>(i)->textSIDefaultsAtom);
    }
    static const Introspectable* get_textMasterStyleAtom(const Introspectable* i, int j) {
        return &(static_cast<const DocumentTextInfoContainer*>(i)->textMasterStyleAtom);
    }
};
const QString DocumentTextInfoContainer::_Introspection::name("DocumentTextInfoContainer");
const int DocumentTextInfoContainer::_Introspection::numberOfMembers(8);
const QString DocumentTextInfoContainer::_Introspection::names[8] = {
    "rh",
    "kinsoku",
    "fontCollection",
    "textCFDefaultsAtom",
    "textPFDefaultsAtom",
    "defaultRulerAtom",
    "textSIDefaultsAtom",
    "textMasterStyleAtom",
};
int (* const DocumentTextInfoContainer::_Introspection::numberOfInstances[8])(const Introspectable*) = {
    Introspection::one,
    _Introspection::count_kinsoku,
    _Introspection::count_fontCollection,
    _Introspection::count_textCFDefaultsAtom,
    _Introspection::count_textPFDefaultsAtom,
    _Introspection::count_defaultRulerAtom,
    Introspection::one,
    Introspection::one,
};
QVariant (* const DocumentTextInfoContainer::_Introspection::value[8])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const DocumentTextInfoContainer::_Introspection::introspectable[8])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_kinsoku,
    _Introspection::get_fontCollection,
    _Introspection::get_textCFDefaultsAtom,
    _Introspection::get_textPFDefaultsAtom,
    _Introspection::get_defaultRulerAtom,
    _Introspection::get_textSIDefaultsAtom,
    _Introspection::get_textMasterStyleAtom,
};
const Introspection DocumentTextInfoContainer::_introspection(
    "DocumentTextInfoContainer", 8, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DrawingGroupContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DrawingGroupContainer*>(i)->rh);
    }
    static const Introspectable* get_OfficeArtDgg(const Introspectable* i, int j) {
        return &(static_cast<const DrawingGroupContainer*>(i)->OfficeArtDgg);
    }
};
const QString DrawingGroupContainer::_Introspection::name("DrawingGroupContainer");
const int DrawingGroupContainer::_Introspection::numberOfMembers(2);
const QString DrawingGroupContainer::_Introspection::names[2] = {
    "rh",
    "OfficeArtDgg",
};
int (* const DrawingGroupContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const DrawingGroupContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const DrawingGroupContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_OfficeArtDgg,
};
const Introspection DrawingGroupContainer::_introspection(
    "DrawingGroupContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtDgContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDgContainer*>(i)->rh);
    }
    static const Introspectable* get_drawingData(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDgContainer*>(i)->drawingData);
    }
    static int count_regroupItems(const Introspectable* i) {
        return static_cast<const OfficeArtDgContainer*>(i)->regroupItems ?1 :0;
    }
    static const Introspectable* get_regroupItems(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtDgContainer*>(i)->regroupItems.data());
    }
    static const Introspectable* get_groupShape(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDgContainer*>(i)->groupShape);
    }
    static const Introspectable* get_shape(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDgContainer*>(i)->shape);
    }
    static int count_deletedShapes(const Introspectable* i) {
        return static_cast<const OfficeArtDgContainer*>(i)->deletedShapes.size();
    }
    static const Introspectable* get_deletedShapes(const Introspectable* i, int j) {
        return &(static_cast<const OfficeArtDgContainer*>(i)->deletedShapes[j]);
    }
    static int count_solvers(const Introspectable* i) {
        return static_cast<const OfficeArtDgContainer*>(i)->solvers ?1 :0;
    }
    static const Introspectable* get_solvers(const Introspectable* i, int j) {
        return (static_cast<const OfficeArtDgContainer*>(i)->solvers.data());
    }
};
const QString OfficeArtDgContainer::_Introspection::name("OfficeArtDgContainer");
const int OfficeArtDgContainer::_Introspection::numberOfMembers(7);
const QString OfficeArtDgContainer::_Introspection::names[7] = {
    "rh",
    "drawingData",
    "regroupItems",
    "groupShape",
    "shape",
    "deletedShapes",
    "solvers",
};
int (* const OfficeArtDgContainer::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_regroupItems,
    Introspection::one,
    Introspection::one,
    _Introspection::count_deletedShapes,
    _Introspection::count_solvers,
};
QVariant (* const OfficeArtDgContainer::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtDgContainer::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_drawingData,
    _Introspection::get_regroupItems,
    _Introspection::get_groupShape,
    _Introspection::get_shape,
    _Introspection::get_deletedShapes,
    _Introspection::get_solvers,
};
const Introspection OfficeArtDgContainer::_introspection(
    "OfficeArtDgContainer", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class OfficeArtSpgrContainerFileBlock::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const OfficeArtSpgrContainerFileBlock*>(i)->anon.officeartspcontainer.data();
        if (k == 0) k = static_cast<const OfficeArtSpgrContainerFileBlock*>(i)->anon.officeartspgrcontainer.data();
        return k;
    }
};
const QString OfficeArtSpgrContainerFileBlock::_Introspection::name("OfficeArtSpgrContainerFileBlock");
const int OfficeArtSpgrContainerFileBlock::_Introspection::numberOfMembers(1);
const QString OfficeArtSpgrContainerFileBlock::_Introspection::names[1] = {
    "anon",
};
int (* const OfficeArtSpgrContainerFileBlock::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const OfficeArtSpgrContainerFileBlock::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const OfficeArtSpgrContainerFileBlock::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection OfficeArtSpgrContainerFileBlock::_introspection(
    "OfficeArtSpgrContainerFileBlock", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DocumentContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[13];
    static int (* const numberOfInstances[13])(const Introspectable*);
    static QVariant (* const value[13])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[13])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DocumentContainer*>(i)->rh);
    }
    static const Introspectable* get_documentAtom(const Introspectable* i, int j) {
        return &(static_cast<const DocumentContainer*>(i)->documentAtom);
    }
    static int count_exObjList(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->exObjList ?1 :0;
    }
    static const Introspectable* get_exObjList(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->exObjList.data());
    }
    static const Introspectable* get_documentTextInfo(const Introspectable* i, int j) {
        return &(static_cast<const DocumentContainer*>(i)->documentTextInfo);
    }
    static const Introspectable* get_drawingGroup(const Introspectable* i, int j) {
        return &(static_cast<const DocumentContainer*>(i)->drawingGroup);
    }
    static const Introspectable* get_masterList(const Introspectable* i, int j) {
        return &(static_cast<const DocumentContainer*>(i)->masterList);
    }
    static int count_docInfoList(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->docInfoList ?1 :0;
    }
    static const Introspectable* get_docInfoList(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->docInfoList.data());
    }
    static int count_slideHF(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->slideHF ?1 :0;
    }
    static const Introspectable* get_slideHF(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->slideHF.data());
    }
    static int count_notesHF(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->notesHF ?1 :0;
    }
    static const Introspectable* get_notesHF(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->notesHF.data());
    }
    static int count_slideList(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->slideList ?1 :0;
    }
    static const Introspectable* get_slideList(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->slideList.data());
    }
    static int count_notesList(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->notesList ?1 :0;
    }
    static const Introspectable* get_notesList(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->notesList.data());
    }
    static int count_slideShowDocInfoAtom(const Introspectable* i) {
        return static_cast<const DocumentContainer*>(i)->slideShowDocInfoAtom ?1 :0;
    }
    static const Introspectable* get_slideShowDocInfoAtom(const Introspectable* i, int j) {
        return (static_cast<const DocumentContainer*>(i)->slideShowDocInfoAtom.data());
    }
    static const Introspectable* get_endDocumentAtom(const Introspectable* i, int j) {
        return &(static_cast<const DocumentContainer*>(i)->endDocumentAtom);
    }
};
const QString DocumentContainer::_Introspection::name("DocumentContainer");
const int DocumentContainer::_Introspection::numberOfMembers(13);
const QString DocumentContainer::_Introspection::names[13] = {
    "rh",
    "documentAtom",
    "exObjList",
    "documentTextInfo",
    "drawingGroup",
    "masterList",
    "docInfoList",
    "slideHF",
    "notesHF",
    "slideList",
    "notesList",
    "slideShowDocInfoAtom",
    "endDocumentAtom",
};
int (* const DocumentContainer::_Introspection::numberOfInstances[13])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_exObjList,
    Introspection::one,
    Introspection::one,
    Introspection::one,
    _Introspection::count_docInfoList,
    _Introspection::count_slideHF,
    _Introspection::count_notesHF,
    _Introspection::count_slideList,
    _Introspection::count_notesList,
    _Introspection::count_slideShowDocInfoAtom,
    Introspection::one,
};
QVariant (* const DocumentContainer::_Introspection::value[13])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const DocumentContainer::_Introspection::introspectable[13])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_documentAtom,
    _Introspection::get_exObjList,
    _Introspection::get_documentTextInfo,
    _Introspection::get_drawingGroup,
    _Introspection::get_masterList,
    _Introspection::get_docInfoList,
    _Introspection::get_slideHF,
    _Introspection::get_notesHF,
    _Introspection::get_slideList,
    _Introspection::get_notesList,
    _Introspection::get_slideShowDocInfoAtom,
    _Introspection::get_endDocumentAtom,
};
const Introspection DocumentContainer::_introspection(
    "DocumentContainer", 13, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class DrawingContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[2];
    static int (* const numberOfInstances[2])(const Introspectable*);
    static QVariant (* const value[2])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[2])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const DrawingContainer*>(i)->rh);
    }
    static const Introspectable* get_OfficeArtDg(const Introspectable* i, int j) {
        return &(static_cast<const DrawingContainer*>(i)->OfficeArtDg);
    }
};
const QString DrawingContainer::_Introspection::name("DrawingContainer");
const int DrawingContainer::_Introspection::numberOfMembers(2);
const QString DrawingContainer::_Introspection::names[2] = {
    "rh",
    "OfficeArtDg",
};
int (* const DrawingContainer::_Introspection::numberOfInstances[2])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
};
QVariant (* const DrawingContainer::_Introspection::value[2])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const DrawingContainer::_Introspection::introspectable[2])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_OfficeArtDg,
};
const Introspection DrawingContainer::_introspection(
    "DrawingContainer", 2, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class SlideContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[7];
    static int (* const numberOfInstances[7])(const Introspectable*);
    static QVariant (* const value[7])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[7])(const Introspectable*, int position);
    static const Introspectable* get_rh(const Introspectable* i, int j) {
        return &(static_cast<const SlideContainer*>(i)->rh);
    }
    static const Introspectable* get_slideAtom(const Introspectable* i, int j) {
        return &(static_cast<const SlideContainer*>(i)->slideAtom);
    }
    static int count_slideShowSlideInfoAtom(const Introspectable* i) {
        return static_cast<const SlideContainer*>(i)->slideShowSlideInfoAtom ?1 :0;
    }
    static const Introspectable* get_slideShowSlideInfoAtom(const Introspectable* i, int j) {
        return (static_cast<const SlideContainer*>(i)->slideShowSlideInfoAtom.data());
    }
    static int count_perSlideHFContainer(const Introspectable* i) {
        return static_cast<const SlideContainer*>(i)->perSlideHFContainer ?1 :0;
    }
    static const Introspectable* get_perSlideHFContainer(const Introspectable* i, int j) {
        return (static_cast<const SlideContainer*>(i)->perSlideHFContainer.data());
    }
    static const Introspectable* get_drawing(const Introspectable* i, int j) {
        return &(static_cast<const SlideContainer*>(i)->drawing);
    }
    static const Introspectable* get_slideSchemeColorSchemeAtom(const Introspectable* i, int j) {
        return &(static_cast<const SlideContainer*>(i)->slideSchemeColorSchemeAtom);
    }
    static int count_slideProgTagsContainer(const Introspectable* i) {
        return static_cast<const SlideContainer*>(i)->slideProgTagsContainer ?1 :0;
    }
    static const Introspectable* get_slideProgTagsContainer(const Introspectable* i, int j) {
        return (static_cast<const SlideContainer*>(i)->slideProgTagsContainer.data());
    }
};
const QString SlideContainer::_Introspection::name("SlideContainer");
const int SlideContainer::_Introspection::numberOfMembers(7);
const QString SlideContainer::_Introspection::names[7] = {
    "rh",
    "slideAtom",
    "slideShowSlideInfoAtom",
    "perSlideHFContainer",
    "drawing",
    "slideSchemeColorSchemeAtom",
    "slideProgTagsContainer",
};
int (* const SlideContainer::_Introspection::numberOfInstances[7])(const Introspectable*) = {
    Introspection::one,
    Introspection::one,
    _Introspection::count_slideShowSlideInfoAtom,
    _Introspection::count_perSlideHFContainer,
    Introspection::one,
    Introspection::one,
    _Introspection::count_slideProgTagsContainer,
};
QVariant (* const SlideContainer::_Introspection::value[7])(const Introspectable*, int position) = {
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
    Introspection::nullValue,
};
const Introspectable* (* const SlideContainer::_Introspection::introspectable[7])(const Introspectable*, int position) = {
    _Introspection::get_rh,
    _Introspection::get_slideAtom,
    _Introspection::get_slideShowSlideInfoAtom,
    _Introspection::get_perSlideHFContainer,
    _Introspection::get_drawing,
    _Introspection::get_slideSchemeColorSchemeAtom,
    _Introspection::get_slideProgTagsContainer,
};
const Introspection SlideContainer::_introspection(
    "SlideContainer", 7, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class MasterOrSlideContainer::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const MasterOrSlideContainer*>(i)->anon.mainmastercontainer.data();
        if (k == 0) k = static_cast<const MasterOrSlideContainer*>(i)->anon.slidecontainer.data();
        return k;
    }
};
const QString MasterOrSlideContainer::_Introspection::name("MasterOrSlideContainer");
const int MasterOrSlideContainer::_Introspection::numberOfMembers(1);
const QString MasterOrSlideContainer::_Introspection::names[1] = {
    "anon",
};
int (* const MasterOrSlideContainer::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const MasterOrSlideContainer::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const MasterOrSlideContainer::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection MasterOrSlideContainer::_introspection(
    "MasterOrSlideContainer", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
class PowerPointStruct::_Introspection {
public:
    static const QString name;
    static const int numberOfMembers;
    static const QString names[1];
    static int (* const numberOfInstances[1])(const Introspectable*);
    static QVariant (* const value[1])(const Introspectable*, int position);
    static const Introspectable* (* const introspectable[1])(const Introspectable*, int position);
    static const Introspectable* get_anon(const Introspectable* i, int j) {
        const Introspectable* k = 0;
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.documentcontainer.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.masterorslidecontainer.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.persistdirectoryatom.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.notescontainer.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.handoutcontainer.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.slidecontainer.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.exoleobjstg.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.excontrolstg.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.vbaprojectstg.data();
        if (k == 0) k = static_cast<const PowerPointStruct*>(i)->anon.usereditatom.data();
        return k;
    }
};
const QString PowerPointStruct::_Introspection::name("PowerPointStruct");
const int PowerPointStruct::_Introspection::numberOfMembers(1);
const QString PowerPointStruct::_Introspection::names[1] = {
    "anon",
};
int (* const PowerPointStruct::_Introspection::numberOfInstances[1])(const Introspectable*) = {
    Introspection::one,
};
QVariant (* const PowerPointStruct::_Introspection::value[1])(const Introspectable*, int position) = {
    Introspection::nullValue,
};
const Introspectable* (* const PowerPointStruct::_Introspection::introspectable[1])(const Introspectable*, int position) = {
    _Introspection::get_anon,
};
const Introspection PowerPointStruct::_introspection(
    "PowerPointStruct", 1, _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);
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
            Byte _t;
            parseByte(in, _t);
            _s.trailing.append(_t);
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
            OfficeArtBStoreContainerFileBlock _t;
            parseOfficeArtBStoreContainerFileBlock(in, _t);
            _s.anon1.append(_t);
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
            PowerPointStruct _t;
            parsePowerPointStruct(in, _t);
            _s.anon.append(_t);
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
            DocInfoListSubContainerOrAtom _t;
            parseDocInfoListSubContainerOrAtom(in, _t);
            _s.rgChildRec.append(_t);
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
            SlideListWithTextSubContainerOrAtom _t;
            parseSlideListWithTextSubContainerOrAtom(in, _t);
            _s.rgChildRec.append(_t);
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
            PersistDirectoryEntry _t;
            parsePersistDirectoryEntry(in, _t);
            _s.rgPersistDirEntry.append(_t);
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
    _s.todo.resize(_c);
    for (int _i=0; _i<_c; ++_i) {
        _s.todo[_i] = in.readuint8();
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
            OfficeArtBStoreContainerFileBlock _t;
            parseOfficeArtBStoreContainerFileBlock(in, _t);
            _s.rgfb.append(_t);
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
            OfficeArtSpgrContainerFileBlock _t;
            parseOfficeArtSpgrContainerFileBlock(in, _t);
            _s.rgfb.append(_t);
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
            TextClientDataSubContainerOrAtom _t;
            parseTextClientDataSubContainerOrAtom(in, _t);
            _s.rgChildRec.append(_t);
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
void parsetodo(LEInputStream& in, todo& _s) {
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
            todo _t;
            parsetodo(in, _t);
            _s.anon.append(_t);
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
            ShapeClientRoundtripDataSubcontainerOrAtom _t;
            parseShapeClientRoundtripDataSubcontainerOrAtom(in, _t);
            _s.rgShapeClientRoundtripData.append(_t);
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
            Pcr _t;
            parsePcr(in, _t);
            _s.RgPrc.append(_t);
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
            OfficeArtSpgrContainerFileBlock _t;
            parseOfficeArtSpgrContainerFileBlock(in, _t);
            _s.deletedShapes.append(_t);
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
const Introspectable* parse(const QString& key, LEInputStream& in) {
    const Introspectable* i = 0;
    if ("PowerPoint Document" == key) {
        PowerPointStructs _t;
        parsePowerPointStructs(in, _t);
        i = new PowerPointStructs(_t);
    } else if ("Current User" == key) {
        CurrentUserStream _t;
        parseCurrentUserStream(in, _t);
        i = new CurrentUserStream(_t);
    } else if ("Pictures" == key) {
        OfficeArtBStoreDelay _t;
        parseOfficeArtBStoreDelay(in, _t);
        i = new OfficeArtBStoreDelay(_t);
    } else if ("WordDocument" == key) {
        WordDocument _t;
        parseWordDocument(in, _t);
        i = new WordDocument(_t);
    } else if ("1Table" == key) {
        Table _t;
        parseTable(in, _t);
        i = new Table(_t);
    } else {
        TODOS _t;
        parseTODOS(in, _t);
        i = new TODOS(_t);
    }
    return i;
}
