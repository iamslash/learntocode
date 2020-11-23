// Copyright (C) 2020 by iamslash

// 5ms 97.08% 47.2MB 100.00%
// partial sum
// O(HW) O(HW)
class Solution {
	public int maxSideLength(int[][] M, int T) {
		int h = M.length, w = M[0].length;
		int[][] gs = new int[h+1][w+1];
		int len = 1, ans = 0;
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				gs[y][x] = gs[y-1][x] + gs[y][x-1] - gs[y-1][x-1] + M[y-1][x-1];
				if (y >= len && x >= len &&
						gs[y][x] - gs[y-len][x] -
						gs[y][x-len] + gs[y-len][x-len] <= T) {
					ans = len++;
				}
			}
		}
		return ans;
	}
}
