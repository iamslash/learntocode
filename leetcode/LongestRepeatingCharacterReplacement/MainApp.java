// Copyright (C) 2024 by iamslash

import java.util.*;

// k: 2
//    i
// s: ABAB
//    j
//

// 5ms 98.44% 42.5MB 51.86%
// sliding window
// O(N) O(1)
class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int[] freqs = new int[26];
        int i = 0, maxCnt = 0, maxLen = 0;

        for (int j = 0; j < n; ++j) {
            maxCnt = Math.max(maxCnt, ++freqs[s.charAt(j) - 'A']);
            while (j - i + 1 - maxCnt > k) {
                freqs[s.charAt(i) - 'A']--;
                i++;
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
}
