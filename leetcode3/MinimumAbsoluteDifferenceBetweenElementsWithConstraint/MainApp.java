// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: tree map
//
// TreeSet<Integer> numSet
//  When a is number.
//  hi = numSet.ceiling(a), less value equal greater than a
//  lo = numSet.floor(a)  , most value equal smaller than a
// ans = min(ans, min(abs(a - hi), abs(a - lo)))

// 110ms 71.58% 57MB 56.28%
// tree set
// O(NlgN) O(N)
class Solution {
    public int minAbsoluteDifference(List<Integer> nums, int x) {
        TreeSet<Integer> numSet = new TreeSet<>();
        int n = nums.size(), ans = Integer.MAX_VALUE;
        for (int i = x; i < n; ++i) {
            numSet.add(nums.get(i - x));
            Integer hi = numSet.ceiling(nums.get(i));
            Integer lo = numSet.floor(nums.get(i));
            if (hi != null) {
                ans = Math.min(ans, Math.abs(nums.get(i) - hi));
            }
            if (lo != null) {
                ans = Math.min(ans, Math.abs(nums.get(i) - lo));
            }
        }
        return ans;
    }
}
