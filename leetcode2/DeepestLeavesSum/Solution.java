// Copyright (C) 2020 by iamslash

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

// 0ms 100.00% 41.8MB 100.00%
// DFS
// O(N) O(N)
class Solution {
	private int sum = 0;
	private int maxDepth = 0;
	private void dfs(TreeNode u, int depth) {
		// base
		if (u == null)
			return;
		if (u.left == null && u.right == null) {
			if (depth > maxDepth) {
				sum = u.val;
				maxDepth = depth;
			} else if (depth == maxDepth) {
				sum += u.val;
			}
		}
		// recursion
		dfs(u.left, depth+1);
		dfs(u.right, depth+1);
	}
	public int deepestLeavesSum(TreeNode u) {
		dfs(u, 1);
		return sum;
	}
}
