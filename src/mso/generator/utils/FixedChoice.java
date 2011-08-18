package mso.generator.utils;

import java.util.SortedSet;

import mso.generator.utils.Member.ByteArray;

public class FixedChoice extends TypeRegistry.Type {

	final private SortedSet<ByteArray> texts;

	private static int getSize(SortedSet<ByteArray> texts) {
		if (texts.size() == 0) {
			return 0;
		}
		int size = -2;
		for (ByteArray b : texts) {
			if (size == -2) {
				size = 8 * b.data.length;
			} else if (size != 8 * b.data.length) {
				size = -1;
			}
		}
		return size;
	}

	FixedChoice(TypeRegistry registry, String name, SortedSet<ByteArray> texts,
			boolean optional) {
		registry.super(registry, name, getSize(texts));
		this.texts = texts;
	}

}