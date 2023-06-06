// Copyright (C) 2023 by iamslash

import java.util.*;

// // Memory Limit Exceeded
// // brute foce
// // O(HW) O(HW)
// class Solution {
//     public long matrixSumQueries(int n, int[][] queries) {
//         int[][] grid = new int[n][n];
//         for (int[] query : queries) {
//             if (query[0] == 0) {
//                 for (int x = 0; x < n; ++x) {
//                     grid[query[1]][x] = query[2];
//                 }
//             } else {
//                 for (int y = 0; y < n; ++y) {
//                     grid[y][query[1]] = query[2];
//                 }
//             }
//         }
//         long sum = 0;
//         for (int y = 0; y < n; ++y) {
//             for (int x = 0; x < n; ++x) {
//                 sum += grid[y][x];
//             }
//         }
//         return sum;
//     }
// }

// n: 3
//        i
// q: 0,0,1 1,2,2 0,2,3 1,0,4
//
// 4 1 2
// 4 0 2
// 4 3 3
//
// seen: f f t
//       t f t
// cnts: 2 1
//
//  sum: 12 + 6 + 4 

// Idea: greedy
//
// Last query covers old query.
//
// seen[2][n]: covered for rows, cols?
// cnts[2]: count of uncovered cell for row, col.
//
// Whenever seen[0][y] = true, decrease cnts[1].
// Whenever seen[1][x] = true, decrease cnts[0].
// cnts[0]: how many cells we can fill with the value at a row.
// cnts[1]: how many cells we can fill with the value at a column.

// 5ms 100.00% 61.1MB 94.04%
// greedy
// O(Q) O(N)
class Solution {
    public long matrixSumQueries(int n, int[][] queries) {
        long sum = 0;
        boolean[][] seen = new boolean[2][n];
        int[] cnts = new int[]{n, n};
        for (int i = queries.length - 1; i >= 0; --i) {
            int type = queries[i][0], idx = queries[i][1], val = queries[i][2];
            if (!seen[type][idx]) {
                seen[type][idx] = true;
                cnts[type]--;
                sum += (long)cnts[1 - type] * val;
            }
        }
        return sum;
    }
}
