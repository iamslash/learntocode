// Copyright (C) 2025 by iamslash

import java.util.*;

// 0ms 100.00% 44.29MB 93.53%
// brute force
// O(N) O(1)
class Solution {
    public int alternatingSum(int[] nums) {
        int sum = 0;
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }

        return sum;
    }
}
