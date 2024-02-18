// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 42MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int maxOperations(int[] nums) {
        int n = nums.length, cnt = 1;
        int sum = nums[0] + nums[1];
        for (int i = 2; i < n; i += 2) {
            int wnd = nums[i] + nums[i+1];
            if (sum != wnd) {
                break;
            }
            cnt++;
        }
        return cnt;
    }
}
