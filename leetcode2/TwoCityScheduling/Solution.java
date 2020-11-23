// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 170 10 -10 -350

// 2ms 36.10% 38.9MB 63.89%
// sort
// O(NlgN) O(1)
class Solution {
	public int twoCitySchedCost(int[][] C) {
		Arrays.sort(C, (a, b) -> -Integer.valueOf(a[1]-a[0]).compareTo(b[1]-b[0]));
		int n = C.length / 2;
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans += C[i][0];
		for (int i = n; i < 2*n; ++i)
			ans += C[i][1];
		return ans;
	}
}
