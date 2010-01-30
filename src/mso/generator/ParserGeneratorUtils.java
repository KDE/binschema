package mso.generator;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.zip.CRC32;

import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

class MSO {
	final List<Struct> structs = new ArrayList<Struct>();
	final List<Choice> choices = new ArrayList<Choice>();
	final List<Stream> streams = new ArrayList<Stream>();

	MSO(Document dom) throws IOException {
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

class Limitation {
	final String name;
	final String expression;
	final String value;

	Limitation(Element e) {
		name = e.getAttribute("name");
		if (e.hasAttribute("expression")) {
			expression = e.getAttribute("expression");
			value = null;
		} else {
			expression = null;
			value = e.getAttribute("value");
		}
	}

	public boolean equals(Object o) {
		if (!(o instanceof Limitation))
			return false;
		Limitation l = (Limitation) o;
		if (!l.name.equals(name))
			return false;
		if (expression != null) {
			if (l.expression == null || !expression.equals(l.expression))
				return false;
		}
		// value is not null
		if (l.value == null || !l.value.equals(value))
			return false;
		return true;
	}
}

class Member {
	final TypeRegistry registry;
	final String name;
	private final String typeName;
	final String count;
	final String size;
	final String condition;
	final boolean isArray;
	final boolean isOptional;
	final boolean isInteger;
	final boolean isSimple;
	final boolean isStruct;
	final boolean isChoice;
	final Limitation limitations[];

	Member(TypeRegistry r, Element e) {
		registry = r;
		name = e.getAttribute("name");
		condition = (e.hasAttribute("condition")) ? e.getAttribute("condition")
				: null;
		count = (e.hasAttribute("count")) ? e.getAttribute("count") : null;
		size = (e.hasAttribute("size")) ? e.getAttribute("size") : null;

		isOptional = e.hasAttribute("optional");
		isArray = count != null || e.hasAttribute("array");
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

class TypeRegistry {
	protected final Map<String, Type> types = new HashMap<String, Type>();

	class Type {
		public final TypeRegistry registry;
		public final String name;
		public final int size;

		Type(TypeRegistry r, String name_, int size_) {
			registry = r;
			name = name_;
			size = size_;
			if (types.containsKey(name)) {
				throw new Error("Duplicate key: " + name);
			}
			types.put(name, this);
		}

		Type get(String name) {
			return types.get(name);
		}
	}

	protected Type getType(String name) {
		return types.get(name);
	}

	final public Type bit = new Type(this, "bit", 1);
	final public Type uint2 = new Type(this, "uint2", 2);
	final public Type uint3 = new Type(this, "uint3", 3);
	final public Type uint4 = new Type(this, "uint4", 4);
	final public Type uint5 = new Type(this, "uint5", 5);
	final public Type uint6 = new Type(this, "uint6", 6);
	final public Type uint7 = new Type(this, "uint7", 7);
	final public Type uint8 = new Type(this, "uint8", 8);
	final public Type uint9 = new Type(this, "uint9", 9);
	final public Type uint12 = new Type(this, "uint12", 12);
	final public Type uint14 = new Type(this, "uint14", 14);
	final public Type uint15 = new Type(this, "uint15", 15);
	final public Type uint16 = new Type(this, "uint16", 16);
	final public Type uint20 = new Type(this, "uint20", 20);
	final public Type uint30 = new Type(this, "uint30", 30);
	final public Type uint32 = new Type(this, "uint32", 32);
	final public Type int16 = new Type(this, "int16", 16);
	final public Type int32 = new Type(this, "int32", 32);
}

class Struct extends TypeRegistry.Type {

	final List<Member> members = new ArrayList<Member>();
	final String sizeExpression;
	final boolean containsArrayMember;
	final boolean containsOptionalMember;
	final boolean containsUnknownLengthArrayMember;
	final boolean containsKnownLengthArrayMember;
	final boolean containsUnsureChoice;
	final boolean containsSureChoice;
	final boolean containsChoice;

	static int getSize(TypeRegistry registry, Element e) {
		int size = 0;
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				Element me = (Element) n;
				if (me.getNodeName().equals("limitation")) {
					continue;
				}
				Member m = new Member(registry, me);
				if (m.type() == null)
					System.err.println("null " + m.name);
				if (m.isOptional || m.type() == null || m.type().size == -1) {
					return -1;
				}
				if (m.isArray) {
					Integer asize = null;
					try {
						if (m.size != null)
							asize = Integer.decode(m.size);
					} catch (NumberFormatException e1) {
					}
					Integer count = null;
					try {
						if (m.count != null)
							count = Integer.decode(m.count);
					} catch (NumberFormatException e2) {
					}
					if (asize != null) {
						size += asize * 8;
					} else if (count != null && m.type().size != -1) {
						size += count * m.type().size;
					} else {
						return -1;
					}
				} else {
					size += m.type().size;
				}
			}
		}
		if (size == 0) {
			throw new Error("size is 0 for " + e.getAttribute("name"));
		}
		if (size % 8 != 0)
			throw new Error("sizes do not add up to multiple of 8: " + size
					+ " for " + e.getAttribute("name"));
		System.err.println(e.getAttribute("name") + " " + (size / 8));
		return size;
	}

	Struct(TypeRegistry registry, Element e) {
		registry.super(registry, e.getAttribute("name"), getSize(registry, e));
		sizeExpression = e.getAttribute("size");

		boolean _containsArrayMember = false;
		boolean _containsOptionalMember = false;
		boolean _containsUnknownLengthArrayMember = false;
		boolean _containsKnownLengthArrayMember = false;
		boolean _containsSureChoice = false;
		boolean _containsUnsureChoice = false;
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				Element me = (Element) n;
				if (me.getNodeName().equals("limitation")) {
					break;
				}
				Member m = new Member(registry, me);
				members.add(m);
				_containsArrayMember = _containsArrayMember || m.isArray;
				_containsOptionalMember = _containsOptionalMember
						|| m.isOptional;
				_containsUnknownLengthArrayMember = _containsUnknownLengthArrayMember
						|| (m.isArray && m.count == null);
				_containsKnownLengthArrayMember = _containsKnownLengthArrayMember
						|| m.count != null;
				if (m.type() instanceof Choice) {
					_containsSureChoice = _containsSureChoice
							|| ((Choice) m.type()).commonType != null;
					_containsUnsureChoice = _containsSureChoice
							|| ((Choice) m.type()).commonType == null;
				}
			}
		}
		containsArrayMember = _containsArrayMember;
		containsOptionalMember = _containsOptionalMember;
		containsUnknownLengthArrayMember = _containsUnknownLengthArrayMember;
		containsKnownLengthArrayMember = _containsKnownLengthArrayMember;
		containsUnsureChoice = _containsUnsureChoice;
		containsSureChoice = _containsSureChoice;
		containsChoice = containsUnsureChoice || containsSureChoice;
	}
}

class Option {
	class Lim {
		Limitation[] limitations;
		Lim[] lims;

		boolean containsCommonLimitation(Limitation l) {
			if (limitations != null) {
				for (int i = 0; i < limitations.length; ++i) {
					if (limitations[i].equals(l)) {
						return true;
					}
				}
			}
			return false;
		}

		void removeLimitation(Limitation l) {
			if (!containsCommonLimitation(l))
				return;
			if (limitations != null) {
				Limitation[] nl = new Limitation[limitations.length - 1];
				int pos = 0;
				for (int i = 0; i < limitations.length; ++i) {
					if (!limitations[i].equals(l)) {
						nl[pos++] = limitations[i];
					}
				}
				limitations = nl;
			}
		}
	}

	Struct type;
	TypeRegistry.Type limitsType;
	Lim lim = new Lim();

	Option(Struct s, TypeRegistry.Type suggestedType) {
		type = s;
		setLimitations(s, suggestedType);
	}

	Option(Struct s) {
		type = s;
		setLimitations(s, null);
	}

	private void setLimitations(Choice c) {
		// all restrictions in the
		lim.lims = new Option.Lim[c.options.size()];
		for (int i = 0; i < c.options.size(); ++i) {
			lim.lims[i] = c.options.get(i).lim;
		}
		limitsType = c.commonType;
	}

	private void setLimitations(Struct s, TypeRegistry.Type suggestedType) {
		Member m = s.members.get(0);
		if (m.isOptional) {
			throw new Error("choice member may not be optional");
		}
		TypeRegistry.Type t = m.type();
		if (t instanceof Choice) {
			setLimitations((Choice) t);
			return;
		}
		// if the type is equal to a previous common type, use that
		if (t == suggestedType) {
			lim.limitations = m.limitations;
			limitsType = suggestedType;
			return;
		}
		// if this struct has no limitations, take its first member
		if (m.limitations.length == 0) {
			setLimitations((Struct) t, suggestedType);
			return;
		}
		lim.limitations = m.limitations;
		limitsType = t;
	}
}

class Choice extends TypeRegistry.Type {
	final TypeRegistry.Type commonType;
	final List<Option> options = new ArrayList<Option>();

	static int getSize(List<Struct> choices) {
		int size = choices.get(0).size;
		for (Struct s : choices) {
			if (s.size != size) {
				return -1;
			}
		}
		return size;
	}

	Choice(TypeRegistry registry, String name, List<Struct> choices,
			boolean optional) {
		registry.super(registry, name, getSize(choices));
		TypeRegistry.Type common = null;
		for (Struct s : choices) {
			Option o = new Option(s, common);
			if (common != null && o.limitsType != common
					&& !compareTypes(common, o.limitsType)) {
				throw new Error("Conflicting common type: " + common.name
						+ " vs " + o.limitsType.name);
			}
			common = o.limitsType;
			options.add(o);
		}
		// check if the common type is the same
		for (Option o : options) {
			if (!compareTypes(common, o.limitsType)) {
				String types = "";
				for (Option op : options) {
					types = types + " " + op.type.name;
				}
				System.err.println("The choice " + name
						+ " has no common options for types" + types);
				common = null;
				break;
			}
		}
		if (common == null) {
			commonType = null;
			return;
		}
		// Check if the limitations are distinctive
		// if limitation on an earlier option are a subset of a later
		// limitation,
		// then then the limitations cannot be used for making the choice
		// so must make sure that earlier sets of limitations are not
		// subsets of later limitations.
		for (int i = 0; i < options.size(); ++i) {
			int last = (optional) ? options.size() : options.size() - 1;
			for (int j = i + 1; j < last; ++j) {
				// the double negation is important: we cannot be sure that it
				// is a subset
				// we must be sure that it is not a subset
				Option a = options.get(i);
				Option b = options.get(j);
				if (!noOverlap(a.lim, b.lim)) {
					System.err.println("Options " + a.type.name + " and "
							+ b.type.name + " have overlap.");
					common = null;
				}
			}
		}

		// if the options are distinctive we can use them
		commonType = common;

		if (!optional && common != null) {
			// remove options that are present in all options
			removeNonDistinctiveLimitations();
		}
	}

	/**
	 * Return true if not all of the limitations in a are sure to be present in
	 * b. Err on the side of safety: if unsure return false;
	 */
	static private boolean noOverlap(Option.Lim a, Option.Lim b) {
		if (a.limitations == null && a.lims == null)
			return false;
		if (a.limitations != null) {
			if (!noOverlap(a.limitations, b)) {
				return false;
			}
		}
		if (a.lims != null) {
			for (Option.Lim sa : a.lims) {
				if (!noOverlap(sa, b)) {
					return false;
				}
			}
		}
		return true;
	}

	static private boolean noOverlap(Limitation a[], Option.Lim b) {
		if (b.limitations == null && b.lims == null)
			return false;
		if (b.limitations != null) {
			if (!noOverlap(a, b.limitations)) {
				return false;
			}
		}
		if (b.lims != null) {
			for (Option.Lim sb : b.lims) {
				if (!noOverlap(a, sb)) {
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * Return true if sure that a and b define value spaces with no overlap
	 */
	static private boolean noOverlap(Limitation a[], Limitation b[]) {
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < b.length; ++j) {
				if (a[i].name.equals(b[j].name)
						&& noOverlap(a[i].value, b[j].value)) {
					return true;
				}
			}
		}
		return false;
	}

	static private boolean noOverlap(String a, String b) {
		if (a == null || b == null)
			return false;
		String[] avalues = a.split("\\|");
		String[] bvalues = b.split("\\|");
		for (int i = 0; i < avalues.length; ++i) {
			for (int j = 0; j < bvalues.length; ++j) {
				if (avalues[i].equals(bvalues[j])) {
					return false;
				}
			}
		}
		return true;
	}

	static private boolean compareMembers(Member a, Member b) {
		if (a.isArray != b.isArray)
			return false;
		if (a.type() != b.type())
			return false;
		if (a.isOptional != b.isOptional)
			return false;
		return true;
	}

	static private boolean structsWithSameMembers(TypeRegistry.Type a,
			TypeRegistry.Type b) {
		if (a instanceof Struct && b instanceof Struct) {
			Struct as = (Struct) a;
			Struct bs = (Struct) b;
			if (as.members.size() != bs.members.size()) {
				return false;
			}
			for (int i = 0; i < as.members.size(); ++i) {
				if (!compareMembers(as.members.get(i), bs.members.get(i))) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	static private boolean compareTypes(TypeRegistry.Type a, TypeRegistry.Type b) {
		return a == b || structsWithSameMembers(a, b);
	}

	public String[] getChoiceNames() {
		String n[] = new String[options.size()];
		for (int i = 0; i < options.size(); ++i) {
			n[i] = options.get(i).type.name;
		}
		return n;
	}

	void removeNonDistinctiveLimitations() {
		Option.Lim a = options.get(0).lim;
		if (a.limitations != null) {
			for (int i = 0; i < a.limitations.length; ++i) {
				Limitation l = a.limitations[i];
				boolean common = true;
				for (int j = 1; j < options.size(); ++j) {
					common = common
							&& options.get(j).lim.containsCommonLimitation(l);
				}
				if (common) {
					for (int j = 0; j < options.size(); ++j) {
						options.get(j).lim.removeLimitation(l);
					}
					i = 0;
				}
			}
		}
	}
}

class Stream {

	final String key;
	final String type;

	Stream(Element e) {
		key = e.getAttribute("key");
		type = e.getAttribute("type");
	}
}

public class ParserGeneratorUtils {

	static Collection<String> getDependencies(Element e) {
		Set<String> deps = new TreeSet<String>();
		NodeList l = e.getElementsByTagName("type");
		for (int i = 0; i < l.getLength(); ++i) {
			Element se = (Element) l.item(i);
			if (!se.hasAttribute("count") && !se.hasAttribute("array")) {
				deps.add(se.getAttribute("type"));
			}
		}
		return deps;
	}

	static List<Element> getOrderedStructureList(Document dom)
			throws IOException {

		List<Element> unorderedList = new ArrayList<Element>();
		NodeList l = dom.getElementsByTagName("struct");
		for (int i = 0; i < l.getLength(); ++i) {
			unorderedList.add((Element) l.item(i));
		}

		List<String> done = new ArrayList<String>();
		List<Element> orderedList = new ArrayList<Element>();
		while (unorderedList.size() > 0) {
			int count = unorderedList.size();
			for (int i = 0; i < unorderedList.size();) {
				Element e = unorderedList.get(i);
				Collection<String> deps = getDependencies(e);
				deps.removeAll(done);
				if (deps.size() == 0) {
					orderedList.add(e);
					done.add(e.getAttribute("name"));
					unorderedList.remove(e);
				} else {
					i++;
				}
			}
			if (count == unorderedList.size()) {
				String msg = "";
				for (Element e : unorderedList) {
					Collection<String> deps = getDependencies(e);
					deps.removeAll(done);
					msg = msg + e.getAttribute("name") + ": " + deps + "\n";
				}
				throw new IOException(msg + count);
			}
		}
		return orderedList;
	}

	static Map<Integer, String> getRecordTypeNames(Document dom)
			throws XPathExpressionException {
		Map<Integer, String> map = new HashMap<Integer, String>();

		XPath xpath = XPathFactory.newInstance().newXPath();
		String expression = "/mso/struct/type[@name='rh']/limitation[@name='recType']";
		NodeList list = (NodeList) xpath.evaluate(expression, dom,
				XPathConstants.NODESET);

		for (int i = 0; i < list.getLength(); ++i) {
			Element e = (Element) list.item(i);
			String name = ((Element) e.getParentNode().getParentNode())
					.getAttribute("name");
			String type = e.getAttribute("value").replace("0x", "");
			for (String s : type.split("\\|")) {
				int typeNumber = Integer.parseInt(s, 16);
				if (map.containsKey(typeNumber)) {
					name = map.get(typeNumber) + "/" + name;
				}
				map.put(typeNumber, name);
			}
		}
		return map;
	}
}
