// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 43.4MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (Long.bitCount(i) == k) {
                sum += nums.get(i);
            }
        }
        return sum;
    }
}
