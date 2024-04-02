// Copyright (C) 2024 by iamslash

import java.util.*;

//             i
// nums: 0 1 1 1
//  cum: 1 2 1 1
//  cnt: 1 3 4 5

//              i
// nums: 1 0 1  0
//  cum: 1 2 3  4
//  cnt: 1 3 6 10

// 3ms 96.97% 55.7MB 97.12%
// math
// O(N) O(1)
class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long cnt = 1;
        int cum = 1, n = nums.length;

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                cum = 1;
            } else {
                cum++;
            }            
            cnt += cum;
        }

        return cnt;
    }
}
