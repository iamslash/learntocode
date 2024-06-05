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

// 7ms 100.00% 69.4MB 34.02%
// BFS
// O(N) O(lgN)
class Solution {
    public int minimumLevel(TreeNode root) {
        long minSum = Integer.MAX_VALUE;
        int minLv = 0, curLv = 0;
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int n = q.size();
            long curSum = 0;
            curLv++;

            while (n-- > 0) {
                TreeNode top = q.poll();
                curSum += top.val;
                if (top.left != null) {
                    q.offer(top.left);
                }
                if (top.right != null) {
                    q.offer(top.right);
                }
            }

            if (curSum < minSum) {
                minLv = curLv;
                minSum = curSum;
            }
        }

        return minLv;
    }
}
