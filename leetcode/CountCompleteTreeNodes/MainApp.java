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

// 0ms 100.00% 41.2MB 90.51%
// DFS
// O(N) O(lgN)
class Solution {
	public int countNodes(TreeNode root) {
		// base
		if (root == null) {
			return 0;
		}
		// recursion
		return 1 + countNodes(root.left) + countNodes(root.right);
	}
}

// 0ms 100.00% 41.2MB 79.56%
// DFS
class Solution {
	private int height(TreeNode u) {
		// base
		if (u == null) {
			return -1;
		}
		return 1 + height(u.left);
	}
	public int countNodes(TreeNode u) {
		int h = height(u);
		// base
		if (h < 0) {
			return 0;
		}
		// recursion
		if (height(u.right) == h-1) {
			return (1 << h) + countNodes(u.right);
		}
		return (1 << h-1) + countNodes(u.left);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
