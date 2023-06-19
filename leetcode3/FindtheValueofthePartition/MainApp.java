// Copyright (C) 2023 by iamslash

import java.util.*;

// 23ms 23.34% 54.3MB 89.04%
// sort
// O(NlgN) O(1)
class Solution {
    public int findValueOfPartition(int[] nums) {
        int minDiff = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; ++i) {
            minDiff = Math.min(minDiff, nums[i] - nums[i-1]);
        }
        return minDiff;
    }
}
