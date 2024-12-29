// Copyright (C) 2024 by iamslash

import java.util.*;


// 1 0 0    
// 0 0 0    
// 0 0 1    
//

// 19ms 7.41% 108.88MB 79.37%
// matrix
// O(HW) O(1)
class Solution {
    public int minFlips(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int rowCnt = 0, colCnt = 0;
        int halfH = h / 2, halfW = w / 2;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < halfW; ++x) {
                if (grid[y][x] != grid[y][w - 1 - x]) {
                    rowCnt++;
                }
            }
        }

        for (int y = 0; y < halfW; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] != grid[h - 1 - y][x]) {
                    colCnt++;
                }
            }
        }

        // System.out.printf("%d %d\n", rowCnt, colCnt);

        return Math.min(rowCnt, colCnt);        
    }
}


// Idea: cache locality
// 5ms 97.88% 111.80MB 24.87%
// matrix
// O(HW) O(1)
class Solution {
    public int minFlips(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int rowCnt = 0, colCnt = 0;
        int halfH = h / 2, halfW = w / 2;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < halfW; ++x) {
                if (grid[y][x] != grid[y][w - 1 - x]) {
                    rowCnt++;
                }
            }
        }

        for (int y = 0; y < halfH; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] != grid[h - 1 - y][x]) {
                    colCnt++;
                }
            }
        }

        // System.out.printf("%d %d\n", rowCnt, colCnt);

        return Math.min(rowCnt, colCnt);        
    }
}
