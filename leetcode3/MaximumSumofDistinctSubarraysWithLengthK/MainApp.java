// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 3
// nums: 1 5 4 2 9 9 9

// 181ms 11.81% 108.4MB 28.40%
// sliding window
// O(N) O(N)
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long maxSum = 0, sum = 0;
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            // System.out.printf("i: %d, sum: %d\n", i, sum);
            freqMap.put(nums[i], freqMap.getOrDefault(nums[i], 0) + 1);
            if (i >= k - 1) {
                // Sum 
                if (freqMap.size() == k) {
                    maxSum = Math.max(maxSum, sum);
                }
                // Remove first one
                int j = i - k + 1;
                sum -= nums[j];
                freqMap.put(nums[j], freqMap.getOrDefault(nums[j], 0) - 1);
                if (freqMap.get(nums[j]) == 0) {
                    freqMap.remove(nums[j]);
                }
            }
        }
        return maxSum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
