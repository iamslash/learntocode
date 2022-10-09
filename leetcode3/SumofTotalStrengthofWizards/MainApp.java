// Copyright (C) 2022 by iamslash

import java.util.*;

// 1 3 1 2
// 1
//   3
//     1
//       2
// 1 3
//   3 1
//     1 2
// 1 3 1
//   3 1 2
// 1 3 1 2

// 1 3 1 2
// 1
// 1 3
// 1 3 1
// 1 3 1 2
//   3
//   3 1
//   3 1 2
//     1
//     1 2
//       2

// Time Limit Exceeded
// brute force
// O(N^2) O(1)
class Solution {
    public int totalStrength(int[] strength) {
        int sum = 0, n = strength.length, mod = 1_000_000_007;
        for (int i = 0; i < n; ++i) {
            int locSum = 0, locMin = 1_000_000_000;
            for (int j = i; j < n; ++j) {
                locSum += strength[j];
                locMin = Math.min(locMin, strength[j]);
                sum = (sum + locMin * locSum % mod) % mod;
            }
        }
        return sum;
    }
}
