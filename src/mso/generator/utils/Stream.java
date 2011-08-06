package mso.generator.utils;

import org.w3c.dom.Element;

public class Stream {

	public final String key;
	public final String type;

	Stream(Element e) {
		key = e.getAttribute("key");
		type = e.getAttribute("type");
	}
}