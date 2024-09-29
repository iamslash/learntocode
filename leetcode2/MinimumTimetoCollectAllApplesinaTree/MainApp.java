// Copyright (C) 2024 by iamslash

import java.util.*;

// dfs
// O(N) O(N)
class Solution {

    private int dfs(List<List<Integer>> adj, List<Boolean> hasApple, int u, int p) {
        // base
        int cost = 0;

        // recursion
        for (int v : adj.get(u)) {
            if (v == p) {
                continue;
            }
            cost += dfs(adj, hasApple, v, u);
        }

        if (u != 0 && (hasApple.get(u) || cost > 0)) {
            cost += 2;
        }

        return cost;
    }
    
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        return dfs(adj, hasApple, 0, 0);
    }
}
