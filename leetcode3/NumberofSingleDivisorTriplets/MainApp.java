// Copyright (C) 2022 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // math
// // O(N^3) O(1)
// class Solution {
//     public long singleDivisorTriplet(int[] nums) {
//         long cnt = 0, n = nums.length;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i+1; j < n; ++j) {
//                 for (int k = j+1; k < n; ++k) {
//                     int sum = nums[i] + nums[j] + nums[k];
//                     int rst = (sum % nums[i] == 0 ? 1 : 0) +
//                         (sum % nums[j] == 0 ? 1 : 0) +
//                         (sum % nums[k] == 0 ? 1 : 0);
//                     if (rst == 1) {
//                         cnt += 6;
//                     }
//                 }
//             }
//         }
//         return cnt;
//     }
// }


// a b c
// 2 2 3

// 101ms 100.00% 68.6MB 100.00%
// permutation
// O(1) O(1)
class Solution {
    public long singleDivisorTriplet(int[] nums) {
        int[] cnts = new int[101];
        for (int num : nums) {
            cnts[num]++;
        }
        long ans = 0;
        // when two nums are same
        for (int a = 1; a <= 100; ++a) {
            if (cnts[a] >= 2) {
                for (int b = 1; b <= 100; ++b) {
                    if (a == b || cnts[b] == 0) {
                        continue;
                    }
                    int sum = 2 * a + b;
                    if (sum % b == 0 && sum % a != 0) {
                        ans += 3L * cnts[a] * (cnts[a] - 1) * cnts[b];
                    }
                }
            }
        }
        // when others
        for (int a = 1; a <= 100; ++a) {
            if (cnts[a] == 0) {
                continue;
            }
            for (int b = a+1; b <= 100; ++b) {
                if (cnts[b] == 0) {
                    continue;
                }
                for (int c = b+1; c <= 100; ++c) {
                    if (cnts[c] == 0) {
                        continue;
                    }
                    long sum = a + b + c;
                    int rst = (sum % a == 0 ? 1 : 0) +
                        (sum % b == 0 ? 1 : 0) +
                        (sum % c == 0 ? 1 : 0);
                    if (rst == 1) {
                        ans += 6L * cnts[a] * cnts[b] * cnts[c];
                    }
                }
            }
        }
        return ans;
    }
}
