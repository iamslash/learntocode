// Copyright (C) 2021 by iamslash

import java.util.*;

// partial sum
// O(N) O(N)
class Solution {
	public boolean[] canEat(int[] candiesCount, int[][] queries) {
		int m = candiesCount.length, n = queries.length;
		long[] ps = new long[m];
		ps[0] = candiesCount[0];
		boolean[] ans = new boolean[n];
		for (int i = 1; i < m; ++i) {
			ps[i] += ps[i-1];
		}
		for (int i = 0; i < n; ++i) {
			int type = queries[i][0];
			int day = queries[i][1];
			long cap = queries[i][2];
			long mostCnt = (day + 1) * cap;
			long leastCnt = day + 1;
			ans[i] = (mostCnt > ((type == 0) ? 0 : ps[type-1]) &&
								leastCnt <= ps[type]);
		}
		return ans;
	}
}
