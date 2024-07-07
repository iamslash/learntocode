// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 43.8MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int n = colors.length, cnt = 0;
        int col0 = colors[n-2];
        int col1 = colors[n-1];

        for (int i = 0; i < n; ++i) {
            int col2 = colors[i];

            if (col0 == col2 && col0 != col1) {
                cnt++;
            }

            col0 = col1;
            col1 = col2;
        }

        return cnt;
    }
}
