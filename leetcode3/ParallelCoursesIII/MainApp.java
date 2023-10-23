// Copyright (C) 2023 by iamslash

import java.util.*;

// 21ms 56.01% 65.6MB 78.84%
// topological sort
// O(N) O(N)
class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        int[] costs = new int[n];
        int[] inDegs = new int[n];
        List<Integer>[] graph = new ArrayList[n];        
        // CAUTION: This doesn't work. 
        // Arrays.fill(graph, new ArrayList<>());
        for (int u = 0; u < n; ++u) {
            graph[u] = new ArrayList<>();
        }

        // Build graph, inDegs
        for (int[] edge : relations) {
            int u = edge[0] - 1, v = edge[1] - 1;
            // System.out.printf("%d : %d\n", u, v);
            graph[u].add(v);
            inDegs[v]++;
        }
        
        // for (int u = 0; u < n; ++u) {
        //     System.out.println(graph[u]);
        // }

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
            // System.out.println(u);
            for (int v : graph[u]) {
                // System.out.printf("\t%d\n", v);
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
