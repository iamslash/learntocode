// Copyright (C) 2020 by iamslash

// 1ms 98.43% 48.1MB 100.00%
// DFS
// O(N) O(lgN)
class Solution {
    private int sum = 0;
	private void dfs(TreeNode u, TreeNode p, TreeNode g) {
		// base
		if (u == null)
			return;
		// recursion
		int r = 0;
		if (g != null && (g.val & 1) == 0)
			sum += u.val;
		dfs(u.left, u, p);
        dfs(u.right, u, p);
	}
	public int sumEvenGrandparent(TreeNode u) {
		dfs(u, null, null);
        return sum;
	}
}
