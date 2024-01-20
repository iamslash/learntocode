// Copyright (C) 2024 by iamslash

//           i
// prices: 7 1 5 3 6 4


// 3ms 17.14% 61.8MB 38.25%
// kadane
// O(N) O(1)
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length, locMax = 0, glbMax = 0;
        for (int i = 1; i < n; ++i) {
            locMax = Math.max(0, locMax + prices[i] - prices[i-1]);
            glbMax = Math.max(glbMax, locMax);
        }
        return glbMax;
    }
}
