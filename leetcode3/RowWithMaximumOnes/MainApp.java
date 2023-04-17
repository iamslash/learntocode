// Copyright (C) 2023 by iamslash

import java.util.*;

// 6ms 80.00% 44.4MB 20.00%
// brute force
// O(HW) O(1)
class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int maxRow = 0, maxCnt = 0, h = mat.length, w = mat[0].length;
        for (int y = 0; y < h; ++y) {
            int oneCnt = 0;
            for (int x = 0; x < w; ++x) {
                if (mat[y][x] == 1) {
                    oneCnt++;
                }
            }
            if (maxCnt < oneCnt) {
                maxRow = y;
                maxCnt = oneCnt;
            }
        }
        return new int[]{maxRow, maxCnt};
    }
}
