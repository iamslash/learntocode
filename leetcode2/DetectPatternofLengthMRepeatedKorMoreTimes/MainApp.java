// Copyright (C) 2024 by iamslash


//    m: 2
//    k: 3
//       s   
// nums: 1 2 1 2 1 2 1 3
//       i     .
//  true

// 0ms 100.00% 41.2MB 65.50%
// brute force
// O(N^2) O(1)
class Solution {
    public boolean containsPattern(int[] nums, int m, int k) {
        int n = nums.length;

        // Iterate through all possible starting points of patterns
        for (int start = 0; start <= n - m * k; start++) {
            boolean isPattern = true;

            // Compare each segment of length m to the next segment
            for (int i = 0; i < m * (k - 1); i++) {
                if (nums[start + i] != nums[start + i + m]) {
                    isPattern = false;
                    break;
                }
            }

            // If we found a valid pattern, return true
            if (isPattern) {
                return true;
            }
        }

        // No valid pattern found
        return false;
    }
}

// Idea:
//
// A pattern is a subarray (consecutive sub-sequence) that consists of
// one or more values, repeated multiple times **consecutively** without
// overlapping
//
// The meaning of `cnt` is not the number of repeated patterns but the
// number of matching characters. which means that
// cnt + m == k * m
//     cnt == (k - 1) * m

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
//           i   .
//  cnt: 1
//  true

//    m: 2
//    k: 3
// nums: 3 1 2 1 2 1 2 1 3
//               i   .
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
