// Copyright (C) 2022 by iamslash

import java.util.*;

\public class TreeNode {
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

// 1ms 100.00% 42.2MB 100.00%
class Solution {
    public boolean checkTree(TreeNode root) {
        return root.val == root.left.val + root.right.val;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
