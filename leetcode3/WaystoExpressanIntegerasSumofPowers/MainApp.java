// Copyright (C) 2023 by iamslash

import java.util.*;

// x:  2
// n: 10
//
// v:  1
// n: 10 9 8 7 6 5 4 3 2 1
// C:  0 0 0 0 0 0 0 0 0 1 1
//
// v:  4
// n: 10 9 8 7 6 5 4 3 2 1
// C:  0 0 0 0 0 1 1 0 0 1 1
// 
// v:  9
// n: 10 9 8 7 6 5 4 3 2 1
// C:  1 1 0 0 0 1 1 0 0 1 1

// Idea: iterative dynamic programming
//
// C[i] = (C[i] + C[i - v]) % mod
//
// See also:
//   https://leetcode.com/problems/coin-change/description/
//
// 12ms 99.09% 41.1MB 92.99%
// iterative dynamic programming
// O(NlgN) O(N)
class Solution {
    public int numberOfWays(int n, int x) {
        int[] C = new int[n + 1];
        C[0] = 1;
        int mod = 1_000_000_007;

        for (int a = 1; a <= n; ++a) {
            int v = (int) Math.pow(a, x);
            if (v > n) {
                break;
            }

            for (int i = n; i >= v; --i) {
                C[i] = (C[i] + C[i - v]) % mod;
            }
        }
        
        return C[n];
    }
}
