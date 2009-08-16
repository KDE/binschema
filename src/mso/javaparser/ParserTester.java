package mso.javaparser;

import java.io.IOException;

public class ParserTester {

	public static void main(String[] args) throws IOException {
		String testfile = "/home/oever/oever/Mir/Claessens-Delft-2007b.ppt";
		//String testfile = "/home/oever/oever/Desktop/Biophysical Techniques Week1_Mir.ppt";
		MSOParser p = new MSOParser();
		p.parse(testfile);
	}

}
