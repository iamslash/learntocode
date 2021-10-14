// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 61.99% 47.2MB 63.35%
// DFS
// O(N) O(N)
class Solution {
    private int[] dir = new int[]{-1, 0, 1, 0, -1};
    private int dfs(char[][] grid, int y, int x) {
        // base
        grid[y][x] = '0';
        int h = grid.length, w = grid[0].length;
        // recursion
        for (int i = 0; i < 4; ++i) {
            int ny = y + dir[i], nx = x + dir[i+1];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || grid[ny][nx] == '0') {
                continue;
            }
            dfs(grid, ny, nx);
        }
    }
    public int numIslands(char[][] grid) {
        int h = grid.length, w = grid[0].length, cnt = 0;
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
