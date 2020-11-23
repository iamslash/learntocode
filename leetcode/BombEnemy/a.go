/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// 0ms 100.00% 4.3MB 5.26%
// memoization
// O(H*W*max(H,W)) O(W)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func maxKilledEnemies(G [][]byte) int {
  if len(G) == 0 || len(G[0]) == 0 {
    return 0
  }
  h, w, ans, killrow := len(G), len(G[0]), 0, 0
  killcol := make([]int, w)
  for y := 0; y < h; y++ {
    for x := 0; x < w; x++ {
      if x == 0 || G[y][x-1] == 'W' {
        killrow = 0;
        for k := x; k < w && G[y][k] != 'W'; k++ {
          if G[y][k] == 'E' {
            killrow++
          }
        }
      }
      if y == 0 || G[y-1][x] == 'W' {
        killcol[x] = 0;
        for k := y; k < h && G[k][x] != 'W'; k++ {
          if G[k][x] == 'E' {
            killcol[x]++
          }
        }
      }
      if G[y][x] == '0' {
        ans = max(ans, killrow + killcol[x])
      }
    }
  }
  return ans
}
