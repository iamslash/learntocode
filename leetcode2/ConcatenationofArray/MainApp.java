// Copyright (C) 2023 by iamslash

import java.util.*;

// // 1ms 96.12% 44.3MB 38.03%
// // brute force
// // O(N) O(N)
// class Solution {
//     public int[] getConcatenation(int[] nums) {
//         int n = nums.length;
//         int[] ans = new int[n + n];
//         for (int i = 0; i < n + n; ++i) {
//             ans[i] = nums[i % n];
//         }
//         return ans;
//     }
// }

// 1ms 96.12% 44.4MB 26.13%
// brute force
// O(N) O(N)
class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n + n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        return ans;
    }
}
