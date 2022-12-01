// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 98.33% 42.9MB 98.41%
// two pointers
// O(N) O(1)
class Solution {
    public int appendCharacters(String s, String t) {
        int i = 0, j = 0, n = s.length(), m = t.length();
        for (i = 0; i < n && j < m; ++i) {
            if (s.charAt(i) == t.charAt(j)) {
                j++;
            }
        }
        return m - j;
    }
}
