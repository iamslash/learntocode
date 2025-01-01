// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea:
// 
// vowelCnt == 0:
// - Bob always wins
// vowelCnt % 2 == 1:
// - Alice always wins
// vowelCnt % 2 == 0 && vowelCnt == n:
// - Alice can pick n - 1 vowels
// - Bob can't pick 1 vowel
// - Alice always wins

// 6ms 63.81% 45.19MB 90.67%
// linear traversal
// O(N) O(1)
class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u';
    }
    
    public boolean doesAliceWin(String s) {

        for (char c : s.toCharArray()) {
            if (isVowel(c)) {
                return true;
            }
        }
        
        return false;
    }
}

