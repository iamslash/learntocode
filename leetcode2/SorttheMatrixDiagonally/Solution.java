// Copyright (C) 2020 by iamslash

// use k, y, x index
// O(H^2W) O(1)
// use k, y, x index
// O(H^2W) O(1)
class Solution {
	public int[][] diagonalSort(int[][] M) {
		int h = M.length, w = M[0].length;
		for (int k = 0; k < h; ++k) {
			for (int y = 0; y < h-1; ++y) {
				for (int x = 0; x < w-1; ++x) {
					if (M[y][x] > M[y+1][x+1]) {
						int t = M[y][x];
						M[y][x] = M[y+1][x+1];
						M[y+1][x+1] = t;
					}
				}
			}
		}
		return M;
	}
}
