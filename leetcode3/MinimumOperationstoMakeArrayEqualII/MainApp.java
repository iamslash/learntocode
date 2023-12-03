// Copyright (C) 2023 by iamslash

import java.util.*;

// 4ms 64.13% 58.3MB 14.13%
// greedy
// O(N) O(1)
class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        long up = 0, dn = 0;
        for (int i = 0; i < n; ++i) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            // System.out.printf("num1: %d, num2: %d, diff: %d\n", nums1[i], nums2[i], diff);
            if (k == 0) {
                if (diff > 0) {
                    return -1;
                }
            } else {
                if (diff % k != 0) {
                    return -1;
                }
                int quo = diff / k;
                if (nums1[i] > nums2[i]) {
                    up += quo;
                } else if (nums1[i] < nums2[i]) {
                    dn += quo;
                }
            }
            // System.out.printf("  up: %d, dn: %d\n", up, dn);
        }
        return up == dn ? up : -1;
    }
}
