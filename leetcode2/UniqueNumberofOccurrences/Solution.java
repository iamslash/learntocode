// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.Hashtable;
import java.util.Set;
import java.util.HashSet;

// 2ms 25.84% 37.6MB 100.00%
// hash table
// O(N) O(N)
import java.util.Map;
import java.util.Hashtable;
class Solution {
	public boolean uniqueOccurrences(int[] A) {
		Map<Integer, Integer> cnts = new Hashtable<>();
		for (int a : A) {
			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
		}
		Set<Integer> valueSet = new HashSet<>(cnts.values());
		return cnts.size() == valueSet.size();
	}
}
