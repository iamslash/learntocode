// Copyright (C) 2024 by iamslash

import java.util.*;

// 66ms 54.46% 120MB 5.06%
// dijkstra
// O(VlgN) O(V)
class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        ArrayList<int[]>[] graph = new ArrayList[n];
        for (int u = 0; u < n; ++u) {
            graph[u] = new ArrayList<int[]>();
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], c = edge[2];
            graph[u].add(new int[]{v, c});
            graph[v].add(new int[]{u, c});
        }

        int[] minDists = new int[n];
        Arrays.fill(minDists, Integer.MAX_VALUE);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{0, 0});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int u = curr[0], distU = curr[1];
            
            if (distU > minDists[u]) {
                continue; // Corrected the continuation condition
            }
            minDists[u] = distU;

            for (int[] next : graph[u]) {
                int v = next[0], costV = next[1];
                int distV = distU + costV;
                
                if (distV < minDists[v] && distV < disappear[v]) {
                    minDists[v] = distV;
                    pq.offer(new int[]{v, distV});
                }
            }
        }

        for (int u = 0; u < n; ++u) {
            // Ensure the node disappear constraint is checked
            if (minDists[u] > disappear[u] ||
                minDists[u] == Integer.MAX_VALUE) {  
                minDists[u] = -1;
            } 
        }

        return minDists;
    }
}
