// Copyright (C) 2023 by iamslash

// Idea: dfs
//
// First, dfs with changing cell from 1 to 0.
// Second, dfs with changing cell from 1 to 0 again.
// If two dfs return true, return false.
// That means 2 more connects.
// Otherwise return true.
// That means disconnected.

// 0ms 100.00% 52.1MB 42.62%
// dfs
// O(HW) O(HW)
class Solution {
    private boolean dfs(int[][] grid, int y, int x) {
        int h = grid.length, w = grid[0].length;
        // base
        if (y >= h || x >= w || grid[y][x] == 0) {
            return false;
        }
        if (y == h - 1 && x == w - 1) {
            return true;
        }
        if (y != 0 || x != 0) {
            grid[y][x] = 0;
        }
        // rcursion
        return dfs(grid, y + 1, x) || dfs(grid, y, x + 1);
    }
    public boolean isPossibleToCutPath(int[][] grid) {
        return !(dfs(grid, 0, 0) && dfs(grid, 0, 0));
    }
}
