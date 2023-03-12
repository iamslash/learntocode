// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 42.1MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    private boolean startEndWithVowel(String word) {
        int n = word.length();
        char s = word.charAt(0), e = word.charAt(n - 1);
        if (s != 'a' && s != 'e' && s != 'i' && s != 'o' && s != 'u') {
            return false;
        }
        if (e != 'a' && e != 'e' && e != 'i' && e != 'o' && e != 'u') {
            return false;
        }
        return true;
    }
    public int vowelStrings(String[] words, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (startEndWithVowel(words[i])) {
                cnt++;
            }
        }
        return cnt;
    }
}
