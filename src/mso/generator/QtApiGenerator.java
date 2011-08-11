package mso.generator;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import mso.generator.utils.Choice;
import mso.generator.utils.Limitation;
import mso.generator.utils.MSO;
import mso.generator.utils.Member;
import mso.generator.utils.Option;
import mso.generator.utils.Struct;
import mso.generator.utils.TypeRegistry;

public class QtApiGenerator {

	public class QtApiConfiguration {
		public String namespace;
		public String outputdir;
		public String basename;
		public boolean createHeader;
	}

	final public QtApiConfiguration config = new QtApiConfiguration();

	final private String generatedWarning = "/* This code was generated by msoscheme (http://gitorious.org/msoscheme) */";

	void generate(MSO mso) throws IOException {
		FileWriter fout;
		if (config.createHeader) {
			fout = new FileWriter(config.outputdir + File.separator
					+ config.basename + ".h");
		} else {
			fout = new FileWriter(config.outputdir + File.separator
					+ config.basename + ".cpp");
		}
		PrintWriter out = new PrintWriter(fout);
		out.println(generatedWarning);
		if (config.createHeader) {
			out.println("#ifndef " + config.basename.toUpperCase() + "_H");
			out.println("#define " + config.basename.toUpperCase() + "_H");
		}
		out.println("#include \"leinput.h\"");
		out.println("namespace " + config.namespace + "{");

		for (Struct s : mso.structs) {
			out.println("class " + s.name + ";");
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
			out.println("#include \"" + config.basename + ".h\"");
		}

		for (Struct s : mso.structs) {
			printStructureDefinition(out, s);
		}

		if (!config.createHeader) {
			out.println("}");// close namespace
		}
		out.close();
		fout.close();
	}

	private void printStructureClassDeclaration(PrintWriter out, Struct s) {
		out.println("class " + s.name + " {");
		out.println("private:");
		out.println("    const char* _data;");
		out.println("public:");
		if (s.size == -1) {
			out.println("    quint32 _size;");
			out.println("    " + s.name + "() :_data(0), _size(0) {}");
			out.println("    explicit " + s.name
					+ "(const char* data, const quint32 maxsize);");
		} else {
			out.println("    static const quint32 _size;");
			out.println("    " + s.name + "() :_data(0) {}");
			out.println("    " + s.name
					+ "(const char* data, quint32/*ignored*/ = 0);// "
					+ (s.size / 8) + " bytes");
		}
		boolean hasData = false;
		for (Member m : s.members) {
			hasData = hasData || m.name.equals("data");
			printMemberDeclaration(out, m, s.name);
		}
		out.println("public:");
		for (Member m : s.members) {
			if (m.isSimple && m.condition != null) {
				out.println("    bool _has_" + m.name + ";");
			}
		}
		out.println("    inline operator bool () const { return _data; }");
		out.println("    inline bool operator ! () const { return !_data; }");
		out.println("    inline operator const void * () const { return _data; }");
		out.println("    inline const " + s.name
				+ "* operator->() const { return this; }");
		out.println("    inline const " + s.name
				+ "& operator*() const { return *this; }");
		if (!hasData) {
			out.println("    inline const " + s.name
					+ "* data() const { return this; }");
		}
		out.println("};");
	}

	private String definitionPrefix() {
		return (config.namespace == null || config.namespace.length() == 0) ? ""
				: config.namespace + "::";
	}

	private void printStructureDefinition(PrintWriter out, Struct s) {
		// constructor
		String c = definitionPrefix() + s.name + "::";
		if (s.size == -1) {
			out.println(c + s.name
					+ "(const char* _d, quint32 _maxsize) :_data(0), _size(0)");
			out.println("{");
		} else {
			out.println("const quint32 " + c + "_size = " + (s.size / 8) + ";");
			out.println(c + s.name
					+ "(const char* _d, quint32/*ignored*/) :_data(0)");
			out.println("{");
		}
		out.println("    quint32 _position = 0;");
		out.println("    quint32 _msize;");
		int bytepos = 0;
		String sp;
		for (Member m : s.members) {
			sp = "    ";
			int msize = getSize(m);
			String condition = m.condition;
			if (m.isSimple && condition != null) {
				condition = fixForMemberName(condition);
				out.println(sp + "_has_" + m.name + " = " + condition + ";");
				condition = "_has_" + m.name;
			}
			if (condition != null) {
				condition = fixForMemberName(condition);
				out.println(sp + "if (" + condition + ") {");
				sp = "        ";
			}
			if (msize != -1 && s.size == -1) {
				out.print(sp + "if (_position + " + msize);
				if (m.isOptional) {
					sp += "    ";
					out.println(" <= _maxsize) {");
				} else {
					out.println(" > _maxsize) return;");
				}
			}
			bytepos = printMemberParser(out, sp, s, m, bytepos);
			printLimitationCheck(out, sp, m.name, m);
			out.println(sp + "_position += _msize;");
			while (sp.length() > 4) {
				sp = sp.substring(sp.length() - 4);
				out.println(sp + "}");
			}
		}
		if (s.size == -1) {
			out.println("    _size = _position;");
		}
		out.println("    _data = _d;");
		out.println("}");
		// access functions
		for (Member m : s.members) {
			if (m.isArray && m.isStruct) {
				// printStructArrayAccessor(out, s, m);
			} else if (m.isChoice) {
				printChoiceAccessor(out, s, m);
			}
		}
	}

	private int printMemberParser(PrintWriter out, String sp, Struct s,
			Member m, int bytepos) {
		if (m.isArray) {
			if (m.isSimple) {
				printSimpleArrayMemberParser(out, sp, s, m);
			} else {
				printStructArrayMemberParser(out, sp, s, m);
			}
			if (m.isChoice) {
				throw new Error("There should be no choice in an array.");
			}
		} else {
			if (m.isSimple) {
				return printSimpleMemberParser(out, sp, s, m, bytepos);
			} else if (m.isStruct) {
				printStructMemberParser(out, sp, s, m);
			} else if (m.isChoice) {
				printChoiceMemberParser(out, sp, s, m);
			}
		}
		return 0;
	}

	private int printSimpleMemberParser(PrintWriter out, String sp, Struct s,
			Member m, int bytepos) {
		out.println(sp + "m_" + m.name + " = read" + m.type().name
				+ ((bytepos > 0) ? "_" + String.valueOf(bytepos) : "")
				+ "(_d + _position);");
		int size = m.type().size / 8;
		if (bytepos != 0 && ((bytepos + m.type().size) % 8) == 0) {
			size += 1;
		}
		bytepos = (bytepos + m.type().size) % 8;
		out.println(sp + "_msize = " + size + ";");
		return bytepos;
	}

	/** return size in bytes **/
	private int getSize(Member m) {
		int size = -1;
		if (m.count != null && m.isArray && m.type().size != -1) {
			try {
				size = m.type().size * Integer.parseInt(m.count) / 8;
			} catch (NumberFormatException e) {
				size = -1;
			}
		} else if (m.size != null) {
			try {
				size = Integer.parseInt(m.size);
			} catch (NumberFormatException e) {
				size = -1;
			}
		} else if (!m.isArray) {
			return m.type().size / 8;
		}
		return size;
	}

	private void printSimpleArrayMemberParser(PrintWriter out, String sp,
			Struct s, Member m) {
		if (m.type().size % 8 != 0) {
			throw new Error(
					"only arrays of types with a size of a multiple of 8 bits are allowed.");
		}
		// get the expression for the size
		int size = getSize(m);
		String count = String.valueOf(size * 8 / m.type().size);
		if (size == -1) {
			if (m.count != null) {
				count = m.count;
			} else {
				count = "(" + m.size + ")/" + (m.type().size / 8);
			}
		} else {
			if (size % (m.type().size / 8) != 0) {
				throw new Error(
						"array size must be a multiple of the size of the type for "
								+ m.type().name + " and size " + size);
			}
		}
		count = fixForMemberName(count);
		String type = getTypeName(m.type());
		if ("quint8".equals(type))
			type = "char";
		out.println(sp + "m_" + m.name + " = MSOCastArray<" + type
				+ ">((const " + type + "*)(_d + _position), " + count + ");");
		out.println(sp + "_msize = (" + count + ")*" + (m.type().size / 8)
				+ ";");
	}

	private void printStructArrayMemberParser(PrintWriter out, String sp,
			Struct s, Member m) {
		if (m.count != null) {
			String size = "_maxsize - _position, ";
			String count = fixForMemberName(m.count);
			if (m.type().size != -1) {
				size = (m.type().size / 8) + " * " + count + ", ";
			}
			out.println(sp + "m_" + m.name + " = MSOArray<" + m.type().name
					+ ">(_d + _position, " + size + count + ");");
			out.println(sp + "if (m_" + m.name + "._count != " + count
					+ ") return;");
		} else if (m.size != null) {
			String size = fixForMemberName(m.size);
			out.println(sp + "if (_maxsize - _position < " + size + ") return;");
			out.println(sp + "m_" + m.name + " = MSOArray<" + m.type().name
					+ ">(_d + _position, " + size + ");");
			out.println(sp + "if (m_" + m.name + "._size != " + size
					+ ") return;");
		} else {
			out.println(sp + "m_" + m.name + " = MSOArray<" + m.type().name
					+ ">(_d + _position, _maxsize - _position);");
			out.println(sp + "if (!m_" + m.name + ") return;");
		}
		out.println(sp + "    _msize = m_" + m.name + "._size;");
	}

	private void printStructMemberParser(PrintWriter out, String sp, Struct s,
			Member m) {
		if (m.type().size == -1) {
			out.println(sp + "m_" + m.name + " = " + m.type().name
					+ "(_d + _position, _maxsize - _position);");
		} else {
			out.println(sp + "m_" + m.name + " = " + m.type().name
					+ "(_d + _position);");
		}
		if (m.isOptional) {
			out.println(sp + "_msize = (m_" + m.name + ") ?m_" + m.name
					+ "._size :0;");
		} else {
			out.println(sp + "if (!m_" + m.name + ") return;");
			out.println(sp + "_msize = m_" + m.name + "._size;");
		}
	}

	private void printChoiceMemberParser(PrintWriter out, String sp, Struct s,
			Member m) {
		Choice c = (Choice) m.type();
		// try all options until one has non-zero size
		// String s = "";
		boolean first = true;
		String sp2 = sp;
		for (Option o : c.options) {
			TypeRegistry.Type t = o.type;
			if (!first) {
				out.println(sp + "if (_msize == 0) {");
			}
			String name = "m_" + m.name + "._" + t.name;
			if (t.size == -1) {
				out.println(sp2 + name + " = " + t.name
						+ "(_d + _position, _maxsize - _position);");
				out.println(sp2 + "_msize = " + name + "._size;");
			} else {
				out.println(sp2 + name + " = " + t.name + "(_d + _position);");
				out.println(sp2 + "_msize = (" + name + ") ?" + t.name
						+ "::_size : 0;");
			}
			if (!first) {
				out.println(sp + "}");
			} else {
				sp2 = sp + "    ";
			}
			first = false;
		}
		if (!m.isOptional) {
			out.println(sp + "if (_msize == 0) return;");
		}
	}

	private String getTypeName(TypeRegistry.Type t) {
		TypeRegistry r = t.registry;
		if (t instanceof Choice) {
			return t.name;
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

	private void printChoiceAccessor(PrintWriter out, TypeRegistry.Type s,
			Member m) {
		Choice c = (Choice) m.type();
		out.println("namespace " + config.namespace + " {");
		for (Option o : c.options) {
			String t = o.type.name;
			out.println("    template <> const " + t + "* " + s.name + "::C_"
					+ m.name + "::get<" + t + ">() const {");
			out.println("        return &_" + t + ";");

			out.println("    }");
			out.println("    template <> bool " + s.name + "::C_" + m.name
					+ "::is<" + t + ">() const {");
			out.println("        return _" + t + ";");

			out.println("    }");
		}
		out.println("}");
	}

	private void printMemberDeclaration(PrintWriter out, Member m,
			String className) {
		String t = getTypeName(m.type());
		if (m.isArray) {
			if (m.isSimple) {
				if ("quint8".equals(t))
					t = "char";
				out.println("private:");
				out.println("    MSOCastArray<" + t + "> m_" + m.name + ";");
				out.println("public:");
				out.println("    MSOCastArray<" + t + "> " + m.name
						+ "() const { return m_" + m.name + "; }");
			}
			if (m.isStruct || m.isChoice) {
				if (m.type().size == -1) {
					out.println("private:");
					out.println("    MSOArray<" + t + "> m_" + m.name + ";");
					out.println("public:");
					out.println("    MSOArray<" + t + "> " + m.name
							+ "() const { return m_" + m.name + "; }");
				} else {
					out.println("private:");
					out.println("    MSOArray<" + t + "> m_" + m.name + ";");
					out.println("public:");
					out.println("    MSOArray<" + t + "> " + m.name
							+ "() const { return m_" + m.name + "; }");
				}
			}
		} else if (m.isChoice) {
			Choice c = (Choice) m.type();
			out.println("    class C_" + m.name + " {");
			out.println("    friend class " + className + ";");
			out.println("    private:");
			for (Option o : c.options) {
				TypeRegistry.Type ct = o.type;
				out.println("        " + ct.name + " _" + ct.name + ";");
			}
			out.println("    public:");
			out.println("        template <typename A> const A* get() const;");
			out.println("        template <typename A> bool is() const;");
			out.println("    };");
			out.println("private:");
			out.println("    C_" + m.name + " m_" + m.name + ";");
			out.println("public:");
			out.println("    C_" + m.name + " " + m.name
					+ "() const { return m_" + m.name + "; }");
		} else {
			out.println("public:");
			out.println("    " + t + " " + m.name + "() const { return m_"
					+ m.name + "; }");
			out.println("private:");
			out.println("    " + t + " m_" + m.name + ";");
		}
	}

	private void printLimitationCheck(PrintWriter out, String s, String name,
			Member m) {
		if (m.type() instanceof Choice)
			return;
		for (Limitation l : m.limitations) {
			String mname = l.name;
			if (!"".equals(mname)) {
				mname = name + "." + mname;
			} else {
				mname = name;
			}
			if (!m.isStruct) {
				mname = "((" + getTypeName(m.type()) + ")m_" + mname + ")";
			}
			String condition = l.expression;
			if (condition == null) {
				condition = QtParserGenerator.getCondition(mname, l);
			} else {
				condition = QtParserGenerator.getExpression(mname, condition);
			}
			if (m.isStruct) {
				condition = fixForMemberName(condition);
			}
			out.println(s + "if (!(" + condition + ")) {");
			out.println(s + "     return;");
			out.println(s + "}");
		}
	}

	private boolean isNumber(String n) {
		boolean isNumber = true;
		try {
			Integer.decode(n);
		} catch (NumberFormatException e) {
			isNumber = false;
		}
		return isNumber;
	}

	final private Pattern pattern1 = Pattern
			.compile("(?<=\\W)([a-zA-Z]\\w*)(?=\\W|$)");
	final private Pattern pattern2 = Pattern
			.compile("(^[a-zA-Z]\\w*)(?=\\W|$)");

	private String fix(String condition, Pattern regex) {
		Matcher m = regex.matcher(condition);
		StringBuffer sb = new StringBuffer();
		while (m.find()) {
			String var = m.group(1);
			if (!isNumber(var)) {
				var = var + "()";
			}
			m.appendReplacement(sb, var);
		}
		m.appendTail(sb);
		return sb.toString();
	}

	private String fixForMemberName(String condition) {
		if (condition.startsWith("_has_")) {
			return condition;
		}
		condition = fix(condition, pattern1);
		condition = fix(condition, pattern2);
		condition = condition.replaceAll("false\\(\\)", "false");
		condition = condition.replaceAll("true\\(\\)", "true");
		return condition;
	}
}
