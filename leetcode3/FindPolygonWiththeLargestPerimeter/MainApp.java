// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea: sort, prefix sum
//
// The perimeter > 2 * the longest side

// 28ms 98.62% 56.1MB 88.54%
// sort, prefix sum
// O(NlgN) O(1)
class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long ans = -1, cur = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            cur += nums[i];
            if (cur > nums[i] * 2) {
                ans = cur;
            }
        }
        return ans;
    }
}
