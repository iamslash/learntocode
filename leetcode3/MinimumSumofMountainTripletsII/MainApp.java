// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 61.3MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);            
        }
        System.out.println();
    }
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] leftMins = new int[n];
        int[] rightMins = new int[n];
        leftMins[0] = nums[0];
        rightMins[n-1] = nums[n-1];
        for (int i = 1; i < n; ++i) {
            leftMins[i] = Math.min(nums[i], leftMins[i-1]);
        }        
        for (int i = n - 2; i >= 0; --i) {
            rightMins[i] = Math.min(nums[i], rightMins[i+1]);
        }
        // dump(leftMins);
        // dump(rightMins);
        int minSum = Integer.MAX_VALUE;
        for (int i = 1; i < n - 1; ++i) {
            if (leftMins[i] < nums[i] && nums[i] > rightMins[i]) {
                minSum = Math.min(minSum, leftMins[i] + nums[i] + rightMins[i]);
            }
        }
        if (minSum == Integer.MAX_VALUE) {
            return -1;
        }
        return minSum;
    }
}
