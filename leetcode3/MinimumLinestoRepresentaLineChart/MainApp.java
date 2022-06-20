// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: sort, slope
//
// Consider 3 values of continuous points
// such as a(x0, y0), b(x1, y1), c(x2, y2).
//
// Find formula.
// (y1 - y0) / (x1 - x0) == (y2 - y1) / (x2 - x1)
// But need float operation.
//
// (y1 - y0) * (x2 - x1) == (y2 - y1) * (x1 - x0)
// Yes, this is it.

// 57ms 60.88% 104.3MB 61.29%
// sort
// O(NlgN) O(1)
class Solution {
    public int minimumLines(int[][] stockPrices) {
        int n = stockPrices.length, ans = n - 1;
        Arrays.sort(stockPrices, (a, b) -> a[0] - b[0]);
        for (int i = 1; i < n-1; ++i) {
            if (1L *
                (stockPrices[i+1][1] - stockPrices[i][1]) *
                (stockPrices[i][0] - stockPrices[i-1][0]) ==
                1L *
                (stockPrices[i][1] - stockPrices[i-1][1]) *
                (stockPrices[i+1][0] - stockPrices[i][0])) {
                ans--;
            }
        }
        return ans;
    }
}
