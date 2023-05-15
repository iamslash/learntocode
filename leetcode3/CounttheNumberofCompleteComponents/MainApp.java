// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: dfs
//
// Search fully connected component.
// node * (node - 1) / 2 == undirected edge
//
//     1 -- 2 
//     | \/ |
//     | /\ |
//     3 -- 4
//
// 4 * 3 / 2 == 6

// 15ms 70.79% 42.6MB 92.73%
// dfs
// O(N) O(N)
class Solution {
    private int edgeCnt = 0, nodeCnt = 0;
    private void dfs(boolean[][] graph, boolean[] visit, int u) {
        int n = graph.length;
        visit[u] = true;
        nodeCnt++;
        // recursion
        for (int v = 0; v < n; ++v) {
            if (!graph[u][v]) {
                continue;
            }
            // for single node
            edgeCnt++;  
            if (!visit[v]) {
                dfs(graph, visit, v);
            }
        }
    }
    public int countCompleteComponents(int n, int[][] edges) {
        boolean[][] graph = new boolean[n][n];
        boolean[] visit = new boolean[n];
        int compCnt = 0;
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u][v] = true;
            graph[v][u] = true;
        }
        for (int u = 0; u < n; ++u) {
            edgeCnt = 0;
            nodeCnt = 0;
            if (!visit[u]) {
                dfs(graph, visit, u);
                // for single node
                edgeCnt /= 2;
                if (edgeCnt == (nodeCnt * (nodeCnt - 1) / 2)) {
                    compCnt++;
                }
            }
        }
        return compCnt;
    }
}
