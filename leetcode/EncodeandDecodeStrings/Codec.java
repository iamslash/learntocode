// Copyright (C) 2021 by iamslash

import java.util.*;

// brute force
// encode: O(N) O(N)
// decode: O(N) O(N)
public class Codec {
	private final char SEP = ':';

	public String encode(List<String> strs) {
		StringBuilder rst = new StringBuilder();
		for (String s : strs) {
			rst.append(s.length())
					.append(SEP)
					.append(s);
		}
		return rst.toString();
	}

	public List<String> decode(String s) {
    // System.out.println(s);
		List<String> rst = new ArrayList<>();
		int i = 0;
		while (i < s.length()) {
			int sepIdx = s.indexOf(SEP, i);
			int wordLen = Integer.valueOf(s.substring(i, sepIdx));
      // System.out.printf("i: %d, sepIdx: %d, wordLen: %d\n", i, sepIdx, wordLen);
			rst.add(s.substring(sepIdx+1, sepIdx+wordLen+1));
			i = sepIdx + wordLen + 1;
		}
		return rst;
	}
}
