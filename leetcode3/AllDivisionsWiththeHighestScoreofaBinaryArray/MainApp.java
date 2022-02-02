// Copyright (C) 2022 by iamslash

import java.util.*;

//                   i
//       nums: 0 0 1 0
//   rightOne: 1 1 0 0
//   leftZero: 1 2 2 3
//      score: 2 3 2 3

//             i
//       nums: 1 1
//   rightOne: 2
//   leftZero: 0
//      score: 2

// We can optimize after reducing maxIdxList.clear() 
// 31MS 83.55% 121.9MB 80.30%
// brute force
// O(N) O(1)
class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int leftZero = 0, rightOne = 0;
        int n = nums.length, maxScore = 0;
        List<Integer> maxIdxList = new ArrayList<>();
        for (int num : nums) {
            if (num == 1) {
                rightOne++;
            }
        }
        maxScore = rightOne;
        maxIdxList.add(0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                leftZero++;
            } else {
                rightOne--;
            }
            int score = leftZero + rightOne;
            if (maxScore < score) {
                maxScore = score;
                maxIdxList.clear();
            }
            if (maxScore <= score) {
                maxIdxList.add(i+1);
            }
        }
        return maxIdxList;
    }
}
