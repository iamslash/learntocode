// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.39% 41.7MB 94.83%
// brute force
// O(N) O(1)
class Solution {
    public boolean isValid(String word) {

        if (word.length() < 3) {
            return false;
        }

        boolean bVowel = false, bConsonant = false;
        for (char c : word.toCharArray()) {
            if (Character.isDigit(c) == false &&
                Character.isAlphabetic(c) == false) {
                return false;
            }
            if (Character.isAlphabetic(c)) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    bVowel = true;
                } else {
                    bConsonant = true;
                }
            }
        }

        if (bVowel == false || bConsonant == false) {
            return false;
        }

        return true;
    }
}
