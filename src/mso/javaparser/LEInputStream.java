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

		public Object setMark() {
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

	int uint4leftover;

	public LEInputStream(InputStream i) {
		rewindableInputStream = new RewindableInputStream(i);
		input = new DataInputStream(rewindableInputStream);
	}

	public Object setMark() {
		return rewindableInputStream.setMark();
	}

	public void releaseMark(Object mark) {
		rewindableInputStream.releaseMark(mark);
	}

	public void rewind(Object mark) throws IOException {
		rewindableInputStream.rewind(mark);
	}

	public int getNumberOfMarks() {
		return rewindableInputStream.marks.size();
	}

	public boolean atEnd() throws IOException {
		return input.available() == 0;
	}

	public byte readuint4() throws IOException {
		// TODO: we only support reading uint4 then uint12, make this general if
		// needed
		uint4leftover = Short.reverseBytes(input.readShort());
		return (byte) (uint4leftover & 0xF);
	}

	public byte readuint8() throws IOException {
		return input.readByte();
	}

	public short readuint12() throws IOException {
		short s = (short) uint4leftover;
		s = (short) (s >> 4);
		return s;
	}

	public short readint16() throws IOException {
		return Short.reverseBytes(input.readShort());
	}

	public int readuint16() throws IOException {
		int s = Short.reverseBytes(input.readShort());
		if (s < 0)
			s = 0x10000 + s;
		return s;
	}

	public int readuint32() throws IOException {
		return Integer.reverseBytes(input.readInt());
	}

	public int readint32() throws IOException {
		return Integer.reverseBytes(input.readInt());
	}
}
