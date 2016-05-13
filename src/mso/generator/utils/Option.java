package mso.generator.utils;

import org.eclipse.jdt.annotation.Nullable;

public class Option {
	public final Struct type;
	public final Type limitsType;
	public final Lim lim;

	private Option(Struct type, Type limitsType, Lim lim) {
		this.type = type;
		this.limitsType = limitsType;
		this.lim = lim;
	}

	public static Option parseOption(Struct s, @Nullable Type suggestedType) {
		return setLimitations(s, s, suggestedType);
	}

	private static Option setLimitations(Struct parent, Struct type, Choice c) {
		// all restrictions in the
		Lim lims[] = new Lim[c.options.size()];
		for (int i = 0; i < c.options.size(); ++i) {
			lims[i] = c.options.get(i).lim;
		}
		Type commonType = c.commonType;
		if (commonType == null) {
			throw new Error("Common type is null.");
		}
		return new Option(parent, commonType, new Lim(lims));
	}

	private static Option setLimitations(Struct parent, Struct type,
			@Nullable Type suggestedType) {
		Member m = type.members.get(0);
		System.out.println(parent.name + " " + type.name + " , " + m.name
				+ " . " + m.type());
		if (m.isOptional) {
			throw new Error("choice member may not be optional");
		}
		Type t = m.type();
		if (t instanceof Choice) {
			return setLimitations(parent, type, (Choice) t);
		}
		// if the type is equal to a previous common type, use that
		if (t == suggestedType) {
			return new Option(parent, suggestedType, new Lim(m.limitations));
		}
		// if this struct has no limitations, take its first member
		if (m.limitations.length == 0) {
			return setLimitations(parent, (Struct) t, suggestedType);
		}
		return new Option(parent, t, new Lim(m.limitations));
	}
}