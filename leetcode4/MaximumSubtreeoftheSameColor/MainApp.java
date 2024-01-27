// Copyright (C) 2024 by iamslash

import java.util.*;

// dfs
// 43ms 41.36% 82.3MB 6.17%
class Solution {
    private int maxSubtreeSize = 1;
    
    public int maximumSubtreeSize(int[][] edges, int[] colors) {
        int n = colors.length;
        List<Integer>[] graph = new ArrayList[n];
        for (int u = 0; u < n; ++u) {
            graph[u] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        dfs(colors, graph, 0, -1);
        return maxSubtreeSize;
    }

    private int dfs(int[] colors, List<Integer>[] graph,
                    int u, int p) {
        int subtreeSize = 1;
        boolean allSameColor = true;
        
        for (int v : graph[u]) {
            if (v != p) {
                int childSubtreeSize = dfs(colors, graph, v, u);
                if (childSubtreeSize != -1 && colors[u] == colors[v]) {
                    subtreeSize += childSubtreeSize;
                } else {
                    allSameColor = false;
                }
            }
        }
        
        if (!allSameColor) {
            subtreeSize = -1;
        } else {
            maxSubtreeSize = Math.max(maxSubtreeSize, subtreeSize);
        }
        
        return subtreeSize;
    }
}
