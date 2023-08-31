// Copyright (C) 2023 by iamslash

import java.util.*;

// 161ms 100.00% 64.1MB 100.00%
// binary search, partial sum
// O(NlgN) O(N)
class Solution {
    public long[] maximumCoins(int[] heroes, int[] monsters, int[] coins) {
        int n = heroes.length, m = monsters.length;
        // {power : profits}
        TreeMap<Integer, Long> powerProfitMap = new TreeMap<>();
        for (int i = 0; i < m; ++i) {
            powerProfitMap.put(monsters[i], powerProfitMap.getOrDefault(monsters[i], 0L) + coins[i]);
        }
        // Build partial sum
        Integer key = powerProfitMap.firstKey();
        long sum = 0;
        while (key != null) {
            sum += powerProfitMap.get(key);
            powerProfitMap.put(key, sum);            
            key = powerProfitMap.higherKey(key);
        }
        // Build ans
        long[] ans = new long[n];
        for (int i = 0; i < n; ++i) {
            Integer floorKey = powerProfitMap.floorKey(heroes[i]);
            if (floorKey != null) {
                ans[i] = powerProfitMap.get(floorKey);
            }
        }
        return ans;
    }
}
