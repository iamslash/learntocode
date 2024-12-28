// Copyright (C) 2024 by iamslash

import java.util.*;

//           i
//  nums: 1  5 8
//   max: 8  8 8
// score:   16 8

//                      i
//  nums: 4 5 2 8 9 1 3 8
//   max:               
// score:


// Idea: backward
//
// nums: 1 5 8
//
// (2 - 0) * 8 = 8 + 8

// 1ms 75.86% 45.06MB 48.28%
// backward 
// O(N) O(1)
class Solution {
    public int maxScore(int[] nums) {
        int score = 0, maxNum = 0, n = nums.length;

        for (int i = n - 1; i > 0; --i) {
            maxNum = Math.max(maxNum, nums[i]);
            score += maxNum;
        }

        return score;
    }
}
