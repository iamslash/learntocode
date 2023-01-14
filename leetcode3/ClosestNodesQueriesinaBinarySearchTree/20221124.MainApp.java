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

// Time Limit Exceeded
// BST, DFS
// O(NlgN) O(lgN)
class Solution {
    private int ceiling(TreeNode u, int val) {
        // base
        if (u == null) {
            return -1;
        }
        if (u.val == val) {
            return val;
        }
        if (val < u.val) {
            int leftCeiling = ceiling(u.left, val);
            if (leftCeiling == -1) {
                return u.val;
            }
            return leftCeiling;
        }
        return ceiling(u.right, val);
    }
    private int floor(TreeNode u, int val) {
        // base
        if (u == null) {
            return -1;
        }
        if (u.val == val) {
            return val;
        }
        // recursion
        if (val > u.val) {
            int rightFloor = floor(u.right, val);
            if (rightFloor == -1) {
                return u.val;
            }
            return rightFloor;
        }
        return floor(u.left, val);
    }
    public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
        List<List<Integer>> ans = new ArrayList<>();
        for (Integer query : queries) {
            ans.add(Arrays.asList(floor(root, query), ceiling(root, query)));
        }
        return ans;
    }
}

// 179ms 68.81% 96MB 85.79%
// BST
// O(NlgN) O(N)
class Solution {
    private void dfs(TreeSet<Integer> numSet, TreeNode u) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        dfs(numSet, u.left);
        numSet.add(u.val);
        dfs(numSet, u.right);
    }
    public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
        List<List<Integer>> ans = new ArrayList<>();
        TreeSet<Integer> numSet = new TreeSet<>();
        dfs(numSet, root);        
        for (int query : queries) {
            Integer minLargest = numSet.lower(query + 1);
            Integer maxSmallest = numSet.higher(query - 1);
            if (minLargest == null) {
                minLargest = -1;
            }
            if (maxSmallest == null) {
                maxSmallest = -1;
            }
            ans.add(List.of(minLargest, maxSmallest));
        }
        return ans;
    }
}
