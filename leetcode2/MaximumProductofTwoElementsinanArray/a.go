/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 93.30% 3MB 87.60%
// sort
// O(NlgN) O(1)
func maxProduct(A []int) int {
  n := len(A)
  sort.Ints(A)
  return (A[n-2]-1) * (A[n-1]-1)
}
