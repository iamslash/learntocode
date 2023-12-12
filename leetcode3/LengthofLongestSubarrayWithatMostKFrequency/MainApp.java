// Copyright (C) 2023 by iamslash

import java.util.*;

//      k: 2
//           i
//   nums: 1 2 3 1 2 3 1 2
//                       j
// cntMap: 1 2 3
//         2 2 2
//         

// Idea: sliding window
//
// The frequency of each element should be less than or equal to k.
//

// 63ms 75.11% 57.1MB 63.14%
// sliding window
// O(N) O(N)
class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int cnt = 0, i = 0, n = nums.length;
        for (int j = 0; j < n; ++j) {
            cntMap.put(nums[j], cntMap.getOrDefault(nums[j], 0) + 1);
            while (cntMap.get(nums[j]) > k) {
                cntMap.put(nums[i], cntMap.get(nums[i++]) - 1);
            }
            cnt = Math.max(cnt, j - i + 1);
        }
        return cnt;
    }
}

