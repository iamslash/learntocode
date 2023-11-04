// Copyright (C) 2023 by iamslash

import java.util.*;

// nums1: 3 2 0 1 0
// nums2: 6 5 0
//  sum1: 11
//  cnt1: 1
//  sum2: 6
//  cnt2: 2

// nums1: 2 0 2 0
// nums2: 1 4
//  sum1: 5
//  cnt1: 0
//  sum2: 4
//  cnt2: 2

// 3ms 98.81% 58.4MB 89.58%
// greedy
// O(N) O(1)
class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, cnt1 = 0, sum2 = 0, cnt2 = 0;
        for (int num : nums1) {
            sum1 += num;
            if (num == 0) {
                cnt1++;
            }
        }
        for (int num : nums2) {
            sum2 += num;
            if (num == 0) {
                cnt2++;
            }
        }
        if (sum1 + cnt1 < sum2 + cnt2) {
            long tsum = sum1, tcnt = cnt1;
            sum1 = sum2;
            cnt1 = cnt2;
            sum2 = tsum;
            cnt2 = tcnt;
        }
        sum1 += cnt1;
        // System.out.printf("sum1: %d, cnt1: %d, sum2: %d, cnt2: %d\n", sum1, cnt1, sum2, cnt2);
        if (sum1 - sum2 < cnt2 || (sum1 > sum2 && cnt2 == 0)) {
            return -1;
        }
        return sum1;
    }
}
