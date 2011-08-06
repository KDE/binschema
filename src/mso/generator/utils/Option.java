package mso.generator.utils;

public class Option {
	public class Lim {
		public Limitation[] limitations;
		public Lim[] lims;

		boolean containsCommonLimitation(Limitation l) {
			if (limitations != null) {
				for (int i = 0; i < limitations.length; ++i) {
					if (limitations[i].equals(l)) {
						return true;
					}
				}
			}
			return false;
		}

		void removeLimitation(Limitation l) {
			if (!containsCommonLimitation(l))
				return;
			if (limitations != null) {
				Limitation[] nl = new Limitation[limitations.length - 1];
				int pos = 0;
				for (int i = 0; i < limitations.length; ++i) {
					if (!limitations[i].equals(l)) {
						nl[pos++] = limitations[i];
					}
				}
				limitations = nl;
			}
		}
	}

	public Struct type;
	public TypeRegistry.Type limitsType;
	public Lim lim = new Lim();

	public Option(Struct s, TypeRegistry.Type suggestedType) {
		type = s;
		setLimitations(s, suggestedType);
	}

	Option(Struct s) {
		type = s;
		setLimitations(s, null);
	}

	private void setLimitations(Choice c) {
		// all restrictions in the
		lim.lims = new Option.Lim[c.options.size()];
		for (int i = 0; i < c.options.size(); ++i) {
			lim.lims[i] = c.options.get(i).lim;
		}
		limitsType = c.commonType;
	}

	private void setLimitations(Struct s, TypeRegistry.Type suggestedType) {
		Member m = s.members.get(0);
		if (m.isOptional) {
			throw new Error("choice member may not be optional");
		}
		TypeRegistry.Type t = m.type();
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