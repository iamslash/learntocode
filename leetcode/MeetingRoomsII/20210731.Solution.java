// Copyright (C) 2020 by iamslash

import java.util.*;

//        i
//  0  5 15
// 10 20 30
//  j

//              i
//      4  4  9
//   I: 9 10 17
//         j
// ans: 2

// 2ms 95.46% 38.4MB 99.38%
// sort
// O(NlgN) O(N)
class Solution {
	public int minMeetingRooms(int[][] intervals) {
		if (intervals == null || intervals.length == 0 ||
				intervals[0].length == 0) {
			return 0;
		}
		int n = intervals.length;
		int[] begArr = new int[n];
		int[] endArr = new int[n];
		for (int i = 0; i < n; ++i) {
			begArr[i] = intervals[i][0];
			endArr[i] = intervals[i][1];
		}
		Arrays.sort(begArr);
		Arrays.sort(endArr);
		int ans = 0;
		for (int i = 0, j = 0; i < n; ++i) {
			if (begArr[i] < endArr[j]) {
				ans++;
			} else {
				j++;
			}
		}
		return ans;
	}
}
