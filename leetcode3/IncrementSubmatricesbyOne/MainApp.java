// Copyright (C) 2023 by iamslash

import java.util.*;

// 0 0 0    0 0 0      1 0 -
// 0 0 0    0 1 0 -    0 1 0 -
// 0 0 0    0 0 0      - 0 1
//            -   1      -   1
//
// 1 0 -    1 0 -      1 1 0
// 0 1 0    1 1 -      1 2 1
// - 0 1    0 1 0      0 1 1

// 7ms 99.71% 50.8MB 53.23%
// range sum
// O(HW) O(HW)
class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] ans = new int[n][n];
        for (int[] query : queries) {
            int r1 = query[0], c1 = query[1];
            int r2 = query[2], c2 = query[3];
            ans[r1][c1] += 1;
            if (r2 + 1 < n) {
                ans[r2 + 1][c1] -= 1;
            }
            if (c2 + 1 < n) {
                ans[r1][c2 + 1] -= 1;
            }
            if (r2 + 1 < n && c2 + 1 < n) {
                ans[r2 + 1][c2 + 1] += 1;
            }
        }
        for (int y = 1; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                ans[y][x] += ans[y - 1][x];
            }
        }
        for (int y = 0; y < n; ++y) {
            for (int x = 1; x < n; ++x) {
                ans[y][x] += ans[y][x - 1];
            }
        }
        return ans;
    }
}
