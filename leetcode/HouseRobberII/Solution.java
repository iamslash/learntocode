// Copyright (C) 2021 by iamslash

import java.util.*;

//            i
//            1 2 3 1
// maxCurr: 0 1 2 4 4
// max2ago: 0 0 1 2 4
// max1ago: 0 1 2 4 4

// 0ms 100.00% 36.2MB 89.56%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	private int maxRob(int[] A, int lo, int hi) {
		int maxCurr = 0, max2ago = 0, max1ago = 0;
		for (int i = lo; i <= hi; ++i) {
			maxCurr = Math.max(max2ago + A[i], max1ago);
			max2ago = max1ago;
			max1ago = maxCurr;
		}
		return maxCurr;
	}
	public int rob(int[] A) {
		int n = A.length;
		if (n == 1)
			return A[0];
		return Math.max(maxRob(A, 0, n-2),
										maxRob(A, 1, n-1));
	}
}
