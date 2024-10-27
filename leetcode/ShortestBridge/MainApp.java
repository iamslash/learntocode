// Copyright (C) 2024 by iamslash

import java.util.*;

// 7ms 97.60% 44.8MB 87.97%
// dfs
// O(N^2) O(1)
class Solution {
    private int paint(int[][] grid, int y, int x) {
        int n = grid.length;
        if (y < 0 || x < 0 || y >= n || x >= n || grid[y][x] != 1) {
            return 0;
        }
        grid[y][x] = 2;
        return 1 + paint(grid, y - 1, x) +
            paint(grid, y, x + 1) +
            paint(grid, y + 1, x) +
            paint(grid, y, x - 1);
    }

    private boolean expand(int[][] grid, int y, int x, int c) {
        int n = grid.length;
        if (y < 0 || x < 0 || y >= n || x >= n) {
            return false;
        }
        
        if (grid[y][x] == 0) {
            grid[y][x] = c + 1;
        }
        
        return grid[y][x] == 1;
    }
    
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int found = 0;
        for (int y = 0; found == 0 && y < n; ++y) {
            for (int x = 0; found == 0 && x < n; ++x) {
                found = paint(grid, y, x);
            }
        }

        for (int c = 2; ; ++c) {
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (grid[y][x] != c) {
                        continue;
                    }
                    if (expand(grid, y - 1, x, c) ||
                        expand(grid, y, x + 1, c) ||
                        expand(grid, y + 1, x, c) ||
                        expand(grid, y, x - 1, c)) {
                        return c - 2;
                    }
                }
            }
        }
    }
}
