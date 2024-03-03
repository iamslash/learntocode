// Copyright (C) 2021 by iamslash

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

//    -10
//   /    \
// 9        20
//        /    \
//      15       7

//       2
//     /
//  -1

//      1
//    /  \
//  -2    3

// 0ms 100.00% 40.9MB 61.32%
// DFS
// O(N) O(lgN)
class Solution {
    private int maxSum = 0;
    private int dfs(TreeNode u) {
        // base
        if (u == null) {
            return 0;
        }
        // recursion
        int l = Math.max(0, dfs(u.left));
        int r = Math.max(0, dfs(u.right));
        maxSum = Math.max(maxSum, l + r + u.val);
        return Math.max(l, r) + u.val;
    }
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        dfs(root);
        return maxSum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
