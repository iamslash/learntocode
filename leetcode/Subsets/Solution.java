// Copyright (C) 2021 by iamslash

import java.util.*;

//         
//      n: 000    i
//         001
//         010
//         011
//         100
//         101
//         110
//         111
// subset: 
//   nums: 1 2 3
//         j

// // bit manipulation
// // O(2^N) O(2^N)
// class Solution {
// 	public List<List<Integer>> subsets(int[] nums) {
// 		List<List<Integer>> ans = new ArrayList<>();
// 		int n = 1 << nums.length;
// 		for (int i = 0; i < n; ++i) {
//       List<Integer> subset = new ArrayList<>();
// 			for (int j = 0; j < nums.length; ++j) {
// 				if ((i & (1 << j)) > 0) {
// 					subset.add(new Integer(nums[j]));
// 				}
// 			}
// 			ans.add(subset);
// 		}
// 		return ans;
// 	}
// }

// 0ms 100.00% 39.4MB 51.49%
// back tracking
// O(2^N) O(2^N)
class Solution {
	private void dfs(List<List<Integer>> ans,
									 List<Integer> subset,
									 int[] nums,
									 int i) {
		// base
		if (i >= nums.length) {
			ans.add(new ArrayList<>(subset));
			return;
		}
		// recursion
		subset.add(new Integer(nums[i]));
		dfs(ans, subset, nums, i+1);
		subset.remove(subset.size()-1);
		dfs(ans, subset, nums, i+1);
	}
							 
	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> ans = new ArrayList<>();
		List<Integer> subset = new ArrayList<>();
		dfs(ans, subset, nums, 0);
		return ans;
	}
}
