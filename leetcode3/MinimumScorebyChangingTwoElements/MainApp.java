// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 1 4 7 8 5
//       1 4 5 7 8
//       . .
//             . .
//       .       .

// Idea : greedy
//
// The ans is the sum of high, low scores.
// We should minimize the scores.
// What if we have nums [1, 4, 7, 8, 5]
// Sort it.
// We can think about possible cases like these.
// We can change dotted numbers as same numbers to make low is 0.
// 1 4 5 7 8
// . .         low: 0, high: nums[n-1] - nums[2] 
//       . .   low: 0, high: nums[n-3] - nums[0]
// .       .   low: 0, high: nums[n-2] - nums[1]
// The ans is the minimum.

// 17ms 66.80% 55.3MB 94.02%
// greedy
// O(NlgN) O(1)
class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return Math.min(nums[n-1] - nums[2],
                        Math.min(nums[n-3] - nums[0], nums[n-2] - nums[1]));
    }
}
