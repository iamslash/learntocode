// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.1MB 66.67%
// brute force
// O(N) O(1)
class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] lowers = new boolean[26];
        boolean[] uppers = new boolean[26];

        for (char c : word.toCharArray()) {
            if (Character.isLowerCase(c)) {
                lowers[c - 'a'] = true;
            } else {
                uppers[c - 'A'] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (lowers[i] && uppers[i]) {
                cnt++;
            }
        }

        return cnt;
    }
}
