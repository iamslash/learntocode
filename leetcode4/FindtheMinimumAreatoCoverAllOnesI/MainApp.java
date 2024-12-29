// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea:
// 
// 0 1 0
// 1 0 1
//
// minY: 0
// maxY: 1
// minX: 0
// maxX: 2
//
// area: (maxX - minX + 1) * (maxY - minY + 1)
//       (2 - 0 + 1) * (1 - 0 + 1) = 6

// 5ms 93.06% 196.94MB 37.00%
// matrix
// O(HW) O(1)
class Solution {
    public int minimumArea(int[][] grid) {
        int minY = 1000, maxY = 0;
        int minX = 1000, maxX = 0;
        int h = grid.length, w = grid[0].length;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 1) {
                    minY = Math.min(minY, y);
                    maxY = Math.max(maxY, y);
                    minX = Math.min(minX, x);
                    maxX = Math.max(maxX, x);
                }
            }
        }

        return (maxX - minX + 1) * (maxY - minY + 1);        
    }
}
