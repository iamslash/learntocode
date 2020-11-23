// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 3ms 97.54% 39.7MB 100.00%
// hash map
// O(N) O(1)
class Solution {
	private boolean match(String word, int[] cnts) {
		cnts = Arrays.copyOf(cnts, cnts.length);
		for (char c : word.toCharArray()) {
			if (--cnts[c-'a'] < 0)
				return false;				
		}
		return true;
	}
	public int countCharacters(String[] W, String C) {
		int[] cnts = new int[26];
		for (char c : C.toCharArray())
			cnts[c-'a']++;
		int ans = 0;
		for (String word : W) {
			if (match(word, cnts))
				ans += word.length();
		}
		return ans;
	}
}
