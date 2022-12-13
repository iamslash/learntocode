// Copyright (C) 2022 by iamslash

import java.util.*;

// 14ms 30.24% 46.2MB 73.98%
// sort
// O(HWlgW) O(W)
class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[] maxCols = new int[w];
        for (int y = 0; y < h; ++y) {
            Arrays.sort(grid[y]);
        }
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                maxCols[x] = Math.max(maxCols[x], grid[y][x]);
            }
        }
        int ans = 0;
        for (int x = 0; x < w; ++x) {
            ans += maxCols[x];
        }
        return ans;
    }
}
