// Copyright (C) 2022 by iamslash

import java.util.*;

// 6ms 33.33% 95.2MB 66.67%
// partial sum
// O(N) O(N)
class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length, cnt = 0;
        long[] ps = new long[n+1];
        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + nums[i];
        }
        for (int i = 0; i < n-1; ++i) {
            if (ps[i+1] >= ps[n] - ps[i+1]) {
                cnt++;
            }
        }
        return cnt;
    }
}

// 4ms 33.33% 82.8MB 66.67%
// brute force
// O(N) O(1)
class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length, cnt = 0;
        long lsum = 0, rsum = 0;
        for (int num : nums) {
            rsum += num;
        }
        for (int i = 0; i < n-1; ++i) {
            lsum += nums[i];
            rsum -= nums[i];
            if (lsum >= rsum) {
                cnt++;
            }
        }
        return cnt;
    }
}
