// Copyright (C) 2023 by iamslash

import java.util.*;

// topological sort
// O(N) O(N)
class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        int[] costs = new int[n];
        int[] inDegs = new int[n];
        List<Integer>[] graph = new ArrayList[n];
        Arrays.fill(graph, new ArrayList<>());

        // Build graph, inDegs
        for (int[] edge : relations) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].add(v);
            inDegs[v]++;
        }

        // topological sort
        Queue<Integer> q = new LinkedList<>();
        for (int u = 0; u < n; ++u) {
            if (inDegs[u] == 0) {
                q.offer(u);
                costs[u] = time[u];
            }
        }
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : graph[u]) {
                costs[v] = Math.max(costs[v], costs[u] + time[v]);
                if (--inDegs[v] == 0) {
                    q.offer(v);
                }
            }
        }

        // Build maxTime
        int maxTime = 0;
        for (int u = 0; u < n; ++u) {
            maxTime = Math.max(maxTime, costs[u]);
        }
        return maxTime;
    }
}
