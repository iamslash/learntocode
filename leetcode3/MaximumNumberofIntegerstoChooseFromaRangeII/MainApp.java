// Copyright (C) 2023 by iamslash

import java.util.*;

// 26ms 100.00% 51.5MB 77.08%
// binary search right most equal
// O(NlgN) O(1)
class Solution {
    public int maxCount(int[] banned, int n, long maxSum) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mi = lo + (hi - lo + 1) / 2;
            // Gauss summation
            long sum = (long)mi * (mi + 1) / 2;
            for (int a : banned) {
                if (a <= mi) {
                    sum -= a;
                }
            }
            if (sum <= maxSum) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        int ans = lo;
        for (int a : banned) {
            if (a <= lo) {
                ans--;
            }
        }
        return ans;
    }
}
