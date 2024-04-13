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

// 0ms 100.00% 41.2MB 23.13%
// dfs
// O(N) O(lgN)
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // base
        if (p == null) {
            if (q == null) {
                return true;
            }
            return false;
        }
        if (q == null) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }

        // recursion
        return isSameTree(p.left, q.left) &&
            isSameTree(p.right, q.right);
    }
}
