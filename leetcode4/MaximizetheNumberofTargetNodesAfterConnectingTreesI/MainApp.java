// Copyright (C) 2025 by iamslash

import java.util.*;


// Idea: dfs
//
// Build tree1[][]
// Build tree2[][]
// Build tree1NodeCnts[] with dfs(tree1)
// Get maxTree2NodeCnt with dfs(tree2)
// ans[i] = tree1NodeCnts[i] + maxTree2NodeCnt
//

// 262ms 82.39% 47.32MB 41.48
// dfs
// O(N + M) O(N + M)
class Solution {

    private int dfs(List<Integer>[] graph, boolean[] visited, int u, int k) {
        // base
        if (k < 0) {
            return 0;
        }
        // recursion
        int cnt = 1;
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                cnt += dfs(graph, visited, v, k - 1);
            }
        }

        return cnt;
    }
    
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.length + 1, m = edges2.length + 1;
        int[] ans = new int[n];
        List<Integer>[] tree1 = new ArrayList[n];
        List<Integer>[] tree2 = new ArrayList[m];

        for (int i = 0; i < n; ++i) {
            tree1[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; ++i) {
            tree2[i] = new ArrayList<>();
        }

        for (int[] edge : edges1) {
            int u = edge[0], v = edge[1];
            tree1[u].add(v);
            tree1[v].add(u);
        }
        for (int[] edge : edges2) {
            int u = edge[0], v = edge[1];
            tree2[u].add(v);
            tree2[v].add(u);
        }

        int[] tree1NodeCnts = new int[n];
        for (int i = 0; i < n; ++i) {
            boolean[] visited = new boolean[n];
            visited[i] = true;
            tree1NodeCnts[i] = dfs(tree1, visited, i, k);
        }

        int maxTree2NodeCnt = 0;
        for (int i = 0; i < m; ++i) {
            boolean[] visited = new boolean[m];
            visited[i] = true;
            maxTree2NodeCnt = Math.max(maxTree2NodeCnt,
                                       dfs(tree2, visited, i, k - 1));
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = tree1NodeCnts[i] + maxTree2NodeCnt;
        }

        return ans;
    }
}
