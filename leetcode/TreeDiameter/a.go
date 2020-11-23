/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// Start from u node.
// Find 2 nodes which are the farest nodes from u.
// The sum of distances from u node are the answer.

// 20ms 85.71% 6.4MB 100.00%
// DFS
// O(N) O(N)
var maxDiameter int = 0
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func dfs(adj [][]int, u, p int) int {
  maxDepth1, maxDepth2 := 0, 0
  for _, v := range adj[u] {
    if v != p {
      vDepth := dfs(adj, v, u)
      if vDepth > maxDepth1 {
        maxDepth2 = maxDepth1
        maxDepth1 = vDepth
      } else if vDepth > maxDepth2 {
        maxDepth2 = vDepth
      }
    }
  }
  maxDiameter = max(maxDiameter, maxDepth1 + maxDepth2)
  return maxDepth1 + 1
}
func treeDiameter(E [][]int) int {
  n := len(E) + 1
  adj := make([][]int, n)
  for _, e := range E {
    adj[e[0]] = append(adj[e[0]], e[1])
    adj[e[1]] = append(adj[e[1]], e[0])
  }
  maxDiameter = 0
  dfs(adj, 0, -1)
  return maxDiameter
}

func main() {
    fmt.Println("hello world")
}
