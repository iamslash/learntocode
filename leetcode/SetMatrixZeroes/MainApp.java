// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 78.52% 45MB 98.96%
// brute force
// O(HW) O(MAX(H, W))
class Solution {
    public void setZeroes(int[][] matrix) {
        int h = matrix.length, w = matrix[0].length;
        boolean[] rows = new boolean[h];
        boolean[] cols = new boolean[w];

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (matrix[y][x] == 0) {
                    rows[y] = true;
                    cols[x] = true;
                }
            }
        }

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (rows[y] || cols[x]) {
                    matrix[y][x] = 0;
                }
            }
        }
    }
}
