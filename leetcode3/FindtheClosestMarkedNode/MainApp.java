// Copyright (C) 2023 by iamslash

import java.util.*;

// 8ms 100.00% 44MB 94.87%
// dijkstra
// O(ElgV) O(V)
class Solution {
    public int minimumDistance(int n, List<List<Integer>> edges, int s, int[] marked) {
        ArrayList<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<int[]>();
        }
        // Build graph
        for (List<Integer> edge : edges) {
            int u = edge.get(0), v = edge.get(1), c = edge.get(2);
            graph[u].add(new int[]{v, c});
        }        
        Set<Integer> markSet = new HashSet<>();
        for (int u : marked) {
            markSet.add(u);
        }
        // dijkstra data
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{s, 0});
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;
        // dijkstra loop
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int u = top[0], suCost = top[1];
            if (markSet.contains(u)) {
                return suCost;
            }            
            for (int[] p : graph[u]) {
                int v = p[0], uvCost = p[1];
                if (suCost + uvCost < dist[v]) {
                    dist[v] = suCost + uvCost;
                    pq.add(new int[]{v, dist[v]});
                }
            }
        }        
        return -1;
    }
}

// dijkstra
// O(VlgE) O(V^2)
class Solution {
    public int minimumDistance(int n, List<List<Integer>> edges, int s, int[] marked) {
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(graph[i], -1);
        }
        // Build graph
        for (List<Integer> edge : edges) {
            int u = edge.get(0), v = edge.get(1), c = edge.get(2);
            graph[u][v] = c;
        }
        Set<Integer> markSet = new HashSet<>();
        for (int u : marked) {
            markSet.add(u);
        }
        // dijkstra data
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{s, 0});
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;
        // dijkstra loop
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int u = top[0], suCost = top[1];
            if (markSet.contains(u)) {
                return suCost;
            }
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] < 0) {
                    continue;
                }
                int uvCost = graph[u][v];
                if (suCost + uvCost < dist[v]) {
                    dist[v] = suCost + uvCost;
                    pq.offer(new int[]{v, dist[v]});
                }
            }
        }
        return -1;
    }
}
