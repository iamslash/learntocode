// Copyright (C) 2021 by iamslash

import java.util.*;

//            i
// word:      a    b    a
//   bm:   0001 0011 0010
// cnts:   0000 0001 0010 
//            1    0    0
//  ans:      0

// 22ms 96.70% 39.8MB 63.09%
// bit manipulation
// O(N) O(1)
class Solution {
    public long wonderfulSubstrings(String word) {
        // the count of state
        long cnt[] = new long[1024];
        cnt[0] = 1;
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
