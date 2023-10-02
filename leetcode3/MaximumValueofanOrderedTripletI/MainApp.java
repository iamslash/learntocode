// Copyright (C) 2023 by iamslash

import java.util.*;

// // 3ms 60.00% 40MB 100.00%
// // brute force
// // O(N^3) O(1)
// class Solution {
//     public long maximumTripletValue(int[] nums) {
//         int n = nums.length;
//         long ans = 0;
//         for (int i = 0; i < n - 2; ++i) {
//             for (int j = i + 1; j < n - 1; ++j) {
//                 for (int k = j + 1; k < n; ++k) {
//                     long val = (nums[i] - nums[j]) * (long)nums[k];
//                     ans = Math.max(ans, val);
//                 }
//             }
//         }
//         return Math.max(0, ans);
//     }
// }

// Idea: math
//
//  maxa: max(num)
// maxab: max(maxa - num)
//   ans: max(ans, maxab * num)
//
// 1ms 100.00% 39.9MB 100.00%
// math
// O(N) O(1)
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, maxa = 0, maxab = 0;
        for (int num : nums) {
            ans = Math.max(ans, 1L * maxab * num);
            maxab = Math.max(maxab, maxa - num);
            maxa = Math.max(maxa, num);
        }
        return ans;
    }
}
