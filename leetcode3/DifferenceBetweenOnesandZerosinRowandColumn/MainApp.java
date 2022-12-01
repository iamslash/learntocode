// Copyright (C) 2022 by iamslash

import java.util.*;

// 31ms 51.21% 144.8MB 77.70%
// brute force
// O(HW) O(HW)
class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[][] diff = new int[h][w];
        int[] rows = new int[h];
        int[] cols = new int[w];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                rows[y] += grid[y][x];
                cols[x] += grid[y][x];
            }
        }
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                diff[y][x] = rows[y] + cols[x] - (h - rows[y]) - (w - cols[x]);                
            }
        }
        return diff;
    }
}
