// Copyright (C) 2024 by iamslash

import java.util.*;

//         i
// nums: 1 5 8
//         8 8

// 1ms 100.00% 58.18% 92.31%
// backward
// O(N) O(1)
class Solution {
    public long maxScore(int[] nums) {
        int n = nums.length, maxVal = nums[n - 1];
        long sum = 0;

        for (int i = n - 1; i > 0; --i) {
            maxVal = Math.max(maxVal, nums[i]);
            sum += maxVal;
        }

        return sum;
    }
}
