// Copyright (C) 2020 by iamslash
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

// 51ms 23.41% 46.5MB 9.52%
// dynamic programming
// O(N) O(N)
class Solution {
	public boolean canCross(int[] S) {
		int n = S.length;
		Map<Integer, Set<Integer>> ans = new HashMap<>();
		for (int pos : S) {
			ans.put(pos, new HashSet<Integer>());
		}
		ans.get(0).add(0);
		for (int pos : S) {
			Set<Integer> jumps = new HashSet<>(ans.get(pos));
			for (int jump : jumps) {
				for (int i = -1; i <= 1; ++i) {
					int delta = jump + i;
					if (ans.containsKey(pos + delta)) {
						ans.get(pos + delta).add(delta);
					}						
				}
			}
		}
		return ans.get(S[n-1]).size() > 0;
	}
}

