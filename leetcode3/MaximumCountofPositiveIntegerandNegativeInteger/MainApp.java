// Copyright (C) 2023 by iamslash

import java.util.*;

//    n: 9
// nums: -3 -2 -1 0 0 0 1 2 3
//                l
//                      l

// 0ms 100.00% 42.8MB 71.43%
// binary search
// O(lgN) O(1) 
class Solution {
    public int maximumCount(int[] nums) {
        int n = nums.length, lo = 0, hi = n - 1, mi = 0;
        while (lo < hi) {
            mi = (lo + hi) / 2;
            if (nums[mi] < 0) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        // lo is left most equal position nums[lo] >= 0
        int neg = lo;
        while (lo < n && nums[lo] == 0) {
            lo++;
        }
        int pos = n - lo;
        return Math.max(neg, pos);
    }
}
