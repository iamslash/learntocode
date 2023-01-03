// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: recursive dynamic programming
//
// the number of 1 should be "(h + w - 1) / 2"

// Time Limit Exceeded
// back tracking
// O(HW) O(HW)
class Solution {
    private boolean dfs(int[][] grid, int y, int x, int ones) {
        // base
        int h = grid.length, w = grid[0].length;
        if (y < 0 || y >= h || x < 0 || x >= w || ones < 0) {
            return false;
        }
        if (y == 0 && x == 0) {
            return (ones == 1 && grid[0][0] == 1) ||
                (ones == 0 && grid[0][0] == 0);
        }
        // recursion
        if (grid[y][x] == 0) {
            return dfs(grid, y, x - 1, ones) || dfs(grid, y - 1, x, ones);
        }
        return dfs(grid, y, x - 1, ones - 1) || dfs(grid, y - 1, x, ones - 1);
    }
    public boolean isThereAPath(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        if ((h + w) % 2 == 0) {
            return false;
        }
        return dfs(grid, h - 1, w - 1, (h + w - 1) / 2); 
    }
}

// 56ms 42.53% 72.9MB 21.84%
// recursive dynamic programming
// O(HW) O(HW)
class Solution {
    private boolean[][][] C = new boolean[101][101][100];
    private boolean dfs(int[][] grid, int ones, int y, int x) {
        int h = grid.length, w = grid[0].length;
        // base
        if (y >= h || x >= w || ones > (h + w - 1) / 2 || C[y][x][ones]) {
            return false;
        }
        C[y][x][ones] = true;
        ones += grid[y][x];
        if (y == h - 1 && x == w - 1) {
            return ones == (h + w - 1) / 2;
        }
        // recursion        
        return dfs(grid, ones, y + 1, x) || dfs(grid, ones, y, x + 1); 
    }
    public boolean isThereAPath(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        if ((h + w) % 2 == 0) {
            return false;
        }
        return dfs(grid, 0, 0, 0); 
    }
}
