// Copyright (C) 2023 by iamslash

import java.util.*;

// 4ms 95.88% 44.5MB 64.42%
// brute foce
// O(HW) O(HW)
class Solution {
    private int avg(int[][] grid, int y, int x) {
        int h = grid.length, w = grid[0].length;
        int cnt = 0, sum = 0;
        for (int i = y - 1; i <= y + 1; ++i) {
            for (int j = x - 1; j <= x + 1; ++j) {
                if (i >= 0 && i < h && j >= 0 && j < w) {
                    cnt++;
                    sum += grid[i][j];
                }
            }
        }
        return sum / cnt;
    }
    public int[][] imageSmoother(int[][] img) {
        int h = img.length, w = img[0].length;
        int[][] ans = new int[h][w];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                ans[y][x] = avg(img, y, x);
            }
        }
        return ans;
    }
}
