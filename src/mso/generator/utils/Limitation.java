package mso.generator.utils;

import org.eclipse.jdt.annotation.Nullable;
import org.w3c.dom.Element;

public class Limitation {
	public final String name;
	@Nullable
	public final String expression;
	@Nullable
	public final String value;

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

	public boolean equals(@Nullable Object o) {
		if (!(o instanceof Limitation))
			return false;
		Limitation l = (Limitation) o;
		if (!l.name.equals(name))
			return false;
		final String lexpression = l.expression;
		if (expression != null) {
			if (lexpression == null || !lexpression.equals(expression))
				return false;
		}
		// value is not null
		final String lvalue = l.value;
		if (lvalue == null || !lvalue.equals(value))
			return false;
		return true;
	}
}