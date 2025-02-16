// Copyright (C) 2025 by iamslash

import java.util.*;

// k: 3
//    p
// s: aaabaaa
//       i

// 1ms 100.00% 42.28MB 100.00%
// sliding window
// O(N) O(1)
class Solution {
    public boolean hasSpecialSubstring(String s, int k) {
        int n = s.length(), prevIdx = 0;
        char prevChr = s.charAt(0);

        for (int i = 0; i < n; ++i) {
            if (i - prevIdx >= k) {
                prevChr = s.charAt(++prevIdx);
            }
            
            char c = s.charAt(i);
            if (prevChr != c) {
                prevIdx = i;
                prevChr = c;
            }

            // Valid window len
            int len = i - prevIdx + 1;
            if (len < k) {
                continue;
            }
            
            // Valid before character
            if (prevIdx > 0 && s.charAt(prevIdx - 1) == c) {
                continue;
            }
            
            // Valid after character
            if (i < n - 1 && c == s.charAt(i + 1)) {
                continue;
            }
            
            return true;
        }

        return false;
    }
}
