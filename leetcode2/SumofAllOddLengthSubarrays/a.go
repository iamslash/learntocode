/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// A: 1 2 3 4 5
// 
// 1 2 3 4 5 subarray length 1
// 1 2 X X X subarray length 2
// X 2 3 X X subarray length 2
// X X 3 4 X subarray length 2
// X X X 4 5 subarray length 2
// 1 2 3 X X subarray length 3
// X 2 3 4 X subarray length 3
// X X 3 4 5 subarray length 3
// 1 2 3 4 X subarray length 4
// X 2 3 4 5 subarray length 4
// 1 2 3 4 5 subarray length 5

// 5 8 9 8 5 The count of A[i]
// 3 4 5 4 3 The count of A[i] in odd length array with (x + 1) / 2
// 2 4 4 4 2 The count of A[i] in even length array with x / 2

// 0ms 100.00% 2.1MB 100.00%
// O(N) O(1)
func sumOddLengthSubarrays(A []int) int {
  ans, n := 0, len(A)
  for i := 0; i < n; i++ {
    ans += ((i + 1) * (n - i) + 1) / 2 * A[i]
  }
  return ans
}
