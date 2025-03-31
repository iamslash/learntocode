// Copyright (C) 2025 by iamslash

import java.util.*;

// cost: 5 3 4 1 3 2
//       3 5

// 1ms 97.59% 45.05MB 46.12%
// brute force
// O(N) O(1)
class Solution {
    public int[] minCosts(int[] cost) {
        int n = cost.length, minCost = cost[0];
        int[] ans = new int[n];

        for (int i = 0; i < n; ++i) {
            minCost = Math.min(minCost, cost[i]);
            ans[i] = minCost;
        }

        return ans;        
    }
}
