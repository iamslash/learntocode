// Copyright (C) 2024 by iamslash

// 1ms 99.86% 45.7MB 75.79%
// bit manipulation
// O(N) O(1)
class Solution {
    public int singleNumber(int[] nums) {
        int bm = 0;
        for (int num : nums) {
            bm ^= num;
        }
        return bm;
    }
}
