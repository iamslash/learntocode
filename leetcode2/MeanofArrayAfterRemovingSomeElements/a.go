/* Copyright (C) 2020 by iamslash */

package main

import "fmt"
import "sort"

// 4ms 100.00% 3.4MB 100.00%
// sort
// O(NlgN) O(1)
func trimMean(A []int) float64 {
  n := len(A)
  m, p := int(float64(n) * 0.9), int(float64(n) * 0.05)
  sort.Ints(A)
  sum := float64(0)
  for i := p; i < m+p; i++ {
    sum += float64(A[i])
  }
  return sum / float64(m)
}
