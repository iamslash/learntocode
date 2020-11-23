// Copyright (C) 2020 by iamslash

import java.util.Arrays;

//                i
// [1,4] [2,8] [2,6] [3,6]
//       last

// 4ms 93.82% 39.4MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
	public int removeCoveredIntervals(int[][] I) {
		Arrays.sort(I, (a, b) -> {
				if (a[0] == b[0])
					return Integer.compare(b[1], a[1]);
				return Integer.compare(a[0], b[0]);
			});
		int last = -1, ans = 0;
		for (int[] i : I) {
			if (last < i[1]) {
				ans++;
				last = i[1];
			}
		}
		return ans;
	}
}
