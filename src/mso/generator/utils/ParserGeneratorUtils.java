package mso.generator.utils;

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

import org.eclipse.jdt.annotation.NonNullByDefault;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
@NonNullByDefault
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

	public static Map<Integer, String> getRecordTypeNames(Document dom)
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
