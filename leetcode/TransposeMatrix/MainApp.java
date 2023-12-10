// Copyright (C) 2023 by iamslash

import java.util.*;

// 0ms 100.00% 44.4MB 59.30%
// matrix
// O(HW) O(HW)
class Solution {
    public int[][] transpose(int[][] matrix) {
        int h = matrix.length, w = matrix[0].length;
        int[][] ans = new int[w][h];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                ans[x][y] = matrix[y][x];
            }
        }
        return ans;
    }
}
