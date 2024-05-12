// Copyright (C) 2024 by iamslash

import java.util.*;

// 36ms 33.20% 45.2MB 86.47%
// brute force
// O(N) O(1)
class Solution {
    private boolean isValid(String s, int len) {
        int n = s.length();
        int[] wndFreqs = new int[26];

        for (int i = 0; i < len; ++i) {
            wndFreqs[s.charAt(i) - 'a']++;
        }

        for (int i = len; i < n; i += len) {
            int[] strFreqs = new int[26];
            for (int j = i; j < i + len; ++j) {
                strFreqs[s.charAt(j) - 'a']++;
            }
            for (int k = 0; k < 26; ++k) {
                if (strFreqs[k] != wndFreqs[k]) {
                    return false;
                }
            }            
        }

        return true;
    }
    
    public int minAnagramLength(String s) {
        int n = s.length();
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0 && isValid(s, i)) {
                return i;
            }
        }
        return -1;
    }
}
