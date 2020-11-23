/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// Wrong Answer:
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]
// [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]] 
type NumMatrix struct {
  gs [][]int
}
func Constructor(M [][]int) NumMatrix {
  h, w := len(M), len(M[0])
  for y := 0; y < h; y++ {
    for x := 0; x < w; x++ {
      if y > 0 {
        M[y][x] += M[y-1][x]
      }
      if x > 0 {
        M[y][x] += M[y][x-1]
      }
      if y > 0 && x > 0 {
        M[y][x] -= M[y-1][x-1]
      }
    }
  }
  return NumMatrix{
    gs: M,
  }
}
func (this *NumMatrix) SumRegion(y1 int, x1 int, y2 int, x2 int) int {
  ans := this.gs[y2][x2]
  if y1 > 0 {
    ans -= this.gs[y1-1][x2]
  }
  if x1 > 0 {
    ans -= this.gs[y1][x1-1]
  }
  if y1 > 0 && x1 > 0 {
    ans += this.gs[y1-1][x1-1]
  }
  return ans
}
