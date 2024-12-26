// Copyright (C) 2024 by iamslash

import java.util.*;

//                     i
//       nums: 4 5 6 4 4
// numFreqMap: 4 5 6
//             4 1 2
//        ops: 1

// 3ms 64.60% 44.2MB 88.84%
// hash map
// O(N) O(1)
class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length, ops = 0;

        Map<Integer, Integer> numFreqMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            if (numFreqMap.containsKey(nums[i])) {
                int idx = numFreqMap.get(nums[i]);
                ops = Math.max(ops, (idx + 3) / 3);
            }
            numFreqMap.put(nums[i], i);
        }        

        return ops;        
    }
}
