// Copyright (C) 2021 by iamslash

import java.util.*;

// M:        H:
// 1 0 1     3 2 0
// 1 1 0 
// 1 1 0 y
//     x
//     k
// ans:
// 13

// 4ms 88.07% 53.4MB 5.10%
// iterative dynamic programming
// O(HW^2) O(W)
class Solution {
	public int numSubmat(int[][] M) {
		int h = M.length, w = M[0].length, ans = 0;
		int[] H = new int[w];
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (M[y][x] == 0) {
					H[x] = 0;
				} else {
					H[x] += 1;
				}
				for (int k = x, minH = H[x]; k >= 0 && minH > 0; --k) {
					minH = Math.min(minH, H[k]);
					ans += minH;
				}				
			}
		}
		return ans;
	}
}
