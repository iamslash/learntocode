// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.1MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int countKeyChanges(String s) {
        int cnt = 0, last = -1;
        for (char c : s.toCharArray()) {
            c = Character.toLowerCase(c);
            if (last >= 0 && last != c) {
                cnt++;
            }
            last = c;
        }
        return cnt;
    }
}
