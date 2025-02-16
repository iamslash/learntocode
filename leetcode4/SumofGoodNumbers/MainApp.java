// Copyright (C) 2025 by iamslash

import java.util.*;

// i + k < n

// 1ms 100.00% 44.32MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
    public int sumOfGoodNumbers(int[] nums, int k) {
        int sum = 0, n = nums.length;

        for (int i = 0; i < n; ++i) {
            int left = i < k ? -1 : i - k;
            int right = i + k >= n ? -1 : i + k;

            if ((left < 0 && right < 0) ||
                (left < 0 && right >= 0 && nums[i] > nums[right]) ||
                (left >= 0 && right < 0 && nums[left] < nums[i]) ||
                (left >= 0 && right >= 0 &&
                 nums[left] < nums[i] && nums[i] > nums[right])) {
                sum += nums[i];
            }
        }

        return sum;
    }
}
