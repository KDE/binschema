package mso;
import java.io.IOException;
public class GeneratedMsoParser {
    boolean parse(String key, LEInputStream in) throws IOException {
        if ("PowerPoint Document".equals(key)) {
            parsePowerPointStruct(in);
            return true;
        } else if ("Current User".equals(key)) {
            parseCurrentUserAtom(in);
            return true;
        } else if ("Pictures".equals(key)) {
            parseOfficeArtBStoreDelay(in);
            return true;
        }
        return false;
    }
    RecordHeader parseRecordHeader(LEInputStream in) throws IOException  {
        RecordHeader _s = new RecordHeader();
        _s.recVer = in.readuint4();
        _s.recInstance = in.readuint12();
        _s.recType = in.readuint16();
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
        if (!(_s.lenUserName <= 255)) {
            throw new IncorrectValueException("_s.lenUserName <= 255 for value " + String.valueOf(_s.lenUserName) );
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
        if (!(_s.size >= 8)) {
            throw new IncorrectValueException("_s.size >= 8 for value " + String.valueOf(_s.size) );
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
    PowerPointStruct parsePowerPointStruct(LEInputStream in) throws IOException  {
        PowerPointStruct _s = new PowerPointStruct();
        boolean _atend = false;
        int i=0;
        while (!_atend) {
            System.out.println("round "+(i++));
            Object _m = in.setMark();
            try {
                RecordHeader _t = parseRecordHeader(in);
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
class PowerPointStruct{
    final java.util.List<RecordHeader> anon1 = new java.util.ArrayList<RecordHeader>();
    public String toString() {
        String _s = "PowerPointStruct:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        return _s;
    }
}
