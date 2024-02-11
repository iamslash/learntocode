// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 45.4MB 50.00%
// brute force
// O(N) O(N)
class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        int h = matrix.length, w = matrix[0].length;
        int[] cols = new int[w];
        Arrays.fill(cols, -1);
        List<int[]> tgtList = new ArrayList<>();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (matrix[y][x] == -1) {
                    tgtList.add(new int[]{y, x});
                } else {
                    cols[x] = Math.max(cols[x], matrix[y][x]);                
                }
            }
        }

        for (int[] tgt : tgtList) {
            int y = tgt[0], x = tgt[1];
            matrix[y][x] = cols[x];
        }

        return matrix;
    }
}
