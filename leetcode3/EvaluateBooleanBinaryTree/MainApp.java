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

// 0ms 100.00% 41.8MB 100.00%
// DFS
// O(N) O(lgN)
class Solution {
    public boolean evaluateTree(TreeNode u) {
        // base
        if (u.val == 0) {
            return false;
        }
        if (u.val == 1) {
            return true;
        }
        // recursion
        if (u.val == 2) {
            return evaluateTree(u.left) || evaluateTree(u.right);
        }
        return evaluateTree(u.left) && evaluateTree(u.right);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
