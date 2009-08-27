package mso.generator;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class QtParserGenerator {

	void generate(MSO mso, String dir) throws IOException {
		FileWriter fout = new FileWriter(dir + "/generatedclasses.cpp");
		PrintWriter out = new PrintWriter(fout);
		out.println("#include <QString>");
		out.println("#include <QByteArray>");
		out.println("#include <QVector>");
		out.println("#include \"leinputstream.h\"");
		out.println("namespace {");

		for (Struct s : mso.structs) {
			out.println("class " + s.name + ";");
		}

		for (Struct s : mso.structs) {
			printStructureClassDeclaration(out, s);
		}

		for (Struct s : mso.structs) {
			printStructureClassImplementation(out, s);
		}

		for (Struct s : mso.structs) {
			printStructureParser(out, s);
		}

		out.println("void parse(QString key, LEInputStream& in) {");
		boolean first = true;
		for (Stream s : mso.streams) {
			out.print("        ");
			if (first) {
				first = false;
			} else {
				out.print("} else ");
			}
			out.println("if (\"" + s.key + "\" == key) {"); // TODO: fix for
			// \001 and \005
			// prefix
			out.println("            parse" + s.type + "(in);");
		}
		out.println("        } else {");
		out.println("            parseTODOS(in);");
		out.println("        }");
		out.println("    }");

		out.println("}");
		out.close();
		fout.close();
	}

	void printStructureParser(PrintWriter out, Struct s) {
		out.println("void parse" + s.name + "(LEInputStream& in, " + s.name
				+ "& _s) {");
		// if (hasElementWithAttribute(e, "count")) {
		out.println("    int _c;");
		// }
		if (s.containsArrayMember || s.containsOptionalMember) {
			out.println("        Object _m;");
		}
		for (Member m : s.members) {
			printStructureMemberParser(out, m);
		}
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

	void printStructureMemberParser(PrintWriter out, Member m) {
		String s = "    ";
		String condition = prependStructureToExpression(m.condition, "_s");
		if (condition.length() > 0) {
			out.println(s + "if (" + condition + ") {");
			s = s + "    ";
		}
		String count = prependStructureToExpression(m.count, "_s");
		String parse;
		if (m.isComplex) {
			parse = "parse" + m.type + "(in, _s." + m.name + ");";
		} else {
			parse = "in.read" + m.type + "();";
		}

		if (m.choices != null) {
			printChoiceParser(out, s, m);
			return;
		}
		if (m.isArray && m.count == null) {
			// array for which no size is given: parse items until one fails
			printVariableArrayParser(out, s, m);
			return;
		}
		if (m.isOptional) {
			printOptionalMemberParser(out, s, m);
			return;
		}
		if (count.length() > 0) {
			out.println(s + "_c = " + count + ";");
		}
		out.print(s);// + "_s." + name + " = ");
		if (count.length() > 0) {
			out.println("new " + getTypeName(m) + "[_c];");
			out.println(s + "for (int _i=0; _i<_c; ++_i) {");
			out.println(s + "    _s." + m.name + "[_i] = " + parse);
			printLimitationCheck(out, "            ", "_s." + m.name + "[_i]",
					m);
			out.println(s + "}");
		} else {
			out.println(parse);
			printLimitationCheck(out, s, "_s." + m.name, m);
		}
		if (condition.length() > 0) {
			out.println("        }");
		}
	}

	String getTypeName(Member m) {
		String t = m.type;
		if (m.isComplex) {
			return t;
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
			return "void *";
		} else {
			return t;
		}
	}

	String getMemberDeclaration(Member m) {
		if (m.count == null) {
			if (m.isArray) {
				return "QList<" + m.type + "> " + m.name;
			}
			return getTypeName(m) + " " + m.name;
		} else if ("quint8".equals(getTypeName(m))) {
			return "QByteArray " + m.name;
		} else {
			return "QVector<" + getTypeName(m) + "> " + m.name;
		}
	}

	String memberToString(Member m, String prefix) {
		String s;
		String mn = prefix + m.name;
		if (!m.isArray || m.count == null) {
			if (m.type.contains("int") || m.type.equals("bit")) {
				if (m.count == null) {
					s = "QString::number(" + mn
							+ ") + \"(\" + QString::number(" + mn
							+ ",16).toUpper() + \")\"";
				} else {
					s = "QString(" + mn + ")";
				}
			} else if (m.choices != null) {
				s = "\"<choice>\"";
			} else {
				s = mn + ".toString()";
			}
		} else {
			s = "\"[array of " + mn + "]\"";

		}
		return s;
	}

	void printStructureClassDeclaration(PrintWriter out, Struct s) {
		out.println("class " + s.name + " {");
		out.println("public:");
		for (Member m : s.members) {
			String d = getMemberDeclaration(m);
			out.println("    " + d + ";");
		}

		// function toString

		out.println("    QString toString() {");
		out.println("        QString _s = \"" + s.name + ":\";");
		for (Member m : s.members) {
			out.print("        _s = _s + \"" + m.name + ": \" + ");
			out.print(memberToString(m, ""));
			out.println(" + \", \";");
		}
		out.println("        return _s;");
		out.println("    }");

		out.println("};");

	}

	void printStructureClassImplementation(PrintWriter out, Struct s) {

	}

	void printChoiceParser(PrintWriter out, String s, Member m) {
		String closing = "";
		String exception = "_x";
		out.println(s + "Object _m = in.setMark();");
		for (int i = 0; i < m.choices.length - 1; ++i) {
			out.println(s + "try {");
			out.println(s + "    _s." + m.name + " = parse" + m.choices[i]
					+ "(in);");
			out.println(s + "} catch (IncorrectValueException " + exception
					+ ") {");
			out.println(s + "    System.out.println(" + exception
					+ ".getMessage());");
			out
					.println(s
							+ "    if (in.distanceFromMark(_m) > 16) throw IOException("
							+ exception + ");//onlyfordebug");
			out.println(s + "    in.rewind(_m);");
			exception = exception + "x";
			closing = closing + "}";
		}
		out.println(s + "    _s." + m.name + " = parse"
				+ m.choices[m.choices.length - 1] + "(in);");
		out.println(s + closing + " finally {");
		out.println(s + "    in.releaseMark(_m);");
		out.println(s + "}");
	}

	void printVariableArrayParser(PrintWriter out, String s, Member m) {
		out.println(s + "boolean _atend = false;");
		out.println(s + "int i=0;");
		out.println(s + "while (!_atend) {");
		out
				.println(s
						+ "    System.out.println(\"round \"+(i++) + \" \" + in.getPosition());");
		out.println(s + "    _m = in.setMark();");
		out.println(s + "    try {");
		out.println(s + "        " + m.type + " _t = parse" + m.type + "(in);");
		out.println(s + "        _s." + m.name + ".add(_t);");
		out.println(s + "    } catch(IncorrectValueException _e) {");
		out
				.println(s
						+ "    if (in.distanceFromMark(_m) > 16) throw IOException(_e);//onlyfordebug");
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

	void printOptionalMemberParser(PrintWriter out, String s, Member m) {
		out.println(s + "_m = in.setMark();");
		out.println(s + "try {");
		out.println(s + "    _s." + m.name + " = parse" + m.type + "(in);");
		out.println(s + "} catch(IncorrectValueException _e) {");
		out
				.println(s
						+ "    if (in.distanceFromMark(_m) > 16) throw IOException(_e);//onlyfordebug");
		out.println(s + "    in.rewind(_m);");
		out.println(s + "} catch(java.io.EOFException _e) {");
		out.println(s + "    in.rewind(_m);");
		out.println(s + "} finally {");
		out.println(s + "    in.releaseMark(_m);");
		out.println(s + "}");
	}

	void printLimitationCheck(PrintWriter out, String s, String name, Member m) {
		for (Limitation l : m.limitations) {
			String mname = l.name;
			if (!"".equals(mname)) {
				mname = name + "." + mname;
			} else {
				mname = name;
			}
			String condition = l.expression;
			if (condition == null) {
				condition = getCondition(mname, l);
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
			out.println(s + "    throw " + exceptionType
					+ "(in.getPosition() + \"" + condition + " for value \" + "
					+ memberToString(m, "_s.") + ");");
			out.println(s + "}");
		}
	}

	String getExpression(String structure, String expression) {
		if (Pattern.matches(".*[A-Za-z].*", expression)) {
			return prependStructureToExpression(expression, structure);
		}
		return structure + expression;
	}

	String getCondition(String name, Limitation l) {
		String value = l.value;
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
		return l.value;
	}
}
