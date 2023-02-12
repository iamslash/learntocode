// Copyright (C) 2023 by iamslash

import java.util.*;

// math
// 1ms 100.00% 41.8MB 77.78%
class Solution {
    private long concatNums(int a, int b) {
        long num = b;
        while (num > 0) {
            a *= 10;
            num /= 10;
        }
        return a + b;
    }
    public long findTheArrayConcVal(int[] nums) {
        int i = 0, j = nums.length - 1;
        long ans = 0;
        while (i < j) {
            ans += concatNums(nums[i++], nums[j--]);
        }
        if (i == j) {
            ans += nums[i];
        }
        return ans;
    }
}
