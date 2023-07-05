// Copyright (C) 2023 by iamslash

import java.util.*;

//           i
//   nums: 5 4 2 4
//                 j
//    cnt: 1 3 5 8
// 
// numMap: 5 4
//         1 1

// 40ms 60.53% 57.8MB 49.85%
// hash map, sliding window
// O(NlgN) O(N)
class Solution {
    public long continuousSubarrays(int[] nums) {
        int i = 0, n = nums.length;
        long cnt = 0;
        TreeMap<Integer, Integer> numMap = new TreeMap<>();
        for (int j = 0; j < n; ++j) {
            numMap.put(nums[j], numMap.getOrDefault(nums[j], 0) + 1);
            while (i < j && numMap.lastKey() - numMap.firstKey() > 2) {
                numMap.put(nums[i], numMap.get(nums[i]) - 1);
                if (numMap.get(nums[i]) == 0) {
                    numMap.remove(nums[i]);
                }
                i++;
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
}
