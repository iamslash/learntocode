// Copyright (C) 2024 by iamslash

import java.util.*;

// 102ms 47.89% 71.1MB 26.84%
// grid sum
// O(N) O(N)
class NumMatrix {
    private int[][] gsum = null;

    public NumMatrix(int[][] matrix) {
        int h = matrix.length, w = matrix[0].length;
        gsum = new int[h][w];

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                gsum[y][x] = matrix[y][x];

                if (y > 0) {
                    gsum[y][x] += gsum[y-1][x];
                }

                if (x > 0) {
                    gsum[y][x] += gsum[y][x-1];
                }

                if (y > 0 && x > 0) {
                    gsum[y][x] -= gsum[y-1][x-1];
                }
            }
        }
    }
    
    public int sumRegion(int y1, int x1, int y2, int x2) {
        int sum = gsum[y2][x2];

        if (y1 > 0) {
            sum -= gsum[y1-1][x2];
        }

        if (x1 > 0) {
            sum -= gsum[y2][x1-1];
        }

        if (y1 > 0 && x1 > 0) {
            sum += gsum[y1-1][x1-1];
        }        

        return sum;
    }
}
