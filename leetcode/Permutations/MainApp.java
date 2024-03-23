// Copyright (C) 2024 by iamslash

import java.util.*;


// 2ms 49.35% 44.2MB 77.87%
// dfs
// O(N!) O(N!)
class Solution {
    private void dfs(int[] nums, List<List<Integer>> ans, List<Integer> numList) {
        // base
        int n = nums.length;
        if (numList.size() == n) {
            ans.add(new ArrayList<>(numList));
        }
        
        // recursion
        for (int num : nums) {
            if (numList.contains(num)) {
                continue;
            }
            numList.add(num);
            dfs(nums, ans, numList);
            numList.remove(numList.size() - 1);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> numList = new ArrayList<>();
        dfs(nums, ans, numList);
        return ans;
    }
}

// Idea: back tracking
//
// nums: 1 2 3
//
// dfs[1,2,3], 0)
//   dfs[1,2,3], 1)
//     dfs[1,2,3], 2)
//     dfs[1,3,2], 2)
//   dfs[2,1,3], 1)
//     dfs[2,1,3], 2)
//     dfs[2,3,1], 2)
//   dfs[3,1,2], 1)
//     dfs[3,1,2], 2)
//     dfs[3,2,1], 2)

// 1ms 95.58% 44.5MB 45.96%
// back tracking
// O(N!) O(N!)
class Solution {
    private void dfs(int[] nums, List<List<Integer>> ans, int pos) {
        // base
        int n = nums.length;
        if (pos == n) {
            List<Integer> candList = new ArrayList<>();
            for (int num : nums) {
                candList.add(num);
            }
            ans.add(candList);
            return;
        }

        // recursion
        for (int i = pos; i < n; ++i) {
            // swap
            int tmp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = tmp;

            dfs(nums, ans, pos + 1);

            // swap
            tmp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = tmp;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(nums, ans, 0);
        return ans;
    }
}
