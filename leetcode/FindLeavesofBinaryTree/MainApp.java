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

// 0ms 100.00% 40.6MB 90.50%
// dfs
// O(N^2) O(lgN)
class Solution {
    private TreeNode dfs(List<Integer> leafList, TreeNode u) {
        // base
        if (u == null) {
            return null;
        }
        // recursion
        if (u.left == null && u.right == null) {
            leafList.add(u.val);
            return null;
        }
        u.left = dfs(leafList, u.left);
        u.right = dfs(leafList, u.right);
        return u;
    }
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        while (root.left != null || root.right != null) {
            List<Integer> leafList = new ArrayList<>();
            dfs(leafList, root);
            ans.add(leafList);
        }
        ans.add(Arrays.asList(root.val));
        return ans;
    }
}
