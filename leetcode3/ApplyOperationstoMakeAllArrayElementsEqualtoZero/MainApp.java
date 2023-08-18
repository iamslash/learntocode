// Copyright (C) 2023 by iamslash

import java.util.*;

// // 2183ms 28.48% 57.9MB 61.28%
// // sliding window
// // O(N) O(1)
// class Solution {
//     public boolean checkArray(int[] nums, int k) {
//         int n = nums.length;
//         for (int i = 0; i + k <= n; ++i) {
//             if (nums[i] == 0) {
//                 continue;
//             }
//             int delta = nums[i];
//             for (int j = i; j < i + k; ++j) {
//                 if (nums[j] < delta) {
//                     return false;
//                 }
//                 nums[j] -= delta;
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] > 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// }


//    k: 3
//                 i
// nums: 2 0 1 0 0 0
//  cur: 0

// 1ms 100.00% 58.5MB 29.46%
// sliding window
// O(N) O(1)
class Solution {
    public boolean checkArray(int[] nums, int k) {
        int cur = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (cur > nums[i]) {
                return false;
            }
            nums[i] -= cur;
            cur += nums[i];
            if (i >= k - 1) {
                cur -= nums[i - k + 1];
            }
        }
        return cur == 0;
    }
}
