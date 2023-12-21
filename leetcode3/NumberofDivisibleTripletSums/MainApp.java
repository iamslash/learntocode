// Copyright (C) 2023 by iamslash

import java.util.*;

//    d: 5
//       i       
// nums: 3 3 4 7 8
//         j
//  map: 6
//       1

// Idea: hash map
//
// (a + b + c) % d = 0
//
// (d - c % d) % d = w
// (a + b) % d     = x
// (w + x) % d = 0

// 166ms 25.00% 44.7MB 26.32%
// hash map
// O(N^2) O(N)
class Solution {
    public int divisibleTripletCount(int[] nums, int d) {
        int cnt = 0, n = nums.legth;
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> cntMap = new HashMap<>();
            for (int j = i + 1; j < n; j++) {
                cnt += cntMap.getOrDefault((d - nums[j] % d) % d, 0);
                int key = (nums[i] + nums[j]) % d;
                cntMap.put(key, cntMap.getOrDefault(key, 0) + 1);
            }
        }
        return cnt;
    }
}
