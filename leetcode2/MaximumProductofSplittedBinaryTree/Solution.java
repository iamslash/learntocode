// Copyright (C) 2020 by iamslash

// 6ms 98.17% 54.1MB 100.00%
// DFS
// O(N) O(lgN)
class Solution {
	private final int MOD = 1000000009;
	private int glbSum = 0;
	private int ans = 0;
	private int dfs(TreeNode u) {
		// base
		if (u == null)
			return 0;		
		int locSum = u.val +
				dfs(u.left) +
				dfs(u.right);
		int prod = locSum * (glbSum - locSum);
		if (prod > ans)
			ans = prod;
		return locSum % MOD;
	}
	public int maxProduct(TreeNode u) {
		glbSum = dfs(u);
		dfs(u);
		return ans;
	}
}
