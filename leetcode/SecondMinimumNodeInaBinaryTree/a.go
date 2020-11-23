/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// // 0ms 100.00% 1.9MB 100.00%
// // DFS
// // O(N) O(lgN)
// var minVal = -1
// func min(a, b int) int {
//   if a < b {
//     return a
//   }
//   return b
// }
// func max(a, b int) int {
//   if a > b {
//     return a
//   }
//   return b
// }
// func findSecondMinimumValue(u *TreeNode) int {
//   // base
//   if u.Left == nil {
//     return -1
//   }
//   // recursion
//   l := u.Left.Val
//   if u.Left.Val == u.Val {
//     l = findSecondMinimumValue(u.Left)
//   }
//   r := u.Right.Val
//   if u.Right.Val == u.Val {
//     r = findSecondMinimumValue(u.Right)
//   }
//   if l < 0 || r < 0 {
//     return max(l, r)
//   }
//   return min(l, r)
// }
//   //   2
//   //  / \
//   // 2   5
//   //    / \
//   //   5   7

// 0ms 100.00% 1.9MB 100.00%
var min1 int64
var min2 int64

func dfs(u *TreeNode) {
	// base
	if u.Left == nil {
		if int64(u.Val) > min1 && int64(u.Val) < min2 {
			min2 = int64(u.Val)
		}
		return
	}
	// recursion
	dfs(u.Left)
	dfs(u.Right)
}

func findSecondMinimumValue(root *TreeNode) int {
	min1 = int64(root.Val)
	min2 = math.MaxInt64
	dfs(root)
	if min1 == min2 || min2 == math.MaxInt64 {
		return -1
	}
	return int(min2)
}

func main() {
	fmt.Println("hello world")
}
