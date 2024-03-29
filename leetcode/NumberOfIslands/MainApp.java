// Copyright (C) 2021 by iamslash

import java.util.*;

// 2ms 99.98% 47.1MB 85.86%
// DFS
// O(N) O(N)
class Solution {
    private int[] dirs = new int[]{-1, 0, 1, 0, -1};
    private void dfs(char[][] grid, int y, int x) {
        int h = grid.length, w = grid[0].length;
        // visit
        grid[y][x] = '0';
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i], nx = x + dirs[i+1];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
                grid[ny][nx] != '1') {
                continue;
            }
            dfs(grid, ny, nx);
        }
    }
    public int numIslands(char[][] grid) {
        int h = grid.length, w = grid[0].length;
        int cnt = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == '1') {
                    dfs(grid, y, x);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
