// Copyright (C) 2024 by iamslash

import java.util.*;


//    k: 0
// word: a a b c a b a
//
//       a b c
//           l
// frqs: 4 2 1
//       r
// cDel: 3
// mDel: 3


//    k: 2
// word: a a a b a a a
//       a b
//         l
// frqs: 6 1
//       r
// cDel: 0
// mDel: 1

// 8ms 65.92% 45.2MB 90.27%
// math
// O(N) O(1)
// ★
class Solution {
    public int minimumDeletions(String word, int k) {        
        int n = word.length(), minDels = n;
        int[] freqs = new int[26];

        for (char c : word.toCharArray()) {
            freqs[c - 'a']++;
        }

        for (int left : freqs) {
            int curDel = 0;
            for (int right : freqs) {
                if (left > right) {
                    curDel += right;
                } else {
                    curDel += Math.max(0, right - (left + k));
                }
            }
            minDels = Math.min(minDels, curDel);
        }

        return minDels;
    }
}
