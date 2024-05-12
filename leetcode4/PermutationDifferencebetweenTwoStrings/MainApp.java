// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.6MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int findPermutationDifference(String s, String t) {
        int n = s.length();
        int[] sIdxs = new int[26];
        int[] tIdxs = new int[26];

        for (int i = 0; i < n; ++i) {
            sIdxs[s.charAt(i) - 'a'] = i;
            tIdxs[t.charAt(i) - 'a'] = i;
        }

        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += Math.abs(sIdxs[i] - tIdxs[i]);
        }

        return diff;
    }
}
