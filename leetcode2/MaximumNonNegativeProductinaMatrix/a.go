/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.8MB 57.89%
// dynamic programming
// O(HW) O(HW)
func max(a, b int64) int64 {
  if a > b {
    return a
  }
  return b
}
func min(a, b int64) int64 {
  if a < b {
    return a
  }
  return b
}
func maxProductPath(G [][]int) int {
  h, w, MOD := len(G), len(G[0]), 1000000007
  cMax := make([][]int64, h)
  for y := 0; y < h; y++ {
    cMax[y] = make([]int64, w)
  }
  cMin := make([][]int64, h)
  for y := 0; y < h; y++ {
    cMin[y] = make([]int64, w)
  }
  cMax[0][0], cMin[0][0] = int64(G[0][0]), int64(G[0][0])
  for y := 1; y < h; y++ {
    prev := cMax[y-1][0] * int64(G[y][0])
    cMax[y][0], cMin[y][0] = prev, prev
  }
  for x := 1; x < w; x++ {
    prev := cMax[0][x-1] * int64(G[0][x])
    cMax[0][x], cMin[0][x] = prev, prev
  }
  for y := 1; y < h; y++ {
    for x := 1; x < w; x++ {
      if G[y][x] < 0 {
        cMax[y][x] = min(cMin[y-1][x], cMin[y][x-1]) * int64(G[y][x])
        cMin[y][x] = max(cMax[y-1][x], cMax[y][x-1]) * int64(G[y][x])
      } else {
        cMax[y][x] = max(cMax[y-1][x], cMax[y][x-1]) * int64(G[y][x])
        cMin[y][x] = min(cMin[y-1][x], cMin[y][x-1]) * int64(G[y][x])
      }
    }
  }
  ans := cMax[h-1][w-1] % int64(MOD)
  if ans < 0 {
    return -1
  }
  return int(ans)  
}
