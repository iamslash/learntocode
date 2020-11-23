/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 12ms 100.00% 6MB 100.00%
// matrix
// O(RC) O(RC)
func matrixReshape(A [][]int, r int, c int) [][]int {
  h, w := len(A), len(A[0])
  if h * w != r * c {
    return A
  }
  M := make([][]int, r)
  for i := 0; i < len(M); i++ {
    M[i] = make([]int, c)
  }
  i := 0
  for y := 0; y < len(A); y++ {
    for x := 0; x < len(A[0]); x++ {
      M[i/c][i%c] = A[y][x]
      i++
    }
  }
  return M
}

func main() {
    fmt.Println("hello world")
}
