// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: math
//
// mximum value = max(nums[i] - nums[j] + nums[k])
//   i < j < k
//   nums[i] < nums[j] < nums[k]
//
// rightMaxNum[i]: right max num including nums[i]
// numSet: set of nums[1..n)
// for every nums[j] (0 < j < n - 1)
// nums[i] = numSet.lower(nums[j])
// nums[k] = rightMaxNum[j+1]
//
// ans = nums[i] - nums[j] + nums[k]

// 203ms 100.00% 57.2MB 100.00%
// binary search
// O(NlgN) O(1)
class Solution {
    public int maximumTripletValue(int[] nums) {
        int n = nums.length;
        int[] rightMaxNum = new int[n + 1];

        for (int i = n - 1; i >= 0; --i) {
            rightMaxNum[i] = Math.max(rightMaxNum[i + 1], nums[i]);
        }

        int ans = 0;
        TreeSet<Integer> numSet = new TreeSet<>();
        numSet.add(nums[0]);

        for (int j = 1; j < n - 1; ++j) {
            Integer numI = numSet.lower(nums[j]);
            int numK = rightMaxNum[j + 1];
            if (numI != null && numK > nums[j]) {
                // System.out.printf("nums[i]: %d, nums[j]: %d, nums[k]: %d\n", numI, nums[j], numK);
                ans = Math.max(ans, numI - nums[j] + numK);
            }
            numSet.add(nums[j]);
        }

        return ans;
    }
}
