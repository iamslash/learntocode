// Copyright (C) 2020 by iamslash

import java.util.*;

public class TreeNode {
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

// 0ms 100.00% 39.4MB 8.97%
// DFS
// O(N) O(lgN)
class Solution {
	private List<TreeNode> dfs(int fr, int to) {
		List<TreeNode> ans = new ArrayList<>();
		if (fr == to) {
			ans.add(new TreeNode(fr));
		} else if (fr > to) {
			ans.add(null);
		} else {
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
		}
		return ans;
	}
	public List<TreeNode> generateTrees(int n) {
		if (n == 0)
			return new ArrayList<>();
		return dfs(1, n);
	}
}
