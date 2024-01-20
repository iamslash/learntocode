// Copyright (C) 2020 by iamslash

import java.util.*;

// 1ms 98.47% 38.9MB 9.46%
// kadane algorithm
// O(N) O(1)
class Solution {
	public int maxProfit(int[] P) {
		int lmax = 0, gmax = 0, n = P.length;
		for (int i = 1; i < n; ++i) {
			lmax = Math.max(0, lmax + P[i] - P[i-1]);
			gmax = Math.max(gmax, lmax);
		}
		return gmax;
	}
}
