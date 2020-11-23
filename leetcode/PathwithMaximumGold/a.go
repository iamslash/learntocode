/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 16ms 92.68% 2.1MB 100.00%
// DFS
// O(4^N) O(N)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func dfs(G [][]int, y, x int) int {
  // base
  if y < 0 || y >= len(G) || x < 0 || x >= len(G[0]) || G[y][x] <= 0 {
    return 0
  }
  // recursion
  G[y][x] = -G[y][x]
  r := 0
  r = max(r, dfs(G, y-1, x))
  r = max(r, dfs(G, y, x+1))
  r = max(r, dfs(G, y+1, x))
  r = max(r, dfs(G, y, x-1))
  G[y][x] = -G[y][x]
  return G[y][x] + r
}
func getMaximumGold(G [][]int) int {
  r := 0
  for y := 0; y < len(G); y++ {
    for x := 0; x < len(G[0]); x++ {
      r = max(r, dfs(G, y, x))
    }
  }
  return r
}

func main() {
    fmt.Println("hello world")
}
