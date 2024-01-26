// Copyright (C) 2024 by iamslash

import java.util.*;


// nums: 2 1 3 4
//    k: 1
//
//       10
//       01
//       11
//      100
//
// xor(nums): 100
//         k:   1
//       xor: 101
//  bitcount:   2

// nums: 2 0 2 0
//    k: 0
//
//       10
//       00
//       10
//       00
//
//        0
//
// xor(nums): 00
//         k:  0
//       xor: 00
//  bitcount:  0

// 1ms 100.00% 56.6MB 54.98%
// bit manipulation
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums, int k) {
        for (int num : nums) {
            k ^= num;
        }
        return Integer.bitCount(k);
    }
}
