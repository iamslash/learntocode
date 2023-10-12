// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: math
//
// prices: a b c d
//   idxs: i j k l
// b - a = j - i
// a - i = b - j
// Create a map: {prices[i] - i : sum of prices[i]}
// The answer is max of values from a map.
//
// 37ms 100.00% 55.9MB 100.00% 
// math, hash map
// O(N) O(N)
class Solution {
    public long maxScore(int[] prices) {
        Map<Integer, Long> diffSumMap = new HashMap<>();
        int n = prices.length;
        for (int i = 0; i < n; ++i) {
            int key = prices[i] - i;
            long val = prices[i];
            diffSumMap.put(key, diffSumMap.getOrDefault(key, 0L) + val);
        }
        long maxSum = 0;
        for (long sum : diffSumMap.values()) {
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}
