/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//     5
//    / \
//   3   6
//  / \
// 2   4

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// 12ms 80.00% 6.2MB 100.00%
// DFS
// O(N) O(lgN)
func trimBST(u *TreeNode, L int, R int) *TreeNode {
  // base
  if u == nil {
    return nil
  }
  // recursion
  if u.Val < L {
    return trimBST(u.Right, L, R);
  }
  if u.Val > R {
    return trimBST(u.Left, L, R);
  }
  u.Left = trimBST(u.Left, L, R);
  u.Right = trimBST(u.Right, L, R);
  return u;
}

func main() {
    fmt.Println("hello world")
}
