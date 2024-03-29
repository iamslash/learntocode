// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 43.7MB 19.84%
// exhaustive search
// O(N) O(N)
class Solution {
    private int[][] dirs = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    private boolean dfs(int[][] grid, int y, int x, int seq) {
        // System.out.printf("y: %d, x: %d, ord: %d\n", y, x, ord);
        int n = grid.length;
        // base
        if (y < 0 || y >= n || x < 0 || x >= n ||
            grid[y][x] != seq) {
            return false;
        }
        if (grid[y][x] == (n * n - 1)) {
            return true;
        }
        // recursion
        for (int i = 0; i < dirs.length; ++i) {
            int ny = y + dirs[i][0], nx = x + dirs[i][1];
            if (dfs(grid, ny, nx, seq + 1)) {
                return true;
            }
        }
        return false;
    }
    public boolean checkValidGrid(int[][] grid) {
        return dfs(grid, 0, 0, 0);
    }
}
