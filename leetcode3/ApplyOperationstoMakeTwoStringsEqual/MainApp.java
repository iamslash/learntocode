// Copyright (C) 2023 by iamslash

import java.util.*;


//  x: 4
//       i
// s1: 10110
// s2: 00011
//     10101
//

// 00000
// 00010

// Idea: iterative dynamic programming
//
// done: change the prefix to all 0.
//  two: one and last.
//  one: have one 1 in the prefix.
// last: the last element in the prefix is still 1.
//
// 1ms 100.00% 41.6MB 97.28%
// iterative dynamic programming
// O(N) O(1)
// Difficult to understand
class Solution {
    public int minOperations(String s1, String s2, int x) {
        int n = s1.length(), done = 0, inf = 1_000_000;
        int one = inf, last = inf, two = inf;
        for (int i = 0; i < n; ++i) {
            if (s1.charAt(i) == s2.charAt(i)) {
                last++;
                two++;
            } else if (done < n) {
                one = Math.min(done, two + 1);
                last = Math.min(done, two + x);
                done = two = inf;
            } else {
                done = Math.min(one + x, last + 1);
                two = one;
                one = last = inf;
            }
        }
        if (done < inf) {
            return done;
        }
        return -1;
    }
}
//    x: 2
//                 i  
//   s1: 1100011000
//   s2: 0101001010
// done: M
//  one: 2
//  two: M
// last: 3
