package mso.javaparser;

import java.io.IOException;

import org.eclipse.jdt.annotation.NonNullByDefault;

@NonNullByDefault
public class ParserTester {

	public static void main(String[] args) throws IOException {
		// String testfile = "/home/oever/oever/Mir/Claessens-Delft-2007b.ppt";
		// String testfile =
		// "/home/oever/oever/Desktop/Biophysical Techniques Week1_Mir.ppt";
		// String testfile = "tests/data/simpleimageslide.ppt";
		// String testfile ="/home/oever/pdfs/vinod/Biblio/2006 SMA Ian.ppt";
		String testfile = "tests/data/diagram.ppt";
		MSOParser p = new MSOParser();
		p.parse(testfile);
	}

}
