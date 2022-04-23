// Copyright (C) 2022 by iamslash

import java.util.*;

// 5ms 87.10% 43.1MB 85.95%
// two pointers
// O(HW) O(1)
class Solution {
    public int[][] candyCrush(int[][] B) {
        int h = B.length, w = B[0].length;
        while (true) {
            // eliminate phase
            boolean found = false;
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    int val = Math.abs(B[y][x]);
                    if (x + 2 < w && val != 0) {
                        if (val == Math.abs(B[y][x+1]) && 
                            val == Math.abs(B[y][x+2])) {
                            B[y][x] = B[y][x+1] = B[y][x+2] = -val;
                            found = true;
                        }
                    }
                    if (y + 2 < h && val != 0) {
                        if (val == Math.abs(B[y+1][x]) &&
                            val == Math.abs(B[y+2][x])) {
                            B[y][x] = B[y+1][x] = B[y+2][x] = -val;
                            found = true;
                        }
                    }
                }
            }
            if (!found) {
                break;
            }
            // resolve phase
            for (int x = 0; x < w; ++x) {
                int wHead = h - 1;
                for (int rHead = h - 1; rHead >= 0; --rHead) {
                    if (B[rHead][x] > 0) {
                        B[wHead--][x] = B[rHead][x];
                    }
                }
                while (wHead >= 0) {
                    B[wHead--][x] = 0;
                }
            }
        }
        return B;
    }
}
