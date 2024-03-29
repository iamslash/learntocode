// Copyright (C) 2024 by iamslash

import java.util.*;

// 5ms 75.11% 45.8MB 5.49%
// brute force
// O(HW) O(HW)
class Solution {
    private int avg(int[][] img, int row, int col) {
        int h = img.length, w = img[0].length;
        int sum = 0, cnt = 0;
        for (int y = row - 1; y < row + 2; ++y) {
            for (int x = col - 1; x < col + 2; ++x) {
                if (y >= 0 && y < h && x >= 0 && x < w) {
                    sum += img[y][x];
                    cnt++;
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
