// Copyright (C) 2025 by iamslash

import java.util.*;

// 123ms 100.00% 56.34B 100.00%
// hash map
//   setCell: O(1) O(N)
// resetCell: O(1) O(N)
//  getValue: O(1) O(N)
class Spreadsheet {
    int[][] data;

    public Spreadsheet(int rows) {
        data = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        int x = cell.charAt(0) - 'A';
        int y = Integer.valueOf(cell.substring(1)) - 1;

        data[y][x] = value;
    }
    
    public void resetCell(String cell) {
        int x = cell.charAt(0) - 'A';
        int y = Integer.valueOf(cell.substring(1)) - 1;

        data[y][x] = 0;
    }
    
    public int getValue(String formula) {
        String[] terms = formula.substring(1).split("\\+");
        return getTermVal(terms[0]) + getTermVal(terms[1]);
    }

    private int getTermVal(String cell) {
        if (cell.charAt(0) >= '0' && cell.charAt(0) <= '9') {
            return Integer.valueOf(cell);
        }
        
        int x = cell.charAt(0) - 'A';
        int y = Integer.valueOf(cell.substring(1)) - 1;
        // System.out.printf("cell: %s, y: %d, x: %d\n", cell, y, x);
        return data[y][x];
    }

}
