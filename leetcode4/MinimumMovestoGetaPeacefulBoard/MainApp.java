// Copyright (C) 2024 by iamslash

import java.util.*;

// rooks: 0,0 0,1 0,2 0,3
//                    x
//        0,0 0,1 0,2 0,3
//          y
//        0,0 0,1 0,2 0,3

// 17ms 7.14% 45.06MB 35.71%
// sort
// O(NlgN) O(1)
class Solution {
    public int minMoves(int[][] rooks) {
        int cost = 0, n = rooks.length;

        Arrays.sort(rooks, (a, b) -> a[0] - b[0]);
        for (int x = 0; x < n; ++x) {
            cost += Math.abs(x - rooks[x][0]);
        }

        Arrays.sort(rooks, (a, b) -> a[1] - b[1]);
        for (int y = 0; y < n; ++y) {
            cost += Math.abs(y - rooks[y][1]);
        }

        return cost;
    }
}

// rooks: 0,0 0,1 0,2 0,3
//  rows: 4 0 0 0
//  cols: 1 1 1 1

// Idea:
//
// rooks: 0,0 0,1 0,2 0,3
//  rows: 4 0 0 0
//  cols: 1 1 1 1
//
// 4 0 0 0
// 1 3 0 0    3
// 1 1 2 0    2
// 1 1 1 1    1
//
// 1 1 1 1    0
//
// The answer is 3 + 2 + 1 = 6

// 1ms 100.00% 44.85MB 57.14%
class Solution {
    
    private int oneDim(int[] rooks) {
        int excess = 0, moves = 0;

        for (int rook : rooks) {
            moves += Math.abs(excess);
            excess += (rook - 1);
        }

        return moves;
    }
    
    public int minMoves(int[][] rooks) {
        int n = rooks.length;
        int[] rows = new int[n];
        int[] cols = new int[n];

        for (int[] rook: rooks) {
            rows[rook[0]] += 1;
            cols[rook[1]] += 1;
        }

        return oneDim(rows) + oneDim(cols);
    }
}
