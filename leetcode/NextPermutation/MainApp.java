// Copyright (C) 2021 by iamslash

import java.util.*;

//     i
// 1 2 7 3 5
//       j
// 1 2 7 3 5

// 1ms 43.53% 40.9MB 7.54%
// backward
// O(N) O(1)
class Solution {
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    private void reverse(int[] nums, int i, int j) {
        while (i < j) {
            swap(nums, i++, j--);
        }
    }
    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return;            
        }
        int n = nums.length, i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) {
            --i;
        }
        if (i >= 0) {
            int j = n-1;
            while (nums[i] >= nums[j]) {
                --j;
            }
            swap(nums, i, j);
        }
        reverse(nums, i+1, n-1);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
