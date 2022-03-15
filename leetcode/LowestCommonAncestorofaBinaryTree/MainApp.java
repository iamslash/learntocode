// Copyright (C) 2022 by iamslash

import java.util.*;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

//        3
//     /     \
//    5       1
//  /   \    / \
// 6     2  0   8
//      / \
//     7   4

// 8ms 72.29% 47.1MB 51.09%
// lca
// O(N) O(lgN)
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode u, TreeNode p, TreeNode q) {
        // base
        if (u == null || u == p || u == q) {
            return u;
        }
        // recursion
        TreeNode l = lowestCommonAncestor(u.left, p, q);
        TreeNode r = lowestCommonAncestor(u.right, p, q);
        if (l != null && r != null) {
            return u;
        }
        if (l != null) {
            return l;
        }
        return r;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
