// Copyright (C) 2022 by iamslash

import java.util.*;

//                      i
// nums: 5 3 4 4 7 3 6 11 8 5 11
//                      j

//        i
// nums: 10 1 2 3 4 5 6 1 2 3
//        j

// Wrong Answer
//    Input: [10,1,2,3,4,5,6,1,2,3]
//   Output: 9
// Expected: 6
// two pointers
// O(N) O(1)
class Solution {
    public int totalSteps(int[] nums) {
        int maxLen = 0, n = nums.length, i = 0, j = 0;
        while (i < n) {
            i = j++;            
            while (j < n && nums[i] > nums[j]) {
                ++j;
            }
            maxLen = Math.max(maxLen, j - i - 1);
        }
        return maxLen;
    }
}

// iterative dynamic programming, mono stack
// O(N) O(N)
class Solution {
    public int totalSteps(int[] nums) {
        int n = nums.length, maxLen = 0, j = -1;
        int[] C = new int[n], stck[] = new int[n];
        for (int i = n-1; i >= 0; --i) {
            while (j >= 0 && nums[i] > nums[stck[j]]) {
                C[i] = Math.max(++C[i], C[stck[j--]]);
                maxLen = Math.max(maxLen, C[i]);
            }
            stck[++j] = i;
        }
        return maxLen;
    }
}
