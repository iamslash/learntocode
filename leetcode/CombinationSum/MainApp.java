// Copyright (C) 2024 by iamslash

import java.util.*;

// 3ms 33.90% 44.3MB 75.13%
// backtracking
// O(2^N) O(N)
class Solution {

    private void dfs(int[] nums, List<List<Integer>> ans,
                     List<Integer> cand, int tgt, int beg) {
        // base
        int n = nums.length;
        if (tgt < 0) {
            return;
        }
        if (tgt == 0) {
            ans.add(new ArrayList<>(cand));
        }
        // recursion
        for (int i = beg; i < n; ++i) {
            cand.add(nums[i]);
            dfs(nums, ans, cand, tgt - nums[i], i); 
            cand.remove(cand.size() - 1);
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int tgt) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(candidates, ans, new ArrayList<>(), tgt, 0);
        return ans;
    }
}
