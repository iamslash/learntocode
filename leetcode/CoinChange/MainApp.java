// Copyright (C) 2023 by iamslash

import java.util.*;

// dfs(3)
//   dfs(

// 37ms 23.17% 44.1MB 17.63%
// recursive dynamic programming
// O(AN) O(A)
class Solution {
    private int dfs(int[] coins, int[] C, int avail) {
        int n = coins.length;
        // base
        if (avail <= 0) {
            return 0;
        }
        // memo
        if (C[avail] >= 0) {
            return C[avail];
        }
        // recursion
        int minCnt = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            if (coins[i] <= avail) {
                int cnt = dfs(coins, C, avail - coins[i]);
                if (cnt != Integer.MAX_VALUE) {
                    minCnt = Math.min(minCnt, cnt + 1);
                }
            }
        }
        return C[avail] = minCnt;
    }
    public int coinChange(int[] coins, int amount) {
        int[] C = new int[amount + 1];
        Arrays.fill(C, -1);
        C[0] = 0;
        int minCnt = dfs(coins, C, amount);
        if (minCnt == Integer.MAX_VALUE) {
            return -1;
        }
        return minCnt;
    }
}

// // 17ms 78.50% 42.9MB 74.61%
// // iterative dynamic programming
// // O(AN) O(A)
// class Solution {
//     public int coinChange(int[] coins, int amount) {
//         int n = coins.length;
//         int[] C = new int[amount + 1];
//         Arrays.fill(C, amount + 1);
//         C[0] = 0;        

//         for (int a = 0; a <= amount; ++a) {
//             for (int i = 0; i < n; ++i) {
//                 if (coins[i] <= a) {
//                     C[a] = Math.min(C[a], C[a - coins[i]] + 1);
//                 }
//             }
//         }
//         if (C[amount] == amount + 1) {
//             return -1;
//         }
//         return C[amount];
//     }
// }
