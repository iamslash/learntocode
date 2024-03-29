// Copyright (C) 2023 by iamslash

import java.util.*;

//             i
// nums: 7 4 3 9 1 8 5 2 6

// 6ms 99.10% 58.3MB 98.76%
// sliding window
// O(N) O(N)
class Solution {
    public int[] getAverages(int[] nums, int k) {
        if (k == 0) {
            return nums;
        }
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int wndLen = k * 2 + 1;
        long wndSum = 0;
        for (int i = 0; i < n; ++i) {
            wndSum += nums[i];
            if (i - wndLen >= 0) {
                wndSum -= nums[i - wndLen];
            }
            if (i >= wndLen - 1) {
                ans[i - k] = (int)(wndSum / wndLen);
            }
        }
        return ans;
    }
}
