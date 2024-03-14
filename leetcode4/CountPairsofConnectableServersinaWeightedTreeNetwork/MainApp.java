// Copyright (C) 2024 by iamslash

import java.util.*;

// 282ms 45.96% 45.3MB 94.79%
// dfs
// O(N^2) O(N^2)
class Solution {
    private int dfs(List<List<int[]>> graph, int signalSpeed, int p, int u, int cost) {
        // recursion
        int n = graph.size(), cnt = 0;
        if (cost % signalSpeed == 0) {
            cnt = 1;
        }
        for (int[] next : graph.get(u)) {
            int v = next[0], c = next[1];
            if (v == p) {
                continue;
            }
            cnt += dfs(graph, signalSpeed, u, v, cost + c);
        }

        return cnt;
    }
    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length + 1;
        int[] ans = new int[n];
        List<List<int[]>> graph = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], c = edge[2];
            graph.get(u).add(new int[]{v, c});
            graph.get(v).add(new int[]{u, c});
        }

        for (int u = 0; u < n; ++u) {
            int uRootedCnt = 0, vRootedPrevCnt = 0;
            for (int[] next : graph.get(u)) {
                int v = next[0], c = next[1];
                int vRootedCnt = dfs(graph, signalSpeed, u, v, c);
                uRootedCnt += vRootedPrevCnt * vRootedCnt;
                vRootedPrevCnt += vRootedCnt;
            }
            ans[u] = uRootedCnt;
        }

        return ans;

    }
}
