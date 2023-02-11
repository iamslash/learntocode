// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: iterative dynamic programming, siding window
//
// C[i] is max prize count of k-len window until prizePositions[i - 1].
// Find a new window [j..i] then
// ans = max(ans, i - j + 1 + C[j])

// 4ms 99.29% 51.7MB 85.28%
// sliding window, iterative dynamic programming
// O(N) O(N)
class Solution {
    public int maximizeWin(int[] prizePositions, int k) {
        int ans = 0, n = prizePositions.length, j = 0;
        int[] C = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            while (prizePositions[j] < prizePositions[i] - k) {
                j++;
            }
            C[i + 1] = Math.max(C[i], i - j + 1);
            ans = Math.max(ans, i - j + 1 + C[j]);
        }
        return ans;
    }
}
