// Copyright (C) 2025 by iamslash

import java.util.*;


// n: 7 
// m: 5
// k: 5
//
// 1 2 3 
// 6 5 4 

// 0ms 100.00% 41.11MB 35.32%
// math
// O(1) O(1)
class Solution {
    public long minCuttingCost(int n, int m, int k) {

        if (n <= k && m <= k) {
            return 0;
        }

        if (m < n) {
            m = n;
        }
        
        return (m - k) * (long)k;        
    }
}
