// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 42.1MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int minimumChairs(String s) {
        int maxCnt = 0, cnt = 0;

        for (char c : s.toCharArray()) {
            if (c == 'E') {
                cnt++;
            } else if (c == 'L') {
                cnt--;
            }
            maxCnt = Math.max(maxCnt, cnt);
        }

        return maxCnt;
    }
}
