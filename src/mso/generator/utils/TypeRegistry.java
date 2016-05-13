package mso.generator.utils;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.jdt.annotation.NonNullByDefault;

@NonNullByDefault
public class TypeRegistry {
	final Map<String, Type> types = new HashMap<String, Type>();

	Type getType(String name) {
		return types.get(name);
	}

	final public Type bit = new Type(this, this, "bit", 1);
	final public Type uint2 = new Type(this, this, "uint2", 2);
	final public Type uint3 = new Type(this, this, "uint3", 3);
	final public Type uint4 = new Type(this, this, "uint4", 4);
	final public Type uint5 = new Type(this, this, "uint5", 5);
	final public Type uint6 = new Type(this, this, "uint6", 6);
	final public Type uint7 = new Type(this, this, "uint7", 7);
	final public Type uint8 = new Type(this, this, "uint8", 8);
	final public Type uint9 = new Type(this, this, "uint9", 9);
	final public Type uint12 = new Type(this, this, "uint12", 12);
	final public Type uint13 = new Type(this, this, "uint13", 13);
	final public Type uint14 = new Type(this, this, "uint14", 14);
	final public Type uint15 = new Type(this, this, "uint15", 15);
	final public Type uint16 = new Type(this, this, "uint16", 16);
	final public Type uint20 = new Type(this, this, "uint20", 20);
	final public Type uint30 = new Type(this, this, "uint30", 30);
	final public Type uint32 = new Type(this, this, "uint32", 32);
	final public Type int16 = new Type(this, this, "int16", 16);
	final public Type int32 = new Type(this, this, "int32", 32);
}