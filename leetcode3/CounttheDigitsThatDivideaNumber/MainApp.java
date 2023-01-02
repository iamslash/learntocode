// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 41.3MB 14.97%
// brute force
// O(N) O(1)
class Solution {
    public int countDigits(int num) {
        int ans = 0, org = num;
        while (num > 0) {
            int rem = num % 10;
            // System.out.printf("num: %d, rem: %d\n", num, rem);
            if (org % rem == 0) {
                ans++;
            }
            num /= 10;
        }
        return ans;
    }
}
