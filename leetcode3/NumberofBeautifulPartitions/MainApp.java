// Copyright (C) 2023 by iamslash

import java.util.*;

//         k: 3
// minLnegth: 2
//    
//         s: 2 3 5 4 2 1 8 5 1 3 1
//            i
//                  j

// 718ms 23.43% 47.6MB 82.41%
// recursive dynamic programming
// O(NK) O(NK)
class Solution {
    private boolean isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    private int dfs(int[][] C, String s, int minLen, int i, int k) {
        // base
        int MOD = 1_000_000_007;
        int n = s.length();
        if (i == n && k == 0) {
            return 1;
        }
        if (i >= n || k < 0) {
            return 0;
        }
        // memo
        if (C[i][k] >= 0) {
            return C[i][k];
        }
        // recursion
        int ans = 0;
        if (isPrime(s.charAt(i))) {
            // xxxxxx
            // i    j
            // j - i + 1 >= minLen
            //         j >= minLen + i - 1
            for (int j = i + minLen - 1; j < n; ++j) {
                // Prune
                if ((j + 1) + (k - 1) * minLen > n) {
                    break;
                }
                if (isPrime(s.charAt(j))) {
                    continue;
                }
                ans = (ans + dfs(C, s, minLen, j + 1, k - 1)) % MOD;
            }
        }
        return C[i][k] = ans;
    }
    public int beautifulPartitions(String s, int k, int minLength) {
        int n = s.length();
        if (!isPrime(s.charAt(0)) || isPrime(s.charAt(n-1))) {
            return 0;
        }
        int[][] C = new int[n][k + 1];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(C[i], -1);
        }
        return dfs(C, s, minLength, 0, k);
    }
}
