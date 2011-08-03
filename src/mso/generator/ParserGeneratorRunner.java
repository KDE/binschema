package mso.generator;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;

import org.w3c.dom.Document;
import org.xml.sax.SAXException;

public class ParserGeneratorRunner {

	public static void main(String[] args) throws Exception {
		final String xsdfilename = "mso.xsd";

		ParserGeneratorRunner pgr = new ParserGeneratorRunner();
		new File("src/mso/javaparser").mkdirs();

		final Validator v = pgr.createValidator(xsdfilename);

		//pgr.generate(v, "pdf.xml", "PDF", "cpp");
		pgr.generate(v, "mso.xml", "MSO", "cpp");
	}

	void generate(Validator v, String xmlfilename, String namespace,
			String cppdir) throws SAXException, IOException,
			ParserConfigurationException, Exception {
		v.validate(new StreamSource(open(xmlfilename)));
		final Document dom = DocumentBuilderFactory.newInstance()
				.newDocumentBuilder().parse(open(xmlfilename));
		MSO mso = new MSO(dom);
		new File(cppdir).mkdirs();
		generateJavaParser(mso, namespace);
		generateQtParser(mso, "", "generatedclasses", cppdir);
		generateSimpleQtParser(mso, namespace, "simpleParser", cppdir);
		generateApi(mso, namespace, "api", cppdir);
	}

	void generateJavaParser(MSO mso, String namespace) throws IOException {
		final JavaParserGenerator g = new JavaParserGenerator();
		String l = namespace.toLowerCase();
		String il = namespace.substring(0, 1) + l.substring(1);
		g.generate(mso, "src", l + ".javaparser", "Generated" + il + "Parser");
	}

	void generateQtParser(MSO mso, String namespace, String basename,
			String outputdir) throws IOException {
		// generate a parser with introspection
		final QtParserGenerator g = new QtParserGenerator();
		g.config.namespace = namespace;
		g.config.basename = basename;
		g.config.outputdir = outputdir;
		g.config.createHeader = false;
		g.config.enableIntrospection = true;
		g.config.enableXml = true;
		g.config.enableWriting = true;
		g.config.enableToString = true;
		g.config.enableStyleTextPropAtomFix = false;
		g.generate(mso);
	}

	void generateSimpleQtParser(MSO mso, String namespace, String basename,
			String outputdir) throws IOException {
		// generate a parser with introspection
		final QtParserGenerator g = new QtParserGenerator();
		g.config.namespace = namespace;
		g.config.basename = basename;
		g.config.outputdir = outputdir;
		g.config.createHeader = true;
		g.config.enableIntrospection = false;
		g.config.enableXml = false;
		g.config.enableWriting = false;
		g.config.enableToString = false;
		g.config.enableStyleTextPropAtomFix = true;
		g.generate(mso);
	}

	void generateApi(MSO mso, String namespace, String basename,
			String outputdir) throws IOException {
		// generate a minimal parser but with a public header
		final QtApiGenerator g = new QtApiGenerator();
		g.config.namespace = namespace;
		g.config.basename = basename;
		g.config.outputdir = outputdir;
		g.config.createHeader = true;
		g.generate(mso);
	}

	InputStream open(String name) throws Exception {
		File f = new File(name);
		if (f.canRead()) {
			System.out.println("Reading " + f.getAbsolutePath());
			return new FileInputStream(f.getAbsolutePath());
		}
		f = new File("src/" + name);
		if (f.canRead()) {
			System.out.println("Reading " + f.getAbsolutePath());
			return new FileInputStream(f.getAbsolutePath());
		}
		System.out.println("Reading " + name + " from jar file.");
		return getClass().getResourceAsStream("/" + name);
	}

	Validator createValidator(String xsdfilename) throws Exception {
		// define the type of schema - we use W3C:
		String schemaLang = "http://www.w3.org/2001/XMLSchema";

		// get validation driver:
		SchemaFactory factory = SchemaFactory.newInstance(schemaLang);

		Source sources[] = new Source[1];
		sources[0] = new StreamSource(open(xsdfilename));
		Schema schema = factory.newSchema(sources);
		return schema.newValidator();
	}
}
