package mso.javaparser;
import java.io.IOException;
public class GeneratedMsoParser {
    void parse(String key, LEInputStream in) throws IOException {
        if ("PowerPoint Document".equals(key)) {
            parsePowerPointStructs(in);
        } else if ("Current User".equals(key)) {
            parseCurrentUserAtom(in);
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
System.out.println(_s);
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
        if (_s.rh.recLen==3*_s.lenUserName+0x14) {
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipWMF(in);
        } catch (IncorrectValueException _xx) {
            System.out.println(_xx.getMessage());
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipPICT(in);
        } catch (IncorrectValueException _xxx) {
            System.out.println(_xxx.getMessage());
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipJPEG(in);
        } catch (IncorrectValueException _xxxx) {
            System.out.println(_xxxx.getMessage());
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipPNG(in);
        } catch (IncorrectValueException _xxxxx) {
            System.out.println(_xxxxx.getMessage());
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipDIB(in);
        } catch (IncorrectValueException _xxxxxx) {
            System.out.println(_xxxxxx.getMessage());
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxx);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseMasterOrSlideContainer(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    DocumentContainer parseDocumentContainer(LEInputStream in) throws IOException  {
        DocumentContainer _s = new DocumentContainer();
        Object _m;
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
        _m = in.setMark();
        try {
            _s.exObjList = parseExObjListContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.documentTextInfo = parseDocumentTextInfoContainer(in);
        _s.drawingGroup = parseDrawingGroupContainer(in);
        return _s;
    }
    DocumentTextInfoContainer parseDocumentTextInfoContainer(LEInputStream in) throws IOException  {
        DocumentTextInfoContainer _s = new DocumentTextInfoContainer();
        Object _m;
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
        _m = in.setMark();
        try {
            _s.kinsoku = parseKinsokuContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.fontCollection = parseFontCollectionContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.textCFDefaultsAtom = parseTextCFExceptionAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.textPFDefaultsAtom = parseTextPFExceptionAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.defaultRulerAtom = parseDefaultRulerAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.textSIDefaultsAtom = parseTextSIExceptionAtom(in);
        _s.textMasterStyleAtom = parseTextMasterStyleAtom(in);
        return _s;
    }
    TextCFExceptionAtom parseTextCFExceptionAtom(LEInputStream in) throws IOException  {
        TextCFExceptionAtom _s = new TextCFExceptionAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA4)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FA4 for value " + String.valueOf(_s.rh) );
        }
        _s.cf = parseTextCFException(in);
        return _s;
    }
    DefaultRulerAtom parseDefaultRulerAtom(LEInputStream in) throws IOException  {
        DefaultRulerAtom _s = new DefaultRulerAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FAB)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FAB for value " + String.valueOf(_s.rh) );
        }
        _s.defaultTextRuler = parseTextRuler(in);
        if (!(_s.defaultTextRuler.fDefaultTabSize == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fDefaultTabSize == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fCLevels == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fCLevels == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fTabStops == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fTabStops == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin1 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fLeftMargin1 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin2 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fLeftMargin2 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin3 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fLeftMargin3 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin4 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fLeftMargin4 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent1 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fIndent1 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent2 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fIndent2 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent3 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fIndent3 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent4 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fIndent4 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent5 == true)) {
            throw new IncorrectValueException("_s.defaultTextRuler.fIndent5 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        return _s;
    }
    TextRuler parseTextRuler(LEInputStream in) throws IOException  {
        TextRuler _s = new TextRuler();
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
            _s.tabs = parseTabStops(in);
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
        return _s;
    }
    TabStops parseTabStops(LEInputStream in) throws IOException  {
        TabStops _s = new TabStops();
        int _c;
        _s.count = in.readuint16();
        _c = _s.count;
        _s.rgTabStop = new TabStop[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgTabStop[_i] = parseTabStop(in);
        }
        return _s;
    }
    TabStop parseTabStop(LEInputStream in) throws IOException  {
        TabStop _s = new TabStop();
        _s.position = in.readint16();
        _s.type = in.readuint16();
        return _s;
    }
    TextPFExceptionAtom parseTextPFExceptionAtom(LEInputStream in) throws IOException  {
        TextPFExceptionAtom _s = new TextPFExceptionAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA5)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FA5 for value " + String.valueOf(_s.rh) );
        }
        _s.reserved = in.readuint16();
        _s.pf = parseTextPFException(in);
        return _s;
    }
    TextPFException parseTextPFException(LEInputStream in) throws IOException  {
        TextPFException _s = new TextPFException();
        _s.masks = parsePFMasks(in);
        if (!(_s.masks.bulletBlip == false)) {
            throw new IncorrectValueException("_s.masks.bulletBlip == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.bulletHasScheme == false)) {
            throw new IncorrectValueException("_s.masks.bulletHasScheme == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.bulletScheme == false)) {
            throw new IncorrectValueException("_s.masks.bulletScheme == false for value " + String.valueOf(_s.masks) );
        }
        if (_s.masks.hasBullet||_s.masks.bulletHasFont||_s.masks.bulletHasColor||_s.masks.bulletHasSize) {
            _s.bulletFlags = parseBulletFlags(in);
        }
        if (_s.masks.bulletChar) {
            _s.bulletChar = in.readint16();
        if (!(_s.bulletChar != 0)) {
            throw new IncorrectValueException("_s.bulletChar != 0 for value " + String.valueOf(_s.bulletChar) );
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
            _s.tabStops = parseTabStops(in);
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
        return _s;
    }
    BulletFlags parseBulletFlags(LEInputStream in) throws IOException  {
        BulletFlags _s = new BulletFlags();
        _s.fHasBullet = in.readbit();
        _s.fBulletHasFont = in.readbit();
        _s.fBulletHasColor = in.readbit();
        _s.fBulletHasSize = in.readbit();
        _s.reserved = in.readuint12();
        return _s;
    }
    PFMasks parsePFMasks(LEInputStream in) throws IOException  {
        PFMasks _s = new PFMasks();
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
        return _s;
    }
    TextCFException parseTextCFException(LEInputStream in) throws IOException  {
        TextCFException _s = new TextCFException();
        _s.masks = parseCFMasks(in);
        if (!(_s.masks.pp10ext == false)) {
            throw new IncorrectValueException("_s.masks.pp10ext == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.newEATypeface == false)) {
            throw new IncorrectValueException("_s.masks.newEATypeface == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.csTypeface == false)) {
            throw new IncorrectValueException("_s.masks.csTypeface == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.pp11ext == false)) {
            throw new IncorrectValueException("_s.masks.pp11ext == false for value " + String.valueOf(_s.masks) );
        }
        if (_s.masks.bold || _s.masks.italic || _s.masks.underline || _s.masks.shadow || _s.masks.fehint || _s.masks.kumi || _s.masks.emboss || _s.masks.fHasStyle != 0) {
            _s.fontStyle = parseCFStyle(in);
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
        if (!(_s.fontSize>=1)) {
            throw new IncorrectValueException("_s.fontSize>=1 for value " + String.valueOf(_s.fontSize) );
        }
        if (!(_s.fontSize<=4000)) {
            throw new IncorrectValueException("_s.fontSize<=4000 for value " + String.valueOf(_s.fontSize) );
        }
        }
        if (_s.masks.color) {
            _s.color = in.readuint32();
        }
        if (_s.masks.position) {
            _s.position = in.readuint16();
        if (!(_s.position>=-100)) {
            throw new IncorrectValueException("_s.position>=-100 for value " + String.valueOf(_s.position) );
        }
        if (!(_s.position<=100)) {
            throw new IncorrectValueException("_s.position<=100 for value " + String.valueOf(_s.position) );
        }
        }
        return _s;
    }
    CFMasks parseCFMasks(LEInputStream in) throws IOException  {
        CFMasks _s = new CFMasks();
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
        return _s;
    }
    CFStyle parseCFStyle(LEInputStream in) throws IOException  {
        CFStyle _s = new CFStyle();
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
        return _s;
    }
    FontCollectionContainer parseFontCollectionContainer(LEInputStream in) throws IOException  {
        FontCollectionContainer _s = new FontCollectionContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x07D5)) {
            throw new IncorrectValueException("_s.rh.recType == 0x07D5 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.rgFontCollectionEntry = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgFontCollectionEntry[_i] = in.readuint8();
        }
        return _s;
    }
    KinsokuContainer parseKinsokuContainer(LEInputStream in) throws IOException  {
        KinsokuContainer _s = new KinsokuContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x2)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC8)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FC8 for value " + String.valueOf(_s.rh) );
        }
        _s.kinsokuAtom = parseKinsokuAtom(in);
        return _s;
    }
    KinsokuAtom parseKinsokuAtom(LEInputStream in) throws IOException  {
        KinsokuAtom _s = new KinsokuAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x3)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FD2)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FD2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException("_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.level = in.readuint32();
        if (!(_s.level == 0 || _s.level == 1 || _s.level == 2)) {
            throw new IncorrectValueException("_s.level == 0 || _s.level == 1 || _s.level == 2 for value " + String.valueOf(_s.level) );
        }
        return _s;
    }
    TextSIExceptionAtom parseTextSIExceptionAtom(LEInputStream in) throws IOException  {
        TextSIExceptionAtom _s = new TextSIExceptionAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA9)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FA9 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.textSIException = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.textSIException[_i] = in.readuint8();
        }
        return _s;
    }
    TextMasterStyleAtom parseTextMasterStyleAtom(LEInputStream in) throws IOException  {
        TextMasterStyleAtom _s = new TextMasterStyleAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 8)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 8 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA3)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0FA3 for value " + String.valueOf(_s.rh) );
        }
        _s.cLevels = in.readuint16();
        if (_s.rh.recInstance>=5) {
            _s.lstLvl1level = in.readuint16();
        }
        if (_s.cLevels>0) {
            _s.lstLvl1 = parseTextMasterStyleLevel(in);
        }
        if (_s.rh.recInstance>=5) {
            _s.lstLvl2level = in.readuint16();
        }
        if (_s.cLevels>1) {
            _s.lstLvl2 = parseTextMasterStyleLevel(in);
        }
        if (_s.rh.recInstance>=5) {
            _s.lstLvl3level = in.readuint16();
        }
        if (_s.cLevels>2) {
            _s.lstLvl3 = parseTextMasterStyleLevel(in);
        }
        if (_s.rh.recInstance>=5) {
            _s.lstLvl4level = in.readuint16();
        }
        if (_s.cLevels>3) {
            _s.lstLvl4 = parseTextMasterStyleLevel(in);
        }
        if (_s.rh.recInstance>=5) {
            _s.lstLvl5level = in.readuint16();
        }
        if (_s.cLevels>4) {
            _s.lstLvl5 = parseTextMasterStyleLevel(in);
        }
        return _s;
    }
    TextMasterStyleLevel parseTextMasterStyleLevel(LEInputStream in) throws IOException  {
        TextMasterStyleLevel _s = new TextMasterStyleLevel();
        _s.pf = parseTextPFException(in);
        _s.cf = parseTextCFException(in);
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
    DrawingGroupContainer parseDrawingGroupContainer(LEInputStream in) throws IOException  {
        DrawingGroupContainer _s = new DrawingGroupContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x040B)) {
            throw new IncorrectValueException("_s.rh.recType == 0x040B for value " + String.valueOf(_s.rh) );
        }
        _s.OfficeArtDgg = parseOfficeArtDggContainer(in);
        return _s;
    }
    OfficeArtDggContainer parseOfficeArtDggContainer(LEInputStream in) throws IOException  {
        OfficeArtDggContainer _s = new OfficeArtDggContainer();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F000)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0F000 for value " + String.valueOf(_s.rh) );
        }
        _s.drawingGroup = parseOfficeArtFDGGBlock(in);
        _s.blipStore = parseOfficeArtBStoreContainer(in);
        _s.drawingPrimaryOptions = parseOfficeArtFOPT(in);
        _s.drawingTertiaryOptions = parseOfficeArtTertiaryFOPT(in);
        _s.colorMRU = parseOfficeArtColorMRUContainer(in);
        _s.splitColors = parseOfficeArtSplitMenuColorContainer(in);
        return _s;
    }
    OfficeArtFDGGBlock parseOfficeArtFDGGBlock(LEInputStream in) throws IOException  {
        OfficeArtFDGGBlock _s = new OfficeArtFDGGBlock();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F006)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0F006 for value " + String.valueOf(_s.rh) );
        }
        _s.head = parseOfficeArtFDGG(in);
        _c = _s.head.cidcl;
        _s.Rgidcl = new OfficeArtIDCL[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.Rgidcl[_i] = parseOfficeArtIDCL(in);
        }
        return _s;
    }
    OfficeArtFDGG parseOfficeArtFDGG(LEInputStream in) throws IOException  {
        OfficeArtFDGG _s = new OfficeArtFDGG();
        _s.spidMax = in.readuint32();
        if (!(_s.spidMax<67098623)) {
            throw new IncorrectValueException("_s.spidMax<67098623 for value " + String.valueOf(_s.spidMax) );
        }
        _s.cidcl = in.readuint32();
        if (!(_s.cidcl<268435455)) {
            throw new IncorrectValueException("_s.cidcl<268435455 for value " + String.valueOf(_s.cidcl) );
        }
        _s.cspSaved = in.readuint32();
        _s.cdgSaved = in.readuint32();
        return _s;
    }
    OfficeArtIDCL parseOfficeArtIDCL(LEInputStream in) throws IOException  {
        OfficeArtIDCL _s = new OfficeArtIDCL();
        _s.dgid = in.readuint32();
        _s.cspidCur = in.readuint32();
        return _s;
    }
    OfficeArtBStoreContainer parseOfficeArtBStoreContainer(LEInputStream in) throws IOException  {
        OfficeArtBStoreContainer _s = new OfficeArtBStoreContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException("_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F001)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0F001 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.rgfb = new OfficeArtBStoreContainerFileBlock[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgfb[_i] = parseOfficeArtBStoreContainerFileBlock(in);
        }
        return _s;
    }
    OfficeArtFOPT parseOfficeArtFOPT(LEInputStream in) throws IOException  {
        OfficeArtFOPT _s = new OfficeArtFOPT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x3)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F008)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0F008 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.fopt = new OfficeArtFOPTE[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.fopt[_i] = parseOfficeArtFOPTE(in);
        }
        return _s;
    }
    OfficeArtFOPTE parseOfficeArtFOPTE(LEInputStream in) throws IOException  {
        OfficeArtFOPTE _s = new OfficeArtFOPTE();
        int _c;
        _s.opid = parseOfficeArtFOPTEOPID(in);
        _s.op = in.readint32();
        _c = (_s.opid.fComplex)?_s.op:0;
        _s.complexData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.complexData[_i] = in.readuint8();
        }
        return _s;
    }
    OfficeArtFOPTEOPID parseOfficeArtFOPTEOPID(LEInputStream in) throws IOException  {
        OfficeArtFOPTEOPID _s = new OfficeArtFOPTEOPID();
        _s.opid = in.readuint14();
        _s.fBid = in.readbit();
        _s.fComplex = in.readbit();
        return _s;
    }
    OfficeArtTertiaryFOPT parseOfficeArtTertiaryFOPT(LEInputStream in) throws IOException  {
        OfficeArtTertiaryFOPT _s = new OfficeArtTertiaryFOPT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x3)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F122)) {
            throw new IncorrectValueException("_s.rh.recType == 0x0F122 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.fopt = new OfficeArtFOPTE[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.fopt[_i] = parseOfficeArtFOPTE(in);
        }
        return _s;
    }
    OfficeArtColorMRUContainer parseOfficeArtColorMRUContainer(LEInputStream in) throws IOException  {
        OfficeArtColorMRUContainer _s = new OfficeArtColorMRUContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF11A)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF11A for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen==4*_s.rh.recInstance)) {
            throw new IncorrectValueException("_s.rh.recLen==4*_s.rh.recInstance for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.rgmsocr = new MSOCR[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgmsocr[_i] = parseMSOCR(in);
        }
        return _s;
    }
    MSOCR parseMSOCR(LEInputStream in) throws IOException  {
        MSOCR _s = new MSOCR();
        _s.red = in.readuint8();
        _s.green = in.readuint8();
        _s.blue = in.readuint8();
        _s.unused1 = in.readuint3();
        _s.fSchemeIndex = in.readbit();
        _s.unused2 = in.readuint4();
        return _s;
    }
    OfficeArtSplitMenuColorContainer parseOfficeArtSplitMenuColorContainer(LEInputStream in) throws IOException  {
        OfficeArtSplitMenuColorContainer _s = new OfficeArtSplitMenuColorContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException("_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x4)) {
            throw new IncorrectValueException("_s.rh.recInstance == 0x4 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF11E)) {
            throw new IncorrectValueException("_s.rh.recType == 0xF11E for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x10)) {
            throw new IncorrectValueException("_s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
        }
        _c = 4;
        _s.smca = new MSOCR[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.smca[_i] = parseMSOCR(in);
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
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
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
    DrawingGroupContainer drawingGroup;
    public String toString() {
        String _s = "DocumentContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "documentAtom: " + String.valueOf(documentAtom) + ", ";
        _s = _s + "exObjList: " + String.valueOf(exObjList) + ", ";
        _s = _s + "documentTextInfo: " + String.valueOf(documentTextInfo) + ", ";
        _s = _s + "drawingGroup: " + String.valueOf(drawingGroup) + ", ";
        return _s;
    }
}
class DocumentTextInfoContainer{
    RecordHeader rh;
    KinsokuContainer kinsoku;
    FontCollectionContainer fontCollection;
    TextCFExceptionAtom textCFDefaultsAtom;
    TextPFExceptionAtom textPFDefaultsAtom;
    DefaultRulerAtom defaultRulerAtom;
    TextSIExceptionAtom textSIDefaultsAtom;
    TextMasterStyleAtom textMasterStyleAtom;
    public String toString() {
        String _s = "DocumentTextInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "kinsoku: " + String.valueOf(kinsoku) + ", ";
        _s = _s + "fontCollection: " + String.valueOf(fontCollection) + ", ";
        _s = _s + "textCFDefaultsAtom: " + String.valueOf(textCFDefaultsAtom) + ", ";
        _s = _s + "textPFDefaultsAtom: " + String.valueOf(textPFDefaultsAtom) + ", ";
        _s = _s + "defaultRulerAtom: " + String.valueOf(defaultRulerAtom) + ", ";
        _s = _s + "textSIDefaultsAtom: " + String.valueOf(textSIDefaultsAtom) + ", ";
        _s = _s + "textMasterStyleAtom: " + String.valueOf(textMasterStyleAtom) + ", ";
        return _s;
    }
}
class TextCFExceptionAtom{
    RecordHeader rh;
    TextCFException cf;
    public String toString() {
        String _s = "TextCFExceptionAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "cf: " + String.valueOf(cf) + ", ";
        return _s;
    }
}
class DefaultRulerAtom{
    RecordHeader rh;
    TextRuler defaultTextRuler;
    public String toString() {
        String _s = "DefaultRulerAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "defaultTextRuler: " + String.valueOf(defaultTextRuler) + ", ";
        return _s;
    }
}
class TextRuler{
    boolean fDefaultTabSize;
    boolean fCLevels;
    boolean fTabStops;
    boolean fLeftMargin1;
    boolean fLeftMargin2;
    boolean fLeftMargin3;
    boolean fLeftMargin4;
    boolean fLeftMargin5;
    boolean fIndent1;
    boolean fIndent2;
    boolean fIndent3;
    boolean fIndent4;
    boolean fIndent5;
    byte reserved1;
    int reserved2;
    short cLevels;
    int defaultTabSize;
    TabStops tabs;
    int leftMargin1;
    int indent1;
    int leftMargin2;
    int indent2;
    int leftMargin3;
    int indent3;
    int leftMargin4;
    int indent4;
    int leftMargin5;
    int indent5;
    public String toString() {
        String _s = "TextRuler:";
        _s = _s + "fDefaultTabSize: " + String.valueOf(fDefaultTabSize) + ", ";
        _s = _s + "fCLevels: " + String.valueOf(fCLevels) + ", ";
        _s = _s + "fTabStops: " + String.valueOf(fTabStops) + ", ";
        _s = _s + "fLeftMargin1: " + String.valueOf(fLeftMargin1) + ", ";
        _s = _s + "fLeftMargin2: " + String.valueOf(fLeftMargin2) + ", ";
        _s = _s + "fLeftMargin3: " + String.valueOf(fLeftMargin3) + ", ";
        _s = _s + "fLeftMargin4: " + String.valueOf(fLeftMargin4) + ", ";
        _s = _s + "fLeftMargin5: " + String.valueOf(fLeftMargin5) + ", ";
        _s = _s + "fIndent1: " + String.valueOf(fIndent1) + ", ";
        _s = _s + "fIndent2: " + String.valueOf(fIndent2) + ", ";
        _s = _s + "fIndent3: " + String.valueOf(fIndent3) + ", ";
        _s = _s + "fIndent4: " + String.valueOf(fIndent4) + ", ";
        _s = _s + "fIndent5: " + String.valueOf(fIndent5) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + ", ";
        _s = _s + "cLevels: " + String.valueOf(cLevels) + ", ";
        _s = _s + "defaultTabSize: " + String.valueOf(defaultTabSize) + ", ";
        _s = _s + "tabs: " + String.valueOf(tabs) + ", ";
        _s = _s + "leftMargin1: " + String.valueOf(leftMargin1) + ", ";
        _s = _s + "indent1: " + String.valueOf(indent1) + ", ";
        _s = _s + "leftMargin2: " + String.valueOf(leftMargin2) + ", ";
        _s = _s + "indent2: " + String.valueOf(indent2) + ", ";
        _s = _s + "leftMargin3: " + String.valueOf(leftMargin3) + ", ";
        _s = _s + "indent3: " + String.valueOf(indent3) + ", ";
        _s = _s + "leftMargin4: " + String.valueOf(leftMargin4) + ", ";
        _s = _s + "indent4: " + String.valueOf(indent4) + ", ";
        _s = _s + "leftMargin5: " + String.valueOf(leftMargin5) + ", ";
        _s = _s + "indent5: " + String.valueOf(indent5) + ", ";
        return _s;
    }
}
class TabStops{
    int count;
    TabStop[] rgTabStop;
    public String toString() {
        String _s = "TabStops:";
        _s = _s + "count: " + String.valueOf(count) + ", ";
        _s = _s + "rgTabStop: " + String.valueOf(rgTabStop) + ", ";
        return _s;
    }
}
class TabStop{
    short position;
    int type;
    public String toString() {
        String _s = "TabStop:";
        _s = _s + "position: " + String.valueOf(position) + ", ";
        _s = _s + "type: " + String.valueOf(type) + ", ";
        return _s;
    }
}
class TextPFExceptionAtom{
    RecordHeader rh;
    int reserved;
    TextPFException pf;
    public String toString() {
        String _s = "TextPFExceptionAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + ", ";
        _s = _s + "pf: " + String.valueOf(pf) + ", ";
        return _s;
    }
}
class TextPFException{
    PFMasks masks;
    BulletFlags bulletFlags;
    short bulletChar;
    int bulletFontRef;
    int bulletSize;
    int bulletColor;
    int textAlignment;
    int lineSpacing;
    int spaceBefore;
    int spaceAfter;
    int leftMargin;
    int indent;
    int defaultTabSize;
    TabStops tabStops;
    int fontAlign;
    int wrapFlags;
    int textDirection;
    public String toString() {
        String _s = "TextPFException:";
        _s = _s + "masks: " + String.valueOf(masks) + ", ";
        _s = _s + "bulletFlags: " + String.valueOf(bulletFlags) + ", ";
        _s = _s + "bulletChar: " + String.valueOf(bulletChar) + ", ";
        _s = _s + "bulletFontRef: " + String.valueOf(bulletFontRef) + ", ";
        _s = _s + "bulletSize: " + String.valueOf(bulletSize) + ", ";
        _s = _s + "bulletColor: " + String.valueOf(bulletColor) + ", ";
        _s = _s + "textAlignment: " + String.valueOf(textAlignment) + ", ";
        _s = _s + "lineSpacing: " + String.valueOf(lineSpacing) + ", ";
        _s = _s + "spaceBefore: " + String.valueOf(spaceBefore) + ", ";
        _s = _s + "spaceAfter: " + String.valueOf(spaceAfter) + ", ";
        _s = _s + "leftMargin: " + String.valueOf(leftMargin) + ", ";
        _s = _s + "indent: " + String.valueOf(indent) + ", ";
        _s = _s + "defaultTabSize: " + String.valueOf(defaultTabSize) + ", ";
        _s = _s + "tabStops: " + String.valueOf(tabStops) + ", ";
        _s = _s + "fontAlign: " + String.valueOf(fontAlign) + ", ";
        _s = _s + "wrapFlags: " + String.valueOf(wrapFlags) + ", ";
        _s = _s + "textDirection: " + String.valueOf(textDirection) + ", ";
        return _s;
    }
}
class BulletFlags{
    boolean fHasBullet;
    boolean fBulletHasFont;
    boolean fBulletHasColor;
    boolean fBulletHasSize;
    short reserved;
    public String toString() {
        String _s = "BulletFlags:";
        _s = _s + "fHasBullet: " + String.valueOf(fHasBullet) + ", ";
        _s = _s + "fBulletHasFont: " + String.valueOf(fBulletHasFont) + ", ";
        _s = _s + "fBulletHasColor: " + String.valueOf(fBulletHasColor) + ", ";
        _s = _s + "fBulletHasSize: " + String.valueOf(fBulletHasSize) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + ", ";
        return _s;
    }
}
class PFMasks{
    boolean hasBullet;
    boolean bulletHasFont;
    boolean bulletHasColor;
    boolean bulletHasSize;
    boolean bulletFont;
    boolean bulletColor;
    boolean bulletSize;
    boolean bulletChar;
    boolean leftMargin;
    boolean unused;
    boolean indent;
    boolean align;
    boolean lineSpacing;
    boolean spaceBefore;
    boolean spaceAfter;
    boolean defaultTabSize;
    boolean fontAlign;
    boolean charWrap;
    boolean wordWrap;
    boolean overflow;
    boolean tabStops;
    boolean textDirection;
    boolean reserved;
    boolean bulletBlip;
    boolean bulletScheme;
    boolean bulletHasScheme;
    byte reserved2;
    public String toString() {
        String _s = "PFMasks:";
        _s = _s + "hasBullet: " + String.valueOf(hasBullet) + ", ";
        _s = _s + "bulletHasFont: " + String.valueOf(bulletHasFont) + ", ";
        _s = _s + "bulletHasColor: " + String.valueOf(bulletHasColor) + ", ";
        _s = _s + "bulletHasSize: " + String.valueOf(bulletHasSize) + ", ";
        _s = _s + "bulletFont: " + String.valueOf(bulletFont) + ", ";
        _s = _s + "bulletColor: " + String.valueOf(bulletColor) + ", ";
        _s = _s + "bulletSize: " + String.valueOf(bulletSize) + ", ";
        _s = _s + "bulletChar: " + String.valueOf(bulletChar) + ", ";
        _s = _s + "leftMargin: " + String.valueOf(leftMargin) + ", ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        _s = _s + "indent: " + String.valueOf(indent) + ", ";
        _s = _s + "align: " + String.valueOf(align) + ", ";
        _s = _s + "lineSpacing: " + String.valueOf(lineSpacing) + ", ";
        _s = _s + "spaceBefore: " + String.valueOf(spaceBefore) + ", ";
        _s = _s + "spaceAfter: " + String.valueOf(spaceAfter) + ", ";
        _s = _s + "defaultTabSize: " + String.valueOf(defaultTabSize) + ", ";
        _s = _s + "fontAlign: " + String.valueOf(fontAlign) + ", ";
        _s = _s + "charWrap: " + String.valueOf(charWrap) + ", ";
        _s = _s + "wordWrap: " + String.valueOf(wordWrap) + ", ";
        _s = _s + "overflow: " + String.valueOf(overflow) + ", ";
        _s = _s + "tabStops: " + String.valueOf(tabStops) + ", ";
        _s = _s + "textDirection: " + String.valueOf(textDirection) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + ", ";
        _s = _s + "bulletBlip: " + String.valueOf(bulletBlip) + ", ";
        _s = _s + "bulletScheme: " + String.valueOf(bulletScheme) + ", ";
        _s = _s + "bulletHasScheme: " + String.valueOf(bulletHasScheme) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + ", ";
        return _s;
    }
}
class TextCFException{
    CFMasks masks;
    CFStyle fontStyle;
    int fontRef;
    int oldEAFontRef;
    int ansiFontRef;
    int symbolFontRef;
    int fontSize;
    int color;
    int position;
    public String toString() {
        String _s = "TextCFException:";
        _s = _s + "masks: " + String.valueOf(masks) + ", ";
        _s = _s + "fontStyle: " + String.valueOf(fontStyle) + ", ";
        _s = _s + "fontRef: " + String.valueOf(fontRef) + ", ";
        _s = _s + "oldEAFontRef: " + String.valueOf(oldEAFontRef) + ", ";
        _s = _s + "ansiFontRef: " + String.valueOf(ansiFontRef) + ", ";
        _s = _s + "symbolFontRef: " + String.valueOf(symbolFontRef) + ", ";
        _s = _s + "fontSize: " + String.valueOf(fontSize) + ", ";
        _s = _s + "color: " + String.valueOf(color) + ", ";
        _s = _s + "position: " + String.valueOf(position) + ", ";
        return _s;
    }
}
class CFMasks{
    boolean bold;
    boolean italic;
    boolean underline;
    boolean unused1;
    boolean shadow;
    boolean fehint;
    boolean unused2;
    boolean kumi;
    boolean unused3;
    boolean emboss;
    byte fHasStyle;
    byte unused4;
    boolean typeface;
    boolean size;
    boolean color;
    boolean position;
    boolean pp10ext;
    boolean oldEATypeface;
    boolean ansiTypeface;
    boolean symbolTypeface;
    boolean newEATypeface;
    boolean csTypeface;
    boolean pp11ext;
    byte reserved;
    public String toString() {
        String _s = "CFMasks:";
        _s = _s + "bold: " + String.valueOf(bold) + ", ";
        _s = _s + "italic: " + String.valueOf(italic) + ", ";
        _s = _s + "underline: " + String.valueOf(underline) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "shadow: " + String.valueOf(shadow) + ", ";
        _s = _s + "fehint: " + String.valueOf(fehint) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "kumi: " + String.valueOf(kumi) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + ", ";
        _s = _s + "emboss: " + String.valueOf(emboss) + ", ";
        _s = _s + "fHasStyle: " + String.valueOf(fHasStyle) + ", ";
        _s = _s + "unused4: " + String.valueOf(unused4) + ", ";
        _s = _s + "typeface: " + String.valueOf(typeface) + ", ";
        _s = _s + "size: " + String.valueOf(size) + ", ";
        _s = _s + "color: " + String.valueOf(color) + ", ";
        _s = _s + "position: " + String.valueOf(position) + ", ";
        _s = _s + "pp10ext: " + String.valueOf(pp10ext) + ", ";
        _s = _s + "oldEATypeface: " + String.valueOf(oldEATypeface) + ", ";
        _s = _s + "ansiTypeface: " + String.valueOf(ansiTypeface) + ", ";
        _s = _s + "symbolTypeface: " + String.valueOf(symbolTypeface) + ", ";
        _s = _s + "newEATypeface: " + String.valueOf(newEATypeface) + ", ";
        _s = _s + "csTypeface: " + String.valueOf(csTypeface) + ", ";
        _s = _s + "pp11ext: " + String.valueOf(pp11ext) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + ", ";
        return _s;
    }
}
class CFStyle{
    boolean bold;
    boolean italic;
    boolean underline;
    boolean unused1;
    boolean shadow;
    boolean fehint;
    boolean unused2;
    boolean kumi;
    boolean unused3;
    boolean emboss;
    byte pp9rt;
    byte unused4;
    public String toString() {
        String _s = "CFStyle:";
        _s = _s + "bold: " + String.valueOf(bold) + ", ";
        _s = _s + "italic: " + String.valueOf(italic) + ", ";
        _s = _s + "underline: " + String.valueOf(underline) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "shadow: " + String.valueOf(shadow) + ", ";
        _s = _s + "fehint: " + String.valueOf(fehint) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "kumi: " + String.valueOf(kumi) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + ", ";
        _s = _s + "emboss: " + String.valueOf(emboss) + ", ";
        _s = _s + "pp9rt: " + String.valueOf(pp9rt) + ", ";
        _s = _s + "unused4: " + String.valueOf(unused4) + ", ";
        return _s;
    }
}
class FontCollectionContainer{
    RecordHeader rh;
    byte[] rgFontCollectionEntry;
    public String toString() {
        String _s = "FontCollectionContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgFontCollectionEntry: " + String.valueOf(rgFontCollectionEntry) + ", ";
        return _s;
    }
}
class KinsokuContainer{
    RecordHeader rh;
    KinsokuAtom kinsokuAtom;
    public String toString() {
        String _s = "KinsokuContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "kinsokuAtom: " + String.valueOf(kinsokuAtom) + ", ";
        return _s;
    }
}
class KinsokuAtom{
    RecordHeader rh;
    int level;
    public String toString() {
        String _s = "KinsokuAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "level: " + String.valueOf(level) + ", ";
        return _s;
    }
}
class TextSIExceptionAtom{
    RecordHeader rh;
    byte[] textSIException;
    public String toString() {
        String _s = "TextSIExceptionAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "textSIException: " + String.valueOf(textSIException) + ", ";
        return _s;
    }
}
class TextMasterStyleAtom{
    RecordHeader rh;
    int cLevels;
    int lstLvl1level;
    TextMasterStyleLevel lstLvl1;
    int lstLvl2level;
    TextMasterStyleLevel lstLvl2;
    int lstLvl3level;
    TextMasterStyleLevel lstLvl3;
    int lstLvl4level;
    TextMasterStyleLevel lstLvl4;
    int lstLvl5level;
    TextMasterStyleLevel lstLvl5;
    public String toString() {
        String _s = "TextMasterStyleAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "cLevels: " + String.valueOf(cLevels) + ", ";
        _s = _s + "lstLvl1level: " + String.valueOf(lstLvl1level) + ", ";
        _s = _s + "lstLvl1: " + String.valueOf(lstLvl1) + ", ";
        _s = _s + "lstLvl2level: " + String.valueOf(lstLvl2level) + ", ";
        _s = _s + "lstLvl2: " + String.valueOf(lstLvl2) + ", ";
        _s = _s + "lstLvl3level: " + String.valueOf(lstLvl3level) + ", ";
        _s = _s + "lstLvl3: " + String.valueOf(lstLvl3) + ", ";
        _s = _s + "lstLvl4level: " + String.valueOf(lstLvl4level) + ", ";
        _s = _s + "lstLvl4: " + String.valueOf(lstLvl4) + ", ";
        _s = _s + "lstLvl5level: " + String.valueOf(lstLvl5level) + ", ";
        _s = _s + "lstLvl5: " + String.valueOf(lstLvl5) + ", ";
        return _s;
    }
}
class TextMasterStyleLevel{
    TextPFException pf;
    TextCFException cf;
    public String toString() {
        String _s = "TextMasterStyleLevel:";
        _s = _s + "pf: " + String.valueOf(pf) + ", ";
        _s = _s + "cf: " + String.valueOf(cf) + ", ";
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
class DrawingGroupContainer{
    RecordHeader rh;
    OfficeArtDggContainer OfficeArtDgg;
    public String toString() {
        String _s = "DrawingGroupContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "OfficeArtDgg: " + String.valueOf(OfficeArtDgg) + ", ";
        return _s;
    }
}
class OfficeArtDggContainer{
    OfficeArtRecordHeader rh;
    OfficeArtFDGGBlock drawingGroup;
    OfficeArtBStoreContainer blipStore;
    OfficeArtFOPT drawingPrimaryOptions;
    OfficeArtTertiaryFOPT drawingTertiaryOptions;
    OfficeArtColorMRUContainer colorMRU;
    OfficeArtSplitMenuColorContainer splitColors;
    public String toString() {
        String _s = "OfficeArtDggContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "drawingGroup: " + String.valueOf(drawingGroup) + ", ";
        _s = _s + "blipStore: " + String.valueOf(blipStore) + ", ";
        _s = _s + "drawingPrimaryOptions: " + String.valueOf(drawingPrimaryOptions) + ", ";
        _s = _s + "drawingTertiaryOptions: " + String.valueOf(drawingTertiaryOptions) + ", ";
        _s = _s + "colorMRU: " + String.valueOf(colorMRU) + ", ";
        _s = _s + "splitColors: " + String.valueOf(splitColors) + ", ";
        return _s;
    }
}
class OfficeArtFDGGBlock{
    OfficeArtRecordHeader rh;
    OfficeArtFDGG head;
    OfficeArtIDCL[] Rgidcl;
    public String toString() {
        String _s = "OfficeArtFDGGBlock:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "head: " + String.valueOf(head) + ", ";
        _s = _s + "Rgidcl: " + String.valueOf(Rgidcl) + ", ";
        return _s;
    }
}
class OfficeArtFDGG{
    int spidMax;
    int cidcl;
    int cspSaved;
    int cdgSaved;
    public String toString() {
        String _s = "OfficeArtFDGG:";
        _s = _s + "spidMax: " + String.valueOf(spidMax) + ", ";
        _s = _s + "cidcl: " + String.valueOf(cidcl) + ", ";
        _s = _s + "cspSaved: " + String.valueOf(cspSaved) + ", ";
        _s = _s + "cdgSaved: " + String.valueOf(cdgSaved) + ", ";
        return _s;
    }
}
class OfficeArtIDCL{
    int dgid;
    int cspidCur;
    public String toString() {
        String _s = "OfficeArtIDCL:";
        _s = _s + "dgid: " + String.valueOf(dgid) + ", ";
        _s = _s + "cspidCur: " + String.valueOf(cspidCur) + ", ";
        return _s;
    }
}
class OfficeArtBStoreContainer{
    OfficeArtRecordHeader rh;
    OfficeArtBStoreContainerFileBlock[] rgfb;
    public String toString() {
        String _s = "OfficeArtBStoreContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgfb: " + String.valueOf(rgfb) + ", ";
        return _s;
    }
}
class OfficeArtFOPT{
    OfficeArtRecordHeader rh;
    OfficeArtFOPTE[] fopt;
    public String toString() {
        String _s = "OfficeArtFOPT:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "fopt: " + String.valueOf(fopt) + ", ";
        return _s;
    }
}
class OfficeArtFOPTE{
    OfficeArtFOPTEOPID opid;
    int op;
    byte[] complexData;
    public String toString() {
        String _s = "OfficeArtFOPTE:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "op: " + String.valueOf(op) + ", ";
        _s = _s + "complexData: " + String.valueOf(complexData) + ", ";
        return _s;
    }
}
class OfficeArtFOPTEOPID{
    short opid;
    boolean fBid;
    boolean fComplex;
    public String toString() {
        String _s = "OfficeArtFOPTEOPID:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fBid: " + String.valueOf(fBid) + ", ";
        _s = _s + "fComplex: " + String.valueOf(fComplex) + ", ";
        return _s;
    }
}
class OfficeArtTertiaryFOPT{
    OfficeArtRecordHeader rh;
    OfficeArtFOPTE[] fopt;
    public String toString() {
        String _s = "OfficeArtTertiaryFOPT:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "fopt: " + String.valueOf(fopt) + ", ";
        return _s;
    }
}
class OfficeArtColorMRUContainer{
    OfficeArtRecordHeader rh;
    MSOCR[] rgmsocr;
    public String toString() {
        String _s = "OfficeArtColorMRUContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgmsocr: " + String.valueOf(rgmsocr) + ", ";
        return _s;
    }
}
class MSOCR{
    byte red;
    byte green;
    byte blue;
    byte unused1;
    boolean fSchemeIndex;
    byte unused2;
    public String toString() {
        String _s = "MSOCR:";
        _s = _s + "red: " + String.valueOf(red) + ", ";
        _s = _s + "green: " + String.valueOf(green) + ", ";
        _s = _s + "blue: " + String.valueOf(blue) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "fSchemeIndex: " + String.valueOf(fSchemeIndex) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        return _s;
    }
}
class OfficeArtSplitMenuColorContainer{
    OfficeArtRecordHeader rh;
    MSOCR[] smca;
    public String toString() {
        String _s = "OfficeArtSplitMenuColorContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "smca: " + String.valueOf(smca) + ", ";
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
