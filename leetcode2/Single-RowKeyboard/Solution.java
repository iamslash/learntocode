// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;

// 8ms 36.05% 39.6MB 100.00%
class Solution {
	public int calculateTime(String K, String W) {
		Map<Character, Integer> keys = new HashMap<>();
		for (int i = 0; i < 26; ++i) {
			keys.put(K.charAt(i), i);
		}
		int p = 0, ans = 0;
		for (char c : W.toCharArray()) {
			ans += Math.abs(keys.get(c) - p);
			p = keys.get(c);
		}
		return ans;	
	}
}
