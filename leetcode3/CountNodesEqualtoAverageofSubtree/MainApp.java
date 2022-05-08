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

// 1ms 100.00% 45MB 25.00%
// DFS
// O(N) O(lgN)
class Solution {
    private int ans = 0;
    // return: [sum, cnt]
    private int[] dfs(TreeNode u) {
        // base
        if (u == null) {
            return new int[]{0, 0};
        }
        // recursion
        int[] lefts = dfs(u.left);
        int[] rights = dfs(u.right);
        int sum = lefts[0] + rights[0] + u.val;
        int cnt = lefts[1] + rights[1] + 1;
        if (sum / cnt == u.val) {
            ans++;
        }
        return new int[]{sum, cnt}; 
    }
    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }
}
