// Copyright (C) 2024 by iamslash

import java.util.*;


// nums: 3 -2 1 4
//    l: 2
//    r: 3

//
// nums: 3 -2 1 4 5 6 7
//    l: 3
//    r: 5
//
//       .  .
//          . .
//            . .

// // 28ms 11.52% 44.3MB 68.71%
// // brute force
// // O(N^2) O(1)
// class Solution {
//     public int minimumSumSubarray(List<Integer> nums, int l, int r) {
//         int n = nums.size(), minSum = -1;

//         for (int wnd = l; wnd <= r; ++wnd) {
//             for (int i = 0; i <= n - wnd; ++i) {
//                 int sum = 0;
//                 for (int j = i; j < i + wnd; ++j) {
//                     sum += nums.get(j);
//                 }
//                 if (sum > 0) {
//                     if (minSum < 0 || sum < minSum) {
//                         minSum = sum;
//                     }
//                 }
//             }
//         }

//         return minSum;
//     }
// }

// nums: 3 -2 1 4
//    l: 2
//    r: 3
//           i
// psum: 0 3 1 2 6

// 2ms 94.12% 44.3MB 68.71%
// prefix sum
// O(N) O(N)
class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size(), minSum = -1;
        int[] psum = new int[n + 1];

        for (int i = 0; i < n; ++i) {
            psum[i + 1] = psum[i] + nums.get(i);
        }

        for (int wnd = l; wnd <= r; ++wnd) {
            for (int rIdx = wnd; rIdx < n + 1; ++rIdx) {
                int sum = psum[rIdx] - psum[rIdx - wnd];

                if (sum > 0) {
                    if (minSum < 0 || sum < minSum) {
                        minSum = sum;
                    }
                }
            }
        }

        return minSum;
    }
}
