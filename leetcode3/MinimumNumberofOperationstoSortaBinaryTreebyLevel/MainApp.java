// Copyright (C) 2022 by iamslash

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

// 0  1 2 3 4 
// 7 11 3 5 2
// ----------
// 4 2 3 0  1
// 2 3 5 7 11
//
// 

// 114ms 76.46% 96.4MB 83.47%
// BFS
// O(NlgN) O(N^2)
class Solution {
    public int minimumOperations(TreeNode root) {
        int ans = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int n = q.size();
            int[] vals = new int[n];
            Integer[] idxs = new Integer[n];
            for (int i = 0; i < n; ++i) {
                TreeNode u = q.poll();
                idxs[i] = i;
                vals[i] = u.val;
                if (u.left != null) {
                    q.offer(u.left);
                }
                if (u.right != null) {
                    q.offer(u.right);
                }
            }
            Arrays.sort(idxs, (i, j) -> vals[i] - vals[j]);
            for (int i = 0; i < n; ++i) {
                while (idxs[i] != i) {
                    int j = idxs[i];
                    idxs[i] = idxs[j];
                    idxs[j] = j;
                    ans++;
                }
            }
        }
        return ans;
    }
}
