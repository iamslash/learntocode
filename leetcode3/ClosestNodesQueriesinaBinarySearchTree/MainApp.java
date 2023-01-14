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

// 176ms 68.87% 86.9MB 94.03%
// BST
// O(NlgN) O(N)
class Solution {
    private void dfs(TreeSet<Integer> numSet, TreeNode u) {
        if (u == null) {
            return;
        }
        dfs(numSet, u.left);
        numSet.add(u.val);
        dfs(numSet, u.right);
    }
    public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
        List<List<Integer>> ans = new ArrayList<>();
        TreeSet<Integer> numSet = new TreeSet<>();
        dfs(numSet, root);
        for (int query : queries) {
            Integer floor = numSet.floor(query);
            Integer ceiling = numSet.ceiling(query);
            if (floor == null) {
                floor = -1;
            }
            if (ceiling == null) {
                ceiling = -1;
            }
            ans.add(List.of(floor, ceiling));
        }
        return ans;
    }
}
