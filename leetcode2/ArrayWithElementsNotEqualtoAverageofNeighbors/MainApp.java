// Copyright (C) 2021 by iamslash

import java.util.*;


// 
// nums: 6 2 0 9 7
//         i
//       0 2 6 7 9
//         .   .
//       2 1 4 3 5
//       
// 

// 40ms 78.95% 59.1MB 75.34%
// sort, swap
// O(NlgN) O(1)
class Solution {
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        for (int i = 1; i < n; i += 2) {
            swap(nums, i-1, i);
        }
        return nums;
    }
}

//              i
// nums: 10 5 7 3 4
// 

// 4ms 96.89% 63.7MB 44.65%
// brute force
// O(N) O(1)
class Solution {
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        for (int i = 1; i < n-1; ++i) {
            if ((nums[i-1] < nums[i] && nums[i] < nums[i+1]) ||
                (nums[i-1] > nums[i] && nums[i] > nums[i+1])) {
                swap(nums, i, i+1);
            }
        }
        return nums;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
