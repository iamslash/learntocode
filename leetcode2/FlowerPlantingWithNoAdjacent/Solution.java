// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.List;
import java.util.HashMap;
import java.util.ArrayList;

// 17ms 75.93% 48.4MB 100.00%
// graph
// O(N) O(N)
class Solution {
	public int[] gardenNoAdj(int N, int[][] P) {
		// build graph
		Map<Integer, List<Integer>> G = new HashMap<>();
		for (int u = 0; u < N; ++u)
			G.put(u, new ArrayList<Integer>());
		for (int[] path : P) {
			int u = path[0]-1;
			int v = path[1]-1;
			G.get(u).add(v);
			G.get(v).add(u);
		}
		// fill colors
		int[] ans = new int[N];
		for (int u = 0; u < N; ++u) {
			int[] usedColors = new int[5];
			for (int v : G.get(u)) {
				usedColors[ans[v]] = 1;
			}
			for (int c = 4; c > 0; --c) {
                if (usedColors[c] == 0)
				    ans[u] = c;
            }
		}
		return ans;
	}
}
