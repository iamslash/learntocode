// Copyright (C) 2023 by iamslash

import java.util.*;

//         
// nums:   2 5  3  9  5  3
//   ps: 0 2 7 10 19 24 27
//         i

// 16ms 88.93% 62MB 37.13%
// partial sum
// O(N) O(1)
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length, minIdx = 0;
        long sum = 0, psum = 0, minVal = Long.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            psum += nums[i];
            int cnt1 = i + 1;
            int cnt2 = Math.max(1, n - i - 1);
            long avgDiff = Math.abs((psum / cnt1) - (sum - psum) / cnt2);
            // System.out.printf("i: %d, avgDiff: %d, minVal: %d\n", i, avgDiff, minVal);
            if (avgDiff < minVal) {
                minIdx = i;
                minVal = avgDiff;
            }
        }
        return minIdx;
    }
}
