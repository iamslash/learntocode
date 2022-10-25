// Copyright (C) 2022 by iamslash

import java.util.*;

// 24ms 17.91% 53.9MB 59.08%
// matrix
// O(HW) O(1)
class Solution {
    public int maxSum(int[][] grid) {
        int maxVal = 0, h = grid.length, w = grid[0].length;
        for (int y = 0; y < h-2; ++y) {
            for (int x = 0; x < w-2; ++x) {
                int val = grid[y][x] + grid[y][x+1] + grid[y][x+2] +
                    grid[y+1][x+1] +
                    grid[y+2][x] + grid[y+2][x+1] + grid[y+2][x+2];
                maxVal = Math.max(maxVal, val);
            }
        }
        return maxVal;
    }
}

// 20ms 21.27% 53.7MB 75.28%
// partial sum
// O(HW) O(HW)
class Solution {
    public int maxSum(int[][] grid) {
        int maxVal = 0, h = grid.length, w = grid[0].length;
        int[][] gs = new int[h][w-2];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w-2; ++x) {
                gs[y][x] = grid[y][x] + grid[y][x+1] + grid[y][x+2];
            }
        }
        for (int y = 0; y < h - 2; ++y) {
            for (int x = 0; x < w - 2; ++x) {
                maxVal = Math.max(maxVal, gs[y][x] + gs[y+2][x] + grid[y+1][x+1]);
            }
        }
        return maxVal;
    }
}
