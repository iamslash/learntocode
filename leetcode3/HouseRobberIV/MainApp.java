// Copyright (C) 2023 by iamslash

import java.util.*;

//    k: 2
// nums: 2 3 5 9

// Idea: binary search
//
// mi: max one house dollar

// 29ms 63.27% 52.1MB 68.93%
// binary search
// O(NlgN) O(1)
class Solution {
    public int minCapability(int[] nums, int k) {
        int lo = 1, hi = (int)1e9, n = nums.length;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int taken = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mi) {
                    taken++;
                    i++; // skip ajacent house
                }
            }
            if (taken < k) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
}
