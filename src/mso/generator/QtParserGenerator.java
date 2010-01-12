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
		out.println("#include <QSharedPointer>");
		out.println("#include <QXmlStreamReader>");
		out.println("#include \"leinputstream.h\"");
		out.println("#include \"leoutputstream.h\"");
		out.println("#include \"introspection.h\"");
		out.println("namespace {");

		out.println("void skipToStartElement(QXmlStreamReader& in) {");
		out.println("    do {");
		out.println("        in.readNext();");
		out.println("    } while (!in.atEnd() && !in.isStartElement());");
		out.println("}");

		for (Struct s : mso.structs) {
			out.println("class " + s.name + ";");
			out.println("void parse" + s.name + "(LEInputStream& in, " + s.name
					+ "& _s);");
			out.println("void parse" + s.name + "(QXmlStreamReader& in, "
					+ s.name + "& _s);");
			out.println("void write(const " + s.name
					+ "& v, LEOutputStream& out);");
		}

		for (Struct s : mso.structs) {
			printStructureClassDeclaration(out, s);
		}

		for (Struct s : mso.structs) {
			printStructureClassImplementation(out, s);
		}

		for (Struct s : mso.structs) {
			printStructureParser(out, s);
			printStructureWriter(out, s);
			printStructureXmlParser(out, s);
		}

		out.println("}");

		out
				.println("const Introspectable* parse(const QString& key, LEInputStream& in) {");
		out.println("    const Introspectable* i = 0;");
		boolean first = true;
		for (Stream s : mso.streams) {
			out.print("    ");
			if (first) {
				first = false;
			} else {
				out.print("} else ");
			}
			out.println("if (\"" + s.key + "\" == key) {"); // TODO: fix for
			// \001 and \005
			// prefix
			out.println("        " + s.type + " *_t = new " + s.type + "(0);");
			out.println("        parse" + s.type + "(in, *_t);");
			out.println("        i = _t;");
		}
		out.println("    } else {");
		out.println("        TODOS* _t = new TODOS(0);");
		out.println("        parseTODOS(in, *_t);");
		out.println("        i = _t;");
		out.println("    }");
		out.println("    return i;");
		out.println("}");

		out
				.println("const QMap<QString,QSharedPointer<const Introspectable> > parse(QXmlStreamReader& in) {");
		out
				.println("    QMap<QString,QSharedPointer<const Introspectable> > streams;");
		out.println("    // skip until first element");
		out.println("    while (!in.atEnd() && !in.isStartElement()) {");
		out.println("        in.readNext();");
		out.println("    }");
		out.println("    if (!in.isStartElement()) {");
		out.println("        return streams;");
		out.println("    }");
		out.println("    do {");
		out.println("        in.readNext();");
		out.println("    } while (!in.atEnd() && !in.isStartElement());");
		out.println("    if (!in.isStartElement()) {");
		out.println("        return streams;");
		out.println("    }");
		out.println("    do {");
		out.println("        QString name = in.name().toString();");
		out.println("        if (streams.contains(name)) {");
		out.println("            streams.clear();");
		out.println("            return streams;");
		out.println("        }");
		first = true;
		for (Stream s : mso.streams) {
			out.print("        ");
			if (first) {
				first = false;
			} else {
				out.print("} else ");
			}
			out.println("if (\"" + s.key + "\" == name) {");
			out.println("            QSharedPointer<Introspectable> _t(new "
					+ s.type + "(0));");
			out.println("            parse" + s.type + "(in, *static_cast<"
					+ s.type + "*>(_t.data()));");
			// out.println("            QSharedPointer<Introspectable> _t(new PowerPointStructs());");
			// out.println("            parsePowerPointStructs(in, *static_cast<PowerPointStructs*>(_t.data()));");
			out.println("            streams[name] = _t;");
		}
		out.println("        } else { // unknown stream should be binary");
		out
				.println("            QSharedPointer<Introspectable> _t(new TODOS(0));");
		out
				.println("            parseTODOS(in, *static_cast<TODOS*>(_t.data()));");
		out.println("            streams[name] = _t;");
		out.println("        }");
		out.println("        do {");
		out.println("            in.readNext();");
		out.println("        } while (in.isWhitespace());");
		out.println("    } while (in.isStartElement());");
		out.println("    qDebug() << in.tokenType();");
		out.println("    if (!in.isEndElement()) {");
		out
				.println("        qDebug() << \"parsing error: not at end of an element\";");
		out.println("        streams.clear();");
		out.println("    }");
		out.println("    in.readNext();");
		out.println("    if (!in.isEndDocument()) {");
		out
				.println("        qDebug() << \"parsing error: not at end of xml\";");
		out.println("        streams.clear();");
		out.println("    }");
		out.println("    return streams;");
		out.println("}");

		out
				.println("void serialize(const Introspectable* i, const QString& key, LEOutputStream& out)  {");
		first = true;
		for (Stream s : mso.streams) {
			out.print("    ");
			if (first) {
				first = false;
			} else {
				out.print("} else ");
			}
			out.println("if (\"" + s.key + "\" == key) {"); // TODO: fix for
			// \001 and \005
			// prefix
			out.println("        write(*static_cast<const " + s.type
					+ "*>(i), out);");
		}
		out.println("    } else {");
		out.println("        write(*static_cast<const TODOS*>(i), out);");
		out.println("    }");
		out.println("}");

		out.close();
		fout.close();
	}

	void printStructureParser(PrintWriter out, Struct s) {
		out.println("void parse" + s.name + "(LEInputStream& in, " + s.name
				+ "& _s) {");
		out.println("    _s.streamOffset = in.getPosition();");
		if (s.containsKnownLengthArrayMember) {
			out.println("    int _c;");
		}
		if (s.containsArrayMember || s.containsOptionalMember
				|| s.containsChoice) {
			out.println("    LEInputStream::Mark _m;");
		}
		if (s.containsUnknownLengthArrayMember) {
			out.println("    bool _atend;");
		}
		for (Member m : s.members) {
			printStructureMemberParser(out, m);
			if (m.type.contains("RecordHeader")) {
			//	out.println("qDebug() << in.getPosition()<<\" \"<<\"" + s.name
			//			+ "\"<<_s.rh.toString();");
			}
		}
		out.println("}");
	}

	void printStructureXmlParser(PrintWriter out, Struct s) {
		out.println("void parse" + s.name + "(QXmlStreamReader& in, " + s.name
				+ "& _s) {");
		out.println("    in.readNext();");
		for (Member m : s.members) {
			printStructureMemberXmlParser(out, m);
		}
		/*
		 * out.println("    int depth = 0;");
		 * out.println("    while (!in.atEnd()) {");
		 * out.println("        if (type == QXmlStreamReader::StartElement) {");
		 * out.println("            depth++;");
		 * out.println("        } else if (type == QXmlStreamReader::EndElement "
		 * + "&& --depth < 0) {"); out.println("            return;");
		 * out.println("        }");
		 * out.println("        type = in.readNext();"); out.println("    }");
		 */
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
		String index = (m.count == null) ? "" : "[_i]";
		if (m.condition != null) {
			String condition = prependStructureToExpression(m.condition, "_s");
			if (!m.isComplex) {
				out.println(s + "_s._has_" + m.name + " = " + condition + ";");
				out.println(s + "if (_s._has_" + m.name + ") {");

			} else {
				out.println(s + "if (" + condition + ") {");
			}
			s = s + "    ";
			if (m.isComplex) {
				out.println(s + "_s." + m.name + " = QSharedPointer<" + m.type
						+ ">(new " + m.type + "(&_s));");
				index = ".data()";
			}
		}
		String parse;
		if (m.isComplex) {
			String star = (m.condition == null) ? "" : "*";
			parse = "parse" + m.type + "(in, " + star + "_s." + m.name + index
					+ ");";
		} else {
			parse = "_s." + m.name + index + " = in.read" + m.type + "();";
		}
		if (m.choices != null) {
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
		if (m.count != null) {
			String count = prependStructureToExpression(m.count, "_s");
			out.println(s + "_c = " + count + ";");
		}
		if (m.count != null) {
			if (!m.isComplex) {
				out.println(s + "_s." + m.name + ".resize(_c);");
			}
			if (m.type.equals("uint8")) { // special case for reading bytearrays
				// quickly
				out.println(s + "in.readBytes(_s." + m.name + ");");
			} else {
				out.println(s + "for (int _i=0; _i<_c; ++_i) {");
				if (m.isComplex) {
					out.println(s + "    _s." + m.name + ".append(" + m.type
							+ "(&_s));");
				}
				out.println(s + "    " + parse);
				printLimitationCheck(out, "        ", "_s." + m.name + "[_i]",
						m);
				out.println(s + "}");
			}
		} else {
			out.println(s + parse);
			printLimitationCheck(out, s, "_s." + m.name, m);
		}
		if (m.condition != null) {
			out.println("    }");
		}
	}

	void printStructureMemberXmlParser(PrintWriter out, Member m) {
		String s = "    ";

		out.println(s + "if (!in.isStartElement()) {");
		out.println(s + "    qDebug() << \"not startelement in " + m.type
				+ " \" << in.lineNumber();");
		out.println(s + "    return;");
		out.println(s + "}");
		if (!m.isOptional && !m.isArray) {
			out.println(s + "if (in.name() != \"" + m.name + "\") {");
			out.println(s + "    qDebug() << \"not startelement in " + m.name
					+ " \" << in.lineNumber();");
			out.println(s + "    return;");
			out.println(s + "}");
		}
		if (m.isOptional) {
			out.println(s + "if (in.name() == \"" + m.name + "\") {");
			s = s + "    ";
		}
		if (!m.isComplex) {
			out.println(s + "in.readElementText();");
		} else {
			out.println(s + "skipToStartElement(in);");
			// out.println(s + "parse" + m.type + "(in, _s." + m.name + ");");
		}
		// out.println(s + "if (in.name() == \"" + m.name + "\") {");
		if (m.isOptional) {
			out.println("    }");
		}
	}

	void printStructureWriter(PrintWriter out, Struct s) {
		out.println("void write(const " + s.name
				+ "& _s, LEOutputStream& out) {");
		for (Member m : s.members) {
			printStructureMemberWriter(out, m);
		}
		out.println("}");
	}

	void printStructureMemberWriter(PrintWriter out, Member m) {
		String s = "    ";
		if (m.condition != null) {
			out.println("    if (" + getExpression("_s", m.condition) + ") {");
			s = s + "    ";
		}
		if (m.choices != null) {
			boolean first = true;
			for (String t : m.choices.getChoiceNames()) {
				out.print(s);
				if (!first) {
					out.print("} else ");
				}
				first = false;
				out.println("if (_s." + m.name + "." + t.toLowerCase() + ") {");
				out.println(s + "    write(*_s." + m.name + "."
						+ t.toLowerCase() + ", out);");
			}
			out.println(s + "}");
		} else if (m.isArray) {
			if (m.type.equals("uint8")) {
				out.println(s + "out.writeBytes(_s." + m.name + ");");
			} else {
				String t = getTypeName(m);
				out.println(s + "foreach (" + t + " _i, _s." + m.name + ") {");
				if (m.isComplex) {
					out.println(s + "    write(_i, out);");
				} else {
					out.println(s + "    out.write" + m.type + "(_i);");
				}
				out.println(s + "}");
			}
		} else if (m.isComplex) {
			out.print(s);
			if (m.isOptional || m.condition != null) {
				out.print("if (_s." + m.name + ") write(*");
			} else {
				out.print("write(");
			}
			out.println("_s." + m.name + ", out);");
		} else {
			out.println(s + "out.write" + m.type + "(_s." + m.name + ");");
		}
		if (m.condition != null) {
			out.println("    }");
		}
	}

	String getTypeName(Member m) {
		String t = m.type;
		if (m.isComplex) {
			return t;
		} else if ("bit".equals(t)) {
			return "bool";
		} else if ("uint2".equals(t) || "uint3".equals(t) || "uint4".equals(t)
				|| "uint5".equals(t) || "uint6".equals(t) || "uint7".equals(t)
				|| "uint8".equals(t)) {
			return "quint8";
		} else if ("uint9".equals(t) || "uint12".equals(t)
				|| "uint14".equals(t) || "uint15".equals(t)
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
			String choice = "class " + m.name + "Choice {public:";
			for (String c : m.choices.getChoiceNames()) {
				choice = choice + "QSharedPointer<" + c + "> "
						+ c.toLowerCase() + ";\n";
			}
			choice = choice + "}; " + m.name + "Choice";
			return choice;
		} else {
			return t;
		}
	}

	String getMemberDeclaration(Member m) {
		if (m.isArray) {
			if (m.isComplex) {
				return "QList<" + m.type + "> " + m.name;
			} else {
				if ("quint8".equals(getTypeName(m))) {
					return "QByteArray " + m.name;
				} else {
					return "QVector<" + getTypeName(m) + "> " + m.name;
				}
			}
		} else if (m.isComplex && (m.isOptional || m.condition != null)) {
			return "QSharedPointer<" + getTypeName(m) + "> " + m.name;
		}
		return getTypeName(m) + " " + m.name;
	}

	String memberToString(Member m, String prefix) {
		String s;
		String mn = prefix + m.name;
		if (m.isArray) {
			s = "\"[array of " + mn + "]\"";
		} else {
			if (m.isInteger) {// m.type.contains("int") ||
				// m.type.equals("bit")) {
				s = "QString::number(" + mn + ") + \"(\" + QString::number("
						+ mn + ",16).toUpper() + \")\"";
			} else if (m.type.equals("bit")) {
				s = "QString::number(" + mn + ")";
			} else if (m.choices != null) {
				s = "\"<choice>\"";
			} else if (m.isOptional || m.condition != null) {
				s = "((" + mn + ")?" + mn + "->toString() :\"null\")";
			} else {
				s = mn + ".toString()";
			}
		}
		return s;
	}

	void printStructureClassDeclaration(PrintWriter out, Struct s) {
		out.println("class " + s.name + " : public Introspectable {");
		out.println("private:");
		out.println("    class _Introspection;");
		out.println("public:");
		out.println("    static const Introspection _introspection;");
		for (Member m : s.members) {
			if (!m.isComplex && m.condition != null) {
				out.println("    bool _has_" + m.name + ";");
			}
		}
		for (Member m : s.members) {
			String d = getMemberDeclaration(m);
			out.println("    " + d + ";");
		}
		out.print("    " + s.name
				+ "(const Introspectable* parent) :Introspectable(parent)");
		for (Member m : s.members) {
			if (m.isComplex && !m.isArray && !m.isOptional && m.choices == null
					&& m.condition == null) {
				out.println(",");
				out.print("        " + m.name + "(this)");
			}
		}
		out.println(" {");
		out.println("    }");

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

		out
				.println("    const Introspection* getIntrospection() const { return &_introspection; }");

		out.println("};");

	}

	void printStructureClassImplementation(PrintWriter out, Struct s) {
		final int nm = s.members.size();
		final String ns = s.name + "::_Introspection";
		out.println("class " + ns + " {");
		out.println("public:");
		out.println("    static const QString name;");
		out.println("    static const int numberOfMembers;");
		out.println("    static const QString names[" + nm + "];");
		// out.println("    static const Introspection* const introspections["
		// + nm + "];");
		out.println("    static int (* const numberOfInstances[" + nm
				+ "])(const Introspectable*);");
		out.println("    static QVariant (* const value[" + nm
				+ "])(const Introspectable*, int position);");
		out.println("    static const Introspectable* (* const introspectable["
				+ nm + "])(const Introspectable*, int position);");
		for (Member m : s.members) {
			if (!m.isComplex && m.choices == null) {
				if (m.condition != null) {
					out.println("    static int count_" + m.name
							+ "(const Introspectable* i) {");
					out.println("        return static_cast<const " + s.name
							+ "*>(i)->_has_" + m.name + " ?1 :0;");
					out.println("    }");
				}
			} else if (m.isOptional || m.condition != null) {
				out.println("    static int count_" + m.name
						+ "(const Introspectable* i) {");
				out.println("        return get_" + m.name + "(i, 0) ?1 :0;");
				out.println("    }");
			} else if (m.isArray) {
				out.println("    static int count_" + m.name
						+ "(const Introspectable* i) {");
				out.println("        return static_cast<const " + s.name
						+ "*>(i)->" + m.name + ".size();");
				out.println("    }");
			}
			if (m.isComplex || m.choices != null) {
				out.println("    static const Introspectable* get_" + m.name
						+ "(const Introspectable* i, int j) {");
			} else {
				out.println("    static QVariant get_" + m.name
						+ "(const Introspectable* i, int j) {");
			}
			String dm = "static_cast<const " + s.name + "*>(i)->" + m.name + "";
			if (m.choices == null) {
				out.print("        ");
				if (!m.isComplex) {
					if (m.isArray && m.type != "uint8") {
						out.println("return qVariantFromValue(" + dm + ");");
					} else {
						out.println("return " + dm + ";");
					}
				} else if (m.isArray) {
					out.println("return &(" + dm + "[j]);");
				} else if (m.isOptional || m.condition != null) {
					out.println("return " + dm + ".data();");
				} else {
					out.println("return &(" + dm + ");");
				}
			} else {
				out.println("        const Introspectable* k = 0;");
				for (String c : m.choices.getChoiceNames()) {
					out.println("        if (k == 0) k = static_cast<const "
							+ s.name + "*>(i)->" + m.name + "."
							+ c.toLowerCase() + ".data();");
				}
				out.println("        return k;");
			}
			out.println("    }");
		}
		out.println("};");
		out.println("const QString " + ns + "::name(\"" + s.name + "\");");
		out.println("const int " + ns + "::numberOfMembers(" + nm + ");");
		out.println("const QString " + ns + "::names[" + nm + "] = {");
		for (Member m : s.members) {
			out.println("    \"" + m.name + "\",");
		}
		out.println("};");
		out.println("int (* const " + ns + "::numberOfInstances[" + nm
				+ "])(const Introspectable*) = {");
		for (Member m : s.members) {
			if (m.condition != null
					|| ((m.isComplex || m.choices != null) && (m.isOptional || m.isArray))) {
				out.println("    _Introspection::count_" + m.name + ",");
			} else {
				// arrays of simple types count as one instance
				out.println("    Introspection::one,");
			}
		}
		out.println("};");
		out.println("QVariant (* const " + ns + "::value[" + nm
				+ "])(const Introspectable*, int position) = {");
		for (Member m : s.members) {
			if (m.isComplex || m.choices != null) {
				out.println("    Introspection::nullValue,");
			} else {
				out.println("    _Introspection::get_" + m.name + ",");
			}
		}
		out.println("};");
		out.println("const Introspectable* (* const " + ns
				+ "::introspectable[" + nm
				+ "])(const Introspectable*, int position) = {");
		for (Member m : s.members) {
			if (m.isComplex || m.choices != null) {
				out.println("    _Introspection::get_" + m.name + ",");
			} else {
				out.println("    Introspection::null,");
			}
		}
		out.println("};");
		out.println("const Introspection " + s.name + "::_introspection(");
		out
				.println("    \""
						+ s.name
						+ "\", "
						+ s.members.size()
						+ ", _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);");
	}

	void printChoiceParser(PrintWriter out, String s, Member m) {
		String closing = "";
		String exception = "_x";
		String choice;
		out.println(s + "_m = in.setMark();");
		String choices[] = m.choices.getChoiceNames();
		int length = (m.isOptional) ? choices.length : choices.length - 1;
		for (int i = 0; i < length; ++i) {
			choice = choices[i];
			out.println(s + "try {");
			out.println(s + "    _s." + m.name + "." + choice.toLowerCase()
					+ " = QSharedPointer<" + choice + ">(" + "new " + choice
					+ "(&_s));");
			out.println(s + "    parse" + choice + "(in, *_s." + m.name + "."
					+ choice.toLowerCase() + ".data());");
			out.println(s + "} catch (IncorrectValueException " + exception
					+ ") {");
			out.println(s + "    _s." + m.name + "." + choice.toLowerCase()
					+ ".clear();");
			out.println(s + "    in.rewind(_m);");
			exception = exception + "x";
			closing = closing + "}";
		}
		if (!m.isOptional) {
			choice = choices[choices.length - 1];
			out.println(s + "    _s." + m.name + "." + choice.toLowerCase()
					+ " = QSharedPointer<" + choice + ">(" + "new " + choice
					+ "(&_s));");
			out.println(s + "    parse" + choice + "(in, *_s." + m.name + "."
					+ choice.toLowerCase() + ");");
		}
		out.println(s + closing);
	}

	void printFixedSizeArrayParser(PrintWriter out, String s, Member m) {
		out.println(s + "int _startPos = in.getPosition();");
		out.println(s + "_atend = in.getPosition() - _startPos >= "
				+ getExpression("_s", m.size) + ";");
		out.println(s + "while (!_atend) {");
		out.println(s + "    _s." + m.name + ".append(&_s);");
		out.println(s + "    parse" + m.type + "(in, _s." + m.name
				+ ".last());");
		out.println(s + "    _atend = in.getPosition() - _startPos >= "
				+ getExpression("_s", m.size) + ";");
		out.println(s + "}");
	}

	void printVariableArrayParser(PrintWriter out, String s, Member m) {
		out.println(s + "_atend = false;");
		out.println(s + "while (!_atend) {");
		out.println(s + "    _m = in.setMark();");
		out.println(s + "    try {");
		out.println(s + "        _s." + m.name + ".append(&_s);");
		out.println(s + "        parse" + m.type + "(in, _s." + m.name
				+ ".last());");
		out.println(s + "    } catch(IncorrectValueException _e) {");
		out.println(s + "        _s." + m.name + ".removeLast();");
		out.println(s + "        _atend = true;");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    } catch(EOFException _e) {");
		out.println(s + "        _s." + m.name + ".removeLast();");
		out.println(s + "        _atend = true;");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    }");
		out.println(s + "}");
	}

	void printOptionalMemberParser(PrintWriter out, String s, Member m) {
		out.println(s + "_m = in.setMark();");
		out.println(s + "try {");
		// out.println(s + "    " + m.type + " _t;");
		out.println(s + "    _s." + m.name + " = QSharedPointer<" + m.type
				+ ">(new " + m.type + "(&_s));");
		out.println(s + "    parse" + m.type + "(in, *_s." + m.name
				+ ".data());");
		out.println(s + "} catch(IncorrectValueException _e) {");
		out.println(s + "    _s." + m.name + ".clear();");
		out.println(s + "    in.rewind(_m);");
		out.println(s + "} catch(EOFException _e) {");
		out.println(s + "    _s." + m.name + ".clear();");
		out.println(s + "    in.rewind(_m);");
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
			if (!m.isComplex) {
				mname = "((" + getTypeName(m) + ")" + mname + ")";
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
					+ "(in.getPosition(), \"" + condition + "\");");
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
