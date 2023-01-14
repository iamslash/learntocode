// Copyright (C) 2023 by iamslash

import java.util.*;


// minLen: 2
// maxLen: 3
// oneGrp: 1
// zroGrp: 2
//               i
//      C: 0 0 0 0
//
// Generate binary string
//
// 00
// 11
// 001
// 100
// 111

// Idea: iterative dynaic programming
//
// 1 <= oneGroup, zeroGroup <= maxLength
//             i >= minLen: C[i]++     Why???
//  i + oneGroup <= maxLen: C[i] + C[i + oneGroup]
// i + zeroGroup <= maxLen: C[i] + C[i + zeroGroup]

// 29ms 36.36% 41.5MB 93.94%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int goodBinaryStrings(int minLength, int maxLength,
                                 int oneGroup, int zeroGroup) {
        int MOD = 1_000_000_007;
        long[] C = new long[maxLength + 1];
        for (int i = maxLength; i >= 0; --i) {
            if (i >= minLength) {
                C[i]++;
            }
            if (i + oneGroup <= maxLength) {
                C[i] = (C[i] + C[i + oneGroup]) % MOD;
            }
            if (i + zeroGroup <= maxLength) {
                C[i] = (C[i] + C[i + zeroGroup]) % MOD;
            }
        }
        return (int)C[0];
    }
}

// 11ms 100.00% 42MB 48.48%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int goodBinaryStrings(int minLength, int maxLength,
                                 int oneGroup, int zeroGroup) {
        int MOD = 1_000_000_007;
        int[] C = new int[maxLength + 1];
        C[0] = 1;  // seed

        int ans = 0;
        for (int i = 1; i <= maxLength; ++i) {
            if (i >= oneGroup) {
                C[i] = C[i - oneGroup];  // ???
            }
            if (i >= zeroGroup) {
                C[i] = (C[i] + C[i - zeroGroup]) % MOD;
            }
            if (i >= minLength) {
                ans = (ans + C[i]) % MOD;
            }
        }
        return ans;
    }
}

// 19ms 78.79% 42MB 60.61%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int goodBinaryStrings(int minLength, int maxLength,
                                 int oneGroup, int zeroGroup) {
        int MOD = 1_000_000_007;
        int[] C = new int[maxLength + 1];
        C[0] = 1;  // seed

        for (int i = 1; i <= maxLength; ++i) {
            if (i >= oneGroup) {
                C[i] = (C[i] + C[i - oneGroup]) % MOD;
            }
            if (i >= zeroGroup) {
                C[i] = (C[i] + C[i - zeroGroup]) % MOD;
            }
        }
        int ans = 0;
        for (int i = minLength; i <= maxLength; ++i) {
            ans = (ans + C[i]) % MOD;
        }
        return ans;
    }
}
