/* Copyright (C) 2019 by iamslash */

package main

import "fmt"
import "sort"

// 4ms 100.00% 2.6MB 100.00%
// sort
// O(NlgN) O(1)
func abs(a int) int {
  if a < 0 {
    return -a
  }
  return a
}
func canMakeArithmeticProgression(A []int) bool {
  sort.Ints(A)
  diff := abs(A[1] - A[0])
  for i := 2; i < len(A); i++ {
    if abs(A[i] - A[i-1]) != diff {
      return false
    }
  }
  return true
}
