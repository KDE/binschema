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
				.println("    void parse(String key, LEInputStream in) throws IOException {");
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
		}
		out.println("        } else {");
		out.println("            parseTODOS(in);");
		out.println("        }");
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
		if (hasElementWithAttribute(e, "count")) {
			out.println("        int _c;");
		}
		if (hasElementWithAttribute(e, "optional")) {
			out.println("        Object _m;");
		}
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element) {
				printStructureMemberParser(out, (Element) n);
			}
		}
		if ("RecordHeader".equals(name)) {
			out.println("System.out.println(_s);");
		}
		out.println("        return _s;");
		out.println("    }");
	}

	String getTypeName(Element e) {
		String t = e.getNodeName();
		if ("type".equals(t)) {
			return e.getAttribute("type");
		} else if ("bit".equals(t)) {
			return "boolean";
		} else if ("uint2".equals(t) || "uint4".equals(t) || "uint5".equals(t)
				|| "uint6".equals(t) || "uint8".equals(t)) {
			return "byte";
		} else if ("uint12".equals(t) || "int16".equals(t)) {
			return "short";
		} else if ("uint16".equals(t) || "uint32".equals(t)
				|| "int32".equals(t)) {
			return "int";
		} else if ("choice".equals(t)) {
			return "Object";
		} else {
			return t;
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

	String prependStructureToExpression(String expression, String structureName) {
		if (expression.length() > 0) {
			Pattern p = Pattern.compile("([^.\\w])([.a-zA-Z])");
			Matcher m = p.matcher(expression);
			expression = m.replaceAll("$1" + structureName + ".$2");
			p = Pattern.compile("^([a-zA-Z])");
			m = p.matcher(expression);
			expression = m.replaceAll(structureName + ".$1");
		}
		return expression;
	}

	boolean hasElementWithAttribute(Element e, String attribute) {
		NodeList l = e.getChildNodes();
		for (int i = 0; i < l.getLength(); ++i) {
			Node n = l.item(i);
			if (n instanceof Element && ((Element) n).hasAttribute(attribute)) {
				return true;
			}
		}
		return false;
	}

	void printStructureMemberParser(PrintWriter out, Element e) {
		String s = "        ";
		String condition = prependStructureToExpression(e
				.getAttribute("condition"), "_s");
		if (condition.length() > 0) {
			s = s + "    ";
			out.println("        if (" + condition + ") {");
		}
		String name = e.getAttribute("name");
		String type = e.getNodeName();
		String array = e.getAttribute("array");
		String count = prependStructureToExpression(e.getAttribute("count"),
				"_s");
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
		if (!"".equals(e.getAttribute("optional"))) {
			printOptionalMemberParser(out, s, e);
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
			out
					.println(s
							+ "    if (in.distanceFromMark(_m) > 16) throw new IOException("
							+ exception + ");//onlyfordebug");
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
		out
				.println(s
						+ "    if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug");
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

	void printOptionalMemberParser(PrintWriter out, String s, Element e) {
		String type = e.getAttribute("type");
		String name = e.getAttribute("name");
		out.println(s + "_m = in.setMark();");
		out.println(s + "try {");
		out.println(s + "    _s." + name + " = parse" + type + "(in);");
		out.println(s + "} catch(IncorrectValueException _e) {");
		out
				.println(s
						+ "    if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug");
		out.println(s + "    in.rewind(_m);");
		out.println(s + "} catch(java.io.EOFException _e) {");
		out.println(s + "    in.rewind(_m);");
		out.println(s + "} finally {");
		out.println(s + "    in.releaseMark(_m);");
		out.println(s + "}");
	}

	void printLimitationCheck(PrintWriter out, String s, String name, Element e) {
		NodeList l = e.getElementsByTagName("limitation");
		for (int i = 0; i < l.getLength(); ++i) {
			Element se = (Element) l.item(i);
			String mname = se.getAttribute("name");
			if (!"".equals(mname)) {
				mname = name + "." + mname;
			} else {
				mname = name;
			}
			String condition = se.getAttribute("expression");
			if ("".equals(condition)) {
				condition = getCondition(mname, se);
			} else {
				condition = getExpression(mname, condition);
			}

			out.println(s + "if (!(" + condition + ")) {");
			String exceptionType = "IncorrectValueException";
			// if (!condition.contains(".recType")
			// && !condition.contains(".recVer")
			// && !condition.contains(".recInstance")) {
			// // special value for debugging: we only have recoverable
			// // exceptions in record headers, remove this in final code
			// exceptionType = "IOException";
			// }
			out.println(s + "    throw new " + exceptionType + "(\""
					+ condition + " for value \" + String.valueOf(" + name
					+ ") );");
			out.println(s + "}");
		}
	}

	String getExpression(String structure, String expression) {
		if (Pattern.matches(".*[A-Za-z].*", expression)) {
			return prependStructureToExpression(expression, structure);
		}
		return structure + expression;
	}

	String getCondition(String name, Element e) {
		String maxValue = e.getAttribute("maxValue");
		if (!"".equals(maxValue)) {
			return name + " <= " + maxValue;
		}
		String minValue = e.getAttribute("minValue");
		if (!"".equals(minValue)) {
			return name + " >= " + minValue;
		}
		String value = e.getAttribute("value");
		String cmp = " == ";
		String cmb = " || ";
		if (value.startsWith("!")) {
			value = value.substring(1);
			cmp = " != ";
			cmb = " && ";
		}
		if (value.contains("|")) {
			String values[] = value.split("\\|");
			String c = name + cmp + values[0];
			for (int i = 1; i < values.length; ++i) {
				c = c + cmb + name + cmp + values[i];
			}
			return c;
		}
		if (!"".equals(value)) {
			return name + cmp + value;
		}
		return e.getAttribute("value");
	}
}
