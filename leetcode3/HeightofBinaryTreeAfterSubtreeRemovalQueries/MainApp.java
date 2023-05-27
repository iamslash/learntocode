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

// 16ms 92.21% 74.3MB 60.78%
// pre-order, post-order
// O(N) O(lgN)
class Solution {
    private int[] preHeights = new int[100001];
    private int[] postHeights = new int[100001];
    int maxHeight;
    private void preOrder(TreeNode u, int height) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        preHeights[u.val] = maxHeight;
        maxHeight = Math.max(maxHeight, height);
        preOrder(u.left, height + 1);
        preOrder(u.right, height + 1);
    }
    private void postOrder(TreeNode u, int height) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        postHeights[u.val] = maxHeight;
        maxHeight = Math.max(maxHeight, height);
        postOrder(u.right, height + 1);
        postOrder(u.left, height + 1);
    }
    public int[] treeQueries(TreeNode root, int[] queries) {
        int n = queries.length;
        maxHeight = 0;
        preOrder(root, 0);
        maxHeight = 0;
        postOrder(root, 0);
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = Math.max(preHeights[queries[i]], postHeights[queries[i]]);
        }
        return ans;
    }
}
