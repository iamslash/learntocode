// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: gaussian summation
// n = (maxNum + k - 1)
// m = (maxNum - 1)
// ans: n * (n + 1) / 2 - m * (m + 1) / 2

// 3ms 100.00% 43MB 33.33%
// math
// O(N) O(1)
class Solution {
    public int maximizeSum(int[] nums, int k) {
        int maxNum = 0;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
        }
        int n = maxNum + k - 1;
        int m = maxNum - 1;
        return (n * (n + 1) / 2) - (m * (m + 1) / 2);
    }
}
