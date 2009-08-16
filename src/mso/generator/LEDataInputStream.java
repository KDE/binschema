package mso.generator;

import java.awt.image.BufferedImage;
import java.io.DataInputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.CodingErrorAction;

import javax.imageio.ImageIO;

public class LEDataInputStream implements SerializeReader {
	DataInputStream input;

	byte[] buffer;
	CharsetDecoder decoder;

	public LEDataInputStream(InputStream i, String encoding) {
		buffer = new byte[256];
		if (i instanceof DataInputStream) {
			input = (DataInputStream) i;
		} else {
			input = new DataInputStream(i);
		}
		decoder = Charset.forName(encoding).newDecoder();
		decoder.onMalformedInput(CodingErrorAction.REPORT);
		decoder.onUnmappableCharacter(CodingErrorAction.REPORT);
	}

	public void readuint4() throws IOException {}
	public void readuint12() throws IOException {}

	public int readInt() throws IOException {
		return Integer.reverseBytes(input.readInt());
	}

	public double readDouble() throws IOException {
		return Double.longBitsToDouble(Long.reverseBytes(input.readLong()));
	}

	public String readString() throws IOException {
		int numBytes = readInt();
		if (buffer.length < numBytes) {
			buffer = new byte[numBytes];
		}
		read(buffer, numBytes);
		ByteBuffer b = ByteBuffer.wrap(buffer, 0, numBytes);
		return decoder.reset().decode(b).toString();
	}

	public byte[] readByteArray() throws IOException {
		int length = readInt();
		if (length < 0) {
			throw new IOException("Could not read bytearray: negative length.");
		}
		byte b[] = new byte[length];
		read(b, length);
		return b;
	}

	public int[] readIntArray() throws IOException {
		int n = readInt();
		int array[] = new int[n];
		for (int i = 0; i < n; ++i) {
			array[i] = readInt();
		}
		return array;
	}

	public double[] readDoubleArray() throws IOException {
		int n = readInt();
		double array[] = new double[n];
		for (int i = 0; i < n; ++i) {
			array[i] = readDouble();
		}
		return array;
	}

	public String[] readStringArray() throws IOException {
		int n = readInt();
		String array[] = new String[n];
		for (int i = 0; i < n; ++i) {
			array[i] = readString();
		}
		return array;
	}

	/**
	 * The InputStream does not always read enough bytes, so we need to loop
	 * over it. This convenience function does this for us.
	 * 
	 * @param b
	 * @param length
	 * @throws IOException
	 */
	private void read(byte b[], int length) throws IOException {
		int done = 0;
		while (done < length) {
			int n = input.read(b, done, length - done);
			if (n <= 0) {
				throw new IOException(
						"Could not read bytearray: shorter than specified.");
			}
			done += n;
		}
	}

	/**
	 * Read image. This only works if the image is an uncompressed BMP image
	 * with 4 bytes per pixel. (http://en.wikipedia.org/wiki/BMP_file_format)
	 * 
	 * @return
	 * @throws IOException
	 */
	public BufferedImage readTBitmap() throws IOException {
		int numBytes = readInt();
		if (buffer.length < numBytes) {
			buffer = new byte[numBytes];
		}
		int n = input.read(buffer, 0, 10);
		if (n != 10) {
			throw new IOException(
					"Could not read bitmap: shorter than specified.");
		}
		input.skip(8);
		int width = readInt();
		int height = readInt();
		input.skip(28);

		BufferedImage image = new BufferedImage(width, height,
				BufferedImage.TYPE_INT_RGB);
		for (int y = height - 1; y >= 0; --y) {
			for (int x = 0; x < width; ++x) {
				image.setRGB(x, y, readInt());
			}
		}
		File outfile = new File("c:\\x.png");
		ImageIO.write(image, "png", outfile);
		return image;
	}

	@Override
	public boolean readBoolean() throws IOException {
		// TODO Auto-generated method stub
		return false;
	}
}
