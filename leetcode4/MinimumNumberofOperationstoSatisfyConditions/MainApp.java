// Copyright (C) 2024 by iamslash

import java.util.*;

// grid:
// 1 1 1
// 0 0 0
//
// colCosts:    minCosts:
//
// 0: 1 1 1     M M M
// 1: 1 1 1     M M M
// 2: 2 2 2     M M M
// 3: 2 2 2     M M M
// 4: 2 2 2     M M M
// 5: 2 2 2     M M M
// 6: 2 2 2     M M M
// 7: 2 2 2     M M M
// 8: 2 2 2     M M M
// 9: 2 2 2     M M M

// 61ms 29.92% 156.7MB 53.41%
// iterative dynamic programming
// O(HW) O(W)
class Solution {
    public int minimumOperations(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[][] colCosts = new int[w][10];
        int[][] minCosts = new int[w][10];
   
        for (int x = 0; x < w; ++x) {
            Arrays.fill(minCosts[x], 1_000_000_000);
        }

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                for (int val = 0; val < 10; ++val) {
                    if (grid[y][x] != val) {
                        colCosts[x][val]++;
                    }
                }
            }
        }

        for (int x = 0; x < w; ++x) {
            for (int curVal = 0; curVal < 10; ++curVal) {
                for (int prvVal = 0; prvVal < 10; ++prvVal) {
                    if (curVal != prvVal) {
                        // extra cost
                        int prvCost = x > 0 ? minCosts[x - 1][prvVal] : 0;
                        minCosts[x][curVal] = Math.min(minCosts[x][curVal],
                                                       colCosts[x][curVal] + prvCost);
                    }
                }
            }
        }

        int minCost = Integer.MAX_VALUE;
        for (int val = 0; val < 10; ++val) {
            minCost = Math.min(minCost, minCosts[w - 1][val]); 
        }

        return minCost;
    }
}
