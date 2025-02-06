// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 42.86MB 93.30%
// hash map
// O(N) O(1)
class Solution {
    public String findValidPair(String s) {
        int[] freqs = new int[10];
        int n = s.length();

        for (char c : s.toCharArray()) {
            freqs[c - '0']++;
        }

        for (int i = 0; i < n - 1; ++i) {
            int firstDigit = s.charAt(i) - '0';
            int secondDigit = s.charAt(i + 1) - '0';

            if (firstDigit != secondDigit &&
                freqs[firstDigit] == firstDigit &&
                freqs[secondDigit] == secondDigit) {
                return s.substring(i, i + 2);
            }
        }

        return "";
    }
}
