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

//    -10
//   /    \
// 9        20
//        /    \
//      15       7
// ans: 42

//       2
//     /
//  -1
// ans: 1

//      1
//    /  \
//  -2    3
// ans: 4


//      -1
//    /  \
//  -2    -3
// ans: -1

//    10
//   /    \
// 9        -20
//        /    \
//      15       7
// ans: 19

// Idea: dfs
//
// The path is a sequence between two nodes.
//
// 1ms 17.92% 43.4MB 99.91%
// dfs
// O(N) O(NlgN)
class Solution {
    private int maxSum = Integer.MIN_VALUE;

    private int dfs(TreeNode u) {
        // base
        if (u == null) {
            return 0;
        }

        // recursion
        int leftMaxSum = Math.max(0, dfs(u.left));
        int rightMaxSum = Math.max(0, dfs(u.right));
        maxSum = Math.max(maxSum, leftMaxSum + rightMaxSum + u.val);
        return Math.max(leftMaxSum, rightMaxSum) + u.val;
    }
    
    public int maxPathSum(TreeNode root) {
        dfs(root);
        return maxSum;
    }
}
