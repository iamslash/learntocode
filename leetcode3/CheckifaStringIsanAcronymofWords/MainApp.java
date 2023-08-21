// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 43.4MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public boolean isAcronym(List<String> words, String s) {
        if (words.size() != s.length()) {
            return false;
        }
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != words.get(i).charAt(0)) {
                return false;
            }
        }
        return true;
    }
}
