package mso.generator;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;

import org.w3c.dom.Document;

public class ParserGeneratorRunner {

	public static void main(String[] args) throws Exception {
		final String xmlfilename = "mso.xml";
		final String xsdfilename = "mso.xsd";

		ParserGeneratorRunner pgr = new ParserGeneratorRunner();
		new File("src/mso/javaparser").mkdirs();
		new File("cpp").mkdirs();

		final Validator v = pgr.createValidator(xsdfilename);
		v.validate(new StreamSource(pgr.open(xmlfilename)));

		final Document dom = DocumentBuilderFactory.newInstance()
				.newDocumentBuilder().parse(pgr.open(xmlfilename));
		pgr.generateJavaParser(dom);
		pgr.generateQtParser(dom);
		pgr.generateSimpleQtParser(dom);
	}

	void generateJavaParser(Document dom) throws IOException {
		final JavaParserGenerator g = new JavaParserGenerator();
		g.generate(new MSO(dom), "src", "mso.javaparser", "GeneratedMsoParser");
	}

	void generateQtParser(Document dom) throws IOException {
		// generate a parser with introspection
		final QtParserGenerator g = new QtParserGenerator();
		g.config.namespace = "";
		g.config.basename = "generatedclasses";
		g.config.outputdir = "cpp";
		g.config.createHeader = false;
		g.config.enableIntrospection = true;
		g.config.enableXml = true;
		g.config.enableWriting = true;
		g.config.enableToString = true;
		g.config.enableStyleTextPropAtomFix = false;
		g.generate(new MSO(dom));
	}

	void generateSimpleQtParser(Document dom) throws IOException {
		// generate a minimal parser but with a public header
		final QtParserGenerator g = new QtParserGenerator();
		g.config.namespace = "PPT";
		g.config.basename = "simpleParser";
		g.config.outputdir = "cpp";
		g.config.createHeader = true;
		g.config.enableIntrospection = false;
		g.config.enableXml = false;
		g.config.enableWriting = false;
		g.config.enableToString = false;
		g.config.enableStyleTextPropAtomFix = true;
		g.generate(new MSO(dom));
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
