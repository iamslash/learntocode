// Copyright (C) 2023 by iamslash

import java.util.*;

// grid:
// 0 1
// 0 0

// grid:
// 0 0 1
// 1 0 1
// 0 0 0

// 1ms 100.00% 43.7MB 100.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int findChampion(int[][] grid) {
        int n = grid.length;
        for (int y = 0; y < n; ++y) {
            int oneCnt = 0;
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == 1) {
                    oneCnt++;
                }
            }
            if (oneCnt == n - 1) {
                return y;
            }
        }
        return -1;
    }
}
