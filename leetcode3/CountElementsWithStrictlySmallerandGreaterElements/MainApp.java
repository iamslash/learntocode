// Copyright (C) 2022 by iamslash

import java.util.*;

// sort
// O(NlgN) O(1)
class Solution {
    public int countElements(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return 0;
        }
        Arrays.sort(nums);
        int minVal = nums[0], minCnt = 0;
        int maxVal = nums[n-1], maxCnt = 0;
        if (minVal == maxVal) {
            return 0;
        }
        for (int i = 0; minVal == nums[i]; ++i) {
            minCnt++;
        }
        for (int i = n-1; maxVal == nums[i]; --i) {
            maxCnt++;
        }
        return n - minCnt - maxCnt;
    }
}

// 0ms 100.00% 37.4MB 90.92%
// brute force
// O(N) O(1)
class Solution {
        public int countElements(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return 0;
        }
        int minVal = 100_000, maxVal = -100_000;
        for (int num : nums) {
            minVal = Math.min(minVal, num);
            maxVal = Math.max(maxVal, num);
        }
        if (minVal == maxVal) {
            return 0;
        }
        int ans = n;
        for (int num : nums) {
            if (num == minVal || num == maxVal) {
                ans--;
            }
        }
        return ans;
    }
}
