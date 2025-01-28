// Copyright (C) 2025 by iamslash

import java.util.*;

// n: 7
// m: 7
// k: 5
//
//    . . . . . _ _
//

// 169ms ??% 63.87MB 50.00%
// recursive dynamic programming
// O(NK) O(NK)
class Solution {
    private int mod = 1_000_000_007;
    private Long[][][] cache;
    
    private long dfs(int n, int m, int k,
                     int pos, int cnt, int prevEven) {
        // base
        if (pos >= n) {
            return cnt == k ? 1 : 0;
        }
        if (cnt > k) {
            return 0;
        }
        
        // memo
        if (cache[pos][cnt][prevEven] != null) {
            return cache[pos][cnt][prevEven];
        }
        
        // recursion
        long evenCase = ((m / 2) * dfs(n, m, k, pos + 1, cnt + prevEven, 1)) % mod;
        long oddCase = ((m + 1) / 2 * dfs(n, m, k, pos + 1, cnt, 0)) % mod;
        cache[pos][cnt][prevEven] = (evenCase + oddCase) % mod;

        return cache[pos][cnt][prevEven];
    }

    public int countOfArrays(int n, int m, int k) {
        cache = new Long[n][k + 1][2];
        return (int)dfs(n, m, k, 0, 0, 0) % mod;
    }
}
