/* Copyright (C) 2020 by iamslash */

package main

import "fmt"
import "sort"

// 76ms 79.75% 10.3MB 75.95%
// sort
// O(NlgN) O(N)
func arrayRankTransform(A []int) []int {
  B := make([]int, len(A))
  copy(B, A)
  sort.Ints(B)
  dict := make(map[int]int)
  for i, j := 0, 0; i < len(B); i++ {
    if i == 0 || B[i-1] != B[i] {
      j++
    }
    dict[B[i]] = j
  }
  for i := 0; i < len(A); i++ {
    A[i] = dict[A[i]]
  }
  return A
}
