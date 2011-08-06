package mso.generator.utils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.zip.CRC32;

import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

public class Member {
	public final TypeRegistry registry;
	public final String name;
	private final String typeName;
	public final String count;
	public final String size;
	public final String condition;
	public final boolean isArray;
	public final boolean isOptional;
	public final boolean isInteger;
	public final boolean isSimple;
	public final boolean isStruct;
	public final boolean isChoice;
	public final Limitation limitations[];

	Member(TypeRegistry r, Element e) throws IOException {
		registry = r;
		name = e.getAttribute("name");
		condition = (e.hasAttribute("condition")) ? e.getAttribute("condition")
				: null;
		count = (e.hasAttribute("count")) ? e.getAttribute("count") : null;
		size = (e.hasAttribute("size")) ? e.getAttribute("size") : null;

		isOptional = e.hasAttribute("optional");
		isArray = count != null || e.hasAttribute("array");
		if (isOptional && isArray) {
			throw new IOException("Member " + name
					+ " is optional and array, which is not allowed.");
		}
		if (e.hasAttribute("type")) {
			typeName = e.getAttribute("type");
			isInteger = false;
			isSimple = false;
			isChoice = false;
			isStruct = true;
		} else if (e.getNodeName().equals("choice")) {
			NodeList l = e.getElementsByTagName("type");
			String choiceName = "";
			List<Struct> choices = new ArrayList<Struct>();
			Element msoelement = (Element) e.getParentNode().getParentNode();
			for (int i = 0; i < l.getLength(); ++i) {
				String type = ((Element) l.item(i)).getAttribute("type");
				Element ce = getStructElement(msoelement, type);
				choiceName += type;
				TypeRegistry.Type t = registry.getType(ce.getAttribute("name"));
				if (t instanceof Struct) {
					choices.add((Struct) t);
				} else {
					choices.add(new Struct(registry, ce));
				}
			}
			CRC32 crc = new CRC32();
			crc.update(choiceName.getBytes());
			choiceName = "choice" + crc.getValue();
			typeName = choiceName;
			if (registry.getType(typeName) == null) {
				new Choice(registry, choiceName, choices, isOptional);
			}
			isInteger = false;
			isSimple = false;
			isChoice = true;
			isStruct = false;
		} else {
			typeName = e.getNodeName();
			isInteger = typeName.startsWith("int")
					|| typeName.startsWith("uint");
			isSimple = true;
			isChoice = false;
			isStruct = false;
		}

		List<Limitation> _limitations = new ArrayList<Limitation>();
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			if (l.item(i) instanceof Element) {
				_limitations.add(new Limitation((Element) l.item(i)));
			}
		}
		limitations = _limitations.toArray(new Limitation[0]);
	}

	public TypeRegistry.Type type() {
		return registry.getType(typeName);
	}

	private static Element getStructElement(Element mso, String typename) {
		NodeList l = mso.getElementsByTagName("struct");
		for (int i = 0; i < l.getLength(); ++i) {
			Element e = (Element) l.item(i);
			if (e.getAttribute("name").equals(typename)) {
				return e;
			}
		}
		return null;
	}

}