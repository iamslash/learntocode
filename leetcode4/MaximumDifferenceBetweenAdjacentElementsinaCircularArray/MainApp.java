// Copyright (C) 2025 by iamslash

import java.util.*;

// nums: 1 2 4
//       3 1 2

// 1ms 99.85% 43.66MB 51.80%
// brute force
// O(N) O(1)
class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int maxAbsDiff = Math.abs(nums[0] - nums[n - 1]);

        for (int i = 1; i < n; ++i) {
            maxAbsDiff = Math.max(maxAbsDiff,
                                  Math.abs(nums[i] - nums[i - 1]));
        }

        return maxAbsDiff;
    }
}
