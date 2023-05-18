// Copyright (C) 2023 by iamslash

import java.util.*;

// 13ms 44.72% 50.5MB 93.71%
// recursive dynamic programming
// O(HW) O(HW)
class Solution {
    private int dfs(int[][] grid, int[][] C, int y, int x) {
        int h = grid.length, w = grid[0].length;
        int[][] dirs = new int[][]{{-1, 1}, {0, 1}, {1, 1}};
        // memo
        if (C[y][x] >= 0) {
            return C[y][x];
        }
        // recursion
        int maxCnt = 0;
        for (int i = 0; i < 3; ++i) {
            int ny = y + dirs[i][0], nx = x + dirs[i][1];
            if (ny < 0 || ny >= h || nx >= w || grid[y][x] >= grid[ny][nx]) {
                continue;
            }
            maxCnt = Math.max(maxCnt, 1 + dfs(grid, C, ny, nx));
        }
        return C[y][x] = maxCnt;
    }
    public int maxMoves(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[][] C = new int[h][w];
        for (int i = 0; i < h; ++i) {
            Arrays.fill(C[i], -1);
        }
        int maxCnt = 0;
        for (int y = 0; y < h; ++y) {
            maxCnt = Math.max(maxCnt, dfs(grid, C, y, 0));
        }
        return maxCnt;
    }
}
