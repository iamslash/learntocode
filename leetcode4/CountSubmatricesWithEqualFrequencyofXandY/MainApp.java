// Copyright (C) 2025 by iamslash

import java.util.*;


// grid:
//
// X Y .
// Y . .
//
// cnt: 3

// grid:
//
// X X Y
// Y Y Y
// Y Y Y
//
// cnt: 0

// 20ms 68.42% 131.11MB 36.84%
// grid sum
// O(HW) O(HW)
class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int h = grid.length, w = grid[0].length, cnt = 0;
        int[][] xCnts = new int[h + 1][w + 1];
        int[][] yCnts = new int[h + 1][w + 1];

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                xCnts[y + 1][x + 1] = xCnts[y][x + 1] + xCnts[y + 1][x] - xCnts[y][x];
                xCnts[y + 1][x + 1] += grid[y][x] == 'X' ? 1 : 0;
                yCnts[y + 1][x + 1] = yCnts[y][x + 1] + yCnts[y + 1][x] - yCnts[y][x];
                yCnts[y + 1][x + 1] += grid[y][x] == 'Y' ? 1 : 0;

                if (xCnts[y + 1][x + 1] == yCnts[y + 1][x + 1] &&
                    xCnts[y + 1][x + 1] > 0) {
                    cnt++;
                }
            }
        }        

        return cnt;
    }
}
