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


// 0ms 100.00% 44.9MB 9.65%
// dfs
// O(N) O(lgN)
class Solution {
    private int maxLen = 0;
    public int dfs(TreeNode root) {
        // base
        if (root == null) {
            return 0;
        }
        // recursion
        int maxLeftLen = dfs(root.left);
        int maxRightLen = dfs(root.right);
        maxLen = Math.max(maxLen, maxLeftLen + maxRightLen);
        return Math.max(maxLeftLen, maxRightLen) + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return maxLen;
    }
}
