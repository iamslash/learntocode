// Copyright (C) 2021 by iamslash

import java.util.*;

//      a: cccddabba
//      b: babababab
// freqs1: a b c
//         2 4 3
// freqs2: a b
//         4 5
//   diff:

// Almost equivalent means that
// the difference of every each character should be
// equal or less than 3 at most.

// 0ms 100.00% 37.5MB 62.50%
// brute force
// O(N) O(1)
class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        int n = word1.length();
        int[] freqs1 = new int[26], freqs2 = new int[26];
        for (int i = 0; i < n; ++i) {
            freqs1[word1.charAt(i)-'a']++;
            freqs2[word2.charAt(i)-'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (Math.abs(freqs1[i] - freqs2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
}
