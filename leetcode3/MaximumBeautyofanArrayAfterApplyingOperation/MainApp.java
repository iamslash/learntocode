// Copyright (C) 2023 by iamslash

import java.util.*;


//    k: 2
//       i
// nums: 1 2 4 6
//             j

// 43ms 95.87% 58.7MB 39.31%
// sort, sliding window
// O(NlgN) O(1)
class Solution {
    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, i = 0, j = 0, bnd = k * 2;
        for (j = 0; j < n; ++j) {
            if (nums[j] - nums[i] > bnd) {
                i++;
            }
        }
        return j - i;
    }
}
