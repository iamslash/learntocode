// Copyright (C) 2021 by iamslash

// Time Limit Exceeded
class Solution {
	private final int MOD = 1000000007;
	public int[] solve(int[] nums, int[][] queries) {		
		int[] ans = new int[queries.length];
		int n = nums.length;
		for (int i = 0; i < queries.length; ++i) {
			int u = queries[i][0];
			int v = queries[i][1];
			for (int j = 0; u + j * v < n; ++j) {
				ans[i] = (ans[i] + nums[u + j * v]) % MOD;
			}
		}
		return ans;
	}
}
