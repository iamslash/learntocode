// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 44.6MB 100.00%
// hash map
// O(NlgN) O(1)
class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[] nums1Freqs = new int[101];
        int[] nums2Freqs = new int[101];
        for (int num : nums1) {
            nums1Freqs[num]++;
        }
        for (int num : nums2) {
            nums2Freqs[num]++;
        }
        int[] ans = new int[2];
        for (int num : nums1) {
            if (nums2Freqs[num] > 0) {
                ans[0]++;
            }
        }
        for (int num : nums2) {
            if (nums1Freqs[num] > 0) {
                ans[1]++;
            }
        }
        return ans;
    }
}
