// Copyright (C) 2024 by iamslash

import java.util.*;

// 2ms 100.00% 43.4MB 50.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        return nums2[0] - nums1[0];
    }
}
