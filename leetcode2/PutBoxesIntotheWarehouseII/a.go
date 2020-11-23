/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "sort"
)

//   B: 4 3 2 2 1
//            i
//   W: 4 3 2 1
//            j
// cnt: 4

//   B: 6 5 4 2
//            i
//   W: 7 6 3 3 3 2
//          j
// cnt: 2

// 132ms 100.00% 10.4MB 100.00%
// sort
// O(NlgN) O(1)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func maxBoxesInWarehouse(B []int, W []int) int {
  sort.Slice(B, func (i, j int) bool {
    return B[i] > B[j]
  })
  i, j := 0, len(W) - 1
  for k := 0; k < len(B) && i <= j; k++ {
    if B[k] <= max(W[i], W[j]) {
      if (W[i] < W[j] && W[i] > B[k]) || W[j] < B[k] {
        i++
      } else {
        j--
      }
    }
  }
  return len(W) - 1 - (j - i)
}
