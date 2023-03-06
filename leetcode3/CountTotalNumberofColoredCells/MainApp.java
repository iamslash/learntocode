// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// prev: 1
// i: 1    prev + 0 * 4    1
//    2    prev + 1 * 4    5
//    3    prev + 2 * 4    13
//    4    prev + 3 * 4    25
//
// S(i) = S(i-1) + 4 * (i-1)

// // 3ms 100.00% 39.5MB 50.00%
// // math
// // O(N) O(1)
// class Solution {
//     public long coloredCells(int n) {
//         long sum = 1;
//         for (int i = 0; i < n; ++i) {
//             sum = sum + 4 * i;
//         }
//         return sum;
//     }
// }

// Idea: math
//
// sum[1..n] = n * (n + 1) / 2
// S(i) = 1 + 4 * (i - 1) * i / 2

// 0ms 100.00% 39.6MB 50.00%
// math
// O(N) O(1)
class Solution {
    public long coloredCells(int n) {
        return 1L + (long)4L * (n - 1) * n / 2;
    }
}
