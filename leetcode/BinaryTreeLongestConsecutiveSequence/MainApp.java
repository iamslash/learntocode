// Copyright (C) 2021 by iamslash

// 1ms 86.22% 40.3MB 43.43%
// dfs
// O(N) O(lgN)
class Solution {
	private int glbMax = 0;
	private int dfs(TreeNode u) {
		// base
		if (u == null) {
			return 0;
		}
		// recursion
		int l = dfs(u.left) + 1;
		int r = dfs(u.right) + 1;
		if (u.left != null && u.val + 1 != u.left.val) {
			l = 1;
		}
		if (u.right !=a null && u.val + 1 != u.right.val) {
			r = 1;
		}
		int locMax = Math.max(l, r);
		glbMax = Math.max(glbMax, locMax);
		return locMax;
	}
	public int longestConsecutive(TreeNode u) {
		dfs(u);
		return glbMax;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
