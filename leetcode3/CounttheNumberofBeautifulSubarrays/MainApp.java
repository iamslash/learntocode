// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: prefix sum, hash map
//
// Find subarray whose xor is 0.
// Create a Map<Integer, Integer> for subarray xor, frequency
// When same subarray xor happens, increase count of ans.
//
//         i
//   nums: 4 3 1 2 4
//         100 011 001 010 100
//           i
// prefix: 000
// xorMap: 000
//           1
//    ans: 0

// 52ms 90.74% 58.5MB 29.81%
// prefix sum, hash map
// O(N) O(N)
class Solution {
    public long beautifulSubarrays(int[] nums) {
        Map<Integer, Integer> xorMap = new HashMap<>();
        xorMap.put(0, 1);
        int prefix = 0;
        long ans = 0;
        for (int num : nums) {
            prefix ^= num;
            int freq = xorMap.getOrDefault(prefix, 0);
            ans += freq;
            xorMap.put(prefix, freq + 1);
        }
        return ans;
    }
}
