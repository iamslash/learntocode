// Copyright (C) 2023 by iamslash

import java.util.*;

// grid:
// 1 2
// 3 4
//
// ans:
// 24 12
//  8  6
//
// pre: 6
// suf: 24

// 11ms 89.85% 71.4MB 71.88%
// brute force
// O(HW) O(HW)
class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        long pre = 1, suf = 1, mod = 12345;
        int h = grid.length, w = grid[0].length;
        int[][] ans = new int[h][w];
        for (int y = 0; y < h; ++y) {
            if (y <= h - y - 1) {
                Arrays.fill(ans[y], 1);
                Arrays.fill(ans[h - y - 1], 1);
            }
            for (int x = 0; x < w; ++x) {
                ans[y][x] = (int)(pre * ans[y][x] % mod);
                ans[h - y - 1][w - x - 1] = (int)(suf * ans[h - y - 1][w - x - 1] % mod);
                pre = pre * grid[y][x] % mod;
                suf = suf * grid[h - y - 1][w - x - 1] % mod;
            }
        }
        return ans;
    }
}
