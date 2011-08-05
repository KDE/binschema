package mso.generator;

import org.w3c.dom.Element;

class Limitation {
	final String name;
	final String expression;
	final String value;

	Limitation(Element e) {
		name = e.getAttribute("name");
		if (e.hasAttribute("expression")) {
			expression = e.getAttribute("expression");
			value = null;
		} else {
			expression = null;
			value = e.getAttribute("value");
		}
	}

	public boolean equals(Object o) {
		if (!(o instanceof Limitation))
			return false;
		Limitation l = (Limitation) o;
		if (!l.name.equals(name))
			return false;
		if (expression != null) {
			if (l.expression == null || !expression.equals(l.expression))
				return false;
		}
		// value is not null
		if (l.value == null || !l.value.equals(value))
			return false;
		return true;
	}
}