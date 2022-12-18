// Copyright (C) 2022 by iamslash

import java.util.*;

// Time Limit Exceeded
class TreeAncestor {
    int[] parent;
    
    public TreeAncestor(int n, int[] parent) {
        this.parent = parent;
    }
    
    public int getKthAncestor(int node, int k) {
        int p = node;
        while (k-- > 0) {
            p = parent[p];
            if (p < 0) {
                return -1;
            }
        }
        return p;
    }
}

// 142ms 70.22% 105.0MB 64.04%
// binary lifting
// O(lgN) O(N)
class TreeAncestor {
    Map<Integer, List<Integer>> graph = new HashMap<>();
    Integer[][] C;

    public TreeAncestor(int n, int[] parents) {
        this.C = new Integer[n][30];
        for (int u = 0; u < n; ++u) {
            int p = parents[u];
            graph.computeIfAbsent(p, v -> new ArrayList<>()).add(u);
            if (u > 0) {
                C[u][0] = parents[u];
            }
        }
        dfs(0);
    }
    
    private void dfs(int u) {
        for (int i = 1; this.C[u][i - 1] != null; ++i) {
            int p = this.C[u][i - 1];
            C[u][i] = C[p][i - 1];
        }
        for (int v : graph.getOrDefault(u, new ArrayList<>())) {
            dfs(v);
        }
    }
    
    public int getKthAncestor(int node, int k) {
        for (int i = 0; k > 0; ++i) {
            if (k % 2 == 1) {
                if (C[node][i] == null) {
                    return -1;
                }
                node = C[node][i];
            }
            k /= 2;
        }
        return node;
    }
}

// binary lifting
// 174ms 42.70% 98.1MB 82.02%
// difficult
class TreeAncestor {
    int[][] C;
    int maxPow;
    public TreeAncestor(int n, int[] parents) {
        maxPow = (int) (Math.log(n) / Math.log(2)) + 1;
        C = new int[maxPow][n];
        C[0] = parents;
        for (int p = 1; p < maxPow; ++p) {
            for (int j = 0; j < n; ++j) {
                int pre = C[p - 1][j];
                C[p][j] = pre == -1 ? -1 : C[p - 1][pre];
            }
        }
    }
    public int getKthAncestor(int node, int k) {
        int maxPow = this.maxPow;
        while (k > 0 && node > -1) {
            if (k >= (1 << maxPow)) {
                node = C[maxPow][node];
                k -= (1 << maxPow);
            } else {
                maxPow--;
            }
        }
        return node;
    }
}
