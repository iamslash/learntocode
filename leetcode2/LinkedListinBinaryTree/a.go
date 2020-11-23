/* Copyright (C) 2020 by iamslash */

package main

// 20ms 95.83% 6.6MB 100.00%
// DFS
// O(N) O(lgN)
func isPath(h *ListNode, u *TreeNode) bool {
  // base
  if h == nil {
    return true
  }
  if u == nil || h.Val != u.Val{
    return false
  }

  // recursion
  return isPath(h.Next, u.Left) ||
    isPath(h.Next, u.Right)
}

func isSubPath(h *ListNode, u *TreeNode) bool {
  // base
  if u == nil {
    return false
  }
  //recursion
  return isPath(h, u) ||
    isSubPath(h, u.Left) ||
    isSubPath(h, u.Right)
}

func main() {
  fmt.Println("hello world")
}
