// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.1MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int scoreOfString(String s) {
        int n = s.length(), score = 0;
        for (int i = 1; i < n; ++i) {
            score += Math.abs(s.charAt(i - 1) - s.charAt(i));
        }
        return score;
    }
}
