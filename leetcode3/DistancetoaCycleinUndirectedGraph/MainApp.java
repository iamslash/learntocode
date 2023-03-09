// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: BFS
//
// List<Integer>[] graph: graph.
// int[] ans: distance from the cycle nodes.
// int[] cnts: count of neighbors.
// BFS not cycle nodes. out to in.
//   cnts[u] == Integer.MAX_VALUE.
// BFS cycle nodes. in to out.
//   Update distances of not cycle nodes.

// 23ms 100.00% 95.7MB 88.89%
// bfs
// O(N) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println();
    }
    public int[] distanceToCycle(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<>();
        }
        int[] ans = new int[n];
        int[] cnts = new int[n];
        Queue<Integer> q = new LinkedList<>();
        // Build graph
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        // Build cnts, q for leaf nodes
        for (int u = 0; u < n; ++u) {
            cnts[u] = graph[u].size();
            if (cnts[u] == 1) {
                q.offer(u);
            }
        }
        //    q: 0 6
        // cnts: 1 3 3 2 2 2 1 

        // BFS not cycle nodes.
        while (!q.isEmpty()) {
            int u = q.poll();
            ans[u] = Integer.MAX_VALUE;
            for (int v : graph[u]) {
                if (cnts[v] > 1 && --cnts[v] == 1) {
                    q.offer(v);
                }
            }
        }
        //    q: []
        // cnts: 1 2 2 2 2 1 1 
        //  ans: M 0 0 0 0 M M

        // Add loop nodes.
        for (int u = 0; u < n; ++u) {
            if (cnts[u] > 1) {
                q.offer(u);
            }
        }
        //   q: [1, 2, 3, 4]
        
        // BFS cycle nodes
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : graph[u]) {
                if (ans[v] > ans[u] + 1) {
                    ans[v] = ans[u] + 1;
                    q.offer(v);
                }
            }
        }
        return ans;
    }
}

//    q: 5
// cnts: 1 2 2 2 2 1 1
//  ans: 1 0 0 0 0 1 2
