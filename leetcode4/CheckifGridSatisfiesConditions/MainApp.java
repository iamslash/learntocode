// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 44.2MB 100.00%
// brute force
// O(HW) O(1)
class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int h = grid.length, w = grid[0].length;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if ((y + 1 < h && grid[y][x] != grid[y + 1][x]) ||
                    (x + 1 < w && grid[y][x] == grid[y][x + 1])) {
                    return false;
                }
            }
        }

        return true;
    }
}
