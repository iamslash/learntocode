/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 4ms 9.09% 2.7MB 100.00%
// DFS
// O(N) O(lgN)
func sumOfLeftLeaves(u *TreeNode) int {
	// base
	if u == nil {
		return 0
	}
	if u.Left != nil && u.Left.Left == nil &&
		u.Left.Right == nil {
		return u.Left.Val + sumOfLeftLeaves(u.Right)
	}

	// recursion
	return sumOfLeftLeaves(u.Left) + sumOfLeftLeaves(u.Right)
}

func main() {
	fmt.Println("hello world")
}
