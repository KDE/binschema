package mso.generator;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.Map;

import javax.xml.parsers.DocumentBuilderFactory;

import mso.generator.utils.ParserGeneratorUtils;
import mso.javaparser.LEInputStream;

import org.apache.poi.poifs.filesystem.DirectoryEntry;
import org.apache.poi.poifs.filesystem.DocumentEntry;
import org.apache.poi.poifs.filesystem.DocumentInputStream;
import org.apache.poi.poifs.filesystem.Entry;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;
import org.w3c.dom.Document;

public class PPTStructurePrinter {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		final String xmlfilename = "src/mso.xml";
		String testfile = "/tmp/mp00_RomanBulletsnumber.ppt";
		PPTStructurePrinter p = new PPTStructurePrinter();

		final Document dom = DocumentBuilderFactory.newInstance()
				.newDocumentBuilder().parse(xmlfilename);
		Map<Integer, String> recordTypeNames = ParserGeneratorUtils
				.getRecordTypeNames(dom);
		PrintStream out = System.out;
		out = new PrintStream(new FileOutputStream("/tmp/out"));
		p.parse(testfile, recordTypeNames, out);
	}

	public void parse(String filepath, Map<Integer, String> recordTypeNames,
			PrintStream out) throws IOException {
		POIFSFileSystem fs = new POIFSFileSystem(new FileInputStream(filepath));
		DirectoryEntry root = fs.getRoot();
		try {
			root = (DirectoryEntry) root.getEntry("PP97_DUALSTORAGE");
		} catch (FileNotFoundException e) {
		}
		parse(root, recordTypeNames, out);
	}

	void parse(DirectoryEntry dir, Map<Integer, String> recordTypeNames,
			PrintStream out) throws IOException {
		for (Iterator<Entry> iter = dir.getEntries(); iter.hasNext();) {
			Entry entry = (Entry) iter.next();
			if (entry instanceof DirectoryEntry) {
				out.println("found directory entry: " + entry.getName());
			} else if (entry instanceof DocumentEntry) {
				DocumentEntry e = (DocumentEntry) entry;
				DocumentInputStream in = new DocumentInputStream(e);
				byte datain[] = new byte[e.getSize()];
				if (datain.length != in.read(datain, 0, datain.length)) {
					in.close();
					throw new IOException("could not read all data");
				}
				in.close();
				LEInputStream le = new LEInputStream(datain);

				out.println("found document entry: " + entry.getName()
						+ " of length " + e.getSize());
				try {
					while (le.getPosition() != e.getSize()) {
						printStructure(le, 0, recordTypeNames, out);
					}
				} catch (IOException ex) {
					out.println("abrupt end");
				}
			}
		}
	}

	void printStructure(LEInputStream in, int depth,
			Map<Integer, String> recordTypeNames, PrintStream out)
					throws IOException {
		int recVer = in.readuint4();
		int recInstance = in.readuint12();
		int recType = in.readuint16();
		int recLen = in.readuint32();

		String hexinstance = Integer.toHexString(recInstance).toUpperCase();
		String hextype = Integer.toHexString(recType).toUpperCase();

		String t = "\t\t";
		String name = recordTypeNames.containsKey(recType)
				? recordTypeNames.get(recType) : "";
		out.println(depth + t + recVer + t + hexinstance + t + hextype + t
				+ recLen + t + in.getPosition() + t + name);
		if (recVer == 0xF && recType != 0x428) {
			int end = in.getPosition() + recLen;
			while (in.getPosition() != end) {
				if (in.getPosition() > end) {
					String msg = in.getPosition() + " > " + end;
					out.println(msg);
					throw new IOException(msg);
				}
				printStructure(in, depth + 1, recordTypeNames, out);
			}
		} else {
			for (int i = 0; i < recLen; ++i) {
				in.readuint8();
			}
		}
	}
}
