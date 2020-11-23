/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 48ms 89.66% 6.5MB 100.00%
// brute force
// O(N) O(N)
func avg(M [][]int, y, x int) int {
  h, w := len(M), len(M[0])  
  cnt, sum := 0, 0
  for i := y - 1; i <= y + 1; i++ {
    for j := x - 1; j <= x + 1; j++ {
      if i >= 0 && i < h && j >= 0 && j < w {
        cnt++
        sum += M[i][j]
      }
    }
  }
  return sum / cnt
}
func imageSmoother(M [][]int) [][]int {
  h, w := len(M), len(M[0])
  R := make([][]int, h)
  for i := range R {
    R[i] = make([]int, w)
  }
  for y := 0; y < h; y++ {
    for x := 0; x < w; x++ {
      R[y][x] = avg(M, y, x)
    }
  }
  return R
}

func main() {
  fmt.Println("hello world")
}
