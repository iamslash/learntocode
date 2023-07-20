// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// >>> bin(5*5*5*5*5*5)
// '0b11110100001001'
// >>> len(bin(5*5*5*5*5*5))
// 16
// >>> lenen(bin(5*5*5*5*5*5)) - 2
// 14
// >>> 5*5*5*5*5*5
// 15625

//    i
// s: 1 0 1 1
//    j
// C: 0 5 5 5 5
//

// 1ms 100.00% 41.1MB 74.05%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int minimumBeautifulSubstrings(String s) {
        int n = s.length();
        int[] C = new int[n + 1];
        Arrays.fill(C, n + 1);
        C[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                continue;
            }
            for (int j = i, num = 0; j < n; ++j) {                
                num = (num << 1) + (s.charAt(j) - '0');
                if (15625 % num == 0) {
                    C[j + 1] = Math.min(C[j + 1], C[i] + 1);
                }
            }
        }
        if (C[n] > n) {
            return -1;
        }
        return C[n];
    }
}
