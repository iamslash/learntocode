/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 12ms 57.48% 4.2MB 81.44%
// sort
// O(NlgN) O(1)
func canBeEqual(T []int, A []int) bool {
  sort.Ints(T)
  sort.Ints(A)
  for i := 0; i < len(T); i++ {
    if T[i] != A[i] {
      return false
    }
  }
  return true
}
