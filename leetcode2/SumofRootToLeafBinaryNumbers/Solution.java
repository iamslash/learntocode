// Copyright (C) 2020 by iamslash

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

// 1ms 39.95% 39.4MB 7.41%
// DFS
// O(N) O(lgN)
class Solution {
	public int dfs(TreeNode u, int cum) {
		// base
		if (u == null)
			return 0;
		// recursion
		cum = (cum << 1) + u.val;		
		if (u.left == u.right)
			return cum;
		return dfs(u.left, cum) +
				dfs(u.right, cum);
	}	
	public int sumRootToLeaf(TreeNode u) {
		return dfs(u, 0);
	}
}
