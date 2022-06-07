// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 1 2 3 4 5 6 7
//       7 6 5 4 3 2 1
//       5 6 7 1 2 3 4 

// 1ms 80.42% 63.9MB
// math
// O(N) O(1)
class Solution {
    public void rotate(int[] nums, int k) {       
        int n = nums.length;
        k %= n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
    private void reverse(int[] nums, int l, int r) {
        while (l < r) {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
}
