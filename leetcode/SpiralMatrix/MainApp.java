// Copyright (C) 2024 by iamslash

import java.util.*;

// Keywords:
// dy, dx, ys, ye, xs, xe

// 0ms 100.00% 41.9MB 6.53%
// Brute force
// O(HW) O(N)
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();

        int h = matrix.length, w = matrix[0].length;
        int y = 0, x = 0, dy = 0, dx = 1;
        int ys = 0, ye = h, xs = 0, xe = w;

        while (y >= ys && y < ye && x >= xs && x < xe) {
            ans.add(matrix[y][x]);
            
            // set dy, dx, xs, xe, ys, ye
            if (dy == 0 && dx == 1 && x == xe - 1) {
                dy = 1;
                dx = 0;
                ys += 1;
            } else if (dy == 1 && dx == 0 && y == ye - 1) {
                dy = 0;
                dx = -1;
                xe -= 1;
            } else if (dy == 0 && dx == -1 && x == xs) {
                dy = -1;
                dx = 0;
                ye -= 1;
            } else if (dy == -1 && dx == 0 && y == ys) {
                dy = 0;
                dx = 1;
                xs += 1;
            }

            y = y + dy;
            x = x + dx;
        }
        
        return ans;
    }
}
