// Copyright (C) 2022 by iamslash

import java.util.*;

//    k1: 0
//    k2: 0
// nums1: 1  2  3  4
// nums2: 2 10 20 19
// diffs: 1  8 17 15
// freqs: 1  8 17 15
//        1  1  1  1

//    k1: 1
//    k2: 1
// nums1: 1  4 10 12
// nums2: 5  8  6  9
// diffs: 4  4  4  3
// freqs: 4  3
//        1  3 

// 8ms 91.38% 59.4MB 80.17%
// bucket sort
// O(N) O(N)
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2,
                                 int k1, int k2) {
        int n = nums1.length;
        int[] diffs = new int[n];
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            diffs[i] = Math.abs(nums1[i] - nums2[i]);
            maxDiff = Math.max(maxDiff, diffs[i]);
        }
        int[] freqs = new int[maxDiff + 1];
        for (int i = 0; i < n; ++i) {
            freqs[diffs[i]]++;
        }
        int k = k1 + k2;
        for (int i = maxDiff; i > 0; --i) {
            if (freqs[i] == 0) {
                continue;
            }
            int delta = Math.min(freqs[i], k);
            freqs[i] -= delta;
            freqs[i - 1] += delta;
            k -= delta;
        }
        long ans = 0;
        for (int i = maxDiff; i > 0; --i) {
            ans += ((long)freqs[i]) * i * i;
        }
        return ans;
    }
}
