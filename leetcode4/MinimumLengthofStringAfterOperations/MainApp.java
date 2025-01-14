// Copyright (C) 2025 by iamslash

import java.util.*;

// aaaaaa: 2
// aaaaa : 1
// aaaa  : 2
// aaa   : 1
// aa    : 2
// a     : 1

// 10ms 81.65% 45.76MB 98.30%
// math
// O(N) O(1)
class Solution {
    public int minimumLength(String s) {
        int[] freqs = new int[26];
        int minLen = 0;

        for (char c : s.toCharArray()) {
            freqs[c - 'a']++;
        }
        
        for (int i = 0; i < freqs.length; ++i) {
            if (freqs[i] == 0) {
                continue;
            }

            if (freqs[i] % 2 == 0) {
                minLen += 2;
            } else {
                minLen += 1;
            }
        }

        return minLen;
    }
}
