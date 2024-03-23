// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: recursive dynamic programming
//
// All operations have the same score.

// 879ms 13.02% 255.1MB 12.10%
// recursive dynamic programming
// O(N^2 * K) O(N^2)
// K: the number of elements in nums.
// K: the number of unique scores considered. 
class Solution {
    private int dfs(int[] nums, int score, Map<String, Integer> C, int lo, int hi) {
        // base
        if (lo >= hi) {
            return 0;
        }
        
        // memo
        String key = lo + "," + hi;
        if (C.containsKey(key)) {
            return C.get(key);
        }

        // recursion
        int maxOps = 0;        
        if (score == nums[lo] + nums[lo + 1]) {
            maxOps = Math.max(maxOps, 1 + dfs(nums, score, C, lo + 2, hi));
        }

        if (score == nums[lo] + nums[hi]) {
            maxOps = Math.max(maxOps, 1 + dfs(nums, score, C, lo + 1, hi - 1));
        }

        if (score == nums[hi - 1] + nums[hi]) {
            maxOps = Math.max(maxOps, 1 + dfs(nums, score, C, lo, hi - 2));
        }

        C.put(key, maxOps);
        return maxOps;
    }
    
    public int maxOperations(int[] nums) {
        int maxOps = 0, n = nums.length;
        Set<Integer> scoreSet = new HashSet<>(List.of(nums[0] + nums[1],
                                                      nums[0] + nums[n-1],
                                                      nums[n-2] + nums[n-1]));
        for (int score : scoreSet) {
            Map<String, Integer> C = new HashMap<>();
            maxOps = Math.max(maxOps, dfs(nums, score, C, 0, n - 1));
        }

        return maxOps;
    }
}
