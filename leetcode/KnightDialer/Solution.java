// Copyright (C) 2020 by iamslash

import java.util.*;

// 23ms 94.02% 36MB 94.14%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	private final int MOD = 1000000007;
	public int knightDialer(int n) {
		int[][] moves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4},
      };
		int[] C0 = new int[10], C1 = new int[10];
		Arrays.fill(C0, 1);
		while (--n > 0) {
			for (int i = 0; i < 10; ++i) {
				C1[i] = 0;
				for (int key : moves[i]) {
					C1[i] = (C1[i] + C0[key]) % MOD;
				}
			}
			int[] t = C0;
			C0 = C1;
			C1 = t;
		}
		int sum = 0;
		for (int i = 0; i < 10; ++i) {
			sum = (sum + C0[i]) % MOD;
		}
		return sum;
	}
}
