// Copyright (C) 2024 by iamslash

import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

// 27ms 39.28% 42.1MB 97.40%
// hash map, dfs
// O(N) O(N)
class Solution {
    private Node dfs(Map<Node, Node> visitMap, Node src) {
        // base
        if (src == null) {
            return null;
        }
        if (visitMap.containsKey(src)) {
            return visitMap.get(src);
        }
        Node dst = new Node(src.val);
        visitMap.put(src, dst);
        if (src.neighbors == null) {
            return dst;
        }

        // recursion
        for (Node u : src.neighbors) {
            dst.neighbors.add(dfs(visitMap, u));
        }
        return dst;
    }
    
    public Node cloneGraph(Node node) {
        Map<Node, Node> visitMap = new HashMap<>();
        return dfs(visitMap, node);
    }
}
