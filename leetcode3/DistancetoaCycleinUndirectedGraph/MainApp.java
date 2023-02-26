// Copyright (C) 2023 by iamslash

import java.util.*;

class Solution {
    public int[] distanceToCycle(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        int[] ans = new int[n];
        int[] cnts = new int[n];
        Queue<Integer> q = new LinkedList<>();
        // Build graph
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        // Build cnts, q for leaf nodes
        for (int u = 0; u < n; ++u) {
            cnts[u] = graph[u].size();
            if (cnts[u] == 1) {
                q.offer(u);
            }
        }
        // BFS and add next leaf nodes to q
        while (!q.isEmpty()) {
            int u = q.poll();
            ans[u] = Integer.MAX_VALUE;
            for (int v : graph[u]) {
                if (cnts[v] > 1 && --cnts[v] == 1) {
                    q.offer(v);
                }
            }
        }
        // Add other nodes to q
        for (int u = 0; u < n; ++u) {
            if (cnts[u] > 1) {
                q.offer(u);
            }
        }
        // BFS loop nodes
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : graph[u]) {
                if (ans[v] > ans[u] + 1) {
                    ans[v] = ans[u] + 1;
                    q.offer(v);
                }
            }
        }
        return ans;
    }
}
