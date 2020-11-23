/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 56ms 93.75MB 7.1MB 100.00%
// linear traversal
// O(N) O(1)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func numTimesAllBlue(L []int) int {
  ans, right := 0, 0
  for i := 0; i < len(L); i++ {
    right = max(right, L[i])
    if i + 1 == right {
      ans++
    }
  }
  return ans
}
