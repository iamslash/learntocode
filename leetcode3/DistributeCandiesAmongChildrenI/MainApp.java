// Copyright (C) 2023 by iamslash

import java.util.*;


// .
// 1 1 1 1 1

// 12ms 20.00% 39.6MB 40.00%
// brute force
// O(N^3) O(1)
class Solution {
    public int distributeCandies(int n, int limit) {
        int cnt = 0, bnd = Math.min(n, limit);
        for (int i = 0; i <= bnd; ++i) {
            for (int j = 0; j <= bnd; ++j) {
                for (int k = 0; k <= bnd; ++k) {
                    if (i + j + k == n) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
}

// 1ms 100.00% 39.8MB 20.00%
// math
// O(N) O(1)
class Solution {
    public int distributeCandies(int n, int limit) {
        int cnt = 0, bnd = Math.min(n, limit);        
        for (int a = 0; a <= bnd; ++a) {
            int minBCnt = Math.max(0, n - a - limit);
            int maxBCnt = Math.min(limit, n - a);
            if (minBCnt <= maxBCnt) {
                int b = maxBCnt - minBCnt + 1;
                cnt += b;
            }
        }
        return cnt;
    }
}
