// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 39.1MB 80.00%
// brute force
// O(N) O(1)
class Solution {
	public int countGoodRectangles(int[][] rectangles) {
		int maxLen = 0, maxCnt = 0;
		for (int[] rec : rectangles) {
			int minLen = Math.min(rec[0], rec[1]);
			if (minLen > maxLen) {
				maxLen = minLen;
				maxCnt = 0;
			}
			if (maxLen == minLen) {
				maxCnt++;
			}
		}
		return maxCnt;
	}
}
