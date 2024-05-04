// Copyright (C) 2024 by iamslash

import java.util.*;

// 3ms 85.45% 42.6MB 87.27%
// sort
// O(NlgN) O(1)
class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int n = nums1.length, m = n - 2, minDiff = Integer.MAX_VALUE;
        int[] diffs = new int[]{
            nums2[0] - nums1[0],
            nums2[0] - nums1[1],
            nums2[0] - nums1[2]
        };

        for (int diff : diffs) {
            int j = 0, skip = 0;
            for (int i = 0; i < n && j < m; ++i) {
                if (nums2[j] - nums1[i] != diff) {
                    skip++;
                } else {
                    j++;
                }

                if (skip > 2) {
                    break;
                }
            }

            if (j == m) {
                minDiff = Math.min(minDiff, diff);
            }
        }

        return minDiff;
    }
}
