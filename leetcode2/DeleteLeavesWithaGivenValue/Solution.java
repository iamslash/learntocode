// Copyright (C) 2020 by iamslash

// 0ms 100.00% 38.9MB 100.00%
// DFS
// O(N) O(lgN)
class Solution {
    public TreeNode removeLeafNodes(TreeNode u, int target) {
			// base
			if (u == null)
				return null;
      // System.out.println(u.val);
			// recursion
			u.left = removeLeafNodes(u.left, target);
			u.right = removeLeafNodes(u.right, target);
			if (u.val == target && u.left == null && u.right == null)
				return null;
			return u;
    }
}
