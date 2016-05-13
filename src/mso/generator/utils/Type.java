package mso.generator.utils;

public class Type {
	/**
	 * 
	 */
	private final TypeRegistry typeRegistry;
	public final TypeRegistry registry;
	public final String name;
	public final int size;

	Type(TypeRegistry typeRegistry, TypeRegistry r, String name_, int size_) {
		this.typeRegistry = typeRegistry;
		registry = r;
		name = name_;
		size = size_;
		if (this.typeRegistry.types.containsKey(name)) {
			throw new Error("Duplicate key: " + name);
		}
		this.typeRegistry.types.put(name, this);
	}
}