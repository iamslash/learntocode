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

// Idea: double dfs
//
//            a
//          /   \
//         b     c
//        / \   / \
//       d   f g   h
//
// Build sum of nodes by level.
// When we visit node d, update d with
//   sum of (d,f,g,h) - sum of (d,f).
// We know sibling sum of (d,f) when visitng b.

// double dfs
// O(N) O(lgN)
class Solution {
    private void buildSum(List<Integer> sumList, TreeNode u, int lv) {
        // base
        if (u == null) {
            return;
        }
        
        if (sumList.size() <= lv) {
            sumList.add(0);
        }
        sumList.set(lv, sumList.get(lv) + u.val);

        // recursion
        buildSum(sumList, u.left, lv + 1);
        buildSum(sumList, u.right, lv + 1);
    }
    private void updateNode(List<Integer> sumList, TreeNode u, int sibSum, int lv) {
        // base
        if (u == null) {
            return;
        }

        // update
        u.val = sumList.get(lv) - sibSum;
        sibSum = 0;
        if (u.left != null) {
            sibSum += u.left.val;
        }
        if (u.right != null) {
            sibSum += u.right.val;
        }
        
        // recursion
        updateNode(sumList, u.left, sibSum, lv + 1);
        updateNode(sumList, u.right, sibSum, lv + 1);
    }
    public TreeNode replaceValueInTree(TreeNode root) {
        List<Integer> sumList = new ArrayList<>();
        buildSum(sumList, root, 0);
        updateNode(sumList, root, root.val, 0);
        return root;
    }
}
