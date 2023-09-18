// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: dfs
//
// randomeNess for each group:
//   (totalSum - groupSum) * groupCellCnt 
//
// 33ms 75.00% 66.4MB 34.09%
// dfs
// O(N) O(1)
class Solution {
    private long[] dfs(int[][] grid, int y, int x) {
        int n = grid.length;
        int[] dirs = new int[]{-1, 0, 1, 0, -1};
        // recursion
        long[] rst = new long[]{grid[y][x], 1};
        grid[y][x] = -1;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i], nx = x + dirs[i+1];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || grid[ny][nx] < 0) {
                continue;
            }
            long[] innerRst = dfs(grid, ny, nx);
            rst[0] += innerRst[0];
            rst[1] += innerRst[1];
        }
        return rst;
    }
    public long sumRemoteness(int[][] grid) {
        int n = grid.length;
        long sum = 0;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                sum += Math.max(grid[y][x], 0);
            }
        }
        long randomeNess = 0;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] >= 0) {
                    long[] innerRst = dfs(grid, y, x);
                    // System.out.printf("groupSum: %d, groupCnt: %d\n", innerRst[0], innerRst[1]);
                    randomeNess += (sum - innerRst[0]) * innerRst[1];
                }
            }               
        }
        return randomeNess;
    }
}
