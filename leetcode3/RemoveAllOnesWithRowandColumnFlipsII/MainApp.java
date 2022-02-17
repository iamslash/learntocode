// Copyright (C) 2022 by iamslash

import java.util.*;

// 1 1 1
// 1 1 1
// 0 1 0

// 0 0 1
// 0 1 0
// 0 1 1
// 1 1 0
// 1 0 1

// 1 0 0 1 1
// 1 1 0 0 0
// 1 0 0 0 1

// 2ms 100.00% 41.8MB 100.00
// back tracking
// O(HW) O(1)
class Solution {
    public int removeOnes(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int cnt = Integer.MAX_VALUE;
        int[] cols = new int[h], rows = new int[w];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 0) {
                    continue;
                }
                for (int r = 0; r < h; ++r) {
                    cols[r] = grid[r][x];
                    grid[r][x] = 0;
                }
                for (int c = 0; c < w; ++c) {
                    rows[c] = grid[y][c];
                    grid[y][c] = 0;
                }
                cnt = Math.min(cnt, 1 + removeOnes(grid));
                for (int c = 0; c < w; ++c) {
                    grid[y][c] = rows[c];
                }
                for (int r = 0; r < h; ++r) {
                    grid[r][x] = cols[r];
                }
            }
        }
        return cnt == Integer.MAX_VALUE ? 0 : cnt;
    }
}
