// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 92.38% 40.69MB 83.81%
// hash map
// O(N) O(1)
class Solution {
    private void increaseFreq(int[] freqs, String digitStr) {
        for (char c : digitStr.toCharArray()) {
            freqs[c - 'a']++;
        }
    }
    
    public int countOddLetters(int n) {
        final String[] digitStrings = new String[]{
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
        };
        int[] freqs = new int[26];
        int oddCnt = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            increaseFreq(freqs, digitStrings[digit]);
        }

        for (int i = 0; i < 26; ++i) {
            if (freqs[i] % 2 == 1) {
                oddCnt++;
            }
        }
        
        return oddCnt;
    }
}
