// Copyright (C) 2021 by iamslash

import java.util.*;

//           i
//  coins: 1 2 5
// amount: 11
//      C: 0 1 1 2 M M M M M M M M

// 11ms 87.46% 38MB 97.32%
// iterative dynamic programming
// O(AC) O(A)
class Solution {  
	public int coinChange(int[] coins, int amount) {
    final int MAXVAL = 40000;
		int n = coins.length;
		int[] C = new int[amount+1];
		Arrays.fill(C, MAXVAL);
		C[0] = 0;
		for (int i = 0; i <= amount; ++i) {
			for (int j = 0; j < n; ++j) {
				if (coins[j] <= i) {
					C[i] = Math.min(C[i], C[i - coins[j]] + 1);
				}
			}
		}
		return C[amount] >= MAXVAL ? -1 : C[amount];
	}
}
