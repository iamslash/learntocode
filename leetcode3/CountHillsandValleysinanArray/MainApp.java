// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 1 4 1
//       1 4 4 5
//       1 4 4 1

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
            for (int j = i-1; j >= 0 && nums[j] == nums[i]; --j) {
                left = nums[j];
            }
            for (int j = i+1; j < n && nums[j] == nums[i]; ++j) {
                right = nums[j];
            }
            System.out.printf("i:%d, nums[i]: %d, left: %d, right: %d\n", i, nums[i], left, right);
            if ((left != nums[i] && right != nums[i]) &&
                ((left < nums[i] && nums[i] > right) ||
                 (left > nums[i] && nums[i] < right))) {
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
