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

// 4ms 40.00% 41.8MB 349.24%
// DFS
// O(N) O(N)
class Solution {
	private List<Integer> pathP = new ArrayList<>();
	private List<Integer> pathQ = new ArrayList<>();
	private boolean dfs(List<Integer> pathList, TreeNode u, int v) {
		// base
		if (u == null) {
			return false;
		}
		// recursion
		pathList.add(u.val);
		if (u.val == v || dfs(pathList, u.left, v) ||
				dfs(pathList, u.right, v)) {
			return true;
		}
		pathList.remove(pathList.size()-1);
		return false;
	}
	public int findDistance(TreeNode root, int p, int q) {
		dfs(pathP, root, p);
		dfs(pathQ, root, q);
    // System.out.println(pathP);
    // System.out.println(pathP.size());
    // System.out.println(pathQ);
    // System.out.println(pathQ.size());
    
		for (int i = 0; i < Math.min(pathP.size(), pathQ.size()); ++i) {
			if (pathP.get(i).equals(pathQ.get(i)) == false) {
				return pathP.size() + pathQ.size() - i * 2;
			}
		}
		return Math.abs(pathP.size() - pathQ.size());
	}
}
