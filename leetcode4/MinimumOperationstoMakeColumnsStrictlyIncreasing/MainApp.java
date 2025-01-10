// Copyright (C) 2025 by iamslash

import java.util.*;


// 3 2    3 2
// 1 3    4 3
// 3 4      4
// 0 1      5

// 1ms 99.95% 44.96MB 93.61%
// brute force
// O(HW) O(1)
class Solution {
    public int minimumOperations(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int ops = 0;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (y > 0) {
                    if (grid[y-1][x] >= grid[y][x]) {
                        ops += grid[y-1][x] + 1 - grid[y][x];
                        grid[y][x] = grid[y-1][x] + 1;
                    } 
                }
            }
        }

        return ops;
    }
}
