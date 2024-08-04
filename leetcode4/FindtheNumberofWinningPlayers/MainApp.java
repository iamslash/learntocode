// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 45.2MB 100.00%
// brute force
// O(HW) O(N)
class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int ans = 0;
        int[][] cnts = new int[n][11];

        for (int[] item : pick) {
            int userid = item[0], color = item[1];
            cnts[userid][color]++;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 10; ++j) {
                if (i < cnts[i][j]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
}
