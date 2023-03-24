// Copyright (C) 2023 by iamslash

import java.util.*;

// 919ms 26.73% 234.4MB 5.22%
// backtracking
// O(2^N) O(N)
class Solution {
    private void dfs(int[] nums, int k,
                     List<List<Integer>> best, List<Integer> cand,
                     int idx) {
        int n = nums.length;
        // base
        if (idx >= n) {
            if (cand.size() > 0) {
                best.add(new ArrayList<>(cand));
            }
            return;
        }
        // recursion
        if (!cand.contains(nums[idx] - k)) {
            cand.add(nums[idx]);
            dfs(nums, k, best, cand, idx + 1);
            cand.remove(cand.size() - 1);
        }
        dfs(nums, k, best, cand, idx + 1);
    }
    public int beautifulSubsets(int[] nums, int k) {
        Arrays.sort(nums);
        List<List<Integer>> best = new ArrayList<>();
        List<Integer> cand = new ArrayList<>();
        dfs(nums, k, best, cand, 0);
        return best.size();
    }
}
