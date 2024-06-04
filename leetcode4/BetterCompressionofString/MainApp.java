// Copyright (C) 2024 by iamslash

import java.util.*;

// 15ms 62.12% 45.1MB 74.24%
// brute force
// O(N) O(N)
class Solution {
    public String betterCompression(String compressed) {
        int[] freqs = new int[26];

        compressed = compressed + "a"; 
        int lastCharIdx = -1, lastFreq = 0;
        for (char c : compressed.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                if (lastFreq > 0) {
                    freqs[lastCharIdx] += lastFreq;
                }
                lastCharIdx = c - 'a';
                lastFreq = 0;
                
                // System.out.printf("c: %c, freqs[i]: %d\n", c, freqs[lastCharIdx]);

            } else {
                lastFreq = lastFreq * 10 + (c - '0');
            }
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < freqs.length; ++i) {
            if (freqs[i] > 0) {
                // System.out.printf("i: %d, freqs[i]: %d\n", i, freqs[i]);
                ans.append((char)('a' + i));
                ans.append(String.valueOf(freqs[i]));
            }
        }

        return ans.toString();
    }
}
