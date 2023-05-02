// Copyright (C) 2023 by iamslash

import java.util.*;

//             i
// nums: 1 1 2 3 7 10

// Idea: binary search
//
//  target: min max difference of pair
// pairCnt: count of pairs

// 24ms 30.60% 56.7MB 44.20%
// binary search left most equal, sort
// O(NlgN) O(1)
class Solution {
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length, lo = 0, hi = nums[n-1] - nums[0];
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int pairCnt = 0;
            for (int i = 1; i < n && pairCnt < p; ++i) {
                if (nums[i] - nums[i - 1] <= mi) {
                    pairCnt++;
                    i++;
                }
            }
            if (pairCnt < p) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
}
