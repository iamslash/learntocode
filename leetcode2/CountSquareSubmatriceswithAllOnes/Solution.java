// Copyright (C) 2020 by iamslash

// 0 1 1 1
// 1 1 1 1
// 0 1 1 1

import java.util.Collections;
import java.util.Arrays;

// 19ms 12.89% 48.6MB 100.00%
// dynamic programming
// O(HW) O(1)
class Solution {
	public int countSquares(int[][] M) {
		int cnt = 0;
		for (int y = 0; y < M.length; y++) {
			for (int x = 0; x < M[0].length; x++) {
				if (M[y][x] > 0 && y > 0 && x > 0) {
					Integer[] arr = {M[y][x-1], M[y-1][x-1], M[y-1][x]};
					M[y][x] = Collections.min(Arrays.asList(arr)) + 1;
				}
				cnt += M[y][x];
			}
		}
		return cnt;
	}
}
