package mso.javaparser;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.LinkedList;

/**
 * byte = int8 short = int16 char = uint16 int = int32 long = int64
 */
public class LEInputStream {

	class RewindableInputStream extends InputStream {

		int[] buffer = new int[64];

		int pos;

		int bytesInBuffer;

		final LinkedList<Integer> marks = new LinkedList<Integer>();

		final InputStream input;

		RewindableInputStream(InputStream in) {
			input = in;
			pos = -1;
		}

		@Override
		public int read() throws IOException {
			if (pos < 0)
				// no mark is set and no data in the buffer
				return input.read();

			if (pos == bytesInBuffer) {
				if (marks.size() == 0) {
					// buffer is depleted, going back to passing data directly
					pos = -1;
					return input.read();
				}
				if (pos == buffer.length) {
					buffer = Arrays.copyOf(buffer, 2 * buffer.length);
				}
				buffer[pos] = input.read();
				bytesInBuffer++;
			}

			return buffer[pos++];
		}

		public Integer setMark() {
			Integer mark;
			if (marks.size() == 0) {
				mark = pos = bytesInBuffer = 0;
			} else {
				mark = pos;
			}
			marks.add(mark);
			return mark;
		}

		public void releaseMark(Object mark) {
			Integer m = marks.removeLast();
			if (m != mark) {
				throw new Error("Logic error: mark was not set.");
			}
		}

		public void rewind(Object mark) throws IOException {
			Integer m = marks.getLast();
			if (m != mark) {
				System.out.println("marks size:" + marks.size());
				throw new Error("Logic error: mark was not set. " + m + " "
						+ mark);
			}
			pos = m;
		}

	}

	final RewindableInputStream rewindableInputStream;
	final DataInputStream input;
	int pos;

	private class Mark {
		final public Integer pos;

		Mark(Integer p) {
			pos = p;
		}
	}

	int bitfield;
	int bitfieldpos;

	public LEInputStream(InputStream i) {
		rewindableInputStream = new RewindableInputStream(i);
		input = new DataInputStream(rewindableInputStream);
		bitfieldpos = -1;
		pos = 0;
	}

	public Mark setMark() {
		return new Mark(rewindableInputStream.setMark());
	}

	public void releaseMark(Object mark) {
		Mark m = (Mark) mark;
		rewindableInputStream.releaseMark(m.pos);
	}

	public int distanceFromMark(Object mark) {
		Mark m = (Mark) mark;
		return rewindableInputStream.pos - m.pos;
	}

	public void rewind(Object m) throws IOException {
		Mark mark = (Mark) m;
		pos -= rewindableInputStream.pos - mark.pos;
		rewindableInputStream.rewind(mark.pos);
	}

	public boolean atEnd() throws IOException {
		return input.available() == 0;
	}

	private int getBits(int n) throws IOException {
		if (bitfieldpos < 0) {
			bitfield = input.readByte();
			pos++;
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

	private void checkForLeftOverBits() throws IOException {
		if (bitfieldpos >= 0)
			throw new IOException(
					"Cannot read this type halfway through a bit operation.");
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
		int a = input.readByte();
		int b = getBits(1) & 0x1;
		pos++;
		int v = (b << 8) | a;
		return (short) v;
	}

	public short readuint12() throws IOException {
		// we assume there are 4 bits left
		int a = getBits(4) & 0xF;
		int b = input.readByte();
		pos++;
		int v = (b << 4) | a;
		return (short) v;
	}

	public short readuint14() throws IOException {
		int v;
		if (bitfieldpos < 0) {
			int a = input.readByte();
			pos++;
			int b = getBits(6) & 0x3F;
			v = (b << 8) | a;
		} else if (bitfieldpos == 2) {
			int a = getBits(6) & 0x3F;
			int b = input.readByte();
			pos++;
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
		int b = input.readByte();
		pos++;
		int v = (b << 7) | a;
		return (short) v;
	}

	public int readuint20() throws IOException {
		int v;
		if (bitfieldpos < 0) {
			int a = input.readByte();
			int b = input.readByte();
			pos += 2;
			int c = getBits(4) & 0xF;
			v = (c << 16) | (b << 8) | a;
		} else if (bitfieldpos == 4) {
			int a = getBits(4) & 0xF;
			int b = input.readByte();
			int c = input.readByte();
			pos += 2;
			v = (c << 12) | (b << 4) | a;
		} else {
			throw new IOException(
					"Cannot read this type halfway through a bit operation.");
		}
		return v;
	}

	public int readuint30() throws IOException {
		checkForLeftOverBits();
		int a = input.readByte();
		int b = input.readByte();
		int c = input.readByte();
		pos += 3;
		int d = getBits(6) & 0x3F;
		int v = (d << 24) | (c << 16) | (b << 8) | a;
		return v;
	}

	public byte readuint8() throws IOException {
		checkForLeftOverBits();
		pos++;
		return input.readByte();
	}

	public short readint16() throws IOException {
		checkForLeftOverBits();
		pos += 2;
		return Short.reverseBytes(input.readShort());
	}

	public int readuint16() throws IOException {
		checkForLeftOverBits();
		pos += 2;
		int s = Short.reverseBytes(input.readShort());
		if (s < 0)
			s = 0x10000 + s;
		return s;
	}

	public int readuint32() throws IOException {
		checkForLeftOverBits();
		pos += 4;
		return Integer.reverseBytes(input.readInt());
	}

	public int readint32() throws IOException {
		checkForLeftOverBits();
		pos += 4;
		return Integer.reverseBytes(input.readInt());
	}

	public int getPosition() {
		return pos;
	}
}
