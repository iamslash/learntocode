// Copyright (C) 2022 by iamslash

import java.util.*;

public class TreeNode {
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

// dfs
// O(N) O(lgN)
class Solution {
    private boolean dfs(TreeNode u, int val, StringBuffer pathh) {
        // base
        if (u.val == val) {
            return true;
        }
        if (u.left != null && dfs(u.left, val, path)) {
            sb.append('L');
        } else if (u.right != null && dfs(u.right, val, path)) {
            sb.append('R');
        }
        return sb.length() > 0;
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
