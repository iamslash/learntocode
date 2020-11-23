/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 34.91% 2.5MB 13.47%
// brute force
// O(N) O(1)
func busyStudent(S []int, E []int, q int) int {
  n, ans := len(S), 0
  for i := 0; i < n; i++ {
    if S[i] <= q && q <= E[i] {
      ans++
    }
  }
  return ans
}
