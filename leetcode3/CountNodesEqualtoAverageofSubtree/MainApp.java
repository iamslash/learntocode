// Copyright (C) 2023 by iamslash

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

// 1ms 89.99% 42.4MB 32.11%
// dfs
// O(N) O(lgN)
class Solution {
    private int best = 0;
    private int[] dfs(TreeNode u) {
        // base
        if (u == null) {
            return new int[]{0, 0};
        }
        // recursion
        int[] lrst = dfs(u.left);
        int[] rrst = dfs(u.right);
        int sum = lrst[0] + rrst[0] + u.val;
        int cnt = lrst[1] + rrst[1] + 1;
        if ((sum / cnt) == u.val) {
            best++;
        }
        return new int[]{sum, cnt};
    }
    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return best;
    }
}
