// Copyright (C) 2023 by iamslash

import java.util.*;

// 3ms 100.00% 43.5MB 100.00%
// hash map
// O(N) O(1)
class Solution {
    private int maxDigit(int num) {
        int rst = 0;
        while (num > 0) {
            rst = Math.max(rst, num % 10);
            num /= 10;
        }
        return rst;
    }
    public int maxSum(int[] nums) {
        int n = nums.length;
        int[] maxFirst = new int[10];
        int[] maxSecond = new int[10];
        Arrays.fill(maxFirst, -1);
        Arrays.fill(maxSecond, -1);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int digit = maxDigit(num);
            if (num > maxFirst[digit]) {
                maxSecond[digit] = maxFirst[digit];
                maxFirst[digit] = num;
            } else if (num > maxSecond[digit]) {
                maxSecond[digit] = num;
            }
        }
        int ans = -1;
        for (int i = 0; i < maxFirst.length; ++i) {
            if (maxFirst[i] >= 0 && maxSecond[i] >= 0) {
                ans = Math.max(ans, maxFirst[i] + maxSecond[i]);
            }
        }
        return ans;
    }
}
