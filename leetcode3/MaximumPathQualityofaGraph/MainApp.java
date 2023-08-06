// Copyright (C) 2023 by iamslash

import java.util.*;

// 118ms 93.58% 45MB 22.46%
// dfs
// O(EV) O(E+V)
class Solution {
    private void dfs(int[] values, List<int[]>[] adj, int maxTime, 
                     int[] visit, int[] ans, int sum, int u) {
        // base
        if (u == 0) {
            ans[0] = Math.max(ans[0], sum);
        }
        if (maxTime < 0) {
            return;
        }
        // recursion
        for (int[] next : adj[u]) {
            int v = next[0], t = next[1];
            if (maxTime - t < 0) {
                continue;
            }
            visit[v]++;
            dfs(values, adj, maxTime - t, visit, ans, sum + (1 == visit[v] ? values[v] : 0), v); 
            visit[v]--;
        }
    }
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        List<int[]>[] adj = new List[n];
        for (int i = 0; i < n; ++i) {
            adj[i] = new LinkedList();            
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].add(new int[]{v, t});
            adj[v].add(new int[]{u, t});
        }
        int[] ans = new int[1];
        int[] visit = new int[n];
        visit[0]++;
        dfs(values, adj, maxTime, visit, ans, values[0], 0);
        return ans[0];
    }
}
