// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 41.5MB 100.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length, minLen = n + 1, bm = 0;
        for (int num : nums) {
            bm |= num;
        }

        if (bm < k) {
            return -1;
        }

        for (int i = 0; i < n; ++i) {
            bm = 0;
            for (int j = i; j < n; ++j) {
                bm |= nums[j];
                if (bm >= k) {
                    minLen = Math.min(minLen, j - i + 1);
                    break;
                }
            }
        }

        return minLen;
    }
}
