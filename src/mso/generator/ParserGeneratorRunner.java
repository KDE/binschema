package mso.generator;

import java.io.FileReader;
import java.io.IOException;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;

import org.w3c.dom.Document;

public class ParserGeneratorRunner {

	public static void main(String[] args) throws Exception {
		final String xmlfilename = "src/mso.xml";
		final String xsdfilename = "src/mso.xsd";

		final Validator v = createValidator(xsdfilename);
		v.validate(new StreamSource(new FileReader(xmlfilename)));

		final Document dom = DocumentBuilderFactory.newInstance()
				.newDocumentBuilder().parse(xmlfilename);
		generateJavaParser(dom);
		generateQtParser(dom);
	}

	static void generateJavaParser(Document dom) throws IOException {
		final JavaParserGenerator g = new JavaParserGenerator();
		g.generate(new MSO(dom), "src", "mso.javaparser", "GeneratedMsoParser");
	}

	static void generateQtParser(Document dom) throws IOException {
		final QtParserGenerator g = new QtParserGenerator();
		g.generate(new MSO(dom), "cpp");
	}

	static private Validator createValidator(String xsdfilename)
			throws Exception {
		// define the type of schema - we use W3C:
		String schemaLang = "http://www.w3.org/2001/XMLSchema";

		// get validation driver:
		SchemaFactory factory = SchemaFactory.newInstance(schemaLang);

		Source sources[] = new Source[1];
		sources[0] = new StreamSource(new FileReader(xsdfilename));
		Schema schema = factory.newSchema(sources);
		return schema.newValidator();
	}

}
