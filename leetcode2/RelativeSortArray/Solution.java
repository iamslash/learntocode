// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;

// 6ms 15.21% 39.7MB 100.00%
import java.util.SortedMap;
import java.util.TreeMap;
class Solution {
	public int[] relativeSortArray(int[] A, int[] B) {
		SortedMap<Integer, Integer> cnts = new TreeMap<>();
		for (int a : A)
			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
		List<Integer> ans = new ArrayList<>();
		for (int b : B) {
			while (cnts.get(b) > 0) {
				ans.add(b);
				cnts.put(b, cnts.get(b) - 1);
			}
		}
		cnts.forEach((k, v) -> {
				for (int j = 0; j < v; ++j)
					ans.add(k);
			});
		
		return ans.stream().mapToInt(i->i).toArray();
	}
}
