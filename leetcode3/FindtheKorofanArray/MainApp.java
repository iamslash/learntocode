// Copyright (C) 2023 by iamslash

import java.util.*;

// nums:
//  7: 0111
// 12: 1100
//  9: 1001
//  8: 1000
//  9: 1001
// 15: 1111

// 2ms 100.00% 43MB 25.00%
// bit manipulation
// O(N) O(1)
class Solution {
    public int findKOr(int[] nums, int k) {
        int n = nums.length;
        int[] bitCnts = new int[31];
        for (int num : nums) {
            int i = 0;
            while (num > 0) {
                if ((num & 0x01) > 0) {
                    bitCnts[i]++;
                }
                num >>= 1;
                i++;
            }
        }
        int ans = 0;
        for (int i = 0; i < bitCnts.length; ++i) {
            if (bitCnts[i] >= k) {
                ans += (1 << i);
            }
        }
        return ans;
    }
}
