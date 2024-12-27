// Copyright (C) 2024 by iamslash

import java.util.*;

//            i
// nums1: 3 1 2 3 1 2
//                j
// nums2: 1 2 3 1 2 3

// 86ms 100.00% 45.20MB 100.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int maximumMatchingIndices(int[] nums1, int[] nums2) {
        int n = nums1.length, maxMatch = 0;

        for (int i = 0; i < n; ++i) {
            int match = 0;

            for (int j = 0; j < n; ++j) {
                int idx = (i + j) % n;
                if (nums1[idx] == nums2[j]) {
                    match++;
                }
            }

            maxMatch = Math.max(maxMatch, match);
        }

        return maxMatch;
    }
}
