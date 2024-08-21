// Copyright (C) 2024 by iamslash

import java.util.*;

// // 4ms 78.17% 44.4MB 75.52%
// // bfs topological sort
// // O(E + V) O(E)
// class Solution {
//     public boolean canFinish(int n, int[][] prerequisites) {
//         ArrayList<Integer>[] graph = new ArrayList[n];
//         int[] degrees = new int[n];
//         List<Integer> bfsList = new ArrayList<>();

//         for (int i = 0; i < n; ++i) {
//             graph[i] = new ArrayList<Integer>();
//         }
//         for (int[] edge : prerequisites) {
//             int v = edge[0], u = edge[1];
//             graph[u].add(v);
//             degrees[v]++;
//         }
//         for (int u = 0; u < n; ++u) {
//             if (degrees[u] == 0) {
//                 bfsList.add(u);
//             }
//         }
//         for (int u = 0; u < bfsList.size(); ++u) {
//             for (int v : graph[bfsList.get(u)]) {
//                 if (--degrees[v] == 0) {
//                     bfsList.add(v);
//                 }
//             }
//         }

//         return bfsList.size() == n;
//     }
// }

// 2ms 99.86% 44MB 94.32%
// dfs topological sort
// O(V + E) O(V)
class Solution {
    public boolean canFinish(int n, int[][] prerequisites) {
        List<Integer>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int[] edge : prerequisites) {
            adjList[edge[0]].add(edge[1]);
        }

        int[] visited = new int[n];

        for (int u = 0; u < n; u++) {
            if (!dfs(u, adjList, visited)) {
                return false; // Cycle detected, cannot finish all courses
            }
        }

        return true; // No cycle detected, all courses can be finished
    }

    private boolean dfs(int u, List<Integer>[] adjList, int[] visited) {
        if (visited[u] == 1) {
            return false; // Cycle detected
        }

        if (visited[u] == 2) {
            return true; // Course already fully processed
        }

        // Mark the course as being visited
        visited[u] = 1;

        // Visit all the neighboring courses
        for (int v : adjList[u]) {
            if (!dfs(v, adjList, visited)) {
                return false; // Cycle detected in recursion
            }
        }

        // Mark the course as fully processed
        visited[u] = 2;
        return true;
    }
}
