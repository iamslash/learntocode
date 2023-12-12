// Copyright (C) 2023 by iamslash

//         k: 2
//                    i
//      nums: 1 3 2 3 3
//                    j
// maxNumCnt: 1
//       ans: 6

// Idea: sliding window
//
//    k: 2
//           i
// nums: 1 3 2 3 3
//             j
// First Window, add i to the answer.
// The subarrays are (1,3,2,3), (3,2,3)
//               i
// nums: 1 3 2 3 3
//               j
// Second Window, add i to the answer.
// The subarrays are (1,3,2,3,3), (3,2,3,3), (2,3,3), (3,3)
//
// Finally the answer is 6.

// 5ms 95.89% 60.6MB 21.11%
// two pointers
// O(N) O(1)
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length, maxNum = 0, j = 0, maxNumCnt = 0;
        long cnt = 0;
        for (int i = 0; i < n; ++i) {
            maxNum = Math.max(maxNum, nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] == maxNum) {
                maxNumCnt++;
            }
            while (maxNumCnt >= k) {
                if (nums[j++] == maxNum) {
                    maxNumCnt--;
                }
            }
            cnt += j;
        }
        return cnt;
    }
}
