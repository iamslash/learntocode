// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 69.14% 41.3MB 11.07%
// fast division
// O(lgN) O(1)
class Solution {
    public int divide(int dividend, int divisor) {
        // Handle overflow
        // 32bit interger -2,147,483,648 to 2,147,483,647
        // -2,147,483,648 / -1 = 2,147,483,648
        if (dividend == Integer.MIN_VALUE) {
            if (divisor == -1) {
                return Integer.MAX_VALUE;
            }
            if (divisor == 1) {
                return Integer.MIN_VALUE;
            }
        }

        boolean positive = (dividend > 0) == (divisor > 0);
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        int ans = 0;

        while (dividend - divisor >= 0) {
            int cnt = 1;
            int tmpDivisor = divisor;
            while (dividend - (tmpDivisor << 1) >= 0) {
                tmpDivisor <<= 1;
                cnt <<= 1;
            }
            dividend -= tmpDivisor;
            ans += cnt;
            // System.out.printf("cnt: %d, tmpDivisor: %d\n", cnt, tmpDivisor);
        }

        return positive ? ans : -ans;
    }
}
