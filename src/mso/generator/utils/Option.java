package mso.generator.utils;

import org.eclipse.jdt.annotation.NonNullByDefault;
import org.eclipse.jdt.annotation.Nullable;

@NonNullByDefault
public class Option {
	public final Struct type;
	public final Type limitsType;
	public final Lim lim = new Lim();

	public Option(Struct s, @Nullable Type suggestedType) {
		type = s;
		limitsType = setLimitations(s, suggestedType);
	}

	private Type setLimitations(Choice c) {
		// all restrictions in the
		lim.lims = new Lim[c.options.size()];
		for (int i = 0; i < c.options.size(); ++i) {
			lim.lims[i] = c.options.get(i).lim;
		}
		Type commonType = c.commonType;
		if (commonType == null) {
			throw new Error("Common type is null.");
		}
		return commonType;
	}

	private Type setLimitations(Struct s, @Nullable Type suggestedType) {
		Member m = s.members.get(0);
		System.out.println(
				type.name + " " + s.name + " , " + m.name + " . " + m.type());
		if (m.isOptional) {
			throw new Error("choice member may not be optional");
		}
		Type t = m.type();
		if (t instanceof Choice) {
			return setLimitations((Choice) t);
		}
		// if the type is equal to a previous common type, use that
		if (t == suggestedType) {
			lim.limitations = m.limitations;
			return suggestedType;
		}
		// if this struct has no limitations, take its first member
		if (m.limitations.length == 0) {
			return setLimitations((Struct) t, suggestedType);
		}
		lim.limitations = m.limitations;
		return t;
	}
}