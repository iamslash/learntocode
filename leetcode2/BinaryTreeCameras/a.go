/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 100.00% 4.2MB 85.71%
// dfs
// O(N) O(lgN)
const (
  NO_NEED = 0
  HAS_CAMERA = 1
  NO_CAMERA = 2
)
var ans int
func dfs(u *TreeNode) int {
  // base
  if u == nil {
    return NO_NEED
  }
  // recursion
  l := dfs(u.Left)
  r := dfs(u.Right)
  if l == NO_CAMERA || r == NO_CAMERA {
    ans++
    return HAS_CAMERA
  }
  if l == HAS_CAMERA || r == HAS_CAMERA {
    return NO_NEED
  }
  return NO_CAMERA
}
func minCameraCover(root *TreeNode) int {
  ans = 0
  if dfs(root) == NO_CAMERA {
    return ans+1
  }
  return ans
}
