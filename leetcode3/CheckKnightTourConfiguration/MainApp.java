// Copyright (C) 2023 by iamslash

import java.util.*;

//  1,2  2,1  2,-1  1,-2
// -1,2 -2,1 -2,-1 -1,-2

// 2ms 100.00% 42.1MB 100.00%
// dfs
// O(HW) O(HW)
class Solution {
    private int[][] dirs = {{1, 2},
                            {2, 1},
                            {2, -1},
                            {1, -2},
                            {-1, 2},
                            {-2, 1},
                            {-2, -1},
                            {-1, -2}};
    private boolean dfs(int[][] grid, int y, int x, int seq) {
        int n = grid.length;
        // base
        if (y < 0 || x < 0 || y >= n || x >= n || seq != grid[y][x]) {
            return false;
        }
        if (seq == n * n - 1) {
            return true;
        }
        // recursion
        for (int i = 0; i < 8; ++i) {
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
