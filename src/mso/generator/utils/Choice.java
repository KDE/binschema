package mso.generator.utils;

import java.util.ArrayList;
import java.util.List;

import org.eclipse.jdt.annotation.Nullable;

public class Choice extends Type {

	public final @Nullable Type commonType;
	public final List<Option> options = new ArrayList<Option>();

	public String[] getChoiceNames() {
		String n[] = new String[options.size()];
		for (int i = 0; i < options.size(); ++i) {
			n[i] = options.get(i).type.name;
		}
		return n;
	}

	Choice(TypeRegistry registry, String name, List<Struct> choices,
			boolean optional) {
		super(registry, name, getSize(choices));
		Type common = null;
		for (Struct s : choices) {
			Option o = Option.parseOption(s, common);
			if (common != null && o.limitsType != common
					&& !compareTypes(common, o.limitsType)) {
				throw new Error("Conflicting common type: " + common.name
						+ " vs " + o.limitsType.name);
			}
			common = o.limitsType;
			options.add(o);
		}
		// check if the common type is the same
		for (Option o : options) {
			if (!compareTypes(common, o.limitsType)) {
				String types = "";
				for (Option op : options) {
					types = types + " " + op.type.name;
				}
				System.err.println("The choice " + name
						+ " has no common options for types" + types);
				common = null;
				break;
			}
		}
		if (common == null) {
			commonType = null;
			return;
		}
		// Check if the limitations are distinctive
		// if limitation on an earlier option are a subset of a later
		// limitation,
		// then then the limitations cannot be used for making the choice
		// so must make sure that earlier sets of limitations are not
		// subsets of later limitations.
		for (int i = 0; i < options.size(); ++i) {
			int last = (optional) ? options.size() : options.size() - 1;
			for (int j = i + 1; j < last; ++j) {
				// the double negation is important: we cannot be sure that it
				// is a subset
				// we must be sure that it is not a subset
				Option a = options.get(i);
				Option b = options.get(j);
				if (!noOverlap(a.lim, b.lim)) {
					System.err.println("Options " + a.type.name + " and "
							+ b.type.name + " have overlap.");
					common = null;
				}
			}
		}

		// if the options are distinctive we can use them
		commonType = common;

		if (!optional && common != null) {
			// remove options that are present in all options
			removeNonDistinctiveLimitations(options);
		}
	}

	// if all choices have equal size, return that sizes, else return -1
	private static int getSize(List<Struct> choices) {
		int size = -1;
		for (Struct s : choices) {
			if (size == -1) {
				size = s.size;
			}
			if (s.size != size) {
				return -1;
			}
		}
		return size;
	}

	/**
	 * Return true if not all of the limitations in a are sure to be present in
	 * b. Err on the side of safety: if unsure return false;
	 */
	private static boolean noOverlap(Lim a, Lim b) {
		if (a.limitations == null && a.lims == null)
			return false;
		if (a.limitations != null) {
			if (!noOverlap(a.limitations, b)) {
				return false;
			}
		}
		if (a.lims != null) {
			for (Lim sa : a.lims) {
				if (!noOverlap(sa, b)) {
					return false;
				}
			}
		}
		return true;
	}

	private static boolean noOverlap(Limitation a[], Lim b) {
		if (b.limitations == null && b.lims == null)
			return false;
		if (b.limitations != null) {
			if (!noOverlap(a, b.limitations)) {
				return false;
			}
		}
		if (b.lims != null) {
			for (Lim sb : b.lims) {
				if (!noOverlap(a, sb)) {
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * Return true if sure that a and b define value spaces with no overlap
	 */
	private static boolean noOverlap(Limitation a[], Limitation b[]) {
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < b.length; ++j) {
				if (a[i].name.equals(b[j].name)
						&& noOverlap(a[i].value, b[j].value)) {
					return true;
				}
			}
		}
		return false;
	}

	private static boolean noOverlap(@Nullable String a, @Nullable String b) {
		if (a == null || b == null)
			return false;
		String[] avalues = a.split("\\|");
		String[] bvalues = b.split("\\|");
		for (int i = 0; i < avalues.length; ++i) {
			for (int j = 0; j < bvalues.length; ++j) {
				if (avalues[i].equals(bvalues[j])) {
					return false;
				}
			}
		}
		return true;
	}

	private static boolean compareMembers(Member a, Member b) {
		if (a.isArray != b.isArray)
			return false;
		if (a.type() != b.type())
			return false;
		if (a.isOptional != b.isOptional)
			return false;
		return true;
	}

	private static boolean structsWithSameMembers(@Nullable Type a, Type b) {
		if (a instanceof Struct && b instanceof Struct) {
			Struct as = (Struct) a;
			Struct bs = (Struct) b;
			if (as.members.size() != bs.members.size()) {
				return false;
			}
			for (int i = 0; i < as.members.size(); ++i) {
				if (!compareMembers(as.members.get(i), bs.members.get(i))) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	private static boolean compareTypes(@Nullable Type a, Type b) {
		return a == b || structsWithSameMembers(a, b);
	}

	private static void removeNonDistinctiveLimitations(List<Option> options) {
		final Lim a = options.get(0).lim;
		final Limitation limitations[] = a.limitations;
		if (limitations != null) {
			for (int i = 0; i < limitations.length; ++i) {
				Limitation l = limitations[i];
				boolean common = true;
				for (int j = 1; j < options.size(); ++j) {
					common = common
							&& options.get(j).lim.containsCommonLimitation(l);
				}
				if (common) {
					for (int j = 0; j < options.size(); ++j) {
						options.get(j).lim.removeLimitation(l);
					}
					i = 0;
				}
			}
		}
	}
}