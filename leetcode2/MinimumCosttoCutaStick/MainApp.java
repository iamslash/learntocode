// Copyright (C) 2023 by iamslash

import java.util.*;

// // Memory Limit Exceeded
// // Inputs:
// // 7249
// // [2542,5776,4306,1787,1536,2520,2558,4289,2390,1371,2526,256,3025,1752,1780,2652,4815,5689,2719,7034,7058,1431,5086,1137,481,3977,1047,899,3915,1615,4996,5317,5330,3010,6987,2633,4396,6006,687,4870,434,4876,3067,4006,2043,2519,2881,2083,3784,6733,3129,6723,5936,3139,908,226]
// // recursive dyanmic programming
// // O(N^2) O(N^2)
// class Solution {
//     private int dfs(int[] cuts, int[][] C, int l, int r) {
//         int n = cuts.length;
//         // memo
//         if (C[l][r] >= 0) {
//             return C[l][r];
//         }
//         // recursion
//         C[l][r] = Integer.MAX_VALUE;
//         for (int i = 0; i < n; ++i) {
//             if (cuts[i] <= l || cuts[i] >= r) {
//                 continue;
//             }
//             int cost = r - l;
//             C[l][r] = Math.min(C[l][r],
//                                cost +
//                                dfs(cuts, C, l, cuts[i]) +
//                                dfs(cuts, C, cuts[i], r));
//         }
//         return C[l][r];
//     }
//     public int minCost(int n, int[] cuts) {
//         Arrays.sort(cuts);
//         int[][] C = new int[n+1][n+1];
//         for (int i = 0; i < n; ++i) {
//             Arrays.fill(C[i], -1);
//         }
//         return dfs(cuts, C, 0, n);
//     }
// }

// // 816ms 5.04% 49.4MB 5.51%
// // recursive dyanamic programming
// // O(N^2) O(N^2)
// class Solution {
//     private int dfs(int[] cuts, Map<String, Integer> C, int l, int r) {
//         // base
//         int rst = Integer.MAX_VALUE, m = cuts.length;        
//         // memo
//         String key = l + "," + r;
//         if (C.containsKey(key)) {
//             return C.get(key);
//         }
//         for (int i = 0; i < m; ++i) {
//             if (cuts[i] <= l || cuts[i] >= r) {
//                 continue;
//             }
//             rst = Math.min(rst,
//                            dfs(cuts, C, l, cuts[i]) +
//                            r - l +
//                            dfs(cuts, C, cuts[i], r));
//         }
//         if (rst == Integer.MAX_VALUE) {
//             rst = 0;
//         }
//         C.put(key, rst);
//         return rst;
//     }
//     public int minCost(int n, int[] cuts) {
//         Arrays.sort(cuts);
//         Map<String, Integer> C = new HashMap<>();
//         return dfs(cuts, C, 0, n);
//     }
// }

// 12ms 80.63% 42.3MB 56.85%
// iterative dynamic programming
// O(M^3) O(M^3)
class Solution {
    public int minCost(int n, int[] cuts) {
        int m = cuts.length + 2;
        int[] tgtCuts = new int[m];
        System.arraycopy(cuts, 0, tgtCuts, 0, m - 2);
        tgtCuts[m-2] = 0;
        tgtCuts[m-1] = n;
        Arrays.sort(tgtCuts);
        int[][] C = new int[m][m];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = i + 1; j < m; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    if (C[i][j] == 0) {
                        C[i][j] = Integer.MAX_VALUE;
                    }
                    C[i][j] = Math.min(C[i][j],
                                       C[i][k] +
                                       tgtCuts[j] - tgtCuts[i] +
                                       C[k][j]);
                }
            }
        }
        return C[0][m - 1];
    }
}
