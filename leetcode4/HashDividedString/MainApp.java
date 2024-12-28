// Copyright (C) 2024 by iamslash

import java.util.*;

// 2ms 97.36% 44.47MB 93.85%
// brute force
// O(N) O(N)
class Solution {
    public String stringHash(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();

        for (int i = 0; i < n; i += k) {
            int hash = 0;
            for (int j = i; j < i + k; ++j) {
                hash += s.charAt(j) - 'a';
            }
            hash %= 26;

            sb.append((char)('a' + hash));
        }

        return sb.toString();
    }
}
