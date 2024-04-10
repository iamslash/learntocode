// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.2MB 98.75%
// math
// O(N) O(N)
class Solution {
    public String getSmallestString(String s, int k) {
        char[] chrs = s.toCharArray();
        int n = s.length();
        
        for (int i = 0; i < n && k > 0; ++i) {
            int dist = Math.min(chrs[i] - 'a', 'z' - chrs[i] + 1);
            chrs[i] = (dist <= k) ? 'a' : (char)(chrs[i] - k);
            k -= dist;
        }
        
        return String.valueOf(chrs);
    }
}
