package mso.javaparser;

import java.io.EOFException;
import java.io.IOException;
import java.util.Arrays;

/**
 * byte = int8 short = int16 char = uint16 int = int32 long = int64
 */
public class LEInputStream {

	final byte data[];
	int pos;

	private class Mark {
		final public Integer pos;

		Mark(Integer p) {
			pos = p;
		}
	}

	int bitfield;
	int bitfieldpos;

	public LEInputStream(byte d[]) {
		data = d;
		bitfieldpos = -1;
		pos = 0;
	}

	public Mark setMark() {
		return new Mark(pos);
	}

	public void releaseMark(Object mark) {
	}

	public int distanceFromMark(Object mark) {
		Mark m = (Mark) mark;
		return pos - m.pos;
	}

	public void rewind(Object m) {
		Mark mark = (Mark) m;
		pos = mark.pos;
	}

	public boolean atEnd() {
		return pos == data.length;
	}

	private int getBits(int n) throws IOException {
		if (bitfieldpos < 0) {
			bitfield = readUnsignedByte();
			bitfieldpos = 0;
		}
		int v = bitfield >> bitfieldpos;
		bitfieldpos += n;
		if (bitfieldpos == 8) {
			bitfieldpos = -1;
		} else if (bitfieldpos > 8) {
			throw new IOException("bitfield does not have enough bits left");
		}
		return v;
	}

	private int readUnsignedByte() throws IOException {
		if (bitfieldpos >= 0)
			throw new IOException(
					"Cannot read this type halfway through a bit operation.");
		if (pos >= data.length)
			throw new EOFException();
		int v = data[pos++];
		if (v < 0)
			v = 0x100 + v;
		return v;
	}

	public boolean readbit() throws IOException {
		int v = getBits(1) & 1;
		return v == 1;
	}

	public byte readuint2() throws IOException {
		int v = getBits(2) & 3;
		return (byte) v;
	}

	public byte readuint3() throws IOException {
		int v = getBits(3) & 0x7;
		return (byte) v;
	}

	public byte readuint4() throws IOException {
		int v = getBits(4) & 0xF;
		return (byte) v;
	}

	public byte readuint5() throws IOException {
		int v = getBits(5) & 0x1F;
		return (byte) v;
	}

	public byte readuint6() throws IOException {
		int v = getBits(6) & 0x3F;
		return (byte) v;
	}

	public byte readuint7() throws IOException {
		int v = getBits(7) & 0x7F;
		return (byte) v;
	}

	public short readuint9() throws IOException {
		int a = readUnsignedByte();
		int b = getBits(1) & 0x1;
		int v = (b << 8) | a;
		return (short) v;
	}

	public short readuint12() throws IOException {
		// we assume there are 4 bits left
		int a = getBits(4) & 0xF;
		int b = readUnsignedByte();
		int v = (b << 4) | a;
		return (short) v;
	}

	public short readuint13() throws IOException {
		// we assume there are 5 bits left
		int a = getBits(5) & 0x1F;
		int b = readUnsignedByte();
		int v = (b << 5) | a;
		return (short) v;
	}

	public short readuint14() throws IOException {
		int v;
		if (bitfieldpos < 0) {
			int a = readUnsignedByte();
			int b = getBits(6) & 0x3F;
			v = (b << 8) | a;
		} else if (bitfieldpos == 2) {
			int a = getBits(6) & 0x3F;
			int b = readUnsignedByte();
			v = (b << 6) | a;
		} else {
			throw new IOException(
					"Cannot read this type halfway through a bit operation.");
		}
		return (short) v;
	}

	public short readuint15() throws IOException {
		// we assume there are 7 bits left
		int a = getBits(7) & 0x7F;
		int b = readUnsignedByte();
		int v = (b << 7) | a;
		return (short) v;
	}

	public int readuint20() throws IOException {
		int v;
		if (bitfieldpos < 0) {
			int a = readUnsignedByte();
			int b = readUnsignedByte();
			int c = getBits(4) & 0xF;
			v = (c << 16) | (b << 8) | a;
		} else if (bitfieldpos == 4) {
			int a = getBits(4) & 0xF;
			int b = readUnsignedByte();
			int c = readUnsignedByte();
			v = (c << 12) | (b << 4) | a;
		} else {
			throw new IOException(
					"Cannot read this type halfway through a bit operation.");
		}
		return v;
	}

	public int readuint30() throws IOException {
		int a = readUnsignedByte();
		int b = readUnsignedByte();
		int c = readUnsignedByte();
		int d = getBits(6) & 0x3F;
		int v = (d << 24) | (c << 16) | (b << 8) | a;
		return v;
	}

	public byte readuint8() throws IOException {
		return (byte) readUnsignedByte();
	}

	public short readint16() throws IOException {
		int a = readUnsignedByte();
		int b = readUnsignedByte();
		int v = (b << 8) | a;
		return (short) v;
	}

	public int readuint16() throws IOException {
		int a = readUnsignedByte();
		int b = readUnsignedByte();
		int v = (b << 8) | a;
		return v;
	}

	public int readuint32() throws IOException {
		int a = readUnsignedByte();
		int b = readUnsignedByte();
		int c = readUnsignedByte();
		int d = readUnsignedByte();
		int v = (d << 24) | (c << 16) | (b << 8) | a;
		return v;
	}

	public int readint32() throws IOException {
		int a = readUnsignedByte();
		int b = readUnsignedByte();
		int c = readUnsignedByte();
		int d = readUnsignedByte();
		int v = (d << 24) | (c << 16) | (b << 8) | a;
		return v;
	}

	public byte[] readBytes(int n) {
		pos += n;
		return Arrays.copyOfRange(data, pos - n, pos);
	}

	public int getPosition() {
		return pos;
	}

	public int getSize() {
		return data.length;
	}
}
