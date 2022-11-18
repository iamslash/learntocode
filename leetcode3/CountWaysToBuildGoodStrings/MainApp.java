// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: iterative dynamic programming
//
// Similar with Coin Change problem
// C[i]: count of i length string way
// C[i] = C[i - zero] + C[i - one]

// 30ms 59.86% 43.4MB 89.02%
// iterative dynamic programming
// O(H) O(H)
class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0, MOD = 1_000_000_007;
        int[] C = new int[high + 1];
        C[0] = 1;
        for (int a = 1; a <= high; ++a) {
            if (a >= zero) {
                C[a] = (C[a] + C[a - zero]) % MOD;                
            }
            if (a >= one) {
                C[a] = (C[a] + C[a - one]) % MOD;
            }
            if (a >= low) {
                ans = (ans + C[a]) % MOD;
            }
        }
        return ans;
    }
}
