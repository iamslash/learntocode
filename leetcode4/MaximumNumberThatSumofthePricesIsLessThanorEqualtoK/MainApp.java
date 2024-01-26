// Copyright (C) 2024 by iamslash

// 8ms 61.79% 40.9MB 56.09%
// binary search
// O(NlgN) O(1)
// difficult
class Solution {
    public long findMaximumNumber(long k, int x) {
        long lo = 0, hi = (long) 1e16;
        while (lo < hi) {
            long mi = lo + (hi - lo + 1 >> 1), bits = 0;
            for (long i = 1L << x - 1; i <= mi; i <<= x) {
                bits += (mi + 1) / (i + i) * i +
                    Math.max(0L, (mi + 1) % (i + i) - i);
            }
            if (bits <= k) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return lo;
    }
}
