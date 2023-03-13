// Copyright (C) 2023 by iamslash

import java.util.*;

// 31ms 99.77% 51.5MB 52.57%
// greedy, sort
// O(NlgN) O(1)
class Solution {
    public int maxScore(int[] nums) {
        Arrays.sort(nums);
        int cnt = 0;
        long sum = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            sum += nums[i];
            if (sum > 0) {
                cnt++;
            } 
        }
        return cnt;
    }
}
