// Copyright (C) 2023 by iamslash

import java.util.*;

// 5ms 71.43% 42.9MB 42.86%
// dfs
// O(HW) O(HW)
class Solution {
    private int dfs(int[][] grid, int y, int x) {
        int h = grid.length, w = grid[0].length;
        // base
        if (y < 0 || y >= h || x < 0 || x >= w || grid[y][x] == 0) {
            return 0;
        }
        int fish = grid[y][x];
        grid[y][x] = 0;
        // recursion
        return fish +
            dfs(grid, y - 1, x) +
            dfs(grid, y, x + 1) +
            dfs(grid, y + 1, x) +
            dfs(grid, y, x - 1);
    }
    public int findMaxFish(int[][] grid) {
        int h = grid.length, w = grid[0].length, maxFish = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] > 0) {
                    maxFish = Math.max(maxFish, dfs(grid, y, x));
                }
            }
        }
        return maxFish;
    }
}
