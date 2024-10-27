// Copyright (C) 2024 by iamslash

// 0ms 100.00% 41.5MB 80.54%
// iterative dynamic programming
// O(HW) O(1)
class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        if (grid[0][0] == 1) {
            return 0;
        }

        grid[0][0] = 1;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (y == 0 && x == 0) {
                    continue;
                }
                
                if (grid[y][x] == 1) {
                    grid[y][x] = 0;
                } else {
                    int top = y > 0 ? grid[y - 1][x] : 0;
                    int left = x > 0 ? grid[y][x - 1] : 0;
                    grid[y][x] = top + left;
                }
            }
        }        

        return grid[h - 1][w - 1];
    }
}
