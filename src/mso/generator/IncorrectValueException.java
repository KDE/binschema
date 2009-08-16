package mso.generator;

import java.io.IOException;

public class IncorrectValueException extends IOException {

	private static final long serialVersionUID = 5106854539956400317L;

	public IncorrectValueException(String condition) {
		super(condition);
	}
}
