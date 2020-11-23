// Copyright (C) 2020 by iamslash

// 0: 1
// 1: 1 2
// 1: 1 2 3
// 1: 1 2 3 4
// 2: 1 2 3 4 5
// 3: 1 2 3 4 5 6
// 3: 1 2 3 4 5 6 7

// 0ms 100.00% 37.4MB 100.00%
// math
// O(N) O(1)
class Solution {
	public int minCostToMoveChips(int[] C) {
		int[] cnt = new int[2];
		for (int c : C)
			++cnt[c % 2];
		return Math.min(cnt[0], cnt[1]);
	}
}
