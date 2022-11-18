// Copyright (C) 2022 by iamslash

import java.util.*;

// 364ms 11.90% 281.3MB 5.11%
// BFS
// O(N) O(N)
class Node {
    Node parent;
    int amount;
    int profit;
    List<Node> children = new ArrayList<>();

    public Node(int amount) {
        this.amount = amount;
    }
}
class Solution {
    private Node[] buildTree(int[][] edges, int[] amounts) {
        int n = amounts.length;
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.computeIfAbsent(u, _k -> new HashSet<>()).add(v);
            graph.computeIfAbsent(v, _k -> new HashSet<>()).add(u);
        }
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(amounts[i]);
        }
        List<Integer> currNodes = new ArrayList<>();
        currNodes.add(0);
        while (!currNodes.isEmpty()) {
            List<Integer> nextNodes = new ArrayList<>();
            for (int i : currNodes) {
                Node u = nodes[i];
                for (int j : graph.get(i)) {
                    Node v = nodes[j];
                    u.children.add(v);
                    v.parent = u;
                    graph.get(j).remove(i);
                    nextNodes.add(j);
                }
            }
            currNodes = nextNodes;
        }
        return nodes;
    }
    public int mostProfitablePath(int[][] edges, int bob, int[] amounts) {
        Node[] tree = buildTree(edges, amounts);
        List<Node> currNodes = new ArrayList<>();
        Node bobNode = tree[bob];
        int maxCost = Integer.MIN_VALUE;
        currNodes.add(tree[0]);
        while (!currNodes.isEmpty()) {
            List<Node> nextNodes = new ArrayList<>();
            for (Node aliceNode : currNodes) {
                int amount = aliceNode.amount;
                if (aliceNode == bobNode) {
                    amount /= 2;
                }
                aliceNode.profit = amount;
                if (aliceNode.parent != null) {
                    aliceNode.profit += aliceNode.parent.profit;
                }
                if (aliceNode.children.isEmpty()) {
                    maxCost = Math.max(maxCost, aliceNode.profit);
                }
                nextNodes.addAll(aliceNode.children);
            }
            bobNode.amount = 0;
            if (bobNode.parent != null) {
                bobNode = bobNode.parent;
            }
            currNodes = nextNodes;
        }
        return maxCost;
    }
}
