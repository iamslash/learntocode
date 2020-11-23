// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;

// i
// hell
// hello

// 1ms 41.55% 39.6MB 7.69%
// hash map
// O(N) O(N)
class Solution {
	private Map<Character, Integer> dic = new HashMap<>();
	private boolean bigger(String a, String b) {
		int m = a.length(), n = b.length();
		for (int i = 0; i < m && i < n; ++i) {
			if (a.charAt(i) != b.charAt(i)) {
				return dic.get(a.charAt(i)) > dic.get(b.charAt(i));
			}
		}
		return m > n;
	}
	public boolean isAlienSorted(String[] W, String s) {
		for (int i = 0; i < s.length(); i++) {
			dic.put(s.charAt(i), i);
		}
		for (int i = 1; i < W.length; i++) {
			if (bigger(W[i-1], W[i]))
				return false;
		}
		return true;
	}
}
