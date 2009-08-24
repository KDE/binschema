package mso.generator;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Iterator;

import mso.javaparser.LEInputStream;

import org.apache.poi.poifs.filesystem.DirectoryEntry;
import org.apache.poi.poifs.filesystem.DocumentEntry;
import org.apache.poi.poifs.filesystem.DocumentInputStream;
import org.apache.poi.poifs.filesystem.Entry;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;

public class PPTStructurePrinter {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		String testfile = "tests/data/Important.ppt";
		PPTStructurePrinter p = new PPTStructurePrinter();
		p.parse(testfile);
	}

	@SuppressWarnings("unchecked")
	public void parse(String filepath) throws IOException {
		POIFSFileSystem fs = new POIFSFileSystem(new FileInputStream(filepath));
		DirectoryEntry root = fs.getRoot();

		for (Iterator iter = root.getEntries(); iter.hasNext();) {
			Entry entry = (Entry) iter.next();
			if (entry instanceof DirectoryEntry) {
				System.out.println("found directory entry: " + entry.getName());
			} else if (entry instanceof DocumentEntry) {
				DocumentEntry e = (DocumentEntry) entry;
				DocumentInputStream in = new DocumentInputStream(e);
				LEInputStream le = new LEInputStream(in);

				System.out.println("found document entry: " + entry.getName()
						+ " of length " + e.getSize());
				try {
					while (le.getPosition() != e.getSize()) {
						printStructure(le, 0);
					}
				} catch (IOException ex) {
					System.out.println("abrupt end");
				}
			}
		}
	}

	void printStructure(LEInputStream in, int depth) throws IOException {
		int recVer = in.readuint4();
		int recInstance = in.readuint12();
		int recType = in.readuint16();
		int recLen = in.readuint32();

		String hexinstance = Integer.toHexString(recInstance).toUpperCase();
		String hextype = Integer.toHexString(recType).toUpperCase();

		String t = "\t\t";
		System.out.println(depth + t + recVer + t + hexinstance + t + hextype
				+ t + recLen + t + in.getPosition());
		if (recVer == 0xF) {
			int end = in.getPosition() + recLen;
			while (in.getPosition() != end) {
				if (in.getPosition() > end) {
					String msg = in.getPosition() + " > " + end;
					System.out.println(msg);
					throw new IOException(msg);
				}
				printStructure(in, depth + 1);
			}
		} else {
			for (int i = 0; i < recLen; ++i) {
				in.readuint8();
			}
		}
	}
}
