// Copyright (C) 2021 by iamslash

import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode() {}
	TreeNode(int val) { this.val = val; }
	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

// i
// 1 2 3 4 5

// 0ms 100.00% 39.7MB 58.33%
// dfs
// O(N) O(N)
class Solution {
	private List<TreeNode> dfs(int fr, int to) {
		List<TreeNode> ans = new ArrayList<>();
		// base
		if (fr > to) {
			ans.add(null);
			return ans;
		}
		if (fr == to) {
			ans.add(new TreeNode(fr));
			return ans;
		}
		// recursion
		for (int i = fr; i <= to; ++i) {
			List<TreeNode> l = dfs(fr, i-1);
			List<TreeNode> r = dfs(i+1, to);
			for (int j = 0; j < l.size(); ++j) {
				for (int k = 0; k < r.size(); ++k) {
					TreeNode t = new TreeNode(i);
					t.left = l.get(j);
					t.right = r.get(k);
					ans.add(t);
				}
			}					
		}
		return ans;
	}
	public List<TreeNode> generateTrees(int n) {
		return dfs(1, n);
	}
}
