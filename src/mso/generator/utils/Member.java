package mso.generator.utils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.zip.CRC32;

import org.eclipse.jdt.annotation.NonNullByDefault;
import org.eclipse.jdt.annotation.Nullable;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

@NonNullByDefault
public class Member {
	public final TypeRegistry registry;
	public final String name;
	private final String typeName;
	@Nullable
	public final String count;
	@Nullable
	public final String size;
	@Nullable
	public final String condition;
	public final boolean isArray;
	public final boolean isOptional;
	public final boolean isInteger;
	public final boolean isSimple;
	public final boolean isStruct;
	public final boolean isChoice;
	public final Limitation limitations[];

	private static final String HEXINDEX = "0123456789abcdef          ABCDEF";

	private static byte[] hexToByte(String s) {
		int l = s.length() / 2;
		byte data[] = new byte[l];
		int j = 0;

		for (int i = 0; i < l; i++) {
			char c = s.charAt(j++);
			int n, b;

			n = HEXINDEX.indexOf(c);
			b = (n & 0xf) << 4;
			c = s.charAt(j++);
			n = HEXINDEX.indexOf(c);
			b += (n & 0xf);
			data[i] = (byte) b;
		}
		return data;
	}

	class ByteArray implements Comparable<ByteArray> {
		final byte data[];

		ByteArray(byte data[]) {
			this.data = data;
		}

		public int compareTo(ByteArray o) {
			byte b[] = o.data;

			for (int i = 0; i < data.length && i < b.length; i++) {
				if (b[i] != data[i]) {
					return data[i] - b[i];
				}
			}
			return data.length - b.length;
		}

	}

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
				Type t = registry.getType(ce.getAttribute("name"));
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
		} else if (e.getNodeName().equals("fixedchoice")) {
			SortedSet<ByteArray> texts = new TreeSet<ByteArray>();
			NodeList l = e.getElementsByTagName("text");
			for (int i = 0; i < l.getLength(); ++i) {
				String text = ((Element) l.item(i)).getTextContent();
				texts.add(new ByteArray(text.getBytes("UTF8")));
			}
			l = e.getElementsByTagName("hex");
			for (int i = 0; i < l.getLength(); ++i) {
				String hex = ((Element) l.item(i)).getTextContent();
				texts.add(new ByteArray(hexToByte(hex)));
			}
			CRC32 crc = new CRC32();
			for (ByteArray b : texts) {
				crc.update(b.data);
			}
			typeName = "fixedchoice" + crc.getValue();

			if (registry.getType(typeName) == null) {
				new FixedChoice(registry, typeName, texts, isOptional);
			}
			isInteger = false;
			isSimple = true;
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

	public Type type() {
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
		throw new NullPointerException(
				"No struct type with name " + typename + " can be found.");
	}

}