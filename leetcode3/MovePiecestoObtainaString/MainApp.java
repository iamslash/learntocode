// Copyright (C) 2022 by iamslash

import java.util.*;

// 33ms 50.10% 55.2MB 46.73%
// two pointers
// O(N) O(1)
class Solution {
    public boolean canChange(String s, String t) {
        int i = 0, j = 0, n = s.length();
        for (i = 0, j = 0; i < n || j < n; ++i, ++j) {
            while (i < n && s.charAt(i) == '_') {
                i++;
            }
            while (j < n && t.charAt(j) == '_') {
                j++;
            }
            if (i == n ||
                j == n ||
                s.charAt(i) != t.charAt(j) ||
                (s.charAt(i) == 'L' && i < j) ||
                (s.charAt(i) == 'R' && i > j)) {
                break;
            }
        }
        return i == n && j == n;
    }
}
