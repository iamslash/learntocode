// Copyright (C) 2023 by iamslash

import java.util.*;

//                i
//  prices:  10 2 3  4
// profits: 100 2 7 10

// 71ms 100.00% 43.8MB 100.00%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];
        // Build leftMax, rightMax
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (prices[j] < prices[i]) {
                    leftMax[i] = Math.max(leftMax[i], profits[j]);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (prices[i] < prices[j]) {
                    rightMax[i] = Math.max(rightMax[i], profits[j]);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (leftMax[i] != 0 && rightMax[i] != 0) {
                ans = Math.max(ans, leftMax[i] + profits[i] + rightMax[i]);
            }
        }
        return ans;
    }
}
