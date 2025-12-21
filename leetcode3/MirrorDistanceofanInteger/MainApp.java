// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 42.68MB 100.00%
// math
// O(1) O(1)
class Solution {
    public int mirrorDistance(int n) {
        int orgNum = n;
        int revNum = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            revNum = revNum * 10 + digit;
        }

        return Math.abs(orgNum - revNum);
    }
}
