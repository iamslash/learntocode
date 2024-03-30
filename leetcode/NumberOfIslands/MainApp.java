// Copyright (C) 2024 by iamslash

import java.util.*;

// 3ms 86.52% 49.5MB 49.88%
// dfs
// O(N) O(N)
class Solution {
    int[] dirs = {-1, 0, 1, 0, -1};
    private void dfs(char[][] grid, int y, int x) {
        int h = grid.length, w = grid[0].length;
        grid[y][x] = '0';
        
        // recursion
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i], nx = x + dirs[i + 1];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && grid[ny][nx] == '1') {
                dfs(grid, ny, nx);
            }
        }
    }
    
    public int numIslands(char[][] grid) {
        int cnt = 0, h = grid.length, w = grid[0].length;

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
