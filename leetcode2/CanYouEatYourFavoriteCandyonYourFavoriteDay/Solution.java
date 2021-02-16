// Copyright (C) 2021 by iamslash

import java.util.*;

// 4ms 100.00% 77.4MB 52.79%
// partial sum
// O(N) O(N)
class Solution {
	public boolean[] canEat(int[] candiesCount, int[][] queries) {
		int m = candiesCount.length, n = queries.length;
		long[] ps = new long[m+1];
		boolean[] ans = new boolean[n];
		for (int i = 1; i <= m; ++i) {
			ps[i] = ps[i-1] + candiesCount[i-1];
		}
		for (int i = 0; i < n; ++i) {
			int type = queries[i][0];
			int day = queries[i][1];
			long cap = queries[i][2];
			long mostCnt = (day + 1) * cap;
			long leastCnt = day + 1;
			ans[i] = (ps[type] < mostCnt) &&
					(ps[type+1] >= leastCnt);
		}
		return ans;
	}
}
