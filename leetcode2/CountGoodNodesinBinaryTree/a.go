/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 208ms 5.30% 14.4MB 8.82%
// DFS
// O(N) O(N)
var cnt int
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func dfs(u *TreeNode, maxVal int) {
  // base
  if u == nil {
    return
  }
  // recursion
  if u.Val >= maxVal {
    cnt++
  }
  dfs(u.Left, max(u.Val, maxVal))
  dfs(u.Right, max(u.Val, maxVal))
}
func goodNodes(u *TreeNode) int {
  cnt = 0
  dfs(u, -10000)
  return cnt
}
