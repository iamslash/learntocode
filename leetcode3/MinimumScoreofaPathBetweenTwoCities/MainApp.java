// Copyright (C) 2022 by iamslash

import java.util.*;

// 33ms 80.64% 97.7MB 93.43%
// DFS
// O(N) O(N)
class Solution {
    private int minCost = Integer.MAX_VALUE;
    private void dfs(List<int[]>[] graph, boolean[] visit, int u) {
        visit[u] = true;
        for (int[] neighbor : graph[u]) {
            int v = neighbor[0], c = neighbor[1];
            minCost = Math.min(minCost, c);
            if (!visit[v]) {
                dfs(graph, visit, v);
            }
        }
    }
    public int minScore(int n, int[][] roads) {
        List<int[]>[] graph = new ArrayList[n + 1];        
        boolean[] visit = new boolean[n + 1];
        for (int i = 0; i <= n; ++i) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < roads.length; ++i) {
            int u = roads[i][0], v = roads[i][1], c = roads[i][2];
            graph[u].add(new int[]{v, c});
            graph[v].add(new int[]{u, c});
        }
        dfs(graph, visit, 1);
        return minCost;
    }    
}

// 30ms 83.00% 98.4MB 90.82%
// DFS
// O(N) O(N)
class Solution {
    private int dfs(List<int[]>[] graph, boolean[] visit, int u) {
        visit[u] = true;
        int minCost = Integer.MAX_VALUE;
        for (int[] neighbor : graph[u]) {
            int v = neighbor[0], c = neighbor[1];
            minCost = Math.min(minCost, c);
            if (!visit[v]) {
                minCost = Math.min(minCost, dfs(graph, visit, v));
            }
        }
        return minCost;
    }
    public int minScore(int n, int[][] roads) {
        List<int[]>[] graph = new ArrayList[n + 1];        
        boolean[] visit = new boolean[n + 1];
        for (int i = 0; i <= n; ++i) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < roads.length; ++i) {
            int u = roads[i][0], v = roads[i][1], c = roads[i][2];
            graph[u].add(new int[]{v, c});
            graph[v].add(new int[]{u, c});
        }
        return dfs(graph, visit, 1);
    }    
}
