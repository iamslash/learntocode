// Copyright (C) 2024 by iamslash

// 1ms 100.00% 45.3MB 34.78%
// linear traversal
// O(N) O(1)
class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length, cnt = 0;
        
        for (int i = 1; i < n - 1; ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                cnt++;
            }
        }

        return cnt;
    }
}
