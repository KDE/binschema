package mso.generator.utils;

public class Option {
	public Struct type;
	public Type limitsType;
	public Lim lim = new Lim();

	public Option(Struct s, Type suggestedType) {
		type = s;
		setLimitations(s, suggestedType);
	}

	private void setLimitations(Choice c) {
		// all restrictions in the
		lim.lims = new Lim[c.options.size()];
		for (int i = 0; i < c.options.size(); ++i) {
			lim.lims[i] = c.options.get(i).lim;
		}
		limitsType = c.commonType;
	}

	private void setLimitations(Struct s, Type suggestedType) {
		Member m = s.members.get(0);
		System.out.println(
				type.name + " " + s.name + " , " + m.name + " . " + m.type());
		if (m.isOptional) {
			throw new Error("choice member may not be optional");
		}
		Type t = m.type();
		if (t instanceof Choice) {
			setLimitations((Choice) t);
			return;
		}
		// if the type is equal to a previous common type, use that
		if (t == suggestedType) {
			lim.limitations = m.limitations;
			limitsType = suggestedType;
			return;
		}
		// if this struct has no limitations, take its first member
		if (m.limitations.length == 0) {
			setLimitations((Struct) t, suggestedType);
			return;
		}
		lim.limitations = m.limitations;
		limitsType = t;
	}
}