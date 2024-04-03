// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: prefix sum
//
//            d
// possibles: 1 0 1 0
//              b b b
//              d
//    daniel:  1
//       bob: -1
//
//              d
// possibles: 1 0 1 0
//                b b
//                d
//    daniel:  0
//       bob:  0
//                d
// possibles: 1 0 1 0
//                  b
//    daniel:  2
//       bob: -1
//                  d 
// possibles: 1 0 1 0
//              
//    daniel:  0
//       bob:  0

// possibles: 1 0 1 0
//            i
//        ps: 1 0 1 0 

// possibles: 1 1
//              i
//        ps: 1 2 

// 9ms 92.72% 58.7MB 96.02%
// prefix sum
// O(N) O(N)
class Solution {
    public int minimumLevels(int[] possibles) {
        int n = possibles.length;
        int[] ps = new int[n + 1];

        for (int i = 0; i < n; ++i) {
            int possible = possibles[i] == 0 ? -1 : 1;
            ps[i + 1] = ps[i] + possible;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (ps[i + 1] > ps[n] - ps[i + 1]) {
                return i + 1;
            }
        }

        return -1;
    }
}
