// Copyright (C) 2021 by iamslash

import java.util.*;

// 0 0 0  1 1 1
// 0 1 0  1 0 1
// 0 0 0  1 1 2

// 0ms 100.00% 37.5MB 74.16%
// iterative dynamic programming
// O(HW) O(1)
class Solution {
	public int uniquePathsWithObstacles(int[][] G) {
		int h = G.length, w = G[0].length;
		if (G[0][0] == 1) {
			return 0;
		}
		G[0][0] = 1;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (y == 0 && x == 0) {
					continue;
				}
				if (G[y][x] == 1) {
					G[y][x] = 0;
				} else {
					int top = y > 0 ? G[y-1][x] : 0;
					int left = x > 0 ? G[y][x-1] : 0;
					G[y][x] = top + left;
				}
			}
		}
		return G[h-1][w-1];
	}
}
