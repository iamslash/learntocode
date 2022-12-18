// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 0010 0001 0000 0011
//  pre: 0010 0011 0011 0110
//  ans: 0010 0011 0011 0111

// prefix sum
// O(N) O(1)
// 14ms 41.46% 79.4MB 7.32%
// difficult
class Solution {
    public long subsequenceSumOr(int[] nums) {
        long ans = 0, pre = 0;
        for (int i = 0; i < nums.length; ++i) {
            pre += nums[i];
            ans |= nums[i];
            ans |= pre;
        }
        return ans;
    }
}
