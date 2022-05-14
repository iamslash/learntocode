// Copyright (C) 2022 by iamslash

import java.util.*;


// 1 2 3
// 1 5 1
// 3 1 1

// Time Limit Exceeded
class Solution {
    public long maxPoints(int[][] points) {
        int h = points.length, w = points[0].length;
        long[][] C = new long[h+1][w];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                C[y][x] = points[y][x];
            }
        }
        long maxPt = 0;
        for (int y = h-1; y >= 0; --y) {
            for (int x = 0; x < w; ++x) {
                long orgPt = C[y][x], maxDelta = 0;
                for (int z = 0; z < w; ++z) {
                    maxDelta = Math.max(maxDelta, C[y+1][z] - Math.abs(z - x));
                }
                C[y][x] = orgPt + maxDelta;
                maxPt = Math.max(maxPt, C[y][x]);
            }
        }
        return maxPt;
    }
}

// 13ms 62.94% 85.1MB 78.22%
// iterative dynamic programming
// O(HW) O(W)
class Solution {
    public long maxPoints(int[][] points) {
        int h = points.length, w = points[0].length;
        long[] prevCols = new long[w];
        for (int i = 0; i < w; ++i) {
            prevCols[i] = points[0][i];
        }
        for (int y = 0; y < h - 1; ++y) {
            long[] lft = new long[w], rgt = new long[w], cur = new long[w];
            lft[0] = prevCols[0];
            rgt[w-1] = prevCols[w-1];
            for (int x = 1; x < w; ++x) {
                lft[x] = Math.max(lft[x-1] - 1, prevCols[x]);
            }
            for (int x = w-2; x >= 0; --x) {
                rgt[x] = Math.max(rgt[x+1] - 1, prevCols[x]);
            }
            for (int x = 0; x < w; ++x) {
                cur[x] = points[y+1][x] + Math.max(lft[x], rgt[x]);
            }
            prevCols = cur;
        }
        long ans = 0;
        for (int x = 0; x < w; ++x) {
            ans = Math.max(ans, prevCols[x]);
        }
        return ans;
    }
}
