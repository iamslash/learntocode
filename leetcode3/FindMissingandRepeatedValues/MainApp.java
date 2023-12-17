// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 44.2MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int twiceNum = 0, missingNum = 0;
        int h = grid.length, w = grid[0].length;
        boolean[] exists = new boolean[h * w + 1];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int num = grid[y][x];
                if (exists[num]) {
                    twiceNum = num;
                }
                exists[num] = true;
            }
        }
        for (int i = 1; i < exists.length; ++i) {
            if (!exists[i]) {
                missingNum = i;
                break;
            }
        }
        return new int[]{twiceNum, missingNum};
    }
}
