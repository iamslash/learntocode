// Copyright (C) 2023 by iamslash

import java.util.*;

// 1 1 0 0    1 0 0 0
// 1 1 1 1    1 0 0 0 
// 1 1 1 1    1 1 1 1

// Idea: dfs
//
// At first, dfs with chaning the cell from 1 to 0.
// At second, dfs again.
// successful two dfs returns false otherwise returns true. 

// 0ms 100.00% 51.5MB 78.46%
// dfs
// O(HW) O(HW)
class Solution {
    private boolean dfs(int[][] grid, int y, int x) {
        int h = grid.length, w = grid[0].length;
        if (y == h || x == w || grid[y][x] == 0) {
            return false;
        }
        if (y == h - 1 && x == w - 1) {
            return true;
        }
        if (y != 0 || x != 0) {
            grid[y][x] = 0;
        }
        return dfs(grid, y, x + 1) || dfs(grid, y + 1, x);
    }
    public boolean isPossibleToCutPath(int[][] grid) {
        return !(dfs(grid, 0, 0) && dfs(grid, 0, 0));
    }
}
