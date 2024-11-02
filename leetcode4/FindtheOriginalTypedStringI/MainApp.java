// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 95.57% 42.3MB 31.65%
// forward
// O(N) O(1)
class Solution {
    public int possibleStringCount(String word) {
        int cnt = 1;
        char prevChar = '0';
        
        for (char c : word.toCharArray()) {
            if (c == prevChar) {
                cnt++;
            }
            prevChar = c;
        }

        return cnt;
    }
}
