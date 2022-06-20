// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 3 4 5 6
//  sum: 6 * (6 + 1) / 2 - 2 * (2 + 1) / 2
//                    21 - 3
// nums: 3 4 5
//  sum: 5 * (5 + 1) / 2 - 2 * (2 + 1) / 2
//                    15 - 3

// 32ms 55.10% 79mb 62.42%
// sort
// O(NlgN) O(N)
class Solution {
    public long minimalKSum(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] sorted = new int[n+1];
        System.arraycopy(nums, 0, sorted, 0, n);
        sorted[n] = 1_000_000_000;
        long sum = 0, prvNum = 0;
        n += 1;
        for (int i = 0; i < n && k > 0; ++i) {
            if (sorted[i] - prvNum > 1) {
                long a = prvNum, b = Math.min(sorted[i] - 1, a + k);
                // System.out.printf("i:%d, a:%d, b:%d, k:%d\n", i, a, b, k);
                sum += b * (b + 1) / 2;
                sum -= a * (a + 1) / 2;
                k -= (b - a);
            }
            prvNum = sorted[i];
        }
        return sum;
    }
}
