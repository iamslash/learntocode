// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 39.5MB 68.38%
// DFS
// O(N) O(N)
class Solution {
    private boolean dfs(int[][] G, int[] C, int u, int color) {
        // base
        C[u] = color;
        // recursion
        for (int v : G[u]) {
            if (C[v] == color) {
                return false;
            }
            if (C[v] == 0 && !dfs(G, C, v, -color)) {
                return false;
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] C = new int[n];
        for (int u = 0; u < n; ++u) {
            if (C[u] == 0 && !dfs(graph, C, u, 1)) {
                return false;
            }
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
