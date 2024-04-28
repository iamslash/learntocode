// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 41.4MB 50.00%
// brute force
// O(HW) O(1)
class Solution {

    private int maxColCnt(char[][] grid, int r, int c) {
        int wCnt = 0, bCnt = 0;

        for (int y = r; y < r + 2; ++y) {
            for (int x = c; x < c + 2; ++x) {
                if (grid[y][x] == 'W') {
                    wCnt++;
                } else {
                    bCnt++;
                }
            }
        }

        return Math.max(wCnt, bCnt);
    }
    
    public boolean canMakeSquare(char[][] grid) {

        if (maxColCnt(grid, 0, 0) > 2 ||
            maxColCnt(grid, 0, 1) > 2 ||
            maxColCnt(grid, 1, 0) > 2 ||
            maxColCnt(grid, 1, 1) > 2) {
            return true;
        }

        return false;
    }
}
