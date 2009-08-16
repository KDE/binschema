package mso.generator;

import java.io.IOException;

public interface SerializeReader {

	boolean readBoolean() throws IOException;

	int readInt() throws IOException;

	double readDouble() throws IOException;

	String readString() throws IOException;

	byte[] readByteArray() throws IOException;

	int[] readIntArray() throws IOException;

	double[] readDoubleArray() throws IOException;

	String[] readStringArray() throws IOException;
}
