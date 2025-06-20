// Copyright (C) 2025 by iamslash

import java.util.*;

// 2ms 97.61% 42.25MB 97.77%
// sort
// O(1) O(1)
class Solution {
    public int minDeletion(String s, int k) {
        int[] freqs = new int[26];
        int minCnt = 0;

        for (char c : s.toCharArray()) {
            freqs[c - 'a']++;
        }

        Arrays.sort(freqs);

        for (int i = 25; i >= 0; --i) {
            if (k <= 0) {
                minCnt += freqs[i];
            }
            k--;
        }

        return minCnt;
    }
}
