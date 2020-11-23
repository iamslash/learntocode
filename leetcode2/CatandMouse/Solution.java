// Copyright (C) 2020 by iamslash

import java.util.*;

// 16ms 90.60% 40.2MB 47.25%
// DFS
// O(N^3) O(N^3)
class Solution {
	private void fill(int[][][]C, int val) {
		for (int i = 0; i < C.length; ++i) {
			for (int j = 0; j < C[0].length; ++j) {
				Arrays.fill(C[i][j], val);
			}
		}
	}
	private int dfs(int[][] G, int[][][]C, int turn, int mouse, int cat) {
		if (turn == G.length * 2) 
			return 0;
		if (mouse == 0)
			return 1;
		if (cat == mouse)
			return 2;
		if (C[turn][mouse][cat] != -1)
			return C[turn][mouse][cat];
		// Move mouse
		if (turn % 2 == 0) {
			boolean catWin = true;
			for (int next : G[mouse]) {
				int r = dfs(G, C, turn+1, next, cat);
				if (r == 1) {
					return C[turn][mouse][cat] = 1;
				}
				if (r == 0) {
					catWin = false;
				}
			}
			if (catWin)
				return C[turn][mouse][cat] = 2;
			return C[turn][mouse][cat] = 0;
		}
		// Move cat
		boolean mouseWin = true;
		for (int next : G[cat]) {
			// cat cannot go to the hole
			if (next == 0)
				continue;
			int r = dfs(G, C, turn+1, mouse, next);
			if (r == 2)
				return C[turn][mouse][cat] = 2;
			if (r == 0)
				mouseWin = false;
		}
		if (mouseWin)
			return C[turn][mouse][cat] = 1;
		return C[turn][mouse][cat] = 0;
	}
	public int catMouseGame(int[][] G) {
		int n = G.length;
		int[][][] C = new int[n+n][n][n];
		fill(C, -1);
		return dfs(G, C, 0, 1, 2);
	}
}
