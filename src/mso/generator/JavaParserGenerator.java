package mso.generator;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class JavaParserGenerator {
	void generate(Document dom, String dir, String packagename, String classname)
			throws IOException {
		FileWriter fout = new FileWriter(dir + "/"
				+ packagename.replace('.', '/') + "/" + classname + ".java");
		PrintWriter out = new PrintWriter(fout);
		out.println("package " + packagename + ";");
		out.println("import java.io.IOException;");
		out.println("public class " + classname + " {");
		out
				.println("    boolean parse(String key, LEInputStream in) throws IOException {");
		NodeList l = dom.getElementsByTagName("stream");
		for (int i = 0; i < l.getLength(); ++i) {
			Element e = (Element) l.item(i);
			// String name = e.getAttribute("name");
			String key = e.getAttribute("key");
			String type = e.getAttribute("type");
			out.print("        ");
			if (i > 0) {
				out.print("} else ");
			}
			out.println("if (\"" + key + "\".equals(key)) {"); // TODO: fix for
			// \001 and \005
			// prefix
			out.println("            parse" + type + "(in);");
			out.println("            return true;");
		}
		out.println("        }");
		out.println("        return false;");
		out.println("    }");

		l = dom.getElementsByTagName("struct");
		for (int i = 0; i < l.getLength(); ++i) {
			printStructureParser(out, (Element) l.item(i));
		}

		out.println("}");

		l = dom.getElementsByTagName("struct");
		for (int i = 0; i < l.getLength(); ++i) {
			printStructureClass(out, (Element) l.item(i));
		}

		out.close();
		fout.close();
	}

	void printStructureParser(PrintWriter out, Element e) {
		String name = e.getAttribute("name");
		out.println("    " + name + " parse" + name
				+ "(LEInputStream in) throws IOException  {");
		out.println("        " + name + " _s = new " + name + "();");
		if (hasArrayMember(e)) {
			out.println("        int _c;");
		}
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				printStructureMemberParser(out, (Element) n);
			}
		}
		out.println("        return _s;");
		out.println("    }");
	}

	String getTypeName(Element e) {
		String t = e.getNodeName();
		if ("type".equals(t)) {
			return e.getAttribute("type");
		} else if ("uint4".equals(t) || "uint8".equals(t)) {
			return "byte";
		} else if ("uint12".equals(t)) {
			return "short";
		} else if ("uint16".equals(t) || "uint32".equals(t)
				|| "int32".equals(t)) {
			return "int";
		} else if ("choice".equals(t)) {
			return "Object";
		} else {
			return e.getNodeName();
		}
	}

	String getMemberDeclaration(Element e) {
		String name = e.getAttribute("name");
		String count = e.getAttribute("count");
		String array = e.getAttribute("array");
		String type = e.getAttribute("type");
		if ("".equals(count)) {
			if (!"".equals(array)) {
				return "final java.util.List<" + type + "> " + name
						+ " = new java.util.ArrayList<" + type + ">()";
			}
			return getTypeName(e) + " " + name;
		} else {
			return getTypeName(e) + "[] " + name;
		}
	}

	void printStructureClass(PrintWriter out, Element e) {
		String name = e.getAttribute("name");
		out.println("class " + name + "{");
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
		out.println("    public String toString() {");
		out.println("        String _s = \"" + name + ":\";");
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				String mn = ((Element) n).getAttribute("name");
				out.println("        _s = _s + \"" + mn
						+ ": \" + String.valueOf(" + mn + ") + \", \";");
			}

		}
		out.println("        return _s;");
		out.println("    }");
		out.println("}");

	}

	String getSpecial(String name, Element e) {
		String condition = e.getAttribute(name);
		if (condition.length() > 0) {
			Pattern p = Pattern.compile("([^.\\w])([.a-zA-Z])");
			Matcher m = p.matcher(condition);
			condition = m.replaceAll("$1_s.$2");
			p = Pattern.compile("^([a-zA-Z])");
			m = p.matcher(condition);
			condition = m.replaceAll("_s.$1");
		}
		return condition;
	}

	boolean hasArrayMember(Element e) {
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element && ((Element) n).hasAttribute("count")) {
				return true;
			}
		}
		return false;
	}

	void printStructureMemberParser(PrintWriter out, Element e) {
		String s = "        ";
		String condition = getSpecial("condition", e);
		if (condition.length() > 0) {
			s = s + "    ";
			out.println("        if (" + condition + ") {");
		}
		String name = e.getAttribute("name");
		String type = e.getNodeName();
		String array = e.getAttribute("array");
		String count = getSpecial("count", e);
		String parse;
		if ("type".equals(type)) {
			parse = "parse" + e.getAttribute("type") + "(in);";
		} else {
			parse = "in.read" + type + "();";
		}

		if ("choice".equals(type)) {
			printChoiceParser(out, s, e);
			return;
		}
		if ("".equals(count) && !"".equals(array)) {
			// array for which no size is given: parse items until one fails
			printVariableArrayParser(out, s, e);
			return;
		}
		if (count.length() > 0) {
			out.println(s + "_c = " + count + ";");
		}
		out.print(s + "_s." + name + " = ");
		if (count.length() > 0) {
			out.println("new " + getTypeName(e) + "[_c];");
			out.println(s + "for (int _i=0; _i<_c; ++_i) {");
			out.println(s + "    _s." + name + "[_i] = " + parse);
			printLimitationCheck(out, "            ", "_s." + name + "[_i]", e);
			out.println(s + "}");
		} else {
			out.println(parse);
			printLimitationCheck(out, "        ", "_s." + name, e);
		}
		if (condition.length() > 0) {
			out.println("        }");
		}
	}

	void printChoiceParser(PrintWriter out, String s, Element e) {
		String name = e.getAttribute("name");
		String closing = "";
		String exception = "_x";
		out.println(s + "Object _m = in.setMark();");
		NodeList l = e.getElementsByTagName("type");
		for (int i = 0; i < l.getLength() - 1; ++i) {
			Element se = (Element) l.item(i);
			out.println(s + "try {");
			out.println(s + "    _s." + name + " = parse"
					+ se.getAttribute("type") + "(in);");
			out.println(s + "} catch (IncorrectValueException " + exception
					+ ") {");
			out.println(s + "    System.out.println(" + exception
					+ ".getMessage());");
			out.println(s + "    in.rewind(_m);");
			exception = exception + "x";
			closing = closing + "}";
		}
		Element se = (Element) l.item(l.getLength() - 1);
		out.println(s + "    _s." + name + " = parse" + se.getAttribute("type")
				+ "(in);");
		out.println(s + closing + " finally {");
		out.println(s + "    in.releaseMark(_m);");
		out.println(s + "}");
	}

	void printVariableArrayParser(PrintWriter out, String s, Element e) {
		String type = e.getAttribute("type");
		String name = e.getAttribute("name");
		out.println(s + "boolean _atend = false;");
		out.println(s + "int i=0;");
		out.println(s + "while (!_atend) {");
		out.println(s + "    System.out.println(\"round \"+(i++));");
		out.println(s + "    Object _m = in.setMark();");
		out.println(s + "    try {");
		out.println(s + "        " + type + " _t = parse" + type + "(in);");
		out.println(s + "        _s." + name + ".add(_t);");
		out.println(s + "    } catch(IncorrectValueException _e) {");
		out.println(s + "        _atend = true;");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    } catch(java.io.EOFException _e) {");
		out.println(s + "        _atend = true;");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    } finally {");
		out.println(s + "        in.releaseMark(_m);");
		out.println(s + "    }");
		out.println(s + "}");
	}

	void printLimitationCheck(PrintWriter out, String s, String name, Element e) {
		NodeList l = e.getElementsByTagName("limitation");
		for (int i = 0; i < l.getLength(); ++i) {
			Element se = (Element) l.item(i);
			String condition = getCondition(name, se);
			out.println(s + "if (!(" + condition + ")) {");
			out.println(s + "    throw new IncorrectValueException(\""
					+ condition + " for value \" + String.valueOf(" + name
					+ ") );");
			out.println(s + "}");
		}
	}

	String getCondition(String name, Element e) {
		String mname = e.getAttribute("name");
		if (!"".equals(mname)) {
			name = name + "." + mname;
		}
		String maxValue = e.getAttribute("maxValue");
		if (!"".equals(maxValue)) {
			return name + " <= " + maxValue;
		}
		String minValue = e.getAttribute("minValue");
		if (!"".equals(minValue)) {
			return name + " >= " + minValue;
		}
		String value = e.getAttribute("value");
		if (value.contains("|")) {
			String values[] = value.split("\\|");
			String c = name + " == " + values[0];
			for (int i = 1; i < values.length; ++i) {
				c = c + " || " + name + " == " + values[i];
			}
			return c;
		}
		if (!"".equals(value)) {
			return name + " == " + value;
		}
		return e.getAttribute("value");
	}
}