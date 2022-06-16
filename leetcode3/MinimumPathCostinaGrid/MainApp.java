// Copyright (C) 2022 by iamslash

import java.util.*;

// 7ms 96.26% 121.6MB 49.38%
// iterative dynamic programming
// O(HW^2) O(HW)
class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {
        int h = grid.length, w = grid[0].length;
        int[][] C = new int[h][w];
        for (int x = 0; x < w; ++x) {
            C[0][x] = grid[0][x];
        }
        for (int y = 1; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int locMin = Integer.MAX_VALUE;
                for (int j = 0; j < w; ++j) {
                    locMin = Math.min(locMin, C[y-1][j] + moveCost[grid[y-1][j]][x]);
                }
                C[y][x] = locMin + grid[y][x];
            }
        }
        int glbMin = Integer.MAX_VALUE;
        for (int x = 0; x < w; ++x) {
            glbMin = Math.min(glbMin, C[h-1][x]);
        }                                     
        return glbMin;
    }
}

// 12ms 60.75% 69.1MB 89.23%
// iterative dynamic programming
// O(HW^2) O(W)
class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {
        int h = grid.length, w = grid[0].length;
        int[][] C = new int[2][w];
        C[0] = grid[0].clone();
        for (int y = 1; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int locMin = Integer.MAX_VALUE;
                for (int j = 0; j < w; ++j) {
                    locMin = Math.min(locMin, C[1 - y % 2][j] + moveCost[grid[y-1][j]][x]);
                }
                C[y % 2][x] = locMin + grid[y][x];
            }
        }
        int glbMin = Integer.MAX_VALUE;
        for (int x = 0; x < w; ++x) {
            glbMin = Math.min(glbMin, C[(h-1)%2][x]);
        }                                     
        return glbMin;
    }
}
