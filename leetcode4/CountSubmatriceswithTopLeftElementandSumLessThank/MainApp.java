// Copyright (C) 2024 by iamslash

// 7 6 3
// 6 6 1

//  7 13 16
// 13 25 29

//  7 13 16
// 13 32 29 



// 7ms 32.34% 117.4MB 89.19%
// grid sum
// O(HW) O(1)
class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int h = grid.length, w = grid[0].length;
        int cnt = 0;

        // build gridsum
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (y > 0) {
                    grid[y][x] += grid[y - 1][x];
                }
                if (x > 0) {
                    grid[y][x] += grid[y][x - 1];
                }
                if (y > 0 && x > 0) {
                    grid[y][x] -= grid[y - 1][x - 1];
                }
                if (grid[y][x] <= k) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
