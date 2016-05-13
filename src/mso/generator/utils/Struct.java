package mso.generator.utils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.jdt.annotation.NonNullByDefault;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

@NonNullByDefault
public class Struct extends Type {

	public final List<Member> members = new ArrayList<Member>();
	final String sizeExpression;
	public final boolean containsArrayMember;
	public final boolean containsOptionalMember;
	public final boolean containsUnknownLengthArrayMember;
	public final boolean containsKnownLengthArrayMember;
	final boolean containsUnsureChoice;
	final boolean containsSureChoice;
	public final boolean containsChoice;

	private static int getSize(TypeRegistry registry, Element e)
			throws IOException {
		int size = 0;
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (!(n instanceof Element)) {
				continue;
			}
			Element me = (Element) n;
			if (me.getNodeName().equals("limitation")) {
				continue;
			}
			Member m = new Member(registry, me);
			if (m.isOptional || m.condition != null || m.type() == null
					|| m.type().size == -1) {
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
		if (size == 0) {
			throw new Error("size is 0 for " + e.getAttribute("name"));
		}
		if (size % 8 != 0)
			throw new Error("sizes do not add up to multiple of 8: " + size
					+ " for " + e.getAttribute("name"));
		return size;
	}

	Struct(TypeRegistry registry, Element e) throws IOException {
		super(registry, e.getAttribute("name"), getSize(registry, e));
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
			if (!(n instanceof Element)) {
				continue;
			}
			Element me = (Element) n;
			if (me.getNodeName().equals("limitation")) {
				break;
			}
			Member m = new Member(registry, me);
			members.add(m);
			_containsArrayMember = _containsArrayMember || m.isArray;
			_containsOptionalMember = _containsOptionalMember || m.isOptional;
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
		containsArrayMember = _containsArrayMember;
		containsOptionalMember = _containsOptionalMember;
		containsUnknownLengthArrayMember = _containsUnknownLengthArrayMember;
		containsKnownLengthArrayMember = _containsKnownLengthArrayMember;
		containsUnsureChoice = _containsUnsureChoice;
		containsSureChoice = _containsSureChoice;
		containsChoice = containsUnsureChoice || containsSureChoice;
	}
}