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

//          5  
//        /   \
//      8       9
//    /   \   /   \
//   2     1 3     7
//  / \
// 4   6
// 
// queries: 3 2 4 8

// Idea: pre-order
//
// Traverse node a, left child l, right child r
// When we visit left child l,
//   we know max lv of sub-tree including a, r
// Traverse node a, right child r, left child l
// When we visit right child r,
//   we know max lv of sub-tree including a, l
// Therefore, we get max lv when we remove node a
//   from max(max lv of left sub-tree including a and r,
//            max lv of right sub-tree including a and l)

// 16ms 92.21% 74.3MB 60.78%
// pre-order, post-order
// O(N) O(lgN)
class Solution {
    private int[] leftMaxLv = new int[100001];
    private int[] rightMaxLv = new int[100001];
    int maxLv;
    private void dfsLeft(TreeNode u, int height) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        leftMaxLv[u.val] = maxLv;
        maxLv = Math.max(maxLv, height);
        dfsLeft(u.left, height + 1);
        dfsLeft(u.right, height + 1);
    }
    private void dfsRight(TreeNode u, int height) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        rightMaxLv[u.val] = maxLv;
        maxLv = Math.max(maxLv, height);
        dfsRight(u.right, height + 1);
        dfsRight(u.left, height + 1);
    }
    public int[] treeQueries(TreeNode root, int[] queries) {
        int n = queries.length;
        maxLv = 0;
        dfsLeft(root, 0);
        maxLv = 0;
        dfsRight(root, 0);
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = Math.max(leftMaxLv[queries[i]],
                              rightMaxLv[queries[i]]);
        }
        return ans;
    }
}
