package mso.generator.utils;

public class Type {
	public final TypeRegistry registry;
	public final String name;
	public final int size;

	Type(TypeRegistry r, String name_, int size_) {
		registry = r;
		name = name_;
		size = size_;
		if (r.types.containsKey(name)) {
			throw new Error("Duplicate key: " + name);
		}
		r.types.put(name, this);
	}
}