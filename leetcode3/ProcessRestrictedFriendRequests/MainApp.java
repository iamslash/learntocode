// Copyright (C) 2023 by iamslash

import java.util.*;

// 7ms 67.16% 44.7MB 26.87%
// disjoint set
// O(N) O(N)
class DisjointSet {
    private int[] prnts;
    public DisjointSet(int n) {
        prnts = new int[n];
        for (int i = 0; i < n; ++i) {
            prnts[i] = i;
        }
    }
    public void merge(int u, int v) {
        prnts[find(v)] = find(u);
    }
    public int find(int u) {
        if (prnts[u] == u) {
            return u;
        }
        return prnts[u] = find(prnts[u]);
    }
}
class Solution {
    public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
        int m = requests.length;
        DisjointSet ds = new DisjointSet(n);
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            int u = requests[i][0], v = requests[i][1];
            boolean friend = true;
            u = ds.find(u);
            v = ds.find(v);
            for (int[] ban : restrictions) {
                int p = ds.find(ban[0]), q = ds.find(ban[1]);
                if (u == p && v == q || u == q && v == p) {
                    friend = false;
                    break;
                }
            }            
            ans[i] = friend;
            if (friend) {
                ds.merge(u, v);
            }
        }
        return ans;
    }
}
