/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//            i
//   B: 4 4 3 1
//   W: 5 3 3 4 1
//          j
// ans: 1

//            i
//   B: 3 2 1
//   W: 1 2 3 4
//        j
// ans: 1

// 152ms 66.67% 9MB 66.67%
// two pointers
// O(NlgN) O(1)
func maxBoxesInWarehouse(B []int, W []int) int {
  sort.Sort(sort.Reverse(sort.IntSlice(B)))
  i, j, n, m, ans := 0, 0, len(B), len(W), 0
  for i < n && j < m {
    if B[i] <= W[j] {
      i++
      j++
      ans++
    } else {
      i++
    }
  }
  return ans
}
