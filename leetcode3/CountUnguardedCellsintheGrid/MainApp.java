// Copyright (C) 2022 by iamslash

import java.util.*;

// 30ms 100.00% 124.1MB 50.00%
// brute force
// O(HW) O(1)
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[] dirs = new int[]{-1, 0, 1, 0, -1};
        char[][] board = new char[m][n];
        for (int[] wall : walls) {
            board[wall[0]][wall[1]] = 'W';
        }
        for (int[] guard : guards) {
            board[guard[0]][guard[1]] = 'G';
        }
        for (int[] guard : guards) {
            for (int i = 0; i < 4; ++i) {
                int y = guard[0] + dirs[i];
                int x = guard[1] + dirs[i+1];
                while (y >= 0 && y < m && x >=0 && x < n &&
                       board[y][x] != 'W' && board[y][x] != 'G') {
                    board[y][x] = '.';
                    y += dirs[i];
                    x += dirs[i+1];
                }
            }
        }
        int cnt = 0;
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (board[y][x] == 0) {
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
