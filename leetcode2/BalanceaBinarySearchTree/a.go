/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 1568ms 13.70% 114.3MB 94.29%
// inorder traversal
// O(N) O(N)
func build(data []*TreeNode, s, e int) *TreeNode {
  if s > e {
    return nil
  }
  m := (s + e)/2
  u := data[m]
  u.Left = build(data, s, m-1)
  u.Right = build(data, m+1, e)
  return u
}
func inorder(data *[]*TreeNode, u *TreeNode) {
  if u == nil {
    return
  }
  inorder(data, u.Left)
  *data = append(*data, u)
  inorder(data, u.Right)  
}
func balanceBST(u *TreeNode) *TreeNode {
  data := []*TreeNode{}
  inorder(&data, u)
    fmt.Println(data)
  return build(data, 0, len(data)-1)
}
