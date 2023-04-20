// Copyright (C) 2023 by iamslash

//   nums: 2 3  7  5 10
//                    i
// maxNum: 2 3  7  7 10
//   conv: 4 6 14 12 20
//    ans: 

// 3ms 78.22% 64.6MB 77.87%
// prefix sum
// O(N) O(N)
class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length, sum = 0, maxNum = 0;
        long[] ans = new long[n];
        for (int i = 0; i < n; ++i) {
            maxNum = Math.max(maxNum, nums[i]);
            nums[i] += maxNum;
            ans[i] = i > 0 ? ans[i-1] + nums[i] : nums[i];
        }
        return ans;
    }
}
