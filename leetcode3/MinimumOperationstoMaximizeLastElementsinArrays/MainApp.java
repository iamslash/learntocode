// Copyright (C) 2023 by iamslash

import java.util.*;

//        i
// nums1: 1 2 7
// nums2: 4 5 3
//  cnt1: 0
//  cnt2: 0

// Idea: itertaive dynamic programming
//
// cnt1: the count for nums1[n-1] and nums2[n-1] not swapped.
// cnt2: the count for nums1[n-1] and nums2[n-1] swapped.
//
// 1ms 100.00% 43.7MB 69.63%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        int cnt1 = 0, cnt2 = 0, n = nums1.length;
        int minLast = Math.min(nums1[n - 1], nums2[n - 1]);
        int maxLast = Math.max(nums1[n - 1], nums2[n - 1]);
        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            if ((Math.max(a, b) > maxLast) ||
                (Math.min(a, b) > minLast)) {
                return -1;
            }
            if (a > nums1[n - 1] || b > nums2[n - 1]) {
                cnt1++;
            }
            if (a > nums2[n - 1] || b > nums1[n - 1]) {
                cnt2++;
            }
        }
        return Math.min(cnt1, cnt2);
    }
}
