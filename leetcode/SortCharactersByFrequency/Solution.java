// Copyright (C) 2020 by iamslash

import java.util.*;

// 12ms 68.78% 40.3MB 78.36%
// bucket
// O(N) O(N)
class Solution {
	public String frequencySort(String s) {
		Map<Character, Integer> cnts = new HashMap<>();
		for (char c : s.toCharArray())
			cnts.put(c, cnts.getOrDefault(c, 0) + 1);
		List<Character>[] bucket = new List[s.length()+1];
		for (char key : cnts.keySet()) {
			int freq = cnts.get(key);
			if (bucket[freq] == null)
				bucket[freq] = new ArrayList<>();
			bucket[freq].add(key);
		}
		StringBuilder sb = new StringBuilder();
		for (int i = bucket.length - 1; i >= 0; --i) {
			if (bucket[i] != null) {
				for (char c : bucket[i]) {
					for (int j = 0; j < i; ++j) {
						sb.append(c);
					}
				}
			}
		}
		return sb.toString();
	}
}
