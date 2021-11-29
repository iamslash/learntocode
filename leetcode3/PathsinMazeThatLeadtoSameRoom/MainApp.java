// Copyright (C) 2021 by iamslash

import java.util.*;

// u --- v
//  \   /
//    k

// 294ms 65.36% 62MB 60.13%
// hash map
// O(E+V) O(EV)
class Solution {
    public int numberOfPaths(int n, int[][] corridors) {
        Map<Integer, Set<Integer>> G = new HashMap<>();
        for (int i = 1; i <= n; ++i) {
            G.put(i, new HashSet<>());
        }
        // build undirected graph
        for (int[] edge : corridors) {
            int u = edge[0], v = edge[1];
            if (u < v) {
                G.get(u).add(v);
            } else {
                G.get(v).add(u);
            }
        }
        //
        int ans = 0;
        for (int[] edge : corridors) {
            int u = edge[0], v = edge[1];
            Set<Integer> uNeighborSet = G.get(u);
            Set<Integer> vNeighborSet = G.get(v);
            for (int z : uNeighborSet) {
                if (vNeighborSet.contains(z)) {
                    ans++;
                }
            }
        }                                     
        return ans;
    }
}

// 73ms 99.35% 59.2MB 92.81%
// brute force
// O(N^3) O(N^2)
class Solution {
    public int numberOfPaths(int n, int[][] corridors) {
        boolean[][] G = new boolean[n+1][n+1];
        for (int[] edge : corridors) {
            int u = Math.min(edge[0], edge[1]);
            int v = Math.max(edge[0], edge[1]);
            G[u][v] = true;
        }
        int ans = 0;
        for (int u = 1; u < n; ++u) {
            for (int v = u+1; v < n; ++v) {
                if (!G[u][v]) {
                    continue;
                }
                for (int z = v+1; z <= n; ++z) {
                    if (G[u][z] && G[v][z]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}
