package mso.javaparser;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator;

import org.apache.poi.poifs.filesystem.DirectoryEntry;
import org.apache.poi.poifs.filesystem.DocumentEntry;
import org.apache.poi.poifs.filesystem.DocumentInputStream;
import org.apache.poi.poifs.filesystem.Entry;
import org.apache.poi.poifs.filesystem.POIFSFileSystem;

public class MSOParser {
	@SuppressWarnings("unchecked")
	public void parse(String filepath) throws IOException {

		// if (test()) return;

		GeneratedMsoParser parser = new GeneratedMsoParser();
		POIFSFileSystem fs = new POIFSFileSystem(new FileInputStream(filepath));
		DirectoryEntry root = fs.getRoot();

		for (Iterator iter = root.getEntries(); iter.hasNext();) {
			Entry entry = (Entry) iter.next();
			if (entry instanceof DirectoryEntry) {
				System.out.println("found dir entry: " + entry.getName());
			} else if (entry instanceof DocumentEntry) {
				DocumentEntry e = (DocumentEntry) entry;
				save("/tmp", e);
				System.out.println("found entry: " + e.getName() + " "
						+ e.getSize());
				DocumentInputStream in = new DocumentInputStream(e);
				LEInputStream le = new LEInputStream(in);
				parser.parse(e.getName(), le);
				if (in.available() > 0) {
					throw new IOException("trailing data in stream "
							+ e.getName() + ": " + in.available() + " bytes");
				}
			}
		}
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
