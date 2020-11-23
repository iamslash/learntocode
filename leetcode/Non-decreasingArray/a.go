/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 3 4 4 3
//     i           

// 24ms 85.15% 6.2MB 100.00%
// brute force
// O(N) O(1)
func checkPossibility(A []int) bool {
  if len(A) <= 2 {
    return true
  }
  mod := false
  for i := 0; i < len(A) - 1; i++ {
    if A[i] <= A[i+1] {
      continue
    }
    if mod {
      return false
    }
    if i > 0 && A[i-1] > A[i+1] {
      A[i+1] = A[i]
    }
    mod = true
  }
  return true
}

func main() {
    fmt.Println("hello world")
}
