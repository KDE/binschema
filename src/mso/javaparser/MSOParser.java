package mso.javaparser;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Iterator;

import org.apache.poi.poifs.filesystem.DirectoryEntry;
import org.apache.poi.poifs.filesystem.DocumentEntry;
import org.apache.poi.poifs.filesystem.DocumentInputStream;
import org.apache.poi.poifs.filesystem.Entry;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;

public class MSOParser {
	public void parse(String filepath) throws IOException {

		// if (test()) return;

		GeneratedMsoParser parser = new GeneratedMsoParser();
		POIFSFileSystem fs = new POIFSFileSystem(new FileInputStream(filepath));
		DirectoryEntry root = fs.getRoot();
		try {
			root = (DirectoryEntry) root.getEntry("PP97_DUALSTORAGE");
		} catch (FileNotFoundException e) {
		}

		parseDirectory(parser, root);
	}

	private void parseDirectory(GeneratedMsoParser parser, DirectoryEntry de)
			throws IOException {
		for (Iterator<Entry> iter = de.getEntries(); iter.hasNext();) {
			Entry entry = (Entry) iter.next();
			if (entry instanceof DirectoryEntry) {
				System.out.println("found dir entry: " + entry.getName());
			} else if (entry instanceof DocumentEntry) {
				DocumentEntry e = (DocumentEntry) entry;
				save("/tmp", e);
				System.out.println("found entry: " + e.getName() + " "
						+ e.getSize());
				DocumentInputStream in = new DocumentInputStream(e);
				byte datain[] = new byte[e.getSize()];
				if (datain.length != in.read(datain, 0, datain.length)) {
					throw new IOException("could not read all data");
				}
				LEInputStream lei = new LEInputStream(datain);
				String name = e.getName();
				Object mso = parser.parse(name, lei);
				if (lei.getPosition() != lei.getSize()) {
					// try {
					throw new IOException("trailing data in stream "
							+ e.getName() + ": "
							+ (lei.getSize() - lei.getPosition()) + " bytes");
					// } catch (Exception ex) {
					// System.out.println(ex.getMessage());
					// }
				}
				in.close();
				ByteArrayOutputStream out = new ByteArrayOutputStream();
				LEOutputStream leo = new LEOutputStream(out);
				parser.serialize(name, mso, leo);
				leo.close();
				out.close();
				byte dataout[] = out.toByteArray();
				writeData("/tmp/datain", datain);
				writeData("/tmp/dataout", dataout);
				int diffpos = 0;
				while (diffpos < datain.length
						&& datain[diffpos] == dataout[diffpos])
					diffpos++;
				if (diffpos < datain.length || diffpos < dataout.length) {
					System.err.println("in: " + e.getSize() + " out: "
							+ dataout.length + " diff at: " + diffpos);
					throw new IOException("missing data when writing stream.");
				}
			}
		}
	}

	private void writeData(String name, byte data[]) throws IOException {
		OutputStream out = new FileOutputStream(name);
		out.write(data);
		out.close();
	}

	public void save(String dir, DocumentEntry e) throws IOException {
		FileOutputStream f = new FileOutputStream(dir + "/" + e.getName());
		DocumentInputStream in = new DocumentInputStream(e);
		while (in.available() > 0) {
			f.write(in.read());
		}
		f.close();
		in.close();
	}

	static boolean test() {
		int i = 3;
		System.out.println(i << 3);
		return true;
	}
}
