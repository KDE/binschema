package mso.generator;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

class MSO {
	List<Struct> structs = new ArrayList<Struct>();
	List<Stream> streams = new ArrayList<Stream>();

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

		// now that all structs are parsed a second step is done where
		// the Choices are introspected. If all options in a choice start with
		// the same member type
		// and the choice have different limitations on the member types, the
		// use of exceptions in the
		// parsing can be avoided
		// for (Struct s : structs) {
		// s.tryToSimplifyChoice();
		// }

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
}

class Member {
	final Struct parent;
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

	Member(Struct parent_, Element e) {
		parent = parent_;
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
			String choiceName = "choice";
			List<Struct> choices = new ArrayList<Struct>();
			Element msoelement = (Element) e.getParentNode().getParentNode();
			for (int i = 0; i < l.getLength(); ++i) {
				String type = ((Element) l.item(i)).getAttribute("type");
				Element ce = getStructElement(msoelement, type);
				choiceName += type;
				TypeRegistry.Type t = parent.registry.getType(ce
						.getAttribute("name"));
				if (t instanceof Struct) {
					choices.add((Struct) t);
				} else {
					choices.add(new Struct(parent.registry, ce));
				}
			}
			typeName = choiceName;
			new Choice(parent.registry, choiceName, choices);
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
		return parent.registry.getType(typeName);
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
	private final Map<String, Type> types = new HashMap<String, Type>();

	class Type {
		public final TypeRegistry registry;
		public final String name;

		Type(TypeRegistry r, String name_) {
			registry = r;
			name = name_;
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

	final public Type bit = new Type(this, "bit");
	final public Type uint2 = new Type(this, "uint2");
	final public Type uint3 = new Type(this, "uint3");
	final public Type uint4 = new Type(this, "uint4");
	final public Type uint5 = new Type(this, "uint5");
	final public Type uint6 = new Type(this, "uint6");
	final public Type uint7 = new Type(this, "uint7");
	final public Type uint8 = new Type(this, "uint8");
	final public Type uint9 = new Type(this, "uint9");
	final public Type uint12 = new Type(this, "uint12");
	final public Type uint14 = new Type(this, "uint14");
	final public Type uint15 = new Type(this, "uint15");
	final public Type uint16 = new Type(this, "uint16");
	final public Type uint20 = new Type(this, "uint20");
	final public Type uint30 = new Type(this, "uint30");
	final public Type uint32 = new Type(this, "uint32");
	final public Type int16 = new Type(this, "int16");
	final public Type int32 = new Type(this, "int32");
}

class Struct extends TypeRegistry.Type {

	final List<Member> members = new ArrayList<Member>();
	final boolean containsArrayMember;
	final boolean containsOptionalMember;
	final boolean containsUnknownLengthArrayMember;
	final boolean containsKnownLengthArrayMember;
	boolean containsUnsureChoice;
	boolean containsSureChoice;

	Struct(TypeRegistry registry, Element e) {
		registry.super(registry, e.getAttribute("name"));

		boolean _containsArrayMember = false;
		boolean _containsOptionalMember = false;
		boolean _containsUnknownLengthArrayMember = false;
		boolean _containsKnownLengthArrayMember = false;
		boolean _containsChoice = false;
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				Element me = (Element) n;
				if (me.getNodeName().equals("limitation")) {
					break;
				}
				Member m = new Member(this, me);
				members.add(m);
				_containsArrayMember = _containsArrayMember || m.isArray;
				_containsOptionalMember = _containsOptionalMember
						|| m.isOptional;
				_containsUnknownLengthArrayMember = _containsUnknownLengthArrayMember
						|| (m.isArray && m.count == null);
				_containsKnownLengthArrayMember = _containsKnownLengthArrayMember
						|| m.count != null;
				_containsChoice = _containsChoice || m.type() instanceof Choice;
			}
		}
		containsArrayMember = _containsArrayMember;
		containsOptionalMember = _containsOptionalMember;
		containsUnknownLengthArrayMember = _containsUnknownLengthArrayMember;
		containsKnownLengthArrayMember = _containsKnownLengthArrayMember;
		containsUnsureChoice = _containsChoice;
		containsSureChoice = false;
	}
}

class Choice extends TypeRegistry.Type {
	final List<Struct> choices;

	Choice(TypeRegistry registry, String name, List<Struct> choices_) {
		registry.super(registry, name);
		choices = choices_;
	}

	String[] getChoiceNames() {
		String n[] = new String[choices.size()];
		for (int i = 0; i < choices.size(); ++i) {
			n[i] = choices.get(i).name;
		}
		return n;
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

	static boolean hasElementWithAttribute(Element e, String attribute) {
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element && ((Element) n).hasAttribute(attribute)) {
				return true;
			}
		}
		return false;
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

	static List<Struct> getPossibleParents(MSO mso, Struct s) {
		List<Struct> parents = new ArrayList<Struct>();
		for (Struct p : mso.structs) {
			for (Member m : s.members) {
				if (m.type() instanceof Struct && m.type() == s) {
					parents.add(p);
				}
			}
		}
		return parents;
	}
}
