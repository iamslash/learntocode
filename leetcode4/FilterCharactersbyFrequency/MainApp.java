// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 43.20MB 76.09%
// hash map
// O(N) O(N)
class Solution {
    public String filterCharacters(String s, int k) {
        int[] freqs = new int[26];
        StringBuilder ans = new StringBuilder();

        for (char c : s.toCharArray()) {
            freqs[c - 'a'] += 1;
        }

        for (char c : s.toCharArray()) {
            if (freqs[c - 'a'] < k) {
                ans.append(c);
            }
        }

        return ans.toString();
    }
}
