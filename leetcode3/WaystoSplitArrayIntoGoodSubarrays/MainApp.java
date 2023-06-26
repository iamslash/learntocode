// Copyright (C) 2023 by iamslash

import java.util.*;

//         i
// 0 1 0 0 1 0 0 1
//               j   

// 13ms 96.92% 59.3MB 85.82%
// two pointers
// O(N) O(1)
class Solution {
    public int numberOfGoodSubarraySplits(int[] nums) {
        int mod = 1_000_000_007;
        int n = nums.length, i = 0;
        long cnt = 1;
        // First 1
        while (i < n && nums[i] == 0) {
            i++;
        }
        if (i == n) {
            return 0;
        }
        // Traverse
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[j] == 0) {
                j++;
            }
            if (j == n) {
                break;
            }
            cnt = cnt * (j - i) % mod;
            i = j;
        }
        return (int)cnt;
    }
}
