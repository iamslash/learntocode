// Copyright (C) 2022 by iamslash

import java.util.*;

// 50ms 29.84% 159.7MB 22.98%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        int n = regular.length;
        long[] minCostReg = new long[n + 1];
        long[] minCostExp = new long[n + 1];
        long[] ans = new long[n];
        minCostExp[0] = expressCost;
        for (int i = 0; i < n; ++i) {
            minCostReg[i+1] = Math.min(minCostReg[i] + regular[i],
                                       minCostExp[i] + express[i]);
            minCostExp[i+1] = Math.min(minCostReg[i+1] + expressCost,
                                       minCostExp[i] + express[i]);
            ans[i] = Math.min(minCostReg[i+1], minCostExp[i+1]);
        }
        return ans;
    }
}
