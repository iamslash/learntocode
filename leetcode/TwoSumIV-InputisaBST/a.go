/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// Wrong Answer
// [1]
// 2
// DFS, hash
// O(N) O(N)
var nums = make(map[int]bool)
func dfs(u *TreeNode, k int) bool {
  // base
  if u == nil {
    return false
  }
  if _, ok := nums[k - u.Val]; ok {
    return true
  }
  nums[u.Val] = true
  return dfs(u.Left, k) || dfs(u.Right, k)
}
func findTarget(u *TreeNode, k int) bool {
  return dfs(u, k)
}

func main() {
    fmt.Println("hello world")
}
