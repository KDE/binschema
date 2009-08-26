#include <QString>
#include <QByteArray>
#include <QVector>
namespace {
class RecordHeader;
class CurrentUserAtom;
class CurrentUserStream;
class PicturesStream;
class OfficeArtBStoreDelay;
class OfficeArtRecordHeader;
class OfficeArtFBSE;
class OfficeArtBlipEMF;
class OfficeArtBlipWMF;
class OfficeArtBlipPICT;
class OfficeArtBlipJPEG;
class OfficeArtBlipPNG;
class OfficeArtBlipDIB;
class OfficeArtBlipTIFF;
class OfficeArtMetafileHeader;
class RECT;
class POINT;
class OfficeArtBlip;
class OfficeArtBStoreContainerFileBlock;
class PowerPointStructs;
class PowerPointStruct;
class DocumentContainer;
class EndDocumentAtom;
class DocInfoListContainer;
class DocInfoListSubContainerOrAtom;
class SlideViewInfoInstance;
class NormalViewSetInfoContainer;
class NormalViewSetInfoAtom;
class MasterListWithTextContainer;
class MasterPersistAtom;
class SlideListWithTextContainer;
class SlideListWithTextSubContainerOrAtom;
class SlidePersistAtom;
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
class DocumentTextInfoContainer;
class TextCFExceptionAtom;
class DefaultRulerAtom;
class TextRuler;
class TabStops;
class TabStop;
class TextPFExceptionAtom;
class TextPFException;
class BulletFlags;
class PFMasks;
class TextCFException;
class CFMasks;
class CFStyle;
class FontCollectionContainer;
class KinsokuContainer;
class KinsokuAtom;
class TextSIExceptionAtom;
class TextMasterStyleAtom;
class TextMasterStyleLevel;
class ExOleEmbedAtom;
class DocumentAtom;
class PointStruct;
class RatioStruct;
class PersistDirectoryAtom;
class PersistDirectoryEntry;
class PersistOffsetEntry;
class PersistIdRef;
class MasterOrSlideContainer;
class MainMasterContainer;
class SlideContainer;
class SlideProgTagscontainer;
class SlideAtom;
class SlideShowSlideInfoAtom;
class DrawingGroupContainer;
class DrawingContainer;
class SlideSchemeColorSchemeAtom;
class RoundTripSlideRecord;
class ColorStruct;
class ExObjListContainer;
class ExObjListAtom;
class ExObjListSubContainer;
class ExOleLinkContainer;
class ExOleEmbedContainer;
class ExOleLinkAtom;
class ExOleObjAtom;
class MenuNameAtom;
class ProgIDAtom;
class ClipboardNameAtom;
class MetafileBlob;
class OfficeArtDggContainer;
class OfficeArtDgContainer;
class OfficeArtFDGGBlock;
class OfficeArtFDGG;
class OfficeArtFDG;
class OfficeArtFRITContainer;
class OfficeArtFRIT;
class OfficeArtSpgrContainer;
class OfficeArtSpgrContainerFileBlock;
class OfficeArtSpContainer;
class OfficeArtFSPGR;
class OfficeArtFSP;
class OfficeArtFPSPL;
class OfficeArtSolverContainer;
class OfficeArtSecondaryFOPT;
class OfficeArtTertiaryFOPT;
class OfficeArtChildAnchor;
class OfficeArtClientAnchor;
class RectStruct;
class SmallRectStruct;
class OfficeArtClientData;
class OfficeArtClientTextBox;
class OfficeArtIDCL;
class OfficeArtBStoreContainer;
class OfficeArtFOPT;
class OfficeArtFOPTE;
class OfficeArtFOPTEOPID;
class OfficeArtColorMRUContainer;
class MSOCR;
class OfficeArtSplitMenuColorContainer;
class TODO;
class TODOS;
class RecordHeader {
public:
    quint8 recVer;
    quint16 recInstance;
    quint16 recType;
    quint32 recLen;
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
};
class CurrentUserStream {
public:
    CurrentUserAtom anon1;
    QByteArray trailing;
};
class OfficeArtBStoreDelay {
public:
    QList<OfficeArtBStoreContainerFileBlock> anon1;
};
class PicturesStream {
public:
    OfficeArtBStoreDelay anon1;
};
class OfficeArtRecordHeader {
public:
    quint8 recVer;
    quint16 recInstance;
    quint16 recType;
    quint32 recLen;
};
class OfficeArtBlipJPEG {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
};
class OfficeArtBlipPNG {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
};
class OfficeArtBlipDIB {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
};
class OfficeArtBlipTIFF {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    quint8 tag;
    QByteArray BLIPFileData;
};
class RECT {
public:
    qint32 left;
    qint32 top;
    qint32 right;
    qint32 bottom;
};
class POINT {
public:
    qint32 x;
    qint32 y;
};
class OfficeArtMetafileHeader {
public:
    quint32 cbSize;
    RECT rcBounds;
    POINT ptSize;
    quint32 cbsave;
    quint8 compression;
    quint8 filter;
};
class OfficeArtBlipEMF {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
};
class OfficeArtBlipWMF {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
};
class OfficeArtBlipPICT {
public:
    OfficeArtRecordHeader rh;
    QByteArray rgbUid1;
    QByteArray rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    QByteArray BLIPFileData;
};
class OfficeArtBlip {
public:
    void * anon;
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
};
class OfficeArtBStoreContainerFileBlock {
public:
    void * anon;
};
class PowerPointStructs {
public:
    QList<PowerPointStruct> anon;
};
class EndDocumentAtom {
public:
    RecordHeader rh;
};
class DocInfoListContainer {
public:
    RecordHeader rh;
    QList<DocInfoListSubContainerOrAtom> rgChildRec;
};
class DocInfoListSubContainerOrAtom {
public:
    RecordHeader rh;
    QByteArray wrong;
};
class SlideViewInfoInstance {
public:
    RecordHeader rh;
    QByteArray todo;
};
class MasterListWithTextContainer {
public:
    RecordHeader rh;
    QVector<MasterPersistAtom> rgMasterPersistAtom;
};
class SlideListWithTextContainer {
public:
    RecordHeader rh;
    QList<SlideListWithTextSubContainerOrAtom> rgChildRec;
};
class TextHeaderAtom {
public:
    RecordHeader rh;
    quint32 textType;
};
class TextCharsAtom {
public:
    RecordHeader rh;
    QVector<quint16> textChars;
};
class TextBytesAtom {
public:
    RecordHeader rh;
    QByteArray textChars;
};
class StyleTextPropAtom {
public:
    RecordHeader rh;
    QByteArray wrong;
};
class SlideNumberMCAtom {
public:
    RecordHeader rh;
    qint32 position;
};
class DateTimeMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    quint8 index;
    QByteArray unused;
};
class GenericDateMCAtom {
public:
    RecordHeader rh;
    qint32 position;
};
class HeaderMCAtom {
public:
    RecordHeader rh;
    qint32 position;
};
class FooterMCAtom {
public:
    RecordHeader rh;
    qint32 position;
};
class RTFDateTimeMCAtom {
public:
    RecordHeader rh;
    qint32 position;
    QByteArray format;
};
class TextBookmarkAtom {
public:
    RecordHeader rh;
    qint32 begin;
    qint32 end;
    qint32 bookmarkID;
};
class TextSpecialInfoAtom {
public:
    RecordHeader rh;
    QByteArray wrong;
};
class InteractiveInfoInstance {
public:
    RecordHeader rh;
    QByteArray range;
};
class TextInteractiveInfoInstance {
public:
    RecordHeader rh;
    QByteArray range;
};
class SlideId {
public:
    quint32 slideId;
};
class TabStops {
public:
    quint16 count;
    QVector<TabStop> rgTabStop;
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
};
class DefaultRulerAtom {
public:
    RecordHeader rh;
    TextRuler defaultTextRuler;
};
class TabStop {
public:
    qint16 position;
    quint16 type;
};
class BulletFlags {
public:
    bool fHasBullet;
    bool fBulletHasFont;
    bool fBulletHasColor;
    bool fBulletHasSize;
    quint16 reserved;
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
};
class TextPFExceptionAtom {
public:
    RecordHeader rh;
    quint16 reserved;
    TextPFException pf;
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
};
class TextCFExceptionAtom {
public:
    RecordHeader rh;
    TextCFException cf;
};
class FontCollectionContainer {
public:
    RecordHeader rh;
    QByteArray rgFontCollectionEntry;
};
class KinsokuAtom {
public:
    RecordHeader rh;
    quint32 level;
};
class KinsokuContainer {
public:
    RecordHeader rh;
    KinsokuAtom kinsokuAtom;
};
class TextSIExceptionAtom {
public:
    RecordHeader rh;
    QByteArray textSIException;
};
class TextMasterStyleLevel {
public:
    TextPFException pf;
    TextCFException cf;
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
};
class ExOleEmbedAtom {
public:
    RecordHeader rh;
    quint32 exColorFollow;
    quint8 fCantLockServer;
    quint8 fNoSizeToServer;
    quint8 fIsTable;
    quint8 unused;
};
class PointStruct {
public:
    qint32 x;
    qint32 y;
};
class RatioStruct {
public:
    qint32 numer;
    qint32 denom;
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
};
class NormalViewSetInfoContainer {
public:
    RecordHeader rh;
    NormalViewSetInfoAtom normalViewSetInfoAtom;
};
class PersistDirectoryAtom {
public:
    RecordHeader rh;
    QList<PersistDirectoryEntry> rgPersistDirEntry;
};
class PersistDirectoryEntry {
public:
    quint32 persistId;
    quint16 cPersist;
    QVector<PersistOffsetEntry> rgPersistOffset;
};
class PersistOffsetEntry {
public:
    quint32 anon;
};
class PersistIdRef {
public:
    quint32 anon;
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
};
class SlideListWithTextSubContainerOrAtom {
public:
    void * anon;
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
};
class MainMasterContainer {
public:
    RecordHeader rh;
    QByteArray todo;
};
class SlideProgTagscontainer {
public:
    RecordHeader rh;
    QByteArray todo;
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
};
class SlideSchemeColorSchemeAtom {
public:
    RecordHeader rh;
    QVector<ColorStruct> rgSchemeColor;
};
class RoundTripSlideRecord {
public:
    RecordHeader rh;
    QByteArray todo;
};
class ColorStruct {
public:
    quint8 red;
    quint8 green;
    quint8 blue;
    quint8 unused;
};
class ExObjListAtom {
public:
    RecordHeader rh;
    qint32 exObjIdSeed;
};
class ExObjListContainer {
public:
    RecordHeader rh;
    ExObjListAtom exObjListAtom;
    QVector<ExObjListSubContainer> rgChildRec;
};
class ExOleLinkAtom {
public:
    RecordHeader rh;
    quint32 slideIdRef;
    quint32 oleUpdateMode;
    quint32 unused;
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
};
class MenuNameAtom {
public:
    RecordHeader rh;
    QByteArray menuName;
};
class ProgIDAtom {
public:
    RecordHeader rh;
    QByteArray progId;
};
class ClipboardNameAtom {
public:
    RecordHeader rh;
    QByteArray clipboardName;
};
class MetafileBlob {
public:
    RecordHeader rh;
    qint16 mm;
    qint16 xExt;
    qint16 yExt;
    QByteArray data;
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
};
class ExObjListSubContainer {
public:
    void * anon;
};
class OfficeArtFDGG {
public:
    quint32 spidMax;
    quint32 cidcl;
    quint32 cspSaved;
    quint32 cdgSaved;
};
class OfficeArtFDGGBlock {
public:
    OfficeArtRecordHeader rh;
    OfficeArtFDGG head;
    QVector<OfficeArtIDCL> Rgidcl;
};
class OfficeArtFDG {
public:
    OfficeArtRecordHeader rh;
    quint32 csp;
    quint32 spidCur;
};
class OfficeArtFRITContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFRIT> rgfrit;
};
class OfficeArtFRIT {
public:
    quint16 fridNew;
    quint16 fridOld;
};
class OfficeArtSpgrContainer {
public:
    OfficeArtRecordHeader rh;
    QList<OfficeArtSpgrContainerFileBlock> rgfb;
};
class OfficeArtFSPGR {
public:
    OfficeArtRecordHeader rh;
    qint32 xLeft;
    qint32 yTop;
    qint32 xRight;
    qint32 yBottom;
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
};
class OfficeArtFPSPL {
public:
    OfficeArtRecordHeader rh;
    quint32 spid;
    bool reserved1;
    bool fLast;
};
class OfficeArtSolverContainer {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
};
class OfficeArtSecondaryFOPT {
public:
    OfficeArtRecordHeader rh;
    QByteArray fopt;
};
class OfficeArtTertiaryFOPT {
public:
    OfficeArtRecordHeader rh;
    QByteArray fopt;
};
class OfficeArtChildAnchor {
public:
    OfficeArtRecordHeader rh;
    qint32 xLeft;
    qint32 yTop;
    qint32 xRight;
    qint32 yBottom;
};
class RectStruct {
public:
    qint32 top;
    qint32 left;
    qint32 right;
    qint32 bottom;
};
class SmallRectStruct {
public:
    qint16 top;
    qint16 left;
    qint16 right;
    qint16 bottom;
};
class OfficeArtClientAnchor {
public:
    OfficeArtRecordHeader rh;
    SmallRectStruct rect1;
    RectStruct rect2;
};
class OfficeArtClientData {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
};
class OfficeArtClientTextBox {
public:
    OfficeArtRecordHeader rh;
    QByteArray todo;
};
class OfficeArtIDCL {
public:
    quint32 dgid;
    quint32 cspidCur;
};
class OfficeArtBStoreContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<OfficeArtBStoreContainerFileBlock> rgfb;
};
class OfficeArtFOPT {
public:
    OfficeArtRecordHeader rh;
    QVector<OfficeArtFOPTE> fopt;
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
};
class DrawingContainer {
public:
    RecordHeader rh;
    OfficeArtDgContainer OfficeArtDg;
};
class SlideContainer {
public:
    RecordHeader rh;
    SlideAtom slideAtom;
    SlideShowSlideInfoAtom slideShowSlideInfoAtom;
    DrawingContainer drawing;
    SlideSchemeColorSchemeAtom slideSchemeColorSchemeAtom;
    SlideProgTagscontainer slideProgTagsContainer;
};
class MasterOrSlideContainer {
public:
    void * anon;
};
class OfficeArtSpgrContainerFileBlock {
public:
    void * anon;
};
class OfficeArtFOPTEOPID {
public:
    quint16 opid;
    bool fBid;
    bool fComplex;
};
class OfficeArtFOPTE {
public:
    OfficeArtFOPTEOPID opid;
    qint32 op;
    QByteArray complexData;
};
class OfficeArtColorMRUContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<MSOCR> rgmsocr;
};
class MSOCR {
public:
    quint8 red;
    quint8 green;
    quint8 blue;
    quint8 unused1;
    bool fSchemeIndex;
    quint8 unused2;
};
class OfficeArtSplitMenuColorContainer {
public:
    OfficeArtRecordHeader rh;
    QVector<MSOCR> smca;
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
};
class DrawingGroupContainer {
public:
    RecordHeader rh;
    OfficeArtDggContainer OfficeArtDgg;
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
};
class PowerPointStruct {
public:
    void * anon;
};
class TODO {
public:
    RecordHeader rh;
    QByteArray anon;
};
class TODOS {
public:
    QList<TODO> anon;
};
}
