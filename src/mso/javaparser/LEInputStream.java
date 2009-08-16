package mso.javaparser;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * byte = int8 short = int16 char = uint16 int = int32 long = int64
 */

public class LEInputStream {
	final DataInputStream originalinput;
	DataInputStream input;

	final LinkedList<ResettableInputStream> marks = new LinkedList<ResettableInputStream>();

	int uint4leftover;

	class ResettableInputStream extends InputStream {
		final DataInputStream input;
		int pos = 0;
		List<Integer> buffer = new ArrayList<Integer>();

		ResettableInputStream(DataInputStream i) {
			input = i;
		}

		@Override
		public int read() throws IOException {
			if (pos == buffer.size()) {
				buffer.add(input.read());
			}
			return buffer.get(pos++);
		}

		void resetStream() {
			pos = 0;
		}
	}

	public LEInputStream(InputStream i) {
		if (i instanceof DataInputStream) {
			originalinput = (DataInputStream) i;
		} else {
			originalinput = new DataInputStream(i);
		}
		input = originalinput;
	}

	public Object setMark() {
		ResettableInputStream m = new ResettableInputStream(input);
		marks.add(m);
		input = new DataInputStream(m);
		return m;
	}

	public void releaseMark(Object mark) {
		ResettableInputStream m = marks.removeLast();
		if (m != mark) {
			throw new Error("Logic error: mark was not set.");
		}
		input = m.input;
	}

	public void rewind(Object mark) throws IOException {
		ResettableInputStream m = marks.getLast();
		if (m != mark) {
			System.out.println("marks size:" + marks.size());
			throw new Error("Logic error: mark was not set. " + m + " " + mark);
		}
		m.resetStream();
	}

	public int getNumberOfMarks() {
		return marks.size();
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
