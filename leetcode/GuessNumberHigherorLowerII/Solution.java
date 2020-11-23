// Copyright (C) 2020 by iamslash

import java.util.*;

// 50ms 8.07%
// recursive dynamic programming
// O(N^2) O(N^2)
class Solution {
	private int dfs(int[][] C, int s, int e) {
		// base
		if (s >= e)
			return 0;
		// memo
		if (C[s][e] >= 0)
			return C[s][e];
		// recursion
		int r = Integer.MAX_VALUE;
		for (int x = s; x <= e; ++x) {
			int t = x + Math.max(dfs(C, s, x-1), dfs(C, x+1, e));
			r = Math.min(r, t);
		}
		return C[s][e] = r;
	}
	public int getMoneyAmount(int n) {
		int[][] C = new int[n+1][n+1];
		for (int i = 0; i < C.length; ++i) {
			Arrays.fill(C[i], -1);
		}
		return dfs(C, 1, n);
	}
}
