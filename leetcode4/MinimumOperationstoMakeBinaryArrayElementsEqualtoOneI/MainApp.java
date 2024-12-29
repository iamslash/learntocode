// Copyright (C) 2024 by iamslash

import java.util.*;


//           i
// nums: 0 1 1 1 0 0
//       1 0 0 1 0 0
//       1 1 1 0 0 0
//       1 1 1 1 1 1

//             i
// nums: 0 1 1 1
//       1 0 0 1
//       1 1 1 0

// 6ms 100.00% 56.96MB 88.89%
// bit manipulation
// O(N) O(1)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                nums[i] = 1;
                cnt++;

                if (i + 1 < n) {
                    nums[i + 1] ^= 1;
                }
                if (i + 2 < n) {
                    nums[i + 2] ^= 1;
                }
                if (i == n - 1 || i == n - 2) {                
                    return -1;
                }
            }
        }

        if (nums[n - 1] == 0) {
            return -1;
        }
        return cnt;
    }
}
