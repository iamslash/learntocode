// Copyright (C) 2023 by iamslash

import java.util.*;

//  tgt: 7
// nums: 1 2 8
//  sum: 11
//

// Idea: greedy, sort
//
// sum is sum of nums.
// If sum < target return -1,
// Else can make target with sum of the subsequence.
// Sort nums.
// Consider these cases for last element num of nums
// 0. sum - num >= target, num is not in the subseq.
// 1. num <= target, sum - num < target and num is in the subseq.
// 2. Otherwise decrease the great num to two of half of num.

// 7ms 12.48% 42.6MB 98.19%
// greedy, sort
// O(NlgN) O(1)
class Solution {
    public int minOperations(List<Integer> nums, int target) {
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum < target) {
            return -1;
        }
        Collections.sort(nums);
        int cnt = 0;
        while (target > 0) {
            int num = nums.remove(nums.size() - 1);
            if (sum - num >= target) {
                sum -= num;
            } else if (num <= target) {
                sum -= num;
                target -= num;
            } else {
                nums.add(num / 2);
                nums.add(num / 2);
                cnt++;
            }
        }
        return cnt;
    }
}
