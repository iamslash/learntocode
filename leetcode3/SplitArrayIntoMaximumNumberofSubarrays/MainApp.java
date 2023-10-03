// Copyright (C) 2023 by iamslash

import java.util.*;

// 10: 2
// 01: 1
//
// 

//       i
// nums: 1 0 2 0 1 2
//       j

// Idea: greedy
//
// The number of zero AND subarray or 1
//
// 3ms 100.00% 56.3MB 33.40%
// greedy
// O(N) O(1)
class Solution {
    public int maxSubarrays(int[] nums) {
        int prv = -1, ans = 0;
        for (int num : nums) {
            prv &= num;
            if (prv == 0) {
                prv = -1;
                ans++;
            }
        }
        return Math.max(1, ans);
    }
}
