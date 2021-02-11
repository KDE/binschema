package mso.generator;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.eclipse.jdt.annotation.Nullable;

import mso.generator.utils.Choice;
import mso.generator.utils.Lim;
import mso.generator.utils.Limitation;
import mso.generator.utils.MSO;
import mso.generator.utils.Member;
import mso.generator.utils.Option;
import mso.generator.utils.Stream;
import mso.generator.utils.Struct;
import mso.generator.utils.Type;
import mso.generator.utils.TypeRegistry;

public class QtParserGenerator {

	public class QtParserConfiguration {
		@Nullable
		public final String namespace;
		public final String basename;
		public final String outputdir;
		public boolean createHeader;
		public boolean enableXml;
		public boolean enableWriting;
		public boolean enableIntrospection;
		public boolean enableToString;
		public boolean enableStyleTextPropAtomFix;

		QtParserConfiguration(@Nullable String namespace, String basename,
				String outputdir) {
			this.namespace = namespace;
			this.basename = basename;
			this.outputdir = outputdir;
		}
	}

	final public QtParserConfiguration config;

	final private String generatedWarning = "/* This code was generated by msoscheme (https://invent.kde.org/libraries/binschema/) */";

	private static String version() {
		return "/* version " + ParserGeneratorRunner.version + " */";
	}

	public QtParserGenerator(@Nullable String namespace, String basename,
			String outputdir) {
		config = new QtParserConfiguration(namespace, basename, outputdir);
	}

	void generate(MSO mso) throws IOException {
		FileWriter fout;
		if (config.createHeader) {
			fout = new FileWriter(
					config.outputdir + File.separator + config.basename + ".h");
		} else {
			fout = new FileWriter(config.outputdir + File.separator
					+ config.basename + ".cpp");
		}
		PrintWriter out = new PrintWriter(fout);
		out.println(generatedWarning);
		out.println(version());
		if (config.createHeader) {
			out.println("#ifndef " + config.basename.toUpperCase() + "_H");
			out.println("#define " + config.basename.toUpperCase() + "_H");
		}
		out.println("#include <QString>");
		out.println("#include <QByteArray>");
		out.println("#include <QVector>");
		out.println(
				"#include <QSharedPointer>// replace with QScopedPointer when switching to Qt 4.6");
		if (config.enableXml) {
			out.println("#include <QXmlStreamReader>");
		}
		if (config.enableWriting) {
			out.println("#include \"leoutputstream.h\"");
		}
		if (config.enableIntrospection) {
			out.println("#include \"introspection.h\"");
		}
		out.println("class LEInputStream;");
		out.println("namespace " + config.namespace + "{");

		if (config.enableXml) {
			out.println("void skipToStartElement(QXmlStreamReader& in) {");
			out.println("    do {");
			out.println("        in.readNext();");
			out.println("    } while (!in.atEnd() && !in.isStartElement());");
			out.println("}");
		}

		if (!config.enableIntrospection) {
			out.println("class StreamOffset {");
			out.println("public:");
			out.println("    virtual ~StreamOffset() {}");
			out.println("    quint32 streamOffset;");
			out.println("};");
		}

		for (Struct s : mso.structs) {
			out.println("class " + s.name + ";");
			out.println("void parse" + s.name + "(LEInputStream& in, " + s.name
					+ "& _s);");
			if (config.enableXml) {
				out.println("void parse" + s.name + "(QXmlStreamReader& in, "
						+ s.name + "& _s);");
			}
			if (config.enableWriting) {
				out.println("void write(const " + s.name
						+ "& v, LEOutputStream& out);");
			}
		}

		for (Struct s : mso.structs) {
			printStructureClassDeclaration(out, s);
		}

		if (config.createHeader) {
			out.println("} // close namespace");
			out.println("#endif");
			out.close();
			fout = new FileWriter(config.outputdir + File.separator
					+ config.basename + ".cpp");
			out = new PrintWriter(fout);
			out.println(generatedWarning);
			out.println(version());
			out.println("#include \"" + config.basename + ".h\"");
			out.println("using namespace " + config.namespace + ";");
		}
		out.println("#include \"leinputstream.h\"");

		if (config.enableIntrospection) {
			for (Struct s : mso.structs) {
				printStructureClassImplementation(out, s);
			}
		}

		for (Struct s : mso.structs) {
			printStructureParser(out, s);
			if (config.enableWriting) {
				printStructureWriter(out, s);
			}
			if (config.enableXml) {
				printStructureXmlParser(out, s);
			}
		}

		if (!config.createHeader) {
			out.println("}");// close namespace
		}

		if (config.enableIntrospection) {
			out.println(
					"const Introspectable* parse(const QString& key, LEInputStream& in) {");
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
				out.println(
						"        " + s.type + " *_t = new " + s.type + "(0);");
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
		}

		if (config.enableXml) {
			out.println(
					"const QMap<QString,QSharedPointer<const Introspectable> > parse(QXmlStreamReader& in) {");
			out.println(
					"    QMap<QString,QSharedPointer<const Introspectable> > streams;");
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
			boolean first = true;
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
				// out.println(" QSharedPointer<Introspectable> _t(new
				// PowerPointStructs());");
				// out.println(" parsePowerPointStructs(in,
				// *static_cast<PowerPointStructs*>(_t.data()));");
				out.println("            streams[name] = _t;");
			}
			out.println("        } else { // unknown stream should be binary");
			out.println(
					"            QSharedPointer<Introspectable> _t(new TODOS(0));");
			out.println(
					"            parseTODOS(in, *static_cast<TODOS*>(_t.data()));");
			out.println("            streams[name] = _t;");
			out.println("        }");
			out.println("        do {");
			out.println("            in.readNext();");
			out.println("        } while (in.isWhitespace());");
			out.println("    } while (in.isStartElement());");
			out.println("    qDebug() << in.tokenType();");
			out.println("    if (!in.isEndElement()) {");
			out.println(
					"        qDebug() << \"parsing error: not at end of an element\";");
			out.println("        streams.clear();");
			out.println("    }");
			out.println("    in.readNext();");
			out.println("    if (!in.isEndDocument()) {");
			out.println(
					"        qDebug() << \"parsing error: not at end of xml\";");
			out.println("        streams.clear();");
			out.println("    }");
			out.println("    return streams;");
			out.println("}");

			out.println(
					"void serialize(const Introspectable* i, const QString& key, LEOutputStream& out)  {");
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
		}
		out.close();
		fout.close();
	}

	private void printStructureParser(PrintWriter out, Struct s) {
		out.print("void ");
		if (config.namespace != null && config.namespace.length() > 0) {
			out.print(config.namespace + "::");
		}
		out.println(
				"parse" + s.name + "(LEInputStream& in, " + s.name + "& _s) {");
		out.println("    _s.streamOffset = in.getPosition();");
		if (s.containsKnownLengthArrayMember) {
			out.println("    int _c;");
		}
		if (s.containsArrayMember || s.containsOptionalMember
				|| s.containsChoice) {
			out.println("    LEInputStream::Mark _m;");
		}
		if (s.containsOptionalMember) {
			out.println("    bool _possiblyPresent;");
		}
		if (s.containsUnknownLengthArrayMember) {
			out.println("    bool _atend;");
		}
		for (Member m : s.members) {
			if (config.enableStyleTextPropAtomFix
					&& s.name.equals("StyleTextPropAtom")
					&& m.name.equals("todo")) {
				break;
			}
			printStructureMemberParser(out, s.name, m);
			if (m.type().name.contains("RecordHeader")) {
				// out.println("qDebug() << in.getPosition()<<\" \"<<\"" +
				// s.name
				// + "\"<<_s.rh.toString();");
			}
			if (config.enableStyleTextPropAtomFix
					&& s.name.equals("TextContainer")
					&& m.name.equals("style")) {
				styleTextPropAtomFix2(out);
			}
		}
		out.println("}");
	}

	private static void printStructureXmlParser(PrintWriter out, Struct s) {
		out.println("void parse" + s.name + "(QXmlStreamReader& in, " + s.name
				+ "& _s) {");
		out.println("    in.readNext();");
		for (Member m : s.members) {
			printStructureMemberXmlParser(out, m);
		}
		/*
		 * out.println("    int depth = 0;"); out.println(
		 * "    while (!in.atEnd()) {"); out.println(
		 * "        if (type == QXmlStreamReader::StartElement) {");
		 * out.println("            depth++;"); out.println(
		 * "        } else if (type == QXmlStreamReader::EndElement " +
		 * "&& --depth < 0) {"); out.println("            return;");
		 * out.println("        }"); out.println("        type = in.readNext();"
		 * ); out.println("    }");
		 */
		out.println("}");

	}

	private static String prependStructureToExpression(String expression,
			String structureName) {
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

	private void printStructureMemberParser(PrintWriter out, String structure,
			Member m) {
		String s = "    ";
		String index = (m.count == null) ? "" : "[_i]";
		if (m.condition != null) {
			String condition = prependStructureToExpression(m.condition, "_s");
			if (!m.isStruct) {
				out.println(s + "_s._has_" + m.name + " = " + condition + ";");
				out.println(s + "if (_s._has_" + m.name + ") {");
			} else {
				out.println(s + "if (" + condition + ") {");
			}
			s = s + "    ";
			if (m.isStruct) {
				out.println(s + "_s." + m.name + " = QSharedPointer<"
						+ m.type().name + ">(new " + m.type().name + "(&_s));");
				index = ".data()";
			}
		}
		String parse;
		if (m.isStruct) {
			String star = (m.condition == null) ? "" : "*";
			parse = "parse" + m.type().name + "(in, " + star + "_s." + m.name
					+ index + ");";
		} else {
			parse = "_s." + m.name + index + " = in.read" + m.type().name
					+ "();";
		}
		if (m.isChoice) {
			printChoiceParser(out, s, structure, m);
			return;
		}
		if (m.isArray && m.count == null) {
			if (m.size != null) {
				printFixedSizeArrayParser(out, s, m, m.size);
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
			if (!m.isStruct) {
				out.println(s + "_s." + m.name + ".resize(_c);");
			}
			if (m.type() == m.registry.uint8) { // special case for
				// reading bytearrays quickly
				out.println(s + "in.readBytes(_s." + m.name + ");");
			} else {
				out.println(s + "for (int _i=0; _i<_c; ++_i) {");
				if (m.isStruct) {
					out.println(s + "    _s." + m.name + ".append("
							+ m.type().name + "(&_s));");
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

	private static void printStructureMemberXmlParser(PrintWriter out,
			Member m) {
		String s = "    ";

		out.println(s + "if (!in.isStartElement()) {");
		out.println(s + "    qDebug() << \"not startelement in " + m.type().name
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
		if (!m.isStruct) {
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

	private void printStructureWriter(PrintWriter out, Struct s) {
		out.println(
				"void write(const " + s.name + "& _s, LEOutputStream& out) {");
		for (Member m : s.members) {
			printStructureMemberWriter(out, m);
		}
		out.println("}");
	}

	private void printStructureMemberWriter(PrintWriter out, Member m) {
		String s = "    ";
		if (m.condition != null) {
			out.println("    if (" + getExpression("_s", m.condition) + ") {");
			s = s + "    ";
		}
		if (m.isChoice) {
			boolean first = true;
			for (String t : ((Choice) m.type()).getChoiceNames()) {
				out.print(s);
				if (!first) {
					out.print("} else ");
				}
				first = false;
				out.println("if (_s." + m.name + ".is<" + t + ">()) {");
				out.println(s + "    write(*_s." + m.name + ".get<" + t
						+ ">(), out);");
			}
			out.println(s + "}");
		} else if (m.isArray) {
			if (m.type() == m.registry.uint8) {
				out.println(s + "out.writeBytes(_s." + m.name + ");");
			} else {
				String t = getTypeName(m.type());
				out.println(s + "foreach (" + t + " _i, _s." + m.name + ") {");
				if (m.isStruct) {
					out.println(s + "    write(_i, out);");
				} else {
					out.println(s + "    out.write" + m.type().name + "(_i);");
				}
				out.println(s + "}");
			}
		} else if (m.isStruct) {
			out.print(s);
			if (m.isOptional || m.condition != null) {
				out.print("if (_s." + m.name + ") write(*");
			} else {
				out.print("write(");
			}
			out.println("_s." + m.name + ", out);");
		} else {
			out.println(
					s + "out.write" + m.type().name + "(_s." + m.name + ");");
		}
		if (m.condition != null) {
			out.println("    }");
		}
	}

	private String getTypeName(Type t) {
		TypeRegistry r = t.registry;
		if (t instanceof Choice) {
			return createChoiceClass(t.name, (Choice) t);
		} else if (t == r.bit) {
			return "bool";
		} else if (t == r.uint2 || t == r.uint3 || t == r.uint4 || t == r.uint5
				|| t == r.uint6 || t == r.uint7 || t == r.uint8) {
			return "quint8";
		} else if (t == r.uint9 || t == r.uint12 || t == r.uint13
				|| t == r.uint14 || t == r.uint15 || t == r.uint16) {
			return "quint16";
		} else if (t == r.uint20 || t == r.uint30 || t == r.uint32) {
			return "quint32";
		} else if (t == r.int16) {
			return "qint16";
		} else if (t == r.int32) {
			return "qint32";
		}
		return t.name;
	}

	private String createChoiceClass(String name, Choice c) {
		String base = "StreamOffset";
		if (config.enableIntrospection) {
			base = "Introspectable";
		}
		String choice = "class " + name + " : public QSharedPointer<" + base
				+ "> {\n";
		choice += "    public:\n";
		choice += "        " + name + "() {}\n";
		for (String s : c.getChoiceNames()) {
			choice += "        explicit " + name + "(" + s
					+ "* a) :QSharedPointer<" + base + ">(a) {}\n";
		}
		choice += "        template <typename T> T*get() { return dynamic_cast<T*>(this->data()); }\n";
		choice += "        template <typename T> const T*get() const { return dynamic_cast<const T*>(this->data()); }\n";
		choice += "        template <typename T> bool is() const { return get<T>(); }\n";
		choice += "    };\n";
		choice += "    " + name;
		return choice;
	}

	private String getMemberDeclaration(Member m) {
		String t = getTypeName(m.type());
		if (m.isArray) {
			if (m.isStruct) {
				return "QList<" + m.type().name + "> " + m.name;
			} else if ("quint8".equals(t)) {
				return "QByteArray " + m.name;
			} else {
				return "QVector<" + t + "> " + m.name;
			}
		} else if (m.isStruct && (m.isOptional || m.condition != null)) {
			return "QSharedPointer<" + t + "> " + m.name;
		}
		return t + " " + m.name;
	}

	private static String memberToString(Member m, String prefix) {
		String s;
		String mn = prefix + m.name;
		if (m.isArray) {
			s = "\"[array of " + mn + "]\"";
		} else {
			if (m.isInteger) {
				s = "QString::number(" + mn + ") + \"(\" + QString::number("
						+ mn + ",16).toUpper() + \")\"";
			} else if (m.type() == m.type().registry.bit) {
				s = "QString::number(" + mn + ")";
			} else if (m.isChoice) {
				s = "\"<choice>\"";
			} else if (m.isOptional || m.condition != null) {
				s = "((" + mn + ")?" + mn + "->toString() :\"null\")";
			} else {
				s = mn + ".toString()";
			}
		}
		return s;
	}

	private static void styleTextPropAtomFix(PrintWriter out) {
		out.println("    RecordHeader rh;");
		out.println("    QList<TextPFRun> rgTextPFRun;");
		out.println("    QList<TextCFRun> rgTextCFRun;");
	}

	private static void styleTextPropAtomFix2(PrintWriter out) {
		out.println("    if (_s.style) {");
		out.println("        quint32 count = 0;");
		out.println("        if (_s.text.is<TextCharsAtom>()) {");
		out.println(
				"            count = _s.text.get<TextCharsAtom>()->textChars.size();");
		out.println("        }");
		out.println("        if (_s.text.is<TextBytesAtom>()) {");
		out.println(
				"            count = _s.text.get<TextBytesAtom>()->textChars.size();");
		out.println("        }");
		out.println("        quint32 sum = 0;");
		out.println("        do {");
		out.println(
				"        _s.style->rgTextPFRun.append(TextPFRun(_s.style.data()));");
		out.println(
				"            parseTextPFRun(in, _s.style->rgTextPFRun.last());");
		out.println("            sum += _s.style->rgTextPFRun.last().count;");
		out.println("        } while (sum <= count);");
		out.println("        sum = 0;");
		out.println("        do {");
		out.println(
				"            _s.style->rgTextCFRun.append(TextCFRun(_s.style.data()));");
		out.println(
				"            parseTextCFRun(in, _s.style->rgTextCFRun.last());");
		out.println("            sum += _s.style->rgTextCFRun.last().count;");
		out.println("        } while (sum <= count);");
		out.println("    }");
	}

	private void printStructureClassDeclaration(PrintWriter out, Struct s) {
		out.print("class " + s.name);
		if (config.enableIntrospection) {
			out.println(" : public Introspectable {");
			out.println("private:");
			out.println("    class _Introspection;");
		} else {
			out.println(" : public StreamOffset {");

		}
		out.println("public:");
		if (config.enableIntrospection) {
			out.println("    static const Introspection _introspection;");
		}
		for (Member m : s.members) {
			if (!m.isStruct && m.condition != null) {
				out.println("    bool _has_" + m.name + ";");
			}
		}
		if (config.enableStyleTextPropAtomFix
				&& s.name.equals("StyleTextPropAtom")) {
			styleTextPropAtomFix(out);
		} else {
			for (Member m : s.members) {
				String d = getMemberDeclaration(m);
				out.println("    " + d + ";");
			}
		}
		boolean first = true;
		if (config.enableIntrospection) {
			out.print("    explicit " + s.name
					+ "(const Introspectable* parent)");
			out.print("\n       :Introspectable(parent)");
			first = false;
			for (Member m : s.members) {
				if (m.isStruct && !m.isArray && !m.isOptional && !(m.isChoice)
						&& m.condition == null) {
					if (first) {
						out.print("\n       :");
						first = false;
					} else {
						out.print(",\n        ");
					}
					out.print(m.name + "(this)");
				}
			}
			out.println(" {}");
		} else {
			out.println("    " + s.name + "(void* /*dummy*/ = 0) {}");
		}

		// function toString
		if (config.enableToString) {
			out.println("    QString toString() {");
			out.println("        QString _s = \"" + s.name + ":\";");
			for (Member m : s.members) {
				out.print("        _s = _s + \"" + m.name + ": \" + ");
				out.print(memberToString(m, ""));
				out.println(" + \", \";");
			}
			out.println("        return _s;");
			out.println("    }");
		}
		if (config.enableIntrospection) {
			out.println(
					"    const Introspection* getIntrospection() const { return &_introspection; }");
		}
		out.println("};");
	}

	private void printStructureClassImplementation(PrintWriter out, Struct s) {
		final int nm = s.members.size();
		final String ns = s.name + "::_Introspection";
		out.println("class " + ns + " {");
		out.println("public:");
		out.println("    static const QString name;");
		out.println("    static const int numberOfMembers;");
		out.println("    static const QString names[" + nm + "];");
		out.println("    static int (* const numberOfInstances[" + nm
				+ "])(const Introspectable*);");
		out.println("    static QVariant (* const value[" + nm
				+ "])(const Introspectable*, int position);");
		out.println("    static const Introspectable* (* const introspectable["
				+ nm + "])(const Introspectable*, int position);");
		for (Member m : s.members) {
			if (s.name.equals("StyleTextPropAtom")
					&& config.enableStyleTextPropAtomFix
					&& m.name.equals("todo")) {
				break;
			}
			if (!m.isStruct && !(m.isChoice)) {
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
			if (m.isStruct || m.isChoice) {
				out.println("    static const Introspectable* get_" + m.name
						+ "(const Introspectable* i, int j) {");
			} else {
				out.println("    static QVariant get_" + m.name
						+ "(const Introspectable* i, int j) {");
			}
			String dm = "static_cast<const " + s.name + "*>(i)->" + m.name + "";
			if (!(m.isChoice)) {
				out.print("        ");
				if (!m.isStruct) {
					if (m.isArray && m.type() != m.type().registry.uint8) {
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
				out.println("        return static_cast<const " + s.name
						+ "*>(i)->" + m.name + ".data();");
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
			if (m.condition != null || ((m.isStruct || m.isChoice)
					&& (m.isOptional || m.isArray))) {
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
			if (s.name.equals("StyleTextPropAtom")
					&& config.enableStyleTextPropAtomFix
					&& m.name.equals("todo")) {
				break;
			} else if (m.isStruct || m.isChoice) {
				out.println("    Introspection::nullValue,");
			} else {
				out.println("    _Introspection::get_" + m.name + ",");
			}
		}
		out.println("};");
		out.println("const Introspectable* (* const " + ns + "::introspectable["
				+ nm + "])(const Introspectable*, int position) = {");
		for (Member m : s.members) {
			if (m.isStruct || m.isChoice) {
				out.println("    _Introspection::get_" + m.name + ",");
			} else {
				out.println("    Introspection::null,");
			}
		}
		out.println("};");
		out.println("const Introspection " + s.name + "::_introspection(");
		out.println("    \"" + s.name + "\", " + s.members.size()
				+ ", _Introspection::names, _Introspection::numberOfInstances, _Introspection::value, _Introspection::introspectable);");
	}

	private void printChoiceParser(PrintWriter out, String s, String structure,
			Member m) {
		final Choice c = (Choice) m.type();
		final Type commonType = c.commonType;
		if (commonType == null) {
			printUnsureChoiceParser(out, s, structure, m);
		} else {
			printSureChoiceParser(out, s, structure, m, commonType);
		}
	}

	private static String getClause(String name, Type t, Lim lim) {
		String ls = "";
		final Limitation limitations[] = lim.limitations;
		final Lim lims[] = lim.lims;
		if (limitations != null && limitations.length > 0) {
			for (int i = 0; i < limitations.length; ++i) {
				Limitation l = limitations[i];
				String mname = name;
				if (t instanceof Struct) {
					mname += "." + l.name;
				}
				String condition = getLimit(mname, l);
				if (ls.length() > 0) {
					ls += "&&";
				}
				ls += "(" + condition + ")";
			}
		} else if (lims != null && lims.length > 0) {
			for (int i = 0; i < lims.length; ++i) {
				Lim l = lims[i];
				String condition = getClause(name, t, l);
				if (ls.length() > 0) {
					ls += "||";
				}
				ls += "(" + condition + ")";
			}
		}
		return ls.replace("..", ".");
	}

	private void printSureChoiceParser(PrintWriter out, String s,
			String structure, Member m, Type commonType) {
		out.println(s + "_m = in.setMark();");
		Choice c = (Choice) m.type();
		String type = getTypeName(commonType);
		if (c.commonType instanceof Struct) {
			out.println(s + type + " _choice(&_s);");
			out.println(s + "parse" + type + "(in, _choice);");
		} else {
			out.println(
					s + type + " _choice = in.read" + commonType.name + "();");
		}
		out.println(s + "in.rewind(_m);");
		out.println(s + "qint64 startPos = in.getPosition();");
		for (int i = 0; i < c.options.size(); ++i) {
			out.print(s);
			Option o = c.options.get(i);
			String clause = getClause("_choice", o.limitsType, o.lim);
			out.print("if (startPos == in.getPosition()");
			if (!m.isOptional && i == c.options.size() - 1) {
				out.println(") {");
			} else {
				out.println(" && (" + clause + ")) {");
			}
			out.println(s + "    _s." + m.name + " = " + structure + "::"
					+ m.type().name + "(new " + o.type.name + "(&_s));");
			out.println(s + "    parse" + o.type.name + "(in, *(" + o.type.name
					+ "*)_s." + m.name + ".data());");
			out.println(s + "}");
		}
	}

	private static void printUnsureChoiceParser(PrintWriter out, String s,
			String structure, Member m) {
		String closing = "";
		String exception = "_x";
		String choice;
		out.println(s + "_m = in.setMark();");
		Choice c = (Choice) m.type();
		String choices[] = c.getChoiceNames();
		int length = (m.isOptional) ? choices.length : choices.length - 1;
		for (int i = 0; i < length; ++i) {
			choice = choices[i];
			out.println(s + "try {");
			out.println(s + "    _s." + m.name + " = " + structure + "::"
					+ c.name + "(new " + choice + "(&_s));");
			out.println(s + "    parse" + choice + "(in, *(" + choice + "*)_s."
					+ m.name + ".data());");
			out.println(s + "} catch (IncorrectValueException " + exception
					+ ") {");
			out.println(s + "    _s." + m.name + ".clear();");
			out.println(s + "    in.rewind(_m);");
			exception = exception + "x";
			closing = closing + "}";
		}
		if (!m.isOptional) {
			choice = choices[choices.length - 1];
			out.println(s + "    _s." + m.name + " = " + structure + "::"
					+ c.name + "(new " + choice + "(&_s));");
			out.println(s + "    parse" + choice + "(in, *(" + choice + "*)_s."
					+ m.name + ".data());");
		}
		out.println(s + closing);
	}

	private static void printFixedSizeArrayParser(PrintWriter out, String s,
			Member m, String msize) {
		out.println(s + "qint64 _startPos = in.getPosition();");
		/*
		 * _totalSize should really be just getExpression("_s", m.size) The
		 * check for the end of the stream is only a workaround for a limitation
		 * in the current Excel file parser. In Excel, the stream is split up in
		 * blocks and the current code parses these blocks separately and
		 * reassembles them later instead of assembling the raw data
		 * transparantly in a stream.
		 */
		out.println(s + "int _totalSize = qMin(" + getExpression("_s", msize)
				+ ", quint32(in.getSize() - _startPos));");
		out.println(s + "_atend = in.getPosition() - _startPos >= _totalSize;");
		out.println(s + "while (!_atend) {");
		out.println(s + "    _s." + m.name + ".append(" + m.type().name
				+ "(&_s));");
		out.println(s + "    parse" + m.type().name + "(in, _s." + m.name
				+ ".last());");
		out.println(
				s + "    _atend = in.getPosition() - _startPos >= _totalSize;");
		out.println(s + "}");
	}

	private static void printVariableArrayParser(PrintWriter out, String s,
			Member m) {
		out.println(s + "_atend = false;");
		out.println(s + "while (!_atend) {");
		out.println(s + "    _m = in.setMark();");
		out.println(s + "    try {");
		out.println(s + "        _s." + m.name + ".append(" + m.type().name
				+ "(&_s));");
		out.println(s + "        parse" + m.type().name + "(in, _s." + m.name
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

	private void printOptionalMemberParser(PrintWriter out, String s,
			Member m) {
		out.println(s + "_m = in.setMark();");
		Option o = Option.parseOption((Struct) m.type(), null);
		String type = getTypeName(o.limitsType);
		out.println(s + "try {");
		out.println(s + "    " + type + " _optionCheck(&_s);");
		out.println(s + "    parse" + type + "(in, _optionCheck);");
		out.println(s + "    _possiblyPresent = "
				+ getClause("_optionCheck", o.limitsType, o.lim) + ";");
		out.println(s + "} catch(EOFException _e) {");
		out.println(s + "    _possiblyPresent = false;");
		out.println(s + "}");

		out.println(s + "in.rewind(_m);");
		out.println(s + "_m = in.setMark();");
		out.println(s + "if (_possiblyPresent) {");
		out.println(s + "    try {");
		out.println(s + "        _s." + m.name + " = QSharedPointer<"
				+ m.type().name + ">(new " + m.type().name + "(&_s));");
		out.println(s + "        parse" + m.type().name + "(in, *_s." + m.name
				+ ".data());");
		out.println(s + "    } catch(IncorrectValueException _e) {");
		out.println(s + "        _s." + m.name + ".clear();");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    } catch(EOFException _e) {");
		out.println(s + "        _s." + m.name + ".clear();");
		out.println(s + "        in.rewind(_m);");
		out.println(s + "    }");
		out.println(s + "}");
	}

	private void printLimitationCheck(PrintWriter out, String s, String name,
			Member m) {
		for (Limitation l : m.limitations) {
			String mname = l.name;
			if (!"".equals(mname)) {
				mname = name + "." + mname;
			} else {
				mname = name;
			}
			if (!m.isStruct) {
				mname = "((" + getTypeName(m.type()) + ")" + mname + ")";
			}
			String value = l.value;
			String condition = l.expression;
			if (value != null) {
				condition = getCondition(mname, value);
			} else if (condition != null) {
				condition = getExpression(mname, condition);
			}

			out.println(s + "if (!(" + condition + ")) {");
			String exceptionType = "IncorrectValueException";
			out.println(s + "    throw " + exceptionType
					+ "(in.getPosition(), \"" + condition + "\");");
			out.println(s + "}");
		}
	}

	static String getLimit(String mname, Limitation l) {
		final String value = l.value;
		final String condition = l.expression;
		if (value != null) {
			return getCondition(mname, value);
		} else if (condition != null) {
			return getExpression(mname, condition);
		}
		throw new Error("value and condition cannot both be null for " + mname);
	}

	private static String getExpression(String structure, String expression) {
		if (Pattern.matches(".*[A-Za-z].*", expression)) {
			return prependStructureToExpression(expression, structure);
		}
		return structure + expression;
	}

	private static String getCondition(String name, String value) {
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
		return value;
	}
}
