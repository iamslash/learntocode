// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 2 6 5 8
//    k: 2
//
//           1 0    2
//         1 1 0    6
//         1 0 1    5
//       1 0 0 0    8
//
// cnts: 1 2 2 1

// Idea: bit manipulation
//
// Consider the simple pair of numbers.
// (1, 1) -> (1 & 1, 1 | 1) -> (1, 1)
// (0, 0) -> (0 & 0, 0 | 0) -> (0, 0)
// (0, 1) -> (0 & 1, 0 | 1) -> (0, 1)
// (1, 0) -> (1 & 0, 1 | 0) -> (0, 1)
// The first three cases do not change.
// The last case move the bit from A[i] to A[j]
//
// For example,
// 10101110
// 10111001
// After operation
// 10101000
// 10111111
//
// The count of bits does not change.
//
// 69ms 67.27% 59.3MB 40.33%
// bit manipulation, greedy
// O(N) O(K)
class Solution {
    public int maxSum(List<Integer> nums, int k) {
        int cnts[] = new int[32];
        long ans = 0, cur = 0, mod = 1_000_000_007;
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num & (1 << i)) > 0) {
                    cnts[i]++;
                }
            }
        }
        for (int j = 0; j < k; j++) {
            cur = 0;
            for (int i = 0; i < 32; ++i) {
                if (cnts[i] > 0) {
                    cnts[i]--;
                    cur += 1 << i;
                }
            }
            ans = (ans + cur * cur % mod) % mod;
        }
        return (int)ans;
    }
}
