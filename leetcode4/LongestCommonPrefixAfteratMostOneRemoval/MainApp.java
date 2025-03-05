// Copyright (C) 2025 by iamslash

import java.util.*;

//        i 
// s: madxa
// t: madam
//       j

// 6ms 87.21% 45.82MB 80.23%
// two pointers
// O(N) O(1)
class Solution {
    public int longestCommonPrefix(String s, String t) {
        int cnt = 0, n = s.length(), m = t.length();
        int i = 0, j = 0, removed = 0;

        while (i < n && j < m) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
                j++;
                cnt++;
            } else if (removed > 0) {
                return cnt;
            } else {
                removed = 1;
                i++;
            }
        }

        return cnt;
    }
}
