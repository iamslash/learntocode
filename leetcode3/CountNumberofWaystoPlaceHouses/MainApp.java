// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: recursive dynamic programming
//
// dfs(n, placed)
// return: cnt
//      n: remained houses
//  place: placed or not before

// 77ms 13.55% 55.3MB 11.21%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    private long mod = 1_000_000_007L;
    public int countHousePlacements(int n) {
        long[][] C = new long[n+1][2];
        long cnt = (dfs(C, n, 0) + dfs(C, n, 1)) % mod;
        return (int)(cnt * cnt % mod);
    }
    private long dfs(long[][] C, int n, int placed) {
        // base
        if (n == 1) {
            return 1;
        }
        // memo
        if (C[n][placed] > 0) {
            return C[n][placed];
        }
        // recursion
        if (placed == 1) {
            return C[n][placed] = dfs(C, n-1, 0);
        }
        return C[n][placed] = (dfs(C, n-1, 1) + dfs(C, n-1, 0)) % mod;
    }
}
