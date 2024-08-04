// Copyright (C) 2024 by iamslash

import java.util.*;

// grid:
//
// 0 1 2
// 3 4 5
// 6 7 8

// 16ms 50.00% 45.4MB 100.00%
// hash map
// O(N) O(N)
class neighborSum {

    Map<Integer, Integer> valPosMap = new HashMap<>();
    int[][] data = null;

    public neighborSum(int[][] grid) {
        int n = grid.length;
        
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                valPosMap.put(grid[y][x], y * 100 + x);
            }
        }

        data = grid;
    }
    
    public int adjacentSum(int val) {
        int n = data.length;
        int pos = valPosMap.get(val), sum = 0;
        int y = pos / 100, x = pos % 100;

        if (y >= 1) {
            sum += data[y - 1][x];
        }

        if (x < n - 1) {
            sum += data[y][x + 1];
        }

        if (y < n - 1) {
            sum += data[y + 1][x];
        }

        if (x >= 1) {
            sum += data[y][x - 1];
        }
        
        return sum;
    }
    
    public int diagonalSum(int val) {
        int n = data.length;
        int pos = valPosMap.get(val), sum = 0;
        int y = pos / 100, x = pos % 100;

        if (y >= 1 && x < n - 1) {
            sum += data[y - 1][x + 1];
        }

        if (y < n - 1 && x < n - 1) {
            sum += data[y + 1][x + 1];
        }

        if (y < n - 1 && x >= 1) {
            sum += data[y + 1][x - 1];
        }

        if (y >= 1 && x >= 1) {
            sum += data[y - 1][x - 1];
        }
        
        return sum;
        
    }
}
