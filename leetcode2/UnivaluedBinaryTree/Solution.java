// Copyright (C) 2020 by iamslash

// public class TreeNode {
// 	int val;
// 	TreeNode left;
// 	TreeNode right;
// 	TreeNode(int x) { val = x; }
// }

// DFS
// O(N) O(lgN)
class Solution {
	private boolean dfs(TreeNode u, int val) {
		// base
		if (u == null)
			return true;
		if (u.val != val)
			return false;
		// recursion
		return dfs(u.left, val) && dfs(u.right, val);
	}
	public boolean isUnivalTree(TreeNode u) {
		return dfs(u, u.val);
	}
}
