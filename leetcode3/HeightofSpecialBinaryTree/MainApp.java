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

// Idea: bfs
//
// when u.left.right is u, u.left is leaf node.
// when u.right.left is u, u.right is leaf node.

// 4ms 53.85% 44.2MB 71.79%
// bfs
// O(N) O(N)
class Solution {
    public int heightOfTree(TreeNode root) {
        int step = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (q.size() > 0) {
            step++;
            int size = q.size();
            while (size-- > 0) {
                TreeNode u = q.poll();
                if (u.left != null && u.left.right != u) {
                    q.offer(u.left);
                }
                if (u.right != null && u.right.left != u) {
                    q.offer(u.right);
                }
            }
        }
        return step - 1;
    }
}
