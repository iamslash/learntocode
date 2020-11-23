// Copyright (C) 2020 by iamslash

import java.util.*;

// 1ms 6.91% 38MB 5.03%
// recursive dynanmic programming
// O(HW) O(HW)
class Solution {
	private int dfs(int[][] C, int h, int w, int y, int x) {
		// base
		if (y == h-1 && x == w-1)
			return 1;
		if (y >= h || x >= w)
			return 0;
		// memo
		if (C[y][x] >= 0)
			return C[y][x];
		// recursion
		int r = dfs(C, h, w, y+1, x) + dfs(C, h, w, y, x+1);
		return C[y][x] = r;
	}
	public int uniquePaths(int h, int w) {
		int[][] C = new int[100][100];
		for (int i = 0; i < C.length; ++i) {
			Arrays.fill(C[i], -1);
		}
		return dfs(C, h, w, 0, 0);
	}
}

// 0ms 100.00% 36.1MB 26.02%
// iterative dynamic programming
// O(HW) O(HW)
class Solution {
	public int uniquePaths(int h, int w) {
		int[][] C = new int[h][w];
		C[0][0] = 1;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (y > 0) {
					C[y][x] += C[y-1][x];
				}
				if (x > 0) {
					C[y][x] += C[y][x-1];
				}
			}
		}
		return C[h-1][w-1];
	}
}
