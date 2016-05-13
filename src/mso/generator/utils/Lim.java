package mso.generator.utils;

import org.eclipse.jdt.annotation.Nullable;

public class Lim {
	public Limitation @Nullable [] limitations;
	public final Lim @Nullable [] lims;

	Lim(Lim lims[]) {
		this.lims = lims;
		this.limitations = null;
	}

	Lim(Limitation lims[]) {
		this.lims = null;
		this.limitations = lims;
	}

	boolean containsCommonLimitation(Limitation l) {
		final Limitation limitations[] = this.limitations;
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
		final Limitation limitations[] = this.limitations;
		if (limitations != null) {
			Limitation[] nl = new Limitation[limitations.length - 1];
			int pos = 0;
			for (int i = 0; i < limitations.length; ++i) {
				if (!limitations[i].equals(l)) {
					nl[pos++] = limitations[i];
				}
			}
			this.limitations = nl;
		}
	}
}