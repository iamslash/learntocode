// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 90.48% 45.7MB 34.59%
// math
// O(N) O(1)
class Solution {
    public int maxProfit(int[] prices) {
        int sum = 0, n = prices.length;
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                sum += diff;
            }
        }
        return sum;
    }
}
