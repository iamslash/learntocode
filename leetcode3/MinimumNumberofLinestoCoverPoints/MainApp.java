// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea ★
// 0. The number of points is just 10, use Bit Mask. ttl represents
//    all points.
// 1. C[bm] means the number of lines of bm which represents points
// 2. Find points whose C[bm] is 1
// 3. Traverse C[bm]
// 4. return C[ttl]

// 10ms 80.00% 42.9MB 66.36%
// iterative dynamic programming
// O(N^3) O(N)
class Solution {
    public int minimumLines(int[][] points) {
        int n = points.length, ttl = (1 << n) - 1;
        int[] C = new int[ttl + 1];
        Arrays.fill(C, ttl);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int bm = (1 << i) + (1 << j);
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                for (int k = j+1; k < n; ++k) {
                    int ddx = points[i][0] - points[k][0];
                    int ddy = points[i][1] - points[k][1];
                    // points i, j, k are on the same line
                    if (dx * ddy == dy * ddx) {
                        bm |= 1 << k;
                    }
                }
                for (int subBm = bm; subBm > 0; subBm = (subBm - 1) & bm) {
                    C[subBm] = 1;
                }
            }
        }
        for (int i = 0; i <= ttl; ++i) {
            if (C[i] == ttl) {
                for (int j = i & (i - 1); j > 0; j = (j - 1) & i) {
                    C[i] = Math.min(C[i], C[j] + C[i-j]);
                }
            }
        }
        return C[ttl];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
