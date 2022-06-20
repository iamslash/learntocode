// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 3 4 5 6
//  sum: 6 * (6 + 1) / 2 - 2 * (2 + 1) / 2
//                    21 - 3
// nums: 3 4 5
//  sum: 5 * (5 + 1) / 2 - 2 * (2 + 1) / 2
//                    15 - 3

// sort
// O(NlgN) O(N)
class Solution {
    public long minimalKSum(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, sum = 0;
        int[] sorted = new int[n+1];
        sorted[0] = 1;
        System.arraycopy(nums, 0, sorted, 1, n);
        n += 1;
        for (int i = 1; i < n && k > 0; ++i) {
            if (sorted[i] - sorted[i-1] > 1) {
                int a = sorted[i-1], b = Math.min(sorted[i] - 1, a + k);
                System.out.printf("i:%d, a:%d, b:%d, k:%d\n", i, a, b, k);
                sum += b * (b + 1) / 2;
                sum -= a * (a + 1) / 2;
                k -= (b - a);
            }
        }
        return sum;
    }
}
