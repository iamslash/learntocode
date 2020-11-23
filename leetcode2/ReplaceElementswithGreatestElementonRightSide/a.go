/* Copyright (C) 2020 by iamslash */

package main

// import "fmt"

//                   i       
//    A: 17 18 5 4 6 1
// last: -1

// 16ms 85.62% 6.1MB 100.00%
// backward
// O(N) O(1)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func replaceElements(A []int) []int {
  last := -1
  for i := len(A) - 1; i >= 0; i-- {
    A[i], last = last, max(last, A[i])
  }
  return A
}
