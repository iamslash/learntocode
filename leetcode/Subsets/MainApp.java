// Copyright (C) 2024 by iamslash

import java.util.*;


//       i
// nums: 1 2 3
//           

// Idea: bit manipulation
//
// bm: 1000
//
//  i: 0000
//  j: 0001
//     0010 
//     0100
//     []
//
//  i: 0001
//  j: 0001
//     0010 
//     0100
//     [1]
//
//  i: 0010
//  j: 0001
//     0010 
//     0100
//     [2]
//
//  i: 0011
//  j: 0001
//     0010  
//     0100
//     [1, 2]
//
//  i: 0100
//  j: 0001
//     0010  
//     0100
//     [3]
//
//  i: 0101
//  j: 0001 
//     0010  
//     0100
//     [1, 3]
//
//  i: 0110
//  j: 0001
//     0010 
//     0100
//     [2, 3]
//
//  i: 0111 
//  j: 0001 
//     0010 
//     0100
//     [1, 2, 3]

// 0ms 100.00% 43Mb 6.89%
// bit manipulation
// O(n * 2 ^ N) O(n * 2 ^ N)
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length, bm = 1 << n;
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < bm; ++i) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) > 0) {
                    subset.add(nums[j]);
                }
            }
            ans.add(subset);
        }

        return ans;
    }
}
 
// Idea: back tracking
//
// dfs([], 0)
//   dfs([1], 1)
//     dfs([1,2], 2)
//       dfs([1,2,3], 3)
//       dfs([1,2], 3)
//     dfs([1], 2)
//       dfs([1,3],3)
//       dfs([1], 3)
//   dfs([], 1)
//     dfs([2], 2)
//       dfs([2,3], 3)
//       dfs([2], 3) 
//     dfs([], 2)
//       dfs([3], 3)
//       dfs([], 3)

// // 0ms 100.00% 42.2MB 96.54%
// // back tracking
// // O(2^N) O(N)
// class Solution {

//     private void dfs(int[] nums,
//                      List<List<Integer>> ans,
//                      List<Integer> subset,
//                      int idx) {
//         // base
//         int n = nums.length;
//         if (idx >= n) {
//             ans.add(new ArrayList<>(subset));
//             return;
//         }

//         // recursion
//         subset.add(nums[idx]);
//         dfs(nums, ans, subset, idx + 1);
//         subset.remove(subset.size() - 1);
//         dfs(nums, ans, subset, idx + 1);
//     }
    
//     public List<List<Integer>> subsets(int[] nums) {
//         List<List<Integer>> ans = new ArrayList<>();
//         List<Integer> subset = new ArrayList<>();
//         dfs(nums, ans, subset, 0);        
//         return ans;
//     }
// }
