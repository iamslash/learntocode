// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 40.4MB 35.91%
// iterative dynamic programming
// O(MN) O(N)
class Solution {
    public int uniquePaths(int m, int n) {
        int cnt = 0;
        int[] cols = new int[n];
        Arrays.fill(cols, 1);
        
        for (int y = 1; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (x > 0) {
                    cols[x] += cols[x-1];
                }
            }
        }

        return cols[n - 1];
    }
}
