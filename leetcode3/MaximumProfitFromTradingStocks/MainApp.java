// Copyright (C) 2022 by iamslash

import java.util.*;

//  budget: 6
//  preset: 2 2 5
//  future: 3 4 10
//
// profits: 1 2 5
//          0 1 2
//
//          5 2 1
//          2 1 0
//            i
//  budget: 1 
//     sum: 5

//  budget: 10
// present: 5 4 6 2 3
//  future: 8 5 4 3 5
// profits: 3 1 -2 1 2
//          0 1  2 3 4
//
// profits: 3 2  1 1 -2
//          0 4  1 3  2
// present: 5 3  4 2  6
//               i
//  budget: 3
//     sum: 5

// 22ms 100.00% 42.8MB 100.00%
// iterative dynamic programming
// O(B^2) O(B)
// B: budget
class Solution {
    public int maximumProfit(int[] present, int[] future, int budget) {
        int n = present.length;
        int[] C = new int[budget + 1];
        for (int i = 0; i < n; ++i) {
            for (int a = budget; a >= 0; --a) {
                if (a >= present[i] && present[i] < future[i]) {
                    int profit = future[i] - present[i];
                    C[a] = Math.max(C[a], C[a - present[i]] + profit);
                }
            }
        }
        return C[budget];
    }
}
