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

// 2ms 97.86% 45.4MB 30.92%
// inorder traversal
// O(N) O(N)
class Solution {
    private TreeNode build(List<Integer> data, int beg, int end) {
        // base
        if (beg > end) {
            return null;
        }
        // recursion
        int mid = (beg + end) / 2;
        TreeNode u = new TreeNode(data.get(mid));
        u.left = build(data, beg, mid - 1);
        u.right = build(data, mid + 1, end);
        return u;
    }
    private void inorder(List<Integer> data, TreeNode u) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        inorder(data, u.left);
        data.add(u.val);
        inorder(data, u.right);
    }
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> data = new ArrayList<>();
        inorder(data, root);
        return build(data, 0, data.size() - 1);
    }
}
