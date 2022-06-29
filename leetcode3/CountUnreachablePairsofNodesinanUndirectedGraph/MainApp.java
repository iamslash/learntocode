// Copyright (C) 2022 by iamslash

import java.util.*;

// Memory Limit Exceeded
// dfs
// O(N) O(N)
class Solution {
    private long cnt = 0;
    public long countPairs(int n, int[][] edges) {
        boolean[][] graph = new boolean[n][n];
        boolean[] visit = new boolean[n];
        long ans = 0, total = n;
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u][v] = true;
            graph[v][u] = true;
        }
        for (int u = 0; u < n; ++u) {
            if (!visit[u]) {
                cnt = 0;
                dfs(n, graph, visit, u);
                total -= cnt;
                // System.out.printf("u: %d, cnt: %d, total: %d\n", u, cnt, total);
                ans += cnt * total;
            }
        }
        return ans;
    }
    private void dfs(int n, boolean[][] graph, boolean[] visit, int u) {
        // base
        if (visit[u]) {
            return;
        }
        visit[u] = true;
        cnt++;
        // recursion
        for (int v = 0; v < n; ++v) {
            if (graph[u][v]) {
                dfs(n, graph, visit, v);
            }
        }
    }
}

// 67ms 72.20% 118.2MB 94.25%
// dfs
// O(N) O(N)
class Solution {
    private long cnt = 0;
    public long countPairs(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        boolean[] visit = new boolean[n];
        long ans = 0, total = n;
        for (int u = 0; u < n; ++u) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        for (int u = 0; u < n; ++u) {
            if (!visit[u]) {
                cnt = 0;
                dfs(n, graph, visit, u);
                total -= cnt;
                // System.out.printf("u: %d, cnt: %d, total: %d\n", u, cnt, total);
                ans += cnt * total;
            }
        }
        return ans;
    }
    private void dfs(int n, List<List<Integer>> graph, boolean[] visit, int u) {
        // base
        if (visit[u]) {
            return;
        }
        visit[u] = true;
        cnt++;
        // recursion
        for (int v : graph.get(u)) {
            dfs(n, graph, visit, v);
        }
    }
}
