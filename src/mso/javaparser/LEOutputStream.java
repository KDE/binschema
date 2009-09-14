package mso.javaparser;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;

/**
 * byte = int8 short = int16 char = uint16 int = int32 long = int64
 */
public class LEOutputStream {

	final DataOutputStream output;

	int bitfield;
	int bitfieldpos;

	public LEOutputStream(OutputStream o) {
		output = new DataOutputStream(o);
		bitfieldpos = 0;
	}

	private void writeBits(int n, int v) throws IOException {
		bitfield = v << bitfieldpos | bitfield;
		bitfieldpos += n;
		if (bitfieldpos == 8) {
			output.write(bitfield);
			bitfield = 0;
			bitfieldpos = 0;
		} else if (bitfieldpos > 8) {
			throw new IOException("bitfield does not have enough bits left");
		}
	}

	private void checkForLeftOverBits() throws IOException {
		if (bitfieldpos > 0)
			throw new IOException(
					"Cannot write this type halfway through a bit operation.");
		if (output.size() >= 424) {
			int p = output.size();
		}
	}

	public void writebit(boolean v) throws IOException {
		writeBits(1, (v) ? 1 : 0);
	}

	public void writeuint2(byte v) throws IOException {
		writeBits(2, v);
	}

	public void writeuint3(byte v) throws IOException {
		writeBits(3, v);
	}

	public void writeuint4(byte v) throws IOException {
		writeBits(4, v);
	}

	public void writeuint5(byte v) throws IOException {
		writeBits(5, v);
	}

	public void writeuint6(byte v) throws IOException {
		writeBits(6, v);
	}

	public void writeuint7(byte v) throws IOException {
		writeBits(7, v);
	}

	public void writeuint9(short v) throws IOException {
		output.write(v);
		writeBits(1, v >> 8);
	}

	public void writeuint12(short v) throws IOException {
		writeBits(4, v);
		output.write(v >> 4);
	}

	public void writeuint14(short v) throws IOException {
		if (bitfieldpos == 0) {
			output.write(v);
			writeBits(6, v >> 8);
		} else if (bitfieldpos == 2) {
			writeBits(6, v);
			output.write(v >> 6);
		} else {
			throw new IOException(
					"Cannot write this type halfway through a bit operation as position "
							+ output.size());
		}
	}

	public void writeuint15(short v) throws IOException {
		// we assume there are 7 bits left
		writeBits(7, v);
		output.write(v >> 7);
	}

	public void writeuint20(int v) throws IOException {
		if (bitfieldpos == 0) {
			output.write(v);
			output.write(v >> 8);
			writeBits(4, v >> 16);
		} else if (bitfieldpos == 4) {
			writeBits(4, v);
			output.write(v >> 4);
			output.write(v >> 12);
		} else {
			throw new IOException(
					"Cannot write this type halfway through a bit operation.");
		}
	}

	public void writeuint30(int v) throws IOException {
		checkForLeftOverBits();
		output.write(v);
		output.write(v >> 8);
		output.write(v >> 16);
		writeBits(6, v >> 24);
	}

	public void writeuint8(byte v) throws IOException {
		checkForLeftOverBits();
		output.write(v);
	}

	public void writeint16(short v) throws IOException {
		checkForLeftOverBits();
		output.write(v);
		output.write(v >> 8);
	}

	public void writeuint16(int v) throws IOException {
		checkForLeftOverBits();
		output.write(v);
		output.write(v >> 8);
	}

	public void writeuint32(int v) throws IOException {
		checkForLeftOverBits();
		output.write(v);
		output.write(v >> 8);
		output.write(v >> 16);
		output.write(v >> 24);
	}

	public void writeint32(int v) throws IOException {
		checkForLeftOverBits();
		output.writeInt(Integer.reverseBytes(v));
	}

	public int getPosition() {
		return output.size();
	}

	public void close() throws IOException {
		output.close();
	}
}
