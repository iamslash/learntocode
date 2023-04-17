// Copyright (C) 2023 by iamslash

import java.util.*;

// 6ms 100.00% 44.1MB 100.00%
// brute force
// O(HW) O(H)
class Solution {
    public int[] findColumnWidth(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[] ans = new int[w];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int len = Integer.toString(grid[y][x]).length();
                if (ans[x] < len) {
                    ans[x] = len;
                }
            }
        }
        return ans;
    }
}
