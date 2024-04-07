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

// 0ms 100.00% 39.2MB 40.95%
// DFS
// O(N) O(lgN)
class Solution {
    private int maxLen = 0;
    private int dfs(TreeNode u) {
        // base
        if (u == null) {
            return 0;
        }
        // recursion
        int l = dfs(u.left);
        int r = dfs(u.right);
        maxLen = Math.max(maxLen, l + r);
        return Math.max(l, r) + 1;
    }
    public int diameterOfBinaryTree(TreeNode u) {
        dfs(u);
        return maxLen;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
