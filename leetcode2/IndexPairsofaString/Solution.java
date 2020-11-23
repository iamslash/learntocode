// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

// 3ms 40.55% 41.5MB 50.00%
// brute force
// O(SW) O(S)
class Solution {
	public int[][] indexPairs(String s, String[] W) {
		List<int[]> ans = new ArrayList();
		for (int i = 0; i < s.length(); ++i) {
			for (String w : W) {
				if (s.startsWith(w, i))
					ans.add(new int[]{i, i+w.length()-1});
			}
		}
		// sort
		Collections.sort(ans, (a, b) -> {
				if (a[0] == b[0])
					return a[1] - b[1];
				return a[0] - b[0];
			});
		return ans.toArray(new int[ans.size()][]);
	}
}
