// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// count of contiguous num : number of ops
//  n: n/3 + 1
//  1: 0
//  2: 1
//  3: 1
//  4: 2
//  5: 2
//  6: 2
//  7: 3
//  8: 3
//  9: 3
// 10: 4
// 11: 4
// 12: 4
// 13: 5
//
// If there is only one element,
// It's not impossible to make an empty array.
// Return -1
//
// 18ms 89.48% 56.7MB 39.48%
// math, hash map
// O(N) O(N)
class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int num : nums) {
            cntMap.put(num, cntMap.getOrDefault(num, 0) + 1);
        }
        int ans = 0;
        for (int num : cntMap.keySet()) {
            int cnt = cntMap.get(num);
            if (cnt == 1) {
                return -1;
            }
            ans += (cnt + 2) / 3;
        }
        return ans;
    }
}
