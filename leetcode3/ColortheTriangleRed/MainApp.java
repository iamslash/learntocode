// Copyright (C) 2023 by iamslash

import java.util.*;

// Wrong Answer for
// input: 4
class Solution {
    public int[][] colorRed(int n) {
        int h = 2 * n - 1;
        int[][] ans = new int[h][2];
        ans[0][0] = 1;
        ans[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i*2 - 1][0] = i + 1;
            ans[i*2 - 1][1] = 1;
            ans[i*2][0] = i + 1;
            ans[i*2][1] = i*2 + 1;
        }
        return ans;
    }
}
