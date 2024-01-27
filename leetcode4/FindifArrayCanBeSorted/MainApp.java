// Copyright (C) 2024 by iamslash

import java.util.*;

//
//       2  1 2 1 1     
// nums: 3 16 5 4 2 
//            i
//  max: 16
// last: 16

// 1ms 100.0% 44.2MB 92.09%
// bit manipulation
// O(N) O(1)
// difficult
class Solution {
    public boolean canSortArray(int[] nums) {
        int lastGroupMax = 0;
        int maxNum = nums[0], n = nums.length;
   
        for (int i = 1; i < n; i++) {
            if (Integer.bitCount(maxNum) != Integer.bitCount(nums[i])) {
                lastGroupMax = maxNum;
            }
            if (nums[i] > maxNum) {
                maxNum = nums[i];
            }
            if (nums[i] < lastGroupMax) {
                return false;
            }
        }
        return true;
    }
}
