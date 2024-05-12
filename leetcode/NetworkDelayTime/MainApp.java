// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: dijkstra
//
// It's a directed graph.

// 9ms 95.53% 40.1MB 16.62%
// dijkstra
// O(ElgV) O(V)
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        ArrayList<int[]>[] adj = new ArrayList[n];
        int[] dists = new int[n];
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        for (int i = 0; i < n; ++i) {
            adj[i] = new ArrayList<int[]>();
            dists[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < times.length; ++i) {
            int u = times[i][0] - 1, v = times[i][1] - 1, c = times[i][2];
            adj[u].add(new int[]{v, c});
        }
        dists[k - 1] = 0;
        pq.offer(new int[]{k - 1, 0});

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int u = top[0], distU = top[1];

            if (dists[u] < distU) {
                continue;
            }
            dists[u] = distU;

            for (int[] next : adj[u]) {
                int v = next[0], costV = next[1];
                int distV = distU + costV;
                if (distV < dists[v]) {
                    dists[v] = distV;
                    pq.offer(new int[]{v, distV});
                }
            }
        }

        int maxDist = 0;
        for (int i = 0; i < n; ++i) {
            maxDist = Math.max(maxDist, dists[i]);
        }
        if (maxDist == Integer.MAX_VALUE) {
            return -1;
        }
        return maxDist;
    }
}
