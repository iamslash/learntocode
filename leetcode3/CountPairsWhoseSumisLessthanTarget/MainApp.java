// Copyright (C) 2023 by iamslash

import java.util.*;

// target: 2
//          i
//   nums: -1 1 1 2 3
//
// target: -2
//                   i
//   nums: -7 -6 -2 -1 2 3 5
//                   j

// 4ms 66.67% 41.1MB 100.00%
// two pointers
// O(NlgN) O(1)
class Solution {
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums);
        int ans = 0, lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int a = nums.get(lo), b = nums.get(hi);
            if (a + b >= target) {
                hi--;
            } else {
                ans += hi - lo;
                lo++;
            }
        }
        return ans;
    }
}
