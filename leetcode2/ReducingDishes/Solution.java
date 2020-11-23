// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 100.00% 37.8MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
	public int maxSatisfaction(int[] S) {
		Arrays.sort(S);
		int ans = 0, prevSum = 0, n = S.length;
		for (int i = n-1; i >= 0 && S[i] + prevSum > 0; --i) {
			prevSum += S[i];
			ans += prevSum;
		}
		return ans;
	}
}
