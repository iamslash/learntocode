// Copyright (C) 2023 by iamslash

import java.util.*;

// bit manipulation
// 2ms 33.33% 43.9MB 33.33%
class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        int cnt = 0;
        for (int num : nums) {
            if ((num & 0x01) == 0) {
                cnt++;
            }
            if (cnt >= 2) {
                return true;
            }
        }
        return false;
    }
}
