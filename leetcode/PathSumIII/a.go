/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// sum: 8
//
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// 16ms 48.51% 4.4MB 20.00%
// double DFS
// O(N^2) O(N)
func dfs(u *TreeNode, sum int) int {
  if u == nil {
    return 0
  }
  rst := 0
  if u.Val == sum {
    rst = 1
  }
  return rst +
    dfs(u.Left, sum - u.Val) +
    dfs(u.Right, sum - u.Val)
}
func pathSum(s *TreeNode, sum int) int {
  if s == nil {
    return 0
  }
  return dfs(s, sum) +
    pathSum(s.Left, sum) +
    pathSum(s.Right, sum)
}

func main() {
    fmt.Println("hello world")
}
