// Copyright (C) 2020 by iamslash

// M:
// 1 2 3
// 4 5 6
// 7 8 9
// 
// K: 1
// 

// 6ms 35.78% 46.6MB 100.00%
// partial sum
// O(HW) O(HW)
class Solution {
	public int[][] matrixBlockSum(int[][] M, int K) {
		int h = M.length, w = M[0].length;
		int[][] gs = new int[h+1][w+1];
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				gs[y+1][x+1] = M[y][x] + gs[y][x+1] +
						gs[y+1][x] - gs[y][x];
			}
		}
		int[][] ans = new int[h][w];
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int a = Math.max(0,   y-K);
				int b = Math.max(0,   x-K);
				int c = Math.min(h-1, y+K);
				int d = Math.min(w-1, x+K);
				
				ans[y][x] = gs[c+1][d+1] - gs[c+1][b] -
						gs[a][d+1] + gs[a][b];
			}
		}
		return ans;
	}
}
