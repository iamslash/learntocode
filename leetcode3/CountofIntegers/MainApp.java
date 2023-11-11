// Copyright (C) 2023 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // brute force
// // O(NS) O(1)
// class Solution {
//     private int mod = 1_000_000_007;
//     private int digitSum(long num) {
//         int sum = 0;
//         while (num > 0) {
//             int digit = (int)(num % 10);
//             num /= 10;
//             sum = (sum + digit) % mod;
//         }
//         return sum;
//     }
//     public int count(String s1, String s2, int minSum, int maxSum) {
//         long num1 = Long.valueOf(s1), num2 = Long.valueOf(s2);
//         int ans = 0;
//         for (long num = num2; num >= num1; --num) {
//             int sum = digitSum(num);
//             // System.out.printf("num: %d, sum: %d\n", num, sum);
//             if (minSum <= sum && sum <= maxSum) {
//                 ans = (ans + 1) % mod;
//             }
//         }
//         return ans;
//     }
// }


// 12

// Idea: recursive dynamic programming
//
// a: The count of num2 cases
// b: The count of (num1 - 1) cases
// The answer is a - b.
//
// C[idx][sum][tight]
// tight == 1: Traverse next digit [0..numStr[idx]]
// tight == 0: Traverse next digit [0..9] 
//
// 182ms 21.25% 44.7MB 32.50%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    private final int mod = 1_000_000_007;
    private long[][][] C;
    private void initCache() {
        for (int i = 0; i < C.length; ++i) {
            for (int j = 0; j < C[0].length; ++j) {
                Arrays.fill(C[i][j], -1);
            }
        }
    }
    private long dfs(int minSum, int maxSum, String s, int idx, int sum, int tight) {
        // base
        if (idx == s.length()) {
            return (minSum <= sum && sum <= maxSum) ? 1: 0;
        }
        // memo
        if (C[idx][sum][tight] >= 0) {
            return C[idx][sum][tight];
        }
        // recursion
        long ans = 0;
        if (tight == 1) {
            for (int i = 0; i <= s.charAt(idx) - '0'; ++i) {
                if (i == s.charAt(idx) - '0') {
                    ans = (ans + dfs(minSum, maxSum, s, idx + 1, sum + i, 1)) % mod;
                } else {
                    ans = (ans + dfs(minSum, maxSum, s, idx + 1, sum + i, 0)) % mod;
                }
            }
        } else {
            for (int i = 0; i <= 9; ++i) {
                ans = (ans + dfs(minSum, maxSum, s, idx + 1, sum + i, 0)) % mod;
            }
        }
        return C[idx][sum][tight] = ans;
    }
    public int count(String s1, String s2, int minSum, int maxSum) {
        // C[idx][sum][tight]
        C = new long[23][401][2];

        initCache();
        long num2Cnt = dfs(minSum, maxSum, s2, 0, 0, 1);

        initCache();
        long num1Cnt = dfs(minSum, maxSum, s1, 0, 0, 1);

        // This looks additional. but s1 might be too long for
        // decreasing one. ex) "1012640017461217236611"
        int sum = 0;
        for (char c : s1.toCharArray()) {
            sum += (c - '0');
        }
        if (minSum <= sum && sum <= maxSum) {
            num1Cnt--;
        }
        long ans = (num2Cnt - num1Cnt + mod) % mod;
        return (int)ans;
    }
}
