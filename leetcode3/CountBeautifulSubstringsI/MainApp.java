// Copyright (C) 2023 by iamslash

import java.util.*;

//         k: 2
//            i
//         s: b a e y h
//            j
//     vowel: 2
// consonant: 3

// 85ms 100.00% 41.3MB 100.00%
// brute force
// O(N^2) O(1)
class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u';
    }
    public int beautifulSubstrings(String s, int k) {
        int n = s.length(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            int vowelCnt = 0, consoCnt = 0;
            for (int j = i; j < n; ++j) {
                if (isVowel(s.charAt(j))) {
                    vowelCnt++;
                } else {
                    consoCnt++;
                }
                if (vowelCnt == consoCnt &&
                    vowelCnt * consoCnt % k == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
