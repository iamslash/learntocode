// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// 
// case 1) nums: a b
//
// [(a | a) & a] ^ [(a | a) & b] ^
// [(a | b) & a] ^ [(a | b) & b] ^
// [(b | a) & a] ^ [(b | a) & b] ^
// [(b | b) & a] ^ [(b | b) & b]
// =
// a ^ [a & b] ^
// [(a | b) & a] ^ [(a | b) & b] ^
// [(a | b) & a] ^ [(a | b) & b] ^
// [b & a] ^ b
// = a ^ b
//
// case 2) nums: a b c
//
// The answer will be a ^ b ^c.

// 1ms 100.00% 58.4MB 100.00%
// math
// O(N) O(1)
class Solution {
    public int xorBeauty(int[] nums) {
        int bm = 0;
        for (int num : nums) {
            bm ^= num;
        }
        return bm;
    }
}
