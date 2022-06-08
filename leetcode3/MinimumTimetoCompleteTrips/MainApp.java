// Copyright (C) 2022 by iamslash

import java.util.*;

// 402ms 36.14% 56.8MB 92.12%
// binary search
// O(lgN) O(1)
class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long lo = 1, hi = 100_000_000_000_000L;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            long sum = 0;
            for (int ts : time) {
                sum += mi / ts;
            }
            if (sum < totalTrips) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
}
