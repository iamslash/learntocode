// Copyright (C) 2021 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // brute force
// // O(NQ) O(Q)
// class Solution {
// 	private final int MOD = 1000000007;
// 	public int[] solve(int[] nums, int[][] queries) {		
// 		int[] ans = new int[queries.length];
// 		int n = nums.length;
// 		for (int i = 0; i < queries.length; ++i) {
// 			int u = queries[i][0];
// 			int v = queries[i][1];
// 			for (int j = 0; u + j * v < n; ++j) {
// 				ans[i] = (ans[i] + nums[u + j * v]) % MOD;
// 			}
// 		}
// 		return ans;
// 	}
// }

// What's the meaning of y*1l*y ???
// What's the difference between y*y*1l and y*1l*y ???
// 207ms 79.46% 116MB 75.00%
// dynamic programming
// O(NlgN) O(N)
class Solution {
	private final int MOD = 1000000007;
	public int[] solve(int[] nums, int[][] queries) {
		int n = nums.length, m = queries.length;
		int[] ans = new int[m];
		int sqrtn = (int)Math.sqrt(n) + 1;
		int[][] C = new int[sqrtn][n];
		for (int i = 1; i*i <= n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j < i) {
					C[i][n-j-1] = nums[n-j-1];
				} else {
					C[i][n-j-1] = (C[i][n-j-1+i] + nums[n-j-1]) % MOD;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			int x = queries[i][0];
			int y = queries[i][1];
			// caveats: overflow
			if (1l*y*y <= n) {
				ans[i] = C[y][x];
			} else {
				for (int j = x; j < n; j += y) {
					ans[i] = (ans[i] + nums[j]) % MOD;
				}
			}
		}
		return ans;
	}
};
