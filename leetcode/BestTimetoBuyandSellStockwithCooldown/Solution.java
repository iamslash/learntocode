// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36.6MB 12.56%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public int maxProfit(int[] P) {
		int statH = 0, statB = 0, statS = 0, n = P.length;
		if (n == 0)
			return 0;
		int bStatH = 0, bStatB = -P[0], bStatS = 0;
		for (int i = 1; i < n; ++i) {
			statH = Math.max(bStatH, bStatS);
			statB = Math.max(bStatB, bStatH - P[i]);
			statS = bStatB + P[i];
			bStatH = statH;
			bStatB = statB;
			bStatS = statS;
		}
		return Math.max(statH, statS);
	}
}
