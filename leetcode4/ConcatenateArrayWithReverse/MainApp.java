// Copyright (C) 2026 by iamslash

// nums: 1 2 3
//       i
//  ans: 1 . . . . .

// linear traveral
// O(N) O(N)
// 1ms 99.24% 47.30MB 45.26%
class Solution {
    public int[] concatWithReverse(int[] nums) {
        int n = nums.length;
        int[] ans = new int[2 * n];
        
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
            ans[n + i] = nums[n - i - 1];
        }

        return ans;
    }
}
