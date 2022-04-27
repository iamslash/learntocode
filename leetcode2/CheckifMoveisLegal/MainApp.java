// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 76.92% 43.1MB 41.54%
// brute force
// O(N) O(1)
class Solution {
    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        int[][] dirs = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        char op = color == 'W' ? 'B' : 'W';
        for (int i = 0; i < 8; ++i) {
            int y = rMove + dirs[i][0];
            int x = cMove + dirs[i][1];
            int cnt = 1;
            while (y >= 0 && y < 8 && x >= 0 && x < 8 && board[y][x] != '.') {
                if (cnt > 1 && board[y][x] == color) {
                    return true;
                }
                if (board[y][x] != op) {
                    break;
                }
                y += dirs[i][0];
                x += dirs[i][1];
                cnt++;
            }
        }
        return false;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
