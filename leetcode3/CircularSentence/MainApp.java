// Copyright (C) 2022 by iamslash

import java.util.*;

// 3ms 71.43% 42MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public boolean isCircularSentence(String s) {
        int n = s.length();
        char last = s.charAt(0);
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) != ' ') {
                if (s.charAt(i-1) == ' ' && last != s.charAt(i)) {
                    return false;                    
                }
                last = s.charAt(i);
            }
        }
        return last == s.charAt(0);
    }
}
 
