// Copyright (C) 2023 by iamslash

import java.util.*;

// 70ms 7.30% 43.5MB 89.47%
// binary search
// O(NlgN) O(1)
class Solution {
    private boolean valid(int budget,
                          List<List<Integer>> composition,
                          List<Integer> stock,
                          List<Integer> cost,
                          long alloyCnt) {
        long minCost = Integer.MAX_VALUE;
        for (int i = 0; i < composition.size(); ++i) {
            long curCost = 0;
            for (int j = 0; j < composition.get(i).size(); ++j) {
                long mtrlCnt = alloyCnt * composition.get(i).get(j);
                if (stock.get(j) >= mtrlCnt) {
                    continue;
                }
                long extra = (mtrlCnt - stock.get(j)) * cost.get(j);
                curCost += extra;
            }
            minCost = Math.min(minCost, curCost);
        }
        return minCost <= budget;
    }
    public int maxNumberOfAlloys(int n, int k, int budget,
                                 List<List<Integer>> composition,
                                 List<Integer> stock,
                                 List<Integer> cost) {
        long lo = 0, hi = 1_000_000_009L;
        while (lo < hi) {
            long mi = (lo + hi + 1) / 2;
            if (valid(budget, composition, stock, cost, mi)) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return (int)lo;
    }
}
