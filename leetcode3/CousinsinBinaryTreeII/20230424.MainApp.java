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

// 37ms 63.70% 81.9MB 38.91%
// DFS
// O(N) O(lgN)
class Solution {
    private List<Integer> sumList = new ArrayList<>();
    private void levelSum(TreeNode u, int lv) {
        // base
        if (u == null) {
            return;
        }
        if (sumList.size() <= lv) {
            sumList.add(0);
        }
        sumList.set(lv, sumList.get(lv) + u.val);
        // recursion
        levelSum(u.left, lv + 1);
        levelSum(u.right, lv + 1);
    }
    private void updateSum(TreeNode u, int sibSum, int lv) {
        // base
        if (u == null) {
            return;
        }
        u.val = sumList.get(lv) - sibSum;
        sibSum = 0;
        if (u.left != null) {
            sibSum += u.left.val;
        }
        if (u.right != null) {
            sibSum += u.right.val;
        }
        // recursion
        updateSum(u.left, sibSum, lv + 1);
        updateSum(u.right, sibSum, lv + 1);
    }
    public TreeNode replaceValueInTree(TreeNode root) {
        levelSum(root, 0);
        updateSum(root, root.val, 0);
        return root;
    }
}
