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

// Idea: DFS
//
// 0. Build graph
// 1. Get max distance with dfs from start to leaf

// 220ms 58.18% 228.4MB 16.18%
// DFS
// O(N) O(lgN)
class Solution {
    private int dfs(Map<Integer, List<Integer>> graph, Set<Integer> visit, int u,
                    int maxDist, int curDist) {
        // base
        if (visit.contains(u)) {
            return maxDist;
        }
        // recursion
        visit.add(u);
        maxDist = Math.max(maxDist, curDist);
        for (int v : graph.get(u)) {
            maxDist = Math.max(maxDist, dfs(graph, visit, v, maxDist, curDist + 1));
        }
        return maxDist;
    }
    private void buildGraph(Map<Integer, List<Integer>> graph, TreeNode root) {
        List<Integer> adj = graph.computeIfAbsent(root.val, a -> new ArrayList<>());
        if (root.left != null) {
            graph.computeIfAbsent(root.left.val, a -> new ArrayList<>()).add(root.val);
            adj.add(root.left.val);
            buildGraph(graph, root.left);
        }
        if (root.right != null) {
            graph.computeIfAbsent(root.right.val, a -> new ArrayList<>()).add(root.val);
            adj.add(root.right.val);
            buildGraph(graph, root.right);
        }
    }
    public int amountOfTime(TreeNode root, int start) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        buildGraph(graph, root);
        return dfs(graph, new HashSet<>(), start, 0, 0);
    }
}
