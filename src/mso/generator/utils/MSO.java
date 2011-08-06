package mso.generator.utils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

public class MSO {
	public final List<Struct> structs = new ArrayList<Struct>();
	private final List<Choice> choices = new ArrayList<Choice>();
	public final List<Stream> streams = new ArrayList<Stream>();

	public MSO(Document dom) throws IOException {
		TypeRegistry typeRegistry = new TypeRegistry();

		// retrieve all the structs
		List<Element> orderedElements = ParserGeneratorUtils
				.getOrderedStructureList(dom);
		for (Element e : orderedElements) {
			String typeName = e.getAttribute("name");
			TypeRegistry.Type t = typeRegistry.getType(typeName);
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
		for (TypeRegistry.Type t : typeRegistry.types.values()) {
			if (t instanceof Choice) {
				choices.add((Choice) t);
			}
		}

		NodeList l = dom.getElementsByTagName("stream");
		for (int i = 0; i < l.getLength(); ++i) {
			streams.add(new Stream((Element) l.item(i)));
		}
	}
}