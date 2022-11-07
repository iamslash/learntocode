// Copyright (C) 2022 by iamslash

import java.util.*;

// powers:   2 4 64
//     pp: 1 2 8 512

// 64ms 81.29% 134.4MB 29.47%
// bit manipulatin
// O(N) O(N)
class Solution {
    public int[] productQueries(int n, int[][] queries) {
        int MOD = 1_000_000_007;
        List<Integer> powerList = new ArrayList<>();
        for (int i = 0; i < 32; ++i) {
            if ((n & (1 << i)) > 0) {
                powerList.add(1 << i);
            }
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int beg = queries[i][0], end = queries[i][1];
            long prod = 1;
            for (int j = beg; j <= end; ++j) {
                prod = prod * powerList.get(j) % MOD;
            }
            ans[i] = (int)prod;
        }
        return ans;
    }
}
