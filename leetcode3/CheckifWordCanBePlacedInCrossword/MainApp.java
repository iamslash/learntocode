// Copyright (C) 2022 by iamslash

import java.util.*;

// 29ms 41.59% 94.5MB 73.80%
// brute force
// O(HW) O(1)
class Solution {
    private boolean inside(char[][] board, int y, int x) {
        int h = board.length, w = board[0].length;
        return y >= 0 && y < h && x >= 0 && x < w;
    }
    public boolean placeWordInCrossword(char[][] board, String word) {
        int h = board.length, w = board[0].length, n = word.length();
        int dirs[] = {-1, 0, 1, 0, -1};
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (board[y][x] != ' ' && board[y][x] != word.charAt(0)) {
                    continue;
                }
                for (int i = 0; i < 4; ++i) {
                    int dy = dirs[i], dx = dirs[i+1];
                    int ny = y, nx = x, idx = 0;
                    int ey = y + dy * n, ex = x + dx * n;
                    // Check opposite position from the starting position
                    if (inside(board, ny - dy, nx - dx) &&
                        board[ny - dy][nx - dx] != '#') {
                        continue;
                    }
                    while (idx < word.length() &&
                           inside(board, ny, nx)) {
                        if (board[ny][nx] == '#' ||
                            (board[ny][nx] != ' ' &&
                             board[ny][nx] != word.charAt(idx))) {
                            break;
                        }
                        idx++;
                        ny += dy;
                        nx += dx;
                    }
                    if (idx == word.length() &&
                        (!inside(board, ny, nx) ||
                         board[ny][nx] == '#')) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
