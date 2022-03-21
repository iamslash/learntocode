// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 1 4 1
//       1 4 4 5
//       1 4 4 1

// 1ms 100.00% 42.1MB 66.67%
// brute force
// O(N) O(1)
class Solution {
    public int countHillValley(int[] nums) {
        int cnt = 0, n = nums.length;
        for (int i = 1; i < n-1; ++i) {
            if (nums[i-1] == nums[i]) {
                continue;
            }
            int left = nums[i-1], right = nums[i+1];
            int j = i-1, k = i+1;
            while (j >= 0 && nums[j] == nums[i]) {
                j--;
            }
            while (k < n && nums[i] == nums[k]) {
                k++;
            }
            // System.out.printf("i:%d, nums[i]: %d, left: %d, right: %d\n", i, nums[i], left, right);
            if ((j >= 0 && k < n) &&
                ((nums[j] < nums[i] && nums[i] > nums[k]) ||
                 (nums[j] > nums[i] && nums[i] < nums[k]))) {
                cnt++;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
