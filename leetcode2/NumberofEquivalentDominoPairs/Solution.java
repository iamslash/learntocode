// Copyright (C) 2020 by iamslash
import java.util.Map;
import java.util.HashMap;

// 7ms 73.51% 48.5MB 100.00%
// hash map, combination
// O(N) O(N)
class Solution {
	public int numEquivDominoPairs(int[][] D) {
		Map<Integer, Integer> cnts = new HashMap<>();
		int ans = 0;
		for (int[] d : D) {
			int k = Math.min(d[0], d[1]) * 10 + Math.max(d[0], d[1]);
			cnts.put(k, cnts.getOrDefault(k, 0) + 1);
		}
		for (int v : cnts.values()) {
			ans += v * (v - 1) / 2;
		}
		return ans;
	}
}
