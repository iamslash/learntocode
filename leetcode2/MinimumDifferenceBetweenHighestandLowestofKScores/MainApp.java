// Copyright (C) 2021 by iamslash

import java.util.*;


// i
// 9 4 1 7

// sort, sliding window
// O(NlgN) O(1)
class Solution {
    public int minimumDifference(int[] nums, int k) {
        int minDiff = 100000, n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i <= n-k; ++i) {
            minDiff = Math.min(minDiff, nums[i+k-1] - nums[i]);
        }
        return minDiff;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
