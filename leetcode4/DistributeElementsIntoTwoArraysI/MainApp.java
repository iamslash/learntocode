// Copyright (C) 2024 by iamslash

import java.util.*;

//              k
//  nums: 1 2 3 4
//        i
// nums1: 1
// nums2: 2 3 4
//            j

// 1ms 100.00% 44.5MB 60.00%
// brute force
// O(N) O(N)
class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length, i = 0, j = 0;
        int[] nums1 = new int[n];
        int[] nums2 = new int[n];
        Arrays.fill(nums1, nums[0]);
        Arrays.fill(nums2, nums[1]);

        // Split
        for (int k = 2; k < n; ++k) {
            if (nums1[i] > nums2[j]) {
                nums1[++i] = nums[k];
            } else {
                nums2[++j] = nums[k];
            }
        }

        // Merge
        for (int k = i + 1, l = 0; l <= j; k++, l++) {
            nums1[k] = nums2[l];
        }
        
        return nums1;
    }
}
