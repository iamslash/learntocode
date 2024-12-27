// Copyright (C) 2024 by iamslash


//   m: 1
//   k: 3
//   A: 1 2 4 4 4 4
//              i
// cnt: 3

//    m: 2
//    k: 2
// nums: 1 2 1 2 1 1 1 3
//           i
//  cnt: 2

//    m: 2
//    k: 3
// nums: 1 2 1 2 1 3 1 2
//                   i
//  cnt: 0
// false

//    m: 2
//    k: 3
// nums: 1 2 1 2 1 2 1 3
//             i   .
//  cnt: 4
//  true

// 0ms 100.00% 41.2% 65.50%
// linear traversal
// O(N) O(1)
class Solution {
    public boolean containsPattern(int[] nums, int m, int k) {
        int n = nums.length, cnt = 0;

        for (int i = 0; i + m < n; ++i) {
            if (nums[i] == nums[i + m]) {
                cnt++;
            } else {
                cnt = 0;
            }

            if (cnt == (k - 1) * m) {
                return true;
            }
        }

        return false;        
    }
}
