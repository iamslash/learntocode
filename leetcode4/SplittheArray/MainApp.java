// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 98.97% 42.7MB 68.96%
// hash map
// O(N) O(1)
class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        boolean[] nums1 = new boolean[101];
        boolean[] nums2 = new boolean[101];

        for (int num : nums) {
            if (!nums1[num]) {
                nums1[num] = true;
            } else if (nums1[num] && !nums2[num]) {
                nums2[num] = true;
            } else {
                return false;
            }
        }

        return true;
    }
}

// 0ms 100.00% 42.8MB 57.27%
// hash map
// O(N) O(1)
class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        int[] cnts = new int[101];

        for (int num : nums) {
            cnts[num]++;
            if (cnts[num] > 2) {
                return false;
            }
        }

        return true;
    }
}
