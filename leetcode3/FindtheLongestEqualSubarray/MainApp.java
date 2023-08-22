// Copyright (C) 2023 by iamslash

import java.util.*;

//       k: 3
//          i
//    nums: 1 3 2 3 1 3
//                      j
//  cntMap: 1 2 3
//          2 1 3
// maxFreq: 3

// 95ms 43.95% 63.5MB 50.00%
// sliding window
// O(N) O(N)
class Solution {
    public int longestEqualSubarray(List<Integer> nums, int k) {
        int n = nums.size(), maxFreq = 0;
        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int i = 0, j = 0; j < n; ++j) {
            int a = nums.get(i), b = nums.get(j);
            cntMap.put(b, cntMap.getOrDefault(b, 0) + 1);
            maxFreq = Math.max(maxFreq, cntMap.get(b));
            if (j - i + 1 - maxFreq > k) {
                cntMap.put(a, cntMap.get(a) - 1);
                i++;
            }
        }
        return maxFreq;
    }
}
