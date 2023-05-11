// Copyright (C) 2023 by iamslash

import java.util.*;

// 9ms 100.00% 62.3MB 55.81%
// pattern
// O(N^2) O(N)
class Solution {
    public int[][] colorRed(int n) {
        List<int[]> ans = new ArrayList<>();
        // Build 4 rows pattern from the bottom
        for (int i = n; i - 4 >= 0; i -= 4) {
            for (int j = 1; j <= 2 * i - 1; j += 2) {
                ans.add(new int[]{i, j});                
            }
            ans.add(new int[]{i - 1, 2});
            for (int j = 2 * (i - 2) - 1; j > 2; j -= 2) {
                ans.add(new int[]{i - 2, j});
            }
            ans.add(new int[]{i - 3, 1});
        }
        // Build rest pattern
        int m = n % 4;
        if (m >= 1) {
            ans.add(new int[]{1, 1});
        }
        if (m >= 2) {
            ans.add(new int[]{2, 1});
            ans.add(new int[]{2, 3});
        }
        if (m >= 3) {
            ans.add(new int[]{3, 1});
            ans.add(new int[]{3, 5});            
        }
        return ans.toArray(new int[0][]);
    }
}
