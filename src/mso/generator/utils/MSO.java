package mso.generator.utils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.jdt.annotation.NonNullByDefault;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

@NonNullByDefault
public class MSO {
	public final List<Struct> structs;
	public final List<Stream> streams;

	public static MSO parse(Document dom) throws IOException {
		final TypeRegistry typeRegistry = new TypeRegistry();
		final List<Struct> structs = new ArrayList<Struct>();
		final List<Stream> streams = new ArrayList<Stream>();

		// retrieve all the structs
		List<Element> orderedElements = ParserGeneratorUtils
				.getOrderedStructureList(dom);
		for (Element e : orderedElements) {
			String typeName = e.getAttribute("name");
			Type t = typeRegistry.getType(typeName);
			Struct s = null;
			if (t instanceof Struct) {
				s = (Struct) t;
			} else {
				s = new Struct(typeRegistry, e);
			}
			structs.add(s);
		}
		// check that all members have a non-null type
		for (Struct s : structs) {
			for (Member m : s.members) {
				if (m.type() == null) {
					throw new Error("Member " + m.name + " of structure "
							+ s.name + " has no parsed type.");
				}
			}
		}

		NodeList l = dom.getElementsByTagName("stream");
		for (int i = 0; i < l.getLength(); ++i) {
			streams.add(new Stream((Element) l.item(i)));
		}
		return new MSO(structs, streams);
	}

	private MSO(List<Struct> structs, List<Stream> streams) {
		this.structs = structs;
		this.streams = streams;
	}
}