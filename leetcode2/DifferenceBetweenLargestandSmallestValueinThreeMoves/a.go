/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 5 3 2 4
// i     
// 2 3 4 5
//       j

// 92ms 96.36% 7.3MB 69.09%
// sort
// O(NlgN) O(1)
func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
func minDifference(A []int) int {
  if len(A) < 5 {
    return 0
  }
  n, ans := len(A), math.MaxInt32
  sort.Ints(A)
  for i := 0; i < 4; i++ {
    ans = min(ans, A[n-(4-i)] - A[i])
  }
  return ans
}
