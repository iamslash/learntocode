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

// 0ms 100.00% 40.6MB 93.56%
// DFS
// O(N) O(lgN)
class Solution {
    private int dfs(List<List<Integer>> ans, TreeNode u) {
        int lv = 0;
        // base
        if (u == null) {
            return 0;
        }
        if (u.left == null && u.right == null) {
            ans.get(lv).add(u.val);
            return lv + 1;            
        }
        // recursion
        int l = dfs(ans, u.left);
        int r = dfs(ans, u.right);
        int maxLv = Math.max(l, r);
        while (ans.size() - 1 < maxLv) {
            ans.add(new ArrayList<>());
        } 
        ans.get(maxLv).add(u.val);
        return maxLv + 1;
    }
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        dfs(ans, root);
        return ans;
    }
}
