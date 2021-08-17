// Copyright (C) 2021 by iamslash

import java.util.*;

// 251ms 100.00% 160.1MB 100.00%
// DFS
// O(VE) O(VE)
// class Solution {
//     private void dfs(boolean[] visit, Map<Integer, List<Integer>> adjMap, int u, int end) {
//         int n = visit.length;
//         // base
//         if (u == end) {
//             visit[u] = true;
//             return;
//         }
//         if (visit[u] || visit[end] || adjMap.get(u) == null) {
//             return;
//         }
//         visit[u] = true;
//         // recursion
//         for (int v : adjMap.get(u)) {
//             dfs(visit, adjMap, v, end);
//         }
//     }
//     public boolean validPath(int n, int[][] edges, int start, int end) {
//         boolean[] visit = new boolean[n];
//         Map<Integer, List<Integer>> adjMap = new HashMap<>();
//         for (int[] edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adjMap.putIfAbsent(u, new ArrayList<>());
//             adjMap.get(u).add(v);
//             adjMap.putIfAbsent(v, new ArrayList<>());
//             adjMap.get(v).add(u);
//         }
//         dfs(visit, adjMap, start, end);
//         return visit[end] == true;
//     }
// }

// // 108ms 100.00% 147.8MB 100.00%
// // BFS
// // O(V+E) O(V)
// class Solution {
//     public boolean validPath(int n, int[][] edges, int start, int end) {
//         Queue<Integer> q = new ArrayDeque<>();
//         boolean[] visit = new boolean[n];
//         Map<Integer, List<Integer>> adjMap = new HashMap<>();
//         for (int[] edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adjMap.putIfAbsent(u, new ArrayList<>());
//             adjMap.get(u).add(v);
//             adjMap.putIfAbsent(v, new ArrayList<>());
//             adjMap.get(v).add(u);
//         }
//         visit[start] = true;
//         q.offer(start);
//         while (q.size() > 0) {
//             int u = q.poll();
//             if (u == end) {
//                 return true;
//             }
//             if (adjMap.get(u) == null) {
//                 continue;
//             }
//             for (int v : adjMap.get(u)) {
//                 if (visit[v]) {
//                     continue;
//                 }
//                 visit[v] = true;
//                 q.offer(v);
//             }            
//         }
//         return false;
//     }    
// }

// 10ms 100.00% 94.2MB 100.00%
// DisjointSet
// O(N) O(N)
class Solution {
    private int[] parents;
    private int find(int u) {
        // base
        if (parents[u] == u) {
            return u;
        }
        // recursion
        return parents[u] = find(parents[u]);
    }
    private void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return;            
        }
        parents[u] = v;
    }
    public boolean validPath(int n, int[][] edges, int start, int end) {
        parents = new int[n];
        for (int u = 0; u < n; ++u) {
            parents[u] = u;
        }
        for (int[] edge : edges) {
            merge(edge[0], edge[1]);
        }
        return find(start) == find(end);
    }    
}

public class MainApp {
  public static void main(String[] args) {
  }
}
