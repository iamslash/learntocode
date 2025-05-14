// Copyright (C) 2025 by iamslash

// 1ms 100.00% 42.54MB 69.92%
// brute force
// O(N) O(1)
class Solution {
    public int maxFreqSum(String s) {
        int maxVowelCnt = 0, maxConsonantCnt = 0;
        int[] charCnt = new int[26];
        
        for (char c : s.toCharArray()) {
            int idx = c - 'a';
            charCnt[idx]++;
            
            if (c == 'a' ||
                c == 'e' ||
                c == 'i' ||
                c == 'o' ||
                c == 'u') {
                if (charCnt[idx] > maxVowelCnt) {
                    maxVowelCnt = charCnt[idx];
                }

            } else {
                if (charCnt[idx] > maxConsonantCnt) {
                    maxConsonantCnt = charCnt[idx];
                }                
            }
        }

        return maxVowelCnt + maxConsonantCnt;        
    }
}
