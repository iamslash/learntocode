// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36MB 14.59%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public int climbStairs(int n) {
		int a = 1, b = 1, t = 0;
		for (int i = 2; i <= n; ++i) {
			t = a + b;
			b = a;
			a = t;
		}
		return a;
	}
}
