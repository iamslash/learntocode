// Copyright (C) 2024 by iamslash

import java.util.*;

//         i
// word: AbBCab

// 22ms 67.74% 45.6MB 88.11%
// brute force
// O(N) O(1)
class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] lowers = new boolean[26], uppers = new boolean[26];
        int cnt = 0;
        for (char c : word.toCharArray())
            if (Character.isLowerCase(c)) {
                lowers[c - 'a'] = !uppers[c - 'a'];
            } else {
                uppers[c - 'A'] = true;
            }
        for (int i = 0; i < 26; ++i) {
            cnt += lowers[i] && uppers[i] ? 1 : 0;
        }
        return cnt;
    }
}
