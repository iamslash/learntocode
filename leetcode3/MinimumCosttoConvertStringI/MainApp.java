// Copyright (C) 2024 by iamslash

import java.util.*;

// 19ms 89.17% 45.5MB 86.25%
// floyd
// O(N) O(N)
class Solution {
    public long minimumCost(
        String source,
        String target,
        char[] original,
        char[] changed,
        int[] cost
    ) {
        int n = 26;
        int[][] graph = new int[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = i == j ? 0 : Integer.MAX_VALUE;
            }
        }

        for (int i = 0; i < original.length; ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u][v] = Math.min(graph[u][v], cost[i]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (graph[i][k] < Integer.MAX_VALUE &&
                        graph[k][j] < Integer.MAX_VALUE) {
                        graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < source.length(); ++i) {
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if (graph[u][v] == Integer.MAX_VALUE) {
                return -1;
            }
            ans += graph[u][v];
        }
        return ans;
    }
}
