// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: bit manipulation
// 
// nums: 2 3 5 7 11
//       0010 0011 0101 0111 1011 1101
//  ans: - 1 4 3
//       1111 0001 0100 0011 1001 1111 
//
// nums[i] = ans[i] || (ans[i] + 1)
//
// Think about `ans[i]`, `ans[i] + 1`.
// The one is odd and The other is even.
// nums[i] is odd cause only even prime
// which is '2' whose ans is -1.
//
// 
//  num + 1 is even
// -num + 1 is 2's complement of num
// (num + 1) & (-num - 1) remain the right most bit.
//
//      num:  5    0101
//  num + 1:  6    0110
// ~num    :       1010
// -num    :       1011 
// -num - 1: -6    1010
// (num + 1) & (-num - 1): 0010
// ((num + 1) & (-num - 1)) / 2: 0001
// num - ((num + 1) & (-num - 1)) / 2: 0100
//
// Difficult to understand

// 1ms 100.00% 44.9MB 100.00%
// bit manipulation
// O(N) O(N)
class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size(), ans[] = new int[n];

        for (int i = 0; i < n; ++i) {
            int num = nums.get(i);

            if (num % 2 == 0) {
                ans[i] = -1;
            } else {
                ans[i] = num - ((num + 1) & (-num - 1)) / 2;
            }
        }

        return ans;
    }
}
