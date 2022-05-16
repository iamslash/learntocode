// Copyright (C) 2022 by iamslash

import java.util.*;

// 41ms 88.23% 80.7MB 55.00%
// bit manipulation
// O(N) O(1)
class Solution {
    public int largestCombination(int[] candidates) {
        int maxCnt = 0, n = candidates.length;
        for (int bm = 1; bm <= 10_000_000; bm <<= 1) {
            int cnt = 0;
            for (int cand : candidates) {
                if ((cand & bm) > 0) {
                    cnt++;
                }
            }
            maxCnt = Math.max(maxCnt, cnt);
        }
        return maxCnt;
    }
}
