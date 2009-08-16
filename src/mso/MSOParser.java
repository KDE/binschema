package mso;

import java.io.FileInputStream;
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
		
		//if (test()) return;
		
		GeneratedMsoParser parser = new GeneratedMsoParser();
		POIFSFileSystem fs = new POIFSFileSystem(new FileInputStream(filepath));
		DirectoryEntry root = fs.getRoot();

		for (Iterator iter = root.getEntries(); iter.hasNext();) {
			Entry entry = (Entry) iter.next();
			if (entry instanceof DirectoryEntry) {
				System.out.println("found dir entry: " + entry.getName());
			} else if (entry instanceof DocumentEntry) {
				DocumentEntry e = (DocumentEntry) entry;
				System.out.println("found entry: " + e.getName() + " "
						+ e.getSize());
				DocumentInputStream in = new DocumentInputStream(e);
				LEInputStream le = new LEInputStream(in);
				boolean parsed = parser.parse(e.getName(), le);
			//	if (parsed && in.available() > 0) {
			//		throw new IOException("trailing data in stream " + in.available());
			//	}
			}
		}
	}

	static boolean test() {
		int i = 3;
		System.out.println(i << 3);
		return true;
	}
}
