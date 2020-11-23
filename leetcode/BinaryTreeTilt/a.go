/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// Console right but submit wrong answer: [1,2]
// DFS
// O(N) O(lgN)
var tilt int = 0
func abs(a int) int {
  if a < 0 {
    return -a
  }
  return a
}
func dfs(u *TreeNode) int {
  // base
  if u == nil {
    return 0
  }
  // recursion
  l := dfs(u.Left)
  r := dfs(u.Right)
  tilt += abs(l - r)
  return l + r + u.Val
}
func findTilt(u *TreeNode) int {
  dfs(u)
  return tilt
}

func main() {
  fmt.Println("hello world")
}
