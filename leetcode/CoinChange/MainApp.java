// Copyright (C) 2024 by iamslash

import java.util.*;

// 15ms 78.58% 44MB 83.65%
// iterative dynamic programming
// O(AC) O(A)
class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[] C = new int[amount + 1];
        Arrays.fill(C, amount + 1);
        C[0] = 0;

        for (int expense = 1; expense <= amount; ++expense) {
            for (int i = 0; i < n; ++i) {
                if (coins[i] <= expense) {
                    C[expense] = Math.min(C[expense], C[expense - coins[i]] + 1);
                }
            }
        }

        if (C[amount] == amount + 1) {
            return -1;
        }

        return C[amount];
    }
}
