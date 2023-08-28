// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: greedy
//
// r = num1 - k * num2
// 0 <= k <= 60
// Find minimum k (bitcount(r) <= k <= r)

// 0ms 100.00% 39.1MB 98.57%
// math
// O(1) O(1)
class Solution {
    public int makeTheIntegerZero(long num1, long num2) {
        for (int k = 1; k <= 60; ++k) {
            long r = num1 - k * num2;
            if (Long.bitCount(r) <= k && k <= r) {
                return k;
            }
        }
        return -1;
    }
}
