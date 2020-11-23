/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

//        6
//      /   \
//     2      8
//    /  \   / \
//   0   4  7   9
//       / \
//      3   5
//
// p: 2, q: 8
// 6
// p: 2, q: 4
// 2
// p: 3, q: 5
//
// find the first node u.val >= p.Val && u.Val <= q.Val


// 24ms 67.69% 6.8MB 100.00%
// tree
// O(N) O(lgN)
func lowestCommonAncestor(u, p, q *TreeNode) *TreeNode {
  if u.Val > p.Val && u.Val > q.Val {
    return lowestCommonAncestor(u.Left, p, q)
  }
  if u.Val < p.Val && u.Val < q.Val {
    return lowestCommonAncestor(u.Right, p, q)
  }
  return u  
}

func main() {
    fmt.Println("hello world")
}
