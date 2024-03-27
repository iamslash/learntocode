// Copyright (C) 2024 by iamslash

import java.util.*;

//          i
// s: b c b b b c b a
//    j

// 1ms 100.00% 42.2MB 72.78%
// sliding window
// O(N) O(1)
class Solution {
    public int maximumLengthSubstring(String s) {
        int[] freqs = new int[26];
        int maxLen = 0;

        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (++freqs[s.charAt(i) - 'a'] > 2) {
                while (freqs[s.charAt(i) - 'a'] > 2) {
                    --freqs[s.charAt(j++) - 'a'];
                }
            }
            maxLen = Math.max(maxLen, i - j + 1);
        }

        return maxLen;
    }
}
