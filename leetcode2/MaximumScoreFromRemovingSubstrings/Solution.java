// Copyright (C) 2021 by iamslash

import java.util.*;

// x: 4
// y: 5
// cdbcbbaaabab   5
// cdbcbaabab     5
// cdbcabab       5
// cdbcab         4
// cdbc
class Solution {
	private int remove(String s, String word, int score) {
		int i = 0, j = 0, ans = 0;
		for (int j = 0; j < s.size(); ++j) {
			s[i++] = s[j];
		}
		s = s.substring(0, i);
		return ans;
	}
	public int maximumGain(String s, int x, int y) {
		String z = "ab", w = "ba";
		if (x < y) {
			int t = y;
			x = y;
			y = t;
			z = "ba";
			w = "ab";
		}
		return remove(s, z, x) + remove(s, w, y);		
	}
}
