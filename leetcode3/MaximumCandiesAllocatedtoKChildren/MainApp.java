// Copyright (C) 2022 by iamslash

import java.util.*;

// 54ms 66.32% 78.9MB 46.85%
// binary search (right most equal value)
// O(N) O(1)
class Solution {
    private long groupCnt(int[] candies, int mi) {
        long cnt = 0;
        for (int candy : candies) {
            cnt += candy / mi;
        }
        return cnt;
    }
    public int maximumCandies(int[] candies, long k) {
        int lo = 0, hi = 10_000_000;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            // System.out.println(mi);
            if (groupCnt(candies, mi) >= k) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return lo;
    }
}
