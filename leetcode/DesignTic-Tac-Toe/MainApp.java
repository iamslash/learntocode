// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 100.00% 44.8MB 79.14%
// hash map
// O(1) O(N)
class TicTacToe {
    private int[] rows;
    private int[] cols;
    private int ldiag;
    private int rdiag;

    public TicTacToe(int n) {
        rows = new int[n];
        cols = new int[n];
    }
    
    public int move(int row, int col, int player) {
        int cell = player == 1 ? 1 : -1;
        rows[row] += cell;
        cols[col] += cell;
        if (row == col) {
            ldiag += cell;
        }
        if (col == (cols.length - row - 1)) {
            rdiag += cell;
        }
        int n = rows.length;
        if (Math.abs(rows[row]) == n ||
            Math.abs(cols[col]) == n ||
            Math.abs(ldiag) == n ||
            Math.abs(rdiag) == n) {
            return player;
        }
        return 0;
    }
}
