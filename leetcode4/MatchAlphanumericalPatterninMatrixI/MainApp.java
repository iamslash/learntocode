// Copyright (C) 2024 by iamslash

import java.util.*;

// 17ms 50.00% 45.7MB 42.86%
// brute force
// O(HWNM) O(1)
// - H: horizontal length of board
// - W: vertical length of board
// - N: horizontal length of pattern
// - M: vertical length of pattern
class Solution {

    private boolean match(int[][] board, String[] pattern,
                          int y, int x) {
        int h = pattern.length, w = pattern[0].length();
        Map<Integer, Integer> cellMap = new HashMap<>();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int a = board[y + i][x + j];
                int b = pattern[i].charAt(j) - '0';
                if (Character.isDigit(pattern[i].charAt(j))) {
                    if (a != b) {
                        return false;
                    }
                } else {
                    if ((cellMap.containsKey(b) && cellMap.get(b) != a) ||
                        (cellMap.containsKey(a) && cellMap.get(a) != b)) {
                        return false;
                    }
                    cellMap.put(a, b);
                    cellMap.put(b, a);
                }
            }
        }
        return true;
    }
    
    public int[] findPattern(int[][] board, String[] pattern) {
        int h = board.length, w = board[0].length;
        int n = pattern.length, m = pattern[0].length();
        for (int y = 0; y + n - 1 < h; ++y) {
            for (int x = 0; x + m - 1 < w; ++x) {
                if (match(board, pattern, y, x)) {
                    return new int[]{y, x};
                }
            }
        }
        return new int[]{-1, -1};
    }
}
