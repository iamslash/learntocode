// Copyright (C) 2023 by iamslash

import java.util.*;

// 649ms 7.78% 40.9MB 82.33%
// backtracking
// O(1) O(1)
class Solution {
    public int minimumMoves(int[][] grid) {
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        if (cnt == 9) {
            return 0;
        }
        int ans = 1_000_000_000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int y = 0; y < 3; ++y) {
                    for (int x = 0; x < 3; ++x) {
                        if (grid[i][j] == 0 && grid[y][x] > 1) {
                            grid[i][j]++;
                            grid[y][x]--;
                            int verDist = Math.abs(i - y), horDist = Math.abs(j - x);                            
                            ans = Math.min(ans, verDist + horDist + minimumMoves(grid));
                            grid[y][x]++;
                            grid[i][j]--;
                        }
                    }
                }
            }
        }
        return ans;
    }
}
