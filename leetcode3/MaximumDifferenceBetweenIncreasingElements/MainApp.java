// Copyright (C) 2021 by iamslash

import java.util.*;

//       i
// nums: 9 4 3 2

//                                       i
//    nums: 87 68 91 86 58 63 43 98 6 40
// maxDiff:   -19 23             55        
//  minNum: 6

// It's similar with Best Time to Buy and Sell Stock.
// Keywords: maxDiff, minNum
// 0ms 100.00% 38.6MB 83.33%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length, maxDiff = -1, minNum = nums[0];
        for (int i = 1; i < n; ++i) {
            maxDiff = Math.max(maxDiff, nums[i] - minNum);
            minNum = Math.min(minNum, nums[i]);
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
