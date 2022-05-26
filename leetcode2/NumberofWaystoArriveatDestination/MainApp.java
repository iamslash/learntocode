// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: dijkstra
//
// dists[i]: the min distance from 0 to i-th node
//  ways[i]: the count of ways from 0 to i-th node
 
// 6ms 97.78% 55.6MB 26.67%
// dijkstra
// O(ElgV) O(lgV)
class Solution {
    public int countPaths(int n, int[][] roads) {
        int MOD = 1_000_000_007;
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(graph[i], -1);
        }
        for (int[] road : roads) {
            int u = road[0], v = road[1], d = road[2];
            graph[u][v] = d;
            graph[v][u] = d;
        }
        int[] dists = new int[n];
        Arrays.fill(dists, Integer.MAX_VALUE);
        int[] ways = new int[n];
        dists[0] = 0;
        ways[0] = 1;
        // [cost, node]
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] item = pq.poll();
            int d = item[0], u = item[1];
            if (d > dists[u]) {
                continue;
            }
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] < 0) {
                    continue;
                }
                int nd = d + graph[u][v];
                if (nd < dists[v]) {
                    dists[v] = nd;
                    ways[v] = ways[u];
                    pq.add(new int[]{nd, v});
                } else if (nd == dists[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
}
