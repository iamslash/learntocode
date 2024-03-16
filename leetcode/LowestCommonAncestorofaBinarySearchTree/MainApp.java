// Copyright (C) 2024 by iamslash

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

// Idea: LCA in BST
//
//        6
//      /   \
//     2      8
//    /  \   / \
//   0   4  7   9
//       / \
//      3   5
//
// p: 2, q: 8
// 6
// p: 2, q: 4
// 2
// p: 3, q: 5
// 4
//
// find the first node u.val >= p.Val && u.Val <= q.Val

// 5ms 100.00% 44.9MB 66.71%
// bst
// O(lgN) O(lgN)
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode u, TreeNode p, TreeNode q) {
        if (u.val > p.val && u.val > q.val) {
            return lowestCommonAncestor(u.left, p, q);
        }
        if (u.val < p.val && u.val < q.val) {
            return lowestCommonAncestor(u.right, p, q);
        }
        return u;
    }
}
