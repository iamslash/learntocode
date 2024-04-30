// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: math
//
// Can make triagles around `@` with multiplying
// the number of rows and the number of columns.
//
// 0 1 0
// 1 @ 1
// 0 1 0
//
// 2 * 2 = 4

// 16ms 67.32% 146.2MB 73.52%
// math
// O(HW) O(max(H, W))
class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[] rows = new int[h];
        int[] cols = new int[w];
        long cnt = 0;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 1) {
                    rows[y]++;
                    cols[x]++;
                }
            }
        }

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 1) {
                    cnt += (rows[y] - 1) * (cols[x] - 1);
                }
            }
        }

        return cnt;
    }
}
