// Copyright (C) 2025 by iamslash

import java.util.*;

// sort
// O(NlgN) O(1)
class Solution {
    public int[] transformArray(int[] nums) {

        int n = nums.length;
        
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] % 2 == 0 ? 0 : 1;
        }

        Arrays.sort(nums);

        return nums;
    }
}

// 1ms 100.00% 45.12MB 100.00%
// sort
// O(N) O(1)
class Solution {
    public int[] transformArray(int[] nums) {

        int n = nums.length, cntZero = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                cntZero++;
            }
        }

        for (int i = 0; i < n; ++i) {
            nums[i] = cntZero > 0 ? 0 : 1;
            cntZero--;
        }

        return nums;
    }
}
