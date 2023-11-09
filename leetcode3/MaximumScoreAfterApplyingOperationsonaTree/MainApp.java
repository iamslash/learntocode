// Copyright (C) 2023 by iamslash

import java.util.*;

//           20
//        /      \
//       9        10
//     /   \     /  \
//    5     3   7    4


// Idea: dfs
//
//    1
//  /   \
// 2     3
//
// 1 or 2 + 3 = 5
//
//    5
//  /   \
// 2     1
//
// 5 or 2 + 1 = 5
//
//      5   
//    /   \
//   8     4
//  / \   / \
// 3   2 6   7
//

// 20ms 91.39% 56.9MB 78.61%
// dfs
// O(N) O(N)
class Solution {
    long ans = 0;
    private long[] dfs(int[] values, List<Integer>[] graph, int u, int p) {
        long leftout = 0, taken = 0;
        for (int v : graph[u]) {
            if (v == p) {
                continue;
            }
            long[] rst = dfs(values, graph, v, u);
            taken += rst[0];
            leftout += rst[1];
        }
        taken += (leftout != 0) ? Math.max(leftout, values[u]) : 0;
        leftout = (leftout != 0) ? Math.min(leftout, values[u]) : values[u];
        return new long[]{taken, leftout};
    }
    public long maximumScoreAfterOperations(int[][] edges, int[] values) {
        int n = values.length;
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        return dfs(values, graph, 0, -1)[0];
    }
}
