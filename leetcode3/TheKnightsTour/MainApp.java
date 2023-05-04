// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: backtracking
//
// . o . o .
// o . . . o
// . . * . .
// o . . . o
// . o . o .

// 61ms 100.00% 40.6MB 100.00%
// backtracking
// O(8^N) O(N)
class Solution {
    private boolean dfs(int[][] board, int y, int x, int ord) {
        // System.out.printf("y: %d, x: %d, ord: %d\n", y, x, ord);
        int h = board.length, w = board[0].length, n = h * w;
        // base
        if (y < 0 || y >= h || x < 0 || x >= w || board[y][x] >= 0) {
            return false;
        }
        board[y][x] = ord;
        if (ord == n - 1) {
            return true;
        }
        // recursion
        if (dfs(board, y-2, x-1, ord + 1) || dfs(board, y-1, x-2, ord + 1) ||
            dfs(board, y+1, x-2, ord + 1) || dfs(board, y+2, x-1, ord + 1) ||
            dfs(board, y+2, x+1, ord + 1) || dfs(board, y+1, x+2, ord + 1) ||
            dfs(board, y-1, x+2, ord + 1) || dfs(board, y-2, x+1, ord + 1)) {
            return true;
        }
        board[y][x] = -1;
        return false;
    }
    public int[][] tourOfKnight(int m, int n, int r, int c) {
        int[][] board = new int[m][n];
        for (int i = 0; i < m; ++i) {
            Arrays.fill(board[i], -1);
        }
        dfs(board, r, c, 0);
        return board;
    }
}
