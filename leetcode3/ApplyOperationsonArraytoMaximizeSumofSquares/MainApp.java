// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 2 6 5 8
//    k: 2
//
//       10
//      110
//      101
//     1000

// Idea: bit manipulation
//
// (1, 1) -> (1 & 1, 1 | 1) -> (1, 1)
// (0, 0) -> (0 & 0, 0 | 0) -> (0, 0)
// (0, 1) -> (0 & 1, 0 | 1) -> (0, 1)
// (1, 0) -> (1 & 0, 1 | 0) -> (0, 1)
//
// The last case move the bit from A[i] to A[j]


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
