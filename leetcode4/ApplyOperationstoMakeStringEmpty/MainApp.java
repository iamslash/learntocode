// Copyright (C) 2024 by iamslash

import java.util.*;

// 21ms 88.80% 50.2MB 72.57%
// brute force
// O(N) O(1)
class Solution {
    public String lastNonEmptyString(String s) {
        int[] cnts = new int[26];
        for (char c : s.toCharArray()) {
            cnts[c - 'a']++;
        }
        int maxFreq = 0;
        for (int i = 0; i < cnts.length; ++i) {
            maxFreq = Math.max(maxFreq, cnts[i]);
        }
        for (int i = 0; i < cnts.length; ++i) {
            cnts[i] = maxFreq;
        }

        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (--cnts[c - 'a'] == 0) {
                sb.append(c);
            }            
        }

        return sb.toString();
    }
}
