// Copyright (C) 2024 by iamslash

import java.util.*;

// initial: abcde
//               i
//  target: cdef
//              j
//
// curC: 0 0 3 0
// prvC: 0 2 0 0
// maxLCS: 3

// 189ms 74.47% 45.3MB 65.96%
// iterative dynamic programming
// O(MN) O(MN)
// M: initial len
// N: target len
class Solution {
    public int minOperations(String s, String t) {
        int m = s.length(), n = t.length();
        int[] prvC = new int[n];
        int maxLCS = 0;

        for (int i = 0; i < m; i++) {
            int[] curC = new int[n];
            for (int j = 0; j < n; j++) {
                if (s.charAt(i) == t.charAt(j)) {
                    curC[j] = 1 + (j > 0 ? prvC[j - 1] : 0);
                    maxLCS = Math.max(maxLCS, curC[j]);
                }
            }
            prvC = curC;
        }
        
        return m + n - 2 * maxLCS;
    }
}
