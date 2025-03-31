// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 43.10MB 28.66%
// brute force
// O(N) O(1)
class Solution {
    
    public int reverseDegree(String s) {
        int sum = 0, n = s.length();

        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            sum += ('z' - c + 1)  * (i + 1);
        }

        return sum;
    }
}
