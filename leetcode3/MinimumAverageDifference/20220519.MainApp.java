// Copyright (C) 2022 by iamslash

import java.util.*;

//         i
// nums: 2 5 3 9 5 3

// 10ms 77.08% 74.8MB 69.94%
// partial sum
// O(N) O(1)
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length, minIdx = 0;
        long minAvgDiff = Integer.MAX_VALUE, lSum = 0, rSum = 0;
        for (int num : nums) {
            rSum += num;
        }
        for (int i = 0; i < n; ++i) {
            lSum += nums[i];
            rSum -= nums[i];
            long lAvg = lSum / (i+1);
            long rAvg = i == n-1 ? 0 : rSum / (n-i-1);
            long avgDiff = Math.abs(lAvg - rAvg); 
            if (avgDiff < minAvgDiff) {
                minAvgDiff = avgDiff;
                minIdx = i;
            }
        }
        return minIdx;
    }
}
