// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 42.5MB 100.00%
// bit manipulation
// O(lgN) O(1)
class Solution {
    public int[] evenOddBit(int n) {
        int i = 0;
        int[] ans = new int[2];
        while (n > 0) {
            ans[i % 2] += n & 0x01;
            n >>= 1;
            i++;
        }
        return ans;
    }
}
