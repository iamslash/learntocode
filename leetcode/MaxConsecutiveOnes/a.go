/* Copyright (C) 2020 by iamslash */

package main

import "fmt"


//     i
// 0 0 1 1 0 1 1 1
//     j

// 36ms 97.58% 6.4MB 100.00%
// two pointers
// O(N) O(1)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func findMaxConsecutiveOnes(A []int) int {
  maxDist := 0
  for i, j := 0, 0; j < len(A); j++ {
    if A[j] == 0 {
      continue
    }
    i = j
    for j < len(A) && A[j] == 1 {
      j++
    }
    maxDist = max(maxDist, j-i)
  }
  return maxDist
}

func main() {
    fmt.Println("hello world")
}
