// Copyright (C) 2022 by iamslash

import java.util.*;

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
        int toAdd = player == 1 ? 1 : -1;
        rows[row] += toAdd;
        cols[col] += toAdd;
        if (row == col) {
            ldiag += toAdd;
        }
        if (col == (cols.length - row - 1)) {
            rdiag += toAdd;
        }
        int len = rows.length;
        if (Math.abs(rows[row]) == len ||
            Math.abs(cols[col]) == len ||
            Math.abs(ldiag) == len ||
            Math.abs(rdiag) == len) {
            return player;
        }
        return 0;
    }
}
