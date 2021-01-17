// Copyright (C) 2021 by iamslash

import java.util.*;

// M:       H:       SH:
// 0 0 1    0 0 1    0 0 1
// 1 1 1    1 1 2    1 1 2
// 1 0 1    2 0 3    0 2 3

// 1 1 0
// 0 1 0
// 0 0 1
// 0 1 1
// 0 1 1

// 41ms 83.33% 112.4MB 16.67%
// sort
// O(HWlgW) O(W)
class Solution {
	public int largestSubmatrix(int[][] matrix) {
		int h = matrix.length, w = matrix[0].length, ans = 0;
		Integer[] heightArr = new Integer[w];
    Arrays.fill(heightArr, 0);
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (matrix[y][x] == 0) {
					heightArr[x] = 0;
				} else {
					heightArr[x] += 1;
				}
			}
			Integer[] sortedHeights = Arrays.copyOf(heightArr, w);
			Arrays.sort(sortedHeights);
			for (int x = 0; x < w; ++x) {
				ans = Math.max(ans, (w - x) * sortedHeights[x]);
			}
		}
		return ans;
	}
}
