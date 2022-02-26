// Copyright (C) 2022 by iamslash

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

// 3ms 97.34% 47MB 12.21%
// dfs
// O(N^2) O(lgN)
class Solution {
    // u is same with v?
    private boolean dfs(TreeNode u, TreeNode v) {
        // base
        if (u == null) {
            return v == null;
        }
        if (v == null) {
            return false;
        }
        // recursion
        return u.val == v.val && dfs(u.left, v.left) && dfs(u.right, v.right);
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // base
        if (root == null) {
            return subRoot == null;
        }
        // recursion
        return dfs(root, subRoot) ||
            isSubtree(root.left, subRoot) ||
            isSubtree(root.right, subRoot);
    }
}
