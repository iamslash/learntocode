// Copyright (C) 2020 by iamslash

import java.util.*;

// 2ms 90.09% 38MB 47.23%
// recursive dynamic programming
// O(WB) O(W)
class Solution {
	private int dfs(int[][] W, int[][] B, int[][] C, int i, int bused) {
		int m = W.length, n = B.length;
		// base
		if (i >= m)
			return 0;
		// memo
		if (C[i][bused] >= 0)
			return C[i][bused];
		// recursion
		C[i][bused] = Integer.MAX_VALUE;
		for (int j = 0; j < n; ++j) {
			int bm = 1 << j;
			if ((bm & bused) > 0)
				continue;
			int dist = Math.abs(W[i][0] - B[j][0]) +
					Math.abs(W[i][1] - B[j][1]);
			dist += dfs(W, B, C, i+1, bused | bm);
			C[i][bused] = Math.min(C[i][bused], dist);
		}
		return C[i][bused];
	}
	public int assignBikes(int[][] W, int[][] B) {
		int[][] C = new int[10][1024];
		for (int[] item : C) {
			Arrays.fill(item, -1);
		}
		return dfs(W, B, C, 0, 0);
	}
}
