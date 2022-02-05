/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 76ms 79.25% 8.1MB 88.46%
// sort
// O(NlgN) O(1)
var MAXxVAL int = 1000000007
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func maxArea(h, w int, H, V []int) int {
  sort.Ints(H)
  sort.Ints(V)
  H = append(H, h)
  V = append(V, w)
  maxy, maxx := H[0], V[0]
  for i := 1; i < len(H); i++ {
    maxy = max(maxy, H[i]-H[i-1])
  }
  for i := 1; i < len(V); i++ {
    maxx = max(maxx, V[i]-V[i-1])
  }
  return maxy * maxx % MAXVAL
}
