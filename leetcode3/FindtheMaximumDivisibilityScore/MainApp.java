// Copyright (C) 2023 by iamslash

import java.util.*;

// 289ms 100.00% 43MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int maxDiv = divisors[0], maxCnt = 0, n = nums.length, m = divisors.length;
        for (int j = 0; j < n; ++j) {
            if (nums[j] % maxDiv == 0) {
                maxCnt++;
            }
        }
        for (int i = 1; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] % divisors[i] == 0) {
                    cnt++;
                }
            }
            if (maxCnt < cnt) {
                maxCnt = cnt;
                maxDiv = divisors[i];
            } else if (maxCnt == cnt) {
                maxDiv = Math.min(maxDiv, divisors[i]);
            }
        }
        return maxDiv;
    }
}

