/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// i j   k
// 0 1 1 3 7 9

// 8ms 100.00% 2.2MB 100.00%
// brute force
// O(N^3) O(1)
func abs(a int) int {
  if a < 0 {
    return -a
  }
  return a
}
func countGoodTriplets(A []int, a int, b int, c int) int {
  ans, n := 0, len(A)  
  for i := 0; i < n-2; i++ {
    for j := i+1; j < n-1; j++ {
      for k := j+1; k < n; k++ {
        if abs(A[i] - A[j]) <= a &&
          abs(A[j] - A[k]) <= b &&
          abs(A[i] - A[k]) <= c {
          ans++
        }
      }
    }
  }
  return ans
}
