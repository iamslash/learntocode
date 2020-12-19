// Copyright (C) 2020 by iamslash

// 0ms 100.00% 35.9MB 35.49%
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
