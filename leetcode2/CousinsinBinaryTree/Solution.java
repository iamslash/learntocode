// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;

// public class TreeNode {
// 	int val;
// 	TreeNode left;
// 	TreeNode right;
// 	TreeNode(int x) { val = x; }
// }

// 0ms 100.00% 37.2MB 7.14%
class Solution {
	private int found=0;
	private Map<Integer, Integer[]> nodes = new HashMap<>();
	private void dfs(TreeNode u, int lv, int p, int x, int y) {
		// base
		if (u == null || found == 2)
			return;
		// recursion
		nodes.put(u.val, new Integer[]{lv, p});
		if (u.val == x || u.val == y)
			found++;
		dfs(u.left, lv+1, x, y);
		dfs(u.right, lv+1, x, y);
	}
	public boolean isCousins(TreeNode u, int x, int y) {
		dfs(u, 1, -1, x, y);
		if (!nodes.containsKey(x) || !nodes.containsKey(y) ||
				nodes.get(x)[0] != nodes.get(y)[0])
			return false;
		return nodes.get(x)[1] != nodes.get(y)[1];
	}
}
