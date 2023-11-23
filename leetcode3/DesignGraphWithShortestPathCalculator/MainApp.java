// Copyright (C) 2023 by iamslash

import java.util.*;

// 83ms 79.89% 54.7MB 43.14%
// dijkstra
// O(ElgV) O(V)
class Graph {
    private List<int[]>[] adj;
    public Graph(int n, int[][] edges) {
        adj = new ArrayList[n];
        for (int u = 0; u < n; ++u) {
            adj[u] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            addEdge(edge);
        }
    }
    
    public void addEdge(int[] edge) {
        int u = edge[0], v = edge[1], c = edge[2];
        adj[u].add(new int[]{v, c});        
    }
    
    public int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

    private int dijkstra(int src, int dst) {
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{src, 0});
        int n = adj.length;
        int[] dists = new int[n];
        Arrays.fill(dists, Integer.MAX_VALUE);
        while (!pq.isEmpty()) {
            int[] item = pq.poll();
            int u = item[0], distU = item[1];
            if (dists[u] < distU) {
                continue;
            }
            if (u == dst) {
                return distU;
            }
            for (int[] next : adj[u]) {
                int v = next[0], costV = next[1];
                int distV = distU + costV;
                if (distV < dists[v]) {
                    dists[v] = distV;
                    pq.offer(new int[]{v, distV});
                }
            }
        }
        if (dists[dst] == Integer.MAX_VALUE) {
            return -1;
        }
        return dists[dst];
    }
}
