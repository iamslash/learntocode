// Copyright (C) 2023 by iamslash

import java.util.*;

//        0 1 2 3 4
//  vals: 1 3 2 1 3
// edges: 0,1 0,2 2,3 2,4
//        0,2 2,3 0,1 2,4
//                      i
//        
// freqs: 1 1 1 1 1 
//   ans:
//        1
//        2
//        0
//        3
//        4

// disjoint set
// O(N) O(N)
class Solution {
    private int[] prnts, freqs;
    private int ans;
    private int find(int u) {
        // base
        if (prnts[u] == u) {
            return u;
        }
        // recursion
        return prnts[u] = find(prnts[u]);
    }    
    private void merge(int u, int v, int[] vals) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        if (vals[u] == vals[v]) {
            ans += freqs[u] * freqs[v];
            freqs[u] += freqs[v];
            prnts[v] = u;
        } else if (vals[u] > vals[v]) {
            prnts[v] = u;
        } else {
            prnts[u] = v;
        }
    }
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        Arrays.sort(edges, (e1, e2) ->
                    Integer.compare(Math.max(vals[e1[0]], vals[e1[1]]),
                                    Math.max(vals[e2[0]], vals[e2[1]])));
        int n = vals.length;
        ans = n;
        prnts = new int[n];
        freqs = new int[n];
        Arrays.fill(freqs, 1);
        for (int u = 0; u < n; ++u) {
            prnts[u] = u;
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            merge(u, v, vals);
        }
        return ans;
    }
}

