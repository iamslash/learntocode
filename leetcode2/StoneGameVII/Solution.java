// Copyright (C) 2020 by iamslash

import java.util.*;

// recursive dynamic programming
// O(N^2) O(N^2)
// 146ms 37.82% 49.9MB 67.89%

class Solution {
	private int dfs(int[][] C, int[] S, int i, int j, int sum) {
		// base
		if (i == j) {
			return 0;
		}
		// memo
		if (C[i][j] >= 0) {
			return C[i][j];
		}
		// recursion
		C[i][j] = Math.max(sum - S[i] - dfs(C, S, i+1, j, sum - S[i]),
											 sum - S[j] - dfs(C, S, i, j-1, sum - S[j]));
		return C[i][j];
	}
	public int stoneGameVII(int[] S) {
		int[][] C = new int[1001][1001];
		for (int i = 0; i < C.length; ++i) {
			Arrays.fill(C[i], -1);
		}
		int n = S.length, sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += S[i];
		}
		return dfs(C, S, 0, n-1, sum);
	}
}
