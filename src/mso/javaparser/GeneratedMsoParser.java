package mso.javaparser;
import java.io.IOException;
public class GeneratedMsoParser {
    void parse(String key, LEInputStream in) throws IOException {
        if ("PowerPoint Document".equals(key)) {
            parsePowerPointStructs(in);
        } else if ("Current User".equals(key)) {
            parseCurrentUserAtom(in);
        } else if ("Pictures".equals(key)) {
            parseOfficeArtBStoreDelay(in);
        } else {
            parseTODOS(in);
        }
    }
    RecordHeader parseRecordHeader(LEInputStream in) throws IOException  {
        RecordHeader _s = new RecordHeader();
        _s.recVer = in.readuint4();
        _s.recInstance = in.readuint12();
        _s.recType = in.readuint16();
        if (!(_s.recType>0)) {
            throw new IncorrectValueException("_s.recType>0 for value " + String.valueOf(_s.recType) );
        }
        _s.recLen = in.readuint32();
        return _s;
    }
    CurrentUserAtom parseCurrentUserAtom(LEInputStream in) throws IOException  {
        CurrentUserAtom _s = new CurrentUserAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FF6)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FF6 for value " + String.valueOf(_s.rh) );
        }
        _s.size = in.readuint32();
        if (!(_s.size == 0x14)) {
            throw new IncorrectValueException("_s.size == 0x14 for value " + String.valueOf(_s.size) );
        }
        _s.headerToken = in.readuint32();
        if (!(_s.headerToken == 0xE391C05F || _s.headerToken == 0xF3D1C4DF)) {
            throw new IncorrectValueException("_s.headerToken == 0xE391C05F || _s.headerToken == 0xF3D1C4DF for value " + String.valueOf(_s.headerToken) );
        }
        _s.offsetToCurrentEdit = in.readuint32();
        _s.lenUserName = in.readuint16();
        if (!(_s.lenUserName<=255)) {
            throw new IncorrectValueException("_s.lenUserName<=255 for value " + String.valueOf(_s.lenUserName) );
        }
        _s.docFileVersion = in.readuint16();
        if (!(_s.docFileVersion == 0x03F4)) {
            throw new IncorrectValueException("_s.docFileVersion == 0x03F4 for value " + String.valueOf(_s.docFileVersion) );
        }
        _s.majorVersion = in.readuint8();
        if (!(_s.majorVersion == 0x03)) {
            throw new IncorrectValueException("_s.majorVersion == 0x03 for value " + String.valueOf(_s.majorVersion) );
        }
        _s.minorVersion = in.readuint8();
        if (!(_s.minorVersion == 0x00)) {
            throw new IncorrectValueException("_s.minorVersion == 0x00 for value " + String.valueOf(_s.minorVersion) );
        }
        _s.unused = in.readuint16();
        _c = _s.lenUserName;
        _s.ansiUserName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.ansiUserName[_i] = in.readuint8();
        }
        _s.relVersion = in.readuint32();
        if (!(_s.relVersion == 0x8 || _s.relVersion == 0x9)) {
            throw new IncorrectValueException("_s.relVersion == 0x8 || _s.relVersion == 0x9 for value " + String.valueOf(_s.relVersion) );
        }
        if (_s.rh.recLen==3*_s.lenUserName) {
            _c = 2*_s.lenUserName;
            _s.unicodeUserName = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.unicodeUserName[_i] = in.readuint8();
            }
        }
        return _s;
    }
    CurrentUserStream parseCurrentUserStream(LEInputStream in) throws IOException  {
        CurrentUserStream _s = new CurrentUserStream();
        _s.anon1 = parseCurrentUserAtom(in);
        return _s;
    }
    PicturesStream parsePicturesStream(LEInputStream in) throws IOException  {
        PicturesStream _s = new PicturesStream();
        _s.anon1 = parseOfficeArtBStoreDelay(in);
        return _s;
    }
    OfficeArtBStoreDelay parseOfficeArtBStoreDelay(LEInputStream in) throws IOException  {
        OfficeArtBStoreDelay _s = new OfficeArtBStoreDelay();
        boolean _atend = false;
        int i=0;
        while (!_atend) {
            System.out.println("round "+(i++));
            Object _m = in.setMark();
            try {
                OfficeArtBStoreContainerFileBlock _t = parseOfficeArtBStoreContainerFileBlock(in);
                _s.anon1.add(_t);
            } catch(IncorrectValueException _e) {
                _atend = true;
                in.rewind(_m);
            } catch(java.io.EOFException _e) {
                _atend = true;
                in.rewind(_m);
            } finally {
                in.releaseMark(_m);
            }
        }
        return _s;
    }
    OfficeArtRecordHeader parseOfficeArtRecordHeader(LEInputStream in) throws IOException  {
        OfficeArtRecordHeader _s = new OfficeArtRecordHeader();
        _s.recVer = in.readuint4();
        _s.recInstance = in.readuint12();
        _s.recType = in.readuint16();
        _s.recLen = in.readuint32();
        return _s;
    }
    OfficeArtFBSE parseOfficeArtFBSE(LEInputStream in) throws IOException  {
        OfficeArtFBSE _s = new OfficeArtFBSE();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x2)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0xF01A || _s.rh.recInstance == 0xF01B || _s.rh.recInstance == 0xF01C || _s.rh.recInstance == 0xF01D || _s.rh.recInstance == 0xF01E || _s.rh.recInstance == 0xF01F || _s.rh.recInstance == 0xF029)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0xF01A || _s.rh.recInstance == 0xF01B || _s.rh.recInstance == 0xF01C || _s.rh.recInstance == 0xF01D || _s.rh.recInstance == 0xF01E || _s.rh.recInstance == 0xF01F || _s.rh.recInstance == 0xF029 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF007)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF007 for value " + String.valueOf(_s.rh) );
        }
        _s.btWin32 = in.readuint8();
        _s.btMacOS = in.readuint8();
        _c = 16;
        _s.rgbUid = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid[_i] = in.readuint8();
        }
        _s.tag = in.readuint16();
        _s.size = in.readuint32();
        if (!(_s.size>=8)) {
            throw new IncorrectValueException("_s.size>=8 for value " + String.valueOf(_s.size) );
        }
        _s.cRef = in.readuint32();
        _s.foDelay = in.readuint32();
        _s.unused1 = in.readuint8();
        _s.cbName = in.readuint8();
        _s.unused2 = in.readuint8();
        _s.unused3 = in.readuint8();
        _c = _s.rh.recLen-_s.size-36;
        _s.nameData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.nameData[_i] = in.readuint8();
        }
        if (_s.size > 0) {
            _s.embeddedBlip = parseOfficeArtBlip(in);
        }
        return _s;
    }
    OfficeArtBlipEMF parseOfficeArtBlipEMF(LEInputStream in) throws IOException  {
        OfficeArtBlipEMF _s = new OfficeArtBlipEMF();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x3D4 || _s.rh.recInstance == 0x3D5)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x3D4 || _s.rh.recInstance == 0x3D5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01A)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF01A for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x3D5) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.metafileHeader = parseOfficeArtMetafileHeader(in);
        _c = _s.rh.recLen-((_s.rh.recInstance==0x3D4)?50:66);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtBlipWMF parseOfficeArtBlipWMF(LEInputStream in) throws IOException  {
        OfficeArtBlipWMF _s = new OfficeArtBlipWMF();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x216 || _s.rh.recInstance == 0x217)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x216 || _s.rh.recInstance == 0x217 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01B)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF01B for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x217) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.metafileHeader = parseOfficeArtMetafileHeader(in);
        _c = _s.rh.recLen-((_s.rh.recInstance==0x216)?50:66);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtBlipPICT parseOfficeArtBlipPICT(LEInputStream in) throws IOException  {
        OfficeArtBlipPICT _s = new OfficeArtBlipPICT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x542 || _s.rh.recInstance == 0x543)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x542 || _s.rh.recInstance == 0x543 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01C)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF01C for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x543) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.metafileHeader = parseOfficeArtMetafileHeader(in);
        _c = _s.rh.recLen-((_s.rh.recInstance==0x542)?50:66);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtBlipJPEG parseOfficeArtBlipJPEG(LEInputStream in) throws IOException  {
        OfficeArtBlipJPEG _s = new OfficeArtBlipJPEG();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E2 || _s.rh.recInstance == 0x6E3)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E2 || _s.rh.recInstance == 0x6E3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01D)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF01D for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E3) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.tag = in.readuint8();
        _c = _s.rh.recLen-((_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x6E2)?17:33);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtBlipPNG parseOfficeArtBlipPNG(LEInputStream in) throws IOException  {
        OfficeArtBlipPNG _s = new OfficeArtBlipPNG();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x6E0 || _s.rh.recInstance == 0x6E1)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x6E0 || _s.rh.recInstance == 0x6E1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01E)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF01E for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x6E1) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.tag = in.readuint8();
        _c = _s.rh.recLen-((_s.rh.recInstance==0x6E0)?17:33);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtBlipDIB parseOfficeArtBlipDIB(LEInputStream in) throws IOException  {
        OfficeArtBlipDIB _s = new OfficeArtBlipDIB();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x7A8 || _s.rh.recInstance == 0x7A9)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x7A8 || _s.rh.recInstance == 0x7A9 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01F)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF01F for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x7A9) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.tag = in.readuint8();
        _c = _s.rh.recLen-((_s.rh.recInstance==0x7A8)?17:33);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtBlipTIFF parseOfficeArtBlipTIFF(LEInputStream in) throws IOException  {
        OfficeArtBlipTIFF _s = new OfficeArtBlipTIFF();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x6E4 || _s.rh.recInstance == 0x6E5)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x6E4 || _s.rh.recInstance == 0x6E5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF020)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF020 for value " + String.valueOf(_s.rh) );
        }
        _c = 16;
        _s.rgbUid1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgbUid1[_i] = in.readuint8();
        }
        if (_s.rh.recInstance == 0x6E5) {
            _c = 16;
            _s.rgbUid2 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.rgbUid2[_i] = in.readuint8();
            }
        }
        _s.tag = in.readuint8();
        _c = _s.rh.recLen-((_s.rh.recInstance==0x6E4)?17:33);
        _s.BLIPFileData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.BLIPFileData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtMetafileHeader parseOfficeArtMetafileHeader(LEInputStream in) throws IOException  {
        OfficeArtMetafileHeader _s = new OfficeArtMetafileHeader();
        _s.cbSize = in.readuint32();
        _s.rcBounds = parseRECT(in);
        _s.ptSize = parsePOINT(in);
        _s.cbsave = in.readuint32();
        _s.compression = in.readuint8();
        _s.filter = in.readuint8();
        return _s;
    }
    RECT parseRECT(LEInputStream in) throws IOException  {
        RECT _s = new RECT();
        _s.left = in.readint32();
        _s.top = in.readint32();
        _s.right = in.readint32();
        _s.bottom = in.readint32();
        return _s;
    }
    POINT parsePOINT(LEInputStream in) throws IOException  {
        POINT _s = new POINT();
        _s.x = in.readint32();
        _s.y = in.readint32();
        return _s;
    }
    OfficeArtBlip parseOfficeArtBlip(LEInputStream in) throws IOException  {
        OfficeArtBlip _s = new OfficeArtBlip();
        Object _m = in.setMark();
        try {
            _s.anon = parseOfficeArtBlipEMF(in);
        } catch (IncorrectValueException _x) {
            System.out.println(_x.getMessage());
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipWMF(in);
        } catch (IncorrectValueException _xx) {
            System.out.println(_xx.getMessage());
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipPICT(in);
        } catch (IncorrectValueException _xxx) {
            System.out.println(_xxx.getMessage());
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipJPEG(in);
        } catch (IncorrectValueException _xxxx) {
            System.out.println(_xxxx.getMessage());
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipPNG(in);
        } catch (IncorrectValueException _xxxxx) {
            System.out.println(_xxxxx.getMessage());
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipDIB(in);
        } catch (IncorrectValueException _xxxxxx) {
            System.out.println(_xxxxxx.getMessage());
            in.rewind(_m);
            _s.anon = parseOfficeArtBlipTIFF(in);
        }}}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    OfficeArtBStoreContainerFileBlock parseOfficeArtBStoreContainerFileBlock(LEInputStream in) throws IOException  {
        OfficeArtBStoreContainerFileBlock _s = new OfficeArtBStoreContainerFileBlock();
        Object _m = in.setMark();
        try {
            _s.anon = parseOfficeArtFBSE(in);
        } catch (IncorrectValueException _x) {
            System.out.println(_x.getMessage());
            in.rewind(_m);
            _s.anon = parseOfficeArtBlip(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    PowerPointStructs parsePowerPointStructs(LEInputStream in) throws IOException  {
        PowerPointStructs _s = new PowerPointStructs();
        boolean _atend = false;
        int i=0;
        while (!_atend) {
            System.out.println("round "+(i++));
            Object _m = in.setMark();
            try {
                PowerPointStruct _t = parsePowerPointStruct(in);
                _s.anon.add(_t);
            } catch(IncorrectValueException _e) {
                _atend = true;
                in.rewind(_m);
            } catch(java.io.EOFException _e) {
                _atend = true;
                in.rewind(_m);
            } finally {
                in.releaseMark(_m);
            }
        }
        return _s;
    }
    PowerPointStruct parsePowerPointStruct(LEInputStream in) throws IOException  {
        PowerPointStruct _s = new PowerPointStruct();
        Object _m = in.setMark();
        try {
            _s.anon = parseDocumentContainer(in);
        } catch (IncorrectValueException _x) {
            System.out.println(_x.getMessage());
            in.rewind(_m);
        try {
            _s.anon = parseMasterOrSlideContainer(in);
        } catch (IncorrectValueException _xx) {
            System.out.println(_xx.getMessage());
            in.rewind(_m);
            _s.anon = parseTODO(in);
        }} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    DocumentContainer parseDocumentContainer(LEInputStream in) throws IOException  {
        DocumentContainer _s = new DocumentContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03E8)) {
            throw new IncorrectValueException("_s.rh.recType == 0x03E8 for value " + String.valueOf(_s.rh) );
        }
        _s.documentAtom = parseDocumentAtom(in);
        _s.exObjList = parseExObjListContainer(in);
        _s.documentTextInfo = parseDocumentTextInfoContainer(in);
        return _s;
    }
    DocumentTextInfoContainer parseDocumentTextInfoContainer(LEInputStream in) throws IOException  {
        DocumentTextInfoContainer _s = new DocumentTextInfoContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03F2)) {
            throw new IncorrectValueException("_s.rh.recType == 0x03F2 for value " + String.valueOf(_s.rh) );
        }
        return _s;
    }
    ExOleEmbedAtom parseExOleEmbedAtom(LEInputStream in) throws IOException  {
        ExOleEmbedAtom _s = new ExOleEmbedAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FCD)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FCD for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x8)) {
            throw new IncorrectValueException("_s.rh.recLen == 0x8 for value " + String.valueOf(_s.rh) );
        }
        _s.exColorFollow = in.readuint32();
        if (!(_s.exColorFollow == 0 || _s.exColorFollow == 1 || _s.exColorFollow == 2)) {
            throw new IncorrectValueException("_s.exColorFollow == 0 || _s.exColorFollow == 1 || _s.exColorFollow == 2 for value " + String.valueOf(_s.exColorFollow) );
        }
        _s.fCantLockServer = in.readuint8();
        _s.fNoSizeToServer = in.readuint8();
        _s.fIsTable = in.readuint8();
        _s.unused = in.readuint8();
        return _s;
    }
    DocumentAtom parseDocumentAtom(LEInputStream in) throws IOException  {
        DocumentAtom _s = new DocumentAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 1)) {
            throw new IncorrectValueException("_s.rh.recVer == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03E9)) {
            throw new IncorrectValueException("_s.rh.recType == 0x03E9 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x28)) {
            throw new IncorrectValueException("_s.rh.recLen == 0x28 for value " + String.valueOf(_s.rh) );
        }
        _s.slideSize = parsePointStruct(in);
        _s.notesSize = parsePointStruct(in);
        _s.serverZoom = parseRatioStruct(in);
        if (!(_s.serverZoom.numer*_s.serverZoom.denom > 0)) {
            throw new IncorrectValueException("_s.serverZoom.numer*_s.serverZoom.denom > 0 for value " + String.valueOf(_s.serverZoom) );
        }
        _s.notesMasterPersistIdRef = parsePersistIdRef(in);
        _s.handoutMasterPersistIdRef = parsePersistIdRef(in);
        _s.firstSlideNumber = in.readuint16();
        if (!(_s.firstSlideNumber<10000)) {
            throw new IncorrectValueException("_s.firstSlideNumber<10000 for value " + String.valueOf(_s.firstSlideNumber) );
        }
        _s.slideSizeType = in.readuint16();
        if (!(_s.slideSizeType == 0 || _s.slideSizeType == 1 || _s.slideSizeType == 2 || _s.slideSizeType == 3 || _s.slideSizeType == 4 || _s.slideSizeType == 5 || _s.slideSizeType == 6)) {
            throw new IncorrectValueException("_s.slideSizeType == 0 || _s.slideSizeType == 1 || _s.slideSizeType == 2 || _s.slideSizeType == 3 || _s.slideSizeType == 4 || _s.slideSizeType == 5 || _s.slideSizeType == 6 for value " + String.valueOf(_s.slideSizeType) );
        }
        _s.fSaveWithFonts = in.readuint8();
        _s.fOmitTitlePlace = in.readuint8();
        _s.fRightToLeft = in.readuint8();
        _s.fShowComments = in.readuint8();
        return _s;
    }
    PointStruct parsePointStruct(LEInputStream in) throws IOException  {
        PointStruct _s = new PointStruct();
        _s.x = in.readint32();
        _s.y = in.readint32();
        return _s;
    }
    RatioStruct parseRatioStruct(LEInputStream in) throws IOException  {
        RatioStruct _s = new RatioStruct();
        _s.numer = in.readint32();
        _s.denom = in.readint32();
        if (!(_s.denom!= 0)) {
            throw new IncorrectValueException("_s.denom!= 0 for value " + String.valueOf(_s.denom) );
        }
        return _s;
    }
    PersistIdRef parsePersistIdRef(LEInputStream in) throws IOException  {
        PersistIdRef _s = new PersistIdRef();
        _s.anon = in.readuint32();
        return _s;
    }
    MasterOrSlideContainer parseMasterOrSlideContainer(LEInputStream in) throws IOException  {
        MasterOrSlideContainer _s = new MasterOrSlideContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03EE || _s.rh.recType == 0x03F8)) {
            throw new IncorrectValueException("_s.rh.recType == 0x03EE || _s.rh.recType == 0x03F8 for value " + String.valueOf(_s.rh) );
        }
        return _s;
    }
    ExObjListContainer parseExObjListContainer(LEInputStream in) throws IOException  {
        ExObjListContainer _s = new ExObjListContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0409)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0409 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen>=12)) {
            throw new IncorrectValueException("_s.rh.recLen>=12 for value " + String.valueOf(_s.rh) );
        }
        _s.exObjListAtom = parseExObjListAtom(in);
        _c = _s.rh.recLen-12;
        _s.rgChildRec = new ExObjListSubContainer[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgChildRec[_i] = parseExObjListSubContainer(in);
        }
        return _s;
    }
    ExObjListAtom parseExObjListAtom(LEInputStream in) throws IOException  {
        ExObjListAtom _s = new ExObjListAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x040A)) {
            throw new IncorrectValueException("_s.rh.recType == 0x040A for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException("_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.exObjIdSeed = in.readint32();
        if (!(_s.exObjIdSeed>1)) {
            throw new IncorrectValueException("_s.exObjIdSeed>1 for value " + String.valueOf(_s.exObjIdSeed) );
        }
        return _s;
    }
    ExObjListSubContainer parseExObjListSubContainer(LEInputStream in) throws IOException  {
        ExObjListSubContainer _s = new ExObjListSubContainer();
        Object _m = in.setMark();
        try {
            _s.anon = parseExOleLinkContainer(in);
        } catch (IncorrectValueException _x) {
            System.out.println(_x.getMessage());
            in.rewind(_m);
            _s.anon = parseExOleEmbedContainer(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    ExOleLinkContainer parseExOleLinkContainer(LEInputStream in) throws IOException  {
        ExOleLinkContainer _s = new ExOleLinkContainer();
        Object _m;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FCE)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FCE for value " + String.valueOf(_s.rh) );
        }
        _s.exOleLinkAtom = parseExOleLinkAtom(in);
        _s.exOleObjAtom = parseExOleObjAtom(in);
        _m = in.setMark();
        try {
            _s.menuNameAtom = parseMenuNameAtom(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.progIdAtom = parseProgIDAtom(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.clipboardNameAtom = parseClipboardNameAtom(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.metafile = parseMetafileBlob(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    ExOleEmbedContainer parseExOleEmbedContainer(LEInputStream in) throws IOException  {
        ExOleEmbedContainer _s = new ExOleEmbedContainer();
        Object _m;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FCC)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FCC for value " + String.valueOf(_s.rh) );
        }
        _s.exOleEmbedAtom = parseExOleEmbedAtom(in);
        _s.exOleObjAtom = parseExOleObjAtom(in);
        _m = in.setMark();
        try {
            _s.menuNameAtom = parseMenuNameAtom(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.progIdAtom = parseProgIDAtom(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.clipboardNameAtom = parseClipboardNameAtom(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.metafile = parseMetafileBlob(in);
        } catch(IncorrectValueException _e) {
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    ExOleLinkAtom parseExOleLinkAtom(LEInputStream in) throws IOException  {
        ExOleLinkAtom _s = new ExOleLinkAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FD1)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FD1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xC)) {
            throw new IncorrectValueException("_s.rh.recType == 0xC for value " + String.valueOf(_s.rh) );
        }
        _s.slideIdRef = in.readuint32();
        _s.oleUpdateMode = in.readuint32();
        _s.unused = in.readuint32();
        return _s;
    }
    ExOleObjAtom parseExOleObjAtom(LEInputStream in) throws IOException  {
        ExOleObjAtom _s = new ExOleObjAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x1)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC3)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FC3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x18)) {
            throw new IncorrectValueException("_s.rh.recLen == 0x18 for value " + String.valueOf(_s.rh) );
        }
        _s.drawAspect = in.readuint32();
        _s.type = in.readuint32();
        _s.exObjId = in.readuint32();
        _s.subType = in.readuint32();
        _s.persistIdRef = in.readuint32();
        _s.unused = in.readuint32();
        return _s;
    }
    MenuNameAtom parseMenuNameAtom(LEInputStream in) throws IOException  {
        MenuNameAtom _s = new MenuNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x1)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2 == 0 )) {
            throw new IncorrectValueException("_s.rh.recLen%2 == 0  for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.menuName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.menuName[_i] = in.readuint8();
        }
        return _s;
    }
    ProgIDAtom parseProgIDAtom(LEInputStream in) throws IOException  {
        ProgIDAtom _s = new ProgIDAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x2)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2 == 0 )) {
            throw new IncorrectValueException("_s.rh.recLen%2 == 0  for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.progId = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.progId[_i] = in.readuint8();
        }
        return _s;
    }
    ClipboardNameAtom parseClipboardNameAtom(LEInputStream in) throws IOException  {
        ClipboardNameAtom _s = new ClipboardNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x3)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2 == 0 )) {
            throw new IncorrectValueException("_s.rh.recLen%2 == 0  for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.clipboardName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.clipboardName[_i] = in.readuint8();
        }
        return _s;
    }
    MetafileBlob parseMetafileBlob(LEInputStream in) throws IOException  {
        MetafileBlob _s = new MetafileBlob();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC1)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FC1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen>16)) {
            throw new IncorrectValueException("_s.rh.recLen>16 for value " + String.valueOf(_s.rh) );
        }
        _s.mm = in.readint16();
        _s.xExt = in.readint16();
        _s.yExt = in.readint16();
        _c = _s.rh.recLen-6;
        _s.data = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.data[_i] = in.readuint8();
        }
        return _s;
    }
    TODO parseTODO(LEInputStream in) throws IOException  {
        TODO _s = new TODO();
        int _c;
        _s.rh = parseRecordHeader(in);
        _c = _s.rh.recLen;
        _s.anon = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.anon[_i] = in.readuint8();
        }
        return _s;
    }
    TODOS parseTODOS(LEInputStream in) throws IOException  {
        TODOS _s = new TODOS();
        boolean _atend = false;
        int i=0;
        while (!_atend) {
            System.out.println("round "+(i++));
            Object _m = in.setMark();
            try {
                TODO _t = parseTODO(in);
                _s.anon.add(_t);
            } catch(IncorrectValueException _e) {
                _atend = true;
                in.rewind(_m);
            } catch(java.io.EOFException _e) {
                _atend = true;
                in.rewind(_m);
            } finally {
                in.releaseMark(_m);
            }
        }
        return _s;
    }
}
class RecordHeader{
    byte recVer;
    short recInstance;
    int recType;
    int recLen;
    public String toString() {
        String _s = "RecordHeader:";
        _s = _s + "recVer: " + String.valueOf(recVer) + ", ";
        _s = _s + "recInstance: " + String.valueOf(recInstance) + ", ";
        _s = _s + "recType: " + String.valueOf(recType) + ", ";
        _s = _s + "recLen: " + String.valueOf(recLen) + ", ";
        return _s;
    }
}
class CurrentUserAtom{
    RecordHeader rh;
    int size;
    int headerToken;
    int offsetToCurrentEdit;
    int lenUserName;
    int docFileVersion;
    byte majorVersion;
    byte minorVersion;
    int unused;
    byte[] ansiUserName;
    int relVersion;
    byte[] unicodeUserName;
    public String toString() {
        String _s = "CurrentUserAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "size: " + String.valueOf(size) + ", ";
        _s = _s + "headerToken: " + String.valueOf(headerToken) + ", ";
        _s = _s + "offsetToCurrentEdit: " + String.valueOf(offsetToCurrentEdit) + ", ";
        _s = _s + "lenUserName: " + String.valueOf(lenUserName) + ", ";
        _s = _s + "docFileVersion: " + String.valueOf(docFileVersion) + ", ";
        _s = _s + "majorVersion: " + String.valueOf(majorVersion) + ", ";
        _s = _s + "minorVersion: " + String.valueOf(minorVersion) + ", ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        _s = _s + "ansiUserName: " + String.valueOf(ansiUserName) + ", ";
        _s = _s + "relVersion: " + String.valueOf(relVersion) + ", ";
        _s = _s + "unicodeUserName: " + String.valueOf(unicodeUserName) + ", ";
        return _s;
    }
}
class CurrentUserStream{
    CurrentUserAtom anon1;
    public String toString() {
        String _s = "CurrentUserStream:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        return _s;
    }
}
class PicturesStream{
    OfficeArtBStoreDelay anon1;
    public String toString() {
        String _s = "PicturesStream:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        return _s;
    }
}
class OfficeArtBStoreDelay{
    final java.util.List<OfficeArtBStoreContainerFileBlock> anon1 = new java.util.ArrayList<OfficeArtBStoreContainerFileBlock>();
    public String toString() {
        String _s = "OfficeArtBStoreDelay:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        return _s;
    }
}
class OfficeArtRecordHeader{
    byte recVer;
    short recInstance;
    int recType;
    int recLen;
    public String toString() {
        String _s = "OfficeArtRecordHeader:";
        _s = _s + "recVer: " + String.valueOf(recVer) + ", ";
        _s = _s + "recInstance: " + String.valueOf(recInstance) + ", ";
        _s = _s + "recType: " + String.valueOf(recType) + ", ";
        _s = _s + "recLen: " + String.valueOf(recLen) + ", ";
        return _s;
    }
}
class OfficeArtFBSE{
    OfficeArtRecordHeader rh;
    byte btWin32;
    byte btMacOS;
    byte[] rgbUid;
    int tag;
    int size;
    int cRef;
    int foDelay;
    byte unused1;
    byte cbName;
    byte unused2;
    byte unused3;
    byte[] nameData;
    OfficeArtBlip embeddedBlip;
    public String toString() {
        String _s = "OfficeArtFBSE:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "btWin32: " + String.valueOf(btWin32) + ", ";
        _s = _s + "btMacOS: " + String.valueOf(btMacOS) + ", ";
        _s = _s + "rgbUid: " + String.valueOf(rgbUid) + ", ";
        _s = _s + "tag: " + String.valueOf(tag) + ", ";
        _s = _s + "size: " + String.valueOf(size) + ", ";
        _s = _s + "cRef: " + String.valueOf(cRef) + ", ";
        _s = _s + "foDelay: " + String.valueOf(foDelay) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "cbName: " + String.valueOf(cbName) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + ", ";
        _s = _s + "nameData: " + String.valueOf(nameData) + ", ";
        _s = _s + "embeddedBlip: " + String.valueOf(embeddedBlip) + ", ";
        return _s;
    }
}
class OfficeArtBlipEMF{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipEMF:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "metafileHeader: " + String.valueOf(metafileHeader) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipWMF{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipWMF:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "metafileHeader: " + String.valueOf(metafileHeader) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipPICT{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    OfficeArtMetafileHeader metafileHeader;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipPICT:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "metafileHeader: " + String.valueOf(metafileHeader) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipJPEG{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    byte tag;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipJPEG:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "tag: " + String.valueOf(tag) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipPNG{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    byte tag;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipPNG:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "tag: " + String.valueOf(tag) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipDIB{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    byte tag;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipDIB:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "tag: " + String.valueOf(tag) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipTIFF{
    OfficeArtRecordHeader rh;
    byte[] rgbUid1;
    byte[] rgbUid2;
    byte tag;
    byte[] BLIPFileData;
    public String toString() {
        String _s = "OfficeArtBlipTIFF:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgbUid1: " + String.valueOf(rgbUid1) + ", ";
        _s = _s + "rgbUid2: " + String.valueOf(rgbUid2) + ", ";
        _s = _s + "tag: " + String.valueOf(tag) + ", ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtMetafileHeader{
    int cbSize;
    RECT rcBounds;
    POINT ptSize;
    int cbsave;
    byte compression;
    byte filter;
    public String toString() {
        String _s = "OfficeArtMetafileHeader:";
        _s = _s + "cbSize: " + String.valueOf(cbSize) + ", ";
        _s = _s + "rcBounds: " + String.valueOf(rcBounds) + ", ";
        _s = _s + "ptSize: " + String.valueOf(ptSize) + ", ";
        _s = _s + "cbsave: " + String.valueOf(cbsave) + ", ";
        _s = _s + "compression: " + String.valueOf(compression) + ", ";
        _s = _s + "filter: " + String.valueOf(filter) + ", ";
        return _s;
    }
}
class RECT{
    int left;
    int top;
    int right;
    int bottom;
    public String toString() {
        String _s = "RECT:";
        _s = _s + "left: " + String.valueOf(left) + ", ";
        _s = _s + "top: " + String.valueOf(top) + ", ";
        _s = _s + "right: " + String.valueOf(right) + ", ";
        _s = _s + "bottom: " + String.valueOf(bottom) + ", ";
        return _s;
    }
}
class POINT{
    int x;
    int y;
    public String toString() {
        String _s = "POINT:";
        _s = _s + "x: " + String.valueOf(x) + ", ";
        _s = _s + "y: " + String.valueOf(y) + ", ";
        return _s;
    }
}
class OfficeArtBlip{
    Object anon;
    public String toString() {
        String _s = "OfficeArtBlip:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class OfficeArtBStoreContainerFileBlock{
    Object anon;
    public String toString() {
        String _s = "OfficeArtBStoreContainerFileBlock:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class PowerPointStructs{
    final java.util.List<PowerPointStruct> anon = new java.util.ArrayList<PowerPointStruct>();
    public String toString() {
        String _s = "PowerPointStructs:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class PowerPointStruct{
    Object anon;
    public String toString() {
        String _s = "PowerPointStruct:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class DocumentContainer{
    RecordHeader rh;
    DocumentAtom documentAtom;
    ExObjListContainer exObjList;
    DocumentTextInfoContainer documentTextInfo;
    public String toString() {
        String _s = "DocumentContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "documentAtom: " + String.valueOf(documentAtom) + ", ";
        _s = _s + "exObjList: " + String.valueOf(exObjList) + ", ";
        _s = _s + "documentTextInfo: " + String.valueOf(documentTextInfo) + ", ";
        return _s;
    }
}
class DocumentTextInfoContainer{
    RecordHeader rh;
    public String toString() {
        String _s = "DocumentTextInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        return _s;
    }
}
class ExOleEmbedAtom{
    RecordHeader rh;
    int exColorFollow;
    byte fCantLockServer;
    byte fNoSizeToServer;
    byte fIsTable;
    byte unused;
    public String toString() {
        String _s = "ExOleEmbedAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exColorFollow: " + String.valueOf(exColorFollow) + ", ";
        _s = _s + "fCantLockServer: " + String.valueOf(fCantLockServer) + ", ";
        _s = _s + "fNoSizeToServer: " + String.valueOf(fNoSizeToServer) + ", ";
        _s = _s + "fIsTable: " + String.valueOf(fIsTable) + ", ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        return _s;
    }
}
class DocumentAtom{
    RecordHeader rh;
    PointStruct slideSize;
    PointStruct notesSize;
    RatioStruct serverZoom;
    PersistIdRef notesMasterPersistIdRef;
    PersistIdRef handoutMasterPersistIdRef;
    int firstSlideNumber;
    int slideSizeType;
    byte fSaveWithFonts;
    byte fOmitTitlePlace;
    byte fRightToLeft;
    byte fShowComments;
    public String toString() {
        String _s = "DocumentAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slideSize: " + String.valueOf(slideSize) + ", ";
        _s = _s + "notesSize: " + String.valueOf(notesSize) + ", ";
        _s = _s + "serverZoom: " + String.valueOf(serverZoom) + ", ";
        _s = _s + "notesMasterPersistIdRef: " + String.valueOf(notesMasterPersistIdRef) + ", ";
        _s = _s + "handoutMasterPersistIdRef: " + String.valueOf(handoutMasterPersistIdRef) + ", ";
        _s = _s + "firstSlideNumber: " + String.valueOf(firstSlideNumber) + ", ";
        _s = _s + "slideSizeType: " + String.valueOf(slideSizeType) + ", ";
        _s = _s + "fSaveWithFonts: " + String.valueOf(fSaveWithFonts) + ", ";
        _s = _s + "fOmitTitlePlace: " + String.valueOf(fOmitTitlePlace) + ", ";
        _s = _s + "fRightToLeft: " + String.valueOf(fRightToLeft) + ", ";
        _s = _s + "fShowComments: " + String.valueOf(fShowComments) + ", ";
        return _s;
    }
}
class PointStruct{
    int x;
    int y;
    public String toString() {
        String _s = "PointStruct:";
        _s = _s + "x: " + String.valueOf(x) + ", ";
        _s = _s + "y: " + String.valueOf(y) + ", ";
        return _s;
    }
}
class RatioStruct{
    int numer;
    int denom;
    public String toString() {
        String _s = "RatioStruct:";
        _s = _s + "numer: " + String.valueOf(numer) + ", ";
        _s = _s + "denom: " + String.valueOf(denom) + ", ";
        return _s;
    }
}
class PersistIdRef{
    int anon;
    public String toString() {
        String _s = "PersistIdRef:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class MasterOrSlideContainer{
    RecordHeader rh;
    public String toString() {
        String _s = "MasterOrSlideContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        return _s;
    }
}
class ExObjListContainer{
    RecordHeader rh;
    ExObjListAtom exObjListAtom;
    ExObjListSubContainer[] rgChildRec;
    public String toString() {
        String _s = "ExObjListContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exObjListAtom: " + String.valueOf(exObjListAtom) + ", ";
        _s = _s + "rgChildRec: " + String.valueOf(rgChildRec) + ", ";
        return _s;
    }
}
class ExObjListAtom{
    RecordHeader rh;
    int exObjIdSeed;
    public String toString() {
        String _s = "ExObjListAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exObjIdSeed: " + String.valueOf(exObjIdSeed) + ", ";
        return _s;
    }
}
class ExObjListSubContainer{
    Object anon;
    public String toString() {
        String _s = "ExObjListSubContainer:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class ExOleLinkContainer{
    RecordHeader rh;
    ExOleLinkAtom exOleLinkAtom;
    ExOleObjAtom exOleObjAtom;
    MenuNameAtom menuNameAtom;
    ProgIDAtom progIdAtom;
    ClipboardNameAtom clipboardNameAtom;
    MetafileBlob metafile;
    public String toString() {
        String _s = "ExOleLinkContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exOleLinkAtom: " + String.valueOf(exOleLinkAtom) + ", ";
        _s = _s + "exOleObjAtom: " + String.valueOf(exOleObjAtom) + ", ";
        _s = _s + "menuNameAtom: " + String.valueOf(menuNameAtom) + ", ";
        _s = _s + "progIdAtom: " + String.valueOf(progIdAtom) + ", ";
        _s = _s + "clipboardNameAtom: " + String.valueOf(clipboardNameAtom) + ", ";
        _s = _s + "metafile: " + String.valueOf(metafile) + ", ";
        return _s;
    }
}
class ExOleEmbedContainer{
    RecordHeader rh;
    ExOleEmbedAtom exOleEmbedAtom;
    ExOleObjAtom exOleObjAtom;
    MenuNameAtom menuNameAtom;
    ProgIDAtom progIdAtom;
    ClipboardNameAtom clipboardNameAtom;
    MetafileBlob metafile;
    public String toString() {
        String _s = "ExOleEmbedContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exOleEmbedAtom: " + String.valueOf(exOleEmbedAtom) + ", ";
        _s = _s + "exOleObjAtom: " + String.valueOf(exOleObjAtom) + ", ";
        _s = _s + "menuNameAtom: " + String.valueOf(menuNameAtom) + ", ";
        _s = _s + "progIdAtom: " + String.valueOf(progIdAtom) + ", ";
        _s = _s + "clipboardNameAtom: " + String.valueOf(clipboardNameAtom) + ", ";
        _s = _s + "metafile: " + String.valueOf(metafile) + ", ";
        return _s;
    }
}
class ExOleLinkAtom{
    RecordHeader rh;
    int slideIdRef;
    int oleUpdateMode;
    int unused;
    public String toString() {
        String _s = "ExOleLinkAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slideIdRef: " + String.valueOf(slideIdRef) + ", ";
        _s = _s + "oleUpdateMode: " + String.valueOf(oleUpdateMode) + ", ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        return _s;
    }
}
class ExOleObjAtom{
    RecordHeader rh;
    int drawAspect;
    int type;
    int exObjId;
    int subType;
    int persistIdRef;
    int unused;
    public String toString() {
        String _s = "ExOleObjAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "drawAspect: " + String.valueOf(drawAspect) + ", ";
        _s = _s + "type: " + String.valueOf(type) + ", ";
        _s = _s + "exObjId: " + String.valueOf(exObjId) + ", ";
        _s = _s + "subType: " + String.valueOf(subType) + ", ";
        _s = _s + "persistIdRef: " + String.valueOf(persistIdRef) + ", ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        return _s;
    }
}
class MenuNameAtom{
    RecordHeader rh;
    byte[] menuName;
    public String toString() {
        String _s = "MenuNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "menuName: " + String.valueOf(menuName) + ", ";
        return _s;
    }
}
class ProgIDAtom{
    RecordHeader rh;
    byte[] progId;
    public String toString() {
        String _s = "ProgIDAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "progId: " + String.valueOf(progId) + ", ";
        return _s;
    }
}
class ClipboardNameAtom{
    RecordHeader rh;
    byte[] clipboardName;
    public String toString() {
        String _s = "ClipboardNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "clipboardName: " + String.valueOf(clipboardName) + ", ";
        return _s;
    }
}
class MetafileBlob{
    RecordHeader rh;
    short mm;
    short xExt;
    short yExt;
    byte[] data;
    public String toString() {
        String _s = "MetafileBlob:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "mm: " + String.valueOf(mm) + ", ";
        _s = _s + "xExt: " + String.valueOf(xExt) + ", ";
        _s = _s + "yExt: " + String.valueOf(yExt) + ", ";
        _s = _s + "data: " + String.valueOf(data) + ", ";
        return _s;
    }
}
class TODO{
    RecordHeader rh;
    byte[] anon;
    public String toString() {
        String _s = "TODO:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class TODOS{
    final java.util.List<TODO> anon = new java.util.ArrayList<TODO>();
    public String toString() {
        String _s = "TODOS:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
