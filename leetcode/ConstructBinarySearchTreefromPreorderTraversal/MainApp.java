// Copyright (C) 2023 by iamslash

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

//                         i
// preorder: 8 5 1 7 10 12
//
//            8
//          /   \
//         5     10
//        / \      \
//       1   7      12
//      

// Idea: bst
//
// Design recursive functions with bound value.

// 0ms 100.00% 40.9MB 35.27%
// bst
class Solution {
    private int idx = 0;
    private TreeNode dfs(int[] preorder, int bnd) {
        // base
        if (idx >= preorder.length || preorder[idx] > bnd) {
            return null;
        }
        // process
        TreeNode u = new TreeNode(preorder[idx++]);
        // recursion
        u.left = dfs(preorder, u.val);
        u.right = dfs(preorder, bnd);
        return u;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        return dfs(preorder, 1000);
    }
}
// hint-1. Use recursive function.
// hint-2. Use the bound value.
