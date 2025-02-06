// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 42.19% 97.71%
// hash map
// O(N) O(1)
class Solution {
    public int maxDifference(String s) {
        int n = s.length(), maxOddCnt = 0, minEvenCnt = 100;
        int[] freqs = new int[26];

        for (char c : s.toCharArray()) {
            freqs[c - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (freqs[i] == 0) {
                continue;
            }

            if (freqs[i] % 2 == 0) {
                minEvenCnt = Math.min(minEvenCnt, freqs[i]);
            } else {
                maxOddCnt = Math.max(maxOddCnt, freqs[i]);
            }
        }

        return maxOddCnt - minEvenCnt;
    }
}
