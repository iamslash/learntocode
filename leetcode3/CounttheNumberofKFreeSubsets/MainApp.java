// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: backtracking
//
// Same as [2597. The Number of Beautiful Subsets](https://leetcode.com/problems/the-number-of-beautiful-subsets/)

// nums: 4 5 6
//       []
//       4
//       5
//       6
//       4 6

// Time Limit Exceeded
// backtracking
// O(2^N) O(N)
class Solution {
    private void dfs(int[] nums, int k,
                     List<List<Integer>> bestList,
                     List<Integer> candList,
                     int idx) {
        int n = nums.length;
        // base
        if (idx >= n) {
            if (candList.size() > 0) {
                bestList.add(new ArrayList<>(candList));
            }
            return;
        }
        // recursion
        // include
        if (!candList.contains(nums[idx] - k)) {
            candList.add(nums[idx]);
            dfs(nums, k, bestList, candList, idx + 1);
            candList.remove(candList.size() - 1);
        }
        // exclude
        dfs(nums, k, bestList, candList, idx + 1); 
    }
                     
    public long countTheNumOfKFreeSubsets(int[] nums, int k) {
        Arrays.sort(nums);
        List<List<Integer>> bestList = new ArrayList<>();
        List<Integer> candList = new ArrayList<>();
        dfs(nums, k, bestList, candList, 0);
        return bestList.size() + 1;
    }
}

// 6ms 72.46% 43.1MB 18.84%
// dynamic programming
// O(N) O(N)
// difficult
class Solution {
    public long countTheNumOfKFreeSubsets(int[] nums, int k) {
        Arrays.sort(nums);
        Map<Integer, Integer> banCntMap = new HashMap<>();
        int maxCnt = 0;
        for (int num : nums) {
            banCntMap.put(num, banCntMap.getOrDefault(num - k, 0) + 1);
            banCntMap.remove(num - k);
            maxCnt = Math.max(maxCnt, banCntMap.get(num));
        }
        long[] fib = new long[maxCnt + 2];
        fib[0] = fib[1] = 1;
        for (int i = 2; i < maxCnt + 2; ++i) {
            fib[i] = fib[i-2] + fib[i-1];
        }
        long ans = 1;
        for (int val : banCntMap.values()) {
            ans *= fib[val + 1];
        }
        return ans;
    }
}
