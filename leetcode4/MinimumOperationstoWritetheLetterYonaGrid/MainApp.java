// Copyright (C) 2024 by iamslash

import java.util.*;

// // 11ms 50.00% 45.2MB 100.00%
// // brute force
// // O(N^2) O(1)
// class Solution {
//     private int getOps(int[][] grid, int y, int z) {
//         int n = grid.length, cnt = 0;

//         for (int r = 0; r < n; ++r) {
//             for (int c = 0; c < n; ++c) {
//                 // Y zone
//                 if ((r <= n/2 && (r == c || r + c == n - 1)) ||
//                     (r > n/2 && c == n/2)) {
//                     if (grid[r][c] != y) {
//                         cnt++;
//                     }
//                 } else {
//                     if (grid[r][c] != z) {
//                         cnt++;
//                     }
//                 }
//             }
//         }

//         return cnt;
//     }
            
//     public int minimumOperationsToWriteY(int[][] grid) {
//         int n = grid.length, ans = n * n;
//         for (int y = 0; y < 3; ++y) {
//             for (int z = 0; z < 3; ++z) {
//                 if (y != z) {
//                     ans = Math.min(ans, getOps(grid, y, z));
//                 }
//             }
//         }
//         return ans;
//     }
// }

// 1ms 100.00% 45.2MB 50.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int n = grid.length;
        int[] ys = new int[3];
        int[] zs = new int[3];

        // Top of Y
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || j == n - i - 1) {
                    ys[grid[i][j]]++;
                } else {
                    zs[grid[i][j]]++;
                }
            }
        }
        // Bottom of Y
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == n / 2) {
                    ys[grid[i][j]]++;
                } else {
                    zs[grid[i][j]]++;
                }
            }
        }
        int ans = n * n;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    continue;
                }
                ans = Math.min(ans, n * n - ys[i] - zs[j]);
            }
        }
        return ans;
    }
}
