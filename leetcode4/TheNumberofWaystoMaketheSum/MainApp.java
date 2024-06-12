// Copyright (C) 2024 by iamslash

import java.util.*;

// 88ms 100.00% 44.6MB 100.00%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int numberOfWays(int n) {
        int mod = 1_000_000_007;
        int[] coins = new int[]{1, 2, 6};
        long[] cases = new long[n + 1];
        cases[0] = 1;

        for (int i = 0; i < coins.length; ++i) {
            for (int amt = coins[i]; amt <= n; ++amt) {
                cases[amt] = (cases[amt] + cases[amt - coins[i]]) % mod;
            }
        }

        long ans = cases[n];
        if (n >= 4) {
            ans = (ans + cases[n - 4]) % mod;
        }
        if (n >= 8) {
            ans = (ans + cases[n - 8]) % mod;
        }

        return (int)ans;
    }
}
