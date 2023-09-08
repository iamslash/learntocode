// Copyright (C) 2023 by iamslash

import java.util.*;

// nums1: 1 3 2 1
// nums2: 2 2 3 4
//        1 2 2 4

// Idea: iterative dynamic programming
//
//  C1: max count for num3 ends with nums1[i]
//  C2: max count for num3 ends with nums2[i]
// t11: count for num3 ends with nums1[i-1], nums1[i]
// t12: count for num3 ends with nums1[i-1], nums1[i]
// t21: count for num3 ends with nums2[i-1], nums1[i] 
// t22: count for num3 ends with nums2[i-1], nums2[i]
//  C1: max(t11, t21)
//  C2: max(t12, t22)
// ans: max(ans, C1, C2)

// 4ms 98.94% 57.6MB 40.46%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int maxNonDecreasingLength(int[] nums1, int[] nums2) {
        int ans = 1, C1 = 1, C2 = 1, n = nums1.length;
        for (int i = 1; i < n; ++i) {
            int t11 = nums1[i - 1] <= nums1[i] ? C1 + 1 : 1;
            int t12 = nums1[i - 1] <= nums2[i] ? C1 + 1 : 1;
            int t21 = nums2[i - 1] <= nums1[i] ? C2 + 1 : 1;
            int t22 = nums2[i - 1] <= nums2[i] ? C2 + 1 : 1;
            C1 = Math.max(t11, t21);
            C2 = Math.max(t12, t22);
            ans = Math.max(ans, Math.max(C1, C2));
        }
        return ans;
    }
}
