/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// // 144ms 54.05% 14.6MB 100.00%
// // DFS
// // O(N^2) O(lgN)
// func max(a, b int) int {
//   if a > b {
//     return a
//   }
//   return b
// }
// func dfs(u *TreeNode, dir, step int) int {
//   // base
//   if u == nil {
//     return step
//   }
//   if dir < 0 {
//     return max(dfs(u.Right, 1, step+1),
//       dfs(u.Left, -1, 1))
//   }
//   return max(dfs(u.Left, -1, step+1),
//     dfs(u.Right, 1, 1))
// }
// func longestZigZag(u *TreeNode) int {
//   return max(dfs(u.Left, -1, 1),
//     dfs(u.Right, 1, 1))
// }

// 160ms 48.65% 20.3MB 100.00%
// DFS
// O(N^2) O(lgN)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func dfs(u *TreeNode) []int {
  // base
  if u == nil {
    return []int{-1, -1, -1}
  }
  l := dfs(u.Left)
  r := dfs(u.Right)
    ans := max(max(l[1], r[0]) + 1,
    max(l[2], r[2]))
  return []int{l[1] + 1, r[0] + 1, ans}
}
func longestZigZag(u *TreeNode) int {
  return dfs(u)[2]
}
