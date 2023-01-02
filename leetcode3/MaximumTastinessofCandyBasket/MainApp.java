// Copyright (C) 2023 by iamslash

import java.util.*;

//            .    .  .
// price: 1 2 5 8 13 21

// Idea: binary search
//
// Search the minimum difference using binary search

// 60ms 13.87% 52.7MB 27.65%
// binary search (right most equal)
// O(NlgN) O(1)
class Solution {
    public int maximumTastiness(int[] price, int k) {
        Arrays.sort(price);
        int lo = 0, hi = 1_000_000_000, n = price.length;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2, cnt = 1;
            for (int i = 1, j = 0; i < n; ++i) {
                if (price[i] - price[j] >= mi) {
                    cnt++;
                    j = i;
                }
                if (cnt >= k) {
                    break;
                }
            }
            if (cnt >= k) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return lo;
    }
}
