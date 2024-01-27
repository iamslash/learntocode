// Copyright (C) 2024 by iamslash

import java.util.*;

// n: 3
// x: 1
// y: 3
//
//                i
//    h --- h --- h
//    |___________|
//          j
//

// 2ms 98.99% 44.2MB 85.30%
// two pointers
// O(N^2) O(N) 
class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        // to make sure that x <= y in every case
        if (x > y) {
            return countOfPairs(n, y, x);
        }
        
        int[] ans = new int[n];
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int idx = i - j;
                idx = Math.min(idx, Math.abs(j - x) + 1 + Math.abs(i - y));
                if (idx >= 1) {
                    // add 2 as we can go from j -> i and i -> j
                    ans[idx - 1] += 2;  
                }
            }
        }
        return ans;
    }
}
