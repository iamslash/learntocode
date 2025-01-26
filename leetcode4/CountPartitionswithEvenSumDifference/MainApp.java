// Copyright (C) 2025 by iamslash

import java.util.*;

// nums: 10 10 3 7 6
//        i
//

// 0ms 100.00% 42.38MB 
// linear traversal
// O(N) O(1)
class Solution {
    public int countPartitions(int[] nums) {
        int firstSum = 0, glbSum = 0;
        int cnt = 0, n = nums.length;

        for (int i = 0; i < n; ++i) {
            glbSum += nums[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            firstSum += nums[i];
            int secondSum = glbSum - firstSum;
            if ((firstSum - secondSum) % 2 == 0) {
                cnt++;
            }
        }

        return cnt;
    }
}
