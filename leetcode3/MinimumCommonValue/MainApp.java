// Copyright (C) 2023 by iamslash

import java.util.*;

// 2MS 100.00% 73.5MB 80.00%
// two pointers
// O(N) O(1)
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0, n = nums1.length, m = nums2.length;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
}
