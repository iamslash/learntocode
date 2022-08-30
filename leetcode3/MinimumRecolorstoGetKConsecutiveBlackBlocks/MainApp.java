// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 46.25% 42MB 28.18%
// sliding window
// O(N) O(1)
class Solution {
    public int minimumRecolors(String blocks, int k) {
        int n = blocks.length(), whiteCnt = 0, minWhiteCnt = k;
        for (int i = 0; i < n; ++i) {
            char c = blocks.charAt(i);
            whiteCnt += c == 'W' ? 1 : 0;
            if (i >= k) {
                whiteCnt -= blocks.charAt(i - k) == 'W' ? 1 : 0;
            }
            if (i >= k - 1) {
                minWhiteCnt = Math.min(minWhiteCnt, whiteCnt);
            }
        }
        return minWhiteCnt;
    }
}
