// Copyright (C) 2023 by iamslash

import java.util.*;

// 64ms 73.70% 43.4MB 99.74%
// brute force
// O(N^2) O(N)
class Solution {
    public long minCost(int[] nums, int x) {
        int n = nums.length;
        long[] costs = new long[n];
        for (int i = 0; i < n; ++i) {
            costs[i] = (long)x * i;
        }
        for (int i = 0; i < n; ++i) {
            long minNum = nums[i];
            for (int j = 0; j < n; ++j) {
                minNum = Math.min(minNum, nums[(i + j) % n]);
                costs[j] += minNum;
            }
        }
        long minCost = costs[0];
        for (int i = 1; i < n; ++i) {
            minCost = Math.min(minCost, costs[i]);
        }
        return minCost;
    }
}
