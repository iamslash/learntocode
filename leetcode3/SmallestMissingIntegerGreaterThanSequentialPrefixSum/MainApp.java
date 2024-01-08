// Copyright (C) 2023 by iamslash

import java.util.*;

//               i
//   nums: 1 2 3 2 5
// cntSum: 1 3 6
//         i
//   nums: 1 2 2 3 5
//

// 1ms 100.00% 42MB 25.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int missingInteger(int[] nums) {
        int cntSum = nums[0], n = nums.length;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] + 1 == nums[i]) {
                cntSum += nums[i];
            } else {
                break;
            }
        }
        Arrays.sort(nums);
        for (int i = 0; i < n; ++i) {
            if (cntSum == nums[i]) {
                cntSum++;
            }
        }
        return cntSum;
    }
}
