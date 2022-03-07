// Copyright (C) 2022 by iamslash

import java.util.*;

//
// n: 2
//            .         .
//        a
// C: 1 0 1
//        b
// n: 5
//            .         .
//              a
// C: 1 0 1 0 0 1
//              b
// n: 6
//            .         .
//              a
// C: 1 0 1 0 0 1 0
//              b
// n: 8
//            .         .
//                    a
// C: 1 0 1 0 0 1 0 0 1
//                    b
// n: 12
//            .         .
//                          a
// C: 1 0 1 0 0 1 0 0 1 0 0 1 0
//                          b
// n: 16
//            .         .
//                                a
// C: 1 0 1 0 0 1 0 1 1 0 1 1 0 2 1 1 2
//                                b

// same with coin change
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int houseOfCards(int n) {
        int[] C = new int[n+1];
        C[0] = 1;
        for (int a = 2; a <= n; a += 3) {
            for (int b = n; b >= a; --b) {
                C[b] += C[b - a];
            }
        }
        return C[n];
    }
}
