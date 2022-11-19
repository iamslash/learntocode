// Copyright (C) 2022 by iamslash

import java.util.*;

// 201ms 52.40% 125.3MB 49.87%
// recursive dynamic programming
// O(N) O(N)
class Solution {
    private int MOD = 1_000_000_007;
    private int dfs(int[][] C, int s, int e, int k) {
        // base
        if (s == e && k == 0) {
            return 1;
        }
        if (k == 0) {
            return 0;
        }
        // memo
        if (C[s + 1000][k] >= 0) {
            return C[s + 1000][k];
        }
        // recursion
        int left = dfs(C, s - 1, e, k - 1);
        int right = dfs(C, s + 1, e, k - 1);
        return C[s + 1000][k] = (left + right) % MOD;
    }
    public int numberOfWays(int s, int e, int k) {
        int[][] C = new int[3001][k+1];
        for (int i = 0; i < C.length; ++i) {
            Arrays.fill(C[i], -1);
        }
        return dfs(C, s, e, k);
    }
}

