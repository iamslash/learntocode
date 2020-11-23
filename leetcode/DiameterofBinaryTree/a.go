/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// 8ms 31.19% 4.5MB 100.00%
// DFS
// O(N) O(lgN)
var maxDiameter int = 0
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func dfs(u *TreeNode) int {
  // base
  if u == nil {
    return 0
  }
  // recursion
  leftDiameter := dfs(u.Left)
  rightDiameter := dfs(u.Right)
  maxDiameter = max(maxDiameter, leftDiameter + rightDiameter)
  return 1 + max(leftDiameter, rightDiameter)
}
func diameterOfBinaryTree(u *TreeNode) int {
  maxDiameter = 0
  dfs(u)
  return maxDiameter
}

func main() {
  fmt.Println("hello world")
}
