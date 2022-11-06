// Copyright (C) 2021 by iamslash

import java.util.*;


// word: a b a
//       a
//         b
//           a
//       a b a

//                      i
// word:      a    b    a
//   bm:   0001 0011 0010
//                      j
// cnts:   0000 0001 0010 0011 
//            1    1    0    1
//  ans:      4

// 22ms 96.70% 39.8MB 63.09%
// bit manipulation
// O(N) O(1)
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
