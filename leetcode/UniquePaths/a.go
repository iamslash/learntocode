/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 28.57%
// iterative dynamic programming
// O(HW) O(HW)
func uniquePaths(h int, w int) int {
  C := make([][]int, h)
  for i := range C {
    C[i] = make([]int, w)
  }
  C[0][0] = 1
  for y := 0; y < h; y++ {
    for x := 0; x < w; x++ {
      if y > 0 {
        C[y][x] += C[y-1][x]
      }
      if x > 0 {
        C[y][x] += C[y][x-1]
      }
    }
  }
  // fmt.Println(C)
  return C[h-1][w-1]
}
