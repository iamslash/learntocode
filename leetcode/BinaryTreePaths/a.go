/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// 0ms 100.00% 2.5MB 100.00%
// dfs
// O(N) O(lgN)
func dfs(u *TreeNode, path string, rslt *[]string) {
  // base
  if u.Left == nil && u.Right == nil {
    *rslt = append(*rslt, path)
    return
  }
  // recursion
  if u.Left != nil {
    dfs(u.Left, path + fmt.Sprintf("->%d", u.Left.Val), rslt)
  }
  if u.Right != nil {
    dfs(u.Right, path + fmt.Sprintf("->%d", u.Right.Val), rslt)
  }
}
func binaryTreePaths(u *TreeNode) []string {
  rslt := []string{}
  if u == nil {
    return rslt
  }
  dfs(u, fmt.Sprintf("%d", u.Val), &rslt)
  return rslt
}

func main() {
    fmt.Println("hello world")
}
