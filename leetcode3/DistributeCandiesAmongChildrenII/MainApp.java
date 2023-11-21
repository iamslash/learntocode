// Copyright (C) 2023 by iamslash

import java.util.*;

//     n: 5
// limit: 2
//
//        2 2 1
//

// Idea: math
//
// There are 3 children a, b, c.
// Traverse a [0..min(n, limit)]
//   Calculate b.
//   minbCnt should be less than maxBCnt.
//
// 24ms 41.57% 39.2MB 95.84%
// math
// O(N) O(1)
class Solution {
    public long distributeCandies(int n, int limit) {
        long cnt = 0, bnd = Math.min(n, limit);        
        for (int a = 0; a <= bnd; ++a) {
            long minBCnt = Math.max(0, n - a - limit);
            long maxBCnt = Math.min(limit, n - a);
            if (minBCnt <= maxBCnt) {
                long b = maxBCnt - minBCnt + 1;
                cnt += b;
            }
        }
        return cnt;
    }
}
