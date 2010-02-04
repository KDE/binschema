package mso.generator;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JavaParserGenerator {
	void generate(MSO mso, String dir, String packagename, String classname)
			throws IOException {
		FileWriter fout = new FileWriter(dir + "/"
				+ packagename.replace('.', '/') + "/" + classname + ".java");
		PrintWriter out = new PrintWriter(fout);
		out.println("package " + packagename + ";");
		out.println("import java.io.IOException;");
		out.println("public class " + classname + " {");
		out
				.println("    Object parse(String key, LEInputStream in) throws IOException {");
		boolean first = true;
		for (Stream s : mso.streams) {
			out.print("        ");
			if (first) {
				first = false;
			} else {
				out.print("} else ");
			}
			out.println("if (\"" + s.key + "\".equals(key)) {"); // TODO: fix
			// for
			// \001 and \005
			// prefix
			out.println("            return parse" + s.type + "(in);");
		}
		out.println("        } else {");
		out.println("            return parseTODOS(in);");
		out.println("        }");
		out.println("    }");

		out
				.println("    void serialize(String key, Object o, LEOutputStream out) throws IOException {");
		first = true;
		for (Stream s : mso.streams) {
			out.print("        ");
			if (first) {
				first = false;
			} else {
				out.print("} else ");
			}
			out.println("if (\"" + s.key + "\".equals(key)) {"); // TODO: fix
			// for
			// \001 and \005
			// prefix
			out.println("            write((" + s.type + ")o, out);");
		}
		out.println("        } else {");
		out.println("            write((TODOS)o, out);");
		out.println("        }");
		out.println("    }");

		for (Struct s : mso.structs) {
			printStructureParser(out, s);
			printStructureWriter(out, s);
		}

		out.println("}");

		for (Struct s : mso.structs) {
			printStructureClass(out, s);
		}

		out.close();
		fout.close();
	}

	void printStructureParser(PrintWriter out, Struct s) {
		out.println("    " + s.name + " parse" + s.name
				+ "(LEInputStream in) throws IOException  {");
		out.println("        " + s.name + " _s = new " + s.name + "();");
		if (s.containsKnownLengthArrayMember) {
			out.println("        int _c;");
		}
		if (s.containsOptionalMember || s.containsUnknownLengthArrayMember
				|| s.containsChoice) {
			out.println("        Object _m;");
		}
		if (s.containsUnknownLengthArrayMember) {
			out.println("        boolean _atend;");
			out.println("        int _i;");
		}
		for (Member m : s.members) {
			printStructureMemberParser(out, m);
		}
		if (s.name.contains("RecordHeader")) {
			out.println("System.out.println(in.getPosition()+\" \"+_s);");
		}
		out.println("        return _s;");
		out.println("    }");
	}

	void printStructureWriter(PrintWriter out, Struct s) {
		out.println("    void write(" + s.name
				+ " _s, LEOutputStream out) throws IOException  {");
		for (Member m : s.members) {
			printStructureMemberWriter(out, m);
		}
		out.println("    }");
	}

	void printStructureMemberWriter(PrintWriter out, Member m) {
		String s = "        ";
		if (m.condition != null) {
			out.println("        if (" + getExpression("_s", m.condition)
					+ ") {");
			s = s + "    ";
		}
		if (m.isChoice) {
			boolean first = true;
			Choice c = (Choice) m.type();
			for (String t : c.getChoiceNames()) {
				out.print(s);
				if (!first) {
					out.print("} else ");
				}
				first = false;
				out.println("if (_s." + m.name + " instanceof " + t + ") {");
				out
						.println(s + "    write((" + t + ")_s." + m.name
								+ ", out);");
			}
			out.println(s + "}");
		} else if (m.isArray) {
			String t = getTypeName(m);
			out.println(s + "for (" + t + " _i: _s." + m.name + ") {");
			if (m.isStruct) {
				out.println(s + "    write(_i, out);");
			} else {
				out.println(s + "    out.write" + m.type().name + "(_i);");
			}
			out.println(s + "}");
		} else if (m.isStruct) {
			out.print(s);
			if (m.isOptional) {
				out.print("if (_s." + m.name + " != null) ");
			}
			out.println("write(_s." + m.name + ", out);");
		} else {
			out.println(s + "out.write" + m.type().name + "(_s." + m.name
					+ ");");
		}
		if (m.condition != null) {
			out.println("        }");
		}
	}

	String getTypeName(Member m) {
		final TypeRegistry.Type t = m.type();
		final TypeRegistry r = m.registry;
		if (t instanceof Struct) {
			return m.type().name;
		} else if (t instanceof Choice) {
			return "Object";
		} else if (t == r.bit) {
			return "boolean";
		} else if (t == r.uint2 || t == r.uint3 || t == r.uint4 || t == r.uint5
				|| t == r.uint6 || t == r.uint7 || t == r.uint8) {
			return "byte";
		} else if (t == r.uint9 || t == r.uint12 || t == r.uint14
				|| t == r.uint15 || t == r.int16) {
			return "short";
		} else if (t == r.uint16 || t == r.uint20 || t == r.uint30
				|| t == r.uint32 || t == r.int32) {
			return "int";
		}
		return t.name;
	}

	String getMemberDeclaration(Member m) {
		if (m.isArray) {
			if (m.count == null) {
				return "final java.util.List<" + m.type().name + "> " + m.name
						+ " = new java.util.ArrayList<" + m.type().name + ">()";
			} else {
				return getTypeName(m) + "[] " + m.name;
			}
		} else {
			return getTypeName(m) + " " + m.name;
		}
	}

	void printStructureClass(PrintWriter out, Struct s) {
		out.println("class " + s.name + " {");
		for (Member m : s.members) {
			String d = getMemberDeclaration(m);
			out.println("    " + d + ";");
		}

		// function toString
		out.println("    public String toString() {");
		out.println("        String _s = \"" + s.name + ":\";");
		for (Member m : s.members) {
			out.print("        _s = _s + \"" + m.name
					+ ": \" + String.valueOf(" + m.name + ") + \"");
			if (m.isInteger && !m.isArray) {
				out.print("(\" + Integer.toHexString(" + m.name
						+ ").toUpperCase() + \")");
			}
			out.println(", \";");
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

	void printStructureMemberParser(PrintWriter out, Member m) {
		String s = "        ";
		String condition = null;
		if (m.condition != null) {
			condition = prependStructureToExpression(m.condition, "_s");
			s = s + "    ";
			out.println("        if (" + condition + ") {");
		}
		String count = null;
		if (m.count != null) {
			count = prependStructureToExpression(m.count, "_s");
		}
		String parse;
		if (m.isStruct) {
			parse = "parse" + m.type().name + "(in);";
		} else {
			parse = "in.read" + m.type().name + "();";
		}

		if (m.isChoice) {
			printChoiceParser(out, s, m);
			return;
		}
		if (m.isArray && m.count == null) {
			if (m.size != null) {
				printFixedSizeArrayParser(out, s, m);
			} else {
				// array for which no size is given: parse items until one fails
				printVariableArrayParser(out, s, m);
			}
			return;
		}
		if (m.isOptional) {
			printOptionalMemberParser(out, s, m);
			return;
		}
		if (count != null) {
			out.println(s + "_c = " + count + ";");
		}
		out.print(s + "_s." + m.name + " = ");
		if (count != null) {
			if (m.type() == m.registry.uint8) {
				out.println("in.readBytes(_c);");
			} else {
				out.println("new " + getTypeName(m) + "[_c];");
				out.println(s + "for (int _j=0; _j<_c; ++_j) {");
				out.println(s + "    _s." + m.name + "[_j] = " + parse);
				printLimitationCheck(out, "            ", "_s." + m.name
						+ "[_j]", m);
				out.println(s + "}");
			}
		} else {
			out.println(parse);
			printLimitationCheck(out, "        ", "_s." + m.name, m);
		}
		if (condition != null) {
			out.println("        }");
		}
	}

	void printChoiceParser(PrintWriter out, String s, Member m) {
		String closing = "";
		String exception = "_x";
		out.println(s + "_m = in.setMark();");
		Choice c = (Choice) m.type();
		String choices[] = c.getChoiceNames();
		int length = (m.isOptional) ? choices.length : choices.length - 1;
		for (int i = 0; i < length; ++i) {
			out.println(s + "try {");
			out.println(s + "    _s." + m.name + " = parse" + choices[i]
					+ "(in);");
			out.println(s + "} catch (IOException " + exception + ") {");
			out.println(s + "    if (!(" + exception
					+ " instanceof IncorrectValueException) && !(" + exception
					+ " instanceof java.io.EOFException)) throw " + exception
					+ ";");
			// out
			// .println(s
			// + "    if (in.distanceFromMark(_m) > 16) throw new IOException("
			// + exception + ");//onlyfordebug");
			out.println(s + "    in.rewind(_m);");
			exception = exception + "x";
			closing = closing + "}";
		}
		if (!m.isOptional) {
			out.println(s + "    _s." + m.name + " = parse"
					+ choices[choices.length - 1] + "(in);");
		}
		out.println(s + closing + " finally {");
		out.println(s + "    in.releaseMark(_m);");
		out.println(s + "}");
	}

	void printFixedSizeArrayParser(PrintWriter out, String s, Member m) {
		out.println(s + "int _startPos = in.getPosition();");
		out.println(s + "while (in.getPosition() - _startPos < "
				+ getExpression("_s", m.size) + ") {");
		out.println(s + "    " + m.type().name + " _t = parse" + m.type().name
				+ "(in);");
		out.println(s + "    _s." + m.name + ".add(_t);");
		out.println(s + "}");
	}

	void printVariableArrayParser(PrintWriter out, String s, Member m) {
		out.println(s + "_atend = false;");
		out.println(s + "_i=0;");
		out.println(s + "while (!_atend) {");
		// out
		// .println(s
		// +
		// "    System.out.println(\"round \"+(_i++) + \" \" + in.getPosition());");
		out.println(s + "    _m = in.setMark();");
		out.println(s + "    try {");
		out.println(s + "        " + m.type().name + " _t = parse"
				+ m.type().name + "(in);");
		out.println(s + "        _s." + m.name + ".add(_t);");
		out.println(s + "    } catch(IncorrectValueException _e) {");
		// out
		// .println(s
		// +
		// "    if (in.distanceFromMark(_m) > 16) throw new IOException(_e);//onlyfordebug");
		out.println(s + "        _atend = true;");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    } catch(java.io.EOFException _e) {");
		out.println(s + "        _atend = true;");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    } finally {");
		out.println(s + "        in.releaseMark(_m);");
		out.println(s + "   }");
		out.println(s + "}");
	}

	void printOptionalMemberParser(PrintWriter out, String s, Member m) {
		out.println(s + "_m = in.setMark();");
		out.println(s + "try {");
		out.println(s + "    _s." + m.name + " = parse" + m.type().name
				+ "(in);");
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

	void printLimitationCheck(PrintWriter out, String s, String name, Member m) {
		for (Limitation l : m.limitations) {
			String mname = l.name;
			if (!"".equals(mname)) {
				mname = name + "." + mname;
			} else {
				mname = name;
			}
			String condition;
			if (l.expression == null) {
				condition = getCondition(mname, l);
			} else {
				condition = getExpression(mname, l.expression);
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
			out.println(s + "    throw new " + exceptionType
					+ "(in.getPosition() + \"" + condition
					+ " for value \" + String.valueOf(" + name + ") );");
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
		return name + cmp + value;
	}
}
