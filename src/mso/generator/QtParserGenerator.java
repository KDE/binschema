package mso.generator;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Set;
import java.util.TreeSet;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class QtParserGenerator {

	void generate(Document dom, String dir) throws IOException {
		FileWriter fout = new FileWriter(dir + "/generatedclasses.cpp");
		PrintWriter out = new PrintWriter(fout);
		out.println("#include <QObject>");
		out.println("#include <QString>");
		out.println("#include <QByteArray>");
		out.println("#include <QVector>");
		out.println("namespace {");

		NodeList l = dom.getElementsByTagName("struct");
		for (int i = 0; i < l.getLength(); ++i) {
			out.println("class " + ((Element) l.item(i)).getAttribute("name")
					+ ";");
		}

		for (int i = 0; i < l.getLength(); ++i) {
			Element e = (Element) l.item(i);
			printStructureClassDeclaration(out, e);
		}

		for (int i = 0; i < l.getLength(); ++i) {
			Element e = (Element) l.item(i);
			printStructureClassImplementation(out, e);
		}

		out.println("}");
		out.close();
		fout.close();
	}

	String getTypeName(Element e) {
		String t = e.getNodeName();
		if ("type".equals(t)) {
			return e.getAttribute("type");
		} else if ("bit".equals(t)) {
			return "bool";
		} else if ("uint2".equals(t) || "uint3".equals(t) || "uint4".equals(t)
				|| "uint5".equals(t) || "uint6".equals(t) || "uint8".equals(t)) {
			return "quint8";
		} else if ("uint12".equals(t) || "uint14".equals(t)
				|| "uint16".equals(t)) {
			return "quint16";
		} else if ("uint20".equals(t) || "uint30".equals(t)
				|| "uint32".equals(t)) {
			return "quint32";
		} else if ("int16".equals(t)) {
			return "qint16";
		} else if ("int32".equals(t)) {
			return "qint32";
		} else if ("choice".equals(t)) {
			return "QObject";
		} else {
			return t;
		}
	}

	String getMemberDeclaration(Element e) {
		String name = e.getAttribute("name");
		String count = e.getAttribute("count");
		String array = e.getAttribute("array");
		if ("".equals(count)) {
			if (!"".equals(array)) {
				String type = e.getAttribute("type") + "*";
				return "final java.util.List<" + type + "> " + name
						+ " = new java.util.ArrayList<" + type + ">()";
			}
			return getTypeName(e) + " " + name;
		} else if ("quint8".equals(getTypeName(e))) {
			return "QByteArray " + name;
		} else {
			return "QVector<" + getTypeName(e) + "> " + name;
		}
	}

	void printStructureClassDeclaration(PrintWriter out, Element e) {
		String name = e.getAttribute("name");
		out.println("class " + name + " : public QObject {");
		out.println("public:");
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				Element se = (Element) n;
				String d = getMemberDeclaration(se);
				out.println("    " + d + ";");
			}
		}

		// function toString
		/*
		 * out.println("    QString toString() {");
		 * out.println("        QString _s = \"" + name + ":\";"); for (int i =
		 * 0; i < l.getLength(); ++i) { Node n = l.item(i); if (n instanceof
		 * Element) { Element se = (Element) n; String mn =
		 * se.getAttribute("name"); out.print("        _s = _s + \"" + mn +
		 * ": \" + "); if (se.getNodeName().contains("int") &&
		 * !se.hasAttribute("count")) { out.print("QString::number(" + mn +
		 * ") + \""); out.print("(\" + QString::number(" + mn +
		 * ",16).toUpper() + \")"); } else { out.print(mn + ".toString() + \"");
		 * } out.println(", \";"); }
		 * 
		 * } out.println("        return _s;"); out.println("    }");
		 */
		out.println("};");

	}

	void printStructureClassImplementation(PrintWriter out, Element e) {

	}

	Collection<String> getDependencies(Element e) {
		Set<String> deps = new TreeSet<String>();
		NodeList l = e.getElementsByTagName("type");
		for (int i = 0; i < l.getLength(); ++i) {
			deps.add(((Element) l.item(i)).getAttribute("type"));
		}
		return deps;
	}

}
