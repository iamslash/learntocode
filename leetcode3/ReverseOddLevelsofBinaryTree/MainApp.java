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

//         0
//     1       2
//  0    0   0    0
// 1 1  1 1 2 2  2 2
//
//         0
//     2       1
//  0    0   0    0
// 2 2  2 2 1 1  1 1

// 2ms 90.35% 71.9MB 73.91%
// DFS
// O(N) O(lgN)
class Solution {
    private void dfs(TreeNode l, TreeNode r, int lv) {
        // base
        if (l == null || r == null) {
            return;
        }
        // recursion
        if (lv % 2 == 1) {
            int t = l.val;
            l.val = r.val;
            r.val = t;
        }
        dfs(l.left, r.right, lv + 1);
        dfs(l.right, r.left, lv + 1);
    }
    public TreeNode reverseOddLevels(TreeNode root) {
        dfs(root.left, root.right, 1);
        return root;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
