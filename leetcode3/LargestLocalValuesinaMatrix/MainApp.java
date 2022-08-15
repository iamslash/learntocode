// Copyright (C) 2022 by iamslash

import java.util.*;

// 5ms 25.00% 52MB 50.00%
// matrix
// O(HW) O(HW)
class Solution {
    private int maxVal(int[][] grid, int r, int c) {
        int ans = 0;
        for (int y = r-1; y <= r+1; ++y) {
            for (int x = c-1; x <= c+1; ++x) {
                // System.out.printf("%d ", grid[y][x]);
                ans = Math.max(ans, grid[y][x]);
            }
        }
        // System.out.println();
        return ans;
    }
    public int[][] largestLocal(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[][] ans = new int[h-2][w-2];
        for (int y = 1; y < h-1; ++y) {
            for (int x = 1; x < w-1; ++x) {
                ans[y-1][x-1] = maxVal(grid, y, x);
            }
        }
        return ans;
    }
}
