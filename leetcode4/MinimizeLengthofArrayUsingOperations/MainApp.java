// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 1 1 3 4
//  ans: 1
// 
// nums: 1 3 4
//  ans: 1
//
// nums: 2 3 4
//  ans: 1
//
// nums: 2 2 3 4 
//  ans: 1
//
// nums: 2 2 2 3 4
//  ans: 1
//
// nums: 1 1 1 4
//  ans: 2


// Idea: greedy
//
// if a < b, a % b = a. remove a, b and generate a 
// minNum = min(nums)
// if N % minNum > 0,
//   generate N % minNum, which is smaller than every number.
//   can delete every number in nums and N % minNum will be remained.
//   The answer is 1.
// if every number is a multiply of minNum,
//   can't generate a number smaller than minNum.
//   nums[i] > 0, nums[j] > 0
//   The anwser is (count(minNum) + 1) / 2.

// 2ms 97.35% 57MB 95.48%
// greedy
// O(N) O(1)
class Solution {
    public int minimumArrayLength(int[] nums) {
        int minNum = nums[0], cnt = 0;
        for (int num : nums) {
            minNum = Math.min(minNum, num);
        }
        for (int num : nums) {
            if (num % minNum > 0) {
                return 1;
            }
        }
        for (int num : nums) {
            if (num == minNum) {
                cnt++;
            }
        }
        return (cnt + 1) / 2;
    }
}
