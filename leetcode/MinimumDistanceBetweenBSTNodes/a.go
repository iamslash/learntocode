/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "math"
)

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

//     4
//    / \
//   2   6
//  / \
// 1   3

// NOTICE: the values of any two different nodes in the tree
// The anser is 1 not 3 : 90 - 89 = 1
//
//       90
//      /   
//     69
//    /  \
//   49  89
//  /
// 52

// 0ms 100.00% 2.3MB 100.00%
// inorder traversal
// O(N) O(lgN)
var (
  minDist int
  prevVal int
)
func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
func dfs(u *TreeNode) {
  if u.Left != nil {
    dfs(u.Left)
  }
  if prevVal >= 0 {
    minDist = min(minDist, u.Val - prevVal)
  }
  prevVal = u.Val
  if u.Right != nil {
    dfs(u.Right)
  }
}
func minDiffInBST(u *TreeNode) int {
  minDist = math.MaxInt32
  prevVal = -1
  dfs(u)
  return minDist
}

func main() {
  fmt.Println("hello world")
}
