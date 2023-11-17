// Copyright (C) 2023 by iamslash

import java.util.*;
/**
 * Definition for BigArray.
 * class BigArray {
 *     public BigArray(int[] elements);
 *     public int at(long index);
 *     public long size();
 * }
 */
// 820ms 100.00% 66.2MB 100.00%
// binary search
// O(NlgN) O(1)
class Solution {
    public int countBlocks(BigArray nums) {
        long n = nums.size();
        int cnt = 0;
        for (long i = 0; i < n; ++i, ++cnt) {
            long lo = i, hi = n - 1;
            while (lo <= hi) {
                long mi = (lo + hi) >>> 1;
                if (nums.at(mi) == nums.at(i)) {
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }
            i = hi;
        }
        return cnt;
    }
}
