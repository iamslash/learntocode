// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 1
//              i
// nums: 1 2 3  4  5  6
// psum: 1 3 6 10
// mSum: m 3 5  7   
//  map: 1 2 3  4
//       0 1 3  6

// Idea: prefix sum, hash map
//
// Return the maximum sum of a subarray.
// It is not the sum of subarrays.

// 61ms 98.04% 60MB 44.62%
// prefix sum, hash map
// O(N) O(N)
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        // {val : min prefix sum}
        Map<Integer, Long> valMinPrefixSumMap = new HashMap<>();
        long maxSum = Long.MIN_VALUE, prefixSum = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (valMinPrefixSumMap.getOrDefault(nums[i], Long.MAX_VALUE) > prefixSum) {
                valMinPrefixSumMap.put(nums[i], prefixSum);
            }
            prefixSum += nums[i];
            if (valMinPrefixSumMap.containsKey(nums[i] + k)) {
                maxSum = Math.max(maxSum, prefixSum - valMinPrefixSumMap.get(nums[i] + k));
            }
            if (valMinPrefixSumMap.containsKey(nums[i] - k)) {
                maxSum = Math.max(maxSum, prefixSum - valMinPrefixSumMap.get(nums[i] - k));
            }
        }
        return maxSum == Long.MIN_VALUE ? 0 : maxSum;
    }
}
