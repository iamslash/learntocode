// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 6.81% 43.2MB 78.52%
// brute force
// O(N) O(1)
class Solution {
    public int sumOfSquares(int[] nums) {
        int n = nums.length, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) != 0) {
                continue;
            }
            ans += nums[i] * nums[i];
        }
        return ans;
    }
}
// brute force
// O(N) O(1)
class Solution {
    public int sumOfSquares(int[] nums) {
        int n = nums.length, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (n % i != 0) {
                continue;
            }
            ans += nums[i] * nums[i];
        }
        return ans;
    }
}
