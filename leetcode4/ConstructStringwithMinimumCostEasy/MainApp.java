// Copyright (C) 2025 by iamslash

import java.util.*;

// 28ms 33.33% 45.76MB 77.78%
// recursive dynamic programming
// O(n * k) O(n + m + k)
// n: len of memoization cache.
// m: len of costMap (number of unique words in the input).
// k: len of wordLenSet (number of unique word lengths).
class Solution {
    private int dfs(String target,
                    Map<String, Integer> costMap,
                    Set<Integer> wordLenSet,
                    Map<Integer, Integer> cache,
                    int offset) {
        // base
        if (offset == target.length()) {
            return 0;
        }
        
        // memo
        if (cache.containsKey(offset)) {
            return cache.get(offset);
        }
        
        // recursion
        int minCost = Integer.MAX_VALUE;
        for (int len: wordLenSet) {
            if (offset + len > target.length()) {
                continue;
            }
            
            String prefix = target.substring(offset, offset + len);
            if (costMap.containsKey(prefix)) {
                int nextCost = dfs(target, costMap, wordLenSet, cache, offset + len);
                if (nextCost != -1) {
                    minCost = Math.min(minCost, costMap.get(prefix) + nextCost);
                }
            }
        }


        if (minCost == Integer.MAX_VALUE) {
            minCost = -1;
        }
        cache.put(offset, minCost);
        return minCost;
    }
    
    public int minimumCost(String target, String[] words, int[] costs) {
        Map<String, Integer> costMap = new HashMap<>();
        Set<Integer> wordLenSet = new HashSet<>();
        int n = costs.length;

        for (int i = 0; i < n; ++i) {
            if (!costMap.containsKey(words[i])) {
                costMap.put(words[i], costs[i]);
                wordLenSet.add(words[i].length());
            } else {
                costMap.put(words[i], Math.min(costMap.get(words[i]), costs[i]));
            }
        }

        Map<Integer, Integer> cache = new HashMap<>();
        return dfs(target, costMap, wordLenSet, cache, 0);
    }
}
