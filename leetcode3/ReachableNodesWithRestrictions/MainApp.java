// Copyright (C) 2022 by iamslash

import java.util.*;

// 109ms 42.86% 200.4MB 14.29%
// dfs
// O(N) O(N)
class Solution {
    private int nodeCnt = 0;
    private void dfs(int n, boolean[] visit, List<List<Integer>> graph,
                     Set<Integer> restrictSet, int u) {
        // base, recursion
        visit[u] = true;
        nodeCnt++;
        for (Integer v : graph.get(u)) {
            if (!visit[v] && !restrictSet.contains(v)) {
                dfs(n, visit, graph, restrictSet, v);
            }
        }
    }
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        boolean[] visit = new boolean[n];
        List<List<Integer>> graph = new ArrayList<>();
        for (int u = 0; u < n; ++u) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges.length; ++i) {
            int u = edges[i][0], v = edges[i][1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        Set<Integer> restrictSet = new HashSet<>();
        for (int i = 0; i < restricted.length; ++i) {
            restrictSet.add(restricted[i]);
        }
        dfs(n, visit, graph, restrictSet, 0);        
        return nodeCnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
