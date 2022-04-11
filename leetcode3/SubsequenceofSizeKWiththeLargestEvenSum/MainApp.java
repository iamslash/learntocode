// Copyright (C) 2022 by iamslash

import java.util.*;


//    k: 3
// nums: 4 1 5 3 1
//       
//       5 4 3 1 1

// Idea
// 0. Get the sum of k numbers
// 1. If the sum is event, return it
// 2. Otherwise
//   2.0 Replace min odd num of k numbers with max even num of remains
//   2.1 Replace min even num of k numbers with max odd num of remains

// 24ms 82.50% 73.3MB 71.25%
// sort
// O(NlgN) O(1)
class Solution {
    public long largestEvenSum(int[] nums, int k) {
        Arrays.sort(nums);
        int minOdd = -1, minEvn = -1, maxOdd = -1, maxEvn = -1;
        int n = nums.length;
        long sum = 0, ans = -1;
        for (int i = n - 1; i >= n - k; --i) {
            sum += nums[i];
            if (nums[i] % 2 == 0) {
                minEvn = nums[i];
            } else {
                minOdd = nums[i];
            }
        }
        if (sum % 2 == 0) {
            return sum;
        }
        for (int i = 0; i < n - k; ++i) {
            if (nums[i] % 2 == 0) {
                maxEvn = nums[i];
            } else {
                maxOdd = nums[i];
            }
        }
        if (maxOdd != -1 && minEvn != -1) {
            ans = Math.max(ans, sum - minEvn + maxOdd);
        }
        if (minOdd != -1 && maxEvn != -1) {
            ans = Math.max(ans, sum - minOdd + maxEvn);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
