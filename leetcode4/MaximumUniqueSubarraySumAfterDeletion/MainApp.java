// Copyright (C) 2025 by iamslash

import java.util.*;

//                          i
//   nums: 1 2 -1 -2 1 0 -1
// maxNum: 1 2   
//    sum: 1 3
//    set: 1 2

// 1ms 100.005 42.82MB 39.03%
// hash set
// O(N) O(N)
class Solution {
    public int maxSum(int[] nums) {
        int sum = 0, maxNum = -1000, n = nums.length;
        Set<Integer> wndSet = new HashSet<>();

        for (int i = 0; i < n; ++i) {
            maxNum = Math.max(maxNum, nums[i]);
            if (nums[i] <= 0 || wndSet.contains(nums[i])) {
                continue;
            }
            sum += nums[i];
            wndSet.add(nums[i]);
        }

        if (maxNum <= 0) {
            return maxNum;
        }
        return sum;
    }
}
