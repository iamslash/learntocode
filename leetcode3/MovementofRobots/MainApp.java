// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: partial sum
//
// When robot conflict they change the direction.
// But it's ok not to change the direction.
//
// a b c d
//
// sum of ditance is

// 15ms 86.39% 55MB 36.39%
// sort, partial sum
// O(NlgN) O(1)
class Solution {
    public int sumDistance(int[] nums, String s, int d) {
        int n = nums.length, mod = 1_000_000_007;
        for (int i = 0; i < n; ++i) {
            nums[i] += s.charAt(i) == 'R' ? d : -d;
        }
        Arrays.sort(nums);
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            long cur = i * (long)nums[i] - (n - 1 - i) * (long)nums[i];
            sum = (sum + cur) % mod;
        }
        return (int)sum;
    }
}
