package mso.javaparser;
import java.io.IOException;
public class GeneratedMsoParser {
    Object parse(String key, LEInputStream in) throws IOException {
        if ("PowerPoint Document".equals(key)) {
            return parsePowerPointStructs(in);
        } else if ("Current User".equals(key)) {
            return parseCurrentUserStream(in);
        } else if ("Pictures".equals(key)) {
            return parseOfficeArtBStoreDelay(in);
        } else if ("WordDocument".equals(key)) {
            return parseWordDocument(in);
        } else if ("1Table".equals(key)) {
            return parseTable(in);
        } else if ("SummaryInformation".equals(key)) {
            return parseSummaryInformationPropertySetStream(in);
        } else if ("DocumentSummaryInformation".equals(key)) {
            return parseDocumentSummaryInformationPropertySetStream(in);
        } else if ("textPFRun".equals(key)) {
            return parseTextPFRun(in);
        } else if ("textCFRun".equals(key)) {
            return parseTextCFRun(in);
        } else {
            return parseTODOS(in);
        }
    }
    void serialize(String key, Object o, LEOutputStream out) throws IOException {
        if ("PowerPoint Document".equals(key)) {
            write((PowerPointStructs)o, out);
        } else if ("Current User".equals(key)) {
            write((CurrentUserStream)o, out);
        } else if ("Pictures".equals(key)) {
            write((OfficeArtBStoreDelay)o, out);
        } else if ("WordDocument".equals(key)) {
            write((WordDocument)o, out);
        } else if ("1Table".equals(key)) {
            write((Table)o, out);
        } else if ("SummaryInformation".equals(key)) {
            write((SummaryInformationPropertySetStream)o, out);
        } else if ("DocumentSummaryInformation".equals(key)) {
            write((DocumentSummaryInformationPropertySetStream)o, out);
        } else if ("textPFRun".equals(key)) {
            write((TextPFRun)o, out);
        } else if ("textCFRun".equals(key)) {
            write((TextCFRun)o, out);
        } else {
            write((TODOS)o, out);
        }
    }
    RecordHeader parseRecordHeader(LEInputStream in) throws IOException  {
        RecordHeader _s = new RecordHeader();
        _s.recVer = in.readuint4();
        _s.recInstance = in.readuint12();
        _s.recType = in.readuint16();
        if (!(_s.recType>0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.recType>0 for value " + String.valueOf(_s.recType) );
        }
        _s.recLen = in.readuint32();
System.out.println(in.getPosition()+" "+_s);
        return _s;
    }
    void write(RecordHeader _s, LEOutputStream out) throws IOException  {
        out.writeuint4(_s.recVer);
        out.writeuint12(_s.recInstance);
        out.writeuint16(_s.recType);
        out.writeuint32(_s.recLen);
    }
    CurrentUserAtom parseCurrentUserAtom(LEInputStream in) throws IOException  {
        CurrentUserAtom _s = new CurrentUserAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FF6)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FF6 for value " + String.valueOf(_s.rh) );
        }
        _s.size = in.readuint32();
        if (!(_s.size == 0x14)) {
            throw new IncorrectValueException(in.getPosition() + "_s.size == 0x14 for value " + String.valueOf(_s.size) );
        }
        _s.headerToken = in.readuint32();
        if (!(_s.headerToken == 0xE391C05F || _s.headerToken == 0xF3D1C4DF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.headerToken == 0xE391C05F || _s.headerToken == 0xF3D1C4DF for value " + String.valueOf(_s.headerToken) );
        }
        _s.offsetToCurrentEdit = in.readuint32();
        _s.lenUserName = in.readuint16();
        if (!(_s.lenUserName<=255)) {
            throw new IncorrectValueException(in.getPosition() + "_s.lenUserName<=255 for value " + String.valueOf(_s.lenUserName) );
        }
        _s.docFileVersion = in.readuint16();
        if (!(_s.docFileVersion == 0x03F4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.docFileVersion == 0x03F4 for value " + String.valueOf(_s.docFileVersion) );
        }
        _s.majorVersion = in.readuint8();
        if (!(_s.majorVersion == 0x03)) {
            throw new IncorrectValueException(in.getPosition() + "_s.majorVersion == 0x03 for value " + String.valueOf(_s.majorVersion) );
        }
        _s.minorVersion = in.readuint8();
        if (!(_s.minorVersion == 0x00)) {
            throw new IncorrectValueException(in.getPosition() + "_s.minorVersion == 0x00 for value " + String.valueOf(_s.minorVersion) );
        }
        _s.unused = in.readuint16();
        _c = _s.lenUserName;
        _s.ansiUserName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.ansiUserName[_i] = in.readuint8();
        }
        _s.relVersion = in.readuint32();
        if (!(_s.relVersion == 0x8 || _s.relVersion == 0x9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.relVersion == 0x8 || _s.relVersion == 0x9 for value " + String.valueOf(_s.relVersion) );
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
    void write(CurrentUserAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.size);
        out.writeuint32(_s.headerToken);
        out.writeuint32(_s.offsetToCurrentEdit);
        out.writeuint16(_s.lenUserName);
        out.writeuint16(_s.docFileVersion);
        out.writeuint8(_s.majorVersion);
        out.writeuint8(_s.minorVersion);
        out.writeuint16(_s.unused);
        for (byte _i: _s.ansiUserName) {
            out.writeuint8(_i);
        }
        out.writeuint32(_s.relVersion);
        if (_s.rh.recLen==3*_s.lenUserName+0x14) {
            for (byte _i: _s.unicodeUserName) {
                out.writeuint8(_i);
            }
        }
    }
    TODOS parseTODOS(LEInputStream in) throws IOException  {
        TODOS _s = new TODOS();
        Object _m;
        boolean _atend;
        int _i;
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                Byte _t = parseByte(in);
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
    void write(TODOS _s, LEOutputStream out) throws IOException  {
        for (Byte _i: _s.anon) {
            write(_i, out);
        }
    }
    Byte parseByte(LEInputStream in) throws IOException  {
        Byte _s = new Byte();
        _s.b = in.readuint8();
        return _s;
    }
    void write(Byte _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.b);
    }
    CurrentUserStream parseCurrentUserStream(LEInputStream in) throws IOException  {
        CurrentUserStream _s = new CurrentUserStream();
        Object _m;
        boolean _atend;
        int _i;
        _s.anon1 = parseCurrentUserAtom(in);
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                Byte _t = parseByte(in);
                _s.trailing.add(_t);
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
    void write(CurrentUserStream _s, LEOutputStream out) throws IOException  {
        write(_s.anon1, out);
        for (Byte _i: _s.trailing) {
            write(_i, out);
        }
    }
    OfficeArtBStoreDelay parseOfficeArtBStoreDelay(LEInputStream in) throws IOException  {
        OfficeArtBStoreDelay _s = new OfficeArtBStoreDelay();
        Object _m;
        boolean _atend;
        int _i;
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
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
    void write(OfficeArtBStoreDelay _s, LEOutputStream out) throws IOException  {
        for (OfficeArtBStoreContainerFileBlock _i: _s.anon1) {
            write(_i, out);
        }
    }
    OfficeArtRecordHeader parseOfficeArtRecordHeader(LEInputStream in) throws IOException  {
        OfficeArtRecordHeader _s = new OfficeArtRecordHeader();
        _s.recVer = in.readuint4();
        _s.recInstance = in.readuint12();
        _s.recType = in.readuint16();
        _s.recLen = in.readuint32();
System.out.println(in.getPosition()+" "+_s);
        return _s;
    }
    void write(OfficeArtRecordHeader _s, LEOutputStream out) throws IOException  {
        out.writeuint4(_s.recVer);
        out.writeuint12(_s.recInstance);
        out.writeuint16(_s.recType);
        out.writeuint32(_s.recLen);
    }
    OfficeArtBlipJPEG parseOfficeArtBlipJPEG(LEInputStream in) throws IOException  {
        OfficeArtBlipJPEG _s = new OfficeArtBlipJPEG();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E2 || _s.rh.recInstance == 0x6E3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x46A || _s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E2 || _s.rh.recInstance == 0x6E3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01D)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF01D for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipJPEG _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x46B || _s.rh.recInstance == 0x6E3) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        out.writeuint8(_s.tag);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtBlipPNG parseOfficeArtBlipPNG(LEInputStream in) throws IOException  {
        OfficeArtBlipPNG _s = new OfficeArtBlipPNG();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x6E0 || _s.rh.recInstance == 0x6E1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x6E0 || _s.rh.recInstance == 0x6E1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01E)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF01E for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipPNG _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x6E1) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        out.writeuint8(_s.tag);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtBlipDIB parseOfficeArtBlipDIB(LEInputStream in) throws IOException  {
        OfficeArtBlipDIB _s = new OfficeArtBlipDIB();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x7A8 || _s.rh.recInstance == 0x7A9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x7A8 || _s.rh.recInstance == 0x7A9 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF01F for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipDIB _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x7A9) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        out.writeuint8(_s.tag);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtBlipTIFF parseOfficeArtBlipTIFF(LEInputStream in) throws IOException  {
        OfficeArtBlipTIFF _s = new OfficeArtBlipTIFF();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x6E4 || _s.rh.recInstance == 0x6E5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x6E4 || _s.rh.recInstance == 0x6E5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF020)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF020 for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipTIFF _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x6E5) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        out.writeuint8(_s.tag);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    RECT parseRECT(LEInputStream in) throws IOException  {
        RECT _s = new RECT();
        _s.left = in.readint32();
        _s.top = in.readint32();
        _s.right = in.readint32();
        _s.bottom = in.readint32();
        return _s;
    }
    void write(RECT _s, LEOutputStream out) throws IOException  {
        out.writeint32(_s.left);
        out.writeint32(_s.top);
        out.writeint32(_s.right);
        out.writeint32(_s.bottom);
    }
    POINT parsePOINT(LEInputStream in) throws IOException  {
        POINT _s = new POINT();
        _s.x = in.readint32();
        _s.y = in.readint32();
        return _s;
    }
    void write(POINT _s, LEOutputStream out) throws IOException  {
        out.writeint32(_s.x);
        out.writeint32(_s.y);
    }
    PowerPointStructs parsePowerPointStructs(LEInputStream in) throws IOException  {
        PowerPointStructs _s = new PowerPointStructs();
        Object _m;
        boolean _atend;
        int _i;
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
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
    void write(PowerPointStructs _s, LEOutputStream out) throws IOException  {
        for (PowerPointStruct _i: _s.anon) {
            write(_i, out);
        }
    }
    SoundCollectionContainer parseSoundCollectionContainer(LEInputStream in) throws IOException  {
        SoundCollectionContainer _s = new SoundCollectionContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x7E4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x7E4 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SoundCollectionContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideHeadersFootersContainer parseSlideHeadersFootersContainer(LEInputStream in) throws IOException  {
        SlideHeadersFootersContainer _s = new SlideHeadersFootersContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFD9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFD9 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SlideHeadersFootersContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    NotesHeadersFootersContainer parseNotesHeadersFootersContainer(LEInputStream in) throws IOException  {
        NotesHeadersFootersContainer _s = new NotesHeadersFootersContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 4 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFD9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFD9 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(NotesHeadersFootersContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    PerSlideHeadersFootersContainer parsePerSlideHeadersFootersContainer(LEInputStream in) throws IOException  {
        PerSlideHeadersFootersContainer _s = new PerSlideHeadersFootersContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFD9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFD9 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(PerSlideHeadersFootersContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    EndDocumentAtom parseEndDocumentAtom(LEInputStream in) throws IOException  {
        EndDocumentAtom _s = new EndDocumentAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3EA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3EA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0 for value " + String.valueOf(_s.rh) );
        }
        return _s;
    }
    void write(EndDocumentAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
    }
    DocInfoListContainer parseDocInfoListContainer(LEInputStream in) throws IOException  {
        DocInfoListContainer _s = new DocInfoListContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x7D0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x7D0 for value " + String.valueOf(_s.rh) );
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                DocInfoListSubContainerOrAtom _t = parseDocInfoListSubContainerOrAtom(in);
                _s.rgChildRec.add(_t);
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
    void write(DocInfoListContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (DocInfoListSubContainerOrAtom _i: _s.rgChildRec) {
            write(_i, out);
        }
    }
    SlideViewInfoAtom parseSlideViewInfoAtom(LEInputStream in) throws IOException  {
        SlideViewInfoAtom _s = new SlideViewInfoAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3FE)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3FE for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 3 for value " + String.valueOf(_s.rh) );
        }
        _s.unused1 = in.readuint8();
        _s.fSnapToGrid = in.readuint8();
        _s.fSnapToShape = in.readuint8();
        return _s;
    }
    void write(SlideViewInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint8(_s.unused1);
        out.writeuint8(_s.fSnapToGrid);
        out.writeuint8(_s.fSnapToShape);
    }
    GuideAtom parseGuideAtom(LEInputStream in) throws IOException  {
        GuideAtom _s = new GuideAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 7 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3FB)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3FB for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 8 for value " + String.valueOf(_s.rh) );
        }
        _s.type = in.readuint32();
        if (!(_s.type == 0 || _s.type == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.type == 0 || _s.type == 1 for value " + String.valueOf(_s.type) );
        }
        _s.pos = in.readint32();
        if (!(_s.pos>=-15840)) {
            throw new IncorrectValueException(in.getPosition() + "_s.pos>=-15840 for value " + String.valueOf(_s.pos) );
        }
        if (!(_s.pos<=32255)) {
            throw new IncorrectValueException(in.getPosition() + "_s.pos<=32255 for value " + String.valueOf(_s.pos) );
        }
        return _s;
    }
    void write(GuideAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.type);
        out.writeint32(_s.pos);
    }
    DocProgTagsContainer parseDocProgTagsContainer(LEInputStream in) throws IOException  {
        DocProgTagsContainer _s = new DocProgTagsContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1388)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1388 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            DocProgTagsSubContainerOrAtom _t = parseDocProgTagsSubContainerOrAtom(in);
            _s.rgChildRec.add(_t);
        }
        return _s;
    }
    void write(DocProgTagsContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (DocProgTagsSubContainerOrAtom _i: _s.rgChildRec) {
            write(_i, out);
        }
    }
    DocProgBinaryTagContainerOrAtom parseDocProgBinaryTagContainerOrAtom(LEInputStream in) throws IOException  {
        DocProgBinaryTagContainerOrAtom _s = new DocProgBinaryTagContainerOrAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x138A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x138A for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(DocProgBinaryTagContainerOrAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SorterViewInfoContainer parseSorterViewInfoContainer(LEInputStream in) throws IOException  {
        SorterViewInfoContainer _s = new SorterViewInfoContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x408)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x408 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SorterViewInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    VBAInfoAtom parseVBAInfoAtom(LEInputStream in) throws IOException  {
        VBAInfoAtom _s = new VBAInfoAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x400)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x400 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0xC)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0xC for value " + String.valueOf(_s.rh) );
        }
        _s.persistIdRef = in.readuint32();
        _s.fHasMacros = in.readuint32();
        if (!(_s.fHasMacros == 0 || _s.fHasMacros == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fHasMacros == 0 || _s.fHasMacros == 1 for value " + String.valueOf(_s.fHasMacros) );
        }
        _s.version = in.readuint32();
        if (!(_s.version == 1 || _s.version == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.version == 1 || _s.version == 2 for value " + String.valueOf(_s.version) );
        }
        return _s;
    }
    void write(VBAInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.persistIdRef);
        out.writeuint32(_s.fHasMacros);
        out.writeuint32(_s.version);
    }
    MasterListWithTextContainer parseMasterListWithTextContainer(LEInputStream in) throws IOException  {
        MasterListWithTextContainer _s = new MasterListWithTextContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FF0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FF0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%28==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%28==0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen/28;
        _s.rgMasterPersistAtom = new MasterPersistAtom[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgMasterPersistAtom[_i] = parseMasterPersistAtom(in);
        }
        return _s;
    }
    void write(MasterListWithTextContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (MasterPersistAtom _i: _s.rgMasterPersistAtom) {
            write(_i, out);
        }
    }
    SlideListWithTextContainer parseSlideListWithTextContainer(LEInputStream in) throws IOException  {
        SlideListWithTextContainer _s = new SlideListWithTextContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FF0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FF0 for value " + String.valueOf(_s.rh) );
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                SlideListWithTextSubContainerOrAtom _t = parseSlideListWithTextSubContainerOrAtom(in);
                _s.rgChildRec.add(_t);
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
    void write(SlideListWithTextContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (SlideListWithTextSubContainerOrAtom _i: _s.rgChildRec) {
            write(_i, out);
        }
    }
    NotesListWithTextContainer parseNotesListWithTextContainer(LEInputStream in) throws IOException  {
        NotesListWithTextContainer _s = new NotesListWithTextContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FF0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FF0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(NotesListWithTextContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    TextHeaderAtom parseTextHeaderAtom(LEInputStream in) throws IOException  {
        TextHeaderAtom _s = new TextHeaderAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF9F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF9F for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.textType = in.readuint32();
        return _s;
    }
    void write(TextHeaderAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.textType);
    }
    TextCharsAtom parseTextCharsAtom(LEInputStream in) throws IOException  {
        TextCharsAtom _s = new TextCharsAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFA0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFA0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2==0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen/2;
        _s.textChars = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.textChars[_i] = in.readuint16();
            if (!(_s.textChars[_i] != 0)) {
                throw new IncorrectValueException(in.getPosition() + "_s.textChars[_i] != 0 for value " + String.valueOf(_s.textChars[_i]) );
            }
        }
        return _s;
    }
    void write(TextCharsAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (int _i: _s.textChars) {
            out.writeuint16(_i);
        }
    }
    TextBytesAtom parseTextBytesAtom(LEInputStream in) throws IOException  {
        TextBytesAtom _s = new TextBytesAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFA8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFA8 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.textChars = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.textChars[_i] = in.readuint8();
            if (!(_s.textChars[_i] != 0)) {
                throw new IncorrectValueException(in.getPosition() + "_s.textChars[_i] != 0 for value " + String.valueOf(_s.textChars[_i]) );
            }
        }
        return _s;
    }
    void write(TextBytesAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.textChars) {
            out.writeuint8(_i);
        }
    }
    MasterTextPropAtom parseMasterTextPropAtom(LEInputStream in) throws IOException  {
        MasterTextPropAtom _s = new MasterTextPropAtom();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFA2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFA2 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            MasterTextPropRun _t = parseMasterTextPropRun(in);
            _s.rgMasterTextPropRun.add(_t);
        }
        return _s;
    }
    void write(MasterTextPropAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (MasterTextPropRun _i: _s.rgMasterTextPropRun) {
            write(_i, out);
        }
    }
    MasterTextPropRun parseMasterTextPropRun(LEInputStream in) throws IOException  {
        MasterTextPropRun _s = new MasterTextPropRun();
        _s.count = in.readuint32();
        _s.indentLevel = in.readuint16();
        if (!(_s.indentLevel<=4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.indentLevel<=4 for value " + String.valueOf(_s.indentLevel) );
        }
        return _s;
    }
    void write(MasterTextPropRun _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.count);
        out.writeuint16(_s.indentLevel);
    }
    StyleTextPropAtom parseStyleTextPropAtom(LEInputStream in) throws IOException  {
        StyleTextPropAtom _s = new StyleTextPropAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFA1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFA1 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(StyleTextPropAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideNumberMCAtom parseSlideNumberMCAtom(LEInputStream in) throws IOException  {
        SlideNumberMCAtom _s = new SlideNumberMCAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFD8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFD8 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        return _s;
    }
    void write(SlideNumberMCAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
    }
    DateTimeMCAtom parseDateTimeMCAtom(LEInputStream in) throws IOException  {
        DateTimeMCAtom _s = new DateTimeMCAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFF7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFF7 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 8 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        _s.index = in.readuint8();
        _c = 3;
        _s.unused = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.unused[_i] = in.readuint8();
        }
        return _s;
    }
    void write(DateTimeMCAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
        out.writeuint8(_s.index);
        for (byte _i: _s.unused) {
            out.writeuint8(_i);
        }
    }
    GenericDateMCAtom parseGenericDateMCAtom(LEInputStream in) throws IOException  {
        GenericDateMCAtom _s = new GenericDateMCAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFF8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFF8 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        return _s;
    }
    void write(GenericDateMCAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
    }
    HeaderMCAtom parseHeaderMCAtom(LEInputStream in) throws IOException  {
        HeaderMCAtom _s = new HeaderMCAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFF9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFF9 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        return _s;
    }
    void write(HeaderMCAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
    }
    FooterMCAtom parseFooterMCAtom(LEInputStream in) throws IOException  {
        FooterMCAtom _s = new FooterMCAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFFA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFFA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        return _s;
    }
    void write(FooterMCAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
    }
    RTFDateTimeMCAtom parseRTFDateTimeMCAtom(LEInputStream in) throws IOException  {
        RTFDateTimeMCAtom _s = new RTFDateTimeMCAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1015)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1015 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x84)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x84 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        _c = 128;
        _s.format = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.format[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RTFDateTimeMCAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
        for (byte _i: _s.format) {
            out.writeuint8(_i);
        }
    }
    TextBookmarkAtom parseTextBookmarkAtom(LEInputStream in) throws IOException  {
        TextBookmarkAtom _s = new TextBookmarkAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFA7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFA7 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0xC)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0xC for value " + String.valueOf(_s.rh) );
        }
        _s.begin = in.readint32();
        _s.end = in.readint32();
        _s.bookmarkID = in.readint32();
        return _s;
    }
    void write(TextBookmarkAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.begin);
        out.writeint32(_s.end);
        out.writeint32(_s.bookmarkID);
    }
    MouseTextInteractiveInfoAtom parseMouseTextInteractiveInfoAtom(LEInputStream in) throws IOException  {
        MouseTextInteractiveInfoAtom _s = new MouseTextInteractiveInfoAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFDF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFDF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 8 for value " + String.valueOf(_s.rh) );
        }
        _c = 8;
        _s.range = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.range[_i] = in.readuint8();
        }
        return _s;
    }
    void write(MouseTextInteractiveInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.range) {
            out.writeuint8(_i);
        }
    }
    SlideId parseSlideId(LEInputStream in) throws IOException  {
        SlideId _s = new SlideId();
        _s.slideId = in.readuint32();
        if (!(_s.slideId>=100)) {
            throw new IncorrectValueException(in.getPosition() + "_s.slideId>=100 for value " + String.valueOf(_s.slideId) );
        }
        if (!(_s.slideId<2147483647)) {
            throw new IncorrectValueException(in.getPosition() + "_s.slideId<2147483647 for value " + String.valueOf(_s.slideId) );
        }
        return _s;
    }
    void write(SlideId _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.slideId);
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
    void write(TabStops _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.count);
        for (TabStop _i: _s.rgTabStop) {
            write(_i, out);
        }
    }
    TabStop parseTabStop(LEInputStream in) throws IOException  {
        TabStop _s = new TabStop();
        _s.position = in.readint16();
        _s.type = in.readuint16();
        return _s;
    }
    void write(TabStop _s, LEOutputStream out) throws IOException  {
        out.writeint16(_s.position);
        out.writeuint16(_s.type);
    }
    ColorIndexStruct parseColorIndexStruct(LEInputStream in) throws IOException  {
        ColorIndexStruct _s = new ColorIndexStruct();
        _s.red = in.readuint8();
        _s.green = in.readuint8();
        _s.blue = in.readuint8();
        _s.index = in.readuint8();
        return _s;
    }
    void write(ColorIndexStruct _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.red);
        out.writeuint8(_s.green);
        out.writeuint8(_s.blue);
        out.writeuint8(_s.index);
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
    void write(BulletFlags _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.fHasBullet);
        out.writebit(_s.fBulletHasFont);
        out.writebit(_s.fBulletHasColor);
        out.writebit(_s.fBulletHasSize);
        out.writeuint12(_s.reserved);
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
    void write(PFMasks _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.hasBullet);
        out.writebit(_s.bulletHasFont);
        out.writebit(_s.bulletHasColor);
        out.writebit(_s.bulletHasSize);
        out.writebit(_s.bulletFont);
        out.writebit(_s.bulletColor);
        out.writebit(_s.bulletSize);
        out.writebit(_s.bulletChar);
        out.writebit(_s.leftMargin);
        out.writebit(_s.unused);
        out.writebit(_s.indent);
        out.writebit(_s.align);
        out.writebit(_s.lineSpacing);
        out.writebit(_s.spaceBefore);
        out.writebit(_s.spaceAfter);
        out.writebit(_s.defaultTabSize);
        out.writebit(_s.fontAlign);
        out.writebit(_s.charWrap);
        out.writebit(_s.wordWrap);
        out.writebit(_s.overflow);
        out.writebit(_s.tabStops);
        out.writebit(_s.textDirection);
        out.writebit(_s.reserved);
        out.writebit(_s.bulletBlip);
        out.writebit(_s.bulletScheme);
        out.writebit(_s.bulletHasScheme);
        out.writeuint6(_s.reserved2);
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
    void write(CFMasks _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.bold);
        out.writebit(_s.italic);
        out.writebit(_s.underline);
        out.writebit(_s.unused1);
        out.writebit(_s.shadow);
        out.writebit(_s.fehint);
        out.writebit(_s.unused2);
        out.writebit(_s.kumi);
        out.writebit(_s.unused3);
        out.writebit(_s.emboss);
        out.writeuint4(_s.fHasStyle);
        out.writeuint2(_s.unused4);
        out.writebit(_s.typeface);
        out.writebit(_s.size);
        out.writebit(_s.color);
        out.writebit(_s.position);
        out.writebit(_s.pp10ext);
        out.writebit(_s.oldEATypeface);
        out.writebit(_s.ansiTypeface);
        out.writebit(_s.symbolTypeface);
        out.writebit(_s.newEATypeface);
        out.writebit(_s.csTypeface);
        out.writebit(_s.pp11ext);
        out.writeuint5(_s.reserved);
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
    void write(CFStyle _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.bold);
        out.writebit(_s.italic);
        out.writebit(_s.underline);
        out.writebit(_s.unused1);
        out.writebit(_s.shadow);
        out.writebit(_s.fehint);
        out.writebit(_s.unused2);
        out.writebit(_s.kumi);
        out.writebit(_s.unused3);
        out.writebit(_s.emboss);
        out.writeuint4(_s.pp9rt);
        out.writeuint2(_s.unused4);
    }
    FontCollectionContainer parseFontCollectionContainer(LEInputStream in) throws IOException  {
        FontCollectionContainer _s = new FontCollectionContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x07D5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x07D5 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            FontCollectionEntry _t = parseFontCollectionEntry(in);
            _s.rgFontCollectionEntry.add(_t);
        }
        return _s;
    }
    void write(FontCollectionContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (FontCollectionEntry _i: _s.rgFontCollectionEntry) {
            write(_i, out);
        }
    }
    FontEntityAtom parseFontEntityAtom(LEInputStream in) throws IOException  {
        FontEntityAtom _s = new FontEntityAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance>=0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance<=128)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance<=128 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFB7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFB7 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x44)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x44 for value " + String.valueOf(_s.rh) );
        }
        _c = 32;
        _s.lfFaceName = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.lfFaceName[_i] = in.readuint16();
        }
        _s.lfCharSet = in.readuint8();
        _s.fEmbedSubsetted = in.readbit();
        _s.unused = in.readuint7();
        _s.rasterFontType = in.readbit();
        _s.deviceFontType = in.readbit();
        _s.truetypeFontType = in.readbit();
        _s.fNoFontSubstitution = in.readbit();
        _s.reserved = in.readuint4();
        if (!(_s.reserved == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved == 0 for value " + String.valueOf(_s.reserved) );
        }
        _s.lfPitchAndFamily = in.readuint8();
        return _s;
    }
    void write(FontEntityAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (int _i: _s.lfFaceName) {
            out.writeuint16(_i);
        }
        out.writeuint8(_s.lfCharSet);
        out.writebit(_s.fEmbedSubsetted);
        out.writeuint7(_s.unused);
        out.writebit(_s.rasterFontType);
        out.writebit(_s.deviceFontType);
        out.writebit(_s.truetypeFontType);
        out.writebit(_s.fNoFontSubstitution);
        out.writeuint4(_s.reserved);
        out.writeuint8(_s.lfPitchAndFamily);
    }
    FontEmbedDataBlob parseFontEmbedDataBlob(LEInputStream in) throws IOException  {
        FontEmbedDataBlob _s = new FontEmbedDataBlob();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance>=0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance<=3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance<=3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFB8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFB8 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.data = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.data[_i] = in.readuint8();
        }
        return _s;
    }
    void write(FontEmbedDataBlob _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.data) {
            out.writeuint8(_i);
        }
    }
    KinsokuAtom parseKinsokuAtom(LEInputStream in) throws IOException  {
        KinsokuAtom _s = new KinsokuAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FD2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FD2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.level = in.readuint32();
        if (!(_s.level == 0 || _s.level == 1 || _s.level == 2 || _s.level == 128)) {
            throw new IncorrectValueException(in.getPosition() + "_s.level == 0 || _s.level == 1 || _s.level == 2 || _s.level == 128 for value " + String.valueOf(_s.level) );
        }
        return _s;
    }
    void write(KinsokuAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.level);
    }
    KinsokuLeadingAtom parseKinsokuLeadingAtom(LEInputStream in) throws IOException  {
        KinsokuLeadingAtom _s = new KinsokuLeadingAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFBA for value " + String.valueOf(_s.rh) );
        }
        _s.kinsokuLeading = in.readuint16();
        return _s;
    }
    void write(KinsokuLeadingAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint16(_s.kinsokuLeading);
    }
    KinsokuFollowingAtom parseKinsokuFollowingAtom(LEInputStream in) throws IOException  {
        KinsokuFollowingAtom _s = new KinsokuFollowingAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1 )) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1  for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFBA for value " + String.valueOf(_s.rh) );
        }
        _s.kinsokuFollowing = in.readuint16();
        return _s;
    }
    void write(KinsokuFollowingAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint16(_s.kinsokuFollowing);
    }
    TextSpecialInfoAtom parseTextSpecialInfoAtom(LEInputStream in) throws IOException  {
        TextSpecialInfoAtom _s = new TextSpecialInfoAtom();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFAA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFAA for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            TextSIRun _t = parseTextSIRun(in);
            _s.rgSIRun.add(_t);
        }
        return _s;
    }
    void write(TextSpecialInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (TextSIRun _i: _s.rgSIRun) {
            write(_i, out);
        }
    }
    SmartTags parseSmartTags(LEInputStream in) throws IOException  {
        SmartTags _s = new SmartTags();
        int _c;
        _s.count = in.readuint32();
        _c = _s.count;
        _s.rgSmartTagIndex = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgSmartTagIndex[_i] = in.readuint32();
        }
        return _s;
    }
    void write(SmartTags _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.count);
        for (int _i: _s.rgSmartTagIndex) {
            out.writeuint32(_i);
        }
    }
    ExOleEmbedAtom parseExOleEmbedAtom(LEInputStream in) throws IOException  {
        ExOleEmbedAtom _s = new ExOleEmbedAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FCD)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FCD for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x8 for value " + String.valueOf(_s.rh) );
        }
        _s.exColorFollow = in.readuint32();
        if (!(_s.exColorFollow == 0 || _s.exColorFollow == 1 || _s.exColorFollow == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.exColorFollow == 0 || _s.exColorFollow == 1 || _s.exColorFollow == 2 for value " + String.valueOf(_s.exColorFollow) );
        }
        _s.fCantLockServer = in.readuint8();
        _s.fNoSizeToServer = in.readuint8();
        _s.fIsTable = in.readuint8();
        _s.unused = in.readuint8();
        return _s;
    }
    void write(ExOleEmbedAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.exColorFollow);
        out.writeuint8(_s.fCantLockServer);
        out.writeuint8(_s.fNoSizeToServer);
        out.writeuint8(_s.fIsTable);
        out.writeuint8(_s.unused);
    }
    PointStruct parsePointStruct(LEInputStream in) throws IOException  {
        PointStruct _s = new PointStruct();
        _s.x = in.readint32();
        _s.y = in.readint32();
        return _s;
    }
    void write(PointStruct _s, LEOutputStream out) throws IOException  {
        out.writeint32(_s.x);
        out.writeint32(_s.y);
    }
    RatioStruct parseRatioStruct(LEInputStream in) throws IOException  {
        RatioStruct _s = new RatioStruct();
        _s.numer = in.readint32();
        _s.denom = in.readint32();
        if (!(_s.denom!= 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.denom!= 0 for value " + String.valueOf(_s.denom) );
        }
        return _s;
    }
    void write(RatioStruct _s, LEOutputStream out) throws IOException  {
        out.writeint32(_s.numer);
        out.writeint32(_s.denom);
    }
    PersistDirectoryAtom parsePersistDirectoryAtom(LEInputStream in) throws IOException  {
        PersistDirectoryAtom _s = new PersistDirectoryAtom();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1772)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1772 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            PersistDirectoryEntry _t = parsePersistDirectoryEntry(in);
            _s.rgPersistDirEntry.add(_t);
        }
        return _s;
    }
    void write(PersistDirectoryAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (PersistDirectoryEntry _i: _s.rgPersistDirEntry) {
            write(_i, out);
        }
    }
    UnknownDocumentContainerChild parseUnknownDocumentContainerChild(LEInputStream in) throws IOException  {
        UnknownDocumentContainerChild _s = new UnknownDocumentContainerChild();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1773)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1773 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownDocumentContainerChild _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UnknownDocumentContainerChild2 parseUnknownDocumentContainerChild2(LEInputStream in) throws IOException  {
        UnknownDocumentContainerChild2 _s = new UnknownDocumentContainerChild2();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1788)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1788 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownDocumentContainerChild2 _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UnknownDocumentContainerChild3 parseUnknownDocumentContainerChild3(LEInputStream in) throws IOException  {
        UnknownDocumentContainerChild3 _s = new UnknownDocumentContainerChild3();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 4 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x101A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x101A for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownDocumentContainerChild3 _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UnknownDocumentContainerChild4 parseUnknownDocumentContainerChild4(LEInputStream in) throws IOException  {
        UnknownDocumentContainerChild4 _s = new UnknownDocumentContainerChild4();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x41A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x41A for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownDocumentContainerChild4 _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UnknownOfficeArtClientDataChild parseUnknownOfficeArtClientDataChild(LEInputStream in) throws IOException  {
        UnknownOfficeArtClientDataChild _s = new UnknownOfficeArtClientDataChild();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFE8 || _s.rh.recType == 0x1019)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFE8 || _s.rh.recType == 0x1019 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownOfficeArtClientDataChild _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UnknownSlideContainerChild parseUnknownSlideContainerChild(LEInputStream in) throws IOException  {
        UnknownSlideContainerChild _s = new UnknownSlideContainerChild();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x101D)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x101D for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownSlideContainerChild _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    PersistDirectoryEntry parsePersistDirectoryEntry(LEInputStream in) throws IOException  {
        PersistDirectoryEntry _s = new PersistDirectoryEntry();
        int _c;
        _s.persistId = in.readuint20();
        _s.cPersist = in.readuint12();
        _c = _s.cPersist;
        _s.rgPersistOffset = new PersistOffsetEntry[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgPersistOffset[_i] = parsePersistOffsetEntry(in);
        }
        return _s;
    }
    void write(PersistDirectoryEntry _s, LEOutputStream out) throws IOException  {
        out.writeuint20(_s.persistId);
        out.writeuint12(_s.cPersist);
        for (PersistOffsetEntry _i: _s.rgPersistOffset) {
            write(_i, out);
        }
    }
    PersistOffsetEntry parsePersistOffsetEntry(LEInputStream in) throws IOException  {
        PersistOffsetEntry _s = new PersistOffsetEntry();
        _s.anon = in.readuint32();
        return _s;
    }
    void write(PersistOffsetEntry _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.anon);
    }
    PersistIdRef parsePersistIdRef(LEInputStream in) throws IOException  {
        PersistIdRef _s = new PersistIdRef();
        _s.anon = in.readuint32();
        return _s;
    }
    void write(PersistIdRef _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.anon);
    }
    SchemeListElementColorSchemeAtom parseSchemeListElementColorSchemeAtom(LEInputStream in) throws IOException  {
        SchemeListElementColorSchemeAtom _s = new SchemeListElementColorSchemeAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 6)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 6 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x7F0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x7F0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x20)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x20 for value " + String.valueOf(_s.rh) );
        }
        _c = 8;
        _s.rgSchemeColor = new ColorStruct[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgSchemeColor[_i] = parseColorStruct(in);
        }
        return _s;
    }
    void write(SchemeListElementColorSchemeAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (ColorStruct _i: _s.rgSchemeColor) {
            write(_i, out);
        }
    }
    RoundTripOArtTextStyles12Atom parseRoundTripOArtTextStyles12Atom(LEInputStream in) throws IOException  {
        RoundTripOArtTextStyles12Atom _s = new RoundTripOArtTextStyles12Atom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x423)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x423 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RoundTripOArtTextStyles12Atom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideNameAtom parseSlideNameAtom(LEInputStream in) throws IOException  {
        SlideNameAtom _s = new SlideNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2==0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SlideNameAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideProgTagsContainer parseSlideProgTagsContainer(LEInputStream in) throws IOException  {
        SlideProgTagsContainer _s = new SlideProgTagsContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1388)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1388 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            SlideProgTagsSubContainerOrAtom _t = parseSlideProgTagsSubContainerOrAtom(in);
            _s.rgTypeRec.add(_t);
        }
        return _s;
    }
    void write(SlideProgTagsContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (SlideProgTagsSubContainerOrAtom _i: _s.rgTypeRec) {
            write(_i, out);
        }
    }
    SlideProgBinaryTagContainer parseSlideProgBinaryTagContainer(LEInputStream in) throws IOException  {
        SlideProgBinaryTagContainer _s = new SlideProgBinaryTagContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x138A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x138A for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SlideProgBinaryTagContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    TagNameAtom parseTagNameAtom(LEInputStream in) throws IOException  {
        TagNameAtom _s = new TagNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFBA for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen/2;
        _s.tagName = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.tagName[_i] = in.readuint16();
        }
        return _s;
    }
    void write(TagNameAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (int _i: _s.tagName) {
            out.writeuint16(_i);
        }
    }
    TagValueAtom parseTagValueAtom(LEInputStream in) throws IOException  {
        TagValueAtom _s = new TagValueAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFBA for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen/2;
        _s.tagValue = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.tagValue[_i] = in.readuint16();
        }
        return _s;
    }
    void write(TagValueAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (int _i: _s.tagValue) {
            out.writeuint16(_i);
        }
    }
    RoundTripMainMasterRecord parseRoundTripMainMasterRecord(LEInputStream in) throws IOException  {
        RoundTripMainMasterRecord _s = new RoundTripMainMasterRecord();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recType == 0x41C || _s.rh.recType == 0x40E || _s.rh.recType == 0x040F || _s.rh.recType == 0x41E || _s.rh.recType == 0x0423 || _s.rh.recType == 0x2B0D || _s.rh.recType == 0x2B0B || _s.rh.recType == 0x041D)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x41C || _s.rh.recType == 0x40E || _s.rh.recType == 0x040F || _s.rh.recType == 0x41E || _s.rh.recType == 0x0423 || _s.rh.recType == 0x2B0D || _s.rh.recType == 0x2B0B || _s.rh.recType == 0x041D for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RoundTripMainMasterRecord _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    TemplateNameAtom parseTemplateNameAtom(LEInputStream in) throws IOException  {
        TemplateNameAtom _s = new TemplateNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2==0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen/2;
        _s.templateName = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.templateName[_i] = in.readuint16();
        }
        return _s;
    }
    void write(TemplateNameAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (int _i: _s.templateName) {
            out.writeuint16(_i);
        }
    }
    RoundTripSlideSyncInfo12Container parseRoundTripSlideSyncInfo12Container(LEInputStream in) throws IOException  {
        RoundTripSlideSyncInfo12Container _s = new RoundTripSlideSyncInfo12Container();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3714)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3714 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RoundTripSlideSyncInfo12Container _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    NotesContainer parseNotesContainer(LEInputStream in) throws IOException  {
        NotesContainer _s = new NotesContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03F0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03F0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(NotesContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    HandoutContainer parseHandoutContainer(LEInputStream in) throws IOException  {
        HandoutContainer _s = new HandoutContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FC9 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(HandoutContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExControlStg parseExControlStg(LEInputStream in) throws IOException  {
        ExControlStg _s = new ExControlStg();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1011)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1011 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExControlStg _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExOleObjStg parseExOleObjStg(LEInputStream in) throws IOException  {
        ExOleObjStg _s = new ExOleObjStg();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1011)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1011 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExOleObjStg _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UserEditAtom parseUserEditAtom(LEInputStream in) throws IOException  {
        UserEditAtom _s = new UserEditAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FF5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FF5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x1C || _s.rh.recLen == 0x20)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x1C || _s.rh.recLen == 0x20 for value " + String.valueOf(_s.rh) );
        }
        _s.lastSlideIdRef = in.readuint32();
        _s.version = in.readuint16();
        _s.minorVersion = in.readuint8();
        if (!(_s.minorVersion == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.minorVersion == 0 for value " + String.valueOf(_s.minorVersion) );
        }
        _s.majorVersion = in.readuint8();
        if (!(_s.majorVersion == 3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.majorVersion == 3 for value " + String.valueOf(_s.majorVersion) );
        }
        _s.offsetLastEdit = in.readuint32();
        _s.offsetPersistDirectory = in.readuint32();
        _s.docPersistIdRef = in.readuint32();
        if (!(_s.docPersistIdRef == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.docPersistIdRef == 1 for value " + String.valueOf(_s.docPersistIdRef) );
        }
        _s.persistIdSeed = in.readuint32();
        _s.lastView = in.readuint16();
        if (!(_s.lastView<=18)) {
            throw new IncorrectValueException(in.getPosition() + "_s.lastView<=18 for value " + String.valueOf(_s.lastView) );
        }
        _s.unused = in.readuint16();
        if (_s.rh.recLen==32) {
            _s.encryptSessionPersistIdRef = in.readuint32();
        }
        return _s;
    }
    void write(UserEditAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.lastSlideIdRef);
        out.writeuint16(_s.version);
        out.writeuint8(_s.minorVersion);
        out.writeuint8(_s.majorVersion);
        out.writeuint32(_s.offsetLastEdit);
        out.writeuint32(_s.offsetPersistDirectory);
        out.writeuint32(_s.docPersistIdRef);
        out.writeuint32(_s.persistIdSeed);
        out.writeuint16(_s.lastView);
        out.writeuint16(_s.unused);
        if (_s.rh.recLen==32) {
            out.writeuint32(_s.encryptSessionPersistIdRef);
        }
    }
    VbaProjectStg parseVbaProjectStg(LEInputStream in) throws IOException  {
        VbaProjectStg _s = new VbaProjectStg();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1011)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1011 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(VbaProjectStg _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideProgTagscontainer parseSlideProgTagscontainer(LEInputStream in) throws IOException  {
        SlideProgTagscontainer _s = new SlideProgTagscontainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1388)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1388 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SlideProgTagscontainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideAtom parseSlideAtom(LEInputStream in) throws IOException  {
        SlideAtom _s = new SlideAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03EF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03EF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x18)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x18 for value " + String.valueOf(_s.rh) );
        }
        _s.geom = in.readuint32();
        _c = 8;
        _s.rgPlaceholderTypes = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgPlaceholderTypes[_i] = in.readuint8();
        }
        _s.masterIdRef = in.readuint32();
        _s.notesIdRef = in.readuint32();
        _s.slideFlags = in.readuint16();
        _s.unused = in.readuint16();
        return _s;
    }
    void write(SlideAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.geom);
        for (byte _i: _s.rgPlaceholderTypes) {
            out.writeuint8(_i);
        }
        out.writeuint32(_s.masterIdRef);
        out.writeuint32(_s.notesIdRef);
        out.writeuint16(_s.slideFlags);
        out.writeuint16(_s.unused);
    }
    SlideShowSlideInfoAtom parseSlideShowSlideInfoAtom(LEInputStream in) throws IOException  {
        SlideShowSlideInfoAtom _s = new SlideShowSlideInfoAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03F9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03F9 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
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
        _s.unused = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.unused[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SlideShowSlideInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.slidetime);
        out.writeuint32(_s.slideIdRef);
        out.writeuint8(_s.effectDirection);
        out.writeuint8(_s.effectType);
        out.writebit(_s.fManualAdvance);
        out.writebit(_s.reserved);
        out.writebit(_s.fHidden);
        out.writebit(_s.reserved2);
        out.writebit(_s.fSound);
        out.writebit(_s.reserved3);
        out.writebit(_s.fLoopSound);
        out.writebit(_s.reserved4);
        out.writebit(_s.fStopSound);
        out.writebit(_s.freserved5);
        out.writebit(_s.fAutoAdvance);
        out.writebit(_s.reserved6);
        out.writebit(_s.fCursorVisible);
        out.writeuint3(_s.reserved7);
        out.writeuint8(_s.speed);
        for (byte _i: _s.unused) {
            out.writeuint8(_i);
        }
    }
    SlideShowDocInfoAtom parseSlideShowDocInfoAtom(LEInputStream in) throws IOException  {
        SlideShowDocInfoAtom _s = new SlideShowDocInfoAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0401)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0401 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x50)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x50 for value " + String.valueOf(_s.rh) );
        }
        _c = 0x50;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SlideShowDocInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SlideSchemeColorSchemeAtom parseSlideSchemeColorSchemeAtom(LEInputStream in) throws IOException  {
        SlideSchemeColorSchemeAtom _s = new SlideSchemeColorSchemeAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x07F0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x07F0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x20)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x20 for value " + String.valueOf(_s.rh) );
        }
        _c = 8;
        _s.rgSchemeColor = new ColorStruct[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgSchemeColor[_i] = parseColorStruct(in);
        }
        return _s;
    }
    void write(SlideSchemeColorSchemeAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (ColorStruct _i: _s.rgSchemeColor) {
            write(_i, out);
        }
    }
    RoundTripSlideRecord parseRoundTripSlideRecord(LEInputStream in) throws IOException  {
        RoundTripSlideRecord _s = new RoundTripSlideRecord();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recType == 0x40E || _s.rh.recType == 0x40F || _s.rh.recType == 0x41D || _s.rh.recType == 0x3714 || _s.rh.recType == 0x2B0D || _s.rh.recType == 0x2B0B || _s.rh.recType == 0x422)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x40E || _s.rh.recType == 0x40F || _s.rh.recType == 0x41D || _s.rh.recType == 0x3714 || _s.rh.recType == 0x2B0D || _s.rh.recType == 0x2B0B || _s.rh.recType == 0x422 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RoundTripSlideRecord _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    NamedShowsContainer parseNamedShowsContainer(LEInputStream in) throws IOException  {
        NamedShowsContainer _s = new NamedShowsContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x410)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x410 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(NamedShowsContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    SummaryContainer parseSummaryContainer(LEInputStream in) throws IOException  {
        SummaryContainer _s = new SummaryContainer();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x402)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x402 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SummaryContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    DocRoutingSlipAtom parseDocRoutingSlipAtom(LEInputStream in) throws IOException  {
        DocRoutingSlipAtom _s = new DocRoutingSlipAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x406)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x406 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(DocRoutingSlipAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    PrintOptionsAtom parsePrintOptionsAtom(LEInputStream in) throws IOException  {
        PrintOptionsAtom _s = new PrintOptionsAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1770)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1770 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 5 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(PrintOptionsAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    RoundTripCustomTableStyles12Atom parseRoundTripCustomTableStyles12Atom(LEInputStream in) throws IOException  {
        RoundTripCustomTableStyles12Atom _s = new RoundTripCustomTableStyles12Atom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0 || _s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 || _s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x428)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x428 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RoundTripCustomTableStyles12Atom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ColorStruct parseColorStruct(LEInputStream in) throws IOException  {
        ColorStruct _s = new ColorStruct();
        _s.red = in.readuint8();
        _s.green = in.readuint8();
        _s.blue = in.readuint8();
        _s.unused = in.readuint8();
        return _s;
    }
    void write(ColorStruct _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.red);
        out.writeuint8(_s.green);
        out.writeuint8(_s.blue);
        out.writeuint8(_s.unused);
    }
    ExObjListAtom parseExObjListAtom(LEInputStream in) throws IOException  {
        ExObjListAtom _s = new ExObjListAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x040A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x040A for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.exObjIdSeed = in.readint32();
        if (!(_s.exObjIdSeed>=1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.exObjIdSeed>=1 for value " + String.valueOf(_s.exObjIdSeed) );
        }
        return _s;
    }
    void write(ExObjListAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.exObjIdSeed);
    }
    ExAviMovieContainer parseExAviMovieContainer(LEInputStream in) throws IOException  {
        ExAviMovieContainer _s = new ExAviMovieContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1006)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1006 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExAviMovieContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExCDAudioContainer parseExCDAudioContainer(LEInputStream in) throws IOException  {
        ExCDAudioContainer _s = new ExCDAudioContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x100E)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x100E for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExCDAudioContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExControlContainer parseExControlContainer(LEInputStream in) throws IOException  {
        ExControlContainer _s = new ExControlContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFEE)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFEE for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExControlContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExHyperlinkContainer parseExHyperlinkContainer(LEInputStream in) throws IOException  {
        ExHyperlinkContainer _s = new ExHyperlinkContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFD7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFD7 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExHyperlinkContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExMCIMovieContainer parseExMCIMovieContainer(LEInputStream in) throws IOException  {
        ExMCIMovieContainer _s = new ExMCIMovieContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1007)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1007 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExMCIMovieContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExMIDIAudioContainer parseExMIDIAudioContainer(LEInputStream in) throws IOException  {
        ExMIDIAudioContainer _s = new ExMIDIAudioContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x100D)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x100D for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExMIDIAudioContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExWAVAudioEmbeddedContainer parseExWAVAudioEmbeddedContainer(LEInputStream in) throws IOException  {
        ExWAVAudioEmbeddedContainer _s = new ExWAVAudioEmbeddedContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x100F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x100F for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExWAVAudioEmbeddedContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExWAVAudioLinkContainer parseExWAVAudioLinkContainer(LEInputStream in) throws IOException  {
        ExWAVAudioLinkContainer _s = new ExWAVAudioLinkContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1010)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1010 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExWAVAudioLinkContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    UnknownExObjListSubContainerChild parseUnknownExObjListSubContainerChild(LEInputStream in) throws IOException  {
        UnknownExObjListSubContainerChild _s = new UnknownExObjListSubContainerChild();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFEA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFEA for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(UnknownExObjListSubContainerChild _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExOleLinkAtom parseExOleLinkAtom(LEInputStream in) throws IOException  {
        ExOleLinkAtom _s = new ExOleLinkAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FD1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FD1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xC)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xC for value " + String.valueOf(_s.rh) );
        }
        _s.slideIdRef = in.readuint32();
        _s.oleUpdateMode = in.readuint32();
        _s.unused = in.readuint32();
        return _s;
    }
    void write(ExOleLinkAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.slideIdRef);
        out.writeuint32(_s.oleUpdateMode);
        out.writeuint32(_s.unused);
    }
    ExOleObjAtom parseExOleObjAtom(LEInputStream in) throws IOException  {
        ExOleObjAtom _s = new ExOleObjAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FC3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x18)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x18 for value " + String.valueOf(_s.rh) );
        }
        _s.drawAspect = in.readuint32();
        _s.type = in.readuint32();
        _s.exObjId = in.readuint32();
        _s.subType = in.readuint32();
        _s.persistIdRef = in.readuint32();
        _s.unused = in.readuint32();
        return _s;
    }
    void write(ExOleObjAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.drawAspect);
        out.writeuint32(_s.type);
        out.writeuint32(_s.exObjId);
        out.writeuint32(_s.subType);
        out.writeuint32(_s.persistIdRef);
        out.writeuint32(_s.unused);
    }
    MenuNameAtom parseMenuNameAtom(LEInputStream in) throws IOException  {
        MenuNameAtom _s = new MenuNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2 == 0 )) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2 == 0  for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.menuName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.menuName[_i] = in.readuint8();
        }
        return _s;
    }
    void write(MenuNameAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.menuName) {
            out.writeuint8(_i);
        }
    }
    ProgIDAtom parseProgIDAtom(LEInputStream in) throws IOException  {
        ProgIDAtom _s = new ProgIDAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2 == 0 )) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2 == 0  for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.progId = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.progId[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ProgIDAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.progId) {
            out.writeuint8(_i);
        }
    }
    ClipboardNameAtom parseClipboardNameAtom(LEInputStream in) throws IOException  {
        ClipboardNameAtom _s = new ClipboardNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2 == 0 )) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2 == 0  for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.clipboardName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.clipboardName[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ClipboardNameAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.clipboardName) {
            out.writeuint8(_i);
        }
    }
    MetafileBlob parseMetafileBlob(LEInputStream in) throws IOException  {
        MetafileBlob _s = new MetafileBlob();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FC1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen>16)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen>16 for value " + String.valueOf(_s.rh) );
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
    void write(MetafileBlob _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint16(_s.mm);
        out.writeint16(_s.xExt);
        out.writeint16(_s.yExt);
        for (byte _i: _s.data) {
            out.writeuint8(_i);
        }
    }
    OfficeArtFDGG parseOfficeArtFDGG(LEInputStream in) throws IOException  {
        OfficeArtFDGG _s = new OfficeArtFDGG();
        _s.spidMax = in.readuint32();
        if (!(_s.spidMax<67098623)) {
            throw new IncorrectValueException(in.getPosition() + "_s.spidMax<67098623 for value " + String.valueOf(_s.spidMax) );
        }
        _s.cidcl = in.readuint32();
        if (!(_s.cidcl<268435455)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cidcl<268435455 for value " + String.valueOf(_s.cidcl) );
        }
        _s.cspSaved = in.readuint32();
        _s.cdgSaved = in.readuint32();
        return _s;
    }
    void write(OfficeArtFDGG _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.spidMax);
        out.writeuint32(_s.cidcl);
        out.writeuint32(_s.cspSaved);
        out.writeuint32(_s.cdgSaved);
    }
    OfficeArtFDG parseOfficeArtFDG(LEInputStream in) throws IOException  {
        OfficeArtFDG _s = new OfficeArtFDG();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance<=4094)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance<=4094 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F008)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F008 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 8 for value " + String.valueOf(_s.rh) );
        }
        _s.csp = in.readuint32();
        _s.spidCur = in.readuint32();
        return _s;
    }
    void write(OfficeArtFDG _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.csp);
        out.writeuint32(_s.spidCur);
    }
    OfficeArtFRITContainer parseOfficeArtFRITContainer(LEInputStream in) throws IOException  {
        OfficeArtFRITContainer _s = new OfficeArtFRITContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF118)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF118 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen==4*_s.rh.recInstance)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen==4*_s.rh.recInstance for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.rgfrit = new OfficeArtFRIT[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgfrit[_i] = parseOfficeArtFRIT(in);
        }
        return _s;
    }
    void write(OfficeArtFRITContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (OfficeArtFRIT _i: _s.rgfrit) {
            write(_i, out);
        }
    }
    OfficeArtFRIT parseOfficeArtFRIT(LEInputStream in) throws IOException  {
        OfficeArtFRIT _s = new OfficeArtFRIT();
        _s.fridNew = in.readuint16();
        _s.fridOld = in.readuint16();
        return _s;
    }
    void write(OfficeArtFRIT _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.fridNew);
        out.writeuint16(_s.fridOld);
    }
    OfficeArtBStoreContainer parseOfficeArtBStoreContainer(LEInputStream in) throws IOException  {
        OfficeArtBStoreContainer _s = new OfficeArtBStoreContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F001)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F001 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            OfficeArtBStoreContainerFileBlock _t = parseOfficeArtBStoreContainerFileBlock(in);
            _s.rgfb.add(_t);
        }
        return _s;
    }
    void write(OfficeArtBStoreContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (OfficeArtBStoreContainerFileBlock _i: _s.rgfb) {
            write(_i, out);
        }
    }
    OfficeArtSpgrContainer parseOfficeArtSpgrContainer(LEInputStream in) throws IOException  {
        OfficeArtSpgrContainer _s = new OfficeArtSpgrContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F003)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F003 for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            OfficeArtSpgrContainerFileBlock _t = parseOfficeArtSpgrContainerFileBlock(in);
            _s.rgfb.add(_t);
        }
        return _s;
    }
    void write(OfficeArtSpgrContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (OfficeArtSpgrContainerFileBlock _i: _s.rgfb) {
            write(_i, out);
        }
    }
    OfficeArtSolverContainer parseOfficeArtSolverContainer(LEInputStream in) throws IOException  {
        OfficeArtSolverContainer _s = new OfficeArtSolverContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF005)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF005 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(OfficeArtSolverContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    OfficeArtFSPGR parseOfficeArtFSPGR(LEInputStream in) throws IOException  {
        OfficeArtFSPGR _s = new OfficeArtFSPGR();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F009)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F009 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
        }
        _s.xLeft = in.readint32();
        _s.yTop = in.readint32();
        _s.xRight = in.readint32();
        _s.yBottom = in.readint32();
        return _s;
    }
    void write(OfficeArtFSPGR _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.xLeft);
        out.writeint32(_s.yTop);
        out.writeint32(_s.xRight);
        out.writeint32(_s.yBottom);
    }
    OfficeArtFSP parseOfficeArtFSP(LEInputStream in) throws IOException  {
        OfficeArtFSP _s = new OfficeArtFSP();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance<= 202)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance<= 202 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F00A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F00A for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 8 for value " + String.valueOf(_s.rh) );
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
        return _s;
    }
    void write(OfficeArtFSP _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.spid);
        out.writebit(_s.fGroup);
        out.writebit(_s.fChild);
        out.writebit(_s.fPatriarch);
        out.writebit(_s.fDeleted);
        out.writebit(_s.fOleShape);
        out.writebit(_s.fHaveMaster);
        out.writebit(_s.fFlipH);
        out.writebit(_s.fFlipV);
        out.writebit(_s.fConnector);
        out.writebit(_s.fHaveAnchor);
        out.writebit(_s.fBackground);
        out.writebit(_s.fHaveSpt);
        out.writeuint20(_s.unused1);
    }
    OfficeArtFOPT parseOfficeArtFOPT(LEInputStream in) throws IOException  {
        OfficeArtFOPT _s = new OfficeArtFOPT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F00B)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F00B for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.fopt = new OfficeArtFOPTEChoice[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.fopt[_i] = parseOfficeArtFOPTEChoice(in);
        }
        _c = _s.rh.recLen-6*_s.rh.recInstance;
        _s.complexData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.complexData[_i] = in.readuint8();
        }
        return _s;
    }
    void write(OfficeArtFOPT _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (OfficeArtFOPTEChoice _i: _s.fopt) {
            write(_i, out);
        }
        for (byte _i: _s.complexData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtFOPTEComplexData parseOfficeArtFOPTEComplexData(LEInputStream in) throws IOException  {
        OfficeArtFOPTEComplexData _s = new OfficeArtFOPTEComplexData();
        int _c;
        _c = 0;
        _s.data = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.data[_i] = in.readuint8();
        }
        return _s;
    }
    void write(OfficeArtFOPTEComplexData _s, LEOutputStream out) throws IOException  {
        for (byte _i: _s.data) {
            out.writeuint8(_i);
        }
    }
    FixedPoint parseFixedPoint(LEInputStream in) throws IOException  {
        FixedPoint _s = new FixedPoint();
        _s.integral = in.readint16();
        _s.fractional = in.readuint16();
        return _s;
    }
    void write(FixedPoint _s, LEOutputStream out) throws IOException  {
        out.writeint16(_s.integral);
        out.writeuint16(_s.fractional);
    }
    OfficeArtCOLORREF parseOfficeArtCOLORREF(LEInputStream in) throws IOException  {
        OfficeArtCOLORREF _s = new OfficeArtCOLORREF();
        _s.red = in.readuint8();
        _s.green = in.readuint8();
        _s.blue = in.readuint8();
        _s.fPaletteIndex = in.readbit();
        _s.fPaletteRGB = in.readbit();
        _s.fSystemRGB = in.readbit();
        _s.fSchemeIndex = in.readbit();
        _s.fSysIndex = in.readbit();
        _s.unused1 = in.readbit();
        _s.unused2 = in.readbit();
        _s.unused3 = in.readbit();
        return _s;
    }
    void write(OfficeArtCOLORREF _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.red);
        out.writeuint8(_s.green);
        out.writeuint8(_s.blue);
        out.writebit(_s.fPaletteIndex);
        out.writebit(_s.fPaletteRGB);
        out.writebit(_s.fSystemRGB);
        out.writebit(_s.fSchemeIndex);
        out.writebit(_s.fSysIndex);
        out.writebit(_s.unused1);
        out.writebit(_s.unused2);
        out.writebit(_s.unused3);
    }
    OfficeArtChildAnchor parseOfficeArtChildAnchor(LEInputStream in) throws IOException  {
        OfficeArtChildAnchor _s = new OfficeArtChildAnchor();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF00F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF00F for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
        }
        _s.xLeft = in.readint32();
        _s.yTop = in.readint32();
        _s.xRight = in.readint32();
        _s.yBottom = in.readint32();
        return _s;
    }
    void write(OfficeArtChildAnchor _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.xLeft);
        out.writeint32(_s.yTop);
        out.writeint32(_s.xRight);
        out.writeint32(_s.yBottom);
    }
    OfficeArtFPSPL parseOfficeArtFPSPL(LEInputStream in) throws IOException  {
        OfficeArtFPSPL _s = new OfficeArtFPSPL();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF11D)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF11D for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.spid = in.readuint30();
        _s.reserved1 = in.readbit();
        _s.fLast = in.readbit();
        return _s;
    }
    void write(OfficeArtFPSPL _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint30(_s.spid);
        out.writebit(_s.reserved1);
        out.writebit(_s.fLast);
    }
    OfficeArtSecondaryFOPT parseOfficeArtSecondaryFOPT(LEInputStream in) throws IOException  {
        OfficeArtSecondaryFOPT _s = new OfficeArtSecondaryFOPT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF121)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF121 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(OfficeArtSecondaryFOPT _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    OfficeArtTertiaryFOPT parseOfficeArtTertiaryFOPT(LEInputStream in) throws IOException  {
        OfficeArtTertiaryFOPT _s = new OfficeArtTertiaryFOPT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF122)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF122 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.fopt = new OfficeArtFOPTE[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.fopt[_i] = parseOfficeArtFOPTE(in);
        }
        _c = _s.rh.recLen-6*_s.rh.recInstance;
        _s.complexData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.complexData[_i] = in.readuint8();
        }
        return _s;
    }
    void write(OfficeArtTertiaryFOPT _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (OfficeArtFOPTE _i: _s.fopt) {
            write(_i, out);
        }
        for (byte _i: _s.complexData) {
            out.writeuint8(_i);
        }
    }
    RectStruct parseRectStruct(LEInputStream in) throws IOException  {
        RectStruct _s = new RectStruct();
        _s.top = in.readint32();
        _s.left = in.readint32();
        _s.right = in.readint32();
        _s.bottom = in.readint32();
        return _s;
    }
    void write(RectStruct _s, LEOutputStream out) throws IOException  {
        out.writeint32(_s.top);
        out.writeint32(_s.left);
        out.writeint32(_s.right);
        out.writeint32(_s.bottom);
    }
    SmallRectStruct parseSmallRectStruct(LEInputStream in) throws IOException  {
        SmallRectStruct _s = new SmallRectStruct();
        _s.top = in.readint16();
        _s.left = in.readint16();
        _s.right = in.readint16();
        _s.bottom = in.readint16();
        return _s;
    }
    void write(SmallRectStruct _s, LEOutputStream out) throws IOException  {
        out.writeint16(_s.top);
        out.writeint16(_s.left);
        out.writeint16(_s.right);
        out.writeint16(_s.bottom);
    }
    ShapeFlagsAtom parseShapeFlagsAtom(LEInputStream in) throws IOException  {
        ShapeFlagsAtom _s = new ShapeFlagsAtom();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xBDB)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xBDB for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 1 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ShapeFlagsAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ShapeFlags10Atom parseShapeFlags10Atom(LEInputStream in) throws IOException  {
        ShapeFlags10Atom _s = new ShapeFlags10Atom();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xBDC)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xBDC for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 1 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ShapeFlags10Atom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    ExObjRefAtom parseExObjRefAtom(LEInputStream in) throws IOException  {
        ExObjRefAtom _s = new ExObjRefAtom();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xBC1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xBC1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ExObjRefAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    AnimationInfoContainer parseAnimationInfoContainer(LEInputStream in) throws IOException  {
        AnimationInfoContainer _s = new AnimationInfoContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1014)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1014 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(AnimationInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    InteractiveInfoAtom parseInteractiveInfoAtom(LEInputStream in) throws IOException  {
        InteractiveInfoAtom _s = new InteractiveInfoAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFF3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFF3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
        }
        _s.soundIdRef = in.readuint32();
        _s.exHyperlinkIdRef = in.readuint32();
        _s.action = in.readuint8();
        if (!(_s.action<8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.action<8 for value " + String.valueOf(_s.action) );
        }
        _s.oleVerb = in.readuint8();
        if (!(_s.oleVerb<3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.oleVerb<3 for value " + String.valueOf(_s.oleVerb) );
        }
        _s.jump = in.readuint8();
        if (!(_s.jump<7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.jump<7 for value " + String.valueOf(_s.jump) );
        }
        _s.fAnimated = in.readbit();
        _s.fStopSound = in.readbit();
        _s.fCustomSoundReturn = in.readbit();
        _s.fVisited = in.readbit();
        _s.reserved = in.readuint4();
        _s.hyperlinkType = in.readuint8();
        _c = 3;
        _s.unused = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.unused[_i] = in.readuint8();
        }
        return _s;
    }
    void write(InteractiveInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint32(_s.soundIdRef);
        out.writeuint32(_s.exHyperlinkIdRef);
        out.writeuint8(_s.action);
        out.writeuint8(_s.oleVerb);
        out.writeuint8(_s.jump);
        out.writebit(_s.fAnimated);
        out.writebit(_s.fStopSound);
        out.writebit(_s.fCustomSoundReturn);
        out.writebit(_s.fVisited);
        out.writeuint4(_s.reserved);
        out.writeuint8(_s.hyperlinkType);
        for (byte _i: _s.unused) {
            out.writeuint8(_i);
        }
    }
    MacroNameAtom parseMacroNameAtom(LEInputStream in) throws IOException  {
        MacroNameAtom _s = new MacroNameAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFBA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFBA for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen%2==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen%2==0 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.macroName = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.macroName[_i] = in.readuint8();
        }
        return _s;
    }
    void write(MacroNameAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.macroName) {
            out.writeuint8(_i);
        }
    }
    PlaceholderAtom parsePlaceholderAtom(LEInputStream in) throws IOException  {
        PlaceholderAtom _s = new PlaceholderAtom();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xBC3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xBC3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 8 for value " + String.valueOf(_s.rh) );
        }
        _s.position = in.readint32();
        _s.placementId = in.readuint8();
        _s.size = in.readuint8();
        _s.unused = in.readuint16();
        return _s;
    }
    void write(PlaceholderAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.position);
        out.writeuint8(_s.placementId);
        out.writeuint8(_s.size);
        out.writeuint16(_s.unused);
    }
    RecolorInfoAtom parseRecolorInfoAtom(LEInputStream in) throws IOException  {
        RecolorInfoAtom _s = new RecolorInfoAtom();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFE7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFE7 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(RecolorInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    OutlineTextRefAtom parseOutlineTextRefAtom(LEInputStream in) throws IOException  {
        OutlineTextRefAtom _s = new OutlineTextRefAtom();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF9E)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF9E for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 4 for value " + String.valueOf(_s.rh) );
        }
        _s.index = in.readint32();
        if (!(_s.index>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.index>=0 for value " + String.valueOf(_s.index) );
        }
        return _s;
    }
    void write(OutlineTextRefAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeint32(_s.index);
    }
    ShapeClientRoundtripDataSubcontainerOrAtom parseShapeClientRoundtripDataSubcontainerOrAtom(LEInputStream in) throws IOException  {
        ShapeClientRoundtripDataSubcontainerOrAtom _s = new ShapeClientRoundtripDataSubcontainerOrAtom();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recType == 0x1388 || _s.rh.recType == 0xBDD || _s.rh.recType == 0x41F || _s.rh.recType == 0x420 || _s.rh.recType == 0x426)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1388 || _s.rh.recType == 0xBDD || _s.rh.recType == 0x41F || _s.rh.recType == 0x420 || _s.rh.recType == 0x426 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ShapeClientRoundtripDataSubcontainerOrAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    OfficeArtClientTextBox parseOfficeArtClientTextBox(LEInputStream in) throws IOException  {
        OfficeArtClientTextBox _s = new OfficeArtClientTextBox();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0 || _s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 || _s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF00D)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF00D for value " + String.valueOf(_s.rh) );
        }
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen) {
            TextClientDataSubContainerOrAtom _t = parseTextClientDataSubContainerOrAtom(in);
            _s.rgChildRec.add(_t);
        }
        return _s;
    }
    void write(OfficeArtClientTextBox _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (TextClientDataSubContainerOrAtom _i: _s.rgChildRec) {
            write(_i, out);
        }
    }
    TextRulerAtom parseTextRulerAtom(LEInputStream in) throws IOException  {
        TextRulerAtom _s = new TextRulerAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFA6)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFA6 for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recLen;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(TextRulerAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    OfficeArtIDCL parseOfficeArtIDCL(LEInputStream in) throws IOException  {
        OfficeArtIDCL _s = new OfficeArtIDCL();
        _s.dgid = in.readuint32();
        _s.cspidCur = in.readuint32();
        return _s;
    }
    void write(OfficeArtIDCL _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.dgid);
        out.writeuint32(_s.cspidCur);
    }
    OfficeArtFOPTEOPID parseOfficeArtFOPTEOPID(LEInputStream in) throws IOException  {
        OfficeArtFOPTEOPID _s = new OfficeArtFOPTEOPID();
        _s.opid = in.readuint14();
        _s.fBid = in.readbit();
        _s.fComplex = in.readbit();
        return _s;
    }
    void write(OfficeArtFOPTEOPID _s, LEOutputStream out) throws IOException  {
        out.writeuint14(_s.opid);
        out.writebit(_s.fBid);
        out.writebit(_s.fComplex);
    }
    OfficeArtColorMRUContainer parseOfficeArtColorMRUContainer(LEInputStream in) throws IOException  {
        OfficeArtColorMRUContainer _s = new OfficeArtColorMRUContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF11A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF11A for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen==4*_s.rh.recInstance)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen==4*_s.rh.recInstance for value " + String.valueOf(_s.rh) );
        }
        _c = _s.rh.recInstance;
        _s.rgmsocr = new MSOCR[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rgmsocr[_i] = parseMSOCR(in);
        }
        return _s;
    }
    void write(OfficeArtColorMRUContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (MSOCR _i: _s.rgmsocr) {
            write(_i, out);
        }
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
    void write(MSOCR _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.red);
        out.writeuint8(_s.green);
        out.writeuint8(_s.blue);
        out.writeuint3(_s.unused1);
        out.writebit(_s.fSchemeIndex);
        out.writeuint4(_s.unused2);
    }
    OfficeArtSplitMenuColorContainer parseOfficeArtSplitMenuColorContainer(LEInputStream in) throws IOException  {
        OfficeArtSplitMenuColorContainer _s = new OfficeArtSplitMenuColorContainer();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x4 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF11E)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF11E for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
        }
        _c = 4;
        _s.smca = new MSOCR[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.smca[_i] = parseMSOCR(in);
        }
        return _s;
    }
    void write(OfficeArtSplitMenuColorContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (MSOCR _i: _s.smca) {
            write(_i, out);
        }
    }
    todo parsetodo(LEInputStream in) throws IOException  {
        todo _s = new todo();
        int _c;
        _s.rh = parseRecordHeader(in);
        _c = _s.rh.recLen;
        _s.anon = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.anon[_i] = in.readuint8();
        }
        return _s;
    }
    void write(todo _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.anon) {
            out.writeuint8(_i);
        }
    }
    FibBase parseFibBase(LEInputStream in) throws IOException  {
        FibBase _s = new FibBase();
        _s.wIdent = in.readuint16();
        if (!(_s.wIdent == 0xA5EC)) {
            throw new IncorrectValueException(in.getPosition() + "_s.wIdent == 0xA5EC for value " + String.valueOf(_s.wIdent) );
        }
        _s.nFib = in.readuint16();
        if (!(_s.nFib == 0xC0 || _s.nFib == 0xC1 || _s.nFib == 0xC2 || _s.nFib == 0x101 || _s.nFib == 0x10B || _s.nFib == 0x10C || _s.nFib == 0x112)) {
            throw new IncorrectValueException(in.getPosition() + "_s.nFib == 0xC0 || _s.nFib == 0xC1 || _s.nFib == 0xC2 || _s.nFib == 0x101 || _s.nFib == 0x10B || _s.nFib == 0x10C || _s.nFib == 0x112 for value " + String.valueOf(_s.nFib) );
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
        if (!(_s.nFibBack == 0xBF || _s.nFibBack == 0xC1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.nFibBack == 0xBF || _s.nFibBack == 0xC1 for value " + String.valueOf(_s.nFibBack) );
        }
        _s.IKey = in.readuint32();
        _s.envr = in.readuint8();
        if (!(_s.envr == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.envr == 0 for value " + String.valueOf(_s.envr) );
        }
        _s.fMac = in.readbit();
        if (!(_s.fMac == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fMac == false for value " + String.valueOf(_s.fMac) );
        }
        _s.fEmptySpecial = in.readbit();
        _s.fLoadOverridePage = in.readbit();
        _s.reserved1 = in.readbit();
        _s.reserved2 = in.readbit();
        _s.fSpare0 = in.readuint3();
        _s.reserved3 = in.readuint16();
        if (!(_s.reserved3 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved3 == 0 for value " + String.valueOf(_s.reserved3) );
        }
        _s.reserved4 = in.readuint16();
        if (!(_s.reserved4 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved4 == 0 for value " + String.valueOf(_s.reserved4) );
        }
        _s.reserved5 = in.readuint32();
        _s.reserved6 = in.readuint32();
        return _s;
    }
    void write(FibBase _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.wIdent);
        out.writeuint16(_s.nFib);
        out.writeuint16(_s.unused);
        out.writeuint16(_s.lid);
        out.writeuint16(_s.pnNext);
        out.writebit(_s.fDot);
        out.writebit(_s.fGlsy);
        out.writebit(_s.fComplex);
        out.writebit(_s.fHasPic);
        out.writeuint4(_s.cQuickSaves);
        out.writebit(_s.fEncrypted);
        out.writebit(_s.fWhichTblStm);
        out.writebit(_s.fReadOnlyRecommended);
        out.writebit(_s.fWriteReservation);
        out.writebit(_s.fExtChar);
        out.writebit(_s.fLoadOverride);
        out.writebit(_s.fFarEast);
        out.writebit(_s.fObfuscated);
        out.writeuint16(_s.nFibBack);
        out.writeuint32(_s.IKey);
        out.writeuint8(_s.envr);
        out.writebit(_s.fMac);
        out.writebit(_s.fEmptySpecial);
        out.writebit(_s.fLoadOverridePage);
        out.writebit(_s.reserved1);
        out.writebit(_s.reserved2);
        out.writeuint3(_s.fSpare0);
        out.writeuint16(_s.reserved3);
        out.writeuint16(_s.reserved4);
        out.writeuint32(_s.reserved5);
        out.writeuint32(_s.reserved6);
    }
    FibRgW97 parseFibRgW97(LEInputStream in) throws IOException  {
        FibRgW97 _s = new FibRgW97();
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
        return _s;
    }
    void write(FibRgW97 _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.reserved1);
        out.writeuint16(_s.reserved2);
        out.writeuint16(_s.reserved3);
        out.writeuint16(_s.reserved4);
        out.writeuint16(_s.reserved5);
        out.writeuint16(_s.reserved6);
        out.writeuint16(_s.reserved7);
        out.writeuint16(_s.reserved8);
        out.writeuint16(_s.reserved9);
        out.writeuint16(_s.reserved10);
        out.writeuint16(_s.reserved11);
        out.writeuint16(_s.reserved12);
        out.writeuint16(_s.reserved13);
        out.writeuint16(_s.lidFE);
    }
    FibRgLw97 parseFibRgLw97(LEInputStream in) throws IOException  {
        FibRgLw97 _s = new FibRgLw97();
        _s.cbMac = in.readuint32();
        _s.reserved1 = in.readuint32();
        _s.reserved2 = in.readuint32();
        _s.ccpText = in.readint32();
        if (!(_s.ccpText>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpText>=0 for value " + String.valueOf(_s.ccpText) );
        }
        _s.ccpFtn = in.readint32();
        if (!(_s.ccpFtn>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpFtn>=0 for value " + String.valueOf(_s.ccpFtn) );
        }
        _s.ccpHdd = in.readint32();
        if (!(_s.ccpHdd>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpHdd>=0 for value " + String.valueOf(_s.ccpHdd) );
        }
        _s.reserved3 = in.readuint32();
        if (!(_s.reserved3 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved3 == 0 for value " + String.valueOf(_s.reserved3) );
        }
        _s.ccpAtn = in.readint32();
        if (!(_s.ccpAtn>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpAtn>=0 for value " + String.valueOf(_s.ccpAtn) );
        }
        _s.ccpEdn = in.readint32();
        if (!(_s.ccpEdn>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpEdn>=0 for value " + String.valueOf(_s.ccpEdn) );
        }
        _s.ccpTxbx = in.readint32();
        if (!(_s.ccpTxbx>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpTxbx>=0 for value " + String.valueOf(_s.ccpTxbx) );
        }
        _s.ccpHdrTxbx = in.readint32();
        if (!(_s.ccpHdrTxbx>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.ccpHdrTxbx>=0 for value " + String.valueOf(_s.ccpHdrTxbx) );
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
        if (!(_s.reserved13 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved13 == 0 for value " + String.valueOf(_s.reserved13) );
        }
        _s.reserved14 = in.readuint32();
        if (!(_s.reserved14 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved14 == 0 for value " + String.valueOf(_s.reserved14) );
        }
        return _s;
    }
    void write(FibRgLw97 _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.cbMac);
        out.writeuint32(_s.reserved1);
        out.writeuint32(_s.reserved2);
        out.writeint32(_s.ccpText);
        out.writeint32(_s.ccpFtn);
        out.writeint32(_s.ccpHdd);
        out.writeuint32(_s.reserved3);
        out.writeint32(_s.ccpAtn);
        out.writeint32(_s.ccpEdn);
        out.writeint32(_s.ccpTxbx);
        out.writeint32(_s.ccpHdrTxbx);
        out.writeuint32(_s.reserved4);
        out.writeuint32(_s.reserved5);
        out.writeuint32(_s.reserved6);
        out.writeuint32(_s.reserved7);
        out.writeuint32(_s.reserved8);
        out.writeuint32(_s.reserved9);
        out.writeuint32(_s.reserved10);
        out.writeuint32(_s.reserved11);
        out.writeuint32(_s.reserved12);
        out.writeuint32(_s.reserved13);
        out.writeuint32(_s.reserved14);
    }
    FibRgFcLcb97 parseFibRgFcLcb97(LEInputStream in) throws IOException  {
        FibRgFcLcb97 _s = new FibRgFcLcb97();
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
        return _s;
    }
    void write(FibRgFcLcb97 _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.fcStshfOrig);
        out.writeuint32(_s.lcbStshfOrig);
        out.writeuint32(_s.fcStshf);
        out.writeuint32(_s.lcbStshf);
        out.writeuint32(_s.fcPlcffndRef);
        out.writeuint32(_s.lcbPlcffndRef);
        out.writeuint32(_s.fcPlcffndTxt);
        out.writeuint32(_s.lcbPlcffndTxt);
        out.writeuint32(_s.fcPlcfandRef);
        out.writeuint32(_s.lcbPlcfandRef);
        out.writeuint32(_s.fcPlcfandTxt);
        out.writeuint32(_s.lcbPlcfandTxt);
        out.writeuint32(_s.fcPlcfSed);
        out.writeuint32(_s.lcbPlcfSed);
        out.writeuint32(_s.fcPlcPad);
        out.writeuint32(_s.lcbPlcPad);
        out.writeuint32(_s.fcPlcfPhe);
        out.writeuint32(_s.lcbPlcfPhe);
        out.writeuint32(_s.fcSttbfGlsy);
        out.writeuint32(_s.lcbSttbfGlsy);
        out.writeuint32(_s.fcPlcfGlsy);
        out.writeuint32(_s.lcbPlcfGlsy);
        out.writeuint32(_s.fcPlcfHdd);
        out.writeuint32(_s.lcbPlcfHdd);
        out.writeuint32(_s.fcPlcfBteChpx);
        out.writeuint32(_s.lcbPlcfBteChpx);
        out.writeuint32(_s.fcPlcfBtePapx);
        out.writeuint32(_s.lcbPlcfBtePapx);
        out.writeuint32(_s.fcPlcfSea);
        out.writeuint32(_s.lcbPlcfSea);
        out.writeuint32(_s.fcSttbfFfn);
        out.writeuint32(_s.lcbSttbfFfn);
        out.writeuint32(_s.fcPlcfFldMom);
        out.writeuint32(_s.lcbPlcfFldMom);
        out.writeuint32(_s.fcPlcfFldHdr);
        out.writeuint32(_s.lcbPlcfFldHdr);
        out.writeuint32(_s.fcPlcfFldFtn);
        out.writeuint32(_s.lcbPlcfFldFtn);
        out.writeuint32(_s.fcPlcfFldAtn);
        out.writeuint32(_s.lcbPlcfFldAtn);
        out.writeuint32(_s.fcPlcfFldMcr);
        out.writeuint32(_s.lcbPlcfFldMcr);
        out.writeuint32(_s.fcSttbfBkmk);
        out.writeuint32(_s.lcbSttbfBkmk);
        out.writeuint32(_s.fcPlcfBkf);
        out.writeuint32(_s.lcbPlcfBkf);
        out.writeuint32(_s.fcPlcfBkl);
        out.writeuint32(_s.lcbPlcfBkl);
        out.writeuint32(_s.fcCmds);
        out.writeuint32(_s.lcbCmds);
        out.writeuint32(_s.fcUnused1);
        out.writeuint32(_s.lcbUnused1);
        out.writeuint32(_s.fcSttbfMcr);
        out.writeuint32(_s.lcbSttbfMcr);
        out.writeuint32(_s.fcPrDrvr);
        out.writeuint32(_s.lcbPrDrvr);
        out.writeuint32(_s.fcPrEnvPort);
        out.writeuint32(_s.lcbPrEnvPort);
        out.writeuint32(_s.fcPrEnvLand);
        out.writeuint32(_s.lcbPrEnvLand);
        out.writeuint32(_s.fcWss);
        out.writeuint32(_s.lcbWss);
        out.writeuint32(_s.fcDop);
        out.writeuint32(_s.lcbDop);
        out.writeuint32(_s.fcSttbfAssoc);
        out.writeuint32(_s.lcbSttbfAssoc);
        out.writeuint32(_s.fcClx);
        out.writeuint32(_s.lcbClx);
        out.writeuint32(_s.fcPlcfPgdFtn);
        out.writeuint32(_s.lcbPlcfPgdFtn);
        out.writeuint32(_s.fcAutosaveSource);
        out.writeuint32(_s.lcbAutosaveSource);
        out.writeuint32(_s.fcGrpXstAtnOwners);
        out.writeuint32(_s.lcbGrpXstAtnOwners);
        out.writeuint32(_s.fcSttbfAtnBkmk);
        out.writeuint32(_s.lcbSttbfAtnBkmk);
        out.writeuint32(_s.fcUnused2);
        out.writeuint32(_s.lcbUnused2);
        out.writeuint32(_s.fcUnused3);
        out.writeuint32(_s.lcbUnused3);
        out.writeuint32(_s.fcPlcSpaMom);
        out.writeuint32(_s.lcbPlcSpaMom);
        out.writeuint32(_s.fcPlcSpaHdr);
        out.writeuint32(_s.lcbPlcSpaHdr);
        out.writeuint32(_s.fcPlcfAtnBkf);
        out.writeuint32(_s.lcbPlcfAtnBkf);
        out.writeuint32(_s.fcPlcfAtnBkl);
        out.writeuint32(_s.lcbPlcfAtnBkl);
        out.writeuint32(_s.fcPms);
        out.writeuint32(_s.lcbPms);
        out.writeuint32(_s.fcFormFldSttbs);
        out.writeuint32(_s.lcbFormFldSttbs);
        out.writeuint32(_s.fcPlcfendRef);
        out.writeuint32(_s.lcbPlcfendRef);
        out.writeuint32(_s.fcPlcfendTxt);
        out.writeuint32(_s.lcbPlcfendTxt);
        out.writeuint32(_s.fcPlcfFldEdn);
        out.writeuint32(_s.lcbPlcfFldEdn);
        out.writeuint32(_s.fcUnused4);
        out.writeuint32(_s.lcbUnused4);
        out.writeuint32(_s.fcDggInfo);
        out.writeuint32(_s.lcbDggInfo);
        out.writeuint32(_s.fcSttbfRMark);
        out.writeuint32(_s.lcbSttbfRMark);
        out.writeuint32(_s.fcSttbfCaption);
        out.writeuint32(_s.lcbSttbfCaption);
        out.writeuint32(_s.fcSttbfAutoCaption);
        out.writeuint32(_s.lcbSttbfAutoCaption);
        out.writeuint32(_s.fcPlcfWkb);
        out.writeuint32(_s.lcbPlcfWkb);
        out.writeuint32(_s.fcPlcfSpl);
        out.writeuint32(_s.lcbPlcfSpl);
        out.writeuint32(_s.fcPlcftxbxTxt);
        out.writeuint32(_s.lcbPlcftxbxTxt);
        out.writeuint32(_s.fcPlcfFldTxbx);
        out.writeuint32(_s.lcbPlcfFldTxbx);
        out.writeuint32(_s.fcPlcfHdrtxbxTxt);
        out.writeuint32(_s.lcbPlcfHdrtxbxTxt);
        out.writeuint32(_s.fcPlcffldHdrTxbx);
        out.writeuint32(_s.lcbPlcffldHdrTxbx);
        out.writeuint32(_s.fcStwUser);
        out.writeuint32(_s.lcbStwUser);
        out.writeuint32(_s.fcSttbTtmbd);
        out.writeuint32(_s.lcbSttbTtmbd);
        out.writeuint32(_s.fcCookieData);
        out.writeuint32(_s.lcbCookieData);
        out.writeuint32(_s.fcPgdMotherOldOld);
        out.writeuint32(_s.lcbPgdMotherOldOld);
        out.writeuint32(_s.fcBkdMotherOldOld);
        out.writeuint32(_s.lcbBkdMotherOldOld);
        out.writeuint32(_s.fcPgdFtnOldOld);
        out.writeuint32(_s.lcbPgdFtnOldOld);
        out.writeuint32(_s.fcBkdFtnOldOld);
        out.writeuint32(_s.lcbBkdFtnOldOld);
        out.writeuint32(_s.fcPgdEdnOldOld);
        out.writeuint32(_s.lcbPgdEdnOldOld);
        out.writeuint32(_s.fcBkdEdnOldOld);
        out.writeuint32(_s.lcbBkdEdnOldOld);
        out.writeuint32(_s.fcSttbfIntlFld);
        out.writeuint32(_s.lcbSttbfIntlFld);
        out.writeuint32(_s.fcRouteSlip);
        out.writeuint32(_s.lcbRouteSlip);
        out.writeuint32(_s.fcSttbSavedBy);
        out.writeuint32(_s.lcbSttbSavedBy);
        out.writeuint32(_s.fcSttbFnm);
        out.writeuint32(_s.lcbSttbFnm);
        out.writeuint32(_s.fcPlfLst);
        out.writeuint32(_s.lcbPlfLst);
        out.writeuint32(_s.fcPlfLfo);
        out.writeuint32(_s.lcbPlfLfo);
        out.writeuint32(_s.fcPlcfTxbxBkd);
        out.writeuint32(_s.lcbPlcfTxbxBkd);
        out.writeuint32(_s.fcPlcfTxbxHdrBkd);
        out.writeuint32(_s.lcbPlcfTxbxHdrBkd);
        out.writeuint32(_s.fcDocUndoWord9);
        out.writeuint32(_s.lcbDocUndoWord9);
        out.writeuint32(_s.fcRgbUse);
        out.writeuint32(_s.lcbRgbUse);
        out.writeuint32(_s.fcUsp);
        out.writeuint32(_s.lcbUsp);
        out.writeuint32(_s.fcUskf);
        out.writeuint32(_s.lcbUskf);
        out.writeuint32(_s.fcPlcupcRgbUse);
        out.writeuint32(_s.lcbPlcupcRgbUse);
        out.writeuint32(_s.fcPlcupcUsp);
        out.writeuint32(_s.lcbPlcupcUsp);
        out.writeuint32(_s.fcSttbGlsyStyle);
        out.writeuint32(_s.lcbSttbGlsyStyle);
        out.writeuint32(_s.fcPlgosl);
        out.writeuint32(_s.lcbPlgosl);
        out.writeuint32(_s.fcPlcocx);
        out.writeuint32(_s.lcbPlcocx);
        out.writeuint32(_s.fcPlcfBteLvc);
        out.writeuint32(_s.lcbPlcfBteLvc);
        out.writeuint32(_s.dwLowDateTime);
        out.writeuint32(_s.dwHighDateTime);
        out.writeuint32(_s.fcPlcfLvcPre10);
        out.writeuint32(_s.lcbPlcfLvcPre10);
        out.writeuint32(_s.fcPlcfAsumy);
        out.writeuint32(_s.lcbPlcfAsumy);
        out.writeuint32(_s.fcPlcfGram);
        out.writeuint32(_s.lcbPlcfGram);
        out.writeuint32(_s.fcSttbListNames);
        out.writeuint32(_s.lcbSttbListNames);
        out.writeuint32(_s.fcSttbfUssr);
        out.writeuint32(_s.lcbSttbfUssr);
    }
    FibRgFcLcb2000 parseFibRgFcLcb2000(LEInputStream in) throws IOException  {
        FibRgFcLcb2000 _s = new FibRgFcLcb2000();
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
        return _s;
    }
    void write(FibRgFcLcb2000 _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.fcPlcfTch);
        out.writeuint32(_s.lcbPlcfTch);
        out.writeuint32(_s.fcRmdThreading);
        out.writeuint32(_s.lcbRmdThreading);
        out.writeuint32(_s.fcMid);
        out.writeuint32(_s.lcbMid);
        out.writeuint32(_s.fcSttbRgtplc);
        out.writeuint32(_s.lcbSttbRgtplc);
        out.writeuint32(_s.fcMsoEnvelope);
        out.writeuint32(_s.lcbMsoEnvelope);
        out.writeuint32(_s.fcPlcfLad);
        out.writeuint32(_s.lcbPlcfLad);
        out.writeuint32(_s.fcRgDofr);
        out.writeuint32(_s.lcbRgDofr);
        out.writeuint32(_s.fcPlcosl);
        out.writeuint32(_s.lcbPlcosl);
        out.writeuint32(_s.fcPlcfCookieOld);
        out.writeuint32(_s.lcbPlcfCookieOld);
        out.writeuint32(_s.fcPgdMotherOld);
        out.writeuint32(_s.lcbPgdMotherOld);
        out.writeuint32(_s.fcBkdMotherOld);
        out.writeuint32(_s.lcbBkdMotherOld);
        out.writeuint32(_s.fcPgdFtnOld);
        out.writeuint32(_s.lcbPgdFtnOld);
        out.writeuint32(_s.fcBkdFtnOld);
        out.writeuint32(_s.lcbBkdFtnOld);
        out.writeuint32(_s.fcPgdEdnOld);
        out.writeuint32(_s.lcbPgdEdnOld);
        out.writeuint32(_s.fcBkdEdnOld);
        out.writeuint32(_s.lcbBkdEdnOld);
    }
    FibRgFcLcb2002 parseFibRgFcLcb2002(LEInputStream in) throws IOException  {
        FibRgFcLcb2002 _s = new FibRgFcLcb2002();
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
        return _s;
    }
    void write(FibRgFcLcb2002 _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.fcUnused1);
        out.writeuint32(_s.lcbUnused1);
        out.writeuint32(_s.fcPlcfPgp);
        out.writeuint32(_s.lcbPlcfPgp);
        out.writeuint32(_s.fcPlcfuim);
        out.writeuint32(_s.lcbPlcfuim);
        out.writeuint32(_s.fcPlfguidUim);
        out.writeuint32(_s.lcbPlfguidUim);
        out.writeuint32(_s.fcAtrdExtra);
        out.writeuint32(_s.lcbAtrdExtra);
        out.writeuint32(_s.fcPlrsid);
        out.writeuint32(_s.lcbPlrsid);
        out.writeuint32(_s.fcSttbfBkmkFactoid);
        out.writeuint32(_s.lcbSttbfBkmkFactoid);
        out.writeuint32(_s.fcPlcfBkfFactoid);
        out.writeuint32(_s.lcbPlcfBkfFactoid);
        out.writeuint32(_s.fcPlcfcookie);
        out.writeuint32(_s.lcbPlcfcookie);
        out.writeuint32(_s.fcPlcfBklFactoid);
        out.writeuint32(_s.lcbPlcfBklFactoid);
        out.writeuint32(_s.fcFactoidData);
        out.writeuint32(_s.lcbFactoidData);
        out.writeuint32(_s.fcDocUndo);
        out.writeuint32(_s.lcbDocUndo);
        out.writeuint32(_s.fcSttbfBkmkFcc);
        out.writeuint32(_s.lcbSttbfBkmkFcc);
        out.writeuint32(_s.fcPlcfBkfFcc);
        out.writeuint32(_s.lcbPlcfBkfFcc);
        out.writeuint32(_s.fcPlcfBklFcc);
        out.writeuint32(_s.lcbPlcfBklFcc);
        out.writeuint32(_s.fcSttbfbkmkBPRepairs);
        out.writeuint32(_s.lcbSttbfbkmkBPRepairs);
        out.writeuint32(_s.fcPlcfbkfBPRepairs);
        out.writeuint32(_s.lcbPlcfbkfBPRepairs);
        out.writeuint32(_s.fcPlcfbklBPRepairs);
        out.writeuint32(_s.lcbPlcfbklBPRepairs);
        out.writeuint32(_s.fcPmsNew);
        out.writeuint32(_s.lcbPmsNew);
        out.writeuint32(_s.fcODSO);
        out.writeuint32(_s.lcbODSO);
        out.writeuint32(_s.fcPlcfpmiOldXP);
        out.writeuint32(_s.lcbPlcfpmiOldXP);
        out.writeuint32(_s.fcPlcfpmiNewXP);
        out.writeuint32(_s.lcbPlcfpmiNewXP);
        out.writeuint32(_s.fcPlcfpmiMixedXP);
        out.writeuint32(_s.lcbPlcfpmiMixedXP);
        out.writeuint32(_s.fcUnused2);
        out.writeuint32(_s.lcbUnused2);
        out.writeuint32(_s.fcPlcffactoid);
        out.writeuint32(_s.lcbPlcffactoid);
    }
    LPStshi parseLPStshi(LEInputStream in) throws IOException  {
        LPStshi _s = new LPStshi();
        int _c;
        _s.cbSthi = in.readuint16();
        _c = _s.cbSthi;
        _s.stshi = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.stshi[_i] = in.readuint8();
        }
        return _s;
    }
    void write(LPStshi _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.cbSthi);
        for (byte _i: _s.stshi) {
            out.writeuint8(_i);
        }
    }
    LPStd parseLPStd(LEInputStream in) throws IOException  {
        LPStd _s = new LPStd();
        int _c;
        _s.cbStd = in.readuint16();
        _c = _s.cbStd;
        _s.std = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.std[_i] = in.readuint8();
        }
        if (_s.cbStd%2==1) {
            _s.padding = in.readuint8();
        }
        return _s;
    }
    void write(LPStd _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.cbStd);
        for (byte _i: _s.std) {
            out.writeuint8(_i);
        }
        if (_s.cbStd%2==1) {
            out.writeuint8(_s.padding);
        }
    }
    PlcfSed parsePlcfSed(LEInputStream in) throws IOException  {
        PlcfSed _s = new PlcfSed();
        int _c;
        _c = 2;
        _s.aCP = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aCP[_i] = in.readuint32();
        }
        _c = 1;
        _s.aSed = new Sed[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aSed[_i] = parseSed(in);
        }
        return _s;
    }
    void write(PlcfSed _s, LEOutputStream out) throws IOException  {
        for (int _i: _s.aCP) {
            out.writeuint32(_i);
        }
        for (Sed _i: _s.aSed) {
            write(_i, out);
        }
    }
    Sed parseSed(LEInputStream in) throws IOException  {
        Sed _s = new Sed();
        _s.fn = in.readuint16();
        _s.fcSepx = in.readint32();
        _s.fnMpr = in.readuint16();
        _s.fcMpr = in.readuint32();
        return _s;
    }
    void write(Sed _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.fn);
        out.writeint32(_s.fcSepx);
        out.writeuint16(_s.fnMpr);
        out.writeuint32(_s.fcMpr);
    }
    Plcfhdd parsePlcfhdd(LEInputStream in) throws IOException  {
        Plcfhdd _s = new Plcfhdd();
        int _c;
        _c = 13;
        _s.aCP = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aCP[_i] = in.readuint32();
        }
        return _s;
    }
    void write(Plcfhdd _s, LEOutputStream out) throws IOException  {
        for (int _i: _s.aCP) {
            out.writeuint32(_i);
        }
    }
    PlcBteChpx parsePlcBteChpx(LEInputStream in) throws IOException  {
        PlcBteChpx _s = new PlcBteChpx();
        int _c;
        _c = 2;
        _s.aCP = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aCP[_i] = in.readuint32();
        }
        _c = 1;
        _s.aPnBteChpx = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aPnBteChpx[_i] = in.readuint32();
        }
        return _s;
    }
    void write(PlcBteChpx _s, LEOutputStream out) throws IOException  {
        for (int _i: _s.aCP) {
            out.writeuint32(_i);
        }
        for (int _i: _s.aPnBteChpx) {
            out.writeuint32(_i);
        }
    }
    PlcfBtePapx parsePlcfBtePapx(LEInputStream in) throws IOException  {
        PlcfBtePapx _s = new PlcfBtePapx();
        int _c;
        _c = 2;
        _s.aCP = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aCP[_i] = in.readuint32();
        }
        _c = 1;
        _s.aPnBteChpx = new int[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.aPnBteChpx[_i] = in.readuint32();
        }
        return _s;
    }
    void write(PlcfBtePapx _s, LEOutputStream out) throws IOException  {
        for (int _i: _s.aCP) {
            out.writeuint32(_i);
        }
        for (int _i: _s.aPnBteChpx) {
            out.writeuint32(_i);
        }
    }
    Tcg parseTcg(LEInputStream in) throws IOException  {
        Tcg _s = new Tcg();
        int _c;
        _s.nTcgVer = in.readuint8();
        if (!(_s.nTcgVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.nTcgVer == 0 for value " + String.valueOf(_s.nTcgVer) );
        }
        _c = 11;
        _s.todo = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.todo[_i] = in.readuint8();
        }
        return _s;
    }
    void write(Tcg _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.nTcgVer);
        for (byte _i: _s.todo) {
            out.writeuint8(_i);
        }
    }
    PrcData parsePrcData(LEInputStream in) throws IOException  {
        PrcData _s = new PrcData();
        int _c;
        _s.cbGrpprl = in.readint16();
        if (!(_s.cbGrpprl>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cbGrpprl>=0 for value " + String.valueOf(_s.cbGrpprl) );
        }
        if (!(_s.cbGrpprl<=16290)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cbGrpprl<=16290 for value " + String.valueOf(_s.cbGrpprl) );
        }
        if (!(_s.cbGrpprl%2==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cbGrpprl%2==0 for value " + String.valueOf(_s.cbGrpprl) );
        }
        _c = _s.cbGrpprl/2;
        _s.GrpPrl = new Sprm[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.GrpPrl[_i] = parseSprm(in);
        }
        return _s;
    }
    void write(PrcData _s, LEOutputStream out) throws IOException  {
        out.writeint16(_s.cbGrpprl);
        for (Sprm _i: _s.GrpPrl) {
            write(_i, out);
        }
    }
    Sprm parseSprm(LEInputStream in) throws IOException  {
        Sprm _s = new Sprm();
        _s.ispmd = in.readuint9();
        _s.fSpec = in.readbit();
        _s.sgc = in.readuint3();
        _s.spra = in.readuint3();
        return _s;
    }
    void write(Sprm _s, LEOutputStream out) throws IOException  {
        out.writeuint9(_s.ispmd);
        out.writebit(_s.fSpec);
        out.writeuint3(_s.sgc);
        out.writeuint3(_s.spra);
    }
    Pcdt parsePcdt(LEInputStream in) throws IOException  {
        Pcdt _s = new Pcdt();
        int _c;
        _s.clxt = in.readuint8();
        if (!(_s.clxt == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.clxt == 2 for value " + String.valueOf(_s.clxt) );
        }
        _s.lcb = in.readuint32();
        _c = _s.lcb/8;
        _s.PlcPcd = new Pcd[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.PlcPcd[_i] = parsePcd(in);
        }
        return _s;
    }
    void write(Pcdt _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.clxt);
        out.writeuint32(_s.lcb);
        for (Pcd _i: _s.PlcPcd) {
            write(_i, out);
        }
    }
    FCompressed parseFCompressed(LEInputStream in) throws IOException  {
        FCompressed _s = new FCompressed();
        _s.fc = in.readuint30();
        _s.fCompressed = in.readbit();
        _s.r1 = in.readbit();
        return _s;
    }
    void write(FCompressed _s, LEOutputStream out) throws IOException  {
        out.writeuint30(_s.fc);
        out.writebit(_s.fCompressed);
        out.writebit(_s.r1);
    }
    Prm0 parsePrm0(LEInputStream in) throws IOException  {
        Prm0 _s = new Prm0();
        _s.fComplex = in.readbit();
        if (!(_s.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fComplex == false for value " + String.valueOf(_s.fComplex) );
        }
        _s.isprm = in.readuint7();
        _s.val = in.readuint8();
        return _s;
    }
    void write(Prm0 _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.fComplex);
        out.writeuint7(_s.isprm);
        out.writeuint8(_s.val);
    }
    Prm1 parsePrm1(LEInputStream in) throws IOException  {
        Prm1 _s = new Prm1();
        _s.fComplex = in.readbit();
        if (!(_s.fComplex == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fComplex == true for value " + String.valueOf(_s.fComplex) );
        }
        _s.igrpprl = in.readuint15();
        return _s;
    }
    void write(Prm1 _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.fComplex);
        out.writeuint15(_s.igrpprl);
    }
    SttbfFfn parseSttbfFfn(LEInputStream in) throws IOException  {
        SttbfFfn _s = new SttbfFfn();
        int _c;
        _s.cData = in.readuint16();
        _s.cbExtra = in.readuint16();
        if (!(_s.cbExtra == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cbExtra == 0 for value " + String.valueOf(_s.cbExtra) );
        }
        _c = _s.cData;
        _s.data = new SttbfFfnEntry[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.data[_i] = parseSttbfFfnEntry(in);
        }
        return _s;
    }
    void write(SttbfFfn _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.cData);
        out.writeuint16(_s.cbExtra);
        for (SttbfFfnEntry _i: _s.data) {
            write(_i, out);
        }
    }
    SttbfFfnEntry parseSttbfFfnEntry(LEInputStream in) throws IOException  {
        SttbfFfnEntry _s = new SttbfFfnEntry();
        int _c;
        _s.cchData = in.readuint8();
        _c = _s.cchData;
        _s.Data = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.Data[_i] = in.readuint8();
        }
        return _s;
    }
    void write(SttbfFfnEntry _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.cchData);
        for (byte _i: _s.Data) {
            out.writeuint8(_i);
        }
    }
    CodePageString parseCodePageString(LEInputStream in) throws IOException  {
        CodePageString _s = new CodePageString();
        int _c;
        _s.size = in.readuint32();
        if (!(_s.size%2==0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.size%2==0 for value " + String.valueOf(_s.size) );
        }
        _c = 4*(_s.size/4)+(_s.size%4)?4:0;
        _s.characters = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.characters[_i] = in.readuint8();
        }
        return _s;
    }
    void write(CodePageString _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.size);
        for (byte _i: _s.characters) {
            out.writeuint8(_i);
        }
    }
    FILETIME parseFILETIME(LEInputStream in) throws IOException  {
        FILETIME _s = new FILETIME();
        _s.dwLowDateTime = in.readuint32();
        _s.dwHighDateTime = in.readuint32();
        return _s;
    }
    void write(FILETIME _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.dwLowDateTime);
        out.writeuint32(_s.dwHighDateTime);
    }
    ClipboardData parseClipboardData(LEInputStream in) throws IOException  {
        ClipboardData _s = new ClipboardData();
        int _c;
        _s.size = in.readuint32();
        _s.format = in.readuint32();
        _c = 4*(_s.size/4)+((_s.size%4)?4:0)-4;
        _s.data = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.data[_i] = in.readuint8();
        }
        return _s;
    }
    void write(ClipboardData _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.size);
        out.writeuint32(_s.format);
        for (byte _i: _s.data) {
            out.writeuint8(_i);
        }
    }
    PropertyIdentifierAndOffset parsePropertyIdentifierAndOffset(LEInputStream in) throws IOException  {
        PropertyIdentifierAndOffset _s = new PropertyIdentifierAndOffset();
        _s.propertyIdentifier = in.readuint32();
        _s.offset = in.readuint32();
        return _s;
    }
    void write(PropertyIdentifierAndOffset _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.propertyIdentifier);
        out.writeuint32(_s.offset);
    }
    TypedPropertyValue parseTypedPropertyValue(LEInputStream in) throws IOException  {
        TypedPropertyValue _s = new TypedPropertyValue();
        _s.type = in.readuint16();
        _s.padding = in.readuint16();
        if (_s.type==2) {
            _s.vt_I2 = in.readuint16();
        }
        if (_s.type==2) {
            _s.paddingI2 = in.readuint16();
        }
        if (_s.type==10) {
            _s.vg_ERROR = in.readuint32();
        }
        if (_s.type==30) {
            _s.vt_lpstr = parseCodePageString(in);
        }
        if (_s.type==64) {
            _s.vg_FILETIME = parseFILETIME(in);
        }
        if (_s.type==71) {
            _s.vg_CF = parseClipboardData(in);
        }
        return _s;
    }
    void write(TypedPropertyValue _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.type);
        out.writeuint16(_s.padding);
        if (_s.type==2) {
            out.writeuint16(_s.vt_I2);
        }
        if (_s.type==2) {
            out.writeuint16(_s.paddingI2);
        }
        if (_s.type==10) {
            out.writeuint32(_s.vg_ERROR);
        }
        if (_s.type==30) {
            write(_s.vt_lpstr, out);
        }
        if (_s.type==64) {
            write(_s.vg_FILETIME, out);
        }
        if (_s.type==71) {
            write(_s.vg_CF, out);
        }
    }
    PropertySet parsePropertySet(LEInputStream in) throws IOException  {
        PropertySet _s = new PropertySet();
        int _c;
        _s.size = in.readuint32();
        _s.numProperties = in.readuint32();
        _c = _s.numProperties;
        _s.propertyIdentifierAndOffset = new PropertyIdentifierAndOffset[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.propertyIdentifierAndOffset[_i] = parsePropertyIdentifierAndOffset(in);
        }
        _c = _s.numProperties;
        _s.property = new TypedPropertyValue[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.property[_i] = parseTypedPropertyValue(in);
        }
        return _s;
    }
    void write(PropertySet _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.size);
        out.writeuint32(_s.numProperties);
        for (PropertyIdentifierAndOffset _i: _s.propertyIdentifierAndOffset) {
            write(_i, out);
        }
        for (TypedPropertyValue _i: _s.property) {
            write(_i, out);
        }
    }
    PropertySetStream parsePropertySetStream(LEInputStream in) throws IOException  {
        PropertySetStream _s = new PropertySetStream();
        int _c;
        Object _m;
        boolean _atend;
        int _i;
        _s.byteOrder = in.readuint16();
        if (!(_s.byteOrder == 0xFFFE)) {
            throw new IncorrectValueException(in.getPosition() + "_s.byteOrder == 0xFFFE for value " + String.valueOf(_s.byteOrder) );
        }
        _s.version = in.readuint16();
        _s.systemIdentifier = in.readuint32();
        _c = 16;
        _s.clsID = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.clsID[_i] = in.readuint8();
        }
        _s.numPropertySets = in.readuint32();
        if (!(_s.numPropertySets == 1 || _s.numPropertySets == 2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.numPropertySets == 1 || _s.numPropertySets == 2 for value " + String.valueOf(_s.numPropertySets) );
        }
        _c = 16;
        _s.fmtID0 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.fmtID0[_i] = in.readuint8();
        }
        _s.offset0 = in.readuint32();
        if (_s.numPropertySets==2) {
            _c = 16;
            _s.fmtID1 = new byte[_c];
            for (int _i=0; _i<_c; ++_i) {
                _s.fmtID1[_i] = in.readuint8();
            }
        }
        if (_s.numPropertySets==2) {
            _s.offset1 = in.readuint32();
        }
        _s.propertySet1 = parsePropertySet(in);
        if (_s.numPropertySets==2) {
            _s.propertySet2 = parsePropertySet(in);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                Byte _t = parseByte(in);
                _s.padding.add(_t);
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
    void write(PropertySetStream _s, LEOutputStream out) throws IOException  {
        out.writeuint16(_s.byteOrder);
        out.writeuint16(_s.version);
        out.writeuint32(_s.systemIdentifier);
        for (byte _i: _s.clsID) {
            out.writeuint8(_i);
        }
        out.writeuint32(_s.numPropertySets);
        for (byte _i: _s.fmtID0) {
            out.writeuint8(_i);
        }
        out.writeuint32(_s.offset0);
        if (_s.numPropertySets==2) {
            for (byte _i: _s.fmtID1) {
                out.writeuint8(_i);
            }
        }
        if (_s.numPropertySets==2) {
            out.writeuint32(_s.offset1);
        }
        write(_s.propertySet1, out);
        if (_s.numPropertySets==2) {
            write(_s.propertySet2, out);
        }
        for (Byte _i: _s.padding) {
            write(_i, out);
        }
    }
    SummaryInformationPropertySetStream parseSummaryInformationPropertySetStream(LEInputStream in) throws IOException  {
        SummaryInformationPropertySetStream _s = new SummaryInformationPropertySetStream();
        _s.propertySet = parsePropertySetStream(in);
        if (!(_s.propertySet.version == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.propertySet.version == 0 for value " + String.valueOf(_s.propertySet) );
        }
        return _s;
    }
    void write(SummaryInformationPropertySetStream _s, LEOutputStream out) throws IOException  {
        write(_s.propertySet, out);
    }
    DocumentSummaryInformationPropertySetStream parseDocumentSummaryInformationPropertySetStream(LEInputStream in) throws IOException  {
        DocumentSummaryInformationPropertySetStream _s = new DocumentSummaryInformationPropertySetStream();
        _s.propertySet = parsePropertySetStream(in);
        if (!(_s.propertySet.version == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.propertySet.version == 0 for value " + String.valueOf(_s.propertySet) );
        }
        return _s;
    }
    void write(DocumentSummaryInformationPropertySetStream _s, LEOutputStream out) throws IOException  {
        write(_s.propertySet, out);
    }
    PicturesStream parsePicturesStream(LEInputStream in) throws IOException  {
        PicturesStream _s = new PicturesStream();
        _s.anon1 = parseOfficeArtBStoreDelay(in);
        return _s;
    }
    void write(PicturesStream _s, LEOutputStream out) throws IOException  {
        write(_s.anon1, out);
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
    void write(OfficeArtMetafileHeader _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.cbSize);
        write(_s.rcBounds, out);
        write(_s.ptSize, out);
        out.writeuint32(_s.cbsave);
        out.writeuint8(_s.compression);
        out.writeuint8(_s.filter);
    }
    ScalingStruct parseScalingStruct(LEInputStream in) throws IOException  {
        ScalingStruct _s = new ScalingStruct();
        _s.x = parseRatioStruct(in);
        _s.y = parseRatioStruct(in);
        return _s;
    }
    void write(ScalingStruct _s, LEOutputStream out) throws IOException  {
        write(_s.x, out);
        write(_s.y, out);
    }
    NoZoomViewInfoAtom parseNoZoomViewInfoAtom(LEInputStream in) throws IOException  {
        NoZoomViewInfoAtom _s = new NoZoomViewInfoAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3FD)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3FD for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x34)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x34 for value " + String.valueOf(_s.rh) );
        }
        _s.curScale = parseScalingStruct(in);
        _c = 24;
        _s.unused1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.unused1[_i] = in.readuint8();
        }
        _s.origin = parsePointStruct(in);
        _s.unused2 = in.readuint8();
        _s.fDraftMode = in.readuint8();
        _s.unused3 = in.readuint16();
        return _s;
    }
    void write(NoZoomViewInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.curScale, out);
        for (byte _i: _s.unused1) {
            out.writeuint8(_i);
        }
        write(_s.origin, out);
        out.writeuint8(_s.unused2);
        out.writeuint8(_s.fDraftMode);
        out.writeuint16(_s.unused3);
    }
    VBAInfoContainer parseVBAInfoContainer(LEInputStream in) throws IOException  {
        VBAInfoContainer _s = new VBAInfoContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3FF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3FF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x14)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x14 for value " + String.valueOf(_s.rh) );
        }
        _s.vbaInfoAtom = parseVBAInfoAtom(in);
        return _s;
    }
    void write(VBAInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.vbaInfoAtom, out);
    }
    NormalViewSetInfoAtom parseNormalViewSetInfoAtom(LEInputStream in) throws IOException  {
        NormalViewSetInfoAtom _s = new NormalViewSetInfoAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x415)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x415 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x14)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x14 for value " + String.valueOf(_s.rh) );
        }
        _s.leftPortion = parseRatioStruct(in);
        _s.topPortion = parseRatioStruct(in);
        _s.vertBarState = in.readuint8();
        _s.horizBarState = in.readuint8();
        _s.fPreferSingleSet = in.readuint8();
        if (!(_s.fPreferSingleSet == 0 || _s.fPreferSingleSet == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fPreferSingleSet == 0 || _s.fPreferSingleSet == 1 for value " + String.valueOf(_s.fPreferSingleSet) );
        }
        _s.fHideThumbnails = in.readbit();
        _s.fBarSnapped = in.readbit();
        _s.reserved = in.readuint6();
        if (!(_s.reserved == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved == 0 for value " + String.valueOf(_s.reserved) );
        }
        return _s;
    }
    void write(NormalViewSetInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.leftPortion, out);
        write(_s.topPortion, out);
        out.writeuint8(_s.vertBarState);
        out.writeuint8(_s.horizBarState);
        out.writeuint8(_s.fPreferSingleSet);
        out.writebit(_s.fHideThumbnails);
        out.writebit(_s.fBarSnapped);
        out.writeuint6(_s.reserved);
    }
    MasterPersistAtom parseMasterPersistAtom(LEInputStream in) throws IOException  {
        MasterPersistAtom _s = new MasterPersistAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3F3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3F3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x14)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x14 for value " + String.valueOf(_s.rh) );
        }
        _s.persistIdRef = parsePersistIdRef(in);
        _s.reserved1 = in.readuint2();
        if (!(_s.reserved1 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved1 == 0 for value " + String.valueOf(_s.reserved1) );
        }
        _s.fNonOutLineData = in.readbit();
        _s.reserved2 = in.readuint5();
        if (!(_s.reserved2 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved2 == 0 for value " + String.valueOf(_s.reserved2) );
        }
        _s.reserved3 = in.readuint8();
        if (!(_s.reserved3 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved3 == 0 for value " + String.valueOf(_s.reserved3) );
        }
        _s.reserved4 = in.readuint16();
        if (!(_s.reserved4 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved4 == 0 for value " + String.valueOf(_s.reserved4) );
        }
        _s.reserved5 = in.readuint32();
        if (!(_s.reserved5 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved5 == 0 for value " + String.valueOf(_s.reserved5) );
        }
        _s.masterId = in.readuint32();
        _s.reserved6 = in.readuint32();
        if (!(_s.reserved6 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved6 == 0 for value " + String.valueOf(_s.reserved6) );
        }
        return _s;
    }
    void write(MasterPersistAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.persistIdRef, out);
        out.writeuint2(_s.reserved1);
        out.writebit(_s.fNonOutLineData);
        out.writeuint5(_s.reserved2);
        out.writeuint8(_s.reserved3);
        out.writeuint16(_s.reserved4);
        out.writeuint32(_s.reserved5);
        out.writeuint32(_s.masterId);
        out.writeuint32(_s.reserved6);
    }
    TextContainer parseTextContainer(LEInputStream in) throws IOException  {
        TextContainer _s = new TextContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.textHeaderAtom = parseTextHeaderAtom(in);
        _m = in.setMark();
        try {
            _s.text = parseTextCharsAtom(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.text = parseTextBytesAtom(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        }} finally {
            in.releaseMark(_m);
        }
        _m = in.setMark();
        try {
            _s.style = parseStyleTextPropAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                TextContainerMeta _t = parseTextContainerMeta(in);
                _s.meta.add(_t);
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
        _m = in.setMark();
        try {
            _s.master = parseMasterTextPropAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                TextBookmarkAtom _t = parseTextBookmarkAtom(in);
                _s.bookmark.add(_t);
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
        _m = in.setMark();
        try {
            _s.specialinfo = parseTextSpecialInfoAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                TextContainerInteractiveInfo _t = parseTextContainerInteractiveInfo(in);
                _s.interactive.add(_t);
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
    void write(TextContainer _s, LEOutputStream out) throws IOException  {
        write(_s.textHeaderAtom, out);
        if (_s.text instanceof TextCharsAtom) {
            write((TextCharsAtom)_s.text, out);
        } else if (_s.text instanceof TextBytesAtom) {
            write((TextBytesAtom)_s.text, out);
        }
        if (_s.style != null) write(_s.style, out);
        for (TextContainerMeta _i: _s.meta) {
            write(_i, out);
        }
        if (_s.master != null) write(_s.master, out);
        for (TextBookmarkAtom _i: _s.bookmark) {
            write(_i, out);
        }
        if (_s.specialinfo != null) write(_s.specialinfo, out);
        for (TextContainerInteractiveInfo _i: _s.interactive) {
            write(_i, out);
        }
    }
    TextContainerMeta parseTextContainerMeta(LEInputStream in) throws IOException  {
        TextContainerMeta _s = new TextContainerMeta();
        Object _m;
        _m = in.setMark();
        try {
            _s.meta = parseSlideNumberMCAtom(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.meta = parseDateTimeMCAtom(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.meta = parseGenericDateMCAtom(in);
        } catch (IOException _xxx) {
            if (!(_xxx instanceof IncorrectValueException) && !(_xxx instanceof java.io.EOFException)) throw _xxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.meta = parseHeaderMCAtom(in);
        } catch (IOException _xxxx) {
            if (!(_xxxx instanceof IncorrectValueException) && !(_xxxx instanceof java.io.EOFException)) throw _xxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.meta = parseFooterMCAtom(in);
        } catch (IOException _xxxxx) {
            if (!(_xxxxx instanceof IncorrectValueException) && !(_xxxxx instanceof java.io.EOFException)) throw _xxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
            _s.meta = parseRTFDateTimeMCAtom(in);
        }}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(TextContainerMeta _s, LEOutputStream out) throws IOException  {
        if (_s.meta instanceof SlideNumberMCAtom) {
            write((SlideNumberMCAtom)_s.meta, out);
        } else if (_s.meta instanceof DateTimeMCAtom) {
            write((DateTimeMCAtom)_s.meta, out);
        } else if (_s.meta instanceof GenericDateMCAtom) {
            write((GenericDateMCAtom)_s.meta, out);
        } else if (_s.meta instanceof HeaderMCAtom) {
            write((HeaderMCAtom)_s.meta, out);
        } else if (_s.meta instanceof FooterMCAtom) {
            write((FooterMCAtom)_s.meta, out);
        } else if (_s.meta instanceof RTFDateTimeMCAtom) {
            write((RTFDateTimeMCAtom)_s.meta, out);
        }
    }
    TextClientDataSubContainerOrAtom parseTextClientDataSubContainerOrAtom(LEInputStream in) throws IOException  {
        TextClientDataSubContainerOrAtom _s = new TextClientDataSubContainerOrAtom();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseOutlineTextRefAtom(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseTextContainer(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseTextRulerAtom(in);
        }} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(TextClientDataSubContainerOrAtom _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof OutlineTextRefAtom) {
            write((OutlineTextRefAtom)_s.anon, out);
        } else if (_s.anon instanceof TextContainer) {
            write((TextContainer)_s.anon, out);
        } else if (_s.anon instanceof TextRulerAtom) {
            write((TextRulerAtom)_s.anon, out);
        }
    }
    SlidePersistAtom parseSlidePersistAtom(LEInputStream in) throws IOException  {
        SlidePersistAtom _s = new SlidePersistAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3F3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3F3 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x14)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x14 for value " + String.valueOf(_s.rh) );
        }
        _s.persistIdRef = parsePersistIdRef(in);
        _s.reserved1 = in.readbit();
        if (!(_s.reserved1 == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved1 == false for value " + String.valueOf(_s.reserved1) );
        }
        _s.fShouldCollapse = in.readbit();
        _s.fNonOutlineData = in.readbit();
        _s.reserved2 = in.readuint5();
        if (!(_s.reserved2 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved2 == 0 for value " + String.valueOf(_s.reserved2) );
        }
        _s.reserved3 = in.readuint8();
        if (!(_s.reserved3 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved3 == 0 for value " + String.valueOf(_s.reserved3) );
        }
        _s.reserved4 = in.readuint16();
        if (!(_s.reserved4 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved4 == 0 for value " + String.valueOf(_s.reserved4) );
        }
        _s.cTexts = in.readint32();
        if (!(_s.cTexts>=0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cTexts>=0 for value " + String.valueOf(_s.cTexts) );
        }
        if (!(_s.cTexts<=8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cTexts<=8 for value " + String.valueOf(_s.cTexts) );
        }
        _s.slideId = parseSlideId(in);
        _s.reserved5 = in.readuint32();
        if (!(_s.reserved5 == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.reserved5 == 0 for value " + String.valueOf(_s.reserved5) );
        }
        return _s;
    }
    void write(SlidePersistAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.persistIdRef, out);
        out.writebit(_s.reserved1);
        out.writebit(_s.fShouldCollapse);
        out.writebit(_s.fNonOutlineData);
        out.writeuint5(_s.reserved2);
        out.writeuint8(_s.reserved3);
        out.writeuint16(_s.reserved4);
        out.writeint32(_s.cTexts);
        write(_s.slideId, out);
        out.writeuint32(_s.reserved5);
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
    void write(TextRuler _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.fDefaultTabSize);
        out.writebit(_s.fCLevels);
        out.writebit(_s.fTabStops);
        out.writebit(_s.fLeftMargin1);
        out.writebit(_s.fLeftMargin2);
        out.writebit(_s.fLeftMargin3);
        out.writebit(_s.fLeftMargin4);
        out.writebit(_s.fLeftMargin5);
        out.writebit(_s.fIndent1);
        out.writebit(_s.fIndent2);
        out.writebit(_s.fIndent3);
        out.writebit(_s.fIndent4);
        out.writebit(_s.fIndent5);
        out.writeuint3(_s.reserved1);
        out.writeuint16(_s.reserved2);
        if (_s.fCLevels) {
            out.writeint16(_s.cLevels);
        }
        if (_s.fDefaultTabSize) {
            out.writeuint16(_s.defaultTabSize);
        }
        if (_s.fTabStops) {
            write(_s.tabs, out);
        }
        if (_s.fLeftMargin1) {
            out.writeuint16(_s.leftMargin1);
        }
        if (_s.fIndent1) {
            out.writeuint16(_s.indent1);
        }
        if (_s.fLeftMargin2) {
            out.writeuint16(_s.leftMargin2);
        }
        if (_s.fIndent2) {
            out.writeuint16(_s.indent2);
        }
        if (_s.fLeftMargin3) {
            out.writeuint16(_s.leftMargin3);
        }
        if (_s.fIndent3) {
            out.writeuint16(_s.indent3);
        }
        if (_s.fLeftMargin4) {
            out.writeuint16(_s.leftMargin4);
        }
        if (_s.fIndent4) {
            out.writeuint16(_s.indent4);
        }
        if (_s.fLeftMargin5) {
            out.writeuint16(_s.leftMargin5);
        }
        if (_s.fIndent5) {
            out.writeuint16(_s.indent5);
        }
    }
    TextPFException parseTextPFException(LEInputStream in) throws IOException  {
        TextPFException _s = new TextPFException();
        _s.masks = parsePFMasks(in);
        if (!(_s.masks.bulletBlip == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.bulletBlip == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.bulletHasScheme == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.bulletHasScheme == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.bulletScheme == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.bulletScheme == false for value " + String.valueOf(_s.masks) );
        }
        if (_s.masks.hasBullet||_s.masks.bulletHasFont||_s.masks.bulletHasColor||_s.masks.bulletHasSize) {
            _s.bulletFlags = parseBulletFlags(in);
        }
        if (_s.masks.bulletChar) {
            _s.bulletChar = in.readint16();
        }
        if (_s.masks.bulletFont) {
            _s.bulletFontRef = in.readuint16();
        }
        if (_s.masks.bulletSize) {
            _s.bulletSize = in.readuint16();
        }
        if (_s.masks.bulletColor) {
            _s.bulletColor = parseColorIndexStruct(in);
        }
        if (_s.masks.align) {
            _s.textAlignment = in.readuint16();
        }
        if (_s.masks.lineSpacing) {
            _s.lineSpacing = in.readint16();
        }
        if (_s.masks.spaceBefore) {
            _s.spaceBefore = in.readint16();
        }
        if (_s.masks.spaceAfter) {
            _s.spaceAfter = in.readint16();
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
    void write(TextPFException _s, LEOutputStream out) throws IOException  {
        write(_s.masks, out);
        if (_s.masks.hasBullet||_s.masks.bulletHasFont||_s.masks.bulletHasColor||_s.masks.bulletHasSize) {
            write(_s.bulletFlags, out);
        }
        if (_s.masks.bulletChar) {
            out.writeint16(_s.bulletChar);
        }
        if (_s.masks.bulletFont) {
            out.writeuint16(_s.bulletFontRef);
        }
        if (_s.masks.bulletSize) {
            out.writeuint16(_s.bulletSize);
        }
        if (_s.masks.bulletColor) {
            write(_s.bulletColor, out);
        }
        if (_s.masks.align) {
            out.writeuint16(_s.textAlignment);
        }
        if (_s.masks.lineSpacing) {
            out.writeint16(_s.lineSpacing);
        }
        if (_s.masks.spaceBefore) {
            out.writeint16(_s.spaceBefore);
        }
        if (_s.masks.spaceAfter) {
            out.writeint16(_s.spaceAfter);
        }
        if (_s.masks.leftMargin) {
            out.writeuint16(_s.leftMargin);
        }
        if (_s.masks.indent) {
            out.writeuint16(_s.indent);
        }
        if (_s.masks.defaultTabSize) {
            out.writeuint16(_s.defaultTabSize);
        }
        if (_s.masks.tabStops) {
            write(_s.tabStops, out);
        }
        if (_s.masks.fontAlign) {
            out.writeuint16(_s.fontAlign);
        }
        if (_s.masks.charWrap||_s.masks.wordWrap||_s.masks.overflow) {
            out.writeuint16(_s.wrapFlags);
        }
        if (_s.masks.textDirection) {
            out.writeuint16(_s.textDirection);
        }
    }
    TextCFException parseTextCFException(LEInputStream in) throws IOException  {
        TextCFException _s = new TextCFException();
        _s.masks = parseCFMasks(in);
        if (!(_s.masks.pp10ext == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.pp10ext == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.newEATypeface == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.newEATypeface == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.csTypeface == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.csTypeface == false for value " + String.valueOf(_s.masks) );
        }
        if (!(_s.masks.pp11ext == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.masks.pp11ext == false for value " + String.valueOf(_s.masks) );
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
            throw new IncorrectValueException(in.getPosition() + "_s.fontSize>=1 for value " + String.valueOf(_s.fontSize) );
        }
        if (!(_s.fontSize<=4000)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fontSize<=4000 for value " + String.valueOf(_s.fontSize) );
        }
        }
        if (_s.masks.color) {
            _s.color = parseColorIndexStruct(in);
        }
        if (_s.masks.position) {
            _s.position = in.readint16();
        if (!(_s.position>=-100)) {
            throw new IncorrectValueException(in.getPosition() + "_s.position>=-100 for value " + String.valueOf(_s.position) );
        }
        if (!(_s.position<=100)) {
            throw new IncorrectValueException(in.getPosition() + "_s.position<=100 for value " + String.valueOf(_s.position) );
        }
        }
        return _s;
    }
    void write(TextCFException _s, LEOutputStream out) throws IOException  {
        write(_s.masks, out);
        if (_s.masks.bold || _s.masks.italic || _s.masks.underline || _s.masks.shadow || _s.masks.fehint || _s.masks.kumi || _s.masks.emboss || _s.masks.fHasStyle != 0) {
            write(_s.fontStyle, out);
        }
        if (_s.masks.typeface) {
            out.writeuint16(_s.fontRef);
        }
        if (_s.masks.oldEATypeface) {
            out.writeuint16(_s.oldEAFontRef);
        }
        if (_s.masks.ansiTypeface) {
            out.writeuint16(_s.ansiFontRef);
        }
        if (_s.masks.symbolTypeface) {
            out.writeuint16(_s.symbolFontRef);
        }
        if (_s.masks.size) {
            out.writeuint16(_s.fontSize);
        }
        if (_s.masks.color) {
            write(_s.color, out);
        }
        if (_s.masks.position) {
            out.writeint16(_s.position);
        }
    }
    FontCollectionEntry parseFontCollectionEntry(LEInputStream in) throws IOException  {
        FontCollectionEntry _s = new FontCollectionEntry();
        Object _m;
        _s.fontEntityAtom = parseFontEntityAtom(in);
        _m = in.setMark();
        try {
            _s.fontEmbedData1 = parseFontEmbedDataBlob(in);
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
            _s.fontEmbedData2 = parseFontEmbedDataBlob(in);
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
            _s.fontEmbedData3 = parseFontEmbedDataBlob(in);
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
            _s.fontEmbedData4 = parseFontEmbedDataBlob(in);
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
    void write(FontCollectionEntry _s, LEOutputStream out) throws IOException  {
        write(_s.fontEntityAtom, out);
        if (_s.fontEmbedData1 != null) write(_s.fontEmbedData1, out);
        if (_s.fontEmbedData2 != null) write(_s.fontEmbedData2, out);
        if (_s.fontEmbedData3 != null) write(_s.fontEmbedData3, out);
        if (_s.fontEmbedData4 != null) write(_s.fontEmbedData4, out);
    }
    KinsokuContainer parseKinsokuContainer(LEInputStream in) throws IOException  {
        KinsokuContainer _s = new KinsokuContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FC8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FC8 for value " + String.valueOf(_s.rh) );
        }
        _s.kinsokuAtom = parseKinsokuAtom(in);
        if (_s.kinsokuAtom.level==2) {
            _s.kinsokuLeadingAtom = parseKinsokuFollowingAtom(in);
        }
        if (_s.kinsokuAtom.level==2) {
            _s.kinsokuFollowingAtom = parseKinsokuFollowingAtom(in);
        }
        return _s;
    }
    void write(KinsokuContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.kinsokuAtom, out);
        if (_s.kinsokuAtom.level==2) {
            write(_s.kinsokuLeadingAtom, out);
        }
        if (_s.kinsokuAtom.level==2) {
            write(_s.kinsokuFollowingAtom, out);
        }
    }
    TextSIException parseTextSIException(LEInputStream in) throws IOException  {
        TextSIException _s = new TextSIException();
        _s.spell = in.readbit();
        _s.lang = in.readbit();
        _s.altLang = in.readbit();
        _s.unused1 = in.readbit();
        _s.unused2 = in.readbit();
        _s.fPp10ext = in.readbit();
        _s.fBidi = in.readbit();
        _s.unused3 = in.readbit();
        _s.reserved1 = in.readbit();
        _s.smartTag = in.readbit();
        _s.reserved2a = in.readuint2();
        _s.reserved2b = in.readuint20();
        if (_s.spell) {
            _s.spellInfo = in.readuint16();
        }
        if (_s.lang) {
            _s.lid = in.readuint16();
        }
        if (_s.altLang) {
            _s.altLid = in.readuint16();
        }
        if (_s.fBidi) {
            _s.bidi = in.readint16();
        if (!(_s.bidi == 0 || _s.bidi == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.bidi == 0 || _s.bidi == 1 for value " + String.valueOf(_s.bidi) );
        }
        }
        if (_s.fPp10ext) {
            _s.pp10runid = in.readuint4();
        }
        if (_s.fPp10ext) {
            _s.reserved3a = in.readuint4();
        }
        if (_s.fPp10ext) {
            _s.reserved3b = in.readuint16();
        }
        if (_s.fPp10ext) {
            _s.reserved3bc = in.readuint7();
        }
        if (_s.fPp10ext) {
            _s.grammarError = in.readbit();
        }
        if (_s.smartTag) {
            _s.smartTags = parseSmartTags(in);
        }
        return _s;
    }
    void write(TextSIException _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.spell);
        out.writebit(_s.lang);
        out.writebit(_s.altLang);
        out.writebit(_s.unused1);
        out.writebit(_s.unused2);
        out.writebit(_s.fPp10ext);
        out.writebit(_s.fBidi);
        out.writebit(_s.unused3);
        out.writebit(_s.reserved1);
        out.writebit(_s.smartTag);
        out.writeuint2(_s.reserved2a);
        out.writeuint20(_s.reserved2b);
        if (_s.spell) {
            out.writeuint16(_s.spellInfo);
        }
        if (_s.lang) {
            out.writeuint16(_s.lid);
        }
        if (_s.altLang) {
            out.writeuint16(_s.altLid);
        }
        if (_s.fBidi) {
            out.writeint16(_s.bidi);
        }
        if (_s.fPp10ext) {
            out.writeuint4(_s.pp10runid);
        }
        if (_s.fPp10ext) {
            out.writeuint4(_s.reserved3a);
        }
        if (_s.fPp10ext) {
            out.writeuint16(_s.reserved3b);
        }
        if (_s.fPp10ext) {
            out.writeuint7(_s.reserved3bc);
        }
        if (_s.fPp10ext) {
            out.writebit(_s.grammarError);
        }
        if (_s.smartTag) {
            write(_s.smartTags, out);
        }
    }
    TextMasterStyleLevel parseTextMasterStyleLevel(LEInputStream in) throws IOException  {
        TextMasterStyleLevel _s = new TextMasterStyleLevel();
        _s.pf = parseTextPFException(in);
        _s.cf = parseTextCFException(in);
        return _s;
    }
    void write(TextMasterStyleLevel _s, LEOutputStream out) throws IOException  {
        write(_s.pf, out);
        write(_s.cf, out);
    }
    DocumentAtom parseDocumentAtom(LEInputStream in) throws IOException  {
        DocumentAtom _s = new DocumentAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03E9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03E9 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x28)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x28 for value " + String.valueOf(_s.rh) );
        }
        _s.slideSize = parsePointStruct(in);
        _s.notesSize = parsePointStruct(in);
        _s.serverZoom = parseRatioStruct(in);
        if (!(_s.serverZoom.numer*_s.serverZoom.denom > 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.serverZoom.numer*_s.serverZoom.denom > 0 for value " + String.valueOf(_s.serverZoom) );
        }
        _s.notesMasterPersistIdRef = parsePersistIdRef(in);
        _s.handoutMasterPersistIdRef = parsePersistIdRef(in);
        _s.firstSlideNumber = in.readuint16();
        if (!(_s.firstSlideNumber<10000)) {
            throw new IncorrectValueException(in.getPosition() + "_s.firstSlideNumber<10000 for value " + String.valueOf(_s.firstSlideNumber) );
        }
        _s.slideSizeType = in.readuint16();
        if (!(_s.slideSizeType == 0 || _s.slideSizeType == 1 || _s.slideSizeType == 2 || _s.slideSizeType == 3 || _s.slideSizeType == 4 || _s.slideSizeType == 5 || _s.slideSizeType == 6)) {
            throw new IncorrectValueException(in.getPosition() + "_s.slideSizeType == 0 || _s.slideSizeType == 1 || _s.slideSizeType == 2 || _s.slideSizeType == 3 || _s.slideSizeType == 4 || _s.slideSizeType == 5 || _s.slideSizeType == 6 for value " + String.valueOf(_s.slideSizeType) );
        }
        _s.fSaveWithFonts = in.readuint8();
        _s.fOmitTitlePlace = in.readuint8();
        _s.fRightToLeft = in.readuint8();
        _s.fShowComments = in.readuint8();
        return _s;
    }
    void write(DocumentAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.slideSize, out);
        write(_s.notesSize, out);
        write(_s.serverZoom, out);
        write(_s.notesMasterPersistIdRef, out);
        write(_s.handoutMasterPersistIdRef, out);
        out.writeuint16(_s.firstSlideNumber);
        out.writeuint16(_s.slideSizeType);
        out.writeuint8(_s.fSaveWithFonts);
        out.writeuint8(_s.fOmitTitlePlace);
        out.writeuint8(_s.fRightToLeft);
        out.writeuint8(_s.fShowComments);
    }
    ProgStringTagContainer parseProgStringTagContainer(LEInputStream in) throws IOException  {
        ProgStringTagContainer _s = new ProgStringTagContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x1389)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x1389 for value " + String.valueOf(_s.rh) );
        }
        _s.tagNameAtom = parseTagNameAtom(in);
        _s.tagValueAtom = parseTagValueAtom(in);
        return _s;
    }
    void write(ProgStringTagContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.tagNameAtom, out);
        write(_s.tagValueAtom, out);
    }
    ExObjListContainer parseExObjListContainer(LEInputStream in) throws IOException  {
        ExObjListContainer _s = new ExObjListContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0409)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0409 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen>=12)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen>=12 for value " + String.valueOf(_s.rh) );
        }
        _s.exObjListAtom = parseExObjListAtom(in);
        int _startPos = in.getPosition();
        while (in.getPosition() - _startPos < _s.rh.recLen-12) {
            ExObjListSubContainer _t = parseExObjListSubContainer(in);
            _s.rgChildRec.add(_t);
        }
        return _s;
    }
    void write(ExObjListContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.exObjListAtom, out);
        for (ExObjListSubContainer _i: _s.rgChildRec) {
            write(_i, out);
        }
    }
    ExOleLinkContainer parseExOleLinkContainer(LEInputStream in) throws IOException  {
        ExOleLinkContainer _s = new ExOleLinkContainer();
        Object _m;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FCE)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FCE for value " + String.valueOf(_s.rh) );
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
    void write(ExOleLinkContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.exOleLinkAtom, out);
        write(_s.exOleObjAtom, out);
        if (_s.menuNameAtom != null) write(_s.menuNameAtom, out);
        if (_s.progIdAtom != null) write(_s.progIdAtom, out);
        if (_s.clipboardNameAtom != null) write(_s.clipboardNameAtom, out);
        if (_s.metafile != null) write(_s.metafile, out);
    }
    ExOleEmbedContainer parseExOleEmbedContainer(LEInputStream in) throws IOException  {
        ExOleEmbedContainer _s = new ExOleEmbedContainer();
        Object _m;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FCC)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FCC for value " + String.valueOf(_s.rh) );
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
    void write(ExOleEmbedContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.exOleEmbedAtom, out);
        write(_s.exOleObjAtom, out);
        if (_s.menuNameAtom != null) write(_s.menuNameAtom, out);
        if (_s.progIdAtom != null) write(_s.progIdAtom, out);
        if (_s.clipboardNameAtom != null) write(_s.clipboardNameAtom, out);
        if (_s.metafile != null) write(_s.metafile, out);
    }
    OfficeArtFDGGBlock parseOfficeArtFDGGBlock(LEInputStream in) throws IOException  {
        OfficeArtFDGGBlock _s = new OfficeArtFDGGBlock();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F006)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F006 for value " + String.valueOf(_s.rh) );
        }
        _s.head = parseOfficeArtFDGG(in);
        _c = _s.head.cidcl-1;
        _s.Rgidcl = new OfficeArtIDCL[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.Rgidcl[_i] = parseOfficeArtIDCL(in);
        }
        return _s;
    }
    void write(OfficeArtFDGGBlock _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.head, out);
        for (OfficeArtIDCL _i: _s.Rgidcl) {
            write(_i, out);
        }
    }
    ProtectionBooleanProperties parseProtectionBooleanProperties(LEInputStream in) throws IOException  {
        ProtectionBooleanProperties _s = new ProtectionBooleanProperties();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x007F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x007F for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fLockAgainstGrouping = in.readbit();
        _s.fLockAdjustHandles = in.readbit();
        _s.fLockText = in.readbit();
        _s.fLockVertices = in.readbit();
        _s.fLockCropping = in.readbit();
        _s.fLockAgainstSelect = in.readbit();
        _s.fLockPosition = in.readbit();
        _s.fLockAspectRatio = in.readbit();
        _s.fLockRotation = in.readbit();
        _s.fLockAgainstUngrouping = in.readbit();
        _s.unused6 = in.readuint6();
        _s.fUsefLockAgainstGrouping = in.readbit();
        _s.fUseLockAdjustHandles = in.readbit();
        _s.fUseLockText = in.readbit();
        _s.fUsefLockVertices = in.readbit();
        _s.fUsefLockCropping = in.readbit();
        _s.fUsefLockAgainstSelect = in.readbit();
        _s.fUsefLockPosition = in.readbit();
        _s.fUsefLockAspectRatio = in.readbit();
        _s.fUsefLockRotation = in.readbit();
        _s.fUsefLockAgainstUngrouping = in.readbit();
        _s.unused2 = in.readuint6();
        return _s;
    }
    void write(ProtectionBooleanProperties _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.fLockAgainstGrouping);
        out.writebit(_s.fLockAdjustHandles);
        out.writebit(_s.fLockText);
        out.writebit(_s.fLockVertices);
        out.writebit(_s.fLockCropping);
        out.writebit(_s.fLockAgainstSelect);
        out.writebit(_s.fLockPosition);
        out.writebit(_s.fLockAspectRatio);
        out.writebit(_s.fLockRotation);
        out.writebit(_s.fLockAgainstUngrouping);
        out.writeuint6(_s.unused6);
        out.writebit(_s.fUsefLockAgainstGrouping);
        out.writebit(_s.fUseLockAdjustHandles);
        out.writebit(_s.fUseLockText);
        out.writebit(_s.fUsefLockVertices);
        out.writebit(_s.fUsefLockCropping);
        out.writebit(_s.fUsefLockAgainstSelect);
        out.writebit(_s.fUsefLockPosition);
        out.writebit(_s.fUsefLockAspectRatio);
        out.writebit(_s.fUsefLockRotation);
        out.writebit(_s.fUsefLockAgainstUngrouping);
        out.writeuint6(_s.unused2);
    }
    Rotation parseRotation(LEInputStream in) throws IOException  {
        Rotation _s = new Rotation();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0004)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0004 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.rotation = parseFixedPoint(in);
        return _s;
    }
    void write(Rotation _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        write(_s.rotation, out);
    }
    ITxid parseITxid(LEInputStream in) throws IOException  {
        ITxid _s = new ITxid();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0080)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0080 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.iTxid = in.readint32();
        return _s;
    }
    void write(ITxid _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.iTxid);
    }
    DxTextLeft parseDxTextLeft(LEInputStream in) throws IOException  {
        DxTextLeft _s = new DxTextLeft();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0081)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0081 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.dxTextLeft = in.readint32();
        return _s;
    }
    void write(DxTextLeft _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.dxTextLeft);
    }
    DyTextTop parseDyTextTop(LEInputStream in) throws IOException  {
        DyTextTop _s = new DyTextTop();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0082)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0082 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.dyTextTop = in.readint32();
        return _s;
    }
    void write(DyTextTop _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.dyTextTop);
    }
    DxTextRight parseDxTextRight(LEInputStream in) throws IOException  {
        DxTextRight _s = new DxTextRight();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0083)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0083 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.dxTextRight = in.readint32();
        return _s;
    }
    void write(DxTextRight _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.dxTextRight);
    }
    DyTextBottom parseDyTextBottom(LEInputStream in) throws IOException  {
        DyTextBottom _s = new DyTextBottom();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0084)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0084 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.dyTextBottom = in.readint32();
        return _s;
    }
    void write(DyTextBottom _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.dyTextBottom);
    }
    WrapText parseWrapText(LEInputStream in) throws IOException  {
        WrapText _s = new WrapText();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0085)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0085 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.wrapText = in.readuint32();
        if (!(_s.wrapText<5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.wrapText<5 for value " + String.valueOf(_s.wrapText) );
        }
        return _s;
    }
    void write(WrapText _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.wrapText);
    }
    AnchorText parseAnchorText(LEInputStream in) throws IOException  {
        AnchorText _s = new AnchorText();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0087)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0087 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.anchorText = in.readuint32();
        if (!(_s.anchorText<=9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.anchorText<=9 for value " + String.valueOf(_s.anchorText) );
        }
        return _s;
    }
    void write(AnchorText _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.anchorText);
    }
    TextBooleanProperties parseTextBooleanProperties(LEInputStream in) throws IOException  {
        TextBooleanProperties _s = new TextBooleanProperties();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x00BF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x00BF for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.unused1 = in.readbit();
        _s.fFitShapeToText = in.readbit();
        _s.unused2 = in.readbit();
        _s.fAutoTextMargin = in.readbit();
        _s.fSelectText = in.readbit();
        _s.unused3a = in.readuint3();
        _s.unused3b = in.readuint8();
        _s.unused4 = in.readbit();
        _s.fUsefFitShapeToText = in.readbit();
        _s.unused5 = in.readbit();
        _s.fUsefAutoTextMargin = in.readbit();
        _s.fUsefSelectText = in.readbit();
        _s.unused6a = in.readuint3();
        _s.unused6b = in.readuint8();
        return _s;
    }
    void write(TextBooleanProperties _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.unused1);
        out.writebit(_s.fFitShapeToText);
        out.writebit(_s.unused2);
        out.writebit(_s.fAutoTextMargin);
        out.writebit(_s.fSelectText);
        out.writeuint3(_s.unused3a);
        out.writeuint8(_s.unused3b);
        out.writebit(_s.unused4);
        out.writebit(_s.fUsefFitShapeToText);
        out.writebit(_s.unused5);
        out.writebit(_s.fUsefAutoTextMargin);
        out.writebit(_s.fUsefSelectText);
        out.writeuint3(_s.unused6a);
        out.writeuint8(_s.unused6b);
    }
    HspNext parseHspNext(LEInputStream in) throws IOException  {
        HspNext _s = new HspNext();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x008A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x008A for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.hspNext = in.readint32();
        return _s;
    }
    void write(HspNext _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.hspNext);
    }
    ShapePath parseShapePath(LEInputStream in) throws IOException  {
        ShapePath _s = new ShapePath();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0144)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0144 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.shapePath = in.readuint32();
        if (!(_s.shapePath<=4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.shapePath<=4 for value " + String.valueOf(_s.shapePath) );
        }
        return _s;
    }
    void write(ShapePath _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.shapePath);
    }
    GeometryBooleanProperties parseGeometryBooleanProperties(LEInputStream in) throws IOException  {
        GeometryBooleanProperties _s = new GeometryBooleanProperties();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x017F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x017F for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fFillOk = in.readbit();
        _s.fFillShadeShapeOK = in.readbit();
        _s.fGtextOK = in.readbit();
        _s.fLineOK = in.readbit();
        _s.f3DOK = in.readbit();
        _s.fShadowOK = in.readbit();
        _s.unuseda = in.readbit();
        _s.unusedb = in.readbit();
        _s.unused2 = in.readuint8();
        _s.fUsefFillOK = in.readbit();
        _s.fUsefFillShadeShapeOK = in.readbit();
        _s.fUsefGtextOK = in.readbit();
        _s.fUsefLineOK = in.readbit();
        _s.fUsef3DOK = in.readbit();
        _s.fUsefShadowOK = in.readbit();
        _s.unused3a = in.readbit();
        _s.unused3b = in.readbit();
        _s.unused4 = in.readuint8();
        return _s;
    }
    void write(GeometryBooleanProperties _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.fFillOk);
        out.writebit(_s.fFillShadeShapeOK);
        out.writebit(_s.fGtextOK);
        out.writebit(_s.fLineOK);
        out.writebit(_s.f3DOK);
        out.writebit(_s.fShadowOK);
        out.writebit(_s.unuseda);
        out.writebit(_s.unusedb);
        out.writeuint8(_s.unused2);
        out.writebit(_s.fUsefFillOK);
        out.writebit(_s.fUsefFillShadeShapeOK);
        out.writebit(_s.fUsefGtextOK);
        out.writebit(_s.fUsefLineOK);
        out.writebit(_s.fUsef3DOK);
        out.writebit(_s.fUsefShadowOK);
        out.writebit(_s.unused3a);
        out.writebit(_s.unused3b);
        out.writeuint8(_s.unused4);
    }
    FillType parseFillType(LEInputStream in) throws IOException  {
        FillType _s = new FillType();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0180)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0180 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fillType = in.readuint32();
        if (!(_s.fillType<=9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fillType<=9 for value " + String.valueOf(_s.fillType) );
        }
        return _s;
    }
    void write(FillType _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.fillType);
    }
    FillColor parseFillColor(LEInputStream in) throws IOException  {
        FillColor _s = new FillColor();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0181)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0181 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fillColor = parseOfficeArtCOLORREF(in);
        return _s;
    }
    void write(FillColor _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        write(_s.fillColor, out);
    }
    FillBackColor parseFillBackColor(LEInputStream in) throws IOException  {
        FillBackColor _s = new FillBackColor();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0183)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0183 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fillBackColor = parseOfficeArtCOLORREF(in);
        return _s;
    }
    void write(FillBackColor _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        write(_s.fillBackColor, out);
    }
    FillBlip parseFillBlip(LEInputStream in) throws IOException  {
        FillBlip _s = new FillBlip();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0186)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0186 for value " + String.valueOf(_s.opid) );
        }
        _s.fillBlip = in.readuint32();
        return _s;
    }
    void write(FillBlip _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.fillBlip);
    }
    FillRectRight parseFillRectRight(LEInputStream in) throws IOException  {
        FillRectRight _s = new FillRectRight();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0193)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0193 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fillRectRight = in.readint32();
        return _s;
    }
    void write(FillRectRight _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.fillRectRight);
    }
    FillRectBottom parseFillRectBottom(LEInputStream in) throws IOException  {
        FillRectBottom _s = new FillRectBottom();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0194)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0194 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fillRectBottom = in.readint32();
        return _s;
    }
    void write(FillRectBottom _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.fillRectBottom);
    }
    FillStyleBooleanProperties parseFillStyleBooleanProperties(LEInputStream in) throws IOException  {
        FillStyleBooleanProperties _s = new FillStyleBooleanProperties();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01BF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01BF for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fNoFillHitText = in.readbit();
        _s.fillUseRect = in.readbit();
        _s.fillShape = in.readbit();
        _s.fHitTestFill = in.readbit();
        _s.fFilled = in.readbit();
        _s.fUseShapeAnchor = in.readbit();
        _s.fRecolorFillAsPicture = in.readbit();
        _s.unused1a = in.readbit();
        _s.unused1b = in.readuint8();
        _s.fUseNoFillHitTest = in.readbit();
        _s.fUseFillUseRext = in.readbit();
        _s.fUseFillShape = in.readbit();
        _s.fUseHitTestFill = in.readbit();
        _s.fUseFilled = in.readbit();
        _s.fUseUseShapeAnchor = in.readbit();
        _s.fUsefRecolorFillAsPicture = in.readbit();
        _s.unused2a = in.readbit();
        _s.unused2b = in.readuint8();
        return _s;
    }
    void write(FillStyleBooleanProperties _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.fNoFillHitText);
        out.writebit(_s.fillUseRect);
        out.writebit(_s.fillShape);
        out.writebit(_s.fHitTestFill);
        out.writebit(_s.fFilled);
        out.writebit(_s.fUseShapeAnchor);
        out.writebit(_s.fRecolorFillAsPicture);
        out.writebit(_s.unused1a);
        out.writeuint8(_s.unused1b);
        out.writebit(_s.fUseNoFillHitTest);
        out.writebit(_s.fUseFillUseRext);
        out.writebit(_s.fUseFillShape);
        out.writebit(_s.fUseHitTestFill);
        out.writebit(_s.fUseFilled);
        out.writebit(_s.fUseUseShapeAnchor);
        out.writebit(_s.fUsefRecolorFillAsPicture);
        out.writebit(_s.unused2a);
        out.writeuint8(_s.unused2b);
    }
    LineColor parseLineColor(LEInputStream in) throws IOException  {
        LineColor _s = new LineColor();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01C0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01C0 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.lineColor = parseOfficeArtCOLORREF(in);
        return _s;
    }
    void write(LineColor _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        write(_s.lineColor, out);
    }
    LineBackColor parseLineBackColor(LEInputStream in) throws IOException  {
        LineBackColor _s = new LineBackColor();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01C2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01C2 for value " + String.valueOf(_s.opid) );
        }
        _s.lineBackColor = parseOfficeArtCOLORREF(in);
        return _s;
    }
    void write(LineBackColor _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        write(_s.lineBackColor, out);
    }
    LineFillBlip parseLineFillBlip(LEInputStream in) throws IOException  {
        LineFillBlip _s = new LineFillBlip();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01C5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01C5 for value " + String.valueOf(_s.opid) );
        }
        _s.lineFillBlip = in.readuint32();
        return _s;
    }
    void write(LineFillBlip _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.lineFillBlip);
    }
    LineWidth parseLineWidth(LEInputStream in) throws IOException  {
        LineWidth _s = new LineWidth();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01CB)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01CB for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.lineWidth = in.readuint32();
        return _s;
    }
    void write(LineWidth _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.lineWidth);
    }
    LineStartArrowhead parseLineStartArrowhead(LEInputStream in) throws IOException  {
        LineStartArrowhead _s = new LineStartArrowhead();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01D0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01D0 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.lineStartArrowhead = in.readuint32();
        if (!(_s.lineStartArrowhead<=8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.lineStartArrowhead<=8 for value " + String.valueOf(_s.lineStartArrowhead) );
        }
        return _s;
    }
    void write(LineStartArrowhead _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.lineStartArrowhead);
    }
    LineEndArrowhead parseLineEndArrowhead(LEInputStream in) throws IOException  {
        LineEndArrowhead _s = new LineEndArrowhead();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01D1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01D1 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.lineEndArrowhead = in.readuint32();
        if (!(_s.lineEndArrowhead<=8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.lineEndArrowhead<=8 for value " + String.valueOf(_s.lineEndArrowhead) );
        }
        return _s;
    }
    void write(LineEndArrowhead _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.lineEndArrowhead);
    }
    LineJoinStyle parseLineJoinStyle(LEInputStream in) throws IOException  {
        LineJoinStyle _s = new LineJoinStyle();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01D6)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01D6 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.lineJoinStyle = in.readuint32();
        if (!(_s.lineJoinStyle<=2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.lineJoinStyle<=2 for value " + String.valueOf(_s.lineJoinStyle) );
        }
        return _s;
    }
    void write(LineJoinStyle _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.lineJoinStyle);
    }
    LineStyleBooleanProperties parseLineStyleBooleanProperties(LEInputStream in) throws IOException  {
        LineStyleBooleanProperties _s = new LineStyleBooleanProperties();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x01FF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x01FF for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fNoLineDrawDash = in.readbit();
        _s.fLineFillShape = in.readbit();
        _s.fHitTestLine = in.readbit();
        _s.fLine = in.readbit();
        _s.fArrowHeadsOK = in.readbit();
        _s.fInsetPenOK = in.readbit();
        _s.fInsetPen = in.readbit();
        _s.reserved1 = in.readbit();
        _s.reserved2 = in.readbit();
        _s.fLineOpaqueBackColor = in.readbit();
        _s.unused1 = in.readuint6();
        _s.fUseNoLineDrawDash = in.readbit();
        _s.fUseLineFillShape = in.readbit();
        _s.fUseHitTestLine = in.readbit();
        _s.fUsefLine = in.readbit();
        _s.fUsefArrowHeadsOK = in.readbit();
        _s.fUseInsetPenOK = in.readbit();
        _s.fUseInsetPen = in.readbit();
        _s.unused2 = in.readbit();
        _s.unused3 = in.readbit();
        _s.fUsefLineOpaqueBackColor = in.readbit();
        _s.unused4 = in.readuint6();
        return _s;
    }
    void write(LineStyleBooleanProperties _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.fNoLineDrawDash);
        out.writebit(_s.fLineFillShape);
        out.writebit(_s.fHitTestLine);
        out.writebit(_s.fLine);
        out.writebit(_s.fArrowHeadsOK);
        out.writebit(_s.fInsetPenOK);
        out.writebit(_s.fInsetPen);
        out.writebit(_s.reserved1);
        out.writebit(_s.reserved2);
        out.writebit(_s.fLineOpaqueBackColor);
        out.writeuint6(_s.unused1);
        out.writebit(_s.fUseNoLineDrawDash);
        out.writebit(_s.fUseLineFillShape);
        out.writebit(_s.fUseHitTestLine);
        out.writebit(_s.fUsefLine);
        out.writebit(_s.fUsefArrowHeadsOK);
        out.writebit(_s.fUseInsetPenOK);
        out.writebit(_s.fUseInsetPen);
        out.writebit(_s.unused2);
        out.writebit(_s.unused3);
        out.writebit(_s.fUsefLineOpaqueBackColor);
        out.writeuint6(_s.unused4);
    }
    ShadowColor parseShadowColor(LEInputStream in) throws IOException  {
        ShadowColor _s = new ShadowColor();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0201)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0201 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.shadowColor = parseOfficeArtCOLORREF(in);
        return _s;
    }
    void write(ShadowColor _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        write(_s.shadowColor, out);
    }
    ShadowStyleBooleanPropertiesr parseShadowStyleBooleanPropertiesr(LEInputStream in) throws IOException  {
        ShadowStyleBooleanPropertiesr _s = new ShadowStyleBooleanPropertiesr();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x023F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x023F for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fshadowObscured = in.readbit();
        _s.fShadow = in.readbit();
        _s.unused1 = in.readuint14();
        _s.fUsefshadowObscured = in.readbit();
        _s.fUsefShadow = in.readbit();
        _s.unused2 = in.readuint14();
        return _s;
    }
    void write(ShadowStyleBooleanPropertiesr _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.fshadowObscured);
        out.writebit(_s.fShadow);
        out.writeuint14(_s.unused1);
        out.writebit(_s.fUsefshadowObscured);
        out.writebit(_s.fUsefShadow);
        out.writeuint14(_s.unused2);
    }
    HspMaster parseHspMaster(LEInputStream in) throws IOException  {
        HspMaster _s = new HspMaster();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0301)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0301 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.hspMaster = in.readuint32();
        return _s;
    }
    void write(HspMaster _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.hspMaster);
    }
    BWMode parseBWMode(LEInputStream in) throws IOException  {
        BWMode _s = new BWMode();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0304)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0304 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.bWMode = in.readuint32();
        if (!(_s.bWMode<=10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.bWMode<=10 for value " + String.valueOf(_s.bWMode) );
        }
        return _s;
    }
    void write(BWMode _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.bWMode);
    }
    ShapeBooleanProperties parseShapeBooleanProperties(LEInputStream in) throws IOException  {
        ShapeBooleanProperties _s = new ShapeBooleanProperties();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x033F)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x033F for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.fBackground = in.readbit();
        _s.reserved1 = in.readbit();
        _s.fInitiator = in.readbit();
        _s.fLockShapeType = in.readbit();
        _s.fPreferRelativeResize = in.readbit();
        _s.fOleIcon = in.readbit();
        _s.fFlipVOverride = in.readbit();
        _s.fFlipHOverride = in.readbit();
        _s.fPolicyBarcode = in.readbit();
        _s.fPolicyLabel = in.readbit();
        _s.unused1 = in.readbit();
        _s.unused2 = in.readbit();
        _s.unused3 = in.readuint4();
        _s.fUsefBackground = in.readbit();
        _s.unused4 = in.readbit();
        _s.fUsefInitiator = in.readbit();
        _s.fUsefLockShapeType = in.readbit();
        _s.fusePreferrelativeResize = in.readbit();
        _s.fUsefOleIcon = in.readbit();
        _s.fUsefFlipVOverride = in.readbit();
        _s.fUsefFlipHOverride = in.readbit();
        _s.fUsefPolicyBarcode = in.readbit();
        _s.fUsefPolicyLabel = in.readbit();
        _s.unused5 = in.readbit();
        _s.unused6 = in.readbit();
        _s.unused7 = in.readuint4();
        return _s;
    }
    void write(ShapeBooleanProperties _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writebit(_s.fBackground);
        out.writebit(_s.reserved1);
        out.writebit(_s.fInitiator);
        out.writebit(_s.fLockShapeType);
        out.writebit(_s.fPreferRelativeResize);
        out.writebit(_s.fOleIcon);
        out.writebit(_s.fFlipVOverride);
        out.writebit(_s.fFlipHOverride);
        out.writebit(_s.fPolicyBarcode);
        out.writebit(_s.fPolicyLabel);
        out.writebit(_s.unused1);
        out.writebit(_s.unused2);
        out.writeuint4(_s.unused3);
        out.writebit(_s.fUsefBackground);
        out.writebit(_s.unused4);
        out.writebit(_s.fUsefInitiator);
        out.writebit(_s.fUsefLockShapeType);
        out.writebit(_s.fusePreferrelativeResize);
        out.writebit(_s.fUsefOleIcon);
        out.writebit(_s.fUsefFlipVOverride);
        out.writebit(_s.fUsefFlipHOverride);
        out.writebit(_s.fUsefPolicyBarcode);
        out.writebit(_s.fUsefPolicyLabel);
        out.writebit(_s.unused5);
        out.writebit(_s.unused6);
        out.writeuint4(_s.unused7);
    }
    LidRegroup parseLidRegroup(LEInputStream in) throws IOException  {
        LidRegroup _s = new LidRegroup();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0388)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0388 for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fBid == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fBid == false for value " + String.valueOf(_s.opid) );
        }
        if (!(_s.opid.fComplex == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.fComplex == false for value " + String.valueOf(_s.opid) );
        }
        _s.lidRegroup = in.readuint32();
        return _s;
    }
    void write(LidRegroup _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeuint32(_s.lidRegroup);
    }
    WzFillId parseWzFillId(LEInputStream in) throws IOException  {
        WzFillId _s = new WzFillId();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        if (!(_s.opid.opid == 0x0403)) {
            throw new IncorrectValueException(in.getPosition() + "_s.opid.opid == 0x0403 for value " + String.valueOf(_s.opid) );
        }
        _s.wzFillId = in.readint32();
        return _s;
    }
    void write(WzFillId _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.wzFillId);
    }
    OfficeArtClientAnchor parseOfficeArtClientAnchor(LEInputStream in) throws IOException  {
        OfficeArtClientAnchor _s = new OfficeArtClientAnchor();
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF010)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF010 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x8 || _s.rh.recLen == 0x10)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x8 || _s.rh.recLen == 0x10 for value " + String.valueOf(_s.rh) );
        }
        if (_s.rh.recLen==0x8) {
            _s.rect1 = parseSmallRectStruct(in);
        }
        if (_s.rh.recLen==0x10) {
            _s.rect2 = parseRectStruct(in);
        }
        return _s;
    }
    void write(OfficeArtClientAnchor _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        if (_s.rh.recLen==0x8) {
            write(_s.rect1, out);
        }
        if (_s.rh.recLen==0x10) {
            write(_s.rect2, out);
        }
    }
    MouseInteractiveInfoContainer parseMouseInteractiveInfoContainer(LEInputStream in) throws IOException  {
        MouseInteractiveInfoContainer _s = new MouseInteractiveInfoContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xFF2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xFF2 for value " + String.valueOf(_s.rh) );
        }
        _s.interactiveInfoAtom = parseInteractiveInfoAtom(in);
        if (_s.rh.recLen>24) {
            _s.macroNameAtom = parseMacroNameAtom(in);
        }
        return _s;
    }
    void write(MouseInteractiveInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.interactiveInfoAtom, out);
        if (_s.rh.recLen>24) {
            write(_s.macroNameAtom, out);
        }
    }
    OfficeArtFOPTE parseOfficeArtFOPTE(LEInputStream in) throws IOException  {
        OfficeArtFOPTE _s = new OfficeArtFOPTE();
        _s.opid = parseOfficeArtFOPTEOPID(in);
        _s.op = in.readint32();
        return _s;
    }
    void write(OfficeArtFOPTE _s, LEOutputStream out) throws IOException  {
        write(_s.opid, out);
        out.writeint32(_s.op);
    }
    Fib parseFib(LEInputStream in) throws IOException  {
        Fib _s = new Fib();
        int _c;
        _s.base = parseFibBase(in);
        _s.csw = in.readuint16();
        if (!(_s.csw == 14)) {
            throw new IncorrectValueException(in.getPosition() + "_s.csw == 14 for value " + String.valueOf(_s.csw) );
        }
        _s.fibRgW = parseFibRgW97(in);
        _s.cslw = in.readuint16();
        if (!(_s.cslw == 22)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cslw == 22 for value " + String.valueOf(_s.cslw) );
        }
        _s.fibRgLw = parseFibRgLw97(in);
        _s.cbRgFcLcb = in.readuint16();
        if (!(_s.cbRgFcLcb == 0x5D || _s.cbRgFcLcb == 0x6C || _s.cbRgFcLcb == 0x88 || _s.cbRgFcLcb == 0xA4 || _s.cbRgFcLcb == 0xB7)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cbRgFcLcb == 0x5D || _s.cbRgFcLcb == 0x6C || _s.cbRgFcLcb == 0x88 || _s.cbRgFcLcb == 0xA4 || _s.cbRgFcLcb == 0xB7 for value " + String.valueOf(_s.cbRgFcLcb) );
        }
        _s.fibRgFcLcbBlob = parseFibRgFcLcb97(in);
        if (_s.cbRgFcLcb>=0x6C) {
            _s.fibRgFcLcbBlob2 = parseFibRgFcLcb2000(in);
        }
        if (_s.cbRgFcLcb>=0x88) {
            _s.fibRgFcLcbBlob3 = parseFibRgFcLcb2002(in);
        }
        _s.cswNew = in.readuint16();
        if (!(_s.cswNew == 0 || _s.cswNew == 2 || _s.cswNew == 5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cswNew == 0 || _s.cswNew == 2 || _s.cswNew == 5 for value " + String.valueOf(_s.cswNew) );
        }
        _c = 2*_s.cswNew;
        _s.fibRgCswNew = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.fibRgCswNew[_i] = in.readuint8();
        }
        _c = _s.fibRgLw.cbMac-156-8*_s.cbRgFcLcb-2*_s.cswNew;
        _s.trail = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.trail[_i] = in.readuint8();
        }
        return _s;
    }
    void write(Fib _s, LEOutputStream out) throws IOException  {
        write(_s.base, out);
        out.writeuint16(_s.csw);
        write(_s.fibRgW, out);
        out.writeuint16(_s.cslw);
        write(_s.fibRgLw, out);
        out.writeuint16(_s.cbRgFcLcb);
        write(_s.fibRgFcLcbBlob, out);
        if (_s.cbRgFcLcb>=0x6C) {
            write(_s.fibRgFcLcbBlob2, out);
        }
        if (_s.cbRgFcLcb>=0x88) {
            write(_s.fibRgFcLcbBlob3, out);
        }
        out.writeuint16(_s.cswNew);
        for (byte _i: _s.fibRgCswNew) {
            out.writeuint8(_i);
        }
        for (byte _i: _s.trail) {
            out.writeuint8(_i);
        }
    }
    STSH parseSTSH(LEInputStream in) throws IOException  {
        STSH _s = new STSH();
        int _c;
        _s.lpstshi = parseLPStshi(in);
        _c = 20;
        _s.rglpstd = new LPStd[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.rglpstd[_i] = parseLPStd(in);
        }
        return _s;
    }
    void write(STSH _s, LEOutputStream out) throws IOException  {
        write(_s.lpstshi, out);
        for (LPStd _i: _s.rglpstd) {
            write(_i, out);
        }
    }
    Clx parseClx(LEInputStream in) throws IOException  {
        Clx _s = new Clx();
        Object _m;
        boolean _atend;
        int _i;
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                Pcr _t = parsePcr(in);
                _s.RgPrc.add(_t);
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
        _s.pcdt = parsePcdt(in);
        return _s;
    }
    void write(Clx _s, LEOutputStream out) throws IOException  {
        for (Pcr _i: _s.RgPrc) {
            write(_i, out);
        }
        write(_s.pcdt, out);
    }
    Pcr parsePcr(LEInputStream in) throws IOException  {
        Pcr _s = new Pcr();
        _s.clxt = in.readuint8();
        if (!(_s.clxt == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.clxt == 1 for value " + String.valueOf(_s.clxt) );
        }
        _s.prcData = parsePrcData(in);
        return _s;
    }
    void write(Pcr _s, LEOutputStream out) throws IOException  {
        out.writeuint8(_s.clxt);
        write(_s.prcData, out);
    }
    Prm parsePrm(LEInputStream in) throws IOException  {
        Prm _s = new Prm();
        Object _m;
        _m = in.setMark();
        try {
            _s.prm = parsePrm0(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.prm = parsePrm1(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(Prm _s, LEOutputStream out) throws IOException  {
        if (_s.prm instanceof Prm0) {
            write((Prm0)_s.prm, out);
        } else if (_s.prm instanceof Prm1) {
            write((Prm1)_s.prm, out);
        }
    }
    OfficeArtBlipEMF parseOfficeArtBlipEMF(LEInputStream in) throws IOException  {
        OfficeArtBlipEMF _s = new OfficeArtBlipEMF();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x3D4 || _s.rh.recInstance == 0x3D5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x3D4 || _s.rh.recInstance == 0x3D5 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01A)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF01A for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipEMF _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x3D5) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        write(_s.metafileHeader, out);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtBlipWMF parseOfficeArtBlipWMF(LEInputStream in) throws IOException  {
        OfficeArtBlipWMF _s = new OfficeArtBlipWMF();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x216 || _s.rh.recInstance == 0x217)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x216 || _s.rh.recInstance == 0x217 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01B)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF01B for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipWMF _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x217) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        write(_s.metafileHeader, out);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtBlipPICT parseOfficeArtBlipPICT(LEInputStream in) throws IOException  {
        OfficeArtBlipPICT _s = new OfficeArtBlipPICT();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x542 || _s.rh.recInstance == 0x543)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x542 || _s.rh.recInstance == 0x543 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF01C)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF01C for value " + String.valueOf(_s.rh) );
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
    void write(OfficeArtBlipPICT _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        for (byte _i: _s.rgbUid1) {
            out.writeuint8(_i);
        }
        if (_s.rh.recInstance == 0x543) {
            for (byte _i: _s.rgbUid2) {
                out.writeuint8(_i);
            }
        }
        write(_s.metafileHeader, out);
        for (byte _i: _s.BLIPFileData) {
            out.writeuint8(_i);
        }
    }
    OfficeArtBlip parseOfficeArtBlip(LEInputStream in) throws IOException  {
        OfficeArtBlip _s = new OfficeArtBlip();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseOfficeArtBlipEMF(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipWMF(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipPICT(in);
        } catch (IOException _xxx) {
            if (!(_xxx instanceof IncorrectValueException) && !(_xxx instanceof java.io.EOFException)) throw _xxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipJPEG(in);
        } catch (IOException _xxxx) {
            if (!(_xxxx instanceof IncorrectValueException) && !(_xxxx instanceof java.io.EOFException)) throw _xxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipPNG(in);
        } catch (IOException _xxxxx) {
            if (!(_xxxxx instanceof IncorrectValueException) && !(_xxxxx instanceof java.io.EOFException)) throw _xxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOfficeArtBlipDIB(in);
        } catch (IOException _xxxxxx) {
            if (!(_xxxxxx instanceof IncorrectValueException) && !(_xxxxxx instanceof java.io.EOFException)) throw _xxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxx);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseOfficeArtBlipTIFF(in);
        }}}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(OfficeArtBlip _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof OfficeArtBlipEMF) {
            write((OfficeArtBlipEMF)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlipWMF) {
            write((OfficeArtBlipWMF)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlipPICT) {
            write((OfficeArtBlipPICT)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlipJPEG) {
            write((OfficeArtBlipJPEG)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlipPNG) {
            write((OfficeArtBlipPNG)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlipDIB) {
            write((OfficeArtBlipDIB)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlipTIFF) {
            write((OfficeArtBlipTIFF)_s.anon, out);
        }
    }
    ZoomViewInfoAtom parseZoomViewInfoAtom(LEInputStream in) throws IOException  {
        ZoomViewInfoAtom _s = new ZoomViewInfoAtom();
        int _c;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3FD)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3FD for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x34)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x34 for value " + String.valueOf(_s.rh) );
        }
        _s.curScale = parseScalingStruct(in);
        _c = 24;
        _s.unused1 = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.unused1[_i] = in.readuint8();
        }
        _s.origin = parsePointStruct(in);
        _s.fUseVarScale = in.readuint8();
        if (!(_s.fUseVarScale == 0 || _s.fUseVarScale == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fUseVarScale == 0 || _s.fUseVarScale == 1 for value " + String.valueOf(_s.fUseVarScale) );
        }
        _s.fDraftMode = in.readuint8();
        _s.unused2 = in.readuint16();
        return _s;
    }
    void write(ZoomViewInfoAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.curScale, out);
        for (byte _i: _s.unused1) {
            out.writeuint8(_i);
        }
        write(_s.origin, out);
        out.writeuint8(_s.fUseVarScale);
        out.writeuint8(_s.fDraftMode);
        out.writeuint16(_s.unused2);
    }
    DocProgTagsSubContainerOrAtom parseDocProgTagsSubContainerOrAtom(LEInputStream in) throws IOException  {
        DocProgTagsSubContainerOrAtom _s = new DocProgTagsSubContainerOrAtom();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseProgStringTagContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseDocProgBinaryTagContainerOrAtom(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(DocProgTagsSubContainerOrAtom _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof ProgStringTagContainer) {
            write((ProgStringTagContainer)_s.anon, out);
        } else if (_s.anon instanceof DocProgBinaryTagContainerOrAtom) {
            write((DocProgBinaryTagContainerOrAtom)_s.anon, out);
        }
    }
    NotesTextViewInfoContainer parseNotesTextViewInfoContainer(LEInputStream in) throws IOException  {
        NotesTextViewInfoContainer _s = new NotesTextViewInfoContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x413)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x413 for value " + String.valueOf(_s.rh) );
        }
        _s.zoomViewInfo = parseZoomViewInfoAtom(in);
        return _s;
    }
    void write(NotesTextViewInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.zoomViewInfo, out);
    }
    OutlineViewInfoContainer parseOutlineViewInfoContainer(LEInputStream in) throws IOException  {
        OutlineViewInfoContainer _s = new OutlineViewInfoContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x407)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x407 for value " + String.valueOf(_s.rh) );
        }
        _s.noZoomViewInfo = parseNoZoomViewInfoAtom(in);
        return _s;
    }
    void write(OutlineViewInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.noZoomViewInfo, out);
    }
    NormalViewSetInfoContainer parseNormalViewSetInfoContainer(LEInputStream in) throws IOException  {
        NormalViewSetInfoContainer _s = new NormalViewSetInfoContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x414)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x414 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recLen == 0x1C)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recLen == 0x1C for value " + String.valueOf(_s.rh) );
        }
        _s.normalViewSetInfoAtom = parseNormalViewSetInfoAtom(in);
        return _s;
    }
    void write(NormalViewSetInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.normalViewSetInfoAtom, out);
    }
    SlideListWithTextSubContainerOrAtom parseSlideListWithTextSubContainerOrAtom(LEInputStream in) throws IOException  {
        SlideListWithTextSubContainerOrAtom _s = new SlideListWithTextSubContainerOrAtom();
        Object _m;
        boolean _atend;
        int _i;
        _s.slidePersistAtom = parseSlidePersistAtom(in);
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                TextContainer _t = parseTextContainer(in);
                _s.atoms.add(_t);
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
    void write(SlideListWithTextSubContainerOrAtom _s, LEOutputStream out) throws IOException  {
        write(_s.slidePersistAtom, out);
        for (TextContainer _i: _s.atoms) {
            write(_i, out);
        }
    }
    TextContainerInteractiveInfo parseTextContainerInteractiveInfo(LEInputStream in) throws IOException  {
        TextContainerInteractiveInfo _s = new TextContainerInteractiveInfo();
        Object _m;
        _m = in.setMark();
        try {
            _s.interactive = parseMouseInteractiveInfoContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.interactive = parseMouseTextInteractiveInfoAtom(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(TextContainerInteractiveInfo _s, LEOutputStream out) throws IOException  {
        if (_s.interactive instanceof MouseInteractiveInfoContainer) {
            write((MouseInteractiveInfoContainer)_s.interactive, out);
        } else if (_s.interactive instanceof MouseTextInteractiveInfoAtom) {
            write((MouseTextInteractiveInfoAtom)_s.interactive, out);
        }
    }
    TextPFRun parseTextPFRun(LEInputStream in) throws IOException  {
        TextPFRun _s = new TextPFRun();
        _s.count = in.readuint32();
        if (!(_s.count>0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.count>0 for value " + String.valueOf(_s.count) );
        }
        _s.indentLevel = in.readuint16();
        if (!(_s.indentLevel<=4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.indentLevel<=4 for value " + String.valueOf(_s.indentLevel) );
        }
        _s.pf = parseTextPFException(in);
        if (!(_s.pf.masks.leftMargin == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.pf.masks.leftMargin == false for value " + String.valueOf(_s.pf) );
        }
        if (!(_s.pf.masks.indent == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.pf.masks.indent == false for value " + String.valueOf(_s.pf) );
        }
        if (!(_s.pf.masks.defaultTabSize == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.pf.masks.defaultTabSize == false for value " + String.valueOf(_s.pf) );
        }
        if (!(_s.pf.masks.tabStops == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.pf.masks.tabStops == false for value " + String.valueOf(_s.pf) );
        }
        return _s;
    }
    void write(TextPFRun _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.count);
        out.writeuint16(_s.indentLevel);
        write(_s.pf, out);
    }
    TextCFRun parseTextCFRun(LEInputStream in) throws IOException  {
        TextCFRun _s = new TextCFRun();
        _s.count = in.readuint32();
        if (!(_s.count>0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.count>0 for value " + String.valueOf(_s.count) );
        }
        if (!(_s.count<1000)) {
            throw new IncorrectValueException(in.getPosition() + "_s.count<1000 for value " + String.valueOf(_s.count) );
        }
        _s.cf = parseTextCFException(in);
        return _s;
    }
    void write(TextCFRun _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.count);
        write(_s.cf, out);
    }
    TextCFExceptionAtom parseTextCFExceptionAtom(LEInputStream in) throws IOException  {
        TextCFExceptionAtom _s = new TextCFExceptionAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA4)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FA4 for value " + String.valueOf(_s.rh) );
        }
        _s.cf = parseTextCFException(in);
        return _s;
    }
    void write(TextCFExceptionAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.cf, out);
    }
    DefaultRulerAtom parseDefaultRulerAtom(LEInputStream in) throws IOException  {
        DefaultRulerAtom _s = new DefaultRulerAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FAB)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FAB for value " + String.valueOf(_s.rh) );
        }
        _s.defaultTextRuler = parseTextRuler(in);
        if (!(_s.defaultTextRuler.fDefaultTabSize == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fDefaultTabSize == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fCLevels == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fCLevels == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fTabStops == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fTabStops == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin1 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fLeftMargin1 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin2 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fLeftMargin2 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin3 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fLeftMargin3 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fLeftMargin4 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fLeftMargin4 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent1 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fIndent1 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent2 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fIndent2 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent3 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fIndent3 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent4 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fIndent4 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        if (!(_s.defaultTextRuler.fIndent5 == true)) {
            throw new IncorrectValueException(in.getPosition() + "_s.defaultTextRuler.fIndent5 == true for value " + String.valueOf(_s.defaultTextRuler) );
        }
        return _s;
    }
    void write(DefaultRulerAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.defaultTextRuler, out);
    }
    TextPFExceptionAtom parseTextPFExceptionAtom(LEInputStream in) throws IOException  {
        TextPFExceptionAtom _s = new TextPFExceptionAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FA5 for value " + String.valueOf(_s.rh) );
        }
        _s.reserved = in.readuint16();
        _s.pf = parseTextPFException(in);
        return _s;
    }
    void write(TextPFExceptionAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint16(_s.reserved);
        write(_s.pf, out);
    }
    TextSIRun parseTextSIRun(LEInputStream in) throws IOException  {
        TextSIRun _s = new TextSIRun();
        _s.count = in.readuint32();
        if (!(_s.count>=1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.count>=1 for value " + String.valueOf(_s.count) );
        }
        _s.si = parseTextSIException(in);
        return _s;
    }
    void write(TextSIRun _s, LEOutputStream out) throws IOException  {
        out.writeuint32(_s.count);
        write(_s.si, out);
    }
    TextSIExceptionAtom parseTextSIExceptionAtom(LEInputStream in) throws IOException  {
        TextSIExceptionAtom _s = new TextSIExceptionAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA9)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FA9 for value " + String.valueOf(_s.rh) );
        }
        _s.textSIException = parseTextSIException(in);
        if (!(_s.textSIException.fPp10ext == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.textSIException.fPp10ext == false for value " + String.valueOf(_s.textSIException) );
        }
        if (!(_s.textSIException.fBidi == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.textSIException.fBidi == false for value " + String.valueOf(_s.textSIException) );
        }
        if (!(_s.textSIException.smartTag == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.textSIException.smartTag == false for value " + String.valueOf(_s.textSIException) );
        }
        return _s;
    }
    void write(TextSIExceptionAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.textSIException, out);
    }
    TextMasterStyleAtom parseTextMasterStyleAtom(LEInputStream in) throws IOException  {
        TextMasterStyleAtom _s = new TextMasterStyleAtom();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 8 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0FA3)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0FA3 for value " + String.valueOf(_s.rh) );
        }
        _s.cLevels = in.readuint16();
        if (!(_s.cLevels<=5)) {
            throw new IncorrectValueException(in.getPosition() + "_s.cLevels<=5 for value " + String.valueOf(_s.cLevels) );
        }
        if (_s.cLevels>0 && _s.rh.recInstance>=5) {
            _s.lstLvl1level = in.readuint16();
        }
        if (_s.cLevels>0) {
            _s.lstLvl1 = parseTextMasterStyleLevel(in);
        }
        if (_s.cLevels>1 && _s.rh.recInstance>=5) {
            _s.lstLvl2level = in.readuint16();
        }
        if (_s.cLevels>1) {
            _s.lstLvl2 = parseTextMasterStyleLevel(in);
        }
        if (_s.cLevels>2 && _s.rh.recInstance>=5) {
            _s.lstLvl3level = in.readuint16();
        }
        if (_s.cLevels>2) {
            _s.lstLvl3 = parseTextMasterStyleLevel(in);
        }
        if (_s.cLevels>3 && _s.rh.recInstance>=5) {
            _s.lstLvl4level = in.readuint16();
        }
        if (_s.cLevels>3) {
            _s.lstLvl4 = parseTextMasterStyleLevel(in);
        }
        if (_s.cLevels>4 && _s.rh.recInstance>=5) {
            _s.lstLvl5level = in.readuint16();
        }
        if (_s.cLevels>4) {
            _s.lstLvl5 = parseTextMasterStyleLevel(in);
        }
        return _s;
    }
    void write(TextMasterStyleAtom _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint16(_s.cLevels);
        if (_s.cLevels>0 && _s.rh.recInstance>=5) {
            out.writeuint16(_s.lstLvl1level);
        }
        if (_s.cLevels>0) {
            write(_s.lstLvl1, out);
        }
        if (_s.cLevels>1 && _s.rh.recInstance>=5) {
            out.writeuint16(_s.lstLvl2level);
        }
        if (_s.cLevels>1) {
            write(_s.lstLvl2, out);
        }
        if (_s.cLevels>2 && _s.rh.recInstance>=5) {
            out.writeuint16(_s.lstLvl3level);
        }
        if (_s.cLevels>2) {
            write(_s.lstLvl3, out);
        }
        if (_s.cLevels>3 && _s.rh.recInstance>=5) {
            out.writeuint16(_s.lstLvl4level);
        }
        if (_s.cLevels>3) {
            write(_s.lstLvl4, out);
        }
        if (_s.cLevels>4 && _s.rh.recInstance>=5) {
            out.writeuint16(_s.lstLvl5level);
        }
        if (_s.cLevels>4) {
            write(_s.lstLvl5, out);
        }
    }
    SlideProgTagsSubContainerOrAtom parseSlideProgTagsSubContainerOrAtom(LEInputStream in) throws IOException  {
        SlideProgTagsSubContainerOrAtom _s = new SlideProgTagsSubContainerOrAtom();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseProgStringTagContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseSlideProgBinaryTagContainer(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(SlideProgTagsSubContainerOrAtom _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof ProgStringTagContainer) {
            write((ProgStringTagContainer)_s.anon, out);
        } else if (_s.anon instanceof SlideProgBinaryTagContainer) {
            write((SlideProgBinaryTagContainer)_s.anon, out);
        }
    }
    ExObjListSubContainer parseExObjListSubContainer(LEInputStream in) throws IOException  {
        ExObjListSubContainer _s = new ExObjListSubContainer();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseExAviMovieContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExCDAudioContainer(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExControlContainer(in);
        } catch (IOException _xxx) {
            if (!(_xxx instanceof IncorrectValueException) && !(_xxx instanceof java.io.EOFException)) throw _xxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExHyperlinkContainer(in);
        } catch (IOException _xxxx) {
            if (!(_xxxx instanceof IncorrectValueException) && !(_xxxx instanceof java.io.EOFException)) throw _xxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExMCIMovieContainer(in);
        } catch (IOException _xxxxx) {
            if (!(_xxxxx instanceof IncorrectValueException) && !(_xxxxx instanceof java.io.EOFException)) throw _xxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExMIDIAudioContainer(in);
        } catch (IOException _xxxxxx) {
            if (!(_xxxxxx instanceof IncorrectValueException) && !(_xxxxxx instanceof java.io.EOFException)) throw _xxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExOleEmbedContainer(in);
        } catch (IOException _xxxxxxx) {
            if (!(_xxxxxxx instanceof IncorrectValueException) && !(_xxxxxxx instanceof java.io.EOFException)) throw _xxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExOleLinkContainer(in);
        } catch (IOException _xxxxxxxx) {
            if (!(_xxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExWAVAudioEmbeddedContainer(in);
        } catch (IOException _xxxxxxxxx) {
            if (!(_xxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExWAVAudioLinkContainer(in);
        } catch (IOException _xxxxxxxxxx) {
            if (!(_xxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseUnknownExObjListSubContainerChild(in);
        }}}}}}}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(ExObjListSubContainer _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof ExAviMovieContainer) {
            write((ExAviMovieContainer)_s.anon, out);
        } else if (_s.anon instanceof ExCDAudioContainer) {
            write((ExCDAudioContainer)_s.anon, out);
        } else if (_s.anon instanceof ExControlContainer) {
            write((ExControlContainer)_s.anon, out);
        } else if (_s.anon instanceof ExHyperlinkContainer) {
            write((ExHyperlinkContainer)_s.anon, out);
        } else if (_s.anon instanceof ExMCIMovieContainer) {
            write((ExMCIMovieContainer)_s.anon, out);
        } else if (_s.anon instanceof ExMIDIAudioContainer) {
            write((ExMIDIAudioContainer)_s.anon, out);
        } else if (_s.anon instanceof ExOleEmbedContainer) {
            write((ExOleEmbedContainer)_s.anon, out);
        } else if (_s.anon instanceof ExOleLinkContainer) {
            write((ExOleLinkContainer)_s.anon, out);
        } else if (_s.anon instanceof ExWAVAudioEmbeddedContainer) {
            write((ExWAVAudioEmbeddedContainer)_s.anon, out);
        } else if (_s.anon instanceof ExWAVAudioLinkContainer) {
            write((ExWAVAudioLinkContainer)_s.anon, out);
        } else if (_s.anon instanceof UnknownExObjListSubContainerChild) {
            write((UnknownExObjListSubContainerChild)_s.anon, out);
        }
    }
    OfficeArtDggContainer parseOfficeArtDggContainer(LEInputStream in) throws IOException  {
        OfficeArtDggContainer _s = new OfficeArtDggContainer();
        Object _m;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F000)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F000 for value " + String.valueOf(_s.rh) );
        }
        _s.drawingGroup = parseOfficeArtFDGGBlock(in);
        _m = in.setMark();
        try {
            _s.blipStore = parseOfficeArtBStoreContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.drawingPrimaryOptions = parseOfficeArtFOPT(in);
        _m = in.setMark();
        try {
            _s.drawingTertiaryOptions = parseOfficeArtTertiaryFOPT(in);
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
            _s.colorMRU = parseOfficeArtColorMRUContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.splitColors = parseOfficeArtSplitMenuColorContainer(in);
        _m = in.setMark();
        try {
            _s.unknown = parseOfficeArtTertiaryFOPT(in);
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
    void write(OfficeArtDggContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.drawingGroup, out);
        if (_s.blipStore != null) write(_s.blipStore, out);
        write(_s.drawingPrimaryOptions, out);
        if (_s.drawingTertiaryOptions != null) write(_s.drawingTertiaryOptions, out);
        if (_s.colorMRU != null) write(_s.colorMRU, out);
        write(_s.splitColors, out);
        if (_s.unknown != null) write(_s.unknown, out);
    }
    OfficeArtFOPTEChoice parseOfficeArtFOPTEChoice(LEInputStream in) throws IOException  {
        OfficeArtFOPTEChoice _s = new OfficeArtFOPTEChoice();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseProtectionBooleanProperties(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseITxid(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseDxTextLeft(in);
        } catch (IOException _xxx) {
            if (!(_xxx instanceof IncorrectValueException) && !(_xxx instanceof java.io.EOFException)) throw _xxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseDyTextTop(in);
        } catch (IOException _xxxx) {
            if (!(_xxxx instanceof IncorrectValueException) && !(_xxxx instanceof java.io.EOFException)) throw _xxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseDxTextRight(in);
        } catch (IOException _xxxxx) {
            if (!(_xxxxx instanceof IncorrectValueException) && !(_xxxxx instanceof java.io.EOFException)) throw _xxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseDyTextBottom(in);
        } catch (IOException _xxxxxx) {
            if (!(_xxxxxx instanceof IncorrectValueException) && !(_xxxxxx instanceof java.io.EOFException)) throw _xxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseWrapText(in);
        } catch (IOException _xxxxxxx) {
            if (!(_xxxxxxx instanceof IncorrectValueException) && !(_xxxxxxx instanceof java.io.EOFException)) throw _xxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseAnchorText(in);
        } catch (IOException _xxxxxxxx) {
            if (!(_xxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseTextBooleanProperties(in);
        } catch (IOException _xxxxxxxxx) {
            if (!(_xxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseHspNext(in);
        } catch (IOException _xxxxxxxxxx) {
            if (!(_xxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseShapePath(in);
        } catch (IOException _xxxxxxxxxxx) {
            if (!(_xxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseGeometryBooleanProperties(in);
        } catch (IOException _xxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillType(in);
        } catch (IOException _xxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillColor(in);
        } catch (IOException _xxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillBackColor(in);
        } catch (IOException _xxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillBlip(in);
        } catch (IOException _xxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillStyleBooleanProperties(in);
        } catch (IOException _xxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineColor(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineBackColor(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineFillBlip(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineWidth(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillRectRight(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseFillRectBottom(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseWzFillId(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineStyleBooleanProperties(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineStartArrowhead(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineEndArrowhead(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLineJoinStyle(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseShadowColor(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseShadowStyleBooleanPropertiesr(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseShapeBooleanProperties(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseHspMaster(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseRotation(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseLidRegroup(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseBWMode(in);
        } catch (IOException _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx) {
            if (!(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseOfficeArtFOPTE(in);
        }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(OfficeArtFOPTEChoice _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof ProtectionBooleanProperties) {
            write((ProtectionBooleanProperties)_s.anon, out);
        } else if (_s.anon instanceof ITxid) {
            write((ITxid)_s.anon, out);
        } else if (_s.anon instanceof DxTextLeft) {
            write((DxTextLeft)_s.anon, out);
        } else if (_s.anon instanceof DyTextTop) {
            write((DyTextTop)_s.anon, out);
        } else if (_s.anon instanceof DxTextRight) {
            write((DxTextRight)_s.anon, out);
        } else if (_s.anon instanceof DyTextBottom) {
            write((DyTextBottom)_s.anon, out);
        } else if (_s.anon instanceof WrapText) {
            write((WrapText)_s.anon, out);
        } else if (_s.anon instanceof AnchorText) {
            write((AnchorText)_s.anon, out);
        } else if (_s.anon instanceof TextBooleanProperties) {
            write((TextBooleanProperties)_s.anon, out);
        } else if (_s.anon instanceof HspNext) {
            write((HspNext)_s.anon, out);
        } else if (_s.anon instanceof ShapePath) {
            write((ShapePath)_s.anon, out);
        } else if (_s.anon instanceof GeometryBooleanProperties) {
            write((GeometryBooleanProperties)_s.anon, out);
        } else if (_s.anon instanceof FillType) {
            write((FillType)_s.anon, out);
        } else if (_s.anon instanceof FillColor) {
            write((FillColor)_s.anon, out);
        } else if (_s.anon instanceof FillBackColor) {
            write((FillBackColor)_s.anon, out);
        } else if (_s.anon instanceof FillBlip) {
            write((FillBlip)_s.anon, out);
        } else if (_s.anon instanceof FillStyleBooleanProperties) {
            write((FillStyleBooleanProperties)_s.anon, out);
        } else if (_s.anon instanceof LineColor) {
            write((LineColor)_s.anon, out);
        } else if (_s.anon instanceof LineBackColor) {
            write((LineBackColor)_s.anon, out);
        } else if (_s.anon instanceof LineFillBlip) {
            write((LineFillBlip)_s.anon, out);
        } else if (_s.anon instanceof LineWidth) {
            write((LineWidth)_s.anon, out);
        } else if (_s.anon instanceof FillRectRight) {
            write((FillRectRight)_s.anon, out);
        } else if (_s.anon instanceof FillRectBottom) {
            write((FillRectBottom)_s.anon, out);
        } else if (_s.anon instanceof WzFillId) {
            write((WzFillId)_s.anon, out);
        } else if (_s.anon instanceof LineStyleBooleanProperties) {
            write((LineStyleBooleanProperties)_s.anon, out);
        } else if (_s.anon instanceof LineStartArrowhead) {
            write((LineStartArrowhead)_s.anon, out);
        } else if (_s.anon instanceof LineEndArrowhead) {
            write((LineEndArrowhead)_s.anon, out);
        } else if (_s.anon instanceof LineJoinStyle) {
            write((LineJoinStyle)_s.anon, out);
        } else if (_s.anon instanceof ShadowColor) {
            write((ShadowColor)_s.anon, out);
        } else if (_s.anon instanceof ShadowStyleBooleanPropertiesr) {
            write((ShadowStyleBooleanPropertiesr)_s.anon, out);
        } else if (_s.anon instanceof ShapeBooleanProperties) {
            write((ShapeBooleanProperties)_s.anon, out);
        } else if (_s.anon instanceof HspMaster) {
            write((HspMaster)_s.anon, out);
        } else if (_s.anon instanceof Rotation) {
            write((Rotation)_s.anon, out);
        } else if (_s.anon instanceof LidRegroup) {
            write((LidRegroup)_s.anon, out);
        } else if (_s.anon instanceof BWMode) {
            write((BWMode)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtFOPTE) {
            write((OfficeArtFOPTE)_s.anon, out);
        }
    }
    OfficeArtClientData parseOfficeArtClientData(LEInputStream in) throws IOException  {
        OfficeArtClientData _s = new OfficeArtClientData();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF011)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF011 for value " + String.valueOf(_s.rh) );
        }
        _m = in.setMark();
        try {
            _s.shapeFlagsAtom = parseShapeFlagsAtom(in);
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
            _s.shapeFlags10Atom = parseShapeFlags10Atom(in);
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
            _s.exObjRefAtom = parseExObjRefAtom(in);
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
            _s.animationInfo = parseAnimationInfoContainer(in);
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
            _s.mouseClickInteractiveInfo = parseMouseInteractiveInfoContainer(in);
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
            _s.mouseOverInteractiveInfo = parseMouseInteractiveInfoContainer(in);
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
            _s.placeholderAtom = parsePlaceholderAtom(in);
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
            _s.recolorInfoAtom = parseRecolorInfoAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                ShapeClientRoundtripDataSubcontainerOrAtom _t = parseShapeClientRoundtripDataSubcontainerOrAtom(in);
                _s.rgShapeClientRoundtripData.add(_t);
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
        _m = in.setMark();
        try {
            _s.unknown = parseUnknownOfficeArtClientDataChild(in);
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
    void write(OfficeArtClientData _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        if (_s.shapeFlagsAtom != null) write(_s.shapeFlagsAtom, out);
        if (_s.shapeFlags10Atom != null) write(_s.shapeFlags10Atom, out);
        if (_s.exObjRefAtom != null) write(_s.exObjRefAtom, out);
        if (_s.animationInfo != null) write(_s.animationInfo, out);
        if (_s.mouseClickInteractiveInfo != null) write(_s.mouseClickInteractiveInfo, out);
        if (_s.mouseOverInteractiveInfo != null) write(_s.mouseOverInteractiveInfo, out);
        if (_s.placeholderAtom != null) write(_s.placeholderAtom, out);
        if (_s.recolorInfoAtom != null) write(_s.recolorInfoAtom, out);
        for (ShapeClientRoundtripDataSubcontainerOrAtom _i: _s.rgShapeClientRoundtripData) {
            write(_i, out);
        }
        if (_s.unknown != null) write(_s.unknown, out);
    }
    WordDocument parseWordDocument(LEInputStream in) throws IOException  {
        WordDocument _s = new WordDocument();
        _s.fib = parseFib(in);
        return _s;
    }
    void write(WordDocument _s, LEOutputStream out) throws IOException  {
        write(_s.fib, out);
    }
    Table parseTable(LEInputStream in) throws IOException  {
        Table _s = new Table();
        int _c;
        _s.stsh = parseSTSH(in);
        _s.plcfSed = parsePlcfSed(in);
        _s.plcfHdd = parsePlcfhdd(in);
        _s.plcfBteChpx = parsePlcBteChpx(in);
        _s.plcfBtePapx = parsePlcfBtePapx(in);
        _s.cmds = parseTcg(in);
        _s.clx = parseClx(in);
        _s.sttbfFfn = parseSttbfFfn(in);
        _c = 600;
        _s.dop = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.dop[_i] = in.readuint8();
        }
        return _s;
    }
    void write(Table _s, LEOutputStream out) throws IOException  {
        write(_s.stsh, out);
        write(_s.plcfSed, out);
        write(_s.plcfHdd, out);
        write(_s.plcfBteChpx, out);
        write(_s.plcfBtePapx, out);
        write(_s.cmds, out);
        write(_s.clx, out);
        write(_s.sttbfFfn, out);
        for (byte _i: _s.dop) {
            out.writeuint8(_i);
        }
    }
    Pcd parsePcd(LEInputStream in) throws IOException  {
        Pcd _s = new Pcd();
        _s.fNoParaLast = in.readbit();
        _s.fR1 = in.readbit();
        _s.fDirtly = in.readbit();
        if (!(_s.fDirtly == false)) {
            throw new IncorrectValueException(in.getPosition() + "_s.fDirtly == false for value " + String.valueOf(_s.fDirtly) );
        }
        _s.fR2 = in.readbit();
        _s.fR3 = in.readuint12();
        _s.fc = parseFCompressed(in);
        _s.prm = parsePrm(in);
        return _s;
    }
    void write(Pcd _s, LEOutputStream out) throws IOException  {
        out.writebit(_s.fNoParaLast);
        out.writebit(_s.fR1);
        out.writebit(_s.fDirtly);
        out.writebit(_s.fR2);
        out.writeuint12(_s.fR3);
        write(_s.fc, out);
        write(_s.prm, out);
    }
    OfficeArtFBSE parseOfficeArtFBSE(LEInputStream in) throws IOException  {
        OfficeArtFBSE _s = new OfficeArtFBSE();
        int _c;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0x2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0x2 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 0x11 || _s.rh.recInstance == 0x12)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 || _s.rh.recInstance == 2 || _s.rh.recInstance == 3 || _s.rh.recInstance == 4 || _s.rh.recInstance == 5 || _s.rh.recInstance == 6 || _s.rh.recInstance == 7 || _s.rh.recInstance == 0x11 || _s.rh.recInstance == 0x12 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF007)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF007 for value " + String.valueOf(_s.rh) );
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
        _s.cRef = in.readuint32();
        _s.foDelay = in.readuint32();
        _s.unused1 = in.readuint8();
        _s.cbName = in.readuint8();
        _s.unused2 = in.readuint8();
        _s.unused3 = in.readuint8();
        _c = _s.cbName;
        _s.nameData = new byte[_c];
        for (int _i=0; _i<_c; ++_i) {
            _s.nameData[_i] = in.readuint8();
        }
        if (_s.rh.recLen > 36 + _s.cbName) {
            _s.embeddedBlip = parseOfficeArtBlip(in);
        }
        return _s;
    }
    void write(OfficeArtFBSE _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        out.writeuint8(_s.btWin32);
        out.writeuint8(_s.btMacOS);
        for (byte _i: _s.rgbUid) {
            out.writeuint8(_i);
        }
        out.writeuint16(_s.tag);
        out.writeuint32(_s.size);
        out.writeuint32(_s.cRef);
        out.writeuint32(_s.foDelay);
        out.writeuint8(_s.unused1);
        out.writeuint8(_s.cbName);
        out.writeuint8(_s.unused2);
        out.writeuint8(_s.unused3);
        for (byte _i: _s.nameData) {
            out.writeuint8(_i);
        }
        if (_s.rh.recLen > 36 + _s.cbName) {
            write(_s.embeddedBlip, out);
        }
    }
    OfficeArtBStoreContainerFileBlock parseOfficeArtBStoreContainerFileBlock(LEInputStream in) throws IOException  {
        OfficeArtBStoreContainerFileBlock _s = new OfficeArtBStoreContainerFileBlock();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseOfficeArtFBSE(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseOfficeArtBlip(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(OfficeArtBStoreContainerFileBlock _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof OfficeArtFBSE) {
            write((OfficeArtFBSE)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtBlip) {
            write((OfficeArtBlip)_s.anon, out);
        }
    }
    SlideViewInfoInstance parseSlideViewInfoInstance(LEInputStream in) throws IOException  {
        SlideViewInfoInstance _s = new SlideViewInfoInstance();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0 || _s.rh.recInstance == 1)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 || _s.rh.recInstance == 1 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x3FA)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x3FA for value " + String.valueOf(_s.rh) );
        }
        _s.slideViewInfoAtom = parseSlideViewInfoAtom(in);
        _s.zoomViewInfoAtom = parseZoomViewInfoAtom(in);
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                GuideAtom _t = parseGuideAtom(in);
                _s.rgGuideAtom.add(_t);
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
    void write(SlideViewInfoInstance _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.slideViewInfoAtom, out);
        write(_s.zoomViewInfoAtom, out);
        for (GuideAtom _i: _s.rgGuideAtom) {
            write(_i, out);
        }
    }
    DocumentTextInfoContainer parseDocumentTextInfoContainer(LEInputStream in) throws IOException  {
        DocumentTextInfoContainer _s = new DocumentTextInfoContainer();
        Object _m;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03F2)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03F2 for value " + String.valueOf(_s.rh) );
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
    void write(DocumentTextInfoContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        if (_s.kinsoku != null) write(_s.kinsoku, out);
        if (_s.fontCollection != null) write(_s.fontCollection, out);
        if (_s.textCFDefaultsAtom != null) write(_s.textCFDefaultsAtom, out);
        if (_s.textPFDefaultsAtom != null) write(_s.textPFDefaultsAtom, out);
        if (_s.defaultRulerAtom != null) write(_s.defaultRulerAtom, out);
        write(_s.textSIDefaultsAtom, out);
        write(_s.textMasterStyleAtom, out);
    }
    DrawingGroupContainer parseDrawingGroupContainer(LEInputStream in) throws IOException  {
        DrawingGroupContainer _s = new DrawingGroupContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x040B)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x040B for value " + String.valueOf(_s.rh) );
        }
        _s.OfficeArtDgg = parseOfficeArtDggContainer(in);
        return _s;
    }
    void write(DrawingGroupContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.OfficeArtDgg, out);
    }
    OfficeArtSpContainer parseOfficeArtSpContainer(LEInputStream in) throws IOException  {
        OfficeArtSpContainer _s = new OfficeArtSpContainer();
        Object _m;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x0F004)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x0F004 for value " + String.valueOf(_s.rh) );
        }
        _m = in.setMark();
        try {
            _s.shapeGroup = parseOfficeArtFSPGR(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.shapeProp = parseOfficeArtFSP(in);
        _m = in.setMark();
        try {
            _s.deletedshape = parseOfficeArtFPSPL(in);
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
            _s.shapePrimaryOptions = parseOfficeArtFOPT(in);
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
            _s.shapeSecondaryOptions1 = parseOfficeArtSecondaryFOPT(in);
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
            _s.shapeTertiaryOptions1 = parseOfficeArtTertiaryFOPT(in);
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
            _s.childAnchor = parseOfficeArtChildAnchor(in);
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
            _s.clientAnchor = parseOfficeArtClientAnchor(in);
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
            _s.clientData = parseOfficeArtClientData(in);
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
            _s.clientTextbox = parseOfficeArtClientTextBox(in);
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
            _s.shapeSecondaryOptions2 = parseOfficeArtSecondaryFOPT(in);
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
            _s.shapeTertiaryOptions2 = parseOfficeArtTertiaryFOPT(in);
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
    void write(OfficeArtSpContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        if (_s.shapeGroup != null) write(_s.shapeGroup, out);
        write(_s.shapeProp, out);
        if (_s.deletedshape != null) write(_s.deletedshape, out);
        if (_s.shapePrimaryOptions != null) write(_s.shapePrimaryOptions, out);
        if (_s.shapeSecondaryOptions1 != null) write(_s.shapeSecondaryOptions1, out);
        if (_s.shapeTertiaryOptions1 != null) write(_s.shapeTertiaryOptions1, out);
        if (_s.childAnchor != null) write(_s.childAnchor, out);
        if (_s.clientAnchor != null) write(_s.clientAnchor, out);
        if (_s.clientData != null) write(_s.clientData, out);
        if (_s.clientTextbox != null) write(_s.clientTextbox, out);
        if (_s.shapeSecondaryOptions2 != null) write(_s.shapeSecondaryOptions2, out);
        if (_s.shapeTertiaryOptions2 != null) write(_s.shapeTertiaryOptions2, out);
    }
    DocumentContainer parseDocumentContainer(LEInputStream in) throws IOException  {
        DocumentContainer _s = new DocumentContainer();
        Object _m;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03E8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03E8 for value " + String.valueOf(_s.rh) );
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
        _m = in.setMark();
        try {
            _s.soundCollection = parseSoundCollectionContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.drawingGroup = parseDrawingGroupContainer(in);
        _s.masterList = parseMasterListWithTextContainer(in);
        _m = in.setMark();
        try {
            _s.docInfoList = parseDocInfoListContainer(in);
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
            _s.slideHF = parseSlideHeadersFootersContainer(in);
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
            _s.notesHF = parseNotesHeadersFootersContainer(in);
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
            _s.slideList = parseSlideListWithTextContainer(in);
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
            _s.slideHF2 = parseSlideHeadersFootersContainer(in);
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
            _s.notesList = parseNotesListWithTextContainer(in);
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
            _s.slideShowDocInfoAtom = parseSlideShowDocInfoAtom(in);
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
            _s.namedShows = parseNamedShowsContainer(in);
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
            _s.summary = parseSummaryContainer(in);
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
            _s.docRoutingSlipAtom = parseDocRoutingSlipAtom(in);
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
            _s.printOptionsAtom = parsePrintOptionsAtom(in);
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
            _s.rtCustomTableStylesAtom1 = parseRoundTripCustomTableStyles12Atom(in);
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
            _s.unknown1 = parseUnknownDocumentContainerChild(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.endDocumentAtom = parseEndDocumentAtom(in);
        _m = in.setMark();
        try {
            _s.unknown2 = parseUnknownDocumentContainerChild3(in);
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
            _s.unknown3 = parseUnknownDocumentContainerChild2(in);
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
            _s.unknown4 = parseUnknownDocumentContainerChild3(in);
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
            _s.unknown5 = parseUnknownDocumentContainerChild4(in);
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
            _s.rtCustomTableStylesAtom2 = parseRoundTripCustomTableStyles12Atom(in);
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
    void write(DocumentContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.documentAtom, out);
        if (_s.exObjList != null) write(_s.exObjList, out);
        write(_s.documentTextInfo, out);
        if (_s.soundCollection != null) write(_s.soundCollection, out);
        write(_s.drawingGroup, out);
        write(_s.masterList, out);
        if (_s.docInfoList != null) write(_s.docInfoList, out);
        if (_s.slideHF != null) write(_s.slideHF, out);
        if (_s.notesHF != null) write(_s.notesHF, out);
        if (_s.slideList != null) write(_s.slideList, out);
        if (_s.slideHF2 != null) write(_s.slideHF2, out);
        if (_s.notesList != null) write(_s.notesList, out);
        if (_s.slideShowDocInfoAtom != null) write(_s.slideShowDocInfoAtom, out);
        if (_s.namedShows != null) write(_s.namedShows, out);
        if (_s.summary != null) write(_s.summary, out);
        if (_s.docRoutingSlipAtom != null) write(_s.docRoutingSlipAtom, out);
        if (_s.printOptionsAtom != null) write(_s.printOptionsAtom, out);
        if (_s.rtCustomTableStylesAtom1 != null) write(_s.rtCustomTableStylesAtom1, out);
        if (_s.unknown1 != null) write(_s.unknown1, out);
        write(_s.endDocumentAtom, out);
        if (_s.unknown2 != null) write(_s.unknown2, out);
        if (_s.unknown3 != null) write(_s.unknown3, out);
        if (_s.unknown4 != null) write(_s.unknown4, out);
        if (_s.unknown5 != null) write(_s.unknown5, out);
        if (_s.rtCustomTableStylesAtom2 != null) write(_s.rtCustomTableStylesAtom2, out);
    }
    DocInfoListSubContainerOrAtom parseDocInfoListSubContainerOrAtom(LEInputStream in) throws IOException  {
        DocInfoListSubContainerOrAtom _s = new DocInfoListSubContainerOrAtom();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseDocProgTagsContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseNormalViewSetInfoContainer(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseNotesTextViewInfoContainer(in);
        } catch (IOException _xxx) {
            if (!(_xxx instanceof IncorrectValueException) && !(_xxx instanceof java.io.EOFException)) throw _xxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseOutlineViewInfoContainer(in);
        } catch (IOException _xxxx) {
            if (!(_xxxx instanceof IncorrectValueException) && !(_xxxx instanceof java.io.EOFException)) throw _xxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseSlideViewInfoInstance(in);
        } catch (IOException _xxxxx) {
            if (!(_xxxxx instanceof IncorrectValueException) && !(_xxxxx instanceof java.io.EOFException)) throw _xxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseSorterViewInfoContainer(in);
        } catch (IOException _xxxxxx) {
            if (!(_xxxxxx instanceof IncorrectValueException) && !(_xxxxxx instanceof java.io.EOFException)) throw _xxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxx);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseVBAInfoContainer(in);
        }}}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(DocInfoListSubContainerOrAtom _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof DocProgTagsContainer) {
            write((DocProgTagsContainer)_s.anon, out);
        } else if (_s.anon instanceof NormalViewSetInfoContainer) {
            write((NormalViewSetInfoContainer)_s.anon, out);
        } else if (_s.anon instanceof NotesTextViewInfoContainer) {
            write((NotesTextViewInfoContainer)_s.anon, out);
        } else if (_s.anon instanceof OutlineViewInfoContainer) {
            write((OutlineViewInfoContainer)_s.anon, out);
        } else if (_s.anon instanceof SlideViewInfoInstance) {
            write((SlideViewInfoInstance)_s.anon, out);
        } else if (_s.anon instanceof SorterViewInfoContainer) {
            write((SorterViewInfoContainer)_s.anon, out);
        } else if (_s.anon instanceof VBAInfoContainer) {
            write((VBAInfoContainer)_s.anon, out);
        }
    }
    OfficeArtDgContainer parseOfficeArtDgContainer(LEInputStream in) throws IOException  {
        OfficeArtDgContainer _s = new OfficeArtDgContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseOfficeArtRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0xF002)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0xF002 for value " + String.valueOf(_s.rh) );
        }
        _s.drawingData = parseOfficeArtFDG(in);
        _m = in.setMark();
        try {
            _s.regroupItems = parseOfficeArtFRITContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.groupShape = parseOfficeArtSpgrContainer(in);
        _m = in.setMark();
        try {
            _s.shape = parseOfficeArtSpContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                OfficeArtSpgrContainerFileBlock _t = parseOfficeArtSpgrContainerFileBlock(in);
                _s.deletedShapes.add(_t);
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
        _m = in.setMark();
        try {
            _s.solvers = parseOfficeArtSolverContainer(in);
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
    void write(OfficeArtDgContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.drawingData, out);
        if (_s.regroupItems != null) write(_s.regroupItems, out);
        write(_s.groupShape, out);
        if (_s.shape != null) write(_s.shape, out);
        for (OfficeArtSpgrContainerFileBlock _i: _s.deletedShapes) {
            write(_i, out);
        }
        if (_s.solvers != null) write(_s.solvers, out);
    }
    OfficeArtSpgrContainerFileBlock parseOfficeArtSpgrContainerFileBlock(LEInputStream in) throws IOException  {
        OfficeArtSpgrContainerFileBlock _s = new OfficeArtSpgrContainerFileBlock();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseOfficeArtSpContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseOfficeArtSpgrContainer(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(OfficeArtSpgrContainerFileBlock _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof OfficeArtSpContainer) {
            write((OfficeArtSpContainer)_s.anon, out);
        } else if (_s.anon instanceof OfficeArtSpgrContainer) {
            write((OfficeArtSpgrContainer)_s.anon, out);
        }
    }
    DrawingContainer parseDrawingContainer(LEInputStream in) throws IOException  {
        DrawingContainer _s = new DrawingContainer();
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x040C)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x040C for value " + String.valueOf(_s.rh) );
        }
        _s.OfficeArtDg = parseOfficeArtDgContainer(in);
        return _s;
    }
    void write(DrawingContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.OfficeArtDg, out);
    }
    MainMasterContainer parseMainMasterContainer(LEInputStream in) throws IOException  {
        MainMasterContainer _s = new MainMasterContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03F8)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03F8 for value " + String.valueOf(_s.rh) );
        }
        _s.slideAtom = parseSlideAtom(in);
        _m = in.setMark();
        try {
            _s.unknown = parseSlideShowSlideInfoAtom(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                SchemeListElementColorSchemeAtom _t = parseSchemeListElementColorSchemeAtom(in);
                _s.rgSchemeListElementColorScheme.add(_t);
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
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                TextMasterStyleAtom _t = parseTextMasterStyleAtom(in);
                _s.rgTextMasterStyle.add(_t);
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
        _m = in.setMark();
        try {
            _s.roundTripOArtTextSTyles12Atom = parseRoundTripOArtTextStyles12Atom(in);
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
            _s.slideShowInfoAtom = parseSlideShowSlideInfoAtom(in);
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
            _s.perSlideHeadersFootersContainer = parsePerSlideHeadersFootersContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.drawing = parseDrawingContainer(in);
        _s.slideSchemeColorSchemeAtom = parseSlideSchemeColorSchemeAtom(in);
        _m = in.setMark();
        try {
            _s.slideNameAtom = parseSlideNameAtom(in);
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
            _s.slideProgTagsContainer = parseSlideProgTagsContainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                RoundTripMainMasterRecord _t = parseRoundTripMainMasterRecord(in);
                _s.rgRoundTripMainMaster.add(_t);
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
        _m = in.setMark();
        try {
            _s.unknown2 = parseUnknownSlideContainerChild(in);
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
            _s.templateNameAtom = parseTemplateNameAtom(in);
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
            _s.unknown3 = parseSlideProgTagsContainer(in);
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
    void write(MainMasterContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.slideAtom, out);
        if (_s.unknown != null) write(_s.unknown, out);
        for (SchemeListElementColorSchemeAtom _i: _s.rgSchemeListElementColorScheme) {
            write(_i, out);
        }
        for (TextMasterStyleAtom _i: _s.rgTextMasterStyle) {
            write(_i, out);
        }
        if (_s.roundTripOArtTextSTyles12Atom != null) write(_s.roundTripOArtTextSTyles12Atom, out);
        if (_s.slideShowInfoAtom != null) write(_s.slideShowInfoAtom, out);
        if (_s.perSlideHeadersFootersContainer != null) write(_s.perSlideHeadersFootersContainer, out);
        write(_s.drawing, out);
        write(_s.slideSchemeColorSchemeAtom, out);
        if (_s.slideNameAtom != null) write(_s.slideNameAtom, out);
        if (_s.slideProgTagsContainer != null) write(_s.slideProgTagsContainer, out);
        for (RoundTripMainMasterRecord _i: _s.rgRoundTripMainMaster) {
            write(_i, out);
        }
        if (_s.unknown2 != null) write(_s.unknown2, out);
        if (_s.templateNameAtom != null) write(_s.templateNameAtom, out);
        if (_s.unknown3 != null) write(_s.unknown3, out);
    }
    SlideContainer parseSlideContainer(LEInputStream in) throws IOException  {
        SlideContainer _s = new SlideContainer();
        Object _m;
        boolean _atend;
        int _i;
        _s.rh = parseRecordHeader(in);
        if (!(_s.rh.recVer == 0xF)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recVer == 0xF for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recInstance == 0x0)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recInstance == 0x0 for value " + String.valueOf(_s.rh) );
        }
        if (!(_s.rh.recType == 0x03EE)) {
            throw new IncorrectValueException(in.getPosition() + "_s.rh.recType == 0x03EE for value " + String.valueOf(_s.rh) );
        }
        _s.slideAtom = parseSlideAtom(in);
        _m = in.setMark();
        try {
            _s.slideShowSlideInfoAtom = parseSlideShowSlideInfoAtom(in);
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
            _s.perSlideHFContainer = parsePerSlideHeadersFootersContainer(in);
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
            _s.rtSlideSyncInfo12 = parseRoundTripSlideSyncInfo12Container(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _s.drawing = parseDrawingContainer(in);
        _s.slideSchemeColorSchemeAtom = parseSlideSchemeColorSchemeAtom(in);
        _m = in.setMark();
        try {
            _s.slideNameAtom = parseSlideNameAtom(in);
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
            _s.slideProgTagsContainer = parseSlideProgTagscontainer(in);
        } catch(IncorrectValueException _e) {
            if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug
            in.rewind(_m);
        } catch(java.io.EOFException _e) {
            in.rewind(_m);
        } finally {
            in.releaseMark(_m);
        }
        _atend = false;
        _i=0;
        while (!_atend) {
            System.out.println("round "+(_i++) + " " + in.getPosition());
            _m = in.setMark();
            try {
                RoundTripSlideRecord _t = parseRoundTripSlideRecord(in);
                _s.rgRoundTripSlide.add(_t);
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
        _m = in.setMark();
        try {
            _s.unknown = parseUnknownSlideContainerChild(in);
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
    void write(SlideContainer _s, LEOutputStream out) throws IOException  {
        write(_s.rh, out);
        write(_s.slideAtom, out);
        if (_s.slideShowSlideInfoAtom != null) write(_s.slideShowSlideInfoAtom, out);
        if (_s.perSlideHFContainer != null) write(_s.perSlideHFContainer, out);
        if (_s.rtSlideSyncInfo12 != null) write(_s.rtSlideSyncInfo12, out);
        write(_s.drawing, out);
        write(_s.slideSchemeColorSchemeAtom, out);
        if (_s.slideNameAtom != null) write(_s.slideNameAtom, out);
        if (_s.slideProgTagsContainer != null) write(_s.slideProgTagsContainer, out);
        for (RoundTripSlideRecord _i: _s.rgRoundTripSlide) {
            write(_i, out);
        }
        if (_s.unknown != null) write(_s.unknown, out);
    }
    MasterOrSlideContainer parseMasterOrSlideContainer(LEInputStream in) throws IOException  {
        MasterOrSlideContainer _s = new MasterOrSlideContainer();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseMainMasterContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseSlideContainer(in);
        } finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(MasterOrSlideContainer _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof MainMasterContainer) {
            write((MainMasterContainer)_s.anon, out);
        } else if (_s.anon instanceof SlideContainer) {
            write((SlideContainer)_s.anon, out);
        }
    }
    PowerPointStruct parsePowerPointStruct(LEInputStream in) throws IOException  {
        PowerPointStruct _s = new PowerPointStruct();
        Object _m;
        _m = in.setMark();
        try {
            _s.anon = parseDocumentContainer(in);
        } catch (IOException _x) {
            if (!(_x instanceof IncorrectValueException) && !(_x instanceof java.io.EOFException)) throw _x;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_x);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseMasterOrSlideContainer(in);
        } catch (IOException _xx) {
            if (!(_xx instanceof IncorrectValueException) && !(_xx instanceof java.io.EOFException)) throw _xx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parsePersistDirectoryAtom(in);
        } catch (IOException _xxx) {
            if (!(_xxx instanceof IncorrectValueException) && !(_xxx instanceof java.io.EOFException)) throw _xxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseNotesContainer(in);
        } catch (IOException _xxxx) {
            if (!(_xxxx instanceof IncorrectValueException) && !(_xxxx instanceof java.io.EOFException)) throw _xxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseHandoutContainer(in);
        } catch (IOException _xxxxx) {
            if (!(_xxxxx instanceof IncorrectValueException) && !(_xxxxx instanceof java.io.EOFException)) throw _xxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseSlideContainer(in);
        } catch (IOException _xxxxxx) {
            if (!(_xxxxxx instanceof IncorrectValueException) && !(_xxxxxx instanceof java.io.EOFException)) throw _xxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExOleObjStg(in);
        } catch (IOException _xxxxxxx) {
            if (!(_xxxxxxx instanceof IncorrectValueException) && !(_xxxxxxx instanceof java.io.EOFException)) throw _xxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseExControlStg(in);
        } catch (IOException _xxxxxxxx) {
            if (!(_xxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxx);//onlyfordebug
            in.rewind(_m);
        try {
            _s.anon = parseVbaProjectStg(in);
        } catch (IOException _xxxxxxxxx) {
            if (!(_xxxxxxxxx instanceof IncorrectValueException) && !(_xxxxxxxxx instanceof java.io.EOFException)) throw _xxxxxxxxx;
            if (in.distanceFromMark(_m) > 16) throw new IOException(_xxxxxxxxx);//onlyfordebug
            in.rewind(_m);
            _s.anon = parseUserEditAtom(in);
        }}}}}}}}} finally {
            in.releaseMark(_m);
        }
        return _s;
    }
    void write(PowerPointStruct _s, LEOutputStream out) throws IOException  {
        if (_s.anon instanceof DocumentContainer) {
            write((DocumentContainer)_s.anon, out);
        } else if (_s.anon instanceof MasterOrSlideContainer) {
            write((MasterOrSlideContainer)_s.anon, out);
        } else if (_s.anon instanceof PersistDirectoryAtom) {
            write((PersistDirectoryAtom)_s.anon, out);
        } else if (_s.anon instanceof NotesContainer) {
            write((NotesContainer)_s.anon, out);
        } else if (_s.anon instanceof HandoutContainer) {
            write((HandoutContainer)_s.anon, out);
        } else if (_s.anon instanceof SlideContainer) {
            write((SlideContainer)_s.anon, out);
        } else if (_s.anon instanceof ExOleObjStg) {
            write((ExOleObjStg)_s.anon, out);
        } else if (_s.anon instanceof ExControlStg) {
            write((ExControlStg)_s.anon, out);
        } else if (_s.anon instanceof VbaProjectStg) {
            write((VbaProjectStg)_s.anon, out);
        } else if (_s.anon instanceof UserEditAtom) {
            write((UserEditAtom)_s.anon, out);
        }
    }
}
class RecordHeader {
    byte recVer;
    short recInstance;
    int recType;
    int recLen;
    public String toString() {
        String _s = "RecordHeader:";
        _s = _s + "recVer: " + String.valueOf(recVer) + "(" + Integer.toHexString(recVer).toUpperCase() + "), ";
        _s = _s + "recInstance: " + String.valueOf(recInstance) + "(" + Integer.toHexString(recInstance).toUpperCase() + "), ";
        _s = _s + "recType: " + String.valueOf(recType) + "(" + Integer.toHexString(recType).toUpperCase() + "), ";
        _s = _s + "recLen: " + String.valueOf(recLen) + "(" + Integer.toHexString(recLen).toUpperCase() + "), ";
        return _s;
    }
}
class CurrentUserAtom {
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
        _s = _s + "size: " + String.valueOf(size) + "(" + Integer.toHexString(size).toUpperCase() + "), ";
        _s = _s + "headerToken: " + String.valueOf(headerToken) + "(" + Integer.toHexString(headerToken).toUpperCase() + "), ";
        _s = _s + "offsetToCurrentEdit: " + String.valueOf(offsetToCurrentEdit) + "(" + Integer.toHexString(offsetToCurrentEdit).toUpperCase() + "), ";
        _s = _s + "lenUserName: " + String.valueOf(lenUserName) + "(" + Integer.toHexString(lenUserName).toUpperCase() + "), ";
        _s = _s + "docFileVersion: " + String.valueOf(docFileVersion) + "(" + Integer.toHexString(docFileVersion).toUpperCase() + "), ";
        _s = _s + "majorVersion: " + String.valueOf(majorVersion) + "(" + Integer.toHexString(majorVersion).toUpperCase() + "), ";
        _s = _s + "minorVersion: " + String.valueOf(minorVersion) + "(" + Integer.toHexString(minorVersion).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        _s = _s + "ansiUserName: " + String.valueOf(ansiUserName) + ", ";
        _s = _s + "relVersion: " + String.valueOf(relVersion) + "(" + Integer.toHexString(relVersion).toUpperCase() + "), ";
        _s = _s + "unicodeUserName: " + String.valueOf(unicodeUserName) + ", ";
        return _s;
    }
}
class TODOS {
    final java.util.List<Byte> anon = new java.util.ArrayList<Byte>();
    public String toString() {
        String _s = "TODOS:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class Byte {
    byte b;
    public String toString() {
        String _s = "Byte:";
        _s = _s + "b: " + String.valueOf(b) + "(" + Integer.toHexString(b).toUpperCase() + "), ";
        return _s;
    }
}
class CurrentUserStream {
    CurrentUserAtom anon1;
    final java.util.List<Byte> trailing = new java.util.ArrayList<Byte>();
    public String toString() {
        String _s = "CurrentUserStream:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        _s = _s + "trailing: " + String.valueOf(trailing) + ", ";
        return _s;
    }
}
class OfficeArtBStoreDelay {
    final java.util.List<OfficeArtBStoreContainerFileBlock> anon1 = new java.util.ArrayList<OfficeArtBStoreContainerFileBlock>();
    public String toString() {
        String _s = "OfficeArtBStoreDelay:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        return _s;
    }
}
class OfficeArtRecordHeader {
    byte recVer;
    short recInstance;
    int recType;
    int recLen;
    public String toString() {
        String _s = "OfficeArtRecordHeader:";
        _s = _s + "recVer: " + String.valueOf(recVer) + "(" + Integer.toHexString(recVer).toUpperCase() + "), ";
        _s = _s + "recInstance: " + String.valueOf(recInstance) + "(" + Integer.toHexString(recInstance).toUpperCase() + "), ";
        _s = _s + "recType: " + String.valueOf(recType) + "(" + Integer.toHexString(recType).toUpperCase() + "), ";
        _s = _s + "recLen: " + String.valueOf(recLen) + "(" + Integer.toHexString(recLen).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtBlipJPEG {
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
        _s = _s + "tag: " + String.valueOf(tag) + "(" + Integer.toHexString(tag).toUpperCase() + "), ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipPNG {
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
        _s = _s + "tag: " + String.valueOf(tag) + "(" + Integer.toHexString(tag).toUpperCase() + "), ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipDIB {
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
        _s = _s + "tag: " + String.valueOf(tag) + "(" + Integer.toHexString(tag).toUpperCase() + "), ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class OfficeArtBlipTIFF {
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
        _s = _s + "tag: " + String.valueOf(tag) + "(" + Integer.toHexString(tag).toUpperCase() + "), ";
        _s = _s + "BLIPFileData: " + String.valueOf(BLIPFileData) + ", ";
        return _s;
    }
}
class RECT {
    int left;
    int top;
    int right;
    int bottom;
    public String toString() {
        String _s = "RECT:";
        _s = _s + "left: " + String.valueOf(left) + "(" + Integer.toHexString(left).toUpperCase() + "), ";
        _s = _s + "top: " + String.valueOf(top) + "(" + Integer.toHexString(top).toUpperCase() + "), ";
        _s = _s + "right: " + String.valueOf(right) + "(" + Integer.toHexString(right).toUpperCase() + "), ";
        _s = _s + "bottom: " + String.valueOf(bottom) + "(" + Integer.toHexString(bottom).toUpperCase() + "), ";
        return _s;
    }
}
class POINT {
    int x;
    int y;
    public String toString() {
        String _s = "POINT:";
        _s = _s + "x: " + String.valueOf(x) + "(" + Integer.toHexString(x).toUpperCase() + "), ";
        _s = _s + "y: " + String.valueOf(y) + "(" + Integer.toHexString(y).toUpperCase() + "), ";
        return _s;
    }
}
class PowerPointStructs {
    final java.util.List<PowerPointStruct> anon = new java.util.ArrayList<PowerPointStruct>();
    public String toString() {
        String _s = "PowerPointStructs:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class SoundCollectionContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SoundCollectionContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideHeadersFootersContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SlideHeadersFootersContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class NotesHeadersFootersContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "NotesHeadersFootersContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class PerSlideHeadersFootersContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "PerSlideHeadersFootersContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class EndDocumentAtom {
    RecordHeader rh;
    public String toString() {
        String _s = "EndDocumentAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        return _s;
    }
}
class DocInfoListContainer {
    RecordHeader rh;
    final java.util.List<DocInfoListSubContainerOrAtom> rgChildRec = new java.util.ArrayList<DocInfoListSubContainerOrAtom>();
    public String toString() {
        String _s = "DocInfoListContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgChildRec: " + String.valueOf(rgChildRec) + ", ";
        return _s;
    }
}
class SlideViewInfoAtom {
    RecordHeader rh;
    byte unused1;
    byte fSnapToGrid;
    byte fSnapToShape;
    public String toString() {
        String _s = "SlideViewInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + "(" + Integer.toHexString(unused1).toUpperCase() + "), ";
        _s = _s + "fSnapToGrid: " + String.valueOf(fSnapToGrid) + "(" + Integer.toHexString(fSnapToGrid).toUpperCase() + "), ";
        _s = _s + "fSnapToShape: " + String.valueOf(fSnapToShape) + "(" + Integer.toHexString(fSnapToShape).toUpperCase() + "), ";
        return _s;
    }
}
class GuideAtom {
    RecordHeader rh;
    int type;
    int pos;
    public String toString() {
        String _s = "GuideAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "type: " + String.valueOf(type) + "(" + Integer.toHexString(type).toUpperCase() + "), ";
        _s = _s + "pos: " + String.valueOf(pos) + "(" + Integer.toHexString(pos).toUpperCase() + "), ";
        return _s;
    }
}
class DocProgTagsContainer {
    RecordHeader rh;
    final java.util.List<DocProgTagsSubContainerOrAtom> rgChildRec = new java.util.ArrayList<DocProgTagsSubContainerOrAtom>();
    public String toString() {
        String _s = "DocProgTagsContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgChildRec: " + String.valueOf(rgChildRec) + ", ";
        return _s;
    }
}
class DocProgBinaryTagContainerOrAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "DocProgBinaryTagContainerOrAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SorterViewInfoContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SorterViewInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class VBAInfoAtom {
    RecordHeader rh;
    int persistIdRef;
    int fHasMacros;
    int version;
    public String toString() {
        String _s = "VBAInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "persistIdRef: " + String.valueOf(persistIdRef) + "(" + Integer.toHexString(persistIdRef).toUpperCase() + "), ";
        _s = _s + "fHasMacros: " + String.valueOf(fHasMacros) + "(" + Integer.toHexString(fHasMacros).toUpperCase() + "), ";
        _s = _s + "version: " + String.valueOf(version) + "(" + Integer.toHexString(version).toUpperCase() + "), ";
        return _s;
    }
}
class MasterListWithTextContainer {
    RecordHeader rh;
    MasterPersistAtom[] rgMasterPersistAtom;
    public String toString() {
        String _s = "MasterListWithTextContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgMasterPersistAtom: " + String.valueOf(rgMasterPersistAtom) + ", ";
        return _s;
    }
}
class SlideListWithTextContainer {
    RecordHeader rh;
    final java.util.List<SlideListWithTextSubContainerOrAtom> rgChildRec = new java.util.ArrayList<SlideListWithTextSubContainerOrAtom>();
    public String toString() {
        String _s = "SlideListWithTextContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgChildRec: " + String.valueOf(rgChildRec) + ", ";
        return _s;
    }
}
class NotesListWithTextContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "NotesListWithTextContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class TextHeaderAtom {
    RecordHeader rh;
    int textType;
    public String toString() {
        String _s = "TextHeaderAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "textType: " + String.valueOf(textType) + "(" + Integer.toHexString(textType).toUpperCase() + "), ";
        return _s;
    }
}
class TextCharsAtom {
    RecordHeader rh;
    int[] textChars;
    public String toString() {
        String _s = "TextCharsAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "textChars: " + String.valueOf(textChars) + ", ";
        return _s;
    }
}
class TextBytesAtom {
    RecordHeader rh;
    byte[] textChars;
    public String toString() {
        String _s = "TextBytesAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "textChars: " + String.valueOf(textChars) + ", ";
        return _s;
    }
}
class MasterTextPropAtom {
    RecordHeader rh;
    final java.util.List<MasterTextPropRun> rgMasterTextPropRun = new java.util.ArrayList<MasterTextPropRun>();
    public String toString() {
        String _s = "MasterTextPropAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgMasterTextPropRun: " + String.valueOf(rgMasterTextPropRun) + ", ";
        return _s;
    }
}
class MasterTextPropRun {
    int count;
    int indentLevel;
    public String toString() {
        String _s = "MasterTextPropRun:";
        _s = _s + "count: " + String.valueOf(count) + "(" + Integer.toHexString(count).toUpperCase() + "), ";
        _s = _s + "indentLevel: " + String.valueOf(indentLevel) + "(" + Integer.toHexString(indentLevel).toUpperCase() + "), ";
        return _s;
    }
}
class StyleTextPropAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "StyleTextPropAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideNumberMCAtom {
    RecordHeader rh;
    int position;
    public String toString() {
        String _s = "SlideNumberMCAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        return _s;
    }
}
class DateTimeMCAtom {
    RecordHeader rh;
    int position;
    byte index;
    byte[] unused;
    public String toString() {
        String _s = "DateTimeMCAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        _s = _s + "index: " + String.valueOf(index) + "(" + Integer.toHexString(index).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        return _s;
    }
}
class GenericDateMCAtom {
    RecordHeader rh;
    int position;
    public String toString() {
        String _s = "GenericDateMCAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        return _s;
    }
}
class HeaderMCAtom {
    RecordHeader rh;
    int position;
    public String toString() {
        String _s = "HeaderMCAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        return _s;
    }
}
class FooterMCAtom {
    RecordHeader rh;
    int position;
    public String toString() {
        String _s = "FooterMCAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        return _s;
    }
}
class RTFDateTimeMCAtom {
    RecordHeader rh;
    int position;
    byte[] format;
    public String toString() {
        String _s = "RTFDateTimeMCAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        _s = _s + "format: " + String.valueOf(format) + ", ";
        return _s;
    }
}
class TextBookmarkAtom {
    RecordHeader rh;
    int begin;
    int end;
    int bookmarkID;
    public String toString() {
        String _s = "TextBookmarkAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "begin: " + String.valueOf(begin) + "(" + Integer.toHexString(begin).toUpperCase() + "), ";
        _s = _s + "end: " + String.valueOf(end) + "(" + Integer.toHexString(end).toUpperCase() + "), ";
        _s = _s + "bookmarkID: " + String.valueOf(bookmarkID) + "(" + Integer.toHexString(bookmarkID).toUpperCase() + "), ";
        return _s;
    }
}
class MouseTextInteractiveInfoAtom {
    RecordHeader rh;
    byte[] range;
    public String toString() {
        String _s = "MouseTextInteractiveInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "range: " + String.valueOf(range) + ", ";
        return _s;
    }
}
class SlideId {
    int slideId;
    public String toString() {
        String _s = "SlideId:";
        _s = _s + "slideId: " + String.valueOf(slideId) + "(" + Integer.toHexString(slideId).toUpperCase() + "), ";
        return _s;
    }
}
class TabStops {
    int count;
    TabStop[] rgTabStop;
    public String toString() {
        String _s = "TabStops:";
        _s = _s + "count: " + String.valueOf(count) + "(" + Integer.toHexString(count).toUpperCase() + "), ";
        _s = _s + "rgTabStop: " + String.valueOf(rgTabStop) + ", ";
        return _s;
    }
}
class TabStop {
    short position;
    int type;
    public String toString() {
        String _s = "TabStop:";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        _s = _s + "type: " + String.valueOf(type) + "(" + Integer.toHexString(type).toUpperCase() + "), ";
        return _s;
    }
}
class ColorIndexStruct {
    byte red;
    byte green;
    byte blue;
    byte index;
    public String toString() {
        String _s = "ColorIndexStruct:";
        _s = _s + "red: " + String.valueOf(red) + "(" + Integer.toHexString(red).toUpperCase() + "), ";
        _s = _s + "green: " + String.valueOf(green) + "(" + Integer.toHexString(green).toUpperCase() + "), ";
        _s = _s + "blue: " + String.valueOf(blue) + "(" + Integer.toHexString(blue).toUpperCase() + "), ";
        _s = _s + "index: " + String.valueOf(index) + "(" + Integer.toHexString(index).toUpperCase() + "), ";
        return _s;
    }
}
class BulletFlags {
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
        _s = _s + "reserved: " + String.valueOf(reserved) + "(" + Integer.toHexString(reserved).toUpperCase() + "), ";
        return _s;
    }
}
class PFMasks {
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
        _s = _s + "reserved2: " + String.valueOf(reserved2) + "(" + Integer.toHexString(reserved2).toUpperCase() + "), ";
        return _s;
    }
}
class CFMasks {
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
        _s = _s + "fHasStyle: " + String.valueOf(fHasStyle) + "(" + Integer.toHexString(fHasStyle).toUpperCase() + "), ";
        _s = _s + "unused4: " + String.valueOf(unused4) + "(" + Integer.toHexString(unused4).toUpperCase() + "), ";
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
        _s = _s + "reserved: " + String.valueOf(reserved) + "(" + Integer.toHexString(reserved).toUpperCase() + "), ";
        return _s;
    }
}
class CFStyle {
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
        _s = _s + "pp9rt: " + String.valueOf(pp9rt) + "(" + Integer.toHexString(pp9rt).toUpperCase() + "), ";
        _s = _s + "unused4: " + String.valueOf(unused4) + "(" + Integer.toHexString(unused4).toUpperCase() + "), ";
        return _s;
    }
}
class FontCollectionContainer {
    RecordHeader rh;
    final java.util.List<FontCollectionEntry> rgFontCollectionEntry = new java.util.ArrayList<FontCollectionEntry>();
    public String toString() {
        String _s = "FontCollectionContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgFontCollectionEntry: " + String.valueOf(rgFontCollectionEntry) + ", ";
        return _s;
    }
}
class FontEntityAtom {
    RecordHeader rh;
    int[] lfFaceName;
    byte lfCharSet;
    boolean fEmbedSubsetted;
    byte unused;
    boolean rasterFontType;
    boolean deviceFontType;
    boolean truetypeFontType;
    boolean fNoFontSubstitution;
    byte reserved;
    byte lfPitchAndFamily;
    public String toString() {
        String _s = "FontEntityAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "lfFaceName: " + String.valueOf(lfFaceName) + ", ";
        _s = _s + "lfCharSet: " + String.valueOf(lfCharSet) + "(" + Integer.toHexString(lfCharSet).toUpperCase() + "), ";
        _s = _s + "fEmbedSubsetted: " + String.valueOf(fEmbedSubsetted) + ", ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        _s = _s + "rasterFontType: " + String.valueOf(rasterFontType) + ", ";
        _s = _s + "deviceFontType: " + String.valueOf(deviceFontType) + ", ";
        _s = _s + "truetypeFontType: " + String.valueOf(truetypeFontType) + ", ";
        _s = _s + "fNoFontSubstitution: " + String.valueOf(fNoFontSubstitution) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + "(" + Integer.toHexString(reserved).toUpperCase() + "), ";
        _s = _s + "lfPitchAndFamily: " + String.valueOf(lfPitchAndFamily) + "(" + Integer.toHexString(lfPitchAndFamily).toUpperCase() + "), ";
        return _s;
    }
}
class FontEmbedDataBlob {
    RecordHeader rh;
    byte[] data;
    public String toString() {
        String _s = "FontEmbedDataBlob:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "data: " + String.valueOf(data) + ", ";
        return _s;
    }
}
class KinsokuAtom {
    RecordHeader rh;
    int level;
    public String toString() {
        String _s = "KinsokuAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "level: " + String.valueOf(level) + "(" + Integer.toHexString(level).toUpperCase() + "), ";
        return _s;
    }
}
class KinsokuLeadingAtom {
    RecordHeader rh;
    int kinsokuLeading;
    public String toString() {
        String _s = "KinsokuLeadingAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "kinsokuLeading: " + String.valueOf(kinsokuLeading) + "(" + Integer.toHexString(kinsokuLeading).toUpperCase() + "), ";
        return _s;
    }
}
class KinsokuFollowingAtom {
    RecordHeader rh;
    int kinsokuFollowing;
    public String toString() {
        String _s = "KinsokuFollowingAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "kinsokuFollowing: " + String.valueOf(kinsokuFollowing) + "(" + Integer.toHexString(kinsokuFollowing).toUpperCase() + "), ";
        return _s;
    }
}
class TextSpecialInfoAtom {
    RecordHeader rh;
    final java.util.List<TextSIRun> rgSIRun = new java.util.ArrayList<TextSIRun>();
    public String toString() {
        String _s = "TextSpecialInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgSIRun: " + String.valueOf(rgSIRun) + ", ";
        return _s;
    }
}
class SmartTags {
    int count;
    int[] rgSmartTagIndex;
    public String toString() {
        String _s = "SmartTags:";
        _s = _s + "count: " + String.valueOf(count) + "(" + Integer.toHexString(count).toUpperCase() + "), ";
        _s = _s + "rgSmartTagIndex: " + String.valueOf(rgSmartTagIndex) + ", ";
        return _s;
    }
}
class ExOleEmbedAtom {
    RecordHeader rh;
    int exColorFollow;
    byte fCantLockServer;
    byte fNoSizeToServer;
    byte fIsTable;
    byte unused;
    public String toString() {
        String _s = "ExOleEmbedAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exColorFollow: " + String.valueOf(exColorFollow) + "(" + Integer.toHexString(exColorFollow).toUpperCase() + "), ";
        _s = _s + "fCantLockServer: " + String.valueOf(fCantLockServer) + "(" + Integer.toHexString(fCantLockServer).toUpperCase() + "), ";
        _s = _s + "fNoSizeToServer: " + String.valueOf(fNoSizeToServer) + "(" + Integer.toHexString(fNoSizeToServer).toUpperCase() + "), ";
        _s = _s + "fIsTable: " + String.valueOf(fIsTable) + "(" + Integer.toHexString(fIsTable).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        return _s;
    }
}
class PointStruct {
    int x;
    int y;
    public String toString() {
        String _s = "PointStruct:";
        _s = _s + "x: " + String.valueOf(x) + "(" + Integer.toHexString(x).toUpperCase() + "), ";
        _s = _s + "y: " + String.valueOf(y) + "(" + Integer.toHexString(y).toUpperCase() + "), ";
        return _s;
    }
}
class RatioStruct {
    int numer;
    int denom;
    public String toString() {
        String _s = "RatioStruct:";
        _s = _s + "numer: " + String.valueOf(numer) + "(" + Integer.toHexString(numer).toUpperCase() + "), ";
        _s = _s + "denom: " + String.valueOf(denom) + "(" + Integer.toHexString(denom).toUpperCase() + "), ";
        return _s;
    }
}
class PersistDirectoryAtom {
    RecordHeader rh;
    final java.util.List<PersistDirectoryEntry> rgPersistDirEntry = new java.util.ArrayList<PersistDirectoryEntry>();
    public String toString() {
        String _s = "PersistDirectoryAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgPersistDirEntry: " + String.valueOf(rgPersistDirEntry) + ", ";
        return _s;
    }
}
class UnknownDocumentContainerChild {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownDocumentContainerChild:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UnknownDocumentContainerChild2 {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownDocumentContainerChild2:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UnknownDocumentContainerChild3 {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownDocumentContainerChild3:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UnknownDocumentContainerChild4 {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownDocumentContainerChild4:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UnknownOfficeArtClientDataChild {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownOfficeArtClientDataChild:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UnknownSlideContainerChild {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownSlideContainerChild:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class PersistDirectoryEntry {
    int persistId;
    short cPersist;
    PersistOffsetEntry[] rgPersistOffset;
    public String toString() {
        String _s = "PersistDirectoryEntry:";
        _s = _s + "persistId: " + String.valueOf(persistId) + "(" + Integer.toHexString(persistId).toUpperCase() + "), ";
        _s = _s + "cPersist: " + String.valueOf(cPersist) + "(" + Integer.toHexString(cPersist).toUpperCase() + "), ";
        _s = _s + "rgPersistOffset: " + String.valueOf(rgPersistOffset) + ", ";
        return _s;
    }
}
class PersistOffsetEntry {
    int anon;
    public String toString() {
        String _s = "PersistOffsetEntry:";
        _s = _s + "anon: " + String.valueOf(anon) + "(" + Integer.toHexString(anon).toUpperCase() + "), ";
        return _s;
    }
}
class PersistIdRef {
    int anon;
    public String toString() {
        String _s = "PersistIdRef:";
        _s = _s + "anon: " + String.valueOf(anon) + "(" + Integer.toHexString(anon).toUpperCase() + "), ";
        return _s;
    }
}
class SchemeListElementColorSchemeAtom {
    RecordHeader rh;
    ColorStruct[] rgSchemeColor;
    public String toString() {
        String _s = "SchemeListElementColorSchemeAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgSchemeColor: " + String.valueOf(rgSchemeColor) + ", ";
        return _s;
    }
}
class RoundTripOArtTextStyles12Atom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "RoundTripOArtTextStyles12Atom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideNameAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SlideNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideProgTagsContainer {
    RecordHeader rh;
    final java.util.List<SlideProgTagsSubContainerOrAtom> rgTypeRec = new java.util.ArrayList<SlideProgTagsSubContainerOrAtom>();
    public String toString() {
        String _s = "SlideProgTagsContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgTypeRec: " + String.valueOf(rgTypeRec) + ", ";
        return _s;
    }
}
class SlideProgBinaryTagContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SlideProgBinaryTagContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class TagNameAtom {
    RecordHeader rh;
    int[] tagName;
    public String toString() {
        String _s = "TagNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "tagName: " + String.valueOf(tagName) + ", ";
        return _s;
    }
}
class TagValueAtom {
    RecordHeader rh;
    int[] tagValue;
    public String toString() {
        String _s = "TagValueAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "tagValue: " + String.valueOf(tagValue) + ", ";
        return _s;
    }
}
class RoundTripMainMasterRecord {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "RoundTripMainMasterRecord:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class TemplateNameAtom {
    RecordHeader rh;
    int[] templateName;
    public String toString() {
        String _s = "TemplateNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "templateName: " + String.valueOf(templateName) + ", ";
        return _s;
    }
}
class RoundTripSlideSyncInfo12Container {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "RoundTripSlideSyncInfo12Container:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class NotesContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "NotesContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class HandoutContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "HandoutContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExControlStg {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExControlStg:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExOleObjStg {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExOleObjStg:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UserEditAtom {
    RecordHeader rh;
    int lastSlideIdRef;
    int version;
    byte minorVersion;
    byte majorVersion;
    int offsetLastEdit;
    int offsetPersistDirectory;
    int docPersistIdRef;
    int persistIdSeed;
    int lastView;
    int unused;
    int encryptSessionPersistIdRef;
    public String toString() {
        String _s = "UserEditAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "lastSlideIdRef: " + String.valueOf(lastSlideIdRef) + "(" + Integer.toHexString(lastSlideIdRef).toUpperCase() + "), ";
        _s = _s + "version: " + String.valueOf(version) + "(" + Integer.toHexString(version).toUpperCase() + "), ";
        _s = _s + "minorVersion: " + String.valueOf(minorVersion) + "(" + Integer.toHexString(minorVersion).toUpperCase() + "), ";
        _s = _s + "majorVersion: " + String.valueOf(majorVersion) + "(" + Integer.toHexString(majorVersion).toUpperCase() + "), ";
        _s = _s + "offsetLastEdit: " + String.valueOf(offsetLastEdit) + "(" + Integer.toHexString(offsetLastEdit).toUpperCase() + "), ";
        _s = _s + "offsetPersistDirectory: " + String.valueOf(offsetPersistDirectory) + "(" + Integer.toHexString(offsetPersistDirectory).toUpperCase() + "), ";
        _s = _s + "docPersistIdRef: " + String.valueOf(docPersistIdRef) + "(" + Integer.toHexString(docPersistIdRef).toUpperCase() + "), ";
        _s = _s + "persistIdSeed: " + String.valueOf(persistIdSeed) + "(" + Integer.toHexString(persistIdSeed).toUpperCase() + "), ";
        _s = _s + "lastView: " + String.valueOf(lastView) + "(" + Integer.toHexString(lastView).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        _s = _s + "encryptSessionPersistIdRef: " + String.valueOf(encryptSessionPersistIdRef) + "(" + Integer.toHexString(encryptSessionPersistIdRef).toUpperCase() + "), ";
        return _s;
    }
}
class VbaProjectStg {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "VbaProjectStg:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideProgTagscontainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SlideProgTagscontainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideAtom {
    RecordHeader rh;
    int geom;
    byte[] rgPlaceholderTypes;
    int masterIdRef;
    int notesIdRef;
    int slideFlags;
    int unused;
    public String toString() {
        String _s = "SlideAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "geom: " + String.valueOf(geom) + "(" + Integer.toHexString(geom).toUpperCase() + "), ";
        _s = _s + "rgPlaceholderTypes: " + String.valueOf(rgPlaceholderTypes) + ", ";
        _s = _s + "masterIdRef: " + String.valueOf(masterIdRef) + "(" + Integer.toHexString(masterIdRef).toUpperCase() + "), ";
        _s = _s + "notesIdRef: " + String.valueOf(notesIdRef) + "(" + Integer.toHexString(notesIdRef).toUpperCase() + "), ";
        _s = _s + "slideFlags: " + String.valueOf(slideFlags) + "(" + Integer.toHexString(slideFlags).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        return _s;
    }
}
class SlideShowSlideInfoAtom {
    RecordHeader rh;
    int slidetime;
    int slideIdRef;
    byte effectDirection;
    byte effectType;
    boolean fManualAdvance;
    boolean reserved;
    boolean fHidden;
    boolean reserved2;
    boolean fSound;
    boolean reserved3;
    boolean fLoopSound;
    boolean reserved4;
    boolean fStopSound;
    boolean freserved5;
    boolean fAutoAdvance;
    boolean reserved6;
    boolean fCursorVisible;
    byte reserved7;
    byte speed;
    byte[] unused;
    public String toString() {
        String _s = "SlideShowSlideInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slidetime: " + String.valueOf(slidetime) + "(" + Integer.toHexString(slidetime).toUpperCase() + "), ";
        _s = _s + "slideIdRef: " + String.valueOf(slideIdRef) + "(" + Integer.toHexString(slideIdRef).toUpperCase() + "), ";
        _s = _s + "effectDirection: " + String.valueOf(effectDirection) + "(" + Integer.toHexString(effectDirection).toUpperCase() + "), ";
        _s = _s + "effectType: " + String.valueOf(effectType) + "(" + Integer.toHexString(effectType).toUpperCase() + "), ";
        _s = _s + "fManualAdvance: " + String.valueOf(fManualAdvance) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + ", ";
        _s = _s + "fHidden: " + String.valueOf(fHidden) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + ", ";
        _s = _s + "fSound: " + String.valueOf(fSound) + ", ";
        _s = _s + "reserved3: " + String.valueOf(reserved3) + ", ";
        _s = _s + "fLoopSound: " + String.valueOf(fLoopSound) + ", ";
        _s = _s + "reserved4: " + String.valueOf(reserved4) + ", ";
        _s = _s + "fStopSound: " + String.valueOf(fStopSound) + ", ";
        _s = _s + "freserved5: " + String.valueOf(freserved5) + ", ";
        _s = _s + "fAutoAdvance: " + String.valueOf(fAutoAdvance) + ", ";
        _s = _s + "reserved6: " + String.valueOf(reserved6) + ", ";
        _s = _s + "fCursorVisible: " + String.valueOf(fCursorVisible) + ", ";
        _s = _s + "reserved7: " + String.valueOf(reserved7) + "(" + Integer.toHexString(reserved7).toUpperCase() + "), ";
        _s = _s + "speed: " + String.valueOf(speed) + "(" + Integer.toHexString(speed).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        return _s;
    }
}
class SlideShowDocInfoAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SlideShowDocInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SlideSchemeColorSchemeAtom {
    RecordHeader rh;
    ColorStruct[] rgSchemeColor;
    public String toString() {
        String _s = "SlideSchemeColorSchemeAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgSchemeColor: " + String.valueOf(rgSchemeColor) + ", ";
        return _s;
    }
}
class RoundTripSlideRecord {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "RoundTripSlideRecord:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class NamedShowsContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "NamedShowsContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class SummaryContainer {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "SummaryContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class DocRoutingSlipAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "DocRoutingSlipAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class PrintOptionsAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "PrintOptionsAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class RoundTripCustomTableStyles12Atom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "RoundTripCustomTableStyles12Atom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ColorStruct {
    byte red;
    byte green;
    byte blue;
    byte unused;
    public String toString() {
        String _s = "ColorStruct:";
        _s = _s + "red: " + String.valueOf(red) + "(" + Integer.toHexString(red).toUpperCase() + "), ";
        _s = _s + "green: " + String.valueOf(green) + "(" + Integer.toHexString(green).toUpperCase() + "), ";
        _s = _s + "blue: " + String.valueOf(blue) + "(" + Integer.toHexString(blue).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        return _s;
    }
}
class ExObjListAtom {
    RecordHeader rh;
    int exObjIdSeed;
    public String toString() {
        String _s = "ExObjListAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exObjIdSeed: " + String.valueOf(exObjIdSeed) + "(" + Integer.toHexString(exObjIdSeed).toUpperCase() + "), ";
        return _s;
    }
}
class ExAviMovieContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExAviMovieContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExCDAudioContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExCDAudioContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExControlContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExControlContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExHyperlinkContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExHyperlinkContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExMCIMovieContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExMCIMovieContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExMIDIAudioContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExMIDIAudioContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExWAVAudioEmbeddedContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExWAVAudioEmbeddedContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExWAVAudioLinkContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExWAVAudioLinkContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class UnknownExObjListSubContainerChild {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "UnknownExObjListSubContainerChild:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExOleLinkAtom {
    RecordHeader rh;
    int slideIdRef;
    int oleUpdateMode;
    int unused;
    public String toString() {
        String _s = "ExOleLinkAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slideIdRef: " + String.valueOf(slideIdRef) + "(" + Integer.toHexString(slideIdRef).toUpperCase() + "), ";
        _s = _s + "oleUpdateMode: " + String.valueOf(oleUpdateMode) + "(" + Integer.toHexString(oleUpdateMode).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        return _s;
    }
}
class ExOleObjAtom {
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
        _s = _s + "drawAspect: " + String.valueOf(drawAspect) + "(" + Integer.toHexString(drawAspect).toUpperCase() + "), ";
        _s = _s + "type: " + String.valueOf(type) + "(" + Integer.toHexString(type).toUpperCase() + "), ";
        _s = _s + "exObjId: " + String.valueOf(exObjId) + "(" + Integer.toHexString(exObjId).toUpperCase() + "), ";
        _s = _s + "subType: " + String.valueOf(subType) + "(" + Integer.toHexString(subType).toUpperCase() + "), ";
        _s = _s + "persistIdRef: " + String.valueOf(persistIdRef) + "(" + Integer.toHexString(persistIdRef).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        return _s;
    }
}
class MenuNameAtom {
    RecordHeader rh;
    byte[] menuName;
    public String toString() {
        String _s = "MenuNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "menuName: " + String.valueOf(menuName) + ", ";
        return _s;
    }
}
class ProgIDAtom {
    RecordHeader rh;
    byte[] progId;
    public String toString() {
        String _s = "ProgIDAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "progId: " + String.valueOf(progId) + ", ";
        return _s;
    }
}
class ClipboardNameAtom {
    RecordHeader rh;
    byte[] clipboardName;
    public String toString() {
        String _s = "ClipboardNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "clipboardName: " + String.valueOf(clipboardName) + ", ";
        return _s;
    }
}
class MetafileBlob {
    RecordHeader rh;
    short mm;
    short xExt;
    short yExt;
    byte[] data;
    public String toString() {
        String _s = "MetafileBlob:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "mm: " + String.valueOf(mm) + "(" + Integer.toHexString(mm).toUpperCase() + "), ";
        _s = _s + "xExt: " + String.valueOf(xExt) + "(" + Integer.toHexString(xExt).toUpperCase() + "), ";
        _s = _s + "yExt: " + String.valueOf(yExt) + "(" + Integer.toHexString(yExt).toUpperCase() + "), ";
        _s = _s + "data: " + String.valueOf(data) + ", ";
        return _s;
    }
}
class OfficeArtFDGG {
    int spidMax;
    int cidcl;
    int cspSaved;
    int cdgSaved;
    public String toString() {
        String _s = "OfficeArtFDGG:";
        _s = _s + "spidMax: " + String.valueOf(spidMax) + "(" + Integer.toHexString(spidMax).toUpperCase() + "), ";
        _s = _s + "cidcl: " + String.valueOf(cidcl) + "(" + Integer.toHexString(cidcl).toUpperCase() + "), ";
        _s = _s + "cspSaved: " + String.valueOf(cspSaved) + "(" + Integer.toHexString(cspSaved).toUpperCase() + "), ";
        _s = _s + "cdgSaved: " + String.valueOf(cdgSaved) + "(" + Integer.toHexString(cdgSaved).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtFDG {
    OfficeArtRecordHeader rh;
    int csp;
    int spidCur;
    public String toString() {
        String _s = "OfficeArtFDG:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "csp: " + String.valueOf(csp) + "(" + Integer.toHexString(csp).toUpperCase() + "), ";
        _s = _s + "spidCur: " + String.valueOf(spidCur) + "(" + Integer.toHexString(spidCur).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtFRITContainer {
    OfficeArtRecordHeader rh;
    OfficeArtFRIT[] rgfrit;
    public String toString() {
        String _s = "OfficeArtFRITContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgfrit: " + String.valueOf(rgfrit) + ", ";
        return _s;
    }
}
class OfficeArtFRIT {
    int fridNew;
    int fridOld;
    public String toString() {
        String _s = "OfficeArtFRIT:";
        _s = _s + "fridNew: " + String.valueOf(fridNew) + "(" + Integer.toHexString(fridNew).toUpperCase() + "), ";
        _s = _s + "fridOld: " + String.valueOf(fridOld) + "(" + Integer.toHexString(fridOld).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtBStoreContainer {
    OfficeArtRecordHeader rh;
    final java.util.List<OfficeArtBStoreContainerFileBlock> rgfb = new java.util.ArrayList<OfficeArtBStoreContainerFileBlock>();
    public String toString() {
        String _s = "OfficeArtBStoreContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgfb: " + String.valueOf(rgfb) + ", ";
        return _s;
    }
}
class OfficeArtSpgrContainer {
    OfficeArtRecordHeader rh;
    final java.util.List<OfficeArtSpgrContainerFileBlock> rgfb = new java.util.ArrayList<OfficeArtSpgrContainerFileBlock>();
    public String toString() {
        String _s = "OfficeArtSpgrContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgfb: " + String.valueOf(rgfb) + ", ";
        return _s;
    }
}
class OfficeArtSolverContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "OfficeArtSolverContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class OfficeArtFSPGR {
    OfficeArtRecordHeader rh;
    int xLeft;
    int yTop;
    int xRight;
    int yBottom;
    public String toString() {
        String _s = "OfficeArtFSPGR:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "xLeft: " + String.valueOf(xLeft) + "(" + Integer.toHexString(xLeft).toUpperCase() + "), ";
        _s = _s + "yTop: " + String.valueOf(yTop) + "(" + Integer.toHexString(yTop).toUpperCase() + "), ";
        _s = _s + "xRight: " + String.valueOf(xRight) + "(" + Integer.toHexString(xRight).toUpperCase() + "), ";
        _s = _s + "yBottom: " + String.valueOf(yBottom) + "(" + Integer.toHexString(yBottom).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtFSP {
    OfficeArtRecordHeader rh;
    int spid;
    boolean fGroup;
    boolean fChild;
    boolean fPatriarch;
    boolean fDeleted;
    boolean fOleShape;
    boolean fHaveMaster;
    boolean fFlipH;
    boolean fFlipV;
    boolean fConnector;
    boolean fHaveAnchor;
    boolean fBackground;
    boolean fHaveSpt;
    int unused1;
    public String toString() {
        String _s = "OfficeArtFSP:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "spid: " + String.valueOf(spid) + "(" + Integer.toHexString(spid).toUpperCase() + "), ";
        _s = _s + "fGroup: " + String.valueOf(fGroup) + ", ";
        _s = _s + "fChild: " + String.valueOf(fChild) + ", ";
        _s = _s + "fPatriarch: " + String.valueOf(fPatriarch) + ", ";
        _s = _s + "fDeleted: " + String.valueOf(fDeleted) + ", ";
        _s = _s + "fOleShape: " + String.valueOf(fOleShape) + ", ";
        _s = _s + "fHaveMaster: " + String.valueOf(fHaveMaster) + ", ";
        _s = _s + "fFlipH: " + String.valueOf(fFlipH) + ", ";
        _s = _s + "fFlipV: " + String.valueOf(fFlipV) + ", ";
        _s = _s + "fConnector: " + String.valueOf(fConnector) + ", ";
        _s = _s + "fHaveAnchor: " + String.valueOf(fHaveAnchor) + ", ";
        _s = _s + "fBackground: " + String.valueOf(fBackground) + ", ";
        _s = _s + "fHaveSpt: " + String.valueOf(fHaveSpt) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + "(" + Integer.toHexString(unused1).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtFOPT {
    OfficeArtRecordHeader rh;
    OfficeArtFOPTEChoice[] fopt;
    byte[] complexData;
    public String toString() {
        String _s = "OfficeArtFOPT:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "fopt: " + String.valueOf(fopt) + ", ";
        _s = _s + "complexData: " + String.valueOf(complexData) + ", ";
        return _s;
    }
}
class OfficeArtFOPTEComplexData {
    byte[] data;
    public String toString() {
        String _s = "OfficeArtFOPTEComplexData:";
        _s = _s + "data: " + String.valueOf(data) + ", ";
        return _s;
    }
}
class FixedPoint {
    short integral;
    int fractional;
    public String toString() {
        String _s = "FixedPoint:";
        _s = _s + "integral: " + String.valueOf(integral) + "(" + Integer.toHexString(integral).toUpperCase() + "), ";
        _s = _s + "fractional: " + String.valueOf(fractional) + "(" + Integer.toHexString(fractional).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtCOLORREF {
    byte red;
    byte green;
    byte blue;
    boolean fPaletteIndex;
    boolean fPaletteRGB;
    boolean fSystemRGB;
    boolean fSchemeIndex;
    boolean fSysIndex;
    boolean unused1;
    boolean unused2;
    boolean unused3;
    public String toString() {
        String _s = "OfficeArtCOLORREF:";
        _s = _s + "red: " + String.valueOf(red) + "(" + Integer.toHexString(red).toUpperCase() + "), ";
        _s = _s + "green: " + String.valueOf(green) + "(" + Integer.toHexString(green).toUpperCase() + "), ";
        _s = _s + "blue: " + String.valueOf(blue) + "(" + Integer.toHexString(blue).toUpperCase() + "), ";
        _s = _s + "fPaletteIndex: " + String.valueOf(fPaletteIndex) + ", ";
        _s = _s + "fPaletteRGB: " + String.valueOf(fPaletteRGB) + ", ";
        _s = _s + "fSystemRGB: " + String.valueOf(fSystemRGB) + ", ";
        _s = _s + "fSchemeIndex: " + String.valueOf(fSchemeIndex) + ", ";
        _s = _s + "fSysIndex: " + String.valueOf(fSysIndex) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + ", ";
        return _s;
    }
}
class OfficeArtChildAnchor {
    OfficeArtRecordHeader rh;
    int xLeft;
    int yTop;
    int xRight;
    int yBottom;
    public String toString() {
        String _s = "OfficeArtChildAnchor:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "xLeft: " + String.valueOf(xLeft) + "(" + Integer.toHexString(xLeft).toUpperCase() + "), ";
        _s = _s + "yTop: " + String.valueOf(yTop) + "(" + Integer.toHexString(yTop).toUpperCase() + "), ";
        _s = _s + "xRight: " + String.valueOf(xRight) + "(" + Integer.toHexString(xRight).toUpperCase() + "), ";
        _s = _s + "yBottom: " + String.valueOf(yBottom) + "(" + Integer.toHexString(yBottom).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtFPSPL {
    OfficeArtRecordHeader rh;
    int spid;
    boolean reserved1;
    boolean fLast;
    public String toString() {
        String _s = "OfficeArtFPSPL:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "spid: " + String.valueOf(spid) + "(" + Integer.toHexString(spid).toUpperCase() + "), ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "fLast: " + String.valueOf(fLast) + ", ";
        return _s;
    }
}
class OfficeArtSecondaryFOPT {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "OfficeArtSecondaryFOPT:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class OfficeArtTertiaryFOPT {
    OfficeArtRecordHeader rh;
    OfficeArtFOPTE[] fopt;
    byte[] complexData;
    public String toString() {
        String _s = "OfficeArtTertiaryFOPT:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "fopt: " + String.valueOf(fopt) + ", ";
        _s = _s + "complexData: " + String.valueOf(complexData) + ", ";
        return _s;
    }
}
class RectStruct {
    int top;
    int left;
    int right;
    int bottom;
    public String toString() {
        String _s = "RectStruct:";
        _s = _s + "top: " + String.valueOf(top) + "(" + Integer.toHexString(top).toUpperCase() + "), ";
        _s = _s + "left: " + String.valueOf(left) + "(" + Integer.toHexString(left).toUpperCase() + "), ";
        _s = _s + "right: " + String.valueOf(right) + "(" + Integer.toHexString(right).toUpperCase() + "), ";
        _s = _s + "bottom: " + String.valueOf(bottom) + "(" + Integer.toHexString(bottom).toUpperCase() + "), ";
        return _s;
    }
}
class SmallRectStruct {
    short top;
    short left;
    short right;
    short bottom;
    public String toString() {
        String _s = "SmallRectStruct:";
        _s = _s + "top: " + String.valueOf(top) + "(" + Integer.toHexString(top).toUpperCase() + "), ";
        _s = _s + "left: " + String.valueOf(left) + "(" + Integer.toHexString(left).toUpperCase() + "), ";
        _s = _s + "right: " + String.valueOf(right) + "(" + Integer.toHexString(right).toUpperCase() + "), ";
        _s = _s + "bottom: " + String.valueOf(bottom) + "(" + Integer.toHexString(bottom).toUpperCase() + "), ";
        return _s;
    }
}
class ShapeFlagsAtom {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ShapeFlagsAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ShapeFlags10Atom {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ShapeFlags10Atom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class ExObjRefAtom {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ExObjRefAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class AnimationInfoContainer {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "AnimationInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class InteractiveInfoAtom {
    RecordHeader rh;
    int soundIdRef;
    int exHyperlinkIdRef;
    byte action;
    byte oleVerb;
    byte jump;
    boolean fAnimated;
    boolean fStopSound;
    boolean fCustomSoundReturn;
    boolean fVisited;
    byte reserved;
    byte hyperlinkType;
    byte[] unused;
    public String toString() {
        String _s = "InteractiveInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "soundIdRef: " + String.valueOf(soundIdRef) + "(" + Integer.toHexString(soundIdRef).toUpperCase() + "), ";
        _s = _s + "exHyperlinkIdRef: " + String.valueOf(exHyperlinkIdRef) + "(" + Integer.toHexString(exHyperlinkIdRef).toUpperCase() + "), ";
        _s = _s + "action: " + String.valueOf(action) + "(" + Integer.toHexString(action).toUpperCase() + "), ";
        _s = _s + "oleVerb: " + String.valueOf(oleVerb) + "(" + Integer.toHexString(oleVerb).toUpperCase() + "), ";
        _s = _s + "jump: " + String.valueOf(jump) + "(" + Integer.toHexString(jump).toUpperCase() + "), ";
        _s = _s + "fAnimated: " + String.valueOf(fAnimated) + ", ";
        _s = _s + "fStopSound: " + String.valueOf(fStopSound) + ", ";
        _s = _s + "fCustomSoundReturn: " + String.valueOf(fCustomSoundReturn) + ", ";
        _s = _s + "fVisited: " + String.valueOf(fVisited) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + "(" + Integer.toHexString(reserved).toUpperCase() + "), ";
        _s = _s + "hyperlinkType: " + String.valueOf(hyperlinkType) + "(" + Integer.toHexString(hyperlinkType).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + ", ";
        return _s;
    }
}
class MacroNameAtom {
    RecordHeader rh;
    byte[] macroName;
    public String toString() {
        String _s = "MacroNameAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "macroName: " + String.valueOf(macroName) + ", ";
        return _s;
    }
}
class PlaceholderAtom {
    OfficeArtRecordHeader rh;
    int position;
    byte placementId;
    byte size;
    int unused;
    public String toString() {
        String _s = "PlaceholderAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        _s = _s + "placementId: " + String.valueOf(placementId) + "(" + Integer.toHexString(placementId).toUpperCase() + "), ";
        _s = _s + "size: " + String.valueOf(size) + "(" + Integer.toHexString(size).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        return _s;
    }
}
class RecolorInfoAtom {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "RecolorInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class OutlineTextRefAtom {
    OfficeArtRecordHeader rh;
    int index;
    public String toString() {
        String _s = "OutlineTextRefAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "index: " + String.valueOf(index) + "(" + Integer.toHexString(index).toUpperCase() + "), ";
        return _s;
    }
}
class ShapeClientRoundtripDataSubcontainerOrAtom {
    OfficeArtRecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "ShapeClientRoundtripDataSubcontainerOrAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class OfficeArtClientTextBox {
    OfficeArtRecordHeader rh;
    final java.util.List<TextClientDataSubContainerOrAtom> rgChildRec = new java.util.ArrayList<TextClientDataSubContainerOrAtom>();
    public String toString() {
        String _s = "OfficeArtClientTextBox:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgChildRec: " + String.valueOf(rgChildRec) + ", ";
        return _s;
    }
}
class TextRulerAtom {
    RecordHeader rh;
    byte[] todo;
    public String toString() {
        String _s = "TextRulerAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class OfficeArtIDCL {
    int dgid;
    int cspidCur;
    public String toString() {
        String _s = "OfficeArtIDCL:";
        _s = _s + "dgid: " + String.valueOf(dgid) + "(" + Integer.toHexString(dgid).toUpperCase() + "), ";
        _s = _s + "cspidCur: " + String.valueOf(cspidCur) + "(" + Integer.toHexString(cspidCur).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtFOPTEOPID {
    short opid;
    boolean fBid;
    boolean fComplex;
    public String toString() {
        String _s = "OfficeArtFOPTEOPID:";
        _s = _s + "opid: " + String.valueOf(opid) + "(" + Integer.toHexString(opid).toUpperCase() + "), ";
        _s = _s + "fBid: " + String.valueOf(fBid) + ", ";
        _s = _s + "fComplex: " + String.valueOf(fComplex) + ", ";
        return _s;
    }
}
class OfficeArtColorMRUContainer {
    OfficeArtRecordHeader rh;
    MSOCR[] rgmsocr;
    public String toString() {
        String _s = "OfficeArtColorMRUContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rgmsocr: " + String.valueOf(rgmsocr) + ", ";
        return _s;
    }
}
class MSOCR {
    byte red;
    byte green;
    byte blue;
    byte unused1;
    boolean fSchemeIndex;
    byte unused2;
    public String toString() {
        String _s = "MSOCR:";
        _s = _s + "red: " + String.valueOf(red) + "(" + Integer.toHexString(red).toUpperCase() + "), ";
        _s = _s + "green: " + String.valueOf(green) + "(" + Integer.toHexString(green).toUpperCase() + "), ";
        _s = _s + "blue: " + String.valueOf(blue) + "(" + Integer.toHexString(blue).toUpperCase() + "), ";
        _s = _s + "unused1: " + String.valueOf(unused1) + "(" + Integer.toHexString(unused1).toUpperCase() + "), ";
        _s = _s + "fSchemeIndex: " + String.valueOf(fSchemeIndex) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtSplitMenuColorContainer {
    OfficeArtRecordHeader rh;
    MSOCR[] smca;
    public String toString() {
        String _s = "OfficeArtSplitMenuColorContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "smca: " + String.valueOf(smca) + ", ";
        return _s;
    }
}
class todo {
    RecordHeader rh;
    byte[] anon;
    public String toString() {
        String _s = "todo:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class FibBase {
    int wIdent;
    int nFib;
    int unused;
    int lid;
    int pnNext;
    boolean fDot;
    boolean fGlsy;
    boolean fComplex;
    boolean fHasPic;
    byte cQuickSaves;
    boolean fEncrypted;
    boolean fWhichTblStm;
    boolean fReadOnlyRecommended;
    boolean fWriteReservation;
    boolean fExtChar;
    boolean fLoadOverride;
    boolean fFarEast;
    boolean fObfuscated;
    int nFibBack;
    int IKey;
    byte envr;
    boolean fMac;
    boolean fEmptySpecial;
    boolean fLoadOverridePage;
    boolean reserved1;
    boolean reserved2;
    byte fSpare0;
    int reserved3;
    int reserved4;
    int reserved5;
    int reserved6;
    public String toString() {
        String _s = "FibBase:";
        _s = _s + "wIdent: " + String.valueOf(wIdent) + "(" + Integer.toHexString(wIdent).toUpperCase() + "), ";
        _s = _s + "nFib: " + String.valueOf(nFib) + "(" + Integer.toHexString(nFib).toUpperCase() + "), ";
        _s = _s + "unused: " + String.valueOf(unused) + "(" + Integer.toHexString(unused).toUpperCase() + "), ";
        _s = _s + "lid: " + String.valueOf(lid) + "(" + Integer.toHexString(lid).toUpperCase() + "), ";
        _s = _s + "pnNext: " + String.valueOf(pnNext) + "(" + Integer.toHexString(pnNext).toUpperCase() + "), ";
        _s = _s + "fDot: " + String.valueOf(fDot) + ", ";
        _s = _s + "fGlsy: " + String.valueOf(fGlsy) + ", ";
        _s = _s + "fComplex: " + String.valueOf(fComplex) + ", ";
        _s = _s + "fHasPic: " + String.valueOf(fHasPic) + ", ";
        _s = _s + "cQuickSaves: " + String.valueOf(cQuickSaves) + "(" + Integer.toHexString(cQuickSaves).toUpperCase() + "), ";
        _s = _s + "fEncrypted: " + String.valueOf(fEncrypted) + ", ";
        _s = _s + "fWhichTblStm: " + String.valueOf(fWhichTblStm) + ", ";
        _s = _s + "fReadOnlyRecommended: " + String.valueOf(fReadOnlyRecommended) + ", ";
        _s = _s + "fWriteReservation: " + String.valueOf(fWriteReservation) + ", ";
        _s = _s + "fExtChar: " + String.valueOf(fExtChar) + ", ";
        _s = _s + "fLoadOverride: " + String.valueOf(fLoadOverride) + ", ";
        _s = _s + "fFarEast: " + String.valueOf(fFarEast) + ", ";
        _s = _s + "fObfuscated: " + String.valueOf(fObfuscated) + ", ";
        _s = _s + "nFibBack: " + String.valueOf(nFibBack) + "(" + Integer.toHexString(nFibBack).toUpperCase() + "), ";
        _s = _s + "IKey: " + String.valueOf(IKey) + "(" + Integer.toHexString(IKey).toUpperCase() + "), ";
        _s = _s + "envr: " + String.valueOf(envr) + "(" + Integer.toHexString(envr).toUpperCase() + "), ";
        _s = _s + "fMac: " + String.valueOf(fMac) + ", ";
        _s = _s + "fEmptySpecial: " + String.valueOf(fEmptySpecial) + ", ";
        _s = _s + "fLoadOverridePage: " + String.valueOf(fLoadOverridePage) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + ", ";
        _s = _s + "fSpare0: " + String.valueOf(fSpare0) + "(" + Integer.toHexString(fSpare0).toUpperCase() + "), ";
        _s = _s + "reserved3: " + String.valueOf(reserved3) + "(" + Integer.toHexString(reserved3).toUpperCase() + "), ";
        _s = _s + "reserved4: " + String.valueOf(reserved4) + "(" + Integer.toHexString(reserved4).toUpperCase() + "), ";
        _s = _s + "reserved5: " + String.valueOf(reserved5) + "(" + Integer.toHexString(reserved5).toUpperCase() + "), ";
        _s = _s + "reserved6: " + String.valueOf(reserved6) + "(" + Integer.toHexString(reserved6).toUpperCase() + "), ";
        return _s;
    }
}
class FibRgW97 {
    int reserved1;
    int reserved2;
    int reserved3;
    int reserved4;
    int reserved5;
    int reserved6;
    int reserved7;
    int reserved8;
    int reserved9;
    int reserved10;
    int reserved11;
    int reserved12;
    int reserved13;
    int lidFE;
    public String toString() {
        String _s = "FibRgW97:";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + "(" + Integer.toHexString(reserved1).toUpperCase() + "), ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + "(" + Integer.toHexString(reserved2).toUpperCase() + "), ";
        _s = _s + "reserved3: " + String.valueOf(reserved3) + "(" + Integer.toHexString(reserved3).toUpperCase() + "), ";
        _s = _s + "reserved4: " + String.valueOf(reserved4) + "(" + Integer.toHexString(reserved4).toUpperCase() + "), ";
        _s = _s + "reserved5: " + String.valueOf(reserved5) + "(" + Integer.toHexString(reserved5).toUpperCase() + "), ";
        _s = _s + "reserved6: " + String.valueOf(reserved6) + "(" + Integer.toHexString(reserved6).toUpperCase() + "), ";
        _s = _s + "reserved7: " + String.valueOf(reserved7) + "(" + Integer.toHexString(reserved7).toUpperCase() + "), ";
        _s = _s + "reserved8: " + String.valueOf(reserved8) + "(" + Integer.toHexString(reserved8).toUpperCase() + "), ";
        _s = _s + "reserved9: " + String.valueOf(reserved9) + "(" + Integer.toHexString(reserved9).toUpperCase() + "), ";
        _s = _s + "reserved10: " + String.valueOf(reserved10) + "(" + Integer.toHexString(reserved10).toUpperCase() + "), ";
        _s = _s + "reserved11: " + String.valueOf(reserved11) + "(" + Integer.toHexString(reserved11).toUpperCase() + "), ";
        _s = _s + "reserved12: " + String.valueOf(reserved12) + "(" + Integer.toHexString(reserved12).toUpperCase() + "), ";
        _s = _s + "reserved13: " + String.valueOf(reserved13) + "(" + Integer.toHexString(reserved13).toUpperCase() + "), ";
        _s = _s + "lidFE: " + String.valueOf(lidFE) + "(" + Integer.toHexString(lidFE).toUpperCase() + "), ";
        return _s;
    }
}
class FibRgLw97 {
    int cbMac;
    int reserved1;
    int reserved2;
    int ccpText;
    int ccpFtn;
    int ccpHdd;
    int reserved3;
    int ccpAtn;
    int ccpEdn;
    int ccpTxbx;
    int ccpHdrTxbx;
    int reserved4;
    int reserved5;
    int reserved6;
    int reserved7;
    int reserved8;
    int reserved9;
    int reserved10;
    int reserved11;
    int reserved12;
    int reserved13;
    int reserved14;
    public String toString() {
        String _s = "FibRgLw97:";
        _s = _s + "cbMac: " + String.valueOf(cbMac) + "(" + Integer.toHexString(cbMac).toUpperCase() + "), ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + "(" + Integer.toHexString(reserved1).toUpperCase() + "), ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + "(" + Integer.toHexString(reserved2).toUpperCase() + "), ";
        _s = _s + "ccpText: " + String.valueOf(ccpText) + "(" + Integer.toHexString(ccpText).toUpperCase() + "), ";
        _s = _s + "ccpFtn: " + String.valueOf(ccpFtn) + "(" + Integer.toHexString(ccpFtn).toUpperCase() + "), ";
        _s = _s + "ccpHdd: " + String.valueOf(ccpHdd) + "(" + Integer.toHexString(ccpHdd).toUpperCase() + "), ";
        _s = _s + "reserved3: " + String.valueOf(reserved3) + "(" + Integer.toHexString(reserved3).toUpperCase() + "), ";
        _s = _s + "ccpAtn: " + String.valueOf(ccpAtn) + "(" + Integer.toHexString(ccpAtn).toUpperCase() + "), ";
        _s = _s + "ccpEdn: " + String.valueOf(ccpEdn) + "(" + Integer.toHexString(ccpEdn).toUpperCase() + "), ";
        _s = _s + "ccpTxbx: " + String.valueOf(ccpTxbx) + "(" + Integer.toHexString(ccpTxbx).toUpperCase() + "), ";
        _s = _s + "ccpHdrTxbx: " + String.valueOf(ccpHdrTxbx) + "(" + Integer.toHexString(ccpHdrTxbx).toUpperCase() + "), ";
        _s = _s + "reserved4: " + String.valueOf(reserved4) + "(" + Integer.toHexString(reserved4).toUpperCase() + "), ";
        _s = _s + "reserved5: " + String.valueOf(reserved5) + "(" + Integer.toHexString(reserved5).toUpperCase() + "), ";
        _s = _s + "reserved6: " + String.valueOf(reserved6) + "(" + Integer.toHexString(reserved6).toUpperCase() + "), ";
        _s = _s + "reserved7: " + String.valueOf(reserved7) + "(" + Integer.toHexString(reserved7).toUpperCase() + "), ";
        _s = _s + "reserved8: " + String.valueOf(reserved8) + "(" + Integer.toHexString(reserved8).toUpperCase() + "), ";
        _s = _s + "reserved9: " + String.valueOf(reserved9) + "(" + Integer.toHexString(reserved9).toUpperCase() + "), ";
        _s = _s + "reserved10: " + String.valueOf(reserved10) + "(" + Integer.toHexString(reserved10).toUpperCase() + "), ";
        _s = _s + "reserved11: " + String.valueOf(reserved11) + "(" + Integer.toHexString(reserved11).toUpperCase() + "), ";
        _s = _s + "reserved12: " + String.valueOf(reserved12) + "(" + Integer.toHexString(reserved12).toUpperCase() + "), ";
        _s = _s + "reserved13: " + String.valueOf(reserved13) + "(" + Integer.toHexString(reserved13).toUpperCase() + "), ";
        _s = _s + "reserved14: " + String.valueOf(reserved14) + "(" + Integer.toHexString(reserved14).toUpperCase() + "), ";
        return _s;
    }
}
class FibRgFcLcb97 {
    int fcStshfOrig;
    int lcbStshfOrig;
    int fcStshf;
    int lcbStshf;
    int fcPlcffndRef;
    int lcbPlcffndRef;
    int fcPlcffndTxt;
    int lcbPlcffndTxt;
    int fcPlcfandRef;
    int lcbPlcfandRef;
    int fcPlcfandTxt;
    int lcbPlcfandTxt;
    int fcPlcfSed;
    int lcbPlcfSed;
    int fcPlcPad;
    int lcbPlcPad;
    int fcPlcfPhe;
    int lcbPlcfPhe;
    int fcSttbfGlsy;
    int lcbSttbfGlsy;
    int fcPlcfGlsy;
    int lcbPlcfGlsy;
    int fcPlcfHdd;
    int lcbPlcfHdd;
    int fcPlcfBteChpx;
    int lcbPlcfBteChpx;
    int fcPlcfBtePapx;
    int lcbPlcfBtePapx;
    int fcPlcfSea;
    int lcbPlcfSea;
    int fcSttbfFfn;
    int lcbSttbfFfn;
    int fcPlcfFldMom;
    int lcbPlcfFldMom;
    int fcPlcfFldHdr;
    int lcbPlcfFldHdr;
    int fcPlcfFldFtn;
    int lcbPlcfFldFtn;
    int fcPlcfFldAtn;
    int lcbPlcfFldAtn;
    int fcPlcfFldMcr;
    int lcbPlcfFldMcr;
    int fcSttbfBkmk;
    int lcbSttbfBkmk;
    int fcPlcfBkf;
    int lcbPlcfBkf;
    int fcPlcfBkl;
    int lcbPlcfBkl;
    int fcCmds;
    int lcbCmds;
    int fcUnused1;
    int lcbUnused1;
    int fcSttbfMcr;
    int lcbSttbfMcr;
    int fcPrDrvr;
    int lcbPrDrvr;
    int fcPrEnvPort;
    int lcbPrEnvPort;
    int fcPrEnvLand;
    int lcbPrEnvLand;
    int fcWss;
    int lcbWss;
    int fcDop;
    int lcbDop;
    int fcSttbfAssoc;
    int lcbSttbfAssoc;
    int fcClx;
    int lcbClx;
    int fcPlcfPgdFtn;
    int lcbPlcfPgdFtn;
    int fcAutosaveSource;
    int lcbAutosaveSource;
    int fcGrpXstAtnOwners;
    int lcbGrpXstAtnOwners;
    int fcSttbfAtnBkmk;
    int lcbSttbfAtnBkmk;
    int fcUnused2;
    int lcbUnused2;
    int fcUnused3;
    int lcbUnused3;
    int fcPlcSpaMom;
    int lcbPlcSpaMom;
    int fcPlcSpaHdr;
    int lcbPlcSpaHdr;
    int fcPlcfAtnBkf;
    int lcbPlcfAtnBkf;
    int fcPlcfAtnBkl;
    int lcbPlcfAtnBkl;
    int fcPms;
    int lcbPms;
    int fcFormFldSttbs;
    int lcbFormFldSttbs;
    int fcPlcfendRef;
    int lcbPlcfendRef;
    int fcPlcfendTxt;
    int lcbPlcfendTxt;
    int fcPlcfFldEdn;
    int lcbPlcfFldEdn;
    int fcUnused4;
    int lcbUnused4;
    int fcDggInfo;
    int lcbDggInfo;
    int fcSttbfRMark;
    int lcbSttbfRMark;
    int fcSttbfCaption;
    int lcbSttbfCaption;
    int fcSttbfAutoCaption;
    int lcbSttbfAutoCaption;
    int fcPlcfWkb;
    int lcbPlcfWkb;
    int fcPlcfSpl;
    int lcbPlcfSpl;
    int fcPlcftxbxTxt;
    int lcbPlcftxbxTxt;
    int fcPlcfFldTxbx;
    int lcbPlcfFldTxbx;
    int fcPlcfHdrtxbxTxt;
    int lcbPlcfHdrtxbxTxt;
    int fcPlcffldHdrTxbx;
    int lcbPlcffldHdrTxbx;
    int fcStwUser;
    int lcbStwUser;
    int fcSttbTtmbd;
    int lcbSttbTtmbd;
    int fcCookieData;
    int lcbCookieData;
    int fcPgdMotherOldOld;
    int lcbPgdMotherOldOld;
    int fcBkdMotherOldOld;
    int lcbBkdMotherOldOld;
    int fcPgdFtnOldOld;
    int lcbPgdFtnOldOld;
    int fcBkdFtnOldOld;
    int lcbBkdFtnOldOld;
    int fcPgdEdnOldOld;
    int lcbPgdEdnOldOld;
    int fcBkdEdnOldOld;
    int lcbBkdEdnOldOld;
    int fcSttbfIntlFld;
    int lcbSttbfIntlFld;
    int fcRouteSlip;
    int lcbRouteSlip;
    int fcSttbSavedBy;
    int lcbSttbSavedBy;
    int fcSttbFnm;
    int lcbSttbFnm;
    int fcPlfLst;
    int lcbPlfLst;
    int fcPlfLfo;
    int lcbPlfLfo;
    int fcPlcfTxbxBkd;
    int lcbPlcfTxbxBkd;
    int fcPlcfTxbxHdrBkd;
    int lcbPlcfTxbxHdrBkd;
    int fcDocUndoWord9;
    int lcbDocUndoWord9;
    int fcRgbUse;
    int lcbRgbUse;
    int fcUsp;
    int lcbUsp;
    int fcUskf;
    int lcbUskf;
    int fcPlcupcRgbUse;
    int lcbPlcupcRgbUse;
    int fcPlcupcUsp;
    int lcbPlcupcUsp;
    int fcSttbGlsyStyle;
    int lcbSttbGlsyStyle;
    int fcPlgosl;
    int lcbPlgosl;
    int fcPlcocx;
    int lcbPlcocx;
    int fcPlcfBteLvc;
    int lcbPlcfBteLvc;
    int dwLowDateTime;
    int dwHighDateTime;
    int fcPlcfLvcPre10;
    int lcbPlcfLvcPre10;
    int fcPlcfAsumy;
    int lcbPlcfAsumy;
    int fcPlcfGram;
    int lcbPlcfGram;
    int fcSttbListNames;
    int lcbSttbListNames;
    int fcSttbfUssr;
    int lcbSttbfUssr;
    public String toString() {
        String _s = "FibRgFcLcb97:";
        _s = _s + "fcStshfOrig: " + String.valueOf(fcStshfOrig) + "(" + Integer.toHexString(fcStshfOrig).toUpperCase() + "), ";
        _s = _s + "lcbStshfOrig: " + String.valueOf(lcbStshfOrig) + "(" + Integer.toHexString(lcbStshfOrig).toUpperCase() + "), ";
        _s = _s + "fcStshf: " + String.valueOf(fcStshf) + "(" + Integer.toHexString(fcStshf).toUpperCase() + "), ";
        _s = _s + "lcbStshf: " + String.valueOf(lcbStshf) + "(" + Integer.toHexString(lcbStshf).toUpperCase() + "), ";
        _s = _s + "fcPlcffndRef: " + String.valueOf(fcPlcffndRef) + "(" + Integer.toHexString(fcPlcffndRef).toUpperCase() + "), ";
        _s = _s + "lcbPlcffndRef: " + String.valueOf(lcbPlcffndRef) + "(" + Integer.toHexString(lcbPlcffndRef).toUpperCase() + "), ";
        _s = _s + "fcPlcffndTxt: " + String.valueOf(fcPlcffndTxt) + "(" + Integer.toHexString(fcPlcffndTxt).toUpperCase() + "), ";
        _s = _s + "lcbPlcffndTxt: " + String.valueOf(lcbPlcffndTxt) + "(" + Integer.toHexString(lcbPlcffndTxt).toUpperCase() + "), ";
        _s = _s + "fcPlcfandRef: " + String.valueOf(fcPlcfandRef) + "(" + Integer.toHexString(fcPlcfandRef).toUpperCase() + "), ";
        _s = _s + "lcbPlcfandRef: " + String.valueOf(lcbPlcfandRef) + "(" + Integer.toHexString(lcbPlcfandRef).toUpperCase() + "), ";
        _s = _s + "fcPlcfandTxt: " + String.valueOf(fcPlcfandTxt) + "(" + Integer.toHexString(fcPlcfandTxt).toUpperCase() + "), ";
        _s = _s + "lcbPlcfandTxt: " + String.valueOf(lcbPlcfandTxt) + "(" + Integer.toHexString(lcbPlcfandTxt).toUpperCase() + "), ";
        _s = _s + "fcPlcfSed: " + String.valueOf(fcPlcfSed) + "(" + Integer.toHexString(fcPlcfSed).toUpperCase() + "), ";
        _s = _s + "lcbPlcfSed: " + String.valueOf(lcbPlcfSed) + "(" + Integer.toHexString(lcbPlcfSed).toUpperCase() + "), ";
        _s = _s + "fcPlcPad: " + String.valueOf(fcPlcPad) + "(" + Integer.toHexString(fcPlcPad).toUpperCase() + "), ";
        _s = _s + "lcbPlcPad: " + String.valueOf(lcbPlcPad) + "(" + Integer.toHexString(lcbPlcPad).toUpperCase() + "), ";
        _s = _s + "fcPlcfPhe: " + String.valueOf(fcPlcfPhe) + "(" + Integer.toHexString(fcPlcfPhe).toUpperCase() + "), ";
        _s = _s + "lcbPlcfPhe: " + String.valueOf(lcbPlcfPhe) + "(" + Integer.toHexString(lcbPlcfPhe).toUpperCase() + "), ";
        _s = _s + "fcSttbfGlsy: " + String.valueOf(fcSttbfGlsy) + "(" + Integer.toHexString(fcSttbfGlsy).toUpperCase() + "), ";
        _s = _s + "lcbSttbfGlsy: " + String.valueOf(lcbSttbfGlsy) + "(" + Integer.toHexString(lcbSttbfGlsy).toUpperCase() + "), ";
        _s = _s + "fcPlcfGlsy: " + String.valueOf(fcPlcfGlsy) + "(" + Integer.toHexString(fcPlcfGlsy).toUpperCase() + "), ";
        _s = _s + "lcbPlcfGlsy: " + String.valueOf(lcbPlcfGlsy) + "(" + Integer.toHexString(lcbPlcfGlsy).toUpperCase() + "), ";
        _s = _s + "fcPlcfHdd: " + String.valueOf(fcPlcfHdd) + "(" + Integer.toHexString(fcPlcfHdd).toUpperCase() + "), ";
        _s = _s + "lcbPlcfHdd: " + String.valueOf(lcbPlcfHdd) + "(" + Integer.toHexString(lcbPlcfHdd).toUpperCase() + "), ";
        _s = _s + "fcPlcfBteChpx: " + String.valueOf(fcPlcfBteChpx) + "(" + Integer.toHexString(fcPlcfBteChpx).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBteChpx: " + String.valueOf(lcbPlcfBteChpx) + "(" + Integer.toHexString(lcbPlcfBteChpx).toUpperCase() + "), ";
        _s = _s + "fcPlcfBtePapx: " + String.valueOf(fcPlcfBtePapx) + "(" + Integer.toHexString(fcPlcfBtePapx).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBtePapx: " + String.valueOf(lcbPlcfBtePapx) + "(" + Integer.toHexString(lcbPlcfBtePapx).toUpperCase() + "), ";
        _s = _s + "fcPlcfSea: " + String.valueOf(fcPlcfSea) + "(" + Integer.toHexString(fcPlcfSea).toUpperCase() + "), ";
        _s = _s + "lcbPlcfSea: " + String.valueOf(lcbPlcfSea) + "(" + Integer.toHexString(lcbPlcfSea).toUpperCase() + "), ";
        _s = _s + "fcSttbfFfn: " + String.valueOf(fcSttbfFfn) + "(" + Integer.toHexString(fcSttbfFfn).toUpperCase() + "), ";
        _s = _s + "lcbSttbfFfn: " + String.valueOf(lcbSttbfFfn) + "(" + Integer.toHexString(lcbSttbfFfn).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldMom: " + String.valueOf(fcPlcfFldMom) + "(" + Integer.toHexString(fcPlcfFldMom).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldMom: " + String.valueOf(lcbPlcfFldMom) + "(" + Integer.toHexString(lcbPlcfFldMom).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldHdr: " + String.valueOf(fcPlcfFldHdr) + "(" + Integer.toHexString(fcPlcfFldHdr).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldHdr: " + String.valueOf(lcbPlcfFldHdr) + "(" + Integer.toHexString(lcbPlcfFldHdr).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldFtn: " + String.valueOf(fcPlcfFldFtn) + "(" + Integer.toHexString(fcPlcfFldFtn).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldFtn: " + String.valueOf(lcbPlcfFldFtn) + "(" + Integer.toHexString(lcbPlcfFldFtn).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldAtn: " + String.valueOf(fcPlcfFldAtn) + "(" + Integer.toHexString(fcPlcfFldAtn).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldAtn: " + String.valueOf(lcbPlcfFldAtn) + "(" + Integer.toHexString(lcbPlcfFldAtn).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldMcr: " + String.valueOf(fcPlcfFldMcr) + "(" + Integer.toHexString(fcPlcfFldMcr).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldMcr: " + String.valueOf(lcbPlcfFldMcr) + "(" + Integer.toHexString(lcbPlcfFldMcr).toUpperCase() + "), ";
        _s = _s + "fcSttbfBkmk: " + String.valueOf(fcSttbfBkmk) + "(" + Integer.toHexString(fcSttbfBkmk).toUpperCase() + "), ";
        _s = _s + "lcbSttbfBkmk: " + String.valueOf(lcbSttbfBkmk) + "(" + Integer.toHexString(lcbSttbfBkmk).toUpperCase() + "), ";
        _s = _s + "fcPlcfBkf: " + String.valueOf(fcPlcfBkf) + "(" + Integer.toHexString(fcPlcfBkf).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBkf: " + String.valueOf(lcbPlcfBkf) + "(" + Integer.toHexString(lcbPlcfBkf).toUpperCase() + "), ";
        _s = _s + "fcPlcfBkl: " + String.valueOf(fcPlcfBkl) + "(" + Integer.toHexString(fcPlcfBkl).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBkl: " + String.valueOf(lcbPlcfBkl) + "(" + Integer.toHexString(lcbPlcfBkl).toUpperCase() + "), ";
        _s = _s + "fcCmds: " + String.valueOf(fcCmds) + "(" + Integer.toHexString(fcCmds).toUpperCase() + "), ";
        _s = _s + "lcbCmds: " + String.valueOf(lcbCmds) + "(" + Integer.toHexString(lcbCmds).toUpperCase() + "), ";
        _s = _s + "fcUnused1: " + String.valueOf(fcUnused1) + "(" + Integer.toHexString(fcUnused1).toUpperCase() + "), ";
        _s = _s + "lcbUnused1: " + String.valueOf(lcbUnused1) + "(" + Integer.toHexString(lcbUnused1).toUpperCase() + "), ";
        _s = _s + "fcSttbfMcr: " + String.valueOf(fcSttbfMcr) + "(" + Integer.toHexString(fcSttbfMcr).toUpperCase() + "), ";
        _s = _s + "lcbSttbfMcr: " + String.valueOf(lcbSttbfMcr) + "(" + Integer.toHexString(lcbSttbfMcr).toUpperCase() + "), ";
        _s = _s + "fcPrDrvr: " + String.valueOf(fcPrDrvr) + "(" + Integer.toHexString(fcPrDrvr).toUpperCase() + "), ";
        _s = _s + "lcbPrDrvr: " + String.valueOf(lcbPrDrvr) + "(" + Integer.toHexString(lcbPrDrvr).toUpperCase() + "), ";
        _s = _s + "fcPrEnvPort: " + String.valueOf(fcPrEnvPort) + "(" + Integer.toHexString(fcPrEnvPort).toUpperCase() + "), ";
        _s = _s + "lcbPrEnvPort: " + String.valueOf(lcbPrEnvPort) + "(" + Integer.toHexString(lcbPrEnvPort).toUpperCase() + "), ";
        _s = _s + "fcPrEnvLand: " + String.valueOf(fcPrEnvLand) + "(" + Integer.toHexString(fcPrEnvLand).toUpperCase() + "), ";
        _s = _s + "lcbPrEnvLand: " + String.valueOf(lcbPrEnvLand) + "(" + Integer.toHexString(lcbPrEnvLand).toUpperCase() + "), ";
        _s = _s + "fcWss: " + String.valueOf(fcWss) + "(" + Integer.toHexString(fcWss).toUpperCase() + "), ";
        _s = _s + "lcbWss: " + String.valueOf(lcbWss) + "(" + Integer.toHexString(lcbWss).toUpperCase() + "), ";
        _s = _s + "fcDop: " + String.valueOf(fcDop) + "(" + Integer.toHexString(fcDop).toUpperCase() + "), ";
        _s = _s + "lcbDop: " + String.valueOf(lcbDop) + "(" + Integer.toHexString(lcbDop).toUpperCase() + "), ";
        _s = _s + "fcSttbfAssoc: " + String.valueOf(fcSttbfAssoc) + "(" + Integer.toHexString(fcSttbfAssoc).toUpperCase() + "), ";
        _s = _s + "lcbSttbfAssoc: " + String.valueOf(lcbSttbfAssoc) + "(" + Integer.toHexString(lcbSttbfAssoc).toUpperCase() + "), ";
        _s = _s + "fcClx: " + String.valueOf(fcClx) + "(" + Integer.toHexString(fcClx).toUpperCase() + "), ";
        _s = _s + "lcbClx: " + String.valueOf(lcbClx) + "(" + Integer.toHexString(lcbClx).toUpperCase() + "), ";
        _s = _s + "fcPlcfPgdFtn: " + String.valueOf(fcPlcfPgdFtn) + "(" + Integer.toHexString(fcPlcfPgdFtn).toUpperCase() + "), ";
        _s = _s + "lcbPlcfPgdFtn: " + String.valueOf(lcbPlcfPgdFtn) + "(" + Integer.toHexString(lcbPlcfPgdFtn).toUpperCase() + "), ";
        _s = _s + "fcAutosaveSource: " + String.valueOf(fcAutosaveSource) + "(" + Integer.toHexString(fcAutosaveSource).toUpperCase() + "), ";
        _s = _s + "lcbAutosaveSource: " + String.valueOf(lcbAutosaveSource) + "(" + Integer.toHexString(lcbAutosaveSource).toUpperCase() + "), ";
        _s = _s + "fcGrpXstAtnOwners: " + String.valueOf(fcGrpXstAtnOwners) + "(" + Integer.toHexString(fcGrpXstAtnOwners).toUpperCase() + "), ";
        _s = _s + "lcbGrpXstAtnOwners: " + String.valueOf(lcbGrpXstAtnOwners) + "(" + Integer.toHexString(lcbGrpXstAtnOwners).toUpperCase() + "), ";
        _s = _s + "fcSttbfAtnBkmk: " + String.valueOf(fcSttbfAtnBkmk) + "(" + Integer.toHexString(fcSttbfAtnBkmk).toUpperCase() + "), ";
        _s = _s + "lcbSttbfAtnBkmk: " + String.valueOf(lcbSttbfAtnBkmk) + "(" + Integer.toHexString(lcbSttbfAtnBkmk).toUpperCase() + "), ";
        _s = _s + "fcUnused2: " + String.valueOf(fcUnused2) + "(" + Integer.toHexString(fcUnused2).toUpperCase() + "), ";
        _s = _s + "lcbUnused2: " + String.valueOf(lcbUnused2) + "(" + Integer.toHexString(lcbUnused2).toUpperCase() + "), ";
        _s = _s + "fcUnused3: " + String.valueOf(fcUnused3) + "(" + Integer.toHexString(fcUnused3).toUpperCase() + "), ";
        _s = _s + "lcbUnused3: " + String.valueOf(lcbUnused3) + "(" + Integer.toHexString(lcbUnused3).toUpperCase() + "), ";
        _s = _s + "fcPlcSpaMom: " + String.valueOf(fcPlcSpaMom) + "(" + Integer.toHexString(fcPlcSpaMom).toUpperCase() + "), ";
        _s = _s + "lcbPlcSpaMom: " + String.valueOf(lcbPlcSpaMom) + "(" + Integer.toHexString(lcbPlcSpaMom).toUpperCase() + "), ";
        _s = _s + "fcPlcSpaHdr: " + String.valueOf(fcPlcSpaHdr) + "(" + Integer.toHexString(fcPlcSpaHdr).toUpperCase() + "), ";
        _s = _s + "lcbPlcSpaHdr: " + String.valueOf(lcbPlcSpaHdr) + "(" + Integer.toHexString(lcbPlcSpaHdr).toUpperCase() + "), ";
        _s = _s + "fcPlcfAtnBkf: " + String.valueOf(fcPlcfAtnBkf) + "(" + Integer.toHexString(fcPlcfAtnBkf).toUpperCase() + "), ";
        _s = _s + "lcbPlcfAtnBkf: " + String.valueOf(lcbPlcfAtnBkf) + "(" + Integer.toHexString(lcbPlcfAtnBkf).toUpperCase() + "), ";
        _s = _s + "fcPlcfAtnBkl: " + String.valueOf(fcPlcfAtnBkl) + "(" + Integer.toHexString(fcPlcfAtnBkl).toUpperCase() + "), ";
        _s = _s + "lcbPlcfAtnBkl: " + String.valueOf(lcbPlcfAtnBkl) + "(" + Integer.toHexString(lcbPlcfAtnBkl).toUpperCase() + "), ";
        _s = _s + "fcPms: " + String.valueOf(fcPms) + "(" + Integer.toHexString(fcPms).toUpperCase() + "), ";
        _s = _s + "lcbPms: " + String.valueOf(lcbPms) + "(" + Integer.toHexString(lcbPms).toUpperCase() + "), ";
        _s = _s + "fcFormFldSttbs: " + String.valueOf(fcFormFldSttbs) + "(" + Integer.toHexString(fcFormFldSttbs).toUpperCase() + "), ";
        _s = _s + "lcbFormFldSttbs: " + String.valueOf(lcbFormFldSttbs) + "(" + Integer.toHexString(lcbFormFldSttbs).toUpperCase() + "), ";
        _s = _s + "fcPlcfendRef: " + String.valueOf(fcPlcfendRef) + "(" + Integer.toHexString(fcPlcfendRef).toUpperCase() + "), ";
        _s = _s + "lcbPlcfendRef: " + String.valueOf(lcbPlcfendRef) + "(" + Integer.toHexString(lcbPlcfendRef).toUpperCase() + "), ";
        _s = _s + "fcPlcfendTxt: " + String.valueOf(fcPlcfendTxt) + "(" + Integer.toHexString(fcPlcfendTxt).toUpperCase() + "), ";
        _s = _s + "lcbPlcfendTxt: " + String.valueOf(lcbPlcfendTxt) + "(" + Integer.toHexString(lcbPlcfendTxt).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldEdn: " + String.valueOf(fcPlcfFldEdn) + "(" + Integer.toHexString(fcPlcfFldEdn).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldEdn: " + String.valueOf(lcbPlcfFldEdn) + "(" + Integer.toHexString(lcbPlcfFldEdn).toUpperCase() + "), ";
        _s = _s + "fcUnused4: " + String.valueOf(fcUnused4) + "(" + Integer.toHexString(fcUnused4).toUpperCase() + "), ";
        _s = _s + "lcbUnused4: " + String.valueOf(lcbUnused4) + "(" + Integer.toHexString(lcbUnused4).toUpperCase() + "), ";
        _s = _s + "fcDggInfo: " + String.valueOf(fcDggInfo) + "(" + Integer.toHexString(fcDggInfo).toUpperCase() + "), ";
        _s = _s + "lcbDggInfo: " + String.valueOf(lcbDggInfo) + "(" + Integer.toHexString(lcbDggInfo).toUpperCase() + "), ";
        _s = _s + "fcSttbfRMark: " + String.valueOf(fcSttbfRMark) + "(" + Integer.toHexString(fcSttbfRMark).toUpperCase() + "), ";
        _s = _s + "lcbSttbfRMark: " + String.valueOf(lcbSttbfRMark) + "(" + Integer.toHexString(lcbSttbfRMark).toUpperCase() + "), ";
        _s = _s + "fcSttbfCaption: " + String.valueOf(fcSttbfCaption) + "(" + Integer.toHexString(fcSttbfCaption).toUpperCase() + "), ";
        _s = _s + "lcbSttbfCaption: " + String.valueOf(lcbSttbfCaption) + "(" + Integer.toHexString(lcbSttbfCaption).toUpperCase() + "), ";
        _s = _s + "fcSttbfAutoCaption: " + String.valueOf(fcSttbfAutoCaption) + "(" + Integer.toHexString(fcSttbfAutoCaption).toUpperCase() + "), ";
        _s = _s + "lcbSttbfAutoCaption: " + String.valueOf(lcbSttbfAutoCaption) + "(" + Integer.toHexString(lcbSttbfAutoCaption).toUpperCase() + "), ";
        _s = _s + "fcPlcfWkb: " + String.valueOf(fcPlcfWkb) + "(" + Integer.toHexString(fcPlcfWkb).toUpperCase() + "), ";
        _s = _s + "lcbPlcfWkb: " + String.valueOf(lcbPlcfWkb) + "(" + Integer.toHexString(lcbPlcfWkb).toUpperCase() + "), ";
        _s = _s + "fcPlcfSpl: " + String.valueOf(fcPlcfSpl) + "(" + Integer.toHexString(fcPlcfSpl).toUpperCase() + "), ";
        _s = _s + "lcbPlcfSpl: " + String.valueOf(lcbPlcfSpl) + "(" + Integer.toHexString(lcbPlcfSpl).toUpperCase() + "), ";
        _s = _s + "fcPlcftxbxTxt: " + String.valueOf(fcPlcftxbxTxt) + "(" + Integer.toHexString(fcPlcftxbxTxt).toUpperCase() + "), ";
        _s = _s + "lcbPlcftxbxTxt: " + String.valueOf(lcbPlcftxbxTxt) + "(" + Integer.toHexString(lcbPlcftxbxTxt).toUpperCase() + "), ";
        _s = _s + "fcPlcfFldTxbx: " + String.valueOf(fcPlcfFldTxbx) + "(" + Integer.toHexString(fcPlcfFldTxbx).toUpperCase() + "), ";
        _s = _s + "lcbPlcfFldTxbx: " + String.valueOf(lcbPlcfFldTxbx) + "(" + Integer.toHexString(lcbPlcfFldTxbx).toUpperCase() + "), ";
        _s = _s + "fcPlcfHdrtxbxTxt: " + String.valueOf(fcPlcfHdrtxbxTxt) + "(" + Integer.toHexString(fcPlcfHdrtxbxTxt).toUpperCase() + "), ";
        _s = _s + "lcbPlcfHdrtxbxTxt: " + String.valueOf(lcbPlcfHdrtxbxTxt) + "(" + Integer.toHexString(lcbPlcfHdrtxbxTxt).toUpperCase() + "), ";
        _s = _s + "fcPlcffldHdrTxbx: " + String.valueOf(fcPlcffldHdrTxbx) + "(" + Integer.toHexString(fcPlcffldHdrTxbx).toUpperCase() + "), ";
        _s = _s + "lcbPlcffldHdrTxbx: " + String.valueOf(lcbPlcffldHdrTxbx) + "(" + Integer.toHexString(lcbPlcffldHdrTxbx).toUpperCase() + "), ";
        _s = _s + "fcStwUser: " + String.valueOf(fcStwUser) + "(" + Integer.toHexString(fcStwUser).toUpperCase() + "), ";
        _s = _s + "lcbStwUser: " + String.valueOf(lcbStwUser) + "(" + Integer.toHexString(lcbStwUser).toUpperCase() + "), ";
        _s = _s + "fcSttbTtmbd: " + String.valueOf(fcSttbTtmbd) + "(" + Integer.toHexString(fcSttbTtmbd).toUpperCase() + "), ";
        _s = _s + "lcbSttbTtmbd: " + String.valueOf(lcbSttbTtmbd) + "(" + Integer.toHexString(lcbSttbTtmbd).toUpperCase() + "), ";
        _s = _s + "fcCookieData: " + String.valueOf(fcCookieData) + "(" + Integer.toHexString(fcCookieData).toUpperCase() + "), ";
        _s = _s + "lcbCookieData: " + String.valueOf(lcbCookieData) + "(" + Integer.toHexString(lcbCookieData).toUpperCase() + "), ";
        _s = _s + "fcPgdMotherOldOld: " + String.valueOf(fcPgdMotherOldOld) + "(" + Integer.toHexString(fcPgdMotherOldOld).toUpperCase() + "), ";
        _s = _s + "lcbPgdMotherOldOld: " + String.valueOf(lcbPgdMotherOldOld) + "(" + Integer.toHexString(lcbPgdMotherOldOld).toUpperCase() + "), ";
        _s = _s + "fcBkdMotherOldOld: " + String.valueOf(fcBkdMotherOldOld) + "(" + Integer.toHexString(fcBkdMotherOldOld).toUpperCase() + "), ";
        _s = _s + "lcbBkdMotherOldOld: " + String.valueOf(lcbBkdMotherOldOld) + "(" + Integer.toHexString(lcbBkdMotherOldOld).toUpperCase() + "), ";
        _s = _s + "fcPgdFtnOldOld: " + String.valueOf(fcPgdFtnOldOld) + "(" + Integer.toHexString(fcPgdFtnOldOld).toUpperCase() + "), ";
        _s = _s + "lcbPgdFtnOldOld: " + String.valueOf(lcbPgdFtnOldOld) + "(" + Integer.toHexString(lcbPgdFtnOldOld).toUpperCase() + "), ";
        _s = _s + "fcBkdFtnOldOld: " + String.valueOf(fcBkdFtnOldOld) + "(" + Integer.toHexString(fcBkdFtnOldOld).toUpperCase() + "), ";
        _s = _s + "lcbBkdFtnOldOld: " + String.valueOf(lcbBkdFtnOldOld) + "(" + Integer.toHexString(lcbBkdFtnOldOld).toUpperCase() + "), ";
        _s = _s + "fcPgdEdnOldOld: " + String.valueOf(fcPgdEdnOldOld) + "(" + Integer.toHexString(fcPgdEdnOldOld).toUpperCase() + "), ";
        _s = _s + "lcbPgdEdnOldOld: " + String.valueOf(lcbPgdEdnOldOld) + "(" + Integer.toHexString(lcbPgdEdnOldOld).toUpperCase() + "), ";
        _s = _s + "fcBkdEdnOldOld: " + String.valueOf(fcBkdEdnOldOld) + "(" + Integer.toHexString(fcBkdEdnOldOld).toUpperCase() + "), ";
        _s = _s + "lcbBkdEdnOldOld: " + String.valueOf(lcbBkdEdnOldOld) + "(" + Integer.toHexString(lcbBkdEdnOldOld).toUpperCase() + "), ";
        _s = _s + "fcSttbfIntlFld: " + String.valueOf(fcSttbfIntlFld) + "(" + Integer.toHexString(fcSttbfIntlFld).toUpperCase() + "), ";
        _s = _s + "lcbSttbfIntlFld: " + String.valueOf(lcbSttbfIntlFld) + "(" + Integer.toHexString(lcbSttbfIntlFld).toUpperCase() + "), ";
        _s = _s + "fcRouteSlip: " + String.valueOf(fcRouteSlip) + "(" + Integer.toHexString(fcRouteSlip).toUpperCase() + "), ";
        _s = _s + "lcbRouteSlip: " + String.valueOf(lcbRouteSlip) + "(" + Integer.toHexString(lcbRouteSlip).toUpperCase() + "), ";
        _s = _s + "fcSttbSavedBy: " + String.valueOf(fcSttbSavedBy) + "(" + Integer.toHexString(fcSttbSavedBy).toUpperCase() + "), ";
        _s = _s + "lcbSttbSavedBy: " + String.valueOf(lcbSttbSavedBy) + "(" + Integer.toHexString(lcbSttbSavedBy).toUpperCase() + "), ";
        _s = _s + "fcSttbFnm: " + String.valueOf(fcSttbFnm) + "(" + Integer.toHexString(fcSttbFnm).toUpperCase() + "), ";
        _s = _s + "lcbSttbFnm: " + String.valueOf(lcbSttbFnm) + "(" + Integer.toHexString(lcbSttbFnm).toUpperCase() + "), ";
        _s = _s + "fcPlfLst: " + String.valueOf(fcPlfLst) + "(" + Integer.toHexString(fcPlfLst).toUpperCase() + "), ";
        _s = _s + "lcbPlfLst: " + String.valueOf(lcbPlfLst) + "(" + Integer.toHexString(lcbPlfLst).toUpperCase() + "), ";
        _s = _s + "fcPlfLfo: " + String.valueOf(fcPlfLfo) + "(" + Integer.toHexString(fcPlfLfo).toUpperCase() + "), ";
        _s = _s + "lcbPlfLfo: " + String.valueOf(lcbPlfLfo) + "(" + Integer.toHexString(lcbPlfLfo).toUpperCase() + "), ";
        _s = _s + "fcPlcfTxbxBkd: " + String.valueOf(fcPlcfTxbxBkd) + "(" + Integer.toHexString(fcPlcfTxbxBkd).toUpperCase() + "), ";
        _s = _s + "lcbPlcfTxbxBkd: " + String.valueOf(lcbPlcfTxbxBkd) + "(" + Integer.toHexString(lcbPlcfTxbxBkd).toUpperCase() + "), ";
        _s = _s + "fcPlcfTxbxHdrBkd: " + String.valueOf(fcPlcfTxbxHdrBkd) + "(" + Integer.toHexString(fcPlcfTxbxHdrBkd).toUpperCase() + "), ";
        _s = _s + "lcbPlcfTxbxHdrBkd: " + String.valueOf(lcbPlcfTxbxHdrBkd) + "(" + Integer.toHexString(lcbPlcfTxbxHdrBkd).toUpperCase() + "), ";
        _s = _s + "fcDocUndoWord9: " + String.valueOf(fcDocUndoWord9) + "(" + Integer.toHexString(fcDocUndoWord9).toUpperCase() + "), ";
        _s = _s + "lcbDocUndoWord9: " + String.valueOf(lcbDocUndoWord9) + "(" + Integer.toHexString(lcbDocUndoWord9).toUpperCase() + "), ";
        _s = _s + "fcRgbUse: " + String.valueOf(fcRgbUse) + "(" + Integer.toHexString(fcRgbUse).toUpperCase() + "), ";
        _s = _s + "lcbRgbUse: " + String.valueOf(lcbRgbUse) + "(" + Integer.toHexString(lcbRgbUse).toUpperCase() + "), ";
        _s = _s + "fcUsp: " + String.valueOf(fcUsp) + "(" + Integer.toHexString(fcUsp).toUpperCase() + "), ";
        _s = _s + "lcbUsp: " + String.valueOf(lcbUsp) + "(" + Integer.toHexString(lcbUsp).toUpperCase() + "), ";
        _s = _s + "fcUskf: " + String.valueOf(fcUskf) + "(" + Integer.toHexString(fcUskf).toUpperCase() + "), ";
        _s = _s + "lcbUskf: " + String.valueOf(lcbUskf) + "(" + Integer.toHexString(lcbUskf).toUpperCase() + "), ";
        _s = _s + "fcPlcupcRgbUse: " + String.valueOf(fcPlcupcRgbUse) + "(" + Integer.toHexString(fcPlcupcRgbUse).toUpperCase() + "), ";
        _s = _s + "lcbPlcupcRgbUse: " + String.valueOf(lcbPlcupcRgbUse) + "(" + Integer.toHexString(lcbPlcupcRgbUse).toUpperCase() + "), ";
        _s = _s + "fcPlcupcUsp: " + String.valueOf(fcPlcupcUsp) + "(" + Integer.toHexString(fcPlcupcUsp).toUpperCase() + "), ";
        _s = _s + "lcbPlcupcUsp: " + String.valueOf(lcbPlcupcUsp) + "(" + Integer.toHexString(lcbPlcupcUsp).toUpperCase() + "), ";
        _s = _s + "fcSttbGlsyStyle: " + String.valueOf(fcSttbGlsyStyle) + "(" + Integer.toHexString(fcSttbGlsyStyle).toUpperCase() + "), ";
        _s = _s + "lcbSttbGlsyStyle: " + String.valueOf(lcbSttbGlsyStyle) + "(" + Integer.toHexString(lcbSttbGlsyStyle).toUpperCase() + "), ";
        _s = _s + "fcPlgosl: " + String.valueOf(fcPlgosl) + "(" + Integer.toHexString(fcPlgosl).toUpperCase() + "), ";
        _s = _s + "lcbPlgosl: " + String.valueOf(lcbPlgosl) + "(" + Integer.toHexString(lcbPlgosl).toUpperCase() + "), ";
        _s = _s + "fcPlcocx: " + String.valueOf(fcPlcocx) + "(" + Integer.toHexString(fcPlcocx).toUpperCase() + "), ";
        _s = _s + "lcbPlcocx: " + String.valueOf(lcbPlcocx) + "(" + Integer.toHexString(lcbPlcocx).toUpperCase() + "), ";
        _s = _s + "fcPlcfBteLvc: " + String.valueOf(fcPlcfBteLvc) + "(" + Integer.toHexString(fcPlcfBteLvc).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBteLvc: " + String.valueOf(lcbPlcfBteLvc) + "(" + Integer.toHexString(lcbPlcfBteLvc).toUpperCase() + "), ";
        _s = _s + "dwLowDateTime: " + String.valueOf(dwLowDateTime) + "(" + Integer.toHexString(dwLowDateTime).toUpperCase() + "), ";
        _s = _s + "dwHighDateTime: " + String.valueOf(dwHighDateTime) + "(" + Integer.toHexString(dwHighDateTime).toUpperCase() + "), ";
        _s = _s + "fcPlcfLvcPre10: " + String.valueOf(fcPlcfLvcPre10) + "(" + Integer.toHexString(fcPlcfLvcPre10).toUpperCase() + "), ";
        _s = _s + "lcbPlcfLvcPre10: " + String.valueOf(lcbPlcfLvcPre10) + "(" + Integer.toHexString(lcbPlcfLvcPre10).toUpperCase() + "), ";
        _s = _s + "fcPlcfAsumy: " + String.valueOf(fcPlcfAsumy) + "(" + Integer.toHexString(fcPlcfAsumy).toUpperCase() + "), ";
        _s = _s + "lcbPlcfAsumy: " + String.valueOf(lcbPlcfAsumy) + "(" + Integer.toHexString(lcbPlcfAsumy).toUpperCase() + "), ";
        _s = _s + "fcPlcfGram: " + String.valueOf(fcPlcfGram) + "(" + Integer.toHexString(fcPlcfGram).toUpperCase() + "), ";
        _s = _s + "lcbPlcfGram: " + String.valueOf(lcbPlcfGram) + "(" + Integer.toHexString(lcbPlcfGram).toUpperCase() + "), ";
        _s = _s + "fcSttbListNames: " + String.valueOf(fcSttbListNames) + "(" + Integer.toHexString(fcSttbListNames).toUpperCase() + "), ";
        _s = _s + "lcbSttbListNames: " + String.valueOf(lcbSttbListNames) + "(" + Integer.toHexString(lcbSttbListNames).toUpperCase() + "), ";
        _s = _s + "fcSttbfUssr: " + String.valueOf(fcSttbfUssr) + "(" + Integer.toHexString(fcSttbfUssr).toUpperCase() + "), ";
        _s = _s + "lcbSttbfUssr: " + String.valueOf(lcbSttbfUssr) + "(" + Integer.toHexString(lcbSttbfUssr).toUpperCase() + "), ";
        return _s;
    }
}
class FibRgFcLcb2000 {
    int fcPlcfTch;
    int lcbPlcfTch;
    int fcRmdThreading;
    int lcbRmdThreading;
    int fcMid;
    int lcbMid;
    int fcSttbRgtplc;
    int lcbSttbRgtplc;
    int fcMsoEnvelope;
    int lcbMsoEnvelope;
    int fcPlcfLad;
    int lcbPlcfLad;
    int fcRgDofr;
    int lcbRgDofr;
    int fcPlcosl;
    int lcbPlcosl;
    int fcPlcfCookieOld;
    int lcbPlcfCookieOld;
    int fcPgdMotherOld;
    int lcbPgdMotherOld;
    int fcBkdMotherOld;
    int lcbBkdMotherOld;
    int fcPgdFtnOld;
    int lcbPgdFtnOld;
    int fcBkdFtnOld;
    int lcbBkdFtnOld;
    int fcPgdEdnOld;
    int lcbPgdEdnOld;
    int fcBkdEdnOld;
    int lcbBkdEdnOld;
    public String toString() {
        String _s = "FibRgFcLcb2000:";
        _s = _s + "fcPlcfTch: " + String.valueOf(fcPlcfTch) + "(" + Integer.toHexString(fcPlcfTch).toUpperCase() + "), ";
        _s = _s + "lcbPlcfTch: " + String.valueOf(lcbPlcfTch) + "(" + Integer.toHexString(lcbPlcfTch).toUpperCase() + "), ";
        _s = _s + "fcRmdThreading: " + String.valueOf(fcRmdThreading) + "(" + Integer.toHexString(fcRmdThreading).toUpperCase() + "), ";
        _s = _s + "lcbRmdThreading: " + String.valueOf(lcbRmdThreading) + "(" + Integer.toHexString(lcbRmdThreading).toUpperCase() + "), ";
        _s = _s + "fcMid: " + String.valueOf(fcMid) + "(" + Integer.toHexString(fcMid).toUpperCase() + "), ";
        _s = _s + "lcbMid: " + String.valueOf(lcbMid) + "(" + Integer.toHexString(lcbMid).toUpperCase() + "), ";
        _s = _s + "fcSttbRgtplc: " + String.valueOf(fcSttbRgtplc) + "(" + Integer.toHexString(fcSttbRgtplc).toUpperCase() + "), ";
        _s = _s + "lcbSttbRgtplc: " + String.valueOf(lcbSttbRgtplc) + "(" + Integer.toHexString(lcbSttbRgtplc).toUpperCase() + "), ";
        _s = _s + "fcMsoEnvelope: " + String.valueOf(fcMsoEnvelope) + "(" + Integer.toHexString(fcMsoEnvelope).toUpperCase() + "), ";
        _s = _s + "lcbMsoEnvelope: " + String.valueOf(lcbMsoEnvelope) + "(" + Integer.toHexString(lcbMsoEnvelope).toUpperCase() + "), ";
        _s = _s + "fcPlcfLad: " + String.valueOf(fcPlcfLad) + "(" + Integer.toHexString(fcPlcfLad).toUpperCase() + "), ";
        _s = _s + "lcbPlcfLad: " + String.valueOf(lcbPlcfLad) + "(" + Integer.toHexString(lcbPlcfLad).toUpperCase() + "), ";
        _s = _s + "fcRgDofr: " + String.valueOf(fcRgDofr) + "(" + Integer.toHexString(fcRgDofr).toUpperCase() + "), ";
        _s = _s + "lcbRgDofr: " + String.valueOf(lcbRgDofr) + "(" + Integer.toHexString(lcbRgDofr).toUpperCase() + "), ";
        _s = _s + "fcPlcosl: " + String.valueOf(fcPlcosl) + "(" + Integer.toHexString(fcPlcosl).toUpperCase() + "), ";
        _s = _s + "lcbPlcosl: " + String.valueOf(lcbPlcosl) + "(" + Integer.toHexString(lcbPlcosl).toUpperCase() + "), ";
        _s = _s + "fcPlcfCookieOld: " + String.valueOf(fcPlcfCookieOld) + "(" + Integer.toHexString(fcPlcfCookieOld).toUpperCase() + "), ";
        _s = _s + "lcbPlcfCookieOld: " + String.valueOf(lcbPlcfCookieOld) + "(" + Integer.toHexString(lcbPlcfCookieOld).toUpperCase() + "), ";
        _s = _s + "fcPgdMotherOld: " + String.valueOf(fcPgdMotherOld) + "(" + Integer.toHexString(fcPgdMotherOld).toUpperCase() + "), ";
        _s = _s + "lcbPgdMotherOld: " + String.valueOf(lcbPgdMotherOld) + "(" + Integer.toHexString(lcbPgdMotherOld).toUpperCase() + "), ";
        _s = _s + "fcBkdMotherOld: " + String.valueOf(fcBkdMotherOld) + "(" + Integer.toHexString(fcBkdMotherOld).toUpperCase() + "), ";
        _s = _s + "lcbBkdMotherOld: " + String.valueOf(lcbBkdMotherOld) + "(" + Integer.toHexString(lcbBkdMotherOld).toUpperCase() + "), ";
        _s = _s + "fcPgdFtnOld: " + String.valueOf(fcPgdFtnOld) + "(" + Integer.toHexString(fcPgdFtnOld).toUpperCase() + "), ";
        _s = _s + "lcbPgdFtnOld: " + String.valueOf(lcbPgdFtnOld) + "(" + Integer.toHexString(lcbPgdFtnOld).toUpperCase() + "), ";
        _s = _s + "fcBkdFtnOld: " + String.valueOf(fcBkdFtnOld) + "(" + Integer.toHexString(fcBkdFtnOld).toUpperCase() + "), ";
        _s = _s + "lcbBkdFtnOld: " + String.valueOf(lcbBkdFtnOld) + "(" + Integer.toHexString(lcbBkdFtnOld).toUpperCase() + "), ";
        _s = _s + "fcPgdEdnOld: " + String.valueOf(fcPgdEdnOld) + "(" + Integer.toHexString(fcPgdEdnOld).toUpperCase() + "), ";
        _s = _s + "lcbPgdEdnOld: " + String.valueOf(lcbPgdEdnOld) + "(" + Integer.toHexString(lcbPgdEdnOld).toUpperCase() + "), ";
        _s = _s + "fcBkdEdnOld: " + String.valueOf(fcBkdEdnOld) + "(" + Integer.toHexString(fcBkdEdnOld).toUpperCase() + "), ";
        _s = _s + "lcbBkdEdnOld: " + String.valueOf(lcbBkdEdnOld) + "(" + Integer.toHexString(lcbBkdEdnOld).toUpperCase() + "), ";
        return _s;
    }
}
class FibRgFcLcb2002 {
    int fcUnused1;
    int lcbUnused1;
    int fcPlcfPgp;
    int lcbPlcfPgp;
    int fcPlcfuim;
    int lcbPlcfuim;
    int fcPlfguidUim;
    int lcbPlfguidUim;
    int fcAtrdExtra;
    int lcbAtrdExtra;
    int fcPlrsid;
    int lcbPlrsid;
    int fcSttbfBkmkFactoid;
    int lcbSttbfBkmkFactoid;
    int fcPlcfBkfFactoid;
    int lcbPlcfBkfFactoid;
    int fcPlcfcookie;
    int lcbPlcfcookie;
    int fcPlcfBklFactoid;
    int lcbPlcfBklFactoid;
    int fcFactoidData;
    int lcbFactoidData;
    int fcDocUndo;
    int lcbDocUndo;
    int fcSttbfBkmkFcc;
    int lcbSttbfBkmkFcc;
    int fcPlcfBkfFcc;
    int lcbPlcfBkfFcc;
    int fcPlcfBklFcc;
    int lcbPlcfBklFcc;
    int fcSttbfbkmkBPRepairs;
    int lcbSttbfbkmkBPRepairs;
    int fcPlcfbkfBPRepairs;
    int lcbPlcfbkfBPRepairs;
    int fcPlcfbklBPRepairs;
    int lcbPlcfbklBPRepairs;
    int fcPmsNew;
    int lcbPmsNew;
    int fcODSO;
    int lcbODSO;
    int fcPlcfpmiOldXP;
    int lcbPlcfpmiOldXP;
    int fcPlcfpmiNewXP;
    int lcbPlcfpmiNewXP;
    int fcPlcfpmiMixedXP;
    int lcbPlcfpmiMixedXP;
    int fcUnused2;
    int lcbUnused2;
    int fcPlcffactoid;
    int lcbPlcffactoid;
    public String toString() {
        String _s = "FibRgFcLcb2002:";
        _s = _s + "fcUnused1: " + String.valueOf(fcUnused1) + "(" + Integer.toHexString(fcUnused1).toUpperCase() + "), ";
        _s = _s + "lcbUnused1: " + String.valueOf(lcbUnused1) + "(" + Integer.toHexString(lcbUnused1).toUpperCase() + "), ";
        _s = _s + "fcPlcfPgp: " + String.valueOf(fcPlcfPgp) + "(" + Integer.toHexString(fcPlcfPgp).toUpperCase() + "), ";
        _s = _s + "lcbPlcfPgp: " + String.valueOf(lcbPlcfPgp) + "(" + Integer.toHexString(lcbPlcfPgp).toUpperCase() + "), ";
        _s = _s + "fcPlcfuim: " + String.valueOf(fcPlcfuim) + "(" + Integer.toHexString(fcPlcfuim).toUpperCase() + "), ";
        _s = _s + "lcbPlcfuim: " + String.valueOf(lcbPlcfuim) + "(" + Integer.toHexString(lcbPlcfuim).toUpperCase() + "), ";
        _s = _s + "fcPlfguidUim: " + String.valueOf(fcPlfguidUim) + "(" + Integer.toHexString(fcPlfguidUim).toUpperCase() + "), ";
        _s = _s + "lcbPlfguidUim: " + String.valueOf(lcbPlfguidUim) + "(" + Integer.toHexString(lcbPlfguidUim).toUpperCase() + "), ";
        _s = _s + "fcAtrdExtra: " + String.valueOf(fcAtrdExtra) + "(" + Integer.toHexString(fcAtrdExtra).toUpperCase() + "), ";
        _s = _s + "lcbAtrdExtra: " + String.valueOf(lcbAtrdExtra) + "(" + Integer.toHexString(lcbAtrdExtra).toUpperCase() + "), ";
        _s = _s + "fcPlrsid: " + String.valueOf(fcPlrsid) + "(" + Integer.toHexString(fcPlrsid).toUpperCase() + "), ";
        _s = _s + "lcbPlrsid: " + String.valueOf(lcbPlrsid) + "(" + Integer.toHexString(lcbPlrsid).toUpperCase() + "), ";
        _s = _s + "fcSttbfBkmkFactoid: " + String.valueOf(fcSttbfBkmkFactoid) + "(" + Integer.toHexString(fcSttbfBkmkFactoid).toUpperCase() + "), ";
        _s = _s + "lcbSttbfBkmkFactoid: " + String.valueOf(lcbSttbfBkmkFactoid) + "(" + Integer.toHexString(lcbSttbfBkmkFactoid).toUpperCase() + "), ";
        _s = _s + "fcPlcfBkfFactoid: " + String.valueOf(fcPlcfBkfFactoid) + "(" + Integer.toHexString(fcPlcfBkfFactoid).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBkfFactoid: " + String.valueOf(lcbPlcfBkfFactoid) + "(" + Integer.toHexString(lcbPlcfBkfFactoid).toUpperCase() + "), ";
        _s = _s + "fcPlcfcookie: " + String.valueOf(fcPlcfcookie) + "(" + Integer.toHexString(fcPlcfcookie).toUpperCase() + "), ";
        _s = _s + "lcbPlcfcookie: " + String.valueOf(lcbPlcfcookie) + "(" + Integer.toHexString(lcbPlcfcookie).toUpperCase() + "), ";
        _s = _s + "fcPlcfBklFactoid: " + String.valueOf(fcPlcfBklFactoid) + "(" + Integer.toHexString(fcPlcfBklFactoid).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBklFactoid: " + String.valueOf(lcbPlcfBklFactoid) + "(" + Integer.toHexString(lcbPlcfBklFactoid).toUpperCase() + "), ";
        _s = _s + "fcFactoidData: " + String.valueOf(fcFactoidData) + "(" + Integer.toHexString(fcFactoidData).toUpperCase() + "), ";
        _s = _s + "lcbFactoidData: " + String.valueOf(lcbFactoidData) + "(" + Integer.toHexString(lcbFactoidData).toUpperCase() + "), ";
        _s = _s + "fcDocUndo: " + String.valueOf(fcDocUndo) + "(" + Integer.toHexString(fcDocUndo).toUpperCase() + "), ";
        _s = _s + "lcbDocUndo: " + String.valueOf(lcbDocUndo) + "(" + Integer.toHexString(lcbDocUndo).toUpperCase() + "), ";
        _s = _s + "fcSttbfBkmkFcc: " + String.valueOf(fcSttbfBkmkFcc) + "(" + Integer.toHexString(fcSttbfBkmkFcc).toUpperCase() + "), ";
        _s = _s + "lcbSttbfBkmkFcc: " + String.valueOf(lcbSttbfBkmkFcc) + "(" + Integer.toHexString(lcbSttbfBkmkFcc).toUpperCase() + "), ";
        _s = _s + "fcPlcfBkfFcc: " + String.valueOf(fcPlcfBkfFcc) + "(" + Integer.toHexString(fcPlcfBkfFcc).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBkfFcc: " + String.valueOf(lcbPlcfBkfFcc) + "(" + Integer.toHexString(lcbPlcfBkfFcc).toUpperCase() + "), ";
        _s = _s + "fcPlcfBklFcc: " + String.valueOf(fcPlcfBklFcc) + "(" + Integer.toHexString(fcPlcfBklFcc).toUpperCase() + "), ";
        _s = _s + "lcbPlcfBklFcc: " + String.valueOf(lcbPlcfBklFcc) + "(" + Integer.toHexString(lcbPlcfBklFcc).toUpperCase() + "), ";
        _s = _s + "fcSttbfbkmkBPRepairs: " + String.valueOf(fcSttbfbkmkBPRepairs) + "(" + Integer.toHexString(fcSttbfbkmkBPRepairs).toUpperCase() + "), ";
        _s = _s + "lcbSttbfbkmkBPRepairs: " + String.valueOf(lcbSttbfbkmkBPRepairs) + "(" + Integer.toHexString(lcbSttbfbkmkBPRepairs).toUpperCase() + "), ";
        _s = _s + "fcPlcfbkfBPRepairs: " + String.valueOf(fcPlcfbkfBPRepairs) + "(" + Integer.toHexString(fcPlcfbkfBPRepairs).toUpperCase() + "), ";
        _s = _s + "lcbPlcfbkfBPRepairs: " + String.valueOf(lcbPlcfbkfBPRepairs) + "(" + Integer.toHexString(lcbPlcfbkfBPRepairs).toUpperCase() + "), ";
        _s = _s + "fcPlcfbklBPRepairs: " + String.valueOf(fcPlcfbklBPRepairs) + "(" + Integer.toHexString(fcPlcfbklBPRepairs).toUpperCase() + "), ";
        _s = _s + "lcbPlcfbklBPRepairs: " + String.valueOf(lcbPlcfbklBPRepairs) + "(" + Integer.toHexString(lcbPlcfbklBPRepairs).toUpperCase() + "), ";
        _s = _s + "fcPmsNew: " + String.valueOf(fcPmsNew) + "(" + Integer.toHexString(fcPmsNew).toUpperCase() + "), ";
        _s = _s + "lcbPmsNew: " + String.valueOf(lcbPmsNew) + "(" + Integer.toHexString(lcbPmsNew).toUpperCase() + "), ";
        _s = _s + "fcODSO: " + String.valueOf(fcODSO) + "(" + Integer.toHexString(fcODSO).toUpperCase() + "), ";
        _s = _s + "lcbODSO: " + String.valueOf(lcbODSO) + "(" + Integer.toHexString(lcbODSO).toUpperCase() + "), ";
        _s = _s + "fcPlcfpmiOldXP: " + String.valueOf(fcPlcfpmiOldXP) + "(" + Integer.toHexString(fcPlcfpmiOldXP).toUpperCase() + "), ";
        _s = _s + "lcbPlcfpmiOldXP: " + String.valueOf(lcbPlcfpmiOldXP) + "(" + Integer.toHexString(lcbPlcfpmiOldXP).toUpperCase() + "), ";
        _s = _s + "fcPlcfpmiNewXP: " + String.valueOf(fcPlcfpmiNewXP) + "(" + Integer.toHexString(fcPlcfpmiNewXP).toUpperCase() + "), ";
        _s = _s + "lcbPlcfpmiNewXP: " + String.valueOf(lcbPlcfpmiNewXP) + "(" + Integer.toHexString(lcbPlcfpmiNewXP).toUpperCase() + "), ";
        _s = _s + "fcPlcfpmiMixedXP: " + String.valueOf(fcPlcfpmiMixedXP) + "(" + Integer.toHexString(fcPlcfpmiMixedXP).toUpperCase() + "), ";
        _s = _s + "lcbPlcfpmiMixedXP: " + String.valueOf(lcbPlcfpmiMixedXP) + "(" + Integer.toHexString(lcbPlcfpmiMixedXP).toUpperCase() + "), ";
        _s = _s + "fcUnused2: " + String.valueOf(fcUnused2) + "(" + Integer.toHexString(fcUnused2).toUpperCase() + "), ";
        _s = _s + "lcbUnused2: " + String.valueOf(lcbUnused2) + "(" + Integer.toHexString(lcbUnused2).toUpperCase() + "), ";
        _s = _s + "fcPlcffactoid: " + String.valueOf(fcPlcffactoid) + "(" + Integer.toHexString(fcPlcffactoid).toUpperCase() + "), ";
        _s = _s + "lcbPlcffactoid: " + String.valueOf(lcbPlcffactoid) + "(" + Integer.toHexString(lcbPlcffactoid).toUpperCase() + "), ";
        return _s;
    }
}
class LPStshi {
    int cbSthi;
    byte[] stshi;
    public String toString() {
        String _s = "LPStshi:";
        _s = _s + "cbSthi: " + String.valueOf(cbSthi) + "(" + Integer.toHexString(cbSthi).toUpperCase() + "), ";
        _s = _s + "stshi: " + String.valueOf(stshi) + ", ";
        return _s;
    }
}
class LPStd {
    int cbStd;
    byte[] std;
    byte padding;
    public String toString() {
        String _s = "LPStd:";
        _s = _s + "cbStd: " + String.valueOf(cbStd) + "(" + Integer.toHexString(cbStd).toUpperCase() + "), ";
        _s = _s + "std: " + String.valueOf(std) + ", ";
        _s = _s + "padding: " + String.valueOf(padding) + "(" + Integer.toHexString(padding).toUpperCase() + "), ";
        return _s;
    }
}
class PlcfSed {
    int[] aCP;
    Sed[] aSed;
    public String toString() {
        String _s = "PlcfSed:";
        _s = _s + "aCP: " + String.valueOf(aCP) + ", ";
        _s = _s + "aSed: " + String.valueOf(aSed) + ", ";
        return _s;
    }
}
class Sed {
    int fn;
    int fcSepx;
    int fnMpr;
    int fcMpr;
    public String toString() {
        String _s = "Sed:";
        _s = _s + "fn: " + String.valueOf(fn) + "(" + Integer.toHexString(fn).toUpperCase() + "), ";
        _s = _s + "fcSepx: " + String.valueOf(fcSepx) + "(" + Integer.toHexString(fcSepx).toUpperCase() + "), ";
        _s = _s + "fnMpr: " + String.valueOf(fnMpr) + "(" + Integer.toHexString(fnMpr).toUpperCase() + "), ";
        _s = _s + "fcMpr: " + String.valueOf(fcMpr) + "(" + Integer.toHexString(fcMpr).toUpperCase() + "), ";
        return _s;
    }
}
class Plcfhdd {
    int[] aCP;
    public String toString() {
        String _s = "Plcfhdd:";
        _s = _s + "aCP: " + String.valueOf(aCP) + ", ";
        return _s;
    }
}
class PlcBteChpx {
    int[] aCP;
    int[] aPnBteChpx;
    public String toString() {
        String _s = "PlcBteChpx:";
        _s = _s + "aCP: " + String.valueOf(aCP) + ", ";
        _s = _s + "aPnBteChpx: " + String.valueOf(aPnBteChpx) + ", ";
        return _s;
    }
}
class PlcfBtePapx {
    int[] aCP;
    int[] aPnBteChpx;
    public String toString() {
        String _s = "PlcfBtePapx:";
        _s = _s + "aCP: " + String.valueOf(aCP) + ", ";
        _s = _s + "aPnBteChpx: " + String.valueOf(aPnBteChpx) + ", ";
        return _s;
    }
}
class Tcg {
    byte nTcgVer;
    byte[] todo;
    public String toString() {
        String _s = "Tcg:";
        _s = _s + "nTcgVer: " + String.valueOf(nTcgVer) + "(" + Integer.toHexString(nTcgVer).toUpperCase() + "), ";
        _s = _s + "todo: " + String.valueOf(todo) + ", ";
        return _s;
    }
}
class PrcData {
    short cbGrpprl;
    Sprm[] GrpPrl;
    public String toString() {
        String _s = "PrcData:";
        _s = _s + "cbGrpprl: " + String.valueOf(cbGrpprl) + "(" + Integer.toHexString(cbGrpprl).toUpperCase() + "), ";
        _s = _s + "GrpPrl: " + String.valueOf(GrpPrl) + ", ";
        return _s;
    }
}
class Sprm {
    short ispmd;
    boolean fSpec;
    byte sgc;
    byte spra;
    public String toString() {
        String _s = "Sprm:";
        _s = _s + "ispmd: " + String.valueOf(ispmd) + "(" + Integer.toHexString(ispmd).toUpperCase() + "), ";
        _s = _s + "fSpec: " + String.valueOf(fSpec) + ", ";
        _s = _s + "sgc: " + String.valueOf(sgc) + "(" + Integer.toHexString(sgc).toUpperCase() + "), ";
        _s = _s + "spra: " + String.valueOf(spra) + "(" + Integer.toHexString(spra).toUpperCase() + "), ";
        return _s;
    }
}
class Pcdt {
    byte clxt;
    int lcb;
    Pcd[] PlcPcd;
    public String toString() {
        String _s = "Pcdt:";
        _s = _s + "clxt: " + String.valueOf(clxt) + "(" + Integer.toHexString(clxt).toUpperCase() + "), ";
        _s = _s + "lcb: " + String.valueOf(lcb) + "(" + Integer.toHexString(lcb).toUpperCase() + "), ";
        _s = _s + "PlcPcd: " + String.valueOf(PlcPcd) + ", ";
        return _s;
    }
}
class FCompressed {
    int fc;
    boolean fCompressed;
    boolean r1;
    public String toString() {
        String _s = "FCompressed:";
        _s = _s + "fc: " + String.valueOf(fc) + "(" + Integer.toHexString(fc).toUpperCase() + "), ";
        _s = _s + "fCompressed: " + String.valueOf(fCompressed) + ", ";
        _s = _s + "r1: " + String.valueOf(r1) + ", ";
        return _s;
    }
}
class Prm0 {
    boolean fComplex;
    byte isprm;
    byte val;
    public String toString() {
        String _s = "Prm0:";
        _s = _s + "fComplex: " + String.valueOf(fComplex) + ", ";
        _s = _s + "isprm: " + String.valueOf(isprm) + "(" + Integer.toHexString(isprm).toUpperCase() + "), ";
        _s = _s + "val: " + String.valueOf(val) + "(" + Integer.toHexString(val).toUpperCase() + "), ";
        return _s;
    }
}
class Prm1 {
    boolean fComplex;
    short igrpprl;
    public String toString() {
        String _s = "Prm1:";
        _s = _s + "fComplex: " + String.valueOf(fComplex) + ", ";
        _s = _s + "igrpprl: " + String.valueOf(igrpprl) + "(" + Integer.toHexString(igrpprl).toUpperCase() + "), ";
        return _s;
    }
}
class SttbfFfn {
    int cData;
    int cbExtra;
    SttbfFfnEntry[] data;
    public String toString() {
        String _s = "SttbfFfn:";
        _s = _s + "cData: " + String.valueOf(cData) + "(" + Integer.toHexString(cData).toUpperCase() + "), ";
        _s = _s + "cbExtra: " + String.valueOf(cbExtra) + "(" + Integer.toHexString(cbExtra).toUpperCase() + "), ";
        _s = _s + "data: " + String.valueOf(data) + ", ";
        return _s;
    }
}
class SttbfFfnEntry {
    byte cchData;
    byte[] Data;
    public String toString() {
        String _s = "SttbfFfnEntry:";
        _s = _s + "cchData: " + String.valueOf(cchData) + "(" + Integer.toHexString(cchData).toUpperCase() + "), ";
        _s = _s + "Data: " + String.valueOf(Data) + ", ";
        return _s;
    }
}
class CodePageString {
    int size;
    byte[] characters;
    public String toString() {
        String _s = "CodePageString:";
        _s = _s + "size: " + String.valueOf(size) + "(" + Integer.toHexString(size).toUpperCase() + "), ";
        _s = _s + "characters: " + String.valueOf(characters) + ", ";
        return _s;
    }
}
class FILETIME {
    int dwLowDateTime;
    int dwHighDateTime;
    public String toString() {
        String _s = "FILETIME:";
        _s = _s + "dwLowDateTime: " + String.valueOf(dwLowDateTime) + "(" + Integer.toHexString(dwLowDateTime).toUpperCase() + "), ";
        _s = _s + "dwHighDateTime: " + String.valueOf(dwHighDateTime) + "(" + Integer.toHexString(dwHighDateTime).toUpperCase() + "), ";
        return _s;
    }
}
class ClipboardData {
    int size;
    int format;
    byte[] data;
    public String toString() {
        String _s = "ClipboardData:";
        _s = _s + "size: " + String.valueOf(size) + "(" + Integer.toHexString(size).toUpperCase() + "), ";
        _s = _s + "format: " + String.valueOf(format) + "(" + Integer.toHexString(format).toUpperCase() + "), ";
        _s = _s + "data: " + String.valueOf(data) + ", ";
        return _s;
    }
}
class PropertyIdentifierAndOffset {
    int propertyIdentifier;
    int offset;
    public String toString() {
        String _s = "PropertyIdentifierAndOffset:";
        _s = _s + "propertyIdentifier: " + String.valueOf(propertyIdentifier) + "(" + Integer.toHexString(propertyIdentifier).toUpperCase() + "), ";
        _s = _s + "offset: " + String.valueOf(offset) + "(" + Integer.toHexString(offset).toUpperCase() + "), ";
        return _s;
    }
}
class TypedPropertyValue {
    int type;
    int padding;
    int vt_I2;
    int paddingI2;
    int vg_ERROR;
    CodePageString vt_lpstr;
    FILETIME vg_FILETIME;
    ClipboardData vg_CF;
    public String toString() {
        String _s = "TypedPropertyValue:";
        _s = _s + "type: " + String.valueOf(type) + "(" + Integer.toHexString(type).toUpperCase() + "), ";
        _s = _s + "padding: " + String.valueOf(padding) + "(" + Integer.toHexString(padding).toUpperCase() + "), ";
        _s = _s + "vt_I2: " + String.valueOf(vt_I2) + "(" + Integer.toHexString(vt_I2).toUpperCase() + "), ";
        _s = _s + "paddingI2: " + String.valueOf(paddingI2) + "(" + Integer.toHexString(paddingI2).toUpperCase() + "), ";
        _s = _s + "vg_ERROR: " + String.valueOf(vg_ERROR) + "(" + Integer.toHexString(vg_ERROR).toUpperCase() + "), ";
        _s = _s + "vt_lpstr: " + String.valueOf(vt_lpstr) + ", ";
        _s = _s + "vg_FILETIME: " + String.valueOf(vg_FILETIME) + ", ";
        _s = _s + "vg_CF: " + String.valueOf(vg_CF) + ", ";
        return _s;
    }
}
class PropertySet {
    int size;
    int numProperties;
    PropertyIdentifierAndOffset[] propertyIdentifierAndOffset;
    TypedPropertyValue[] property;
    public String toString() {
        String _s = "PropertySet:";
        _s = _s + "size: " + String.valueOf(size) + "(" + Integer.toHexString(size).toUpperCase() + "), ";
        _s = _s + "numProperties: " + String.valueOf(numProperties) + "(" + Integer.toHexString(numProperties).toUpperCase() + "), ";
        _s = _s + "propertyIdentifierAndOffset: " + String.valueOf(propertyIdentifierAndOffset) + ", ";
        _s = _s + "property: " + String.valueOf(property) + ", ";
        return _s;
    }
}
class PropertySetStream {
    int byteOrder;
    int version;
    int systemIdentifier;
    byte[] clsID;
    int numPropertySets;
    byte[] fmtID0;
    int offset0;
    byte[] fmtID1;
    int offset1;
    PropertySet propertySet1;
    PropertySet propertySet2;
    final java.util.List<Byte> padding = new java.util.ArrayList<Byte>();
    public String toString() {
        String _s = "PropertySetStream:";
        _s = _s + "byteOrder: " + String.valueOf(byteOrder) + "(" + Integer.toHexString(byteOrder).toUpperCase() + "), ";
        _s = _s + "version: " + String.valueOf(version) + "(" + Integer.toHexString(version).toUpperCase() + "), ";
        _s = _s + "systemIdentifier: " + String.valueOf(systemIdentifier) + "(" + Integer.toHexString(systemIdentifier).toUpperCase() + "), ";
        _s = _s + "clsID: " + String.valueOf(clsID) + ", ";
        _s = _s + "numPropertySets: " + String.valueOf(numPropertySets) + "(" + Integer.toHexString(numPropertySets).toUpperCase() + "), ";
        _s = _s + "fmtID0: " + String.valueOf(fmtID0) + ", ";
        _s = _s + "offset0: " + String.valueOf(offset0) + "(" + Integer.toHexString(offset0).toUpperCase() + "), ";
        _s = _s + "fmtID1: " + String.valueOf(fmtID1) + ", ";
        _s = _s + "offset1: " + String.valueOf(offset1) + "(" + Integer.toHexString(offset1).toUpperCase() + "), ";
        _s = _s + "propertySet1: " + String.valueOf(propertySet1) + ", ";
        _s = _s + "propertySet2: " + String.valueOf(propertySet2) + ", ";
        _s = _s + "padding: " + String.valueOf(padding) + ", ";
        return _s;
    }
}
class SummaryInformationPropertySetStream {
    PropertySetStream propertySet;
    public String toString() {
        String _s = "SummaryInformationPropertySetStream:";
        _s = _s + "propertySet: " + String.valueOf(propertySet) + ", ";
        return _s;
    }
}
class DocumentSummaryInformationPropertySetStream {
    PropertySetStream propertySet;
    public String toString() {
        String _s = "DocumentSummaryInformationPropertySetStream:";
        _s = _s + "propertySet: " + String.valueOf(propertySet) + ", ";
        return _s;
    }
}
class PicturesStream {
    OfficeArtBStoreDelay anon1;
    public String toString() {
        String _s = "PicturesStream:";
        _s = _s + "anon1: " + String.valueOf(anon1) + ", ";
        return _s;
    }
}
class OfficeArtMetafileHeader {
    int cbSize;
    RECT rcBounds;
    POINT ptSize;
    int cbsave;
    byte compression;
    byte filter;
    public String toString() {
        String _s = "OfficeArtMetafileHeader:";
        _s = _s + "cbSize: " + String.valueOf(cbSize) + "(" + Integer.toHexString(cbSize).toUpperCase() + "), ";
        _s = _s + "rcBounds: " + String.valueOf(rcBounds) + ", ";
        _s = _s + "ptSize: " + String.valueOf(ptSize) + ", ";
        _s = _s + "cbsave: " + String.valueOf(cbsave) + "(" + Integer.toHexString(cbsave).toUpperCase() + "), ";
        _s = _s + "compression: " + String.valueOf(compression) + "(" + Integer.toHexString(compression).toUpperCase() + "), ";
        _s = _s + "filter: " + String.valueOf(filter) + "(" + Integer.toHexString(filter).toUpperCase() + "), ";
        return _s;
    }
}
class ScalingStruct {
    RatioStruct x;
    RatioStruct y;
    public String toString() {
        String _s = "ScalingStruct:";
        _s = _s + "x: " + String.valueOf(x) + ", ";
        _s = _s + "y: " + String.valueOf(y) + ", ";
        return _s;
    }
}
class NoZoomViewInfoAtom {
    RecordHeader rh;
    ScalingStruct curScale;
    byte[] unused1;
    PointStruct origin;
    byte unused2;
    byte fDraftMode;
    int unused3;
    public String toString() {
        String _s = "NoZoomViewInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "curScale: " + String.valueOf(curScale) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "origin: " + String.valueOf(origin) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        _s = _s + "fDraftMode: " + String.valueOf(fDraftMode) + "(" + Integer.toHexString(fDraftMode).toUpperCase() + "), ";
        _s = _s + "unused3: " + String.valueOf(unused3) + "(" + Integer.toHexString(unused3).toUpperCase() + "), ";
        return _s;
    }
}
class VBAInfoContainer {
    RecordHeader rh;
    VBAInfoAtom vbaInfoAtom;
    public String toString() {
        String _s = "VBAInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "vbaInfoAtom: " + String.valueOf(vbaInfoAtom) + ", ";
        return _s;
    }
}
class NormalViewSetInfoAtom {
    RecordHeader rh;
    RatioStruct leftPortion;
    RatioStruct topPortion;
    byte vertBarState;
    byte horizBarState;
    byte fPreferSingleSet;
    boolean fHideThumbnails;
    boolean fBarSnapped;
    byte reserved;
    public String toString() {
        String _s = "NormalViewSetInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "leftPortion: " + String.valueOf(leftPortion) + ", ";
        _s = _s + "topPortion: " + String.valueOf(topPortion) + ", ";
        _s = _s + "vertBarState: " + String.valueOf(vertBarState) + "(" + Integer.toHexString(vertBarState).toUpperCase() + "), ";
        _s = _s + "horizBarState: " + String.valueOf(horizBarState) + "(" + Integer.toHexString(horizBarState).toUpperCase() + "), ";
        _s = _s + "fPreferSingleSet: " + String.valueOf(fPreferSingleSet) + "(" + Integer.toHexString(fPreferSingleSet).toUpperCase() + "), ";
        _s = _s + "fHideThumbnails: " + String.valueOf(fHideThumbnails) + ", ";
        _s = _s + "fBarSnapped: " + String.valueOf(fBarSnapped) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + "(" + Integer.toHexString(reserved).toUpperCase() + "), ";
        return _s;
    }
}
class MasterPersistAtom {
    RecordHeader rh;
    PersistIdRef persistIdRef;
    byte reserved1;
    boolean fNonOutLineData;
    byte reserved2;
    byte reserved3;
    int reserved4;
    int reserved5;
    int masterId;
    int reserved6;
    public String toString() {
        String _s = "MasterPersistAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "persistIdRef: " + String.valueOf(persistIdRef) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + "(" + Integer.toHexString(reserved1).toUpperCase() + "), ";
        _s = _s + "fNonOutLineData: " + String.valueOf(fNonOutLineData) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + "(" + Integer.toHexString(reserved2).toUpperCase() + "), ";
        _s = _s + "reserved3: " + String.valueOf(reserved3) + "(" + Integer.toHexString(reserved3).toUpperCase() + "), ";
        _s = _s + "reserved4: " + String.valueOf(reserved4) + "(" + Integer.toHexString(reserved4).toUpperCase() + "), ";
        _s = _s + "reserved5: " + String.valueOf(reserved5) + "(" + Integer.toHexString(reserved5).toUpperCase() + "), ";
        _s = _s + "masterId: " + String.valueOf(masterId) + "(" + Integer.toHexString(masterId).toUpperCase() + "), ";
        _s = _s + "reserved6: " + String.valueOf(reserved6) + "(" + Integer.toHexString(reserved6).toUpperCase() + "), ";
        return _s;
    }
}
class TextContainer {
    TextHeaderAtom textHeaderAtom;
    Object text;
    StyleTextPropAtom style;
    final java.util.List<TextContainerMeta> meta = new java.util.ArrayList<TextContainerMeta>();
    MasterTextPropAtom master;
    final java.util.List<TextBookmarkAtom> bookmark = new java.util.ArrayList<TextBookmarkAtom>();
    TextSpecialInfoAtom specialinfo;
    final java.util.List<TextContainerInteractiveInfo> interactive = new java.util.ArrayList<TextContainerInteractiveInfo>();
    public String toString() {
        String _s = "TextContainer:";
        _s = _s + "textHeaderAtom: " + String.valueOf(textHeaderAtom) + ", ";
        _s = _s + "text: " + String.valueOf(text) + ", ";
        _s = _s + "style: " + String.valueOf(style) + ", ";
        _s = _s + "meta: " + String.valueOf(meta) + ", ";
        _s = _s + "master: " + String.valueOf(master) + ", ";
        _s = _s + "bookmark: " + String.valueOf(bookmark) + ", ";
        _s = _s + "specialinfo: " + String.valueOf(specialinfo) + ", ";
        _s = _s + "interactive: " + String.valueOf(interactive) + ", ";
        return _s;
    }
}
class TextContainerMeta {
    Object meta;
    public String toString() {
        String _s = "TextContainerMeta:";
        _s = _s + "meta: " + String.valueOf(meta) + ", ";
        return _s;
    }
}
class TextClientDataSubContainerOrAtom {
    Object anon;
    public String toString() {
        String _s = "TextClientDataSubContainerOrAtom:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class SlidePersistAtom {
    RecordHeader rh;
    PersistIdRef persistIdRef;
    boolean reserved1;
    boolean fShouldCollapse;
    boolean fNonOutlineData;
    byte reserved2;
    byte reserved3;
    int reserved4;
    int cTexts;
    SlideId slideId;
    int reserved5;
    public String toString() {
        String _s = "SlidePersistAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "persistIdRef: " + String.valueOf(persistIdRef) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "fShouldCollapse: " + String.valueOf(fShouldCollapse) + ", ";
        _s = _s + "fNonOutlineData: " + String.valueOf(fNonOutlineData) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + "(" + Integer.toHexString(reserved2).toUpperCase() + "), ";
        _s = _s + "reserved3: " + String.valueOf(reserved3) + "(" + Integer.toHexString(reserved3).toUpperCase() + "), ";
        _s = _s + "reserved4: " + String.valueOf(reserved4) + "(" + Integer.toHexString(reserved4).toUpperCase() + "), ";
        _s = _s + "cTexts: " + String.valueOf(cTexts) + "(" + Integer.toHexString(cTexts).toUpperCase() + "), ";
        _s = _s + "slideId: " + String.valueOf(slideId) + ", ";
        _s = _s + "reserved5: " + String.valueOf(reserved5) + "(" + Integer.toHexString(reserved5).toUpperCase() + "), ";
        return _s;
    }
}
class TextRuler {
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
        _s = _s + "reserved1: " + String.valueOf(reserved1) + "(" + Integer.toHexString(reserved1).toUpperCase() + "), ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + "(" + Integer.toHexString(reserved2).toUpperCase() + "), ";
        _s = _s + "cLevels: " + String.valueOf(cLevels) + "(" + Integer.toHexString(cLevels).toUpperCase() + "), ";
        _s = _s + "defaultTabSize: " + String.valueOf(defaultTabSize) + "(" + Integer.toHexString(defaultTabSize).toUpperCase() + "), ";
        _s = _s + "tabs: " + String.valueOf(tabs) + ", ";
        _s = _s + "leftMargin1: " + String.valueOf(leftMargin1) + "(" + Integer.toHexString(leftMargin1).toUpperCase() + "), ";
        _s = _s + "indent1: " + String.valueOf(indent1) + "(" + Integer.toHexString(indent1).toUpperCase() + "), ";
        _s = _s + "leftMargin2: " + String.valueOf(leftMargin2) + "(" + Integer.toHexString(leftMargin2).toUpperCase() + "), ";
        _s = _s + "indent2: " + String.valueOf(indent2) + "(" + Integer.toHexString(indent2).toUpperCase() + "), ";
        _s = _s + "leftMargin3: " + String.valueOf(leftMargin3) + "(" + Integer.toHexString(leftMargin3).toUpperCase() + "), ";
        _s = _s + "indent3: " + String.valueOf(indent3) + "(" + Integer.toHexString(indent3).toUpperCase() + "), ";
        _s = _s + "leftMargin4: " + String.valueOf(leftMargin4) + "(" + Integer.toHexString(leftMargin4).toUpperCase() + "), ";
        _s = _s + "indent4: " + String.valueOf(indent4) + "(" + Integer.toHexString(indent4).toUpperCase() + "), ";
        _s = _s + "leftMargin5: " + String.valueOf(leftMargin5) + "(" + Integer.toHexString(leftMargin5).toUpperCase() + "), ";
        _s = _s + "indent5: " + String.valueOf(indent5) + "(" + Integer.toHexString(indent5).toUpperCase() + "), ";
        return _s;
    }
}
class TextPFException {
    PFMasks masks;
    BulletFlags bulletFlags;
    short bulletChar;
    int bulletFontRef;
    int bulletSize;
    ColorIndexStruct bulletColor;
    int textAlignment;
    short lineSpacing;
    short spaceBefore;
    short spaceAfter;
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
        _s = _s + "bulletChar: " + String.valueOf(bulletChar) + "(" + Integer.toHexString(bulletChar).toUpperCase() + "), ";
        _s = _s + "bulletFontRef: " + String.valueOf(bulletFontRef) + "(" + Integer.toHexString(bulletFontRef).toUpperCase() + "), ";
        _s = _s + "bulletSize: " + String.valueOf(bulletSize) + "(" + Integer.toHexString(bulletSize).toUpperCase() + "), ";
        _s = _s + "bulletColor: " + String.valueOf(bulletColor) + ", ";
        _s = _s + "textAlignment: " + String.valueOf(textAlignment) + "(" + Integer.toHexString(textAlignment).toUpperCase() + "), ";
        _s = _s + "lineSpacing: " + String.valueOf(lineSpacing) + "(" + Integer.toHexString(lineSpacing).toUpperCase() + "), ";
        _s = _s + "spaceBefore: " + String.valueOf(spaceBefore) + "(" + Integer.toHexString(spaceBefore).toUpperCase() + "), ";
        _s = _s + "spaceAfter: " + String.valueOf(spaceAfter) + "(" + Integer.toHexString(spaceAfter).toUpperCase() + "), ";
        _s = _s + "leftMargin: " + String.valueOf(leftMargin) + "(" + Integer.toHexString(leftMargin).toUpperCase() + "), ";
        _s = _s + "indent: " + String.valueOf(indent) + "(" + Integer.toHexString(indent).toUpperCase() + "), ";
        _s = _s + "defaultTabSize: " + String.valueOf(defaultTabSize) + "(" + Integer.toHexString(defaultTabSize).toUpperCase() + "), ";
        _s = _s + "tabStops: " + String.valueOf(tabStops) + ", ";
        _s = _s + "fontAlign: " + String.valueOf(fontAlign) + "(" + Integer.toHexString(fontAlign).toUpperCase() + "), ";
        _s = _s + "wrapFlags: " + String.valueOf(wrapFlags) + "(" + Integer.toHexString(wrapFlags).toUpperCase() + "), ";
        _s = _s + "textDirection: " + String.valueOf(textDirection) + "(" + Integer.toHexString(textDirection).toUpperCase() + "), ";
        return _s;
    }
}
class TextCFException {
    CFMasks masks;
    CFStyle fontStyle;
    int fontRef;
    int oldEAFontRef;
    int ansiFontRef;
    int symbolFontRef;
    int fontSize;
    ColorIndexStruct color;
    short position;
    public String toString() {
        String _s = "TextCFException:";
        _s = _s + "masks: " + String.valueOf(masks) + ", ";
        _s = _s + "fontStyle: " + String.valueOf(fontStyle) + ", ";
        _s = _s + "fontRef: " + String.valueOf(fontRef) + "(" + Integer.toHexString(fontRef).toUpperCase() + "), ";
        _s = _s + "oldEAFontRef: " + String.valueOf(oldEAFontRef) + "(" + Integer.toHexString(oldEAFontRef).toUpperCase() + "), ";
        _s = _s + "ansiFontRef: " + String.valueOf(ansiFontRef) + "(" + Integer.toHexString(ansiFontRef).toUpperCase() + "), ";
        _s = _s + "symbolFontRef: " + String.valueOf(symbolFontRef) + "(" + Integer.toHexString(symbolFontRef).toUpperCase() + "), ";
        _s = _s + "fontSize: " + String.valueOf(fontSize) + "(" + Integer.toHexString(fontSize).toUpperCase() + "), ";
        _s = _s + "color: " + String.valueOf(color) + ", ";
        _s = _s + "position: " + String.valueOf(position) + "(" + Integer.toHexString(position).toUpperCase() + "), ";
        return _s;
    }
}
class FontCollectionEntry {
    FontEntityAtom fontEntityAtom;
    FontEmbedDataBlob fontEmbedData1;
    FontEmbedDataBlob fontEmbedData2;
    FontEmbedDataBlob fontEmbedData3;
    FontEmbedDataBlob fontEmbedData4;
    public String toString() {
        String _s = "FontCollectionEntry:";
        _s = _s + "fontEntityAtom: " + String.valueOf(fontEntityAtom) + ", ";
        _s = _s + "fontEmbedData1: " + String.valueOf(fontEmbedData1) + ", ";
        _s = _s + "fontEmbedData2: " + String.valueOf(fontEmbedData2) + ", ";
        _s = _s + "fontEmbedData3: " + String.valueOf(fontEmbedData3) + ", ";
        _s = _s + "fontEmbedData4: " + String.valueOf(fontEmbedData4) + ", ";
        return _s;
    }
}
class KinsokuContainer {
    RecordHeader rh;
    KinsokuAtom kinsokuAtom;
    KinsokuFollowingAtom kinsokuLeadingAtom;
    KinsokuFollowingAtom kinsokuFollowingAtom;
    public String toString() {
        String _s = "KinsokuContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "kinsokuAtom: " + String.valueOf(kinsokuAtom) + ", ";
        _s = _s + "kinsokuLeadingAtom: " + String.valueOf(kinsokuLeadingAtom) + ", ";
        _s = _s + "kinsokuFollowingAtom: " + String.valueOf(kinsokuFollowingAtom) + ", ";
        return _s;
    }
}
class TextSIException {
    boolean spell;
    boolean lang;
    boolean altLang;
    boolean unused1;
    boolean unused2;
    boolean fPp10ext;
    boolean fBidi;
    boolean unused3;
    boolean reserved1;
    boolean smartTag;
    byte reserved2a;
    int reserved2b;
    int spellInfo;
    int lid;
    int altLid;
    short bidi;
    byte pp10runid;
    byte reserved3a;
    int reserved3b;
    byte reserved3bc;
    boolean grammarError;
    SmartTags smartTags;
    public String toString() {
        String _s = "TextSIException:";
        _s = _s + "spell: " + String.valueOf(spell) + ", ";
        _s = _s + "lang: " + String.valueOf(lang) + ", ";
        _s = _s + "altLang: " + String.valueOf(altLang) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "fPp10ext: " + String.valueOf(fPp10ext) + ", ";
        _s = _s + "fBidi: " + String.valueOf(fBidi) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "smartTag: " + String.valueOf(smartTag) + ", ";
        _s = _s + "reserved2a: " + String.valueOf(reserved2a) + "(" + Integer.toHexString(reserved2a).toUpperCase() + "), ";
        _s = _s + "reserved2b: " + String.valueOf(reserved2b) + "(" + Integer.toHexString(reserved2b).toUpperCase() + "), ";
        _s = _s + "spellInfo: " + String.valueOf(spellInfo) + "(" + Integer.toHexString(spellInfo).toUpperCase() + "), ";
        _s = _s + "lid: " + String.valueOf(lid) + "(" + Integer.toHexString(lid).toUpperCase() + "), ";
        _s = _s + "altLid: " + String.valueOf(altLid) + "(" + Integer.toHexString(altLid).toUpperCase() + "), ";
        _s = _s + "bidi: " + String.valueOf(bidi) + "(" + Integer.toHexString(bidi).toUpperCase() + "), ";
        _s = _s + "pp10runid: " + String.valueOf(pp10runid) + "(" + Integer.toHexString(pp10runid).toUpperCase() + "), ";
        _s = _s + "reserved3a: " + String.valueOf(reserved3a) + "(" + Integer.toHexString(reserved3a).toUpperCase() + "), ";
        _s = _s + "reserved3b: " + String.valueOf(reserved3b) + "(" + Integer.toHexString(reserved3b).toUpperCase() + "), ";
        _s = _s + "reserved3bc: " + String.valueOf(reserved3bc) + "(" + Integer.toHexString(reserved3bc).toUpperCase() + "), ";
        _s = _s + "grammarError: " + String.valueOf(grammarError) + ", ";
        _s = _s + "smartTags: " + String.valueOf(smartTags) + ", ";
        return _s;
    }
}
class TextMasterStyleLevel {
    TextPFException pf;
    TextCFException cf;
    public String toString() {
        String _s = "TextMasterStyleLevel:";
        _s = _s + "pf: " + String.valueOf(pf) + ", ";
        _s = _s + "cf: " + String.valueOf(cf) + ", ";
        return _s;
    }
}
class DocumentAtom {
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
        _s = _s + "firstSlideNumber: " + String.valueOf(firstSlideNumber) + "(" + Integer.toHexString(firstSlideNumber).toUpperCase() + "), ";
        _s = _s + "slideSizeType: " + String.valueOf(slideSizeType) + "(" + Integer.toHexString(slideSizeType).toUpperCase() + "), ";
        _s = _s + "fSaveWithFonts: " + String.valueOf(fSaveWithFonts) + "(" + Integer.toHexString(fSaveWithFonts).toUpperCase() + "), ";
        _s = _s + "fOmitTitlePlace: " + String.valueOf(fOmitTitlePlace) + "(" + Integer.toHexString(fOmitTitlePlace).toUpperCase() + "), ";
        _s = _s + "fRightToLeft: " + String.valueOf(fRightToLeft) + "(" + Integer.toHexString(fRightToLeft).toUpperCase() + "), ";
        _s = _s + "fShowComments: " + String.valueOf(fShowComments) + "(" + Integer.toHexString(fShowComments).toUpperCase() + "), ";
        return _s;
    }
}
class ProgStringTagContainer {
    RecordHeader rh;
    TagNameAtom tagNameAtom;
    TagValueAtom tagValueAtom;
    public String toString() {
        String _s = "ProgStringTagContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "tagNameAtom: " + String.valueOf(tagNameAtom) + ", ";
        _s = _s + "tagValueAtom: " + String.valueOf(tagValueAtom) + ", ";
        return _s;
    }
}
class ExObjListContainer {
    RecordHeader rh;
    ExObjListAtom exObjListAtom;
    final java.util.List<ExObjListSubContainer> rgChildRec = new java.util.ArrayList<ExObjListSubContainer>();
    public String toString() {
        String _s = "ExObjListContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "exObjListAtom: " + String.valueOf(exObjListAtom) + ", ";
        _s = _s + "rgChildRec: " + String.valueOf(rgChildRec) + ", ";
        return _s;
    }
}
class ExOleLinkContainer {
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
class ExOleEmbedContainer {
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
class OfficeArtFDGGBlock {
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
class ProtectionBooleanProperties {
    OfficeArtFOPTEOPID opid;
    boolean fLockAgainstGrouping;
    boolean fLockAdjustHandles;
    boolean fLockText;
    boolean fLockVertices;
    boolean fLockCropping;
    boolean fLockAgainstSelect;
    boolean fLockPosition;
    boolean fLockAspectRatio;
    boolean fLockRotation;
    boolean fLockAgainstUngrouping;
    byte unused6;
    boolean fUsefLockAgainstGrouping;
    boolean fUseLockAdjustHandles;
    boolean fUseLockText;
    boolean fUsefLockVertices;
    boolean fUsefLockCropping;
    boolean fUsefLockAgainstSelect;
    boolean fUsefLockPosition;
    boolean fUsefLockAspectRatio;
    boolean fUsefLockRotation;
    boolean fUsefLockAgainstUngrouping;
    byte unused2;
    public String toString() {
        String _s = "ProtectionBooleanProperties:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fLockAgainstGrouping: " + String.valueOf(fLockAgainstGrouping) + ", ";
        _s = _s + "fLockAdjustHandles: " + String.valueOf(fLockAdjustHandles) + ", ";
        _s = _s + "fLockText: " + String.valueOf(fLockText) + ", ";
        _s = _s + "fLockVertices: " + String.valueOf(fLockVertices) + ", ";
        _s = _s + "fLockCropping: " + String.valueOf(fLockCropping) + ", ";
        _s = _s + "fLockAgainstSelect: " + String.valueOf(fLockAgainstSelect) + ", ";
        _s = _s + "fLockPosition: " + String.valueOf(fLockPosition) + ", ";
        _s = _s + "fLockAspectRatio: " + String.valueOf(fLockAspectRatio) + ", ";
        _s = _s + "fLockRotation: " + String.valueOf(fLockRotation) + ", ";
        _s = _s + "fLockAgainstUngrouping: " + String.valueOf(fLockAgainstUngrouping) + ", ";
        _s = _s + "unused6: " + String.valueOf(unused6) + "(" + Integer.toHexString(unused6).toUpperCase() + "), ";
        _s = _s + "fUsefLockAgainstGrouping: " + String.valueOf(fUsefLockAgainstGrouping) + ", ";
        _s = _s + "fUseLockAdjustHandles: " + String.valueOf(fUseLockAdjustHandles) + ", ";
        _s = _s + "fUseLockText: " + String.valueOf(fUseLockText) + ", ";
        _s = _s + "fUsefLockVertices: " + String.valueOf(fUsefLockVertices) + ", ";
        _s = _s + "fUsefLockCropping: " + String.valueOf(fUsefLockCropping) + ", ";
        _s = _s + "fUsefLockAgainstSelect: " + String.valueOf(fUsefLockAgainstSelect) + ", ";
        _s = _s + "fUsefLockPosition: " + String.valueOf(fUsefLockPosition) + ", ";
        _s = _s + "fUsefLockAspectRatio: " + String.valueOf(fUsefLockAspectRatio) + ", ";
        _s = _s + "fUsefLockRotation: " + String.valueOf(fUsefLockRotation) + ", ";
        _s = _s + "fUsefLockAgainstUngrouping: " + String.valueOf(fUsefLockAgainstUngrouping) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        return _s;
    }
}
class Rotation {
    OfficeArtFOPTEOPID opid;
    FixedPoint rotation;
    public String toString() {
        String _s = "Rotation:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "rotation: " + String.valueOf(rotation) + ", ";
        return _s;
    }
}
class ITxid {
    OfficeArtFOPTEOPID opid;
    int iTxid;
    public String toString() {
        String _s = "ITxid:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "iTxid: " + String.valueOf(iTxid) + "(" + Integer.toHexString(iTxid).toUpperCase() + "), ";
        return _s;
    }
}
class DxTextLeft {
    OfficeArtFOPTEOPID opid;
    int dxTextLeft;
    public String toString() {
        String _s = "DxTextLeft:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "dxTextLeft: " + String.valueOf(dxTextLeft) + "(" + Integer.toHexString(dxTextLeft).toUpperCase() + "), ";
        return _s;
    }
}
class DyTextTop {
    OfficeArtFOPTEOPID opid;
    int dyTextTop;
    public String toString() {
        String _s = "DyTextTop:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "dyTextTop: " + String.valueOf(dyTextTop) + "(" + Integer.toHexString(dyTextTop).toUpperCase() + "), ";
        return _s;
    }
}
class DxTextRight {
    OfficeArtFOPTEOPID opid;
    int dxTextRight;
    public String toString() {
        String _s = "DxTextRight:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "dxTextRight: " + String.valueOf(dxTextRight) + "(" + Integer.toHexString(dxTextRight).toUpperCase() + "), ";
        return _s;
    }
}
class DyTextBottom {
    OfficeArtFOPTEOPID opid;
    int dyTextBottom;
    public String toString() {
        String _s = "DyTextBottom:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "dyTextBottom: " + String.valueOf(dyTextBottom) + "(" + Integer.toHexString(dyTextBottom).toUpperCase() + "), ";
        return _s;
    }
}
class WrapText {
    OfficeArtFOPTEOPID opid;
    int wrapText;
    public String toString() {
        String _s = "WrapText:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "wrapText: " + String.valueOf(wrapText) + "(" + Integer.toHexString(wrapText).toUpperCase() + "), ";
        return _s;
    }
}
class AnchorText {
    OfficeArtFOPTEOPID opid;
    int anchorText;
    public String toString() {
        String _s = "AnchorText:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "anchorText: " + String.valueOf(anchorText) + "(" + Integer.toHexString(anchorText).toUpperCase() + "), ";
        return _s;
    }
}
class TextBooleanProperties {
    OfficeArtFOPTEOPID opid;
    boolean unused1;
    boolean fFitShapeToText;
    boolean unused2;
    boolean fAutoTextMargin;
    boolean fSelectText;
    byte unused3a;
    byte unused3b;
    boolean unused4;
    boolean fUsefFitShapeToText;
    boolean unused5;
    boolean fUsefAutoTextMargin;
    boolean fUsefSelectText;
    byte unused6a;
    byte unused6b;
    public String toString() {
        String _s = "TextBooleanProperties:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "fFitShapeToText: " + String.valueOf(fFitShapeToText) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "fAutoTextMargin: " + String.valueOf(fAutoTextMargin) + ", ";
        _s = _s + "fSelectText: " + String.valueOf(fSelectText) + ", ";
        _s = _s + "unused3a: " + String.valueOf(unused3a) + "(" + Integer.toHexString(unused3a).toUpperCase() + "), ";
        _s = _s + "unused3b: " + String.valueOf(unused3b) + "(" + Integer.toHexString(unused3b).toUpperCase() + "), ";
        _s = _s + "unused4: " + String.valueOf(unused4) + ", ";
        _s = _s + "fUsefFitShapeToText: " + String.valueOf(fUsefFitShapeToText) + ", ";
        _s = _s + "unused5: " + String.valueOf(unused5) + ", ";
        _s = _s + "fUsefAutoTextMargin: " + String.valueOf(fUsefAutoTextMargin) + ", ";
        _s = _s + "fUsefSelectText: " + String.valueOf(fUsefSelectText) + ", ";
        _s = _s + "unused6a: " + String.valueOf(unused6a) + "(" + Integer.toHexString(unused6a).toUpperCase() + "), ";
        _s = _s + "unused6b: " + String.valueOf(unused6b) + "(" + Integer.toHexString(unused6b).toUpperCase() + "), ";
        return _s;
    }
}
class HspNext {
    OfficeArtFOPTEOPID opid;
    int hspNext;
    public String toString() {
        String _s = "HspNext:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "hspNext: " + String.valueOf(hspNext) + "(" + Integer.toHexString(hspNext).toUpperCase() + "), ";
        return _s;
    }
}
class ShapePath {
    OfficeArtFOPTEOPID opid;
    int shapePath;
    public String toString() {
        String _s = "ShapePath:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "shapePath: " + String.valueOf(shapePath) + "(" + Integer.toHexString(shapePath).toUpperCase() + "), ";
        return _s;
    }
}
class GeometryBooleanProperties {
    OfficeArtFOPTEOPID opid;
    boolean fFillOk;
    boolean fFillShadeShapeOK;
    boolean fGtextOK;
    boolean fLineOK;
    boolean f3DOK;
    boolean fShadowOK;
    boolean unuseda;
    boolean unusedb;
    byte unused2;
    boolean fUsefFillOK;
    boolean fUsefFillShadeShapeOK;
    boolean fUsefGtextOK;
    boolean fUsefLineOK;
    boolean fUsef3DOK;
    boolean fUsefShadowOK;
    boolean unused3a;
    boolean unused3b;
    byte unused4;
    public String toString() {
        String _s = "GeometryBooleanProperties:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fFillOk: " + String.valueOf(fFillOk) + ", ";
        _s = _s + "fFillShadeShapeOK: " + String.valueOf(fFillShadeShapeOK) + ", ";
        _s = _s + "fGtextOK: " + String.valueOf(fGtextOK) + ", ";
        _s = _s + "fLineOK: " + String.valueOf(fLineOK) + ", ";
        _s = _s + "f3DOK: " + String.valueOf(f3DOK) + ", ";
        _s = _s + "fShadowOK: " + String.valueOf(fShadowOK) + ", ";
        _s = _s + "unuseda: " + String.valueOf(unuseda) + ", ";
        _s = _s + "unusedb: " + String.valueOf(unusedb) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        _s = _s + "fUsefFillOK: " + String.valueOf(fUsefFillOK) + ", ";
        _s = _s + "fUsefFillShadeShapeOK: " + String.valueOf(fUsefFillShadeShapeOK) + ", ";
        _s = _s + "fUsefGtextOK: " + String.valueOf(fUsefGtextOK) + ", ";
        _s = _s + "fUsefLineOK: " + String.valueOf(fUsefLineOK) + ", ";
        _s = _s + "fUsef3DOK: " + String.valueOf(fUsef3DOK) + ", ";
        _s = _s + "fUsefShadowOK: " + String.valueOf(fUsefShadowOK) + ", ";
        _s = _s + "unused3a: " + String.valueOf(unused3a) + ", ";
        _s = _s + "unused3b: " + String.valueOf(unused3b) + ", ";
        _s = _s + "unused4: " + String.valueOf(unused4) + "(" + Integer.toHexString(unused4).toUpperCase() + "), ";
        return _s;
    }
}
class FillType {
    OfficeArtFOPTEOPID opid;
    int fillType;
    public String toString() {
        String _s = "FillType:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fillType: " + String.valueOf(fillType) + "(" + Integer.toHexString(fillType).toUpperCase() + "), ";
        return _s;
    }
}
class FillColor {
    OfficeArtFOPTEOPID opid;
    OfficeArtCOLORREF fillColor;
    public String toString() {
        String _s = "FillColor:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fillColor: " + String.valueOf(fillColor) + ", ";
        return _s;
    }
}
class FillBackColor {
    OfficeArtFOPTEOPID opid;
    OfficeArtCOLORREF fillBackColor;
    public String toString() {
        String _s = "FillBackColor:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fillBackColor: " + String.valueOf(fillBackColor) + ", ";
        return _s;
    }
}
class FillBlip {
    OfficeArtFOPTEOPID opid;
    int fillBlip;
    public String toString() {
        String _s = "FillBlip:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fillBlip: " + String.valueOf(fillBlip) + "(" + Integer.toHexString(fillBlip).toUpperCase() + "), ";
        return _s;
    }
}
class FillRectRight {
    OfficeArtFOPTEOPID opid;
    int fillRectRight;
    public String toString() {
        String _s = "FillRectRight:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fillRectRight: " + String.valueOf(fillRectRight) + "(" + Integer.toHexString(fillRectRight).toUpperCase() + "), ";
        return _s;
    }
}
class FillRectBottom {
    OfficeArtFOPTEOPID opid;
    int fillRectBottom;
    public String toString() {
        String _s = "FillRectBottom:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fillRectBottom: " + String.valueOf(fillRectBottom) + "(" + Integer.toHexString(fillRectBottom).toUpperCase() + "), ";
        return _s;
    }
}
class FillStyleBooleanProperties {
    OfficeArtFOPTEOPID opid;
    boolean fNoFillHitText;
    boolean fillUseRect;
    boolean fillShape;
    boolean fHitTestFill;
    boolean fFilled;
    boolean fUseShapeAnchor;
    boolean fRecolorFillAsPicture;
    boolean unused1a;
    byte unused1b;
    boolean fUseNoFillHitTest;
    boolean fUseFillUseRext;
    boolean fUseFillShape;
    boolean fUseHitTestFill;
    boolean fUseFilled;
    boolean fUseUseShapeAnchor;
    boolean fUsefRecolorFillAsPicture;
    boolean unused2a;
    byte unused2b;
    public String toString() {
        String _s = "FillStyleBooleanProperties:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fNoFillHitText: " + String.valueOf(fNoFillHitText) + ", ";
        _s = _s + "fillUseRect: " + String.valueOf(fillUseRect) + ", ";
        _s = _s + "fillShape: " + String.valueOf(fillShape) + ", ";
        _s = _s + "fHitTestFill: " + String.valueOf(fHitTestFill) + ", ";
        _s = _s + "fFilled: " + String.valueOf(fFilled) + ", ";
        _s = _s + "fUseShapeAnchor: " + String.valueOf(fUseShapeAnchor) + ", ";
        _s = _s + "fRecolorFillAsPicture: " + String.valueOf(fRecolorFillAsPicture) + ", ";
        _s = _s + "unused1a: " + String.valueOf(unused1a) + ", ";
        _s = _s + "unused1b: " + String.valueOf(unused1b) + "(" + Integer.toHexString(unused1b).toUpperCase() + "), ";
        _s = _s + "fUseNoFillHitTest: " + String.valueOf(fUseNoFillHitTest) + ", ";
        _s = _s + "fUseFillUseRext: " + String.valueOf(fUseFillUseRext) + ", ";
        _s = _s + "fUseFillShape: " + String.valueOf(fUseFillShape) + ", ";
        _s = _s + "fUseHitTestFill: " + String.valueOf(fUseHitTestFill) + ", ";
        _s = _s + "fUseFilled: " + String.valueOf(fUseFilled) + ", ";
        _s = _s + "fUseUseShapeAnchor: " + String.valueOf(fUseUseShapeAnchor) + ", ";
        _s = _s + "fUsefRecolorFillAsPicture: " + String.valueOf(fUsefRecolorFillAsPicture) + ", ";
        _s = _s + "unused2a: " + String.valueOf(unused2a) + ", ";
        _s = _s + "unused2b: " + String.valueOf(unused2b) + "(" + Integer.toHexString(unused2b).toUpperCase() + "), ";
        return _s;
    }
}
class LineColor {
    OfficeArtFOPTEOPID opid;
    OfficeArtCOLORREF lineColor;
    public String toString() {
        String _s = "LineColor:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineColor: " + String.valueOf(lineColor) + ", ";
        return _s;
    }
}
class LineBackColor {
    OfficeArtFOPTEOPID opid;
    OfficeArtCOLORREF lineBackColor;
    public String toString() {
        String _s = "LineBackColor:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineBackColor: " + String.valueOf(lineBackColor) + ", ";
        return _s;
    }
}
class LineFillBlip {
    OfficeArtFOPTEOPID opid;
    int lineFillBlip;
    public String toString() {
        String _s = "LineFillBlip:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineFillBlip: " + String.valueOf(lineFillBlip) + "(" + Integer.toHexString(lineFillBlip).toUpperCase() + "), ";
        return _s;
    }
}
class LineWidth {
    OfficeArtFOPTEOPID opid;
    int lineWidth;
    public String toString() {
        String _s = "LineWidth:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineWidth: " + String.valueOf(lineWidth) + "(" + Integer.toHexString(lineWidth).toUpperCase() + "), ";
        return _s;
    }
}
class LineStartArrowhead {
    OfficeArtFOPTEOPID opid;
    int lineStartArrowhead;
    public String toString() {
        String _s = "LineStartArrowhead:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineStartArrowhead: " + String.valueOf(lineStartArrowhead) + "(" + Integer.toHexString(lineStartArrowhead).toUpperCase() + "), ";
        return _s;
    }
}
class LineEndArrowhead {
    OfficeArtFOPTEOPID opid;
    int lineEndArrowhead;
    public String toString() {
        String _s = "LineEndArrowhead:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineEndArrowhead: " + String.valueOf(lineEndArrowhead) + "(" + Integer.toHexString(lineEndArrowhead).toUpperCase() + "), ";
        return _s;
    }
}
class LineJoinStyle {
    OfficeArtFOPTEOPID opid;
    int lineJoinStyle;
    public String toString() {
        String _s = "LineJoinStyle:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lineJoinStyle: " + String.valueOf(lineJoinStyle) + "(" + Integer.toHexString(lineJoinStyle).toUpperCase() + "), ";
        return _s;
    }
}
class LineStyleBooleanProperties {
    OfficeArtFOPTEOPID opid;
    boolean fNoLineDrawDash;
    boolean fLineFillShape;
    boolean fHitTestLine;
    boolean fLine;
    boolean fArrowHeadsOK;
    boolean fInsetPenOK;
    boolean fInsetPen;
    boolean reserved1;
    boolean reserved2;
    boolean fLineOpaqueBackColor;
    byte unused1;
    boolean fUseNoLineDrawDash;
    boolean fUseLineFillShape;
    boolean fUseHitTestLine;
    boolean fUsefLine;
    boolean fUsefArrowHeadsOK;
    boolean fUseInsetPenOK;
    boolean fUseInsetPen;
    boolean unused2;
    boolean unused3;
    boolean fUsefLineOpaqueBackColor;
    byte unused4;
    public String toString() {
        String _s = "LineStyleBooleanProperties:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fNoLineDrawDash: " + String.valueOf(fNoLineDrawDash) + ", ";
        _s = _s + "fLineFillShape: " + String.valueOf(fLineFillShape) + ", ";
        _s = _s + "fHitTestLine: " + String.valueOf(fHitTestLine) + ", ";
        _s = _s + "fLine: " + String.valueOf(fLine) + ", ";
        _s = _s + "fArrowHeadsOK: " + String.valueOf(fArrowHeadsOK) + ", ";
        _s = _s + "fInsetPenOK: " + String.valueOf(fInsetPenOK) + ", ";
        _s = _s + "fInsetPen: " + String.valueOf(fInsetPen) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "reserved2: " + String.valueOf(reserved2) + ", ";
        _s = _s + "fLineOpaqueBackColor: " + String.valueOf(fLineOpaqueBackColor) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + "(" + Integer.toHexString(unused1).toUpperCase() + "), ";
        _s = _s + "fUseNoLineDrawDash: " + String.valueOf(fUseNoLineDrawDash) + ", ";
        _s = _s + "fUseLineFillShape: " + String.valueOf(fUseLineFillShape) + ", ";
        _s = _s + "fUseHitTestLine: " + String.valueOf(fUseHitTestLine) + ", ";
        _s = _s + "fUsefLine: " + String.valueOf(fUsefLine) + ", ";
        _s = _s + "fUsefArrowHeadsOK: " + String.valueOf(fUsefArrowHeadsOK) + ", ";
        _s = _s + "fUseInsetPenOK: " + String.valueOf(fUseInsetPenOK) + ", ";
        _s = _s + "fUseInsetPen: " + String.valueOf(fUseInsetPen) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + ", ";
        _s = _s + "fUsefLineOpaqueBackColor: " + String.valueOf(fUsefLineOpaqueBackColor) + ", ";
        _s = _s + "unused4: " + String.valueOf(unused4) + "(" + Integer.toHexString(unused4).toUpperCase() + "), ";
        return _s;
    }
}
class ShadowColor {
    OfficeArtFOPTEOPID opid;
    OfficeArtCOLORREF shadowColor;
    public String toString() {
        String _s = "ShadowColor:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "shadowColor: " + String.valueOf(shadowColor) + ", ";
        return _s;
    }
}
class ShadowStyleBooleanPropertiesr {
    OfficeArtFOPTEOPID opid;
    boolean fshadowObscured;
    boolean fShadow;
    short unused1;
    boolean fUsefshadowObscured;
    boolean fUsefShadow;
    short unused2;
    public String toString() {
        String _s = "ShadowStyleBooleanPropertiesr:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fshadowObscured: " + String.valueOf(fshadowObscured) + ", ";
        _s = _s + "fShadow: " + String.valueOf(fShadow) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + "(" + Integer.toHexString(unused1).toUpperCase() + "), ";
        _s = _s + "fUsefshadowObscured: " + String.valueOf(fUsefshadowObscured) + ", ";
        _s = _s + "fUsefShadow: " + String.valueOf(fUsefShadow) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        return _s;
    }
}
class HspMaster {
    OfficeArtFOPTEOPID opid;
    int hspMaster;
    public String toString() {
        String _s = "HspMaster:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "hspMaster: " + String.valueOf(hspMaster) + "(" + Integer.toHexString(hspMaster).toUpperCase() + "), ";
        return _s;
    }
}
class BWMode {
    OfficeArtFOPTEOPID opid;
    int bWMode;
    public String toString() {
        String _s = "BWMode:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "bWMode: " + String.valueOf(bWMode) + "(" + Integer.toHexString(bWMode).toUpperCase() + "), ";
        return _s;
    }
}
class ShapeBooleanProperties {
    OfficeArtFOPTEOPID opid;
    boolean fBackground;
    boolean reserved1;
    boolean fInitiator;
    boolean fLockShapeType;
    boolean fPreferRelativeResize;
    boolean fOleIcon;
    boolean fFlipVOverride;
    boolean fFlipHOverride;
    boolean fPolicyBarcode;
    boolean fPolicyLabel;
    boolean unused1;
    boolean unused2;
    byte unused3;
    boolean fUsefBackground;
    boolean unused4;
    boolean fUsefInitiator;
    boolean fUsefLockShapeType;
    boolean fusePreferrelativeResize;
    boolean fUsefOleIcon;
    boolean fUsefFlipVOverride;
    boolean fUsefFlipHOverride;
    boolean fUsefPolicyBarcode;
    boolean fUsefPolicyLabel;
    boolean unused5;
    boolean unused6;
    byte unused7;
    public String toString() {
        String _s = "ShapeBooleanProperties:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "fBackground: " + String.valueOf(fBackground) + ", ";
        _s = _s + "reserved1: " + String.valueOf(reserved1) + ", ";
        _s = _s + "fInitiator: " + String.valueOf(fInitiator) + ", ";
        _s = _s + "fLockShapeType: " + String.valueOf(fLockShapeType) + ", ";
        _s = _s + "fPreferRelativeResize: " + String.valueOf(fPreferRelativeResize) + ", ";
        _s = _s + "fOleIcon: " + String.valueOf(fOleIcon) + ", ";
        _s = _s + "fFlipVOverride: " + String.valueOf(fFlipVOverride) + ", ";
        _s = _s + "fFlipHOverride: " + String.valueOf(fFlipHOverride) + ", ";
        _s = _s + "fPolicyBarcode: " + String.valueOf(fPolicyBarcode) + ", ";
        _s = _s + "fPolicyLabel: " + String.valueOf(fPolicyLabel) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "unused2: " + String.valueOf(unused2) + ", ";
        _s = _s + "unused3: " + String.valueOf(unused3) + "(" + Integer.toHexString(unused3).toUpperCase() + "), ";
        _s = _s + "fUsefBackground: " + String.valueOf(fUsefBackground) + ", ";
        _s = _s + "unused4: " + String.valueOf(unused4) + ", ";
        _s = _s + "fUsefInitiator: " + String.valueOf(fUsefInitiator) + ", ";
        _s = _s + "fUsefLockShapeType: " + String.valueOf(fUsefLockShapeType) + ", ";
        _s = _s + "fusePreferrelativeResize: " + String.valueOf(fusePreferrelativeResize) + ", ";
        _s = _s + "fUsefOleIcon: " + String.valueOf(fUsefOleIcon) + ", ";
        _s = _s + "fUsefFlipVOverride: " + String.valueOf(fUsefFlipVOverride) + ", ";
        _s = _s + "fUsefFlipHOverride: " + String.valueOf(fUsefFlipHOverride) + ", ";
        _s = _s + "fUsefPolicyBarcode: " + String.valueOf(fUsefPolicyBarcode) + ", ";
        _s = _s + "fUsefPolicyLabel: " + String.valueOf(fUsefPolicyLabel) + ", ";
        _s = _s + "unused5: " + String.valueOf(unused5) + ", ";
        _s = _s + "unused6: " + String.valueOf(unused6) + ", ";
        _s = _s + "unused7: " + String.valueOf(unused7) + "(" + Integer.toHexString(unused7).toUpperCase() + "), ";
        return _s;
    }
}
class LidRegroup {
    OfficeArtFOPTEOPID opid;
    int lidRegroup;
    public String toString() {
        String _s = "LidRegroup:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "lidRegroup: " + String.valueOf(lidRegroup) + "(" + Integer.toHexString(lidRegroup).toUpperCase() + "), ";
        return _s;
    }
}
class WzFillId {
    OfficeArtFOPTEOPID opid;
    int wzFillId;
    public String toString() {
        String _s = "WzFillId:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "wzFillId: " + String.valueOf(wzFillId) + "(" + Integer.toHexString(wzFillId).toUpperCase() + "), ";
        return _s;
    }
}
class OfficeArtClientAnchor {
    OfficeArtRecordHeader rh;
    SmallRectStruct rect1;
    RectStruct rect2;
    public String toString() {
        String _s = "OfficeArtClientAnchor:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "rect1: " + String.valueOf(rect1) + ", ";
        _s = _s + "rect2: " + String.valueOf(rect2) + ", ";
        return _s;
    }
}
class MouseInteractiveInfoContainer {
    RecordHeader rh;
    InteractiveInfoAtom interactiveInfoAtom;
    MacroNameAtom macroNameAtom;
    public String toString() {
        String _s = "MouseInteractiveInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "interactiveInfoAtom: " + String.valueOf(interactiveInfoAtom) + ", ";
        _s = _s + "macroNameAtom: " + String.valueOf(macroNameAtom) + ", ";
        return _s;
    }
}
class OfficeArtFOPTE {
    OfficeArtFOPTEOPID opid;
    int op;
    public String toString() {
        String _s = "OfficeArtFOPTE:";
        _s = _s + "opid: " + String.valueOf(opid) + ", ";
        _s = _s + "op: " + String.valueOf(op) + "(" + Integer.toHexString(op).toUpperCase() + "), ";
        return _s;
    }
}
class Fib {
    FibBase base;
    int csw;
    FibRgW97 fibRgW;
    int cslw;
    FibRgLw97 fibRgLw;
    int cbRgFcLcb;
    FibRgFcLcb97 fibRgFcLcbBlob;
    FibRgFcLcb2000 fibRgFcLcbBlob2;
    FibRgFcLcb2002 fibRgFcLcbBlob3;
    int cswNew;
    byte[] fibRgCswNew;
    byte[] trail;
    public String toString() {
        String _s = "Fib:";
        _s = _s + "base: " + String.valueOf(base) + ", ";
        _s = _s + "csw: " + String.valueOf(csw) + "(" + Integer.toHexString(csw).toUpperCase() + "), ";
        _s = _s + "fibRgW: " + String.valueOf(fibRgW) + ", ";
        _s = _s + "cslw: " + String.valueOf(cslw) + "(" + Integer.toHexString(cslw).toUpperCase() + "), ";
        _s = _s + "fibRgLw: " + String.valueOf(fibRgLw) + ", ";
        _s = _s + "cbRgFcLcb: " + String.valueOf(cbRgFcLcb) + "(" + Integer.toHexString(cbRgFcLcb).toUpperCase() + "), ";
        _s = _s + "fibRgFcLcbBlob: " + String.valueOf(fibRgFcLcbBlob) + ", ";
        _s = _s + "fibRgFcLcbBlob2: " + String.valueOf(fibRgFcLcbBlob2) + ", ";
        _s = _s + "fibRgFcLcbBlob3: " + String.valueOf(fibRgFcLcbBlob3) + ", ";
        _s = _s + "cswNew: " + String.valueOf(cswNew) + "(" + Integer.toHexString(cswNew).toUpperCase() + "), ";
        _s = _s + "fibRgCswNew: " + String.valueOf(fibRgCswNew) + ", ";
        _s = _s + "trail: " + String.valueOf(trail) + ", ";
        return _s;
    }
}
class STSH {
    LPStshi lpstshi;
    LPStd[] rglpstd;
    public String toString() {
        String _s = "STSH:";
        _s = _s + "lpstshi: " + String.valueOf(lpstshi) + ", ";
        _s = _s + "rglpstd: " + String.valueOf(rglpstd) + ", ";
        return _s;
    }
}
class Clx {
    final java.util.List<Pcr> RgPrc = new java.util.ArrayList<Pcr>();
    Pcdt pcdt;
    public String toString() {
        String _s = "Clx:";
        _s = _s + "RgPrc: " + String.valueOf(RgPrc) + ", ";
        _s = _s + "pcdt: " + String.valueOf(pcdt) + ", ";
        return _s;
    }
}
class Pcr {
    byte clxt;
    PrcData prcData;
    public String toString() {
        String _s = "Pcr:";
        _s = _s + "clxt: " + String.valueOf(clxt) + "(" + Integer.toHexString(clxt).toUpperCase() + "), ";
        _s = _s + "prcData: " + String.valueOf(prcData) + ", ";
        return _s;
    }
}
class Prm {
    Object prm;
    public String toString() {
        String _s = "Prm:";
        _s = _s + "prm: " + String.valueOf(prm) + ", ";
        return _s;
    }
}
class OfficeArtBlipEMF {
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
class OfficeArtBlipWMF {
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
class OfficeArtBlipPICT {
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
class OfficeArtBlip {
    Object anon;
    public String toString() {
        String _s = "OfficeArtBlip:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class ZoomViewInfoAtom {
    RecordHeader rh;
    ScalingStruct curScale;
    byte[] unused1;
    PointStruct origin;
    byte fUseVarScale;
    byte fDraftMode;
    int unused2;
    public String toString() {
        String _s = "ZoomViewInfoAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "curScale: " + String.valueOf(curScale) + ", ";
        _s = _s + "unused1: " + String.valueOf(unused1) + ", ";
        _s = _s + "origin: " + String.valueOf(origin) + ", ";
        _s = _s + "fUseVarScale: " + String.valueOf(fUseVarScale) + "(" + Integer.toHexString(fUseVarScale).toUpperCase() + "), ";
        _s = _s + "fDraftMode: " + String.valueOf(fDraftMode) + "(" + Integer.toHexString(fDraftMode).toUpperCase() + "), ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        return _s;
    }
}
class DocProgTagsSubContainerOrAtom {
    Object anon;
    public String toString() {
        String _s = "DocProgTagsSubContainerOrAtom:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class NotesTextViewInfoContainer {
    RecordHeader rh;
    ZoomViewInfoAtom zoomViewInfo;
    public String toString() {
        String _s = "NotesTextViewInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "zoomViewInfo: " + String.valueOf(zoomViewInfo) + ", ";
        return _s;
    }
}
class OutlineViewInfoContainer {
    RecordHeader rh;
    NoZoomViewInfoAtom noZoomViewInfo;
    public String toString() {
        String _s = "OutlineViewInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "noZoomViewInfo: " + String.valueOf(noZoomViewInfo) + ", ";
        return _s;
    }
}
class NormalViewSetInfoContainer {
    RecordHeader rh;
    NormalViewSetInfoAtom normalViewSetInfoAtom;
    public String toString() {
        String _s = "NormalViewSetInfoContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "normalViewSetInfoAtom: " + String.valueOf(normalViewSetInfoAtom) + ", ";
        return _s;
    }
}
class SlideListWithTextSubContainerOrAtom {
    SlidePersistAtom slidePersistAtom;
    final java.util.List<TextContainer> atoms = new java.util.ArrayList<TextContainer>();
    public String toString() {
        String _s = "SlideListWithTextSubContainerOrAtom:";
        _s = _s + "slidePersistAtom: " + String.valueOf(slidePersistAtom) + ", ";
        _s = _s + "atoms: " + String.valueOf(atoms) + ", ";
        return _s;
    }
}
class TextContainerInteractiveInfo {
    Object interactive;
    public String toString() {
        String _s = "TextContainerInteractiveInfo:";
        _s = _s + "interactive: " + String.valueOf(interactive) + ", ";
        return _s;
    }
}
class TextPFRun {
    int count;
    int indentLevel;
    TextPFException pf;
    public String toString() {
        String _s = "TextPFRun:";
        _s = _s + "count: " + String.valueOf(count) + "(" + Integer.toHexString(count).toUpperCase() + "), ";
        _s = _s + "indentLevel: " + String.valueOf(indentLevel) + "(" + Integer.toHexString(indentLevel).toUpperCase() + "), ";
        _s = _s + "pf: " + String.valueOf(pf) + ", ";
        return _s;
    }
}
class TextCFRun {
    int count;
    TextCFException cf;
    public String toString() {
        String _s = "TextCFRun:";
        _s = _s + "count: " + String.valueOf(count) + "(" + Integer.toHexString(count).toUpperCase() + "), ";
        _s = _s + "cf: " + String.valueOf(cf) + ", ";
        return _s;
    }
}
class TextCFExceptionAtom {
    RecordHeader rh;
    TextCFException cf;
    public String toString() {
        String _s = "TextCFExceptionAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "cf: " + String.valueOf(cf) + ", ";
        return _s;
    }
}
class DefaultRulerAtom {
    RecordHeader rh;
    TextRuler defaultTextRuler;
    public String toString() {
        String _s = "DefaultRulerAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "defaultTextRuler: " + String.valueOf(defaultTextRuler) + ", ";
        return _s;
    }
}
class TextPFExceptionAtom {
    RecordHeader rh;
    int reserved;
    TextPFException pf;
    public String toString() {
        String _s = "TextPFExceptionAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "reserved: " + String.valueOf(reserved) + "(" + Integer.toHexString(reserved).toUpperCase() + "), ";
        _s = _s + "pf: " + String.valueOf(pf) + ", ";
        return _s;
    }
}
class TextSIRun {
    int count;
    TextSIException si;
    public String toString() {
        String _s = "TextSIRun:";
        _s = _s + "count: " + String.valueOf(count) + "(" + Integer.toHexString(count).toUpperCase() + "), ";
        _s = _s + "si: " + String.valueOf(si) + ", ";
        return _s;
    }
}
class TextSIExceptionAtom {
    RecordHeader rh;
    TextSIException textSIException;
    public String toString() {
        String _s = "TextSIExceptionAtom:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "textSIException: " + String.valueOf(textSIException) + ", ";
        return _s;
    }
}
class TextMasterStyleAtom {
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
        _s = _s + "cLevels: " + String.valueOf(cLevels) + "(" + Integer.toHexString(cLevels).toUpperCase() + "), ";
        _s = _s + "lstLvl1level: " + String.valueOf(lstLvl1level) + "(" + Integer.toHexString(lstLvl1level).toUpperCase() + "), ";
        _s = _s + "lstLvl1: " + String.valueOf(lstLvl1) + ", ";
        _s = _s + "lstLvl2level: " + String.valueOf(lstLvl2level) + "(" + Integer.toHexString(lstLvl2level).toUpperCase() + "), ";
        _s = _s + "lstLvl2: " + String.valueOf(lstLvl2) + ", ";
        _s = _s + "lstLvl3level: " + String.valueOf(lstLvl3level) + "(" + Integer.toHexString(lstLvl3level).toUpperCase() + "), ";
        _s = _s + "lstLvl3: " + String.valueOf(lstLvl3) + ", ";
        _s = _s + "lstLvl4level: " + String.valueOf(lstLvl4level) + "(" + Integer.toHexString(lstLvl4level).toUpperCase() + "), ";
        _s = _s + "lstLvl4: " + String.valueOf(lstLvl4) + ", ";
        _s = _s + "lstLvl5level: " + String.valueOf(lstLvl5level) + "(" + Integer.toHexString(lstLvl5level).toUpperCase() + "), ";
        _s = _s + "lstLvl5: " + String.valueOf(lstLvl5) + ", ";
        return _s;
    }
}
class SlideProgTagsSubContainerOrAtom {
    Object anon;
    public String toString() {
        String _s = "SlideProgTagsSubContainerOrAtom:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class ExObjListSubContainer {
    Object anon;
    public String toString() {
        String _s = "ExObjListSubContainer:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class OfficeArtDggContainer {
    OfficeArtRecordHeader rh;
    OfficeArtFDGGBlock drawingGroup;
    OfficeArtBStoreContainer blipStore;
    OfficeArtFOPT drawingPrimaryOptions;
    OfficeArtTertiaryFOPT drawingTertiaryOptions;
    OfficeArtColorMRUContainer colorMRU;
    OfficeArtSplitMenuColorContainer splitColors;
    OfficeArtTertiaryFOPT unknown;
    public String toString() {
        String _s = "OfficeArtDggContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "drawingGroup: " + String.valueOf(drawingGroup) + ", ";
        _s = _s + "blipStore: " + String.valueOf(blipStore) + ", ";
        _s = _s + "drawingPrimaryOptions: " + String.valueOf(drawingPrimaryOptions) + ", ";
        _s = _s + "drawingTertiaryOptions: " + String.valueOf(drawingTertiaryOptions) + ", ";
        _s = _s + "colorMRU: " + String.valueOf(colorMRU) + ", ";
        _s = _s + "splitColors: " + String.valueOf(splitColors) + ", ";
        _s = _s + "unknown: " + String.valueOf(unknown) + ", ";
        return _s;
    }
}
class OfficeArtFOPTEChoice {
    Object anon;
    public String toString() {
        String _s = "OfficeArtFOPTEChoice:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class OfficeArtClientData {
    OfficeArtRecordHeader rh;
    ShapeFlagsAtom shapeFlagsAtom;
    ShapeFlags10Atom shapeFlags10Atom;
    ExObjRefAtom exObjRefAtom;
    AnimationInfoContainer animationInfo;
    MouseInteractiveInfoContainer mouseClickInteractiveInfo;
    MouseInteractiveInfoContainer mouseOverInteractiveInfo;
    PlaceholderAtom placeholderAtom;
    RecolorInfoAtom recolorInfoAtom;
    final java.util.List<ShapeClientRoundtripDataSubcontainerOrAtom> rgShapeClientRoundtripData = new java.util.ArrayList<ShapeClientRoundtripDataSubcontainerOrAtom>();
    UnknownOfficeArtClientDataChild unknown;
    public String toString() {
        String _s = "OfficeArtClientData:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "shapeFlagsAtom: " + String.valueOf(shapeFlagsAtom) + ", ";
        _s = _s + "shapeFlags10Atom: " + String.valueOf(shapeFlags10Atom) + ", ";
        _s = _s + "exObjRefAtom: " + String.valueOf(exObjRefAtom) + ", ";
        _s = _s + "animationInfo: " + String.valueOf(animationInfo) + ", ";
        _s = _s + "mouseClickInteractiveInfo: " + String.valueOf(mouseClickInteractiveInfo) + ", ";
        _s = _s + "mouseOverInteractiveInfo: " + String.valueOf(mouseOverInteractiveInfo) + ", ";
        _s = _s + "placeholderAtom: " + String.valueOf(placeholderAtom) + ", ";
        _s = _s + "recolorInfoAtom: " + String.valueOf(recolorInfoAtom) + ", ";
        _s = _s + "rgShapeClientRoundtripData: " + String.valueOf(rgShapeClientRoundtripData) + ", ";
        _s = _s + "unknown: " + String.valueOf(unknown) + ", ";
        return _s;
    }
}
class WordDocument {
    Fib fib;
    public String toString() {
        String _s = "WordDocument:";
        _s = _s + "fib: " + String.valueOf(fib) + ", ";
        return _s;
    }
}
class Table {
    STSH stsh;
    PlcfSed plcfSed;
    Plcfhdd plcfHdd;
    PlcBteChpx plcfBteChpx;
    PlcfBtePapx plcfBtePapx;
    Tcg cmds;
    Clx clx;
    SttbfFfn sttbfFfn;
    byte[] dop;
    public String toString() {
        String _s = "Table:";
        _s = _s + "stsh: " + String.valueOf(stsh) + ", ";
        _s = _s + "plcfSed: " + String.valueOf(plcfSed) + ", ";
        _s = _s + "plcfHdd: " + String.valueOf(plcfHdd) + ", ";
        _s = _s + "plcfBteChpx: " + String.valueOf(plcfBteChpx) + ", ";
        _s = _s + "plcfBtePapx: " + String.valueOf(plcfBtePapx) + ", ";
        _s = _s + "cmds: " + String.valueOf(cmds) + ", ";
        _s = _s + "clx: " + String.valueOf(clx) + ", ";
        _s = _s + "sttbfFfn: " + String.valueOf(sttbfFfn) + ", ";
        _s = _s + "dop: " + String.valueOf(dop) + ", ";
        return _s;
    }
}
class Pcd {
    boolean fNoParaLast;
    boolean fR1;
    boolean fDirtly;
    boolean fR2;
    short fR3;
    FCompressed fc;
    Prm prm;
    public String toString() {
        String _s = "Pcd:";
        _s = _s + "fNoParaLast: " + String.valueOf(fNoParaLast) + ", ";
        _s = _s + "fR1: " + String.valueOf(fR1) + ", ";
        _s = _s + "fDirtly: " + String.valueOf(fDirtly) + ", ";
        _s = _s + "fR2: " + String.valueOf(fR2) + ", ";
        _s = _s + "fR3: " + String.valueOf(fR3) + "(" + Integer.toHexString(fR3).toUpperCase() + "), ";
        _s = _s + "fc: " + String.valueOf(fc) + ", ";
        _s = _s + "prm: " + String.valueOf(prm) + ", ";
        return _s;
    }
}
class OfficeArtFBSE {
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
        _s = _s + "btWin32: " + String.valueOf(btWin32) + "(" + Integer.toHexString(btWin32).toUpperCase() + "), ";
        _s = _s + "btMacOS: " + String.valueOf(btMacOS) + "(" + Integer.toHexString(btMacOS).toUpperCase() + "), ";
        _s = _s + "rgbUid: " + String.valueOf(rgbUid) + ", ";
        _s = _s + "tag: " + String.valueOf(tag) + "(" + Integer.toHexString(tag).toUpperCase() + "), ";
        _s = _s + "size: " + String.valueOf(size) + "(" + Integer.toHexString(size).toUpperCase() + "), ";
        _s = _s + "cRef: " + String.valueOf(cRef) + "(" + Integer.toHexString(cRef).toUpperCase() + "), ";
        _s = _s + "foDelay: " + String.valueOf(foDelay) + "(" + Integer.toHexString(foDelay).toUpperCase() + "), ";
        _s = _s + "unused1: " + String.valueOf(unused1) + "(" + Integer.toHexString(unused1).toUpperCase() + "), ";
        _s = _s + "cbName: " + String.valueOf(cbName) + "(" + Integer.toHexString(cbName).toUpperCase() + "), ";
        _s = _s + "unused2: " + String.valueOf(unused2) + "(" + Integer.toHexString(unused2).toUpperCase() + "), ";
        _s = _s + "unused3: " + String.valueOf(unused3) + "(" + Integer.toHexString(unused3).toUpperCase() + "), ";
        _s = _s + "nameData: " + String.valueOf(nameData) + ", ";
        _s = _s + "embeddedBlip: " + String.valueOf(embeddedBlip) + ", ";
        return _s;
    }
}
class OfficeArtBStoreContainerFileBlock {
    Object anon;
    public String toString() {
        String _s = "OfficeArtBStoreContainerFileBlock:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class SlideViewInfoInstance {
    RecordHeader rh;
    SlideViewInfoAtom slideViewInfoAtom;
    ZoomViewInfoAtom zoomViewInfoAtom;
    final java.util.List<GuideAtom> rgGuideAtom = new java.util.ArrayList<GuideAtom>();
    public String toString() {
        String _s = "SlideViewInfoInstance:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slideViewInfoAtom: " + String.valueOf(slideViewInfoAtom) + ", ";
        _s = _s + "zoomViewInfoAtom: " + String.valueOf(zoomViewInfoAtom) + ", ";
        _s = _s + "rgGuideAtom: " + String.valueOf(rgGuideAtom) + ", ";
        return _s;
    }
}
class DocumentTextInfoContainer {
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
class DrawingGroupContainer {
    RecordHeader rh;
    OfficeArtDggContainer OfficeArtDgg;
    public String toString() {
        String _s = "DrawingGroupContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "OfficeArtDgg: " + String.valueOf(OfficeArtDgg) + ", ";
        return _s;
    }
}
class OfficeArtSpContainer {
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
    OfficeArtSecondaryFOPT shapeSecondaryOptions2;
    OfficeArtTertiaryFOPT shapeTertiaryOptions2;
    public String toString() {
        String _s = "OfficeArtSpContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "shapeGroup: " + String.valueOf(shapeGroup) + ", ";
        _s = _s + "shapeProp: " + String.valueOf(shapeProp) + ", ";
        _s = _s + "deletedshape: " + String.valueOf(deletedshape) + ", ";
        _s = _s + "shapePrimaryOptions: " + String.valueOf(shapePrimaryOptions) + ", ";
        _s = _s + "shapeSecondaryOptions1: " + String.valueOf(shapeSecondaryOptions1) + ", ";
        _s = _s + "shapeTertiaryOptions1: " + String.valueOf(shapeTertiaryOptions1) + ", ";
        _s = _s + "childAnchor: " + String.valueOf(childAnchor) + ", ";
        _s = _s + "clientAnchor: " + String.valueOf(clientAnchor) + ", ";
        _s = _s + "clientData: " + String.valueOf(clientData) + ", ";
        _s = _s + "clientTextbox: " + String.valueOf(clientTextbox) + ", ";
        _s = _s + "shapeSecondaryOptions2: " + String.valueOf(shapeSecondaryOptions2) + ", ";
        _s = _s + "shapeTertiaryOptions2: " + String.valueOf(shapeTertiaryOptions2) + ", ";
        return _s;
    }
}
class DocumentContainer {
    RecordHeader rh;
    DocumentAtom documentAtom;
    ExObjListContainer exObjList;
    DocumentTextInfoContainer documentTextInfo;
    SoundCollectionContainer soundCollection;
    DrawingGroupContainer drawingGroup;
    MasterListWithTextContainer masterList;
    DocInfoListContainer docInfoList;
    SlideHeadersFootersContainer slideHF;
    NotesHeadersFootersContainer notesHF;
    SlideListWithTextContainer slideList;
    SlideHeadersFootersContainer slideHF2;
    NotesListWithTextContainer notesList;
    SlideShowDocInfoAtom slideShowDocInfoAtom;
    NamedShowsContainer namedShows;
    SummaryContainer summary;
    DocRoutingSlipAtom docRoutingSlipAtom;
    PrintOptionsAtom printOptionsAtom;
    RoundTripCustomTableStyles12Atom rtCustomTableStylesAtom1;
    UnknownDocumentContainerChild unknown1;
    EndDocumentAtom endDocumentAtom;
    UnknownDocumentContainerChild3 unknown2;
    UnknownDocumentContainerChild2 unknown3;
    UnknownDocumentContainerChild3 unknown4;
    UnknownDocumentContainerChild4 unknown5;
    RoundTripCustomTableStyles12Atom rtCustomTableStylesAtom2;
    public String toString() {
        String _s = "DocumentContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "documentAtom: " + String.valueOf(documentAtom) + ", ";
        _s = _s + "exObjList: " + String.valueOf(exObjList) + ", ";
        _s = _s + "documentTextInfo: " + String.valueOf(documentTextInfo) + ", ";
        _s = _s + "soundCollection: " + String.valueOf(soundCollection) + ", ";
        _s = _s + "drawingGroup: " + String.valueOf(drawingGroup) + ", ";
        _s = _s + "masterList: " + String.valueOf(masterList) + ", ";
        _s = _s + "docInfoList: " + String.valueOf(docInfoList) + ", ";
        _s = _s + "slideHF: " + String.valueOf(slideHF) + ", ";
        _s = _s + "notesHF: " + String.valueOf(notesHF) + ", ";
        _s = _s + "slideList: " + String.valueOf(slideList) + ", ";
        _s = _s + "slideHF2: " + String.valueOf(slideHF2) + ", ";
        _s = _s + "notesList: " + String.valueOf(notesList) + ", ";
        _s = _s + "slideShowDocInfoAtom: " + String.valueOf(slideShowDocInfoAtom) + ", ";
        _s = _s + "namedShows: " + String.valueOf(namedShows) + ", ";
        _s = _s + "summary: " + String.valueOf(summary) + ", ";
        _s = _s + "docRoutingSlipAtom: " + String.valueOf(docRoutingSlipAtom) + ", ";
        _s = _s + "printOptionsAtom: " + String.valueOf(printOptionsAtom) + ", ";
        _s = _s + "rtCustomTableStylesAtom1: " + String.valueOf(rtCustomTableStylesAtom1) + ", ";
        _s = _s + "unknown1: " + String.valueOf(unknown1) + ", ";
        _s = _s + "endDocumentAtom: " + String.valueOf(endDocumentAtom) + ", ";
        _s = _s + "unknown2: " + String.valueOf(unknown2) + ", ";
        _s = _s + "unknown3: " + String.valueOf(unknown3) + ", ";
        _s = _s + "unknown4: " + String.valueOf(unknown4) + ", ";
        _s = _s + "unknown5: " + String.valueOf(unknown5) + ", ";
        _s = _s + "rtCustomTableStylesAtom2: " + String.valueOf(rtCustomTableStylesAtom2) + ", ";
        return _s;
    }
}
class DocInfoListSubContainerOrAtom {
    Object anon;
    public String toString() {
        String _s = "DocInfoListSubContainerOrAtom:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class OfficeArtDgContainer {
    OfficeArtRecordHeader rh;
    OfficeArtFDG drawingData;
    OfficeArtFRITContainer regroupItems;
    OfficeArtSpgrContainer groupShape;
    OfficeArtSpContainer shape;
    final java.util.List<OfficeArtSpgrContainerFileBlock> deletedShapes = new java.util.ArrayList<OfficeArtSpgrContainerFileBlock>();
    OfficeArtSolverContainer solvers;
    public String toString() {
        String _s = "OfficeArtDgContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "drawingData: " + String.valueOf(drawingData) + ", ";
        _s = _s + "regroupItems: " + String.valueOf(regroupItems) + ", ";
        _s = _s + "groupShape: " + String.valueOf(groupShape) + ", ";
        _s = _s + "shape: " + String.valueOf(shape) + ", ";
        _s = _s + "deletedShapes: " + String.valueOf(deletedShapes) + ", ";
        _s = _s + "solvers: " + String.valueOf(solvers) + ", ";
        return _s;
    }
}
class OfficeArtSpgrContainerFileBlock {
    Object anon;
    public String toString() {
        String _s = "OfficeArtSpgrContainerFileBlock:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class DrawingContainer {
    RecordHeader rh;
    OfficeArtDgContainer OfficeArtDg;
    public String toString() {
        String _s = "DrawingContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "OfficeArtDg: " + String.valueOf(OfficeArtDg) + ", ";
        return _s;
    }
}
class MainMasterContainer {
    RecordHeader rh;
    SlideAtom slideAtom;
    SlideShowSlideInfoAtom unknown;
    final java.util.List<SchemeListElementColorSchemeAtom> rgSchemeListElementColorScheme = new java.util.ArrayList<SchemeListElementColorSchemeAtom>();
    final java.util.List<TextMasterStyleAtom> rgTextMasterStyle = new java.util.ArrayList<TextMasterStyleAtom>();
    RoundTripOArtTextStyles12Atom roundTripOArtTextSTyles12Atom;
    SlideShowSlideInfoAtom slideShowInfoAtom;
    PerSlideHeadersFootersContainer perSlideHeadersFootersContainer;
    DrawingContainer drawing;
    SlideSchemeColorSchemeAtom slideSchemeColorSchemeAtom;
    SlideNameAtom slideNameAtom;
    SlideProgTagsContainer slideProgTagsContainer;
    final java.util.List<RoundTripMainMasterRecord> rgRoundTripMainMaster = new java.util.ArrayList<RoundTripMainMasterRecord>();
    UnknownSlideContainerChild unknown2;
    TemplateNameAtom templateNameAtom;
    SlideProgTagsContainer unknown3;
    public String toString() {
        String _s = "MainMasterContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slideAtom: " + String.valueOf(slideAtom) + ", ";
        _s = _s + "unknown: " + String.valueOf(unknown) + ", ";
        _s = _s + "rgSchemeListElementColorScheme: " + String.valueOf(rgSchemeListElementColorScheme) + ", ";
        _s = _s + "rgTextMasterStyle: " + String.valueOf(rgTextMasterStyle) + ", ";
        _s = _s + "roundTripOArtTextSTyles12Atom: " + String.valueOf(roundTripOArtTextSTyles12Atom) + ", ";
        _s = _s + "slideShowInfoAtom: " + String.valueOf(slideShowInfoAtom) + ", ";
        _s = _s + "perSlideHeadersFootersContainer: " + String.valueOf(perSlideHeadersFootersContainer) + ", ";
        _s = _s + "drawing: " + String.valueOf(drawing) + ", ";
        _s = _s + "slideSchemeColorSchemeAtom: " + String.valueOf(slideSchemeColorSchemeAtom) + ", ";
        _s = _s + "slideNameAtom: " + String.valueOf(slideNameAtom) + ", ";
        _s = _s + "slideProgTagsContainer: " + String.valueOf(slideProgTagsContainer) + ", ";
        _s = _s + "rgRoundTripMainMaster: " + String.valueOf(rgRoundTripMainMaster) + ", ";
        _s = _s + "unknown2: " + String.valueOf(unknown2) + ", ";
        _s = _s + "templateNameAtom: " + String.valueOf(templateNameAtom) + ", ";
        _s = _s + "unknown3: " + String.valueOf(unknown3) + ", ";
        return _s;
    }
}
class SlideContainer {
    RecordHeader rh;
    SlideAtom slideAtom;
    SlideShowSlideInfoAtom slideShowSlideInfoAtom;
    PerSlideHeadersFootersContainer perSlideHFContainer;
    RoundTripSlideSyncInfo12Container rtSlideSyncInfo12;
    DrawingContainer drawing;
    SlideSchemeColorSchemeAtom slideSchemeColorSchemeAtom;
    SlideNameAtom slideNameAtom;
    SlideProgTagscontainer slideProgTagsContainer;
    final java.util.List<RoundTripSlideRecord> rgRoundTripSlide = new java.util.ArrayList<RoundTripSlideRecord>();
    UnknownSlideContainerChild unknown;
    public String toString() {
        String _s = "SlideContainer:";
        _s = _s + "rh: " + String.valueOf(rh) + ", ";
        _s = _s + "slideAtom: " + String.valueOf(slideAtom) + ", ";
        _s = _s + "slideShowSlideInfoAtom: " + String.valueOf(slideShowSlideInfoAtom) + ", ";
        _s = _s + "perSlideHFContainer: " + String.valueOf(perSlideHFContainer) + ", ";
        _s = _s + "rtSlideSyncInfo12: " + String.valueOf(rtSlideSyncInfo12) + ", ";
        _s = _s + "drawing: " + String.valueOf(drawing) + ", ";
        _s = _s + "slideSchemeColorSchemeAtom: " + String.valueOf(slideSchemeColorSchemeAtom) + ", ";
        _s = _s + "slideNameAtom: " + String.valueOf(slideNameAtom) + ", ";
        _s = _s + "slideProgTagsContainer: " + String.valueOf(slideProgTagsContainer) + ", ";
        _s = _s + "rgRoundTripSlide: " + String.valueOf(rgRoundTripSlide) + ", ";
        _s = _s + "unknown: " + String.valueOf(unknown) + ", ";
        return _s;
    }
}
class MasterOrSlideContainer {
    Object anon;
    public String toString() {
        String _s = "MasterOrSlideContainer:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
class PowerPointStruct {
    Object anon;
    public String toString() {
        String _s = "PowerPointStruct:";
        _s = _s + "anon: " + String.valueOf(anon) + ", ";
        return _s;
    }
}
