// Copyright (C) 2023 by iamslash

import java.util.*;

// k: 2
//    j
// s: a a b a a a a c a a b c
//    i
// {a: 8, b: 2, c: 2}

// Idea: sliding window
//
// Let's say `n` is the length of s.
// Find the number of a, b, c.
// [a, b, c]
// Find the longest window which has
// [a-2, b-2, c-2].
// The answer is `n` - `len of longest window`.

// 12ms 79.70% 43.2MB 72.77%
// sliding window
// O(N) O(1)
class Solution {
    public int takeCharacters(String s, int k) {
        int[] cnts = new int[]{0, 0, 0};
        int n = s.length(), maxWnd = -1;
        for (char c : s.toCharArray()) {
            cnts[c - 'a']++;
        }
        if (cnts[0] < k || cnts[1] < k || cnts[2] < k) {
            return -1;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (--cnts[s.charAt(i) - 'a'] < k) {
                while (cnts[s.charAt(i) - 'a'] < k) {
                    cnts[s.charAt(j++) - 'a']++;
                }
            }
            maxWnd = Math.max(maxWnd, i - j + 1);
        }
        return n - maxWnd;
    }
}
