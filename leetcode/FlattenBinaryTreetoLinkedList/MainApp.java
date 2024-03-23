// Copyright (C) 2024 by iamslash

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

// 0ms 100.00% 42.1MB 37.65%
// pre-order
// O(N) O(N)
class Solution {
    private TreeNode dfs(TreeNode u) {
        // base
        if (u.left == null && u.right == null) {
            return u;
        }
        if (u.left != null) {
            TreeNode t = u.right;
            u.right = u.left;
            u.left = t;
        }

        // recursion
        TreeNode leftLeaf = dfs(u.right);
        if (u.left != null && leftLeaf != null) {
            TreeNode rightLeaf = dfs(u.left);
            leftLeaf.right = u.left;
            u.left = null;
            leftLeaf = rightLeaf;
        }

        return leftLeaf;
    }
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root);
    }
}
