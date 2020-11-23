/* Copyright (C) 2020 by iamslash */

package main

// -1 -2 0 2 1

// 0ms 100.00% 2.3MB 100.00%
// brute force
// O(N) O(1)
func sumZero(n int) []int {
  half := n/2
  A := make([]int, n)
  for i := 0; i < half; i++ {
    A[i] = i + 1
    A[n-1-i] = -A[i]
  }
  if n & 1 > 0 {
    A[half] = 0
  }
  return A
}
