// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 41.9MB 50.00%
// math
// O(N) O(1)
class Solution {
    public int percentageLetter(String s, char letter) {
        int cnt = 0, n = s.length();
        for (char c : s.toCharArray()) {
            if (c == letter) {
                cnt++;
            }
        }
        return (int)(((double)cnt / n) * 100.00);
    }
}
