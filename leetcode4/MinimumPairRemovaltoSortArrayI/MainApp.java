// Copyright (C) 2025 by iamslash

import java.util.*;
//                
//   nums: 5 2 3 1
//         i
//         5 6 4 1
//             .
// maxSum: 11          
// maxIdx: 0
// nonDec: t
//    len: 2
//    cnt: 2

// 1ms 100.00% 42.48MB 96.12%
// brute force
// O(N^2) O(1)
class Solution {
    public int minimumPairRemoval(int[] nums) {
        int cnt = 0, len = nums.length;

        while (len > 1) {
            boolean nonDecreasing = true;
            int maxSum = Integer.MAX_VALUE;
            int maxIdx = -1;

            for (int i = 0; i < len - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    nonDecreasing = false;
                }
                if (nums[i] + nums[i + 1] < maxSum) {
                    maxSum = nums[i] + nums[i + 1];
                    maxIdx = i;
                }
            }

            if (nonDecreasing) {
                break;
            }

            nums[maxIdx] = maxSum;
            for (int i = maxIdx + 1; i < len - 1; ++i) {
                nums[i] = nums[i + 1];
            }

            len--;
            cnt++;
        }

        return cnt;
    }
}
