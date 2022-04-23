// Copyright (C) 2022 by iamslash

import java.util.*;

// 14ms 72.37% 40.6MB 74.57%
// backtracking
// O(N!) O(N)
class Solution {
    private int dfs(int[] bals, int u) {
        int n = bals.length;
        while (u < n && bals[u] == 0) {
            u++;
        }
        // base
        if (u == n) {
            return 0;
        }
        // recursion
        int minTrx = Integer.MAX_VALUE;
        for (int v = u + 1; v < n; ++v) {
            if (bals[u] * bals[v] < 0) {
                bals[v] += bals[u];
                minTrx = Math.min(minTrx, 1 + dfs(bals, u + 1));
                bals[v] -= bals[u];
            }
        }
        return minTrx;
    }
    public int minTransfers(int[][] transactions) {
        Map<Integer, Integer> balMap = new HashMap<>();
        for (int[] trx : transactions) {
            balMap.put(trx[0], balMap.getOrDefault(trx[0], 0) - trx[2]);
            balMap.put(trx[1], balMap.getOrDefault(trx[1], 0) + trx[2]);
        }
        int n = balMap.size(), i = 0;
        int[] bals = new int[n];
        for (int bal : balMap.values()) {
            bals[i++] = bal;
        }
        // System.out.println(balMap);
        return dfs(bals, 0);
    }
}
