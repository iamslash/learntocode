// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.80% 42.9MB 67.06%
// bit manipulation
// O(N) O(1)
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int[] freqs = new int[51];

        for (int num : nums) {
            freqs[num]++;
        }

        int bm = 0;
        for (int num = 1; num <= 50; ++num) {
            if (freqs[num] > 1) {
                bm ^= num;
            }
        }

        return bm;
    }
}
