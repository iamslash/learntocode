// Copyright (C) 2023 by iamslash

import java.util.*;


// l e e t
// 

// 89ms 52.54% 84MB 36.24%
// recursive dynamic programming
// O(26^N) O(N)
class Solution {
    int mod = 1_000_000_007;
    // C[index][count of 'l'][count of 't'][count of 'e']
    long C[][][][];
    private long dfs(int n, int lcnt, int ecnt, int tcnt) {
        // base
        if (n == 0) {
            if (lcnt == 0 &&
                ecnt == 0 &&
                tcnt == 0) {
                return 1L;
            }
            return 0L;
        }
        // memo
        if (C[n][lcnt][ecnt][tcnt] >= 0) {
            return C[n][lcnt][ecnt][tcnt];
        }
        // recursion
        // 23 alphabets except 'l', 'e', 't'.
        long ans = dfs(n - 1, lcnt, ecnt, tcnt) * 23 % mod;
        ans = (ans + dfs(n - 1, Math.max(lcnt - 1, 0), ecnt, tcnt)) % mod;
        ans = (ans + dfs(n - 1, lcnt, Math.max(ecnt - 1, 0), tcnt)) % mod;
        ans = (ans + dfs(n - 1, lcnt, ecnt, Math.max(tcnt - 1, 0))) % mod;
        return C[n][lcnt][ecnt][tcnt] = ans;
    }
    public int stringCount(int n) {
        C = new long[n + 1][2][3][2];
        for (int i = 0; i < C.length; ++i) {
            for (int j = 0; j < C[0].length; ++j) {
                for (int k = 0; k < C[0][0].length; ++k) {
                    Arrays.fill(C[i][j][k], -1);
                }
            }
        }
        return (int)dfs(n, 1, 2, 1);
    }
}
