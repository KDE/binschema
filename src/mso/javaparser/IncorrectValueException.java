package mso.javaparser;

import java.io.IOException;

import org.eclipse.jdt.annotation.NonNullByDefault;

@NonNullByDefault
public class IncorrectValueException extends IOException {

	private static final long serialVersionUID = 5106854539956400317L;

	public IncorrectValueException(String condition) {
		super(condition);
	}
}
