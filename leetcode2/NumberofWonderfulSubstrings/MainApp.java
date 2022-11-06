// Copyright (C) 2021 by iamslash

import java.util.*;


//       a b c d e f g h i j
// word: a b a
// 
//       a        w
//       a b
//       a b a    w
//         b      w
//         b a
//           a    w
// cnts: freq of bm

//                     i
// word:     a    b    a
//   bm:  0001 0011 0010   
//                     j
//        0100 0100 0001
//        0101 0111 0011
//                a    b   ba     dcba      jihgfedcba
// cnts:  0000 0001 0010 0011 ... 1111 .... 1111111111
//           1    1    0    1        0               0
//  ans:     2

// 22ms 96.70% 39.8MB 63.09%
// bit manipulation
// O(N) O(1)
// too difficult
class Solution {
    public long wonderfulSubstrings(String word) {
        long cnt[] = new long[1024];  // the count of state 
        cnt[0] = 1;  // seed
        long ans = 0;
        int bm = 0;
        for (char c : word.toCharArray()) {
            bm ^= 1 << (c-'a');
            ans += cnt[bm];
            for (int i = 0; i < 10; ++i) {
                ans += cnt[bm ^ (1 << i)];
            }
            ++cnt[bm];
        }
        return ans;
    }
}
