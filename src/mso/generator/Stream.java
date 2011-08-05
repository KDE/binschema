package mso.generator;

import org.w3c.dom.Element;

class Stream {

	final String key;
	final String type;

	Stream(Element e) {
		key = e.getAttribute("key");
		type = e.getAttribute("type");
	}
}