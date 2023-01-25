// Copyright (C) 2023 by iamslash

import java.util.*;

//     k: 3
// nums1: 4 3 1 4
// nums2: 1 3 7 1
//

// 5ms 76.05% 60.5MB 86.85%
// greedy
// O(N) O(1)
class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        long up = 0, dn = 0;
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                continue;
            }
            int diff = Math.abs(nums1[i] - nums2[i]);
            if (diff % k != 0) {
                return -1;
            }
            int quo = diff / k;
            if (nums1[i] < nums2[i]) {
                up += quo;
            } else {
                dn += quo;
            }
        }
        return up == dn ? up : -1;
    }
}
