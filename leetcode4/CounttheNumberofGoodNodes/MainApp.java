// Copyright (C) 2025 by iamslash

import java.util.*;

// Ideation: dfs
//
// Build undirected graph instead of directed graph.
// The input might be [[6,0],[1,0],[5,1],[2,5],[3,1],[4,3]].

// dfs
// O(N) O(N)
// 116ms 70.59% 118.53MB 68.07%
class Solution {
    private List<List<Integer>> graph;
    private int goodCnt = 0;

    private int dfs(int curr, int parent) {
        int size = 1; 
        int prevCnt = 0; 

        for (int nbr : graph.get(curr)) {
            if (nbr != parent) {
                int childCnt = dfs(nbr, curr);
                size += childCnt;

                if (prevCnt == 0) {
                    prevCnt = childCnt;
                } else if (prevCnt != childCnt) {
                    prevCnt = -1;
                }
            }
        }

        if (prevCnt >= 0) {
            goodCnt++;
        }

        return size; 
    }

    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;
        graph = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);  
        }

        dfs(0, -1);

        return goodCnt;
    }
}
