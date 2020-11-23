/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// A: 1 2 3
//    2 3 3
//    3 4 3
//    4 4 4

//    sumA - minA * n  

// 48ms 25.00% 6.5MB 100.00%
// math
// O(N) O(1)
func minMoves(A []int) int {
  sum, minA := 0, A[0]
  for i := 0; i < len(A); i++ {
    if A[i] < minA {
      minA = A[i]
    }
    sum += A[i]
  }
  
  return sum - minA * len(A)
}

func main() {
  fmt.Println("hello world")
}
