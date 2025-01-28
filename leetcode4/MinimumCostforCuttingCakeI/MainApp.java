// Copyright (C) 2025 by iamslash

import java.util.*;


//    m: 3
//    n: 2
//  hor: 1 3
//       i
//  ver: 5
//      j
// hPie: 2
// vPie: 2
//
// cost: 11

// 1ms 99.38% 41.85MB 91.93%
// greedy
// O(HlgH + VlgV) O(1)
class Solution {
    public int minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        int hPieces = 1, vPieces = 1;
        int h = horizontalCut.length, w = verticalCut.length;
        int i = h - 1, j = w - 1, cost = 0;
        Arrays.sort(horizontalCut);
        Arrays.sort(verticalCut);

        while (i >= 0 || j >= 0) {
            if ((i < 0) || (j >= 0 && horizontalCut[i] <= verticalCut[j])) {
                cost += verticalCut[j] * hPieces;
                vPieces++;
                j--;
            } else if ((j < 0) || (i >= 0 && horizontalCut[i] >= verticalCut[j])) {
                cost += horizontalCut[i] * vPieces;
                hPieces++;
                i--;
            }
        }
        
        return cost;
    }
}
