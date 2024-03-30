// Copyright (C) 2021 by iamslash

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

// 25ms 90.34% 39.1MB 79.18%
// DFS
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
        dst.neighbors = new ArrayList<Node>();
        // recursion
        for (Node nsrc : src.neighbors) {
            dst.neighbors.add(dfs(visitMap, nsrc));
        }
        return dst;
    }
    public Node cloneGraph(Node src) {
        Map<Node, Node> visitMap = new HashMap<>();
        return dfs(visitMap, src);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
