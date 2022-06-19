// Copyright (C) 2022 by iamslash

import java.util.*;

// 9ms 50.00% 42.9MB 50.00%
// hash map
// O(N) O(1)
class Solution {
    public String greatestLetter(String s) {
        boolean[] lowers = new boolean[26];
        boolean[] uppers = new boolean[26];
        int maxIdx = -1;
        for (char c : s.toCharArray()) {
            int idx = 0;
            if ('a' <= c && c <= 'z') {
                idx = c - 'a';
                lowers[idx] = true;
            } else {
                idx = c - 'A';
                uppers[idx] = true;
            }
            if (lowers[idx] && uppers[idx] && idx > maxIdx) {
                maxIdx = idx;
            }
        }
        if (maxIdx < 0) {
            return "";
        }
        return String.format("%c", maxIdx + 'A');
    }
}
