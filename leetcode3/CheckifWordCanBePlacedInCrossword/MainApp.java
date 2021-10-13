// Copyright (C) 2021 by iamslash

import java.util.*;

// 5ms 83.98% 68.5MB 60.62%
// brute force
// O(HWS) O(1)
class Solution {
    private boolean inside(char[][] board, int y, int x) {
        return y >= 0 && y < board.length && x >= 0 && x < board[0].length;
    }
    public boolean placeWordInCrossword(char[][] board, String word) {
        int h = board.length, w = board[0].length;
        int dir[] = {-1, 0, 1, 0, -1};
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                // Check starting point
                if (board[y][x] != ' ' && board[y][x] != word.charAt(0)) {
                    continue;
                }
                // Check each direction
                for (int i = 0; i < 4; ++i) {
                    int dy = dir[i], dx = dir[i+1];
                    int ny = y, nx = x, idx = 0;
                    // Check opposite position from the starting position
                    if (inside(board, ny - dy, nx - dx) &&
                        board[ny - dy][nx - dx] != '#') {
                        continue;
                    }
                    while (idx < word.length() && inside(board, ny, nx)) {
                        if (board[ny][nx] == '#' ||
                            (board[ny][nx] != ' ' && board[ny][nx] != word.charAt(idx))) {
                            break;
                        }
                        ++idx;
                        ny += dy;
                        nx += dx;
                    }
                    // Check end position
                    if (idx == word.length() &&
                        (!inside(board, ny, nx) || board[ny][nx] == '#')) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
