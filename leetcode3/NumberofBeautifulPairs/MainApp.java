// Copyright (C) 2023 by iamslash

import java.util.*;

// 

// // 39ms 50.00% 42.8MB 25.00%
// // brute force
// // O(N^2) O(1)
// class Solution {
//     private int gcd(int a, int b) {
//         // base
//         if (b == 0) {
//             return a;
//         }
//         // recursion
//         return gcd(b, a % b);
//     }
//     public int countBeautifulPairs(int[] nums) {
//         int n = nums.length, cnt = 0;
//         for (int i = 0; i < n - 1; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int a = nums[i]; 
//                 while (a >= 10) {
//                     a /= 10;
//                 }
//                 int b = nums[j] % 10;
//                 if (gcd(a, b) == 1) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// }

// 26ms 90.49% 43.2MB 88.03%
// brute force, gcd
// O(N^2) O(1)
class Solution {
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public int countBeautifulPairs(int[] nums) {
        int n = nums.length, cnt = 0;
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 10) {
                nums[i] /= 10;
            }
            for (int j = i + 1; j < n; ++j) {
                if (gcd(nums[i], nums[j] % 10) == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
