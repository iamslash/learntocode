// Copyright (C) 2025 by iamslash

import java.util.*;

// k: 1
// p: 1,2 1,1 3,4 4,5 5,6 7,7
//
// 0: 1 2
// 1: 1
// 2: 3 4
// 3: 4 5
// 4: 5 6
// 5: 7
//
// 6 - 1 - 1 - 1

// 165ms 90.56% 46.29MB 19.96%
// disjoint set
// O(NM) O(N)
class Solution {
    private boolean isConnected(Set<Integer>[] propSets, int k,
                                int u, int v) {
        for (int p : propSets[u]) {
            if (propSets[v].contains(p)) {
                if (--k == 0) {
                    return true;
                }
            }
        }

        return false;
    }

    private int merge(int[] prnts, int u, int v) {
        u = find(prnts, u);
        v = find(prnts, v);
        prnts[v] = u;
        if (u == v) {
            return 0;
        }
        return 1;
    }

    private int find(int[] prnts, int u) {
        if (prnts[u] == u) {
            return u;
        }
        return prnts[u] = find(prnts, prnts[u]);
    }
    
    public int numberOfComponents(int[][] properties, int k) {
        int n = properties.length, compCnt = n;
        int[] prnts = new int[n];
        Set<Integer>[] propSets = new HashSet[n];

        for (int u = 0; u < n; ++u) {
            prnts[u] = u;
        }

        for (int u = 0; u < n; ++u) {
            propSets[u] = new HashSet<>();
            for (int prop : properties[u]) {
                propSets[u].merge(prop);
            }
        }

        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                if (isConnected(propSets, k, u, v)) {
                    compCnt -= merge(prnts, u, v);
                    // System.out.printf("u: %d, v: %d, compCnt: %d\n", u, v, compCnt);
                }
            }
        }

        return compCnt;
    }
}
