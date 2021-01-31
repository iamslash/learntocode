// Copyright (C) 2021 by iamslash

import java.util.*;

// 5ms 47.56% 38MB 98.24%
// recursive dynamic programming
class Solution {
	private int dfs(int[] piles, int[][]C, int i, int M, int left) {
		int n = piles.length;
		// memo
		if (C[i][M] >= 0)
			return C[i][M];
		// recusion
		int r = 0;
		int taken = 0;
		int bound = Math.min(n, i + 2 * M);
		for (int j = i; j < bound; ++j) {
			taken += piles[j];
			int nM = Math.max(M, j - i + 1);
			r = Math.max(r, left - dfs(piles, C, j+1, nM, left - taken));
		}
		return C[i][M] = r;
	}
	public int stoneGameII(int[] piles) {
		int n = piles.length;
		int[][] C = new int[n+1][n+1];
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += piles[i];
			Arrays.fill(C[i], -1);
		}
		Arrays.fill(C[n], -1);
		return dfs(piles, C, 0, 1, sum);
	}
}
