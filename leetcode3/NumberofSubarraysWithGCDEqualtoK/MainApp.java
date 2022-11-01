// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 3
//                 i
// nums: 3 3 1 2 3 3
//                 j

// 16ms 81.25% 42.5MB 64.74%
// brute force
// O(N^2) O(1)
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public int subarrayGCD(int[] nums, int k) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n && nums[j] % k == 0; ++j) {
                nums[i] = gcd(nums[i], nums[j]);
                if (nums[i] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
