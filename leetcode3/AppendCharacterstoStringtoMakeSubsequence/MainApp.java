// Copyright (C) 2023 by iamslash

import java.util.*;


//        i
// s: coaching
// t: coc
//       j

// 5ms 82.86% 42.9MB 93.43%
// two pointers
// O(N) O(1)
class Solution {
    public int appendCharacters(String s, String t) {
        int j = 0, n = s.length(), m = t.length();
        for (int i = 0; i < n && j < m; ++i) {
            if (s.charAt(i) == t.charAt(j)) {
                j++;
            }
        }
        return m - j;
    }
}
