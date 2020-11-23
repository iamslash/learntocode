// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

// 4ms 93.77% 40.1% 100.00%
// greedy algorithm
// O(N) O(N)
class Solution {
	public List<List<Integer>> groupThePeople(int[] G) {
		List<List<Integer>> ans = new ArrayList();
		Map<Integer, List<Integer>> groups = new HashMap<>();
		for (int i = 0; i < G.length; ++i) {
			List<Integer> group = groups.computeIfAbsent(G[i], k -> new ArrayList<>());
			group.add(i);
			if (group.size() == G[i]) {
				ans.add(group);
				groups.put(G[i], new ArrayList<>());
			}
		}
		return ans;
	}
}
