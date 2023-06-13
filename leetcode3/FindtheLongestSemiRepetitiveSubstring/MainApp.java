// Copyright (C) 2023 by iamslash

import java.util.*;

//            l
//        i
// s: 5 2 2 3 3
//            j    

// 10ms 89.22% 44.4MB 30.36%
// two pointers
// O(N) O(1)
class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int lastIdx = 0, i = 0, j = 1, maxLen = 1, n = s.length();
        while (j < n) {
            if (s.charAt(j - 1) == s.charAt(j)) {
                if (lastIdx > 0) {
                    i = lastIdx;
                }
                lastIdx = j;
            }
            maxLen = Math.max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
}
