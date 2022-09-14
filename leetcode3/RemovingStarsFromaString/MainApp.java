// Copyright (C) 2022 by iamslash

import java.util.*;

// 42ms 83.61% 61.7MB 81.96%
// reverse
// O(N) O(N)
class Solution {
    public String removeStars(String s) {
        StringBuilder sb = new StringBuilder();
        int starCnt = 0, n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            char c = s.charAt(i);
            if (c == '*') {
                starCnt++;
            } else if (starCnt > 0) {
                starCnt--;
            } else {
                sb.append(c);
            }
        }
        return sb.reverse().toString();
    }
}
