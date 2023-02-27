// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: two pointers
//
// Sort nums.
// We need max possible number of marked indices.
// So set two pointers i = 0, j = (n+1)/2.
// Loop j from (n+1)/2 to n-1.
// Return i * 2

// 29ms 100.00% 61.6MB 85.71%
// two pointers
// O(NlgN) O(1)
class Solution {
    public int maxNumOfMarkedIndices(int[] nums) {
        int n = nums.length, i = 0, j = (n + 1) / 2;
        Arrays.sort(nums);
        while (j < n) {
            if (nums[i] * 2 <= nums[j]) {
                i++;
            }
            j++;
        }
        return i * 2;
    }
}
