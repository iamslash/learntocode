// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 43.4MB 25.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int maximumStrongPairXor(int[] nums) {
        int n = nums.length, maxXor = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (Math.abs(nums[i] - nums[j]) <= Math.min(nums[i], nums[j])) {
                    maxXor = Math.max(maxXor, nums[i] ^ nums[j]);
                }
            }
        }
        return maxXor;
    }
}
