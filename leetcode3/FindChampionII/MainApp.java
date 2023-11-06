// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 44.2MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] inDegs = new int[n];
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            inDegs[v]++;
        }
        int champion = -1;
        for (int u = 0; u < n; ++u) {
            if (inDegs[u] == 0) {
                if (champion >= 0) {
                    return -1;
                }
                champion = u;
            }
        }
        return champion;
    }
}
